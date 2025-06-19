//plot.cpp implementation
// Will contain the plotting logic for the candlestick data
#include "Plot.h"
#include <iostream>
#include <string>
#include <vector>

//function to plot the candlestick data, takes in a vector of candlestick objects.
//and prints it to the console in a simple text-based format
//Does not takes in the country code, as the candlestick data is already filtered by country
void Plot::plotCandlestick(std::vector<Candlestick> candlesticks) {
    
    //need to find the max and min values for the y-axis and x-axis to find the range of the plot
    //set the initial values to the first candlestick's values
    int y_max = candlesticks[0].high;
    int y_min = candlesticks[0].low;
    int x_max = candlesticks[0].time_key;
    int x_min = candlesticks[0].time_key;

    //Iterate through the candlesticks to find the highest and lowest values for y-axis and x-axis
    for (auto candlestick: candlesticks){
        if (candlestick.high > y_max) {
            y_max = candlestick.high;
        }
        if (candlestick.low < y_min) {
            y_min = candlestick.low;
        }
        if (candlestick.time_key > x_max) {
            x_max = candlestick.time_key;
        }
        if (candlestick.time_key < x_min) {
            x_min = candlestick.time_key;
        }
    }

    // Adjust the y-axis range to create space for the header
    y_max += 2;
    y_min -= 2; 

    // Print the header for the plot
    for (auto i = y_max; i>= y_min; --i){
        printf("%03d|", i);
        for (auto candlestick : candlesticks)
        {
            if (i <= std::max(candlestick.open, candlestick.close) && i >= std::min(candlestick.open, candlestick.close))
                // Prints v when open > close
                // Else ^ when close > open
                printf(" [%c] ", candlestick.open > candlestick.close ? 'v' : '^');
            else if (i == candlestick.high || i == candlestick.low)
                printf(" --- ");
            else if (i <= candlestick.high && i >= candlestick.low)
                printf("  |  ");
            else
                printf("     ");
        }
        printf("\n");
    }

    for(auto i = x_min; i <= x_max; ++i) {
        std::cout << "-----";
    }

    std::cout << std::endl;
    std::cout << "   ";

    for (auto i = x_min; i <= x_max; i++){
        printf(" %04d", i);
    }
    // Iterate through each candlestick and print its data
    for (const auto& candle : candlesticks) {
        std::cout << candle.time_key << "\t"
                  << candle.open << "\t"
                  << candle.high << "\t"
                  << candle.low << "\t"
                  << candle.close << std::endl;
    }
}