#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>

struct Device{
    std::string id;
    bool is_master;
    std::map<int,std::string> data;

};

//Can generate devices (one master and input for slaves)
std::vector<Device> fill_devices (int slaves);

//Fills devices to csv file (id,is_master)
void devices_to_file(const std::vector<Device>& devices, const std::string& filename);

//Fills registers to csv file (id,address,data)
void registers_to_file(const std::vector<Device>& devices, const std::string& filename);

//Reads devices and registers from csv files
void devices_registers_from_files(std::vector<Device>& devices, const std::string& device_file, const std::string& register_file);

//Get address value from device
std::string get_address_value(std::vector<Device> devices,std::string id,int address);

//Writes to address value
void write_address_value(std::vector<Device>& devices,std::string id,int address,std::string value);

#endif  