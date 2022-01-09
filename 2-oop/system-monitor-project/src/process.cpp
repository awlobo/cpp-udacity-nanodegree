#include "process.h"

#include <unistd.h>

#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "linux_parser.h"
#include "process.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid) : pid_(pid) {
    user_ = LinuxParser::User(pid_);
    command_ = LinuxParser::Command(pid_);
    ram_ = LinuxParser::Ram(pid_);
    uptime_ = LinuxParser::UpTime(pid_);
}

// DONE: Return this process's ID
int Process::Pid() const { return pid_; }

// DONE: Return this process's CPU utilization
float Process::CpuUtilization() const {
    // https://stackoverflow.com/a/16736599/6928964

    long totalTime = LinuxParser::ActiveJiffies(pid_);
    long startTime = LinuxParser::UpTime(pid_);
    long upTime = LinuxParser::UpTime();

    long seconds = upTime - (startTime / sysconf(_SC_CLK_TCK));

    return totalTime / sysconf(_SC_CLK_TCK)/ seconds;
}

// DONE: Return the command that generated this process
string Process::Command() const { return command_; }

// DONE: Return this process's memory utilization
string Process::Ram() const { return ram_; }

// DONE: Return the user (name) that generated this process
string Process::User() const { return user_; }

// DONE: Return the age of this process (in seconds)
long int Process::UpTime() const { return uptime_; }

// DONE: Overload the "less than" comparison operator for Process objects
bool Process::operator<(Process const &a) const {
    return stol(ram_) > stol(a.ram_);
}