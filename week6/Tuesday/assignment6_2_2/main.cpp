/*

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>

class Text_file_reader {
    public:
        Text_file_reader(const std::string& file_name) {
            file = std::fopen(file_name.c_str(), "r");
            if(!file) {
                throw std::runtime_error("Failed to open " + file_name);
            }
        }

        ~Text_file_reader() {
            if (file) {
                std::fclose(file);
            }
        }

        std::string read_line() {
            std::string line;
            int symbol = 0;
            while((symbol = std::fgetc(file)) != EOF && symbol != '\n'){
                line += static_cast<char>(symbol);
            }
            return line;
        }
    private:
        FILE* file;
};

int main()
{
    try {
        Text_file_reader readeri("./data/test.txt");
        std::string line;
        line = readeri.read_line();
        while (!line.empty()) {
            std::cout << line << "\n";
            line = readeri.read_line();
        }

    } catch (const std::exception& e){
        std::cout << e.what();
    }
    return 0;
}
