#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "CSV.h"
#include "WeatherDataEntry.h"






int main(){

    std::cout << "running test for CSV and WeatherDataEntry classes" << std::endl;
    //test can read the CSV file and store the data in WeatherDataEntry objects
    std::ifstream file("weather_data.csv");
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file." << std::endl;
        return 1;
    }
    std::vector<WeatherDataEntry> weatherDataEntries = CSV::readLine(file);

    std::cout<< "Weather Data Entries Loaded: " << weatherDataEntries.size() << std::endl;

    if(!weatherDataEntries.empty()) {
        std::cout << "First Entry Timestamp: " << weatherDataEntries[0].timestamp << std::endl;
        std::cout << "First Entry AT: " << weatherDataEntries[0].AT << std::endl;
        // Add more output as needed to verify the data
    } else {
        std::cout << "No weather data entries found." << std::endl;
    }

    return 0;
}