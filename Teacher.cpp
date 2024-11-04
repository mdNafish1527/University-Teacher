#include <iostream>
#include <string>
using namespace std;

class Course{
    public:
        string courseName;
        Course* next;
        string Instructor;
        int NumberOfStudent;
        string code;

    Course(string courseName){
        this -> courseName = courseName;
        this -> next = NULL;
    }

    Course(string courseName,string Instructor,int NumberOfStudent,string code){
        this -> courseName = courseName;
        this -> Instructor = Instructor;
        this -> NumberOfStudent = NumberOfStudent;
        this -> code = code;
    }
};




class Teacher{
    private:
        string name;
        string ID;
        unsigned int salary;
        Course* head;
        int totalCourse;
        string password;

    public:
        Teacher(string name,string ID,int salary,string password){
            this -> name = name;
            this -> ID = ID;
            this -> salary = salary;
            this -> head = NULL;
            this -> totalCourse = 0;
            this -> password = password;
        }

        // Teacher(){
        //     //default constructor
        // }

        void addCourse(string Name){
            Course* temp = head;
            while(temp && temp -> courseName != Name) temp = temp -> next;
            if(temp && temp -> courseName == Name){
                cout << Name << "Al reay present in the list" << endl;
                return;
            }

            Course* newCourse = new Course(Name);
            if(head == NULL){
                head = newCourse;
            }
            else{
                newCourse -> next = head;
                head = newCourse;
            }
            this -> totalCourse += 1;
            cout << Name << " added in the list succesfully" << endl;
            return;
        }



        // void addCourse(string Name,string Instructor,int NumberOfStudent,string code){
        //     Course* temp = head;
        //     while(temp && temp -> Name != )
        // }


        void RemoveCourse(string Name){
            if(head -> courseName == Name) {
                head = head -> next;
                this -> totalCourse -= 1;
                cout << Name << " Course removed succesfully" << endl;
                return;
            }
            Course* temp = head;
            while(temp -> next -> next != NULL && temp -> next -> courseName != Name) temp = temp -> next;
            if(temp -> next -> next && temp -> next -> courseName == Name) {
                temp -> next = temp -> next -> next;
                this -> totalCourse -= 1;
                cout << Name << " Course removed succesfully" << endl;
            }

            else if(temp -> next -> courseName == Name){
                temp -> next = NULL;
                this -> totalCourse -= 1;
                cout << Name << " Course removed succesfully" << endl;
            }
            else{
                cout << "This course isn't present in the lists" << endl << endl;
            }
            return;
        }


        void Details(){
            cout << "Teacher's name      -> " << name << endl;
            cout << "Teacher's ID        -> " << ID << endl;
            cout << "Total " << totalCourse << " Course List -> " << endl;
            Course* temp = head;
            while(temp){
                cout << temp -> courseName << "  ";
                temp = temp -> next;
            }
            cout << endl << endl;
            return;
        }


        void ShowSalary(){
            string ID,password;
            cout << "Enter ID ";
            cin >> ID;
            cout << endl << "Enter Password " ;
            cin >> password;

            if(ID == this -> ID && password == this -> password){
                cout << "Salary is " << this -> salary << endl;
            }
            else cout << "Don't Match" << endl;
            return;
        }


        void ChangePassword(){
            string ID,password;
            cout << "Enter ID ";
            cin >> ID;
            cout << "Enter Password " ;
            cin >> password;

            if(ID != this -> ID || this -> password != password){
                cout << "Don't Match " << endl;
                return;
            }
            else{
                string newPassword1,newPassword2;
                cout << "Enter new Password ";
                cin >> newPassword1;
                cout << "Enter the new Password again to confirm ";
                cin >> newPassword2;
                if(newPassword1 != newPassword2){
                    cout << "Sorry You type differnt password " << endl;
                    exit;
                }
                else{
                    this -> password = newPassword1;
                    cout << "Password changed succesfully" << endl;
                    return;
                }
            }
        }
};




int main(){
    Teacher* JewelSir = new Teacher("Jewel Sir","T",100000,"1");
    JewelSir -> addCourse("CSE1101");
    JewelSir -> addCourse("SE!201");
    JewelSir -> addCourse("SE!323");
    JewelSir -> addCourse("ECE!201");
    JewelSir -> Details();
    JewelSir -> RemoveCourse("CSE1101");
    JewelSir -> addCourse("SE!323");
    JewelSir -> Details();
    JewelSir -> ShowSalary();
    JewelSir -> ChangePassword();
    JewelSir -> ShowSalary();
    return 0;
}