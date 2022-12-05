#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Made By:
Umar Habeeb 20L-1215
*/

class Program;
class PLO;
class Course;
class CLO;
class Evaluation;
class Question;

class Question
{
public:
    int Q_num;
    int marks;
    int CLO_ID;


    Question(int n, int m, int c)
    {
        Q_num = n;
        marks = m;
        CLO_ID = c;
    }

    void Print()
    {
        cout << 'Q' << Q_num << '\t' << '[' << marks << ']' << '\t' << ' ' << CLO_ID << endl;
    }
};

class Evaluation
{
public:
    string name;
    int total = 0;
    float weightage = 0;
    string date;
    vector<Question> Questions;

    Evaluation() = default;

    Evaluation(string n, int t, float w, string d)
    {
        name = n;
        total = t;
        weightage = w;
        date = d;
    }

    void AddQuestion()
    {
        PrintQuestions();
        int q = Questions.size() + 1;
        int m; int c;
        cout << "Q" << q << " Marks: ";
        cin >> m;
        cout << "CLO Tested: ";
        cin >> c;

        Question ques(q, m, c);
        Questions.push_back(ques);
        PrintQuestions();
        cout << "Q" << q << " successfully added! \n\n";
    }
    void RemoveQuestion(int num)
    {
        int q = Questions[num].Q_num;
        auto it = Questions.begin();
        it = it + (num);
        Questions.erase(it);
        cout << "Q" << q << " successfully removed! \n\n";
    }
    void UpdateQuestion(int num)
    {
        int q = Questions[num].Q_num;
        int m; int c;
        cout << "Q" << q << " Marks: ";
        cin >> m;
        cout << "CLO Tested: ";
        cin >> c;

        Question ques(q, m, c);
        Questions.at(num) = ques;
        PrintQuestions();
        cout << "Q" << q << " successfully updated! \n\n";
    }

    void Print()
    {
        cout << name << '\t' << date << '\t' << total << '\t' << weightage << endl;
    }

    void PrintQuestions()
    {
        cout << "Questions in " << name << endl;
        cout << "Sr" << '\t' << "Q#" << '\t' << "Marks" << '\t' << "CLO" << endl;
        for (int i = 0; i < Questions.size(); i++)
        {

            cout << i + 1 << ":" << '\t';
            Questions[i].Print();
        }
        cout << endl;
    }
};

class CLO
{
public:
    string name;
    int id;

    CLO() = default;

    CLO(string n, int i)
    {
        name = n;
        id = i;
    }

    void Print()
    {
        cout << name << endl;
    }

};

class Course
{
public:
    string name;
    string code;
    vector<CLO> CLOs;
    vector<Evaluation> Evaluations;

    Course() = default;

    Course(string n, string c)
    {
        name = n;
        code = c;
    }

    int CheckCLO(CLO c) // checks if a clo has been tested [-1: CLO doesnt exist; 0: not tested; 1: tested]
    {
        int test = 0; int id = -1;
        for (int i = 0; i < CLOs.size(); i++)
        {
            if (CLOs[i].id == c.id)
                id = c.id;
        }
        if (id == -1)
            return -1;

        cout << endl << "CLO " << id << endl;

        for (int i = 0; i < Evaluations.size(); i++)
        {
            for (int j = 0; j < Evaluations[i].Questions.size(); j++)
            {
                if (Evaluations[i].Questions[j].CLO_ID == id)
                {
                    test++;
                    cout << Evaluations[i].name << "  Q" << Evaluations[i].Questions[j].Q_num << endl;
                }
            }
        }
        cout << endl;
        if (test > 1)
            return 1;
        else
            return 0;

    }

    void CheckAllCLOs() // checks whether all the clos have been adequately tested
    {
        int a = 1;
        for (int i = 0; i < CLOs.size(); i++)
        {
            if (CheckCLO(CLOs[i]) == 1)
                a;
            else
                a = 0;
        }
        if (a == 1)
            cout << "All CLOs of Course " << code << " have been tested\n\n";
        else if (a == 0)
            cout << "All CLOs of Course " << code << " have NOT been tested\n\n";
    }

