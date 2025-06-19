#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "CSV.h"
#include "WeatherDataEntry.h"
#include "Candlestick.h"
#include "candleGenerator.h"
#include "Plot.h"





int main()
{

    std::cout << "Reading weather data from CSV file... gonna take a while" << std::endl;

    std::ifstream file("weather_data.csv");
    if (!file.is_open()) 
    {
        std::cerr << "Error: Unable to open file." << std::endl;
        return 1;
    }
    std::vector<WeatherDataEntry> weatherDataEntries = CSV::readLine(file);

    std::cout<< "Weather Data Entries Loaded: " << weatherDataEntries.size() << std::endl;

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
            std::vector<std::string> countries = {
                        "AT", "BE", "BG", "CH", "CZ", "DE", "DK", "EE", "ES", "FI", "FR",
                        "GB", "GR", "HR", "HU", "IE", "IT", "LT", "LU", "LV", "NL", "NO",
                        "PL", "PT", "RO", "SE", "SI", "SK"
            };
            switch(input)
            { 
                case 1: //if user selects 1, plot candlesticks for all countries
                {
                    std::cout << "Plotting candlesticks for all countries..." << std::endl;
                  
                    std::map<std::string, std::vector<Candlestick>> allCandlesticks = CandleGenerator::computeCandlesticks(weatherDataEntries, countries);
                    std::cout << "Candlesticks computed for all countries." << std::endl;
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
              
                    break;
                }
                case 3: //if user selects 3, plot candlesticks for a specific year range
                {
                    int startYear, endYear;
                    std::cout << "Enter start year: ";
                    std::cin >> startYear;
                    std::cout << "Enter end year: ";
                    std::cin >> endYear;
                    // Call function to filter and plot data for the specified year range
                    break;
                }
                case 4: //if user selects 4, plot candlesticks for a specific country and year range
                {
                    std::string country;
                    int startYear, endYear;
                    std::cout << "Enter country code (e.g., AT, BE, etc.): ";
                    std::cin >> country;
                    std::cout << "Enter start year: ";
                    std::cin >> startYear;
                    std::cout << "Enter end year: ";
                    std::cin >> endYear;
                    // Call function to filter and plot data for the specified country and year range
                    break;
                }
                case 5: //if user selects 5, perform temperature trend analysis
                {
                    int startYear, endYear;
                    std::cout << "Enter start year: ";
                    std::cin >> startYear;
                    std::cout << "Enter end year: ";
                    std::cin >> endYear;
                    break;
                }
                case 6:
                {
                    exit = true;
                    break;
                }
                default:
                {
                    std::cout << "Invalid option. Please try again." << std::endl;
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