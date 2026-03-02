// Course Grades_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

//int ReadTxt(std::string file, std::string names[], int grades[], int a);

struct  Student
{
    std::string name;
    int id;
    int grade[5];
};


int main()
{
    int stud_num, test_num;
    int x = 0;
    std::string line;
    //std::string test_num;

    Student students[10];

    std::string filename = "student_data.txt";

    std::ifstream inputFile(filename);

    x = ReadTxt(filename, stud_num, test_num, students, x);


    //inputFile.close();

}

int ReadTxt(std::string file, int stud_n, int test_n, Student student[10], int a)
{
    std::string line;
    std::ifstream inputFile(file);

    //Ends program if the file cannot be opened
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Could not open the file";
        exit(EXIT_FAILURE);
    }

    // While the file is opened, fill the values of the name
    // and grades array, and keep track of the number of
    // names/lines in the txt file

    while (inputFile >> stud_n >> test_n)
    {
        std::cout << stud_n << std::setw(4) << test_n << std::endl;
        break;
    }

    std::getline(inputFile, line);

    while (inputFile >> student[a].name >> student[a].id >> student[a].grade[0] >> student[a].grade[1] >>
        student[a].grade[2] >> student[a].grade[3] >> student[a].grade[4])
    {
        //x++;
        std::cout << std::setw(8) << student[a].name << std::setw(6) << student[a].id
            << std::setw(4) << student[a].grade[0] << std::setw(4) << student[a].grade[1] <<
            std::setw(4) << student[a].grade[2] << std::setw(4) << student[a].grade[3] <<
            std::setw(4) << student[a].grade[4] << std::endl;

        a++;
    }


    /*while (inputFile >> students[x].name >> students[x].id >> students[x].grade[0] >> students[x].grade[1] >>
        students[x].grade[2] >> students[x].grade[3] >> students[x].grade[4])
    {
        //x++;
        std::cout << std::setw(8) << students[x].name << std::setw(6) << students[x].id
            << std::setw(4) << students[x].grade[0] << std::setw(4) << students[x].grade[1] <<
            std::setw(4) << students[x].grade[2] << std::setw(4) << students[x].grade[3] <<
            std::setw(4) << students[x].grade[4] << std::endl;

        x++;
    }*/


    inputFile.close();
    return a;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
