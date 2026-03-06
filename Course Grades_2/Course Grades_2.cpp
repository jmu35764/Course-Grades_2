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
    double average=0;
    char letter;
};

Student *ReadData(std::string file, int &stud_n, int &test_n);
void calc_average(Student s[], int stud_n, int test_n);
char ConvertScore(Student s[], int stud_n);
void Report(Student s[], int stud_n, int test_n);

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

    //std::cout << std::setw(4) << stud_num << std::setw(4) << test_num << std::endl;

    /*for (int i = 0; i < stud_num; i++)
    {
        std::cout << std::setw(10) << std_ptr[i].name << std::setw(6) << std_ptr[i].id;

        for (int j = 0; j < test_num; j++)
        {
            std::cout << std::setw(4) << std_ptr[i].grade[j];
        }

        std::cout << std::endl;
    }*/

    calc_average(std_ptr, stud_num, test_num);

    for (int z = 0; z < stud_num; z++)
    {
        std_ptr[z].letter = ConvertScore(std_ptr, z);
    }
    

    /*for (int z = 0; z < stud_num; z++)
    {
        std::cout << z << " " << std_ptr[z].average << std::setw(3) << ConvertScore(std_ptr, z) << std::endl;
    }*/

    Report(std_ptr, stud_num, test_num);
    

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

void calc_average(Student s[], int stud_n, int test_n)
{
    // Initalize value of total to 0
    double total = 0;

    // First for loop is for each student
    for (int z = 0; z <= (stud_n - 1); z++)
    {
        //Second for loop is for the grades of each student
        for (int y = 0; y < test_n; y++)
        {
            total = s[z].grade[y] + total;
        }

        s[z].average = total / test_n;

        //std::cout << s[z].average << std::endl;

        // Resets value of total for each student
        total = 0;
    }


}

char ConvertScore(Student s[], int stud_n)
{
    // This function outputs a character value based on a numerical score

    char grade = 'z';

    if (s[stud_n].average <= 100 && s[stud_n].average >= 90)
    {
        grade = 'A';
    }

    else if (s[stud_n].average < 90 && s[stud_n].average >= 80)
    {
        grade = 'B';
    }

    else if (s[stud_n].average < 80 && s[stud_n].average >= 70)
    {
        grade = 'C';
    }

    else if (s[stud_n].average < 70 && s[stud_n].average >= 60)
    {
        grade = 'D';
    }

    else if (s[stud_n].average < 60)
    {
        grade = 'F';
    }

    return grade;
}

void Report(Student s[], int stud_n, int test_n)
{
    std::cout << "<number_of_students>" << " " << "<number_of_tests>" << std::endl;

    std::cout << std::setw(20) << stud_n << std::setw(17) << test_n << std::endl << std::endl;
    
    for (int i = 0; i < stud_n; i++)
    {
        std::cout << std::setw(10) << s[i].name << std::setw(6) << s[i].id;

        for (int j = 0; j < test_n; j++)
        {
            std::cout << std::setw(4) << s[i].grade[j];
        }

        std::cout << std::setw(3) << s[i].letter << std::endl;
    }

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