    void AddCLO()
    {
        PrintCLOs();

        string n; int id;
        cout << "ID: ";
        cin >> id;
        cout << "Name: ";
        getline(cin >> ws, n);

        CLO clo(n, id);
        CLOs.push_back(clo);
        PrintCLOs();

        cout << "CLO" << id << " successfully added! \n\n";
    }
    void RemoveCLO(int num)
    {
        int id = CLOs[num].id;
        auto it = CLOs.begin();
        it = it + (num);
        CLOs.erase(it);
        cout << "CLO " << id << " successfully removed! \n\n";
    }
    void UpdateCLO(int num)
    {
        string n; int id;
        cout << "ID: ";
        cin >> id;
        cout << "Name: ";
        getline(cin >> ws, n);

        CLO clo(n, id);

        CLOs.at(num) = clo;
        PrintEvaluations();

        cout << "CLO " << id << " successfully removed! \n\n";

    }

    void AddEvaluation()
    {
        PrintEvaluations();

        string n; int t;
        float w; string d;

        cout << "Title: ";
        getline(cin >> ws, n);
        cout << "Total Marks: ";
        cin >> t;
        cout << "Weightage: ";
        cin >> w;
        cout << "Date: ";
        cin >> d;

        Evaluation eval(n, t, w, d);
        Evaluations.push_back(eval);
        PrintEvaluations();

        cout << n << " successfully added! \n\n";
    }
    void RemoveEvaluation(int num)
    {
        auto it = Evaluations.begin();
        it = it + (num);
        Evaluations.erase(it);
        cout << name << " successfully removed! \n\n";
    }
    void UpdateEvaluation(int num)
    {
        string n; int t;
        float w; string d;

        cout << "Title: ";
        getline(cin >> ws, n);
        cout << "Total Marks: ";
        cin >> t;
        cout << "Weightage: ";
        cin >> w;
        cout << "Date: ";
        cin >> d;

        Evaluation eval(n, t, w, d);
        Evaluations.at(num) = eval;
        PrintEvaluations();

        cout << n << " successfully updated! \n\n";
    }

    void Print()
    {
        cout << code << '\t' << name << endl;
    }

    void PrintCLOs()
    {
        cout << "CLOs in " << name << endl;
        cout << "Sr" << '\t' << "Name" << endl;
        for (int i = 0; i < CLOs.size(); i++)
        {
            cout << i + 1 << ":" << '\t';
            CLOs[i].Print();
        }
        cout << endl;
    }

    void PrintEvaluations()
    {
        cout << "Evaluations in " << name << endl;
        cout << "Sr" << '\t' << "Name" << '\t' << '\t' << "Date" << '\t' << " Total" << '\t' << "Weightage" << endl;
        for (int i = 0; i < Evaluations.size(); i++)
        {
            cout << i + 1 << ":" << '\t';
            Evaluations[i].Print();
        }
        cout << endl;
    }

};

class PLO
{
public:
    string name;
    int id;
    vector<Course> Courses;

    PLO() = default;

    PLO(string n, int i)
    {
        name = n;
        id = i;
    }

    void AddCourse()
    {
        PrintCourses();

        string name; string code;
        cout << "Name: ";
        getline(cin >> ws, name);

        cout << "Code: ";
        cin >> code;

        Course c(name, code);

        Courses.push_back(c);
        PrintCourses();

        cout << "Course " << code << " successfully added! \n\n";
    }
    void RemoveCourse(int num)
    {
        string code = Courses[num].code;
        auto it = Courses.begin();
        it = it + (num);
        Courses.erase(it);
        cout << "Course " << code << " successfully removed! \n\n";
    }
    void UpdateCourse(int num)
    {
        string name; string code;
        cout << "Name: ";
        getline(cin >> ws, name);
        cout << "Code: ";
        cin >> code;
        Course c(name, code);
        Courses.at(num) = c;
        PrintCourses();

        cout << "Course " << code << " successfully updated! \n\n";
    }

