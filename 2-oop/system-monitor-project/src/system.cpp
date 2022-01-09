#include "system.h"

#include <unistd.h>

#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include "linux_parser.h"
#include "process.h"
#include "processor.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

// DONE: Return the system's CPU
Processor &System::Cpu() { return cpu_; }

// DONE: Return a container composed of the system's processes
vector<Process> &System::Processes() {
    vector<int> pids = LinuxParser::Pids();
    processes_.clear();
    for (int pid : pids) {
        processes_.push_back(Process(pid));
    }
    std::sort(processes_.begin(), processes_.end());
    return processes_;
}

// DONE: Return the system's kernel identifier (string)
std::string System::Kernel() const { return LinuxParser::Kernel(); }

// DONE: Return the system's memory utilization
float System::MemoryUtilization() const {
    return LinuxParser::MemoryUtilization();
}

// DONE: Return the operating system name
std::string System::OperatingSystem() const {
    return LinuxParser::OperatingSystem();
}

// DONE: Return the number of processes actively running on the system
int System::RunningProcesses() const { return LinuxParser::RunningProcesses(); }

// DONE: Return the total number of processes on the system
int System::TotalProcesses() const { return LinuxParser::TotalProcesses(); }

// DONE: Return the number of seconds since the system started running
long int System::UpTime() const { return LinuxParser::UpTime(); }