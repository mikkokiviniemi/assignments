/*
Virtual Weather Station

Your task is to create a virtual weather station. The program should handle any exceptions that may occur during runtime. 

Handle various aspects like temperature, humidity, wind speed and atmospheric pressure.

Generate weather data via a function simulating changes in weather over time. 
Make sure the data changes in a way that's somewhat realistic. So the temperature should not jump from +20C to -20C

Implement exception handling. If data generated is out of logical range for example the temperature is less than -273.15C or humidity is over 100%. 

Log data in files. Handle any file-related exceptions like not being able to open the file. 

The console applications should be able to show logs and current weather. 
For testing purposes you can add a function that allows you to manually add weather readings.
*/

#include <iostream>
#include <fstream>
#include <exception>
#include <vector>
#include "weather.h"


void log_data (std::vector<Weather> data, std::string file_name) {
    std::ofstream file(file_name);
    if (!file.is_open()) {
        throw std::runtime_error ("Failed to open file \n");
    }
    file << "time (h),temperature (C),humidity (%),wind speed (m/s),atmospheric pressure (bar)\n";
    for (const auto& weather : data) {
        std::string data_string = 
        std::to_string(weather.time) + "," +
        std::to_string(weather.temperature) + "," +
        std::to_string(weather.humidity) + "," +
        std::to_string(weather.wind_speed) + "," +
        std::to_string(weather.atmospheric_pressure) + ",";
        file << data_string << "\n";

    }

    file.close();
}

int main()
{
    std::vector<Weather> weather_data = weather_simulator(6);

    print_weather_data(weather_data);

    log_data(weather_data,"./data/data.csv");

    return 0;
}
