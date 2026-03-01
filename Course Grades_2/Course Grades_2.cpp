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
    int grades[5][10];
    int id[10];
    std::string names[10];
    int x = 0;
    std::string line;
    //std::string test_num;
    
    //std::cout << "Hello World!\n";
    std::string filename = "student_data.txt";

    std::ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        std::cerr << "Error: Could not open the file";
        exit(EXIT_FAILURE);
    }
    //std::string firstline;

    while (inputFile >> stud_num >> test_num)
    {
        std::cout << stud_num << "  " << test_num;
        break;
    }

    std::getline(inputFile, line);

    while (inputFile >> names[x] >> id[x] >> grades[x][0] >> grades[x][1] >> 
            grades[x][2] >> grades[x][3] >> grades[x][4])
    {
        //x++;
        std::cout << std::setw(8) << names[x] << std::setw(6) << id[x]
            << std::setw(4) << grades[x][0] << std::setw(4) << grades[x][1] <<
            std::setw(4) << grades[x][2] << std::setw(4) << grades[x][3] << std::setw(4) << grades[x][4]
            << std::endl;
        
        x++;
    }

    //inputFile.close();

}

/*int ReadTxt(string file, string names[20], int grades[20][TESTNUMBER], int a)
{
    ifstream inputFile(file);

    //Ends program if the file cannot be opened
    if (!inputFile.is_open())
    {
        cerr << "Error: Could not open the file";
        exit(EXIT_FAILURE);
    }

    // While the file is opened, fill the values of the name
    // and grades array, and keep track of the number of
    // names/lines in the txt file
    while (inputFile >> names[a] >> grades[a][0] >> grades[a][1] >>
        grades[a][2] >> grades[a][3] >> grades[a][4])
    {
        a++;
    }

    inputFile.close();
    return a;
}*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
