#include <iostream>
using namespace std;

class csc201 {
    public:
    int score;
    string name;
    char grade;
};

int main(){
    csc201 student1;
    csc201 student2;
    student1.score = 20;
    student1.grade='F';
    student1.name="Bello Moses Eromsele";
    student2.score=100;
    student2.grade='A';
    student2.name="Leo";
    cout<<"student1's Name = "<<student1.name<<" grade = "<<student1.grade<<" score =  "<<student1.score<<endl;
    cout<<"student2's Name = "<<student2.name<<" grade = "<<student2.grade<<" score =  "<<student2.score<<endl;
    

}