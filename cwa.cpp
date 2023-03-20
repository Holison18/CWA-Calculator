#include <iostream>
#include <string>
#include <list>
#include <unistd.h>

using namespace std;

class student{
    private:
        string name;
        string student_id;
        string major;
        int age;
        float cwa;
        string std_class;
        list<string> courses;
    public:
        student(string Name, string Student_id, string Major, int Age){
            name = Name;
            student_id = Student_id;
            major = Major;
            age = Age;
        }
        
        void calculate_cwa(list<float> &grades, list<int> &weight){
            // calculate cwa
            float total_grade = 0;
            int total_weight = 0;
            for(int i=0; i<8; i++){
                total_grade += grades.front() * weight.front();
                total_weight += weight.front();
                grades.pop_front();
                weight.pop_front();
            }
            cwa = total_grade/total_weight;
            student_class();
        }


        void student_class(){
            // give study advice base on cwa
            if (cwa >= 70){
                std_class = "First Class";
            }else if(cwa>=60 && cwa<70){
                std_class = "Second Class Upper";
            }else if(cwa>=50 && cwa<60){
                std_class = "Second Class Lower";
            }else if(cwa>=40 && cwa<50){
                std_class = "Pass";
            }else{
                std_class = "Fail";
            } 
        }

        void print_info(){
            cout << "Name: " << name << endl;
            cout << "Student ID: " << student_id << endl;
            cout << "Major: " << major << endl;
            cout << "Age: " << age << endl;
            cout << "CWA: " << cwa << endl;
            cout << "Class: " << std_class << endl;
        }
};
int main(){
    // constructors have the same name as the class and do not have return types
    string name, student_id, major;
    int age;
    list<float> grades;
    list<string> courses;
    list<int> Weight;

    cout<<"\t\t\t\tStudent Details"<<endl;
    cout<<"student name: ";
    getline(cin, name);
    cout<<"student id: ";
    getline(cin,student_id);
    cout<<"student major: ";
    getline(cin, major);
    cout<<"student age: ";
    cin>>age;
    cout<<"Enter courses with their corresponding weights and grade\n"<<endl;
    for(int i=0; i<8; i++){
        string course;
        float grade;
        int weight;
        cout<<"Course "<<i+1<<": ";
        cin>>course;
        cout<<"Weight: ";
        cin>>weight;
        cout<<"Grade: ";
        cin>>grade;
        courses.push_back(course);
        grades.push_back(grade);
        Weight.push_back(weight);
    }
    
    student student1(name, student_id, major, age);
    cout<<"Details added successfully"<<endl;
    sleep(1);
    system("clear");

    int response;
    cout<<"Do you want to calculate cwa? (1 for yes, 0 for no): ";
    cin>>response;
    if(response == 1){
        student1.calculate_cwa(grades, Weight);
        cout<<"CWA calculated successfully"<<endl;
        sleep(1);
        system("clear");
        student1.print_info();
    }else{
        exit(0);
    }
}