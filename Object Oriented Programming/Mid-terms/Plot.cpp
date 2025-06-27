//plot.cpp implementation
// Will contain the plotting logic for the candlestick data
//own code
#include "Plot.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
    // Adjust the y-axis, looks better with some padding
    y_max += 2;
    y_min -= 2; 
    //PlotCandlestick function takes reference from https://simgejl.notion.site/Midterm-Essential-Logics-to-Generate-Text-based-Plots-d03a45ee1d10404986623dc3190b9ee6
    //Code is modified to suit the candlestick data structure
    // Print the header for the plot
    for (auto i = y_max; i>= y_min; --i){ //check each y value from y_max to y_min
        printf("%03d|", i);
        for (auto candlestick : candlesticks) //go through each candlestick
        {   // draws the vertical points row by row
            // If the current y value is equal to the open or close price of the candlestick
            if (i <= std::max(candlestick.open, candlestick.close) && i >= std::min(candlestick.open, candlestick.close))
                // Prints v when open > close
                // Else ^ when close > open
                printf(" [%c] ", candlestick.open > candlestick.close ? 'v' : '^'); // draw v if open > close, else draw ^ if close > open
            else if (i == candlestick.high || i == candlestick.low)
                printf("  -  "); //draw - if i is equal to high or low to mark the high-low range
            else if (i <= candlestick.high && i >= candlestick.low)
                printf("  |  "); //draw | if i inside high-low range but not 
            else
                printf("     "); //draw empty space if i is not inside the high-low range
        }
        printf("\n");
    }
    //This next step prints the x-axis header
    //it prints a line of --- for each x-axis value
    for(auto i = x_min; i <= x_max; ++i) {
        std::cout << "-----";
    }
    std::cout << std::endl;
    std::cout << "   ";
    //prints the year labels for each candlestick
    for (auto i = x_min; i <= x_max; i++){
        printf(" %04d", i);
    }
    std::cout << std::endl; //tidy abit here
    // Iterate through each candlestick and print its data
    // print out each candlestick data at the bottom of the plot
    std::cout << "\nYear\tOpen\tHigh\tLow\tClose" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    for (const auto& candle : candlesticks) {
        std::cout << candle.time_key << "\t"
                  << candle.open << "\t"
                  << candle.high << "\t"
                  << candle.low << "\t"
                  << candle.close << std::endl;
    }
}

//function to plot the regression line, takes in a vector of Point objects 
//Takes input params: vector of Point objects
//Prints a simple text-based plot of the regression line
//The x-axis represents the x value, and the y-axis represents the actual value
//The symbol is used to differentiate between actual and predicted values
//'x' for actual values and 'o' for predicted values
////Purpose is to plot the points of the regression line
void Plot::plotLine(std::vector<Point> points) {
    //store the actual and predicted points in separate vectors
    std::vector<Point> actualPoints;
    std::vector<Point> predictedPoints;
    for (const auto& point : points) {
        if (point.symbol == 'x')
            actualPoints.push_back(point);
        else if (point.symbol == 'o')
            predictedPoints.push_back(point);
    }

    std::sort(actualPoints.begin(), actualPoints.end(), [](const Point& a, const Point& b) {
        return a.x < b.x;
    });

    // Take the latest 5 years from the end
    std::vector<Point> filtered;
    int actualCount = actualPoints.size();
    for (int i = std::max(0, actualCount - 5); i < actualCount; ++i) {
        filtered.push_back(actualPoints[i]);
    }

    // Add predicted points
    filtered.insert(filtered.end(), predictedPoints.begin(), predictedPoints.end());

    // Find the min and max values for x and y axes
    int x_min = filtered[0].x;
    int x_max = filtered[0].x;
    float y_min = filtered[0].actual;
    float y_max = filtered[0].actual;
    // Iterate through the filtered points to find the min and max values
    // for both x and y axes
    for (const auto& point : filtered) {
        if (point.actual > y_max) y_max = point.actual;
        if (point.actual < y_min) y_min = point.actual;
        if (point.x > x_max) x_max = point.x;
        if (point.x < x_min) x_min = point.x;
    }
    // Calculate the range for plotting
    float y_range = y_max - y_min;
    int plot_height = 20; 
    float y_plot_min = y_min - y_range * 0.1f; // Looks better with some padding
    float y_plot_max = y_max + y_range * 0.1f;
    // Print the plot from top to bottom
    for (int row = plot_height; row >= 0; --row) {
        // Calculate the actual temperature value for this row
        float current_y = y_plot_min + (y_plot_max - y_plot_min) * row / plot_height;
        // print y-axis label at intervals of 5, 0 and plot_height
        if (row % 5 == 0 || row == plot_height || row == 0) {
            printf("%6.1f|", current_y);
        } else {
            printf("      |"); 
        }
        // For every year, check if a pt needs to be plotted
        for (int year = x_min; year <= x_max; ++year) {
            bool point_plotted = false;
            // Check if any point should be plotted at this position
            for (const auto& point : filtered) {
                if (point.x == year) {
                    // imrpove the tolerance check to allow for slight variations in y values
                    float tolerance = (y_plot_max - y_plot_min) / (2 * plot_height);
                    if (std::abs(point.actual - current_y) <= tolerance) {
                        printf("  %c  ", point.symbol);
                        point_plotted = true;
                        break;
                    }
                }
            }
            // print space if no pt was plotted here.
            if (!point_plotted) {
                printf("     ");
            }
        }
        printf("\n");
    }

    // Print the x-axis header at the bottom of the plot
    printf("      ");
    for (int i = x_min; i <= x_max; ++i)
        std::cout << "-----";
    std::cout << "\n      ";

    // Print the year labels for each point
    for (int i = x_min; i <= x_max; ++i)
        printf(" %04d", i);
    std::cout << std::endl;
}

//function to plot a table of data, takes in a vector of Point objects
//Takes input params: vector of Point objects
//Prints the x value, actual value and symbol for each point in the vector at bottom of the plot
//Purpose is to provide a summary of the actual and predicted values in a tabular format
//The symbol is used to differentiate between actual and predicted values
void Plot::plotTable(std::vector<Point> points) {
    //store the actual and predicted points in separate vectors
    std::vector<Point> actualPoints;
    std::vector<Point> predictedPoints;

    // Separate actual and predicted points
    for (const auto& point : points) {
        if (point.symbol == 'x') {
            actualPoints.push_back(point);
        } else if (point.symbol == 'o') {
            predictedPoints.push_back(point);
        }
    }

    // Sort actual points by descending temperature
    std::sort(actualPoints.begin(), actualPoints.end(), [](const Point& a, const Point& b) {
        return a.x > b.x;
    });

    std::cout << "\nLast 5 Years:\n";
    std::cout << "Year | Temp   | Type\n";
    std::cout << "--------------------------\n";
    // Print the latest 5 years (highest years) from actualPoints
    int n = actualPoints.size();
    for (int i = 0; i < std::min(5, n); ++i) {
        const auto& p = actualPoints[i];
        printf("%4d | %.4f | (actual)\n", p.x, p.actual); 
    }

    // Sort predicted points by ascending temperature
    std::cout << "\nNext 12-Year Temperature Predictions:\n";
    std::cout << "Year | Temp   | Type\n";
    std::cout << "--------------------------\n";
    // Print the next 12 years (lowest years) from predictedPoints
    for (const auto& p : predictedPoints) {
        printf("%4d | %.4f | (predicted)\n", p.x, p.actual); 
    }
}
//end of own code

// Note: The above code assumes that the Candlestick and Point classes are defined as per the provided snippets.
// Make sure to include the necessary headers and link against the required libraries when compiling this code.