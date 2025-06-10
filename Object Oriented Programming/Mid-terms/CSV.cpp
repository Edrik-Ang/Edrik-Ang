//Implementation of the CSV.cpp class
//task: 
//1. Readthe CSV file line by line
//2. Tokenise each line based on the separator (,)
//3. Store each WeatherDataEntry object in a vector for later use
#include "CSV.h"
#include <fstream>
#include <iostream>

CSV::CSV(){}

std::vector<WeatherDataEntry> CSV::readLine(std::istream &filename) {
    std::vector<WeatherDataEntry> weatherDataEntries;
    std::string line;

    // Read the first line (header) and ignore it
    std::getline(filename, line);

    // Read each subsequent line
    while (std::getline(filename, line)) {
        std::vector<std::string> tokens = tokenise(line, ',');
        if (tokens.size() < 29) continue; // Ensure there are enough tokens

        // Create a WeatherDataEntry object from the tokens
        WeatherDataEntry entry(
            tokens[0], // timestamp
            std::stod(tokens[1]), // AT
            std::stod(tokens[2]), // BE
            std::stod(tokens[3]), // BG
            std::stod(tokens[4]), // CH
            std::stod(tokens[5]), // CZ
            std::stod(tokens[6]), // DE
            std::stod(tokens[7]), // DK
            std::stod(tokens[8]), // EE
            std::stod(tokens[9]), // ES
            std::stod(tokens[10]), // FI
            std::stod(tokens[11]), // FR
            std::stod(tokens[12]), // GB
            std::stod(tokens[13]), // GR
            std::stod(tokens[14]), // HR
            std::stod(tokens[15]), // HU
            std::stod(tokens[16]), // IE
            std::stod(tokens[17]), // IT
            std::stod(tokens[18]), // LT
            std::stod(tokens[19]), // LU
            std::stod(tokens[20]), // LV
            std::stod(tokens[21]), // NL
            std::stod(tokens[22]), // NO
            std::stod(tokens[23]), // PL
            std::stod(tokens[24]), // PT
            std::stod(tokens[25]), // RO
            std::stod(tokens[26]), // SE
            std::stod(tokens[27]), // SI
            std::stod(tokens[28])  // SK
        );

        weatherDataEntries.push_back(entry);
    }
    return weatherDataEntries;
}

//Referenced from Coursera Tokenise code
std::vector<std::string> CSV::tokenise(const std::string& csvLine, char sep)
{
   std::vector<std::string> tokens;
   signed int start, end;
   std::string token;
    start = csvLine.find_first_not_of(sep, 0);
    do{
        end = csvLine.find_first_of(sep, start);
        if (start == csvLine.length() || start == end)
            break;
        if (end >= 0) 
            token = csvLine.substr(start, end - start);
        else 
            token = csvLine.substr(start, csvLine.length() - start);
        tokens.push_back(token);
        start = end + 1;
    }while(end > 0);

   return tokens; 
}