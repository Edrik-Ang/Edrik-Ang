//plot.h implementation
#pragma once
#include <vector>
#include "Candlestick.h"

//this class handles all plotting related tasks 
class Plot {
    public:
        //function to plot the candlestick data, takes in a vector of candlestick objects
        //and prints it to the console in a simple text-based format
        static void plotCandlestick(std::vector<Candlestick> candlesticks);

        //static void plotLine(std::vector<Point> data);

        //static void plotTable(std::vector<Point> data);
        
    };