    void Print()
    {
        cout << name << endl;
    }

    void PrintCourses()
    {
        cout << "Courses in " << name << endl;
        cout << "Sr" << '\t' << "Code" << '\t' << "Name" << endl;
        for (int i = 0; i < Courses.size(); i++)
        {
            cout << i + 1 << ":" << '\t';
            Courses[i].Print();
        }
        cout << endl;
    }
};

class Program
{
public:
    string name;
    string dept;
    vector<PLO> PLOs;

    Program() = default;

    Program(string n, string d)
    {
        name = n;
        dept = d;
    }

    void Print()
    {
        cout << name << endl;
    }

    void PrintPLOs()
    {
        cout << "PLOs in " << name << ": " << endl;
        cout << "Sr" << '\t' << "Name" << endl;
        for (int i = 0; i < PLOs.size(); i++)
        {
            cout << i + 1 << ":" << '\t';
            PLOs[i].Print();
        }
        cout << endl;
    }
};

Program P("BSCS", "CS");

void Reports()
{
    int a;
    cout << "1: Check CLO\n2: Check Course\n3: List PLO Courses\nSelect Report Type: ";
    cin >> a;

    if (a == 1)
    {
        int plo; int course; int clo;
        cout << endl;
        P.PrintPLOs();
        cout << "Select PLO: ";
        cin >> plo;
        plo = plo - 1;
        P.PLOs[plo].PrintCourses();
        cout << "Select Course: ";
        cin >> course;
        course = course - 1;
        P.PLOs[plo].Courses[course].PrintCLOs();
        cout << "Select CLO: ";
        cin >> clo;
        clo = clo - 1;

        if (P.PLOs[plo].Courses[course].CheckCLO(P.PLOs[plo].Courses[course].CLOs[clo]) == 1)
            cout << "CLO " << P.PLOs[plo].Courses[course].CLOs[clo].id << " has been tested adequately.\n\n";
        else if (P.PLOs[plo].Courses[course].CheckCLO(P.PLOs[plo].Courses[course].CLOs[clo]) == 0)
            cout << "CLO " << P.PLOs[plo].Courses[course].CLOs[clo].id << " has not been tested adequately.\n\n";
        else
            cout << "CLO doesn't exist in course\n\n";

    }
    else if (a == 2)
    {
        int plo; int course;
        cout << endl;
        P.PrintPLOs();
        cout << "Select PLO: ";
        cin >> plo;
        plo = plo - 1;
        P.PLOs[plo].PrintCourses();
        cout << "Select Course: ";
        cin >> course;
        course = course - 1;

        P.PLOs[plo].Courses[course].CheckAllCLOs();

    }
    else if (a == 3)
    {
        int plo;
        cout << endl;
        P.PrintPLOs();
        cout << "Select PLO: ";
        cin >> plo;
        plo = plo - 1;
        P.PLOs[plo].PrintCourses();

    }
}

int LogIn()
{
    string u_name;
    int mode;
    while (true)
    {
        while (true)
        {
            cout << "username: ";
            cin >> u_name;
            if (u_name == "ao")
            {
                mode = 1;
                cout << "Logged in as Academic Officer\n\n";
                break;
            }

            else if (u_name == "teacher")
            {
                mode = 2;
                cout << "Logged in as Teacher\n\n";
                break;
            }
            else if (u_name == "0")
            {
                return 0;
            }
            else
                cout << "username invalid\n";
        }
        return mode;
    }
}

