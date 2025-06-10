#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "CSV.h"
#include "WeatherDataEntry.h"
#include "Candlestick.h"
#include "candleGenerator.h"





int main(){

    //std::cout << "running test for CSV and WeatherDataEntry classes" << std::endl;
    //test can read the CSV file and store the data in WeatherDataEntry objects
    std::ifstream file("weather_data.csv");
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file." << std::endl;
        return 1;
    }
    std::vector<WeatherDataEntry> weatherDataEntries = CSV::readLine(file);

    std::cout<< "Weather Data Entries Loaded: " << weatherDataEntries.size() << std::endl;

    // if(!weatherDataEntries.empty()) {
    //     std::cout << "First Entry Timestamp: " << weatherDataEntries[0].timestamp << std::endl;
    //     std::cout << "First Entry AT: " << weatherDataEntries[0].AT << std::endl;
    //     std::cout << "First Entry BE: " << weatherDataEntries[0].BE << std::endl;
    //     std::cout << "First Entry BG: " << weatherDataEntries[0].BG << std::endl;
    //     std::cout << "First Entry CH: " << weatherDataEntries[0].CH << std::endl;
    // } else {
    //     std::cout << "No weather data entries found." << std::endl;
    // }

    std::string country = "AT"; // Example country
    std::vector<Candlestick> candlesticks = CandleGenerator::computeCandlesticks(weatherDataEntries, country);
    std::cout << "Candlesticks generated for country: " << country << std::endl;
    CandleGenerator generator;
    for (const auto& candle : candlesticks) {
    generator.generateCandles(candlesticks); 
    }
    
    

    return 0;
}