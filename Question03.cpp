#include <iostream>
using namespace std;
struct student
{
    int regNo;
    string name;
    string branch;
    float cgpa;
};
student s[50] = {
    {150, "Ali", "Computer Science", 3.8},
    {102, "Sara", "Electrical Engineering", 3.5},
    {103, "Hina", "Mechanical Engineering", 3.2},
    {104, "Abubakar", "Chemical Engineering", 3.9},
    {105, "Ahmad", "Civil Engineering", 3.6},
    {106, "Tom", "Computer Science", 3.7},
    {146, "Abdullah", "Electrical Engineering", 3.4},
    {108, "Omer", "Aerospace Engineering", 3.5},
    {109, "Usman", "Biomedical Engineering", 3.9},
    {110, "Oon", "Computer Science", 3.2},
    {111, "Faizan", "Electrical Engineering", 3.6},
    {112, "Jack", "Mechanical Engineering", 3.8},
    {113, "Root", "Chemical Engineering", 3.3},
    {114, "Babar", "Civil Engineering", 3.7},
    {115, "Mia", "Computer Science", 3.5},
    {116, "Hassan", "Biomedical Engineering", 3.9},
    {117, "Amir", "Aerospace Engineering", 3.2},
    {118, "Shaheen", "Electrical Engineering", 3.6},
    {119, "Hafeez", "Mechanical Engineering", 3.8},
    {120, "Rayan", "Chemical Engineering", 3.3},
    {121, "Zana", "Civil Engineering", 3.7},
    {122, "Ilyas", "Computer Science", 3.5},
    {127, "Faisal", "Biomedical Engineering", 3.9},
    {124, "Qaisar", "Aerospace Engineering", 3.2},
    {125, "Shahzad", "Electrical Engineering", 3.6},
    {126, "Xavier", "Mechanical Engineering", 3.8},
    {123, "Yara", "Chemical Engineering", 3.3},
    {128, "Zane", "Civil Engineering", 3.7},
    {129, "Amy", "Computer Science", 3.5},
    {130, "Ben", "Biomedical Engineering", 3.9},
    {131, "Cara", "Aerospace Engineering", 3.2},
    {132, "Watson", "Electrical Engineering", 3.6},
    {133, "Emma", "Mechanical Engineering", 3.8},
    {134, "Felix", "Chemical Engineering", 3.3},
    {135, "Fakkar", "Civil Engineering", 3.7},
    {136, "lana", "Computer Science", 3.5},
    {137, "Danial", "Biomedical Engineering", 3.9},
    {138, "Fara", "Aerospace Engineering", 3.2},
    {139, "Ben", "Electrical Engineering", 3.6},
    {140, "Salman", "Mechanical Engineering", 3.8},
    {141, "Nora", "Chemical Engineering", 3.3},
    {142, "Khan", "Civil Engineering", 3.7},
    {143, "Imran", "Computer Science", 3.5},
    {144, "Wahid", "Biomedical Engineering", 3.9},
    {145, "Ahad", "Aerospace Engineering", 3.2},
    {107, "Tabish", "Electrical Engineering", 3.6},
    {147, "Arslan", "Mechanical Engineering", 3.8},
    {148, "Zainab", "Chemical Engineering", 3.3},
    {149, "Hania", "Civil Engineering", 3.7},
    {101, "Zara", "Computer Science", 3.5}

};
void displayStudent(student s)
{
    cout << "Regn No.: " << s.regNo << ", Name: " << s.name << ", Branch: " << s.branch << ", CGPA: " << s.cgpa << endl;
}
void linearsearch(student s[])
{
    int reg;
    cout << "Enter Register number of student you want to search";
    cin >> reg;
    for (int i = 0; i < 50; i++)
    {
        {
            if (s[i].regNo == reg)
            {
                cout << "Student found = ";
                displayStudent(s[i]);
                return;
            }
        }
    }
    cout << "Student not found with Regn No. " << reg << endl;
}

void bubblesort(student s[])
{
    for (int i = 0; i < 50 - 1; i++)
    {
        for (int j = 0; j < 50 - 1 - i; j++)
        {
            if (s[j].regNo > s[j + 1].regNo)
            {

                student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}
void Binarysearch(student s[])
{
    int reg;
    cout << "Enter Register number of student you want to search";
    cin >> reg;
    int S = 0;
    int e = 50;
    while (S <= e)
    {
        int mid = (S + e) / 2;
        for (int i = 0; i < 50; i++)
        {
            if (s[mid].regNo == reg)
            {
                cout << "Student found = ";
                displayStudent(s[mid]);
                return;
            }
            else if (s[mid].regNo < reg)
            {
                S = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
    }
}
void insertionSortdec(student s[])
{
    ;
    for (int i = 1; i < 50; i++)
    {
        student key = s[i];
        int j = i - 1;
        while (j >= 0 && s[j].cgpa < key.cgpa)
        {
            s[j + 1] = s[j];
            j = j - 1;
        }
        s[j + 1] = key;
    }
}
void labelMenu()
{
    while (true)
    {

        cout << "1.  Call linear search function to display data of student with a particular Regn no." << endl;
        cout << "2. Call bubble sort function to arrange data of students according to Regn no." << endl;
        cout << "3. Apply binary search on the above output (part b) to display data of a student with a particular Regn no." << endl;
        cout << "4. Use and modify Insertion sort logic to arrange data of students in descending order of CGPA" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            linearsearch(s);
        }
        break;
        case 2:
            bubblesort(s);
            cout << "Sorted array based on registration numbers:" << endl;
            for (int i = 0; i < 50; i++)
            {
                displayStudent(s[i]);
            }
            break;
        case 3:
            bubblesort(s);
            Binarysearch(s);

            break;
        case 4:
            insertionSortdec(s);
            for (int i = 0; i < 50; i++)
            {
                displayStudent(s[i]);
            }
            break;
        default:
            cout << "Wrong input" << endl;
            break;
        }
    }
}
int main()
{
    labelMenu();
    return 0;
}