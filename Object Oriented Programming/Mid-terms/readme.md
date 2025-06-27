## How to Run the Project

1. Make sure the `weather_data_EU_1980-2019_temp_only.csv` file is in the main.cpp file.
2. Open a terminal in that folder.
3. Compile the project using the following command:
    ```sh
    g++ main.cpp CSV.cpp plot.cpp WeatherDataEntry.cpp candleGenerator.cpp Candlestick.h CandleFilter.cpp point.h regression.cpp
    ```
4. Run the compiled program:
    ```sh
    ./a.exe
    ```