int Menu(int mode)
{
    int action = 0;

    if (mode == 1)
    {

        cout << "1. Add Course\n2. Remove Course\n3. Update Course\n4. Add CLO\n5. Remove CLO\n6. Update CLO\n7. Reports\n8. Log Out";
        while (true)
        {
            cout << "\nSelect Action: ";
            cin >> action;
            if (action >= 1 && action <= 6)
                break;
            else if (action == 7) {
                action = 13; break;
            }
            else if (action == 8) {
                action = 0; break;
            }

            else
                cout << "Invalid Input\n";
        }

    }
    else if (mode == 2)
    {

        cout << "1. Add Evaluation\n2. Remove Evaluation\n3. Update Evaluation\n4. Add Question\n5. Remove Question\n6. Update Question\n7. Reports\n8. Log Out\n";
        while (true)
        {
            cout << "\nSelect Action: ";
            cin >> action;
            if (action >= 1 && action <= 8)
                break;
            else
                cout << "Invalid Input\n";
        }
        if (action < 8)
            action = action + 6;
        else if (action == 8)
            action = 0;
    }

    if (action == 0)
        cout << "Logged Out...\n\n";

    return action;
}

int DoAction(int action)
{
    if (action == 0)
        return 0;
    else if (action == 1)
    {
        int plo;
        cout << "Add new course.. \n" << endl;
        P.PrintPLOs();
        cout << "Select PLO: ";
        cin >> plo;
        plo = plo - 1;

        P.PLOs[plo].AddCourse();
    }
    else if (action == 2)
    {
        int plo; int course;
        cout << "Removing course.. \n" << endl;
        P.PrintPLOs();
        cout << "Select PLO: ";
        cin >> plo;
        plo = plo - 1;
        P.PLOs[plo].PrintCourses();
        cout << "Select Course: ";
        cin >> course;
        course = course - 1;

        P.PLOs[plo].RemoveCourse(course);
    }
    else if (action == 3)
    {
        int plo; int course;
        cout << "Updating course.. \n" << endl;
        P.PrintPLOs();
        cout << "Select PLO: ";
        cin >> plo;
        plo = plo - 1;
        P.PLOs[plo].PrintCourses();
        cout << "Select Course: ";
        cin >> course;
        course = course - 1;

        P.PLOs[plo].UpdateCourse(course);
    }
    else if (action == 4)
    {
        int plo; int course;
        cout << "Add new CLO.. \n" << endl;
        P.PrintPLOs();
        cout << "Select PLO: ";
        cin >> plo;
        plo = plo - 1;
        P.PLOs[plo].PrintCourses();
        cout << "Select Course: ";
        cin >> course;
        course = course - 1;

        P.PLOs[plo].Courses[course].AddCLO();
    }
    else if (action == 5)
    {
        int plo; int course; int clo;
        cout << "Removing CLO.. \n" << endl;
        P.PrintPLOs();
        cout << "Select PLO: ";
        cin >> plo;
        plo = plo - 1;
        P.PLOs[plo].PrintCourses();
        cout << "Select Course: ";
        cin >> course;
        course = course - 1;
        P.PLOs[plo].Courses[course].PrintCLOs();
        cout << "Select CLO: ";
        cin >> clo;
        clo = clo - 1;

        P.PLOs[plo].Courses[course].RemoveCLO(clo);
    }
    else if (action == 6)
    {
        int plo; int course; int clo;
        cout << "Update CLO.. \n" << endl;
        P.PrintPLOs();
        cout << "Select PLO: ";
        cin >> plo;
        plo = plo - 1;
        P.PLOs[plo].PrintCourses();
        cout << "Select Course: ";
        cin >> course;
        course = course - 1;
        P.PLOs[plo].Courses[course].PrintCLOs();
        cout << "Select CLO: ";
        cin >> clo;
        clo = clo - 1;

        P.PLOs[plo].Courses[course].UpdateCLO(clo);
    }
    else if (action == 7)
    {
        int plo; int course;
        cout << "Add new evaluation.. \n" << endl;
        P.PrintPLOs();
        cout << "Select PLO: ";
        cin >> plo;
        plo = plo - 1;
        P.PLOs[plo].PrintCourses();
        cout << "Select Course: ";
        cin >> course;
        course = course - 1;

        P.PLOs[plo].Courses[course].AddEvaluation();

    }
    else if (action == 8)
    {
        int plo; int course; int eval;
        cout << "Removing evaluation.. \n" << endl;
        P.PrintPLOs();
        cout << "Select PLO: ";
        cin >> plo;
        plo = plo - 1;
        P.PLOs[plo].PrintCourses();
        cout << "Select Course: ";
        cin >> course;
        course = course - 1;
        P.PLOs[plo].Courses[course].PrintEvaluations();
        cout << "Select Evaluation: ";
        cin >> eval;
        eval = eval - 1;

        P.PLOs[plo].Courses[course].RemoveEvaluation(eval);
    }
    else if (action == 9)
    {
        int plo; int course; int eval;
        cout << "Update evaluation.. \n" << endl;
        P.PrintPLOs();
        cout << "Select PLO: ";
        cin >> plo;
        plo = plo - 1;
        P.PLOs[plo].PrintCourses();
        cout << "Select Course: ";
        cin >> course;
        course = course - 1;
        P.PLOs[plo].Courses[course].PrintEvaluations();
        cout << "Select Evaluation: ";
        cin >> eval;
        eval = eval - 1;

        P.PLOs[plo].Courses[course].UpdateEvaluation(eval);

    }
    else if (action == 10)
    {
        int plo; int course; int eval; int new_total = 0;
        cout << "Add new question.. \n" << endl;
        P.PrintPLOs();
        cout << "Select PLO: ";
        cin >> plo;
        plo = plo - 1;
        P.PLOs[plo].PrintCourses();
        cout << "Select Course: ";
        cin >> course;
        course = course - 1;
        P.PLOs[plo].Courses[course].PrintEvaluations();
        cout << "Select Evaluation: ";
        cin >> eval;
        eval = eval - 1;
        P.PLOs[plo].Courses[course].Evaluations[eval].AddQuestion();

        for (int i = 0; i < P.PLOs[plo].Courses[course].Evaluations[eval].Questions.size(); i++)
            new_total = new_total + P.PLOs[plo].Courses[course].Evaluations[eval].Questions[i].marks;

        P.PLOs[plo].Courses[course].Evaluations[eval].total = new_total;

    }
    else if (action == 11)
    {
        int plo; int course; int eval; int ques; int new_total = 0;
        cout << "Removing question.. \n" << endl;
        P.PrintPLOs();
        cout << "Select PLO: ";
        cin >> plo;
        plo = plo - 1;
        P.PLOs[plo].PrintCourses();
        cout << "Select Course: ";
        cin >> course;
        course = course - 1;
        P.PLOs[plo].Courses[course].PrintEvaluations();
        cout << "Select Evaluation: ";
        cin >> eval;
        eval = eval - 1;
        P.PLOs[plo].Courses[course].Evaluations[eval].PrintQuestions();
        cout << "Select Question: ";
        cin >> ques;
        ques = ques - 1;

        P.PLOs[plo].Courses[course].Evaluations[eval].RemoveQuestion(ques);

        for (int i = 0; i < P.PLOs[plo].Courses[course].Evaluations[eval].Questions.size(); i++)
            new_total = new_total + P.PLOs[plo].Courses[course].Evaluations[eval].Questions[i].marks;

        P.PLOs[plo].Courses[course].Evaluations[eval].total = new_total;
    }
    else if (action == 12)
    {

        int plo; int course; int eval; int ques; int new_total = 0;
        cout << "Update question.. \n" << endl;
        P.PrintPLOs();
        cout << "Select PLO: ";
        cin >> plo;
        plo = plo - 1;
        P.PLOs[plo].PrintCourses();
        cout << "Select Course: ";
        cin >> course;
        course = course - 1;
        P.PLOs[plo].Courses[course].PrintEvaluations();
        cout << "Select Evaluation: ";
        cin >> eval;
        eval = eval - 1;
        P.PLOs[plo].Courses[course].Evaluations[eval].PrintQuestions();
        cout << "Select Question: ";
        cin >> ques;
        ques = ques - 1;

        P.PLOs[plo].Courses[course].Evaluations[eval].UpdateQuestion(ques);

        for (int i = 0; i < P.PLOs[plo].Courses[course].Evaluations[eval].Questions.size(); i++)
            new_total = new_total + P.PLOs[plo].Courses[course].Evaluations[eval].Questions[i].marks;

        P.PLOs[plo].Courses[course].Evaluations[eval].total = new_total;
    }
    else if (action == 13)
    {
        Reports();
    }

    return 1;
}

