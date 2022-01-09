#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <vector>

#include "process.h"
#include "processor.h"

class System {
public:
    Processor &Cpu();                    // DONE: See src/system.cpp
    std::vector<Process> &Processes();   // DONE: See src/system.cpp
    float MemoryUtilization() const;     // DONE: See src/system.cpp
    long UpTime() const;                 // DONE: See src/system.cpp
    int TotalProcesses() const;          // DONE: See src/system.cpp
    int RunningProcesses() const;        // DONE: See src/system.cpp
    std::string Kernel() const;          // DONE: See src/system.cpp
    std::string OperatingSystem() const; // DONE: See src/system.cpp

    // DONE: Define any necessary private members
private:
    Processor cpu_ = {};
    std::vector<Process> processes_ = {};
};

#endif