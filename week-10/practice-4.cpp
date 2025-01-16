#include <iostream>
using namespace std;

class csc201{
    private:
       char grade;
       int score;
    public:
       string name;
    public:
    csc201(){
        cout<<"Student must pass CSC101\n ";
        cout<<"To pass the course the student must have a minimum score of 40\n";

    }



void setscore(int s){
    score = s;
}
int getscore(){
    return score;
}
void setgrade(char g){
    grade = g;
}
int getgrade(){
    return grade;
}
};

int main (){
    csc201 student1;
    student1.setscore(20);
    student1.setgrade('F');
    student1.name="Bello Moses Eromsele";
    cout<<"Student1's Name = "<<student1.name<<", grade = "<<student1.getgrade()<<" , and score = "<<student1.getscore()<<endl;

}