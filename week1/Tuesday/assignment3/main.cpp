#include <iostream>
#include <vector>


/*
Create a student database program. The program will ask the user for how many students the user wants to input. 
For each student the program will store the students name, age and grade.
The program will then print out the average grade of the class and the student with the highest grade.
*/

struct Student {
    std::string name;
    int age;
    int grade;
};

//Fills student database vector.
std::vector<Student> studentDatabase (int count) {

    std::vector<Student> studentVector;

    for (int i = 0; i < count;i++) {
        
        std::cout << "Student " << i+1 << std::endl;

        Student newStudent;
        
        std::cout << "Enter name: ";
        std::cin >> newStudent.name;

        std::cout << "Enter age: ";
        std::cin >> newStudent.age;

        std::cout << "Enter grade: ";
        std::cin >> newStudent.grade;
        std::cout << std::endl;

        studentVector.push_back(newStudent);

    }

    return studentVector;
}

//Calculates average grade.
float averageGrade (std::vector<Student> students) {
    float total = 0.0;

    for (auto student : students) {
        total += student.grade;
    }   
    return total/students.size();
}

//Finds student with highest grade.
Student highestGrade (std::vector<Student> students) {

    Student highestGradeStudent = students[0];

    for (auto student : students) {
        if (student.grade > highestGradeStudent.grade) {
            highestGradeStudent = student;
        }
    }


    return highestGradeStudent;
}

int main()
{
    int studentCount;
    std::cout << "Enter number of the students: ";
    std::cin >> studentCount;
    std::cout << "\n";

    std::vector<Student> studentVector = studentDatabase(studentCount);

    std::cout << "Average grade: " << averageGrade(studentVector) << std::endl;

    std::cout << "Highest grade student: " << highestGrade(studentVector).name << std::endl;

    return 0;
}
