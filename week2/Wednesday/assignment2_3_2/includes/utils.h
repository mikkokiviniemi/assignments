#ifndef UTILS_H
#define UTILS_H


#include <iostream>
#include "utils.h"
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>

//Each reading is an object that includes a timestamp (use integers for simplicity), a sensor ID (string), and a sensor value (float).
struct Sensor_object {
    std::string id;
    int timestamp = 0;
    float value = 0.0f;
};

float rand_float(float min, float max);

std::vector<Sensor_object> data_ingestion_simulator (std::string id, int time, float min, float max);

std::vector<Sensor_object> data_list (std::vector<Sensor_object> data, std::string id);

bool data_comp (Sensor_object obj1, Sensor_object obj2);

void sorted_data (std::vector<Sensor_object>& data);

float mean_sensor_value (std::vector<Sensor_object>& data);

std::vector<Sensor_object> detect_outlier (std::vector<Sensor_object>& data, float deviation);

std::string highest_frequency (std::vector<Sensor_object>& data);

void print_data (std::vector<Sensor_object>& data);


#endif