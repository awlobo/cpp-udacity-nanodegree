#include "linux_parser.h"

#include <dirent.h>
#include <unistd.h>

#include <string>
#include <vector>

using std::stof;
using std::string;
using std::to_string;
using std::vector;

// DONE: An example of how to read data from the filesystem
string LinuxParser::OperatingSystem() {
    string line;
    string key;
    string value;
    std::ifstream filestream(kOSPath);
    if (filestream.is_open()) {
        while (std::getline(filestream, line)) {
            std::replace(line.begin(), line.end(), ' ', '_');
            std::replace(line.begin(), line.end(), '=', ' ');
            std::replace(line.begin(), line.end(), '"', ' ');
            std::istringstream linestream(line);
            while (linestream >> key >> value) {
                if (key == "PRETTY_NAME") {
                    std::replace(value.begin(), value.end(), '_', ' ');
                    return value;
                }
            }
        }
    }
    return value;
}

// DONE: An example of how to read data from the filesystem
string LinuxParser::Kernel() {
    string os, version, kernel;
    string line;
    std::ifstream stream(kProcDirectory + kVersionFilename);
    if (stream.is_open()) {
        std::getline(stream, line);
        std::istringstream linestream(line);
        linestream >> os >> version >> kernel;
    }
    return kernel;
}

// BONUS: Update this to use std::filesystem
vector<int> LinuxParser::Pids() {
    vector<int> pids;
    DIR *directory = opendir(kProcDirectory.c_str());
    struct dirent *file;
    while ((file = readdir(directory)) != nullptr) {
        // Is this a directory?
        if (file->d_type == DT_DIR) {
            // Is every character of the name a digit?
            string filename(file->d_name);
            if (std::all_of(filename.begin(), filename.end(), isdigit)) {
                int pid = stoi(filename);
                pids.push_back(pid);
            }
        }
    }
    closedir(directory);
    return pids;
}

// DONE: Read and return the system memory utilization
float LinuxParser::MemoryUtilization() {
    string line, key, value, memFree, memTotal;
    std::ifstream stream(kProcDirectory + kMeminfoFilename);
    if (stream.is_open()) {
        while (std::getline(stream, line)) {
            std::istringstream linestream(line);
            while (linestream >> key >> value) {
                if (key == "MemTotal:") {
                    memTotal = value;
                }
                if (key == "MemFree:") {
                    memFree = value;
                }
            }
        }
    }
    // string -> float
    return (stof(memTotal) - stof(memFree)) / stof(memTotal);
}

// DONE: Read and return the system uptime
long LinuxParser::UpTime() {
    string uptime, line;
    std::ifstream stream(kProcDirectory + kUptimeFilename);
    if (stream.is_open()) {
        std::getline(stream, line);
        std::istringstream linestream(line);
        linestream >> uptime;
    }
    // string to long
    return stol(uptime);
}

// DONE: Read and return the number of jiffies for the system
long LinuxParser::Jiffies() {
    vector<string> values = LinuxParser::CpuUtilization();
    long total = 0;
    for (int i = kUser_; i <= kSteal_; i++) {
        total += stol(values[i]);
    }
    return total;
}

// DONE: Read and return the number of active jiffies for a PID
long LinuxParser::ActiveJiffies(int pid) {
    string value, line;
    vector<string> values;
    std::ifstream stream(kProcDirectory + to_string(pid) + kStatFilename);
    if (stream.is_open()) {
        std::getline(stream, line);
        std::istringstream linestream(line);
        while (linestream >> value) {
            values.push_back(value);
        }
    }
    // (14) utime  &  (15) stime
    return stol(values[13] + values[14]);
}

// DONE: Read and return the number of active jiffies for the system
long LinuxParser::ActiveJiffies() {
    return LinuxParser::Jiffies() - LinuxParser::IdleJiffies();
}

