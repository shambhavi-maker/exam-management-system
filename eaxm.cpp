#include <bits/stdc++.h>
using namespace std;

int total = 0;
char guess;
string str1 = "staffMember";
string str2;

vector<int> courseList;
vector<void> que;

class result
{
public:
    void getresult()
    {
        if (total >= 50)
            cout << "Congratulation you Pass the Quiz\n";
        else
            cout << "Fail the Quiz\n";
    }
};

class Question : public result
{
public:
    void setValues(string, string, string, string, string, char, int);
    void askQuestion();

private:
    string Question_Text;
    string answer_1;
    string answer_2;
    string answer_3;
    string answer_4;

    char correct_answer;
    int Question_Score;
};

// Student Result End

// Teacher Class Start
class Teacher
{
    int courseCode;
    string courseName;

public:
    void addCourse();
    void addQuiz();
    void editCourse();
    void deleteCourse();
};

void Teacher::addCourse()
{
    cout << "Enter Course Name : ";
    getline(cin, courseName);
    cout << "Enter Course Code : ";
    cin >> courseCode;
    courseList.push_back(courseCode);
}

void Teacher::addQuiz()
{
    for (int i = 0; courseList.size(); i++)
    {
        int code;
        cout << "Enter Course Code :";
        cin >> code;
        if (code == courseList[i])
        {
            cout << "Add Quiz\n\n";
            while (true)
            {
                int input;
                cout << "Press 1 : To add Question :" << endl;
                cout << "Press 2 : exit(0)" << endl;
                cin >> input;
                switch (input)
                {
                case 1:
                    Question q;
                    cout << "Values in the given Format i.e :" << endl;
                    cout << "Question, opt1, op2, op3, opt4, correct option a to d, marks";
                    que.push_back(q.setValues());
                    break;

                case 2:
                    exit(0);
                    break;
                }
                default: cout<<"Invalid Input";
            }
        }
        else{
            cout<<"Enter Valid Code";
        }
    }
}

void Teacher::deleteCourse()
{
    int val;
    cout << "Press 1 : To Delete all Courses." << endl;
    cout << "Press 2 : To Delete specific Course." << endl;

    if (val == 1)
    {
        courseList.clear();
    }

    else if (val == 2)
    {
        int courseCode;
        string courseName;

        cout << "Enter Course Name which you want to Delete : ";
        getline(cin, courseName);
        cout << "Enter Course Code : ";
        cin >> courseCode;

        for (int i = 0; i < courseList.size(); i++)
        {
            if (courseCode == courseList[i])
            {
                courseList[i--];
            }
        }
    }

    else
        cout << "Invalid Input";
}

// Student Class Start

class student
{
    long rollNo;
    string studentName;

public:
    student() {}
    void getdata();
    void display();
};

void student::getdata()
{
    cout << "\nEnter Students Roll no. : ";
    cin >> rollNo;
    cout << "\nEnter Student Name : ";
    getline(cin, studentName);
}

void student::display()
{
    cout << "\n---------------------------------------------------------------------------------\n";
    cout << "\nStudent Roll no.     ::" << rollNo;
    cout << "\nstudent Name         ::" << studentName;
    cout << "\n---------------------------------------------------------------------------------\n";
}

// Students Class End

// Student Result Start

