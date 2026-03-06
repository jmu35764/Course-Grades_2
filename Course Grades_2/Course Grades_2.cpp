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
    int *grade;
};

Student *ReadData(std::string file, int &stud_n, int &test_n);

int main()
{
    int stud_num, test_num;
    std::string line;

    Student* std_ptr;
    
    //Student *std_ptr = new Student[10];
    //std_ptr->grade[5] = new int[5];

    std::string filename = "Student_data.txt";

    std::ifstream inputFile(filename);

    std_ptr = ReadData(filename, stud_num, test_num);

    std::cout << std::setw(4) << stud_num << std::setw(4) << test_num << std::endl;

    for (int i = 0; i < stud_num; i++)
    {
        std::cout << std::setw(10) << std_ptr[i].name << std::setw(6) << std_ptr[i].id;

        for (int j = 0; j < test_num; j++)
        {
            std::cout << std::setw(4) << std_ptr[i].grade[j];
        }

        std::cout << std::endl;
    }
    

    //inputFile.close();
    //delete[] grade_ptr;
    delete[] std_ptr->grade;
    delete[] std_ptr;
    

}

Student *ReadData(std::string file, int &stud_n, int &test_n)
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

    //while 

    inputFile >> stud_n >> test_n;
    //std::cout << stud_n << std::setw(4) << test_n << std::endl;


    Student *student_list = nullptr;
    student_list = new Student[stud_n];

    for (int i = 0; i < stud_n; i++)
    {
        inputFile >> student_list[i].name >> student_list[i].id;

        //std::cout << " " << student_list[i].name << " " << student_list[i].id;
            
        student_list[i].grade = new int[test_n];

        for (int j = 0; j < test_n; j++)
        {
            inputFile >> student_list[i].grade[j];

            //std::cout << " " << student_list[i].grade[j];
        }

        //std::cout << std::endl;
    }
       inputFile.close();
    return student_list;
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
