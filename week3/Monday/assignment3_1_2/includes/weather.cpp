#include "weather.h"
#include <iostream>
#include <vector>
#include <random>
#include <exception>


float random_float(float min, float max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(min, max);
    return dis(gen);
}

std::vector<Weather> weather_simulator (int hours) {
    std::vector<Weather> weather_data;

    for(int i = 1; i < hours + 1; i++) {
        float temperature = random_float(15.0,20.0);
        float humidity = random_float(45.0,55.0);
        float wind_speed = random_float(0.0,3.0);
        float atmospheric_pressure = 1.01325;

        Weather new_data = {temperature,humidity,wind_speed,atmospheric_pressure,i};
        weather_data.push_back(new_data);
    }

    return weather_data;
}

bool valid_data (Weather weather) {
    if(weather.time < 0) {
        throw std::logic_error("Time not logical\n");
    }
    if (weather.humidity > 100 || weather.humidity < 0) {
        throw std::logic_error("Humidity not logical\n");
    }
    if (weather.temperature < -273.15) {
        throw std::logic_error("Temperature not logical\n");
    }
    if (weather.wind_speed < 0) {
        throw std::logic_error("Wind speed not logical\n");
    }

    return true;
}

void check_data (std::vector<Weather> data) {
    bool valid = true;
    for (auto& weather : data) {
        valid = valid_data(weather);
    }
    if (valid) {
        std::cout << "Weather data ok \n";
    }
}

void print_weather_data (std::vector<Weather> data) {
    std::cout 
        << "Weather between: " << data.front().time << "-" << data.back().time << "\n";
    for(auto& weather : data) {
        try {
            bool valid = valid_data(weather);
            std::cout 
            << "Time:                 " << weather.time << " h\n"
            << "Temperature:          " << weather.temperature << " C\n"
            << "Humidity:             " << weather.humidity << " %\n"
            << "Wind speed:           " << weather.wind_speed << " m/s\n"
            << "Atmospheric pressure: " << weather.atmospheric_pressure << " Bar\n";
        } catch(std::exception& e) {
            std::cout << e.what();
        }
    }
}