int main()
{
    Teacher objTeach;
    int val;
    while (true)
    {
        cout << "******************  WELCOME TO STUDENTS TEACHER MANAGEMENT SYSTEM ****************" << endl
             << endl;
        cout << "1. Teacher \n";
        cout << "2. Student \n";

        cout << "Press 1 or 2 for further details : ";
        cin >> val;
        switch (val)
        {
        case 1:

            cout << "*****LOGIN MODULE*****\n\n";
            cout << "\nEnter your login identity\n\n";
            cin >> str2;

            if (str1.compare(str2) == 0)
            {
                cout << "Login Successfull\n\n";

                int val2;
                while (true)
                {
                    cout << "Press 1 : Add Course " << endl;
                    cout << "Press 2 : Edit Course" << endl;
                    cout << "Press 3 : Delete Course" << endl;
                    cout << "Press 4 : Exit" << endl;

                    cin >> val2;
                    switch (val2)
                    {
                    case 1:
                        objTeach.addCourse();
                        break;
                    case 2:
                        objTeach.editCourse();
                        break;
                    case 3:
                        objTeach.deleteCourse();
                        break;
                    case 4:
                        exit(0);
                        break;
                    default:
                        cout << "Invalid input" << endl;
                    }
                }
            }
            else
            {

                cout << "Login failed\n";
                exit(0);
            }

            break;

        case 2:
            student s[1];
            fstream file;
            int i;
            file.open("record.txt", ios::out);
            cout << "\n**STUDENT REGISTRATION**\n\n"
                 << endl;
            cout << "\nEnter Student Details\n\n"
                 << endl;
            for (i = 0; i < 1; i++)
            {
                s[i].getdata();
                file.write((char *)&s[i], sizeof(s[i]));
            }
            file.close();

            cout << "...Press Enter to Start...\n";
            cin.get();

            string respond;
            cout << "\n**EXAM MODULE**\n\n";
            cout << "Are you ready to start the Quiz, "
                 << "? Yes/No.\n";
            cin >> respond;

            if (respond == "Yes" || respond == "yes")
            {
                cout << "\n";
                cout << "---------------------------------------------------------------------\n\n";
                cout << "...........INSTRUCTIONS...........\n\n";
                cout << "Total Questions = 10\n\n";
                cout << "Enter the right option to answer\n\n";
                cout << "Total Marks = 100\n\n";
                cout << "Mark  50 and above , Pass S\n\n";
                cout << "Mark less than 50 , Fail\n\n";
                cout << "Best of Luck!\n";
                cout << "----------------------------------------------------------------------\n\n";
                cout << "\n";
                cout << "Press Enter to Continue";
                cin.get();
                cin.ignore();
            }
            else
            {
                cout << "\n";
                cout << "Goodbye!\n";
                cin.ignore();
                cin.get();
                return 0;
            }

            for (int i = 0; i < que.size(); i++)
            {
                Question q;
                q.askQuestion();
            }

            file.open("record.txt", ios::in);
            cout << "\nStudent Details\n"
                 << endl;
            for (i = 0; i < 1; i++)
            {
                file.read((char *)&s[i], sizeof(s[i]));
                s[i].display();
            }
            file.close();

            cout << "**RESULT MODULE**\n\n";
            cout << "\n....RESULT....\n"
                 << endl;
            cout << "Your Total Score is " << total << " out of 100!\n";
            cout << "\n";

            Question res;
            res.getresult();

            if (total > 50)
            {

                cout << "\n";
                cin.get();
                cin.ignore();
                return 0;
            }
            else
            {
                cout << "You failed... Sorry, better luck next time.\n";
                cout << "\n";
            }
            cin.get();
            cin.ignore();

            return 0;
        }

        void Question::setValues(string q, string a1, string a2, string a3, string a4, char ca, int pa)
        {
            Question_Text = q;
            answer_1 = a1;
            answer_2 = a2;
            answer_3 = a3;
            answer_4 = a4;
            correct_answer = ca;
            Question_Score = pa;
        }

        void Question::askQuestion()
        {
            cout << "\n";
            cout << Question_Text << "\n";
            cout << "a. " << answer_1 << "\n";
            cout << "b. " << answer_2 << "\n";
            cout << "c. " << answer_3 << "\n";
            cout << "d. " << answer_4 << "\n";
            cout << "\n";

            cout << "What is your answer?"
                 << "\n";
            cin >> guess;

            if (guess == correct_answer)
            {
                cout << "\n";
                total = total + Question_Score;
                cout << "\n";
                cout << "Press Enter to Continue."
                     << "\n";
                cin.get();
                cin.ignore();
            }
            else

            {
                cout << "\n";
                cout << "Press Enter to Continue."
                     << "\n";
                cin.get();
                cin.ignore();
            }
            break;
        default:
            cout << "Inavalid input";
        }
    }

    return 0;
}