void initiaize()
{

    PLO po1("Problem Solving", 1);
    PLO po2("Programming", 2);
    PLO po3("Design and Analysis", 3);
    PLO po4("Professional Conduct", 4);

    Course c1("Phil", "CS1004");
    Course c2("Logic", "CS1005");
    Course c3("Trig", "MT1002");
    Course c4("PF", "CS1001");


    CLO co1("Understanding", 1);
    CLO co2("Working", 2);

    Evaluation e1("Assignment 1", 50, 10, "1/11/22");
    Evaluation e2("Assignment 2", 30, 8, "3/12/22");

    Question q1(1, 30, 1);
    Question q2(2, 20, 2);
    Question q3(1, 10, 2);
    Question q4(2, 10, 2);

    P.PLOs.push_back(po1);
    P.PLOs.push_back(po2);
    P.PLOs.push_back(po3);
    P.PLOs.push_back(po4);

    P.PLOs[0].Courses.push_back(c1);
    P.PLOs[0].Courses.push_back(c2);
    P.PLOs[0].Courses.push_back(c3);
    P.PLOs[1].Courses.push_back(c4);

    P.PLOs[0].Courses[0].CLOs.push_back(co1);
    P.PLOs[0].Courses[0].CLOs.push_back(co2);

    P.PLOs[0].Courses[0].Evaluations.push_back(e1);
    P.PLOs[0].Courses[0].Evaluations.push_back(e2);

    P.PLOs[0].Courses[0].Evaluations[0].Questions.push_back(q1);
    P.PLOs[0].Courses[0].Evaluations[0].Questions.push_back(q2);
    P.PLOs[0].Courses[0].Evaluations[1].Questions.push_back(q3);
    P.PLOs[0].Courses[0].Evaluations[1].Questions.push_back(q4);

    P.Print();
    P.PrintPLOs();
    P.PLOs[0].PrintCourses();
    P.PLOs[0].Courses[0].PrintCLOs();
    P.PLOs[0].Courses[0].PrintEvaluations();
    P.PLOs[0].Courses[0].Evaluations[0].PrintQuestions();
    P.PLOs[0].Courses[0].Evaluations[1].PrintQuestions();
}

void PrintALL()
{
    P.Print();
    P.PrintPLOs();
    P.PLOs[0].PrintCourses();
    P.PLOs[0].Courses[0].PrintCLOs();
    P.PLOs[1].Courses[0].PrintCLOs();
    P.PLOs[0].Courses[0].PrintEvaluations();
    P.PLOs[0].Courses[0].Evaluations[0].PrintQuestions();
    P.PLOs[0].Courses[0].Evaluations[1].PrintQuestions();
}

int main()
{
    initiaize();
    int mode; int act = 0;
    while (true)
    {
        mode = LogIn();
        if (mode == 0)   break;
        while (true)
        {
            int menu = Menu(mode);
            act = DoAction(menu);
            if (act == 0)   break;
        }
    }

    PrintALL();
    return 0;
}
