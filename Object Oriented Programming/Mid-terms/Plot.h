//plot.h implementation
//own code
#pragma once
#include <vector>
#include "Candlestick.h"
#include "point.h"

//this class handles all plotting related tasks 
class Plot {
    public:
        //function to plot the candlestick data, takes in a vector of candlestick objects
        //and prints it to the console in a simple text-based format
        static void plotCandlestick(std::vector<Candlestick> candlesticks);

        //function to plot the regression line, takes in a vector of Point objects
        //Purpose is to plot the points of the regression line
        // Takes input params: vector of Point objects
        static void plotLine(std::vector<Point> data);

        //function to plot a table of data, takes in a vector of Point objects
        //purpose to 
        static void plotTable(std::vector<Point> data);
        
};
//end of own code