// DONE: Read and return the number of idle jiffies for the system
long LinuxParser::IdleJiffies() {
    vector<string> values = LinuxParser::CpuUtilization();
    long total = 0;
    for (int i = kIdle_; i <= kIOwait_; i++) {
        total += stol(values[i]);
    }
    return total;
}

// DONE: Read and return CPU utilization
vector<string> LinuxParser::CpuUtilization() {
    string key, line;
    vector<string> values;
    std::ifstream stream(kProcDirectory + kStatFilename);
    if (stream.is_open()) {
        std::getline(stream, line);
        std::istringstream linestream(line);
        while (linestream >> key) {
            // save all values except the first one (cpu)
            if (key != "cpu") {
                values.push_back(key);
            }
        }
    }
    return values;
}

// DONE: Read and return the total number of processes
int LinuxParser::TotalProcesses() {
    string key, value, line;
    std::ifstream stream(kProcDirectory + kStatFilename);
    if (stream.is_open()) {
        while (std::getline(stream, line)) {
            std::istringstream linestream(line);
            while (linestream >> key >> value) {
                if (key == "processes") {
                    // string to int
                    return stoi(value);
                }
            }
        }
    }
    return 0;
}

// DONE: Read and return the number of running processes
int LinuxParser::RunningProcesses() {
    string key, value, line;
    std::ifstream stream(kProcDirectory + kStatFilename);
    if (stream.is_open()) {
        while (std::getline(stream, line)) {
            std::istringstream linestream(line);
            while (linestream >> key >> value) {
                if (key == "procs_running") {
                    // string to int
                    return stoi(value);
                }
            }
        }
    }
    return 0;
}

// DONE: Read and return the command associated with a process
string LinuxParser::Command(int pid) {
    string value;
    std::ifstream stream(kProcDirectory + to_string(pid) + kCmdlineFilename);
    if (stream.is_open()) {
        std::getline(stream, value);
    }
    return value;
}

// DONE: Read and return the memory used by a process
string LinuxParser::Ram(int pid) {
    string key, value, line;
    std::ifstream stream(kProcDirectory + to_string(pid) + kStatusFilename);
    if (stream.is_open()) {
        while (std::getline(stream, line)) {
            std::istringstream linestream(line);
            while (linestream >> key >> value) {
                if (key == "VmRSS:") {
                    // convert to mb
                    return to_string(stol(value) / 1024);
                }
            }
        }
    }
    return "-";
}

// DONE: Read and return the user ID associated with a process
string LinuxParser::Uid(int pid) {
    string key, value, line;
    std::ifstream stream(kProcDirectory + to_string(pid) + kStatusFilename);
    if (stream.is_open()) {
        while (std::getline(stream, line)) {
            std::istringstream linestream(line);
            while (linestream >> key >> value) {
                if (key == "Uid:") {
                    return value;
                }
            }
        }
    }
    return "-";
}

// DONE: Read and return the user associated with a process
string LinuxParser::User(int pid) {
    // structure -> root:x:0:0:root:/root:/bin/bash
    string name, x, uid, line;
    std::ifstream stream(kPasswordPath);
    if (stream.is_open()) {
        while (std::getline(stream, line)) {
            std::replace(line.begin(), line.end(), ':', ' ');
            std::istringstream linestream(line);
            while (linestream >> name >> x >> uid) {
                if (uid == LinuxParser::Uid(pid)) {
                    return name;
                }
            }
        }
    }
    return "-";
}

// DONE: Read and return the uptime of a process
long LinuxParser::UpTime(int pid) {
    vector<string> values;
    string value, line;
    std::ifstream stream(kProcDirectory + to_string(pid) + kStatFilename);
    if (stream.is_open()) {
        std::getline(stream, line);
        std::istringstream linestream(line);
        // store every value in a vector
        while (linestream >> value) {
            values.push_back(value);
        };
    }
    // we will need to retrive the uptime value from the vector
    // (22) starttime from https://man7.org/linux/man-pages/man5/proc.5.html
    return LinuxParser::UpTime() - (stol(values[21]) / 100);
}
