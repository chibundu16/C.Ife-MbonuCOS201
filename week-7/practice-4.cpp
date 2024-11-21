#include <iostream>
using namespace std;

int * multiply (int b){
static int c[12];
for(int i=1; i<=12; i++){
    c[i]=i*b;
}
return c;
}
int main(){
int *p=NULL, num=6;
p = multiply(num);
for (int i = 1; i<= 12; i++){
cout << "*(P+" << i <<") : ";
cout<< *(p + i)<<endl;
}
}