//Main.cpp implementation
// This is the main entry point of the program, which reads weather data from a CSV file,
// computes candlesticks for each country, and provides a menu for the user to interact with the data.
// The user can plot candlesticks for all countries, filter by country or year range, and perform temperature trend analysis using linear regression.
//own code
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "CSV.h"
#include "WeatherDataEntry.h"
#include "Candlestick.h"
#include "candleGenerator.h"
#include "Plot.h"
#include "candlefilter.h"
#include "regression.h"



std::vector<std::string> countries = {
            "AT", "BE", "BG", "CH", "CZ", "DE", "DK", "EE", "ES", "FI", "FR",
            "GB", "GR", "HR", "HU", "IE", "IT", "LT", "LU", "LV", "NL", "NO",
            "PL", "PT", "RO", "SE", "SI", "SK"
};

int main()
{
    
    std::cout << "Reading weather data from CSV file... gonna take a while" << std::endl;
    //read the weather data from the CSV file
    std::ifstream file("weather_data.csv");
    if (!file.is_open()) 
    {
        //if the file cannot be opened, print an error message and exit
        std::cerr << "Error: Unable to open file." << std::endl;
        return 1;
    }
    //Store the weather data entries in a vector of WeatherDataEntry objects
    std::vector<WeatherDataEntry> weatherDataEntries = CSV::readLine(file);
    //Check if the entries were loaded successfully
    std::cout<< "Weather Data Entries Loaded: " << weatherDataEntries.size() << std::endl;

    std::cout << "computing all candlesticks, this may take a while..." << std::endl;
    //Store the candlesticks for all countries in a map, where the key is the country code and the value is a vector of Candlestick objects
    //The computeCandlesticks function takes in the weather data entries and the list of countries
    //and returns a map of candlesticks for each country
    //The Candlestick objects are computed from the WeatherDataEntry objects
    //The Candlestick objects contain the time_key, open, close, high, and low values for each country
    std::map<std::string, std::vector<Candlestick>> allCandlesticks = CandleGenerator::computeCandlesticks(weatherDataEntries, countries);
    std::cout << "All candlesticks computed successfully." << std::endl;
    auto exit = false;
    do 
    {
        try
        {
            std::cout <<"========================"<<std::endl;
            std::cout <<"|| Main Menu          ||"<<std::endl;
            std::cout <<"========================"<<std::endl;
            std::cout <<"||1. Plot for all countries " << std::endl;
            std::cout <<"||2. Plot filtered data by country" << std::endl;
            std::cout <<"||3. Plot filtered data by year range" <<std::endl;
            std::cout <<"||4. Plot filtered data by country and year range" <<std::endl;
            std::cout <<"||5. Temperature trend analysis (Linear Regression)" <<std::endl;
            std::cout <<"||6. Exit" <<std::endl;
            std::cout <<"========================"<<std::endl;

            int input;
            std::cin >>input;


            switch(input)
            { 
                case 1: //if user selects 1, plot candlesticks for all countries
                {
                    // // test to see if the candlesticks for GB are present and correct
                    // if (allCandlesticks.find("AT") != allCandlesticks.end()) {
                    //     std::cout << "\nCandlestick data for GB:\n";
                    //     for (const auto& c : allCandlesticks["GB"]) {
                    //         std::cout << "Time: " << c.time_key 
                    //                   << ", Open: " << c.open 
                    //                   << ", Close: " << c.close 
                    //                   << ", High: " << c.high 
                    //                   << ", Low: " << c.low << std::endl;
                    //     }
                    //     std::cout <<"num of candlesticks in GB " << allCandlesticks["GB"].size() << std::endl;
                    // } else {
                    //     std::cout << "No data for GB.\n";
                    // }
                    std::cout << "Plotting candlesticks for all countries..." << std::endl;
                    for (const auto& country : countries){
                        std::cout << "Plotting candlesticks for country: " << country << std::endl;
                        Plot::plotCandlestick(allCandlesticks[country]);
                    };
                    break;

                }
                case 2: //if user selects 2, plot candlesticks for a specific country
                {
                    std::string country;
                    std::cout << "Enter country code (e.g., AT, BE, etc.): ";
                    std::cin >> country;
                    auto countryCandles = CandleFilter::filterByCountry(allCandlesticks, country);
                    Plot::plotCandlestick(countryCandles);
                    std::cout << "Plotting candlesticks for country: " << country << std::endl;
                    break;
                }
                case 3: //if user selects 3, plot candlesticks for a specific year range
                {
                    int startYear, endYear;
                    std::cout << "Enter start year: ";
                    std::cin >> startYear;
                    std::cout << "Enter end year: ";
                    std::cin >> endYear;
                    std::vector<Candlestick> combined;
                    for (const auto& [country, candles] : allCandlesticks){
                        auto filtered = CandleFilter::filterByYearRange(candles, startYear, endYear);
                        combined.insert(combined.end(), filtered.begin(), filtered.end());
                    }
                    Plot::plotCandlestick(combined);
                    std::cout << "Plotting candlesticks for all regions of the specified year range: " << startYear << " to " << endYear << std::endl;
                    break;
                }
                case 4: //if user selects 4, plot candlesticks for a specific country and year range
                {
                    std::string country;
                    int startYear, endYear;
                    std::cout << "Enter country code (e.g., AT, BE, etc.): ";
                    std::cin >> country;
                     // Check if the country code is valid
                    if (allCandlesticks.find(country) == allCandlesticks.end()) {
                        std::cerr << "Invalid country code. Please try again." << std::endl;
                        continue; // Skip to the next iteration of the loop
                    }
                    std::cout << "Enter start year: ";
                    std::cin >> startYear;
                    std::cout << "Enter end year: ";
                    std::cin >> endYear;
                    // Validate the year range
                    if (startYear > endYear) {
                        std::cerr << "Invalid year range. Start year must be less than or equal to end year." << std::endl;
                        continue; // Skip to the next iteration of the loop
                    }
                   
                    auto countryCandles = CandleFilter::filterByCountry(allCandlesticks, country);
                    auto filteredCandles = CandleFilter::filterByYearRange(countryCandles, startYear, endYear);
                    Plot::plotCandlestick(filteredCandles);
                    break;
                }
                case 5: //if user selects 5, perform temperature trend analysis
                {
                    std::string country;
                    std::cout << "Enter country code (e.g., AT, BE, etc.): ";
                    std::cin >> country;
                    std::cout <<"Fitting data for country: " << country << std::endl;
                    auto countryCandles = CandleFilter::filterByCountry(allCandlesticks, country);
                    std::cout<<"Calculating regression for country: " << country << std::endl;
                    auto regressionData = regression::calculateRegression(countryCandles, country);
                    std::cout << "Plotting regression data for country: " << country << std::endl;
                    Plot::plotLine(regressionData);
                    std::cout << "Legend: " <<std::endl;
                
                    std::cout<< "\tx - actual" << std::endl;
                    std::cout<< "\to - predicted" << std::endl;
                    std::cout<< std::endl;
                    Plot::plotTable(regressionData);
                    std::cout << "Temperature trend analysis completed for country: " << country << std::endl;
                    break;
                }
                case 6:
                {
                    exit = true;
                    break;
                }
                default:
                {
                    std::cout << "Invalid option. Enter 1-6" << std::endl;
                    break;
                }
            }            
        }
        catch (const std::exception& e) 
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    while (!exit);
    std::cout<< "Exiting program..." << std::endl;
    file.close();
    std::cout << "File closed successfully." << std::endl;
    return 0;
}
//end of own code