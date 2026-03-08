// Course Grades_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>


//Initialize the Struct Student

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


// This function displays the names of students, their ids
// test scores, and letter grades by setting them all to values
// in a dynamcially allocated struct array.

int main()
{
    //Define variables for student number and test number
    int stud_num, test_num;

    //Create struct pointer
    Student* std_ptr;

    //Create filename string
    std::string filename = "Student_data.txt";


    // Sets the value of the student pointer to the value
    // that is returned in the ReadData functon
    std_ptr = ReadData(filename, stud_num, test_num);

    // Calculates average test score of each student
    calc_average(std_ptr, stud_num, test_num);

    // Sets the letter grade for each student in the struct 
    // array
    for (int i = 0; i < stud_num; i++)
    {
        std_ptr[i].letter = ConvertScore(std_ptr, i);
    }

    // Displays a report of the students names, id's
    // Test grades, and letter grades
    Report(std_ptr, stud_num, test_num);
    
    // Deallocates memory for first the grade array pointer 
    // and then the struct array pointer
    delete[] std_ptr->grade;
    delete[] std_ptr;
    

}

Student *ReadData(std::string file, int &stud_n, int &test_n)
{
    //Create inputeFile object for input operations
    std::ifstream inputFile(file);

    //Ends program if the file cannot be opened
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Could not open the file";
        exit(EXIT_FAILURE);
    }

    // Set value of student number and test number
    // to the first two values in the first line
    // of the txt file
    inputFile >> stud_n >> test_n;

    //Set up pointer for struct array
    Student *student_list = nullptr;

    // Dynamically allocate memory for
    // struct array
    student_list = new Student[stud_n];

    
    // First fills value for names and id in struct 
    // array
    for (int i = 0; i < stud_n; i++)
    {
        inputFile >> student_list[i].name >> student_list[i].id;
            
        student_list[i].grade = new int[test_n];

        for (int j = 0; j < test_n; j++)
        {
            // Then fills the values of the grade array
            // inside each struct
            inputFile >> student_list[i].grade[j];

        }

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
    // Create headers
    std::cout << "<number_of_students>" << " " << "<number_of_tests>" << std::endl;

    std::cout << std::setw(21) << std::left << stud_n << std::setw(17) << test_n << std::endl << std::endl;
    
    for (int i = 0; i < stud_n; i++)
    {
        // Display out student names and id
        std::cout << std::setw(10) << s[i].name << std::setw(6) << s[i].id;

        for (int j = 0; j < test_n; j++)
        {
            // Display student grades
            std::cout << std::setw(4) << s[i].grade[j];
        }

        // Display letter grades
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
