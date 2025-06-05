//CSV is the class that has the read methods for waether data CSV file. 
//Its purpose is to read each line in the csv file store each for later use.
#pragma once
#include "WeatherDataEntry.h"
#include <vector>
#include <fstream>
#include <map>
#include <string>


class CSV {
    public:
        CSV(); //default constructor

        //Two function need declare: read and tokenise
        //**Read function reads each line in the csv file */
        static std::vector<WeatherDataEntry> readLine(std::istream &filename);
        //**Tokenise function to break down each csv line based on the separator (,) */
        static std::vector<std::string> tokenise(const std::string& csvLine, char sep);
};