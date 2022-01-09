#include "format.h"

#include <iomanip>
#include <sstream>
#include <string>

using std::string;

// DONE: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long int timeInSeconds) {
    int hour = timeInSeconds / 3600;
    int minutes = (timeInSeconds / 60) % 60;
    int seconds = timeInSeconds % 60;

    // Apply formatting to the string
    std::stringstream stream;
    stream << std::setfill('0') << std::setw(2) << hour << ":"
           << std::setfill('0') << std::setw(2) << minutes << ":"
           << std::setfill('0') << std::setw(2) << seconds;
    return stream.str();
}