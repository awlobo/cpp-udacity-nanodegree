#include "process.h"

#include <unistd.h>

#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "linux_parser.h"
#include "process.h"

using std::stol;
using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid) : pid_(pid) {}

// DONE: Return this process's ID
int Process::Pid() { return pid_; }

// DONE: Return this process's CPU utilization
float Process::CpuUtilization() {
    auto result =
        ((float)LinuxParser::ActiveJiffies(pid_) / sysconf(_SC_CLK_TCK));
    cpu_utilization_ = result / UpTime();
    return this->cpu_utilization_;
}

// DONE: Return the command that generated this process
string Process::Command() { return LinuxParser::Command(pid_); }

// DONE: Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(pid_); }

// DONE: Return the user (name) that generated this process
string Process::User() { return LinuxParser::User(pid_); }

// DONE: Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(pid_); }

// DONE: Overload the "less than" comparison operator for Process objects
bool Process::operator<(Process &a) {
    return (cpu_utilization_ > a.cpu_utilization_);
}