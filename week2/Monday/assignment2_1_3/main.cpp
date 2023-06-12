/*
You are teaching a programming course and you have many exercises that require peer reviews. 
The system that is hosting these exercises has broken and the automatic peer review assignment is not working. 
Write a program that lists all the students, and when the program gets run it will automatically create a peer review list
where every student gets to review someone else's exercise.
Each student will review another person and two students can't review each others assignments.
*/

#include <iostream>
#include <vector>
#include <algorithm> 

std::vector<std::string> fill_student_vector(){
    std::vector<std::string> students;

    std::string input;

    while (true) {
        std::cout << "Enter a student name (enter to stop): ";
        std::getline(std::cin, input);

        if (input == "") {
            break;
        }
        students.push_back(input);
    }
    return students;
}

void review_list (std::vector<std::string> students) {

    std::random_shuffle(students.begin(), students.end() );
    for (int i=0;i < students.size()-1;i++) {
        std::cout << students[i] << " reviews " << students[i+1] << ".\n";
    }
    std::cout << students[students.size()-1] << " reviews " << students[0] << ".\n";
}

int main()
{
    std::vector<std::string> students = fill_student_vector();

    review_list(students);






    return 0;
}
