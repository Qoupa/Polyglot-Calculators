#include <iostream>
#include <string>
#include <sstream>

class Converter {
// Constants
const int secondsInMinute = 60;
const int secondsInHour = 3600;
const int secondsInDay = 86400;
const int minutesInHour = 60;
const int minutesInDay = 1440;
const int hoursInDay = 24;

enum DurationType { seconds, minutes, hours, days };

struct ConvertData {
    int count;
    DurationType from;
    DurationType to;
};

// Conversion methods
int ConvertSecondsToMinutes(int count) {
    return count / secondsInMinute;
}

int ConvertSecondsToHours(int count) {
    return count / secondsInHour;
}

int ConvertSecondsToDays(int count) {
    return count / secondsInDay;
}

int ConvertMinutesToSeconds(int count) {
    return count * secondsInMinute;
}

int ConvertMinutesToHours(int count) {
    return count / minutesInHour;
}

int ConvertMinutesToDays(int count) {
    return count / minutesInDay;
}

int ConvertHoursToSeconds(int count) {
    return count * secondsInHour;
}

int ConvertHoursToMinutes(int count) {
    return count * minutesInHour;
}

int ConvertHoursToDays(int count) {
    return count / hoursInDay;
}

int ConvertDaysToSeconds(int count) {
    return count * secondsInDay;
}

int ConvertDaysToMinutes(int count) {
    return count * minutesInDay;
}

int ConvertDaysToHours(int count) {
    return count * hoursInDay;
}

ConvertData PrepareToConvert(const std::string text) {

    ConvertData output;
    std::istringstream ss(text);
    std::string countStr, fromStr, toStr;

    // Separating string
    ss >> countStr >> fromStr >> toStr;

    output.count = std::stoi(countStr);

    // From
    if (fromStr == "sec") {
        output.from = seconds;
    }
    else if (fromStr == "min") {
        output.from = minutes;
    }
    else if (fromStr == "hour") {
        output.from = hours;
    }
    else if (fromStr == "day") {
        output.from = days;
    }

    // To
    if (toStr == "sec") {
        output.to = seconds;
    }
    else if (toStr == "min") {
        output.to = minutes;
    }
    else if (toStr == "hour") {
        output.to = hours;
    }
    else if (toStr == "day") {
        output.to = days;
    }

    return output;
}

public:

// Conversion method
int Convert(std::string text) {

    // Preparing input data for conversion
    ConvertData data = PrepareToConvert(text);
    switch (data.from) {
        case seconds:
        switch (data.to) {
            case minutes:
            return ConvertSecondsToMinutes(data.count);

            case hours:
            return ConvertSecondsToHours(data.count);
        
            case days:
            return ConvertSecondsToDays(data.count);

            case seconds:
            return data.count;
        }

        case minutes:
        switch (data.to) {
            case seconds:
            return ConvertMinutesToSeconds(data.count);

            case hours:
            return ConvertMinutesToHours(data.count);
        
            case days:
            return ConvertMinutesToDays(data.count);

            case minutes:
            return data.count;
        }

        case hours:
        switch (data.to) {
            case seconds:
            return ConvertHoursToSeconds(data.count);

            case minutes:
            return ConvertHoursToMinutes(data.count);
        
            case days:
            return ConvertHoursToDays(data.count);

            case hours:
            return data.count;
        }

        case days:
        switch (data.to) {
            case seconds:
            return ConvertDaysToSeconds(data.count);

            case minutes:
            return ConvertDaysToMinutes(data.count);
        
            case hours:
            return ConvertDaysToHours(data.count);

            case days:
            return data.count;
        }
    }
    // Returning 0 if input is invalid
    return 0;
}

};

int main() {
    Converter converter;
    std::string text;

    std::cout << "Enter count, from, to (supports: sec, min, hour, day): ";
    std::getline(std::cin, text);
    std::cout << converter.Convert(text);
}