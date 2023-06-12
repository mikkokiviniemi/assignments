#include <iostream>


//Didnt understand :(

int* allocate(int size) {
    int* array = new int[size];


    for (int i = 0; i < size; i++){
        array[i] = 3+i;
    }

    return array;

}

void print(int* array, int size){

    for(int i = 0; i < size; i++){
        
        std::cout << array[i] << " ";

    }

}
void dellocate(int* array){
    delete[] array;
}

int main () {

    int size = 7;

    int* nice_array = allocate(size);

    print(nice_array, size);

    std::cout << std::endl;

    dellocate(nice_array);


    return 0;
}