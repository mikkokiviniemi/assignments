#include "utils.h"

//Fills devices with one master and with slaves
std::vector<Device> fill_devices (int slaves) {
    std::vector<Device> devices;

    devices.push_back({ "Master", true });

    for (int i = 0; i < slaves; ++i) {
        std::string deviceId = "slave_" + std::to_string(i);
        std::map<int,std::string> data;
        for (int j = 0; j < 10; j++) {
            data[j] = "Data" + std::to_string(j);
        }
        devices.push_back({ deviceId, false, data});
    }

    return devices;
}

//Fills devices to csv file (id,is_master)
void devices_to_file(const std::vector<Device>& devices, const std::string& filename) {
    std::ofstream file(filename);
    
    if (!file.is_open()) {
        std::cout << "Failed to open file \n";
        return;
    }

    file << "id,is_master\n";
    for (const auto& device : devices) {
        file << device.id << "," <<device.is_master<< "\n";
    }

    file.close();
}

//Fills registers to csv file (id,address,data)
void registers_to_file(const std::vector<Device>& devices, const std::string& filename) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cout << "Failed to open file \n";
        return;
    }

    file << "id,address,data\n";
    for (const auto& device : devices) {
        if(!device.is_master) {
            for(auto& data : device.data) {
                std::string data_string = std::to_string(data.first) + "," + data.second;
                file << device.id << "," << data_string << "\n";
            }
        }
    }

    file.close();
}

//Reads devices and registers from csv files
void devices_registers_from_files(std::vector<Device>& devices, const std::string& device_file, const std::string& register_file) {
    std::ifstream device_stream(device_file);
    std::ifstream register_stream(register_file);

    if (!device_stream.is_open() || !register_stream.is_open()) {
        std::cout << "Failed to open file \n";
        return;
    }

    //Gets devices from csv file
    std::string device_line;
    std::getline(device_stream, device_line);
    while (std::getline(device_stream, device_line)) {
        std::string id;
        std::string is_master;
        std::istringstream iss(device_line);
        std::getline(iss, id, ',');
        std::getline(iss, is_master);
        Device new_device = {id, is_master == "1"};
        devices.push_back(new_device);
    }

    //Gets registers from csv file and put them to right slave
    std::string register_line;
    std::getline(register_stream, register_line);
    while (std::getline(register_stream, register_line)) {
        std::string id;
        std::string address;
        std::string value;
        std::istringstream iss(register_line);
        std::getline(iss, id, ',');
        std::getline(iss, address, ',');
        std::getline(iss, value);
        for (auto& device : devices) {
            if (device.id == id){
                device.data[std::stoi(address)] = value;
            }
        }

    }

    register_stream.close();
    device_stream.close();
}

//Get address value from device
std::string get_address_value(std::vector<Device> devices,std::string id,int address) {
    for(auto& device : devices) {
        if (device.id == id) {
            return device.data[address];
        }
    }

    return "";
}

//Writes to address value
void write_address_value(std::vector<Device>& devices,std::string id,int address,std::string value) {
    for(auto& device : devices) {
        if (device.id == id) {
            device.data[address] = value;
        }
    }

}