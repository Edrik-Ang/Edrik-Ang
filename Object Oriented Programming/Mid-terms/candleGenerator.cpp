//Task 1:
//this will create a candlestick and store them inside a vector candlestick object called candlesticks.
//tasks include:
//1. group the data yearly
//2. Calculate the average, high, lows
//3. Calculate the open from previous period and transfer to current close period.
#include <iostream>
#include <vector>
#include "Candlestick.h"
#include "WeatherDataEntry.h"
#include "candleGenerator.h"
#include <map>
#include <numeric> // For std::accumulate
#include <algorithm> // For std::max_element and std::min_element

//Function to compute a vector of candlesticks for a country from a vector of WeatherDataEntry objects.
std::vector<Candlestick> CandleGenerator::computeCandlesticks(const std::vector<WeatherDataEntry>& entries, const std::string& country){

    std::map<std::string, std::vector<double>> YearlyData;

    // Group data by year
    for (const auto& entry : entries){
        std::string year = entry.timestamp.substr(0, 4); // Extract the year from the timestamp
        double temp;

        //choose the temperature based on the country selected
        if (country == "AT") {
            temp = entry.AT;
        } else if (country == "BE") {
            temp = entry.BE;
        } else if (country == "BG") {
            temp = entry.BG;
        } else if (country == "CH") {
            temp = entry.CH;
        } else if (country == "CZ") {
            temp = entry.CZ;
        } else if (country == "DE") {
            temp = entry.DE;
        } else if (country == "DK") {
            temp = entry.DK;
        } else if (country == "EE") {
            temp = entry.EE;
        } else if (country == "ES") {
            temp = entry.ES;
        } else if (country == "FI") {
            temp = entry.FI;
        } else if (country == "FR") {
            temp = entry.FR;
        } else if (country == "GB") {
            temp = entry.GB;
        } else if (country == "GR") {
            temp = entry.GR;
        } else if (country == "HR") {
            temp = entry.HR;
        } else if (country == "HU") {
            temp = entry.HU;
        } else if (country == "IE") {
            temp = entry.IE;
        } else if (country == "IT") {
            temp = entry.IT;
        } else if (country == "LT") {
            temp = entry.LT;
        } else if (country == "LU") {
            temp = entry.LU;
        } else if (country == "LV") {
            temp = entry.LV;
        } else if (country == "NL") {
            temp = entry.NL;
        } else if (country == "NO") {
            temp = entry.NO;
        } else if (country == "PL") {
            temp = entry.PL;
        } else if (country == "PT") {
            temp = entry.PT;
        } else if (country == "RO") {
            temp = entry.RO;
        } else if (country == "SE") {
            temp = entry.SE;
        } else if (country == "SI") {
            temp = entry.SI;
        } else if (country == "SK") {
            temp = entry.SK;
        }

        YearlyData[year].push_back(temp);
    
    }

    //Step 2 compute open, high, low and close for each year
    std::vector<Candlestick> candlesticks;
    std::string prevYear = "";
    double prevAvg = 0.0;

    // Iterate through the yearly data to compute candlesticks
    for (const auto& [year, temps]: YearlyData){
        if (temps.empty()) continue; // Skip empty years
        double sum = std::accumulate(temps.begin(), temps.end(), 0.0); // add up all the temperatures for the year
        double avg = sum /temps.size(); // Calculate the average temperature for the year
        double high = *std::max_element(temps.begin(), temps.end()); // Find the highest temperature for the year
        double low = *std::min_element(temps.begin(), temps.end()); // Find the lowest temperature for the year

        double open = (prevYear =="") ? avg : prevAvg; // If the first year empty, set open to average of the current year, else set it to the previous year's average
        double close = avg; // Close is the average of the current year
        candlesticks.emplace_back(std::stoi(year), open, close, high, low);
        prevYear = year; // Update previous year
        prevAvg = avg; // Update previous average

    }
    return candlesticks;
}
// Function to compute candlesticks for multiple countries from a vector of WeatherDataEntry objects
std::map<std::string, std::vector<Candlestick>> CandleGenerator::computeCandlesticks(
    const std::vector<WeatherDataEntry>& entries,
    const std::vector<std::string>& countries)
{
    std::map<std::string, std::vector<Candlestick>> allCandlesticks;

    for (const auto& country : countries) {
        allCandlesticks[country] = computeCandlesticks(entries, country);
    }

    return allCandlesticks;
}


//function to generate candles from a vector of Candlestick objects
//this function will print the candlestick data to the console
//Purpose is to check if the candlestick data is working correctly
void CandleGenerator::generateCandles(const std::vector<Candlestick>& candlesticks) {
       for (const auto& candle : candlesticks) {
                std::cout << "Year: " << candle.time_key
                          << "Candlestick - Open: " << candle.open 
                          << ", Close: " << candle.close 
                          << ", High: " << candle.high 
                          << ", Low: " << candle.low 
                          << std::endl;
            }
}
