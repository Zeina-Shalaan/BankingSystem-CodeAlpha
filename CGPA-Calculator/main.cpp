#include <iostream>
#include <string>
using namespace std;

struct CourseDetails
{
    string CourseName;
    double CreditHours ;
    double Grade;
};
struct StudentInfo
{
    CourseDetails CousreList[10];
    int NumberOfCourses = 0;
    int TotalCredits = 0;
    double TotalGradePTS = 0.0;
    double CumlativeGRDPTS = 0.0;
    int CumlativeCredits = 0;
    double GPA = 0.0;
    double CGPA = 0.0;
};

double GradeToPoint(double g)
{
    if (g >= 90)
        return 4.0;
    else if (g >= 80)
        return 3.0;
    else if (g >= 70)
        return 2.0;
    else if (g >= 60)
        return 1.0;
    return 0.0;
}

void AddCourse(StudentInfo &stu,string name, int credits,double GRD)
{
    //check if there is space in array
    if (stu.NumberOfCourses < 10)
    {
        stu.CousreList[stu.NumberOfCourses].CourseName = name ;
        stu.CousreList[stu.NumberOfCourses].CreditHours = credits;
        stu.CousreList[stu.NumberOfCourses].Grade = GRD;

        //update credits and grades
        stu.TotalCredits += credits;
        stu.TotalGradePTS += credits * GradeToPoint(GRD);

        stu.NumberOfCourses++;
    }
    else
    {
        cout << "Course list full , cannot add anymore course \n";
    }
}

double CalculateSEM_GPA(StudentInfo &stu)
{
    if (stu.TotalCredits > 0)
    {
        return stu.TotalGradePTS / stu.TotalCredits;
    }
    else
        return 0.0;
}

double Calculate_CUMELATIVE(StudentInfo &stu)
{
    stu.CumlativeGRDPTS += stu.TotalGradePTS;
    stu.CumlativeCredits += stu.TotalCredits;

    if (stu.CumlativeCredits == 0)
    {
        return 0.0;
    }
    return stu.CumlativeGRDPTS / stu.CumlativeCredits;
}

 void displayResults(StudentInfo &stu)
 {
        cout << "Course Details:\n";
        for (int i = 0; i < stu.NumberOfCourses ; i++) {
            cout << "Course: " << stu.CousreList[i].CourseName
                 << " | Credits: " << stu.CousreList[i].CreditHours
                 << " | Grade: " << stu.CousreList[i].Grade
                 << " | Grade Points: " << GradeToPoint(stu.CousreList[i].Grade) << "\n";
        }
        cout << "Total Credits for Semester: " << stu.TotalCredits << "\n";
        cout << "Total Grade Points for Semester: " << stu.TotalGradePTS << "\n";
        cout << "GPA for Semester: " << CalculateSEM_GPA(stu) << "\n";

        cout << "\nCumulative Credits: " << stu.CumlativeCredits << "\n";
        cout << "Cumulative Grade Points: " << stu.CumlativeGRDPTS << "\n";
        cout << "Cumulative GPA (CGPA): " << Calculate_CUMELATIVE(stu) << "\n";
}

void ResetSem (StudentInfo &stu)
{
    stu.NumberOfCourses = 0;
    stu.TotalCredits = 0;
    stu.TotalGradePTS = 0.0;
}

void NewSemester(StudentInfo &stu) {
    // Calculate semester GPA
    stu.GPA = CalculateSEM_GPA(stu);

    // Update CGPA with current semester
    stu.CGPA = Calculate_CUMELATIVE(stu);

    // Display results for the current semester
    displayResults(stu);

    // Reset semester-specific data
    ResetSem(stu);
}

int main()
{
    StudentInfo student;

    int NumCourses, NumSemesters;
    string coursename;
    int credits;
    double grade;

    cout << "Enter the number of semesters: ";
    cin >> NumSemesters;
    if (NumSemesters <= 0)
    {
        cout << " invalid number , try again: ";
        cin >> NumSemesters;
    }


    for (int i =0 ; i < NumSemesters ; i++)
    {

        cout << "\nSemester " << i+1 << ":\n";

        cout << "Enter the number of courses (up to 10): ";
        cin >> NumCourses;
        if (NumCourses <= 0)
        {
        cout << " number (invalid) , try again: ";
        cin >> NumCourses;
        }

         for (int j = 0; j < NumCourses; j++)
        {
            cout << "Enter Course Name:  ";
            cin.ignore();
            getline (cin,coursename);

            cout << "Enter Number Of Credit Hours: ";
            cin >> credits;

            if (credits <= 0)
            {
                cout << " invalid number , try again: ";
                cin >> credits;
            }

            cout << "Enter Your Grade (0-100) : ";
            cin >> grade;

            if (grade <= 0.0)
            {
                cout << " invalid grade ( must be from 0-100 ) , try again: ";
                cin >> NumSemesters;
            }

            AddCourse(student,coursename,credits,grade);
        }
        NewSemester(student);
    }


    return 0;
}
