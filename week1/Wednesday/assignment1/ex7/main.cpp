#include <iostream>

struct Data
{
    private:
        int variable = 3; //Laitetaan tommonen
    public:
        void setter(int new_value) {
            variable = new_value;
        }
        int getter() {
            return variable;
        }
};

int main()
{
    Data obj;

    obj.setter(7);

    //Prints 7
    std::cout << "Private variable: " << obj.getter() << std::endl;


    return 0;
}
