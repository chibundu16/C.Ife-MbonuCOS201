#include <iostream>
using namespace std;

int score = 40;

int addition (int a, int b){
        int r;
        r=a+b;
        return r;}

int func(int a, int b) {
    int r;
    --a;
    --b;
    r = a + b;
    return r;
}       

int main() {
    {
        int j; //define a loop variable
        for (j = 0; j <15; j++)//loop from 0 to 14
            cout << j*j << endl;//displaying the square of j
        cout << endl;
    }
    cout << "" << endl;
    {
        int arr[] ={10, 20, 30, 40 };

        //printing elements of an array using foreach loop
        for (int x : arr)
            cout << x << endl;
    }
    cout << "" << endl;
    {
        int a = 25;
        int b = 20;
        while (b<a) {
            b++;
            cout << b << endl;
        }
    }
    cout << "" << endl;
    {
        int m = 25;
        int n = 20;
        do{
            n++;
            cout << n << endl;
        }while (n<m);

    }
    cout << "" << endl;
    {
        if(score>=70 && score<=100)
            cout << "Group A" << endl;
        else if(score>=60 && score<=69)
            cout << "Group B" << endl;
        else if(score>=50 && score<=59)
            cout << "Group C" << endl;
        else if(score>=45 && score<=49)
            cout << "Group D" << endl;
        else if(score>=40 && score<=44)
            cout << "Group E" << endl;   
        else if(score>=0 && score<=39) 
            cout << "Group F" << endl;
        else
            cout << "failed" << endl;

    }
    cout << "" << endl;
    {
            if(score>=70 && score<=100)
            {cout << "Group A" << endl;
            cout << "excellent" << endl;}
        else if(score>=60 && score<=69)
            {cout << "Group B" << endl;
            cout << "very good" << endl;}
        else if(score>=50 && score<=59)
            {cout << "Group C" << endl;
            cout << "good" << endl;}
        else if(score>=45 && score<=49)
            {cout << "Group D" << endl;
            cout << "average" << endl;}
        else if(score>=40 && score<=44)
            {cout << "Group E" << endl; 
            cout << "Poor" << endl; } 
        else if(score>=0 && score<=39) 
            {cout << "Group F" << endl;
            cout << "Failed" << endl;}
        else
            cout << "failed" << endl;
    }
    cout << "" << endl;
    {
        	int a = 40;
            int b = 30;
            if (a == 40){
		if (b < 12)
			cout << "A is equal to 40 and b is less than 12" << endl;
		else
			cout << "A is equal to 40 and b is greater than 12" << endl;
	} else {
		cout << "A is not equal to 40" << endl;

    }
    }
    cout << "" << endl;
    {
    	char grade = 'D';
	switch(grade) {
		case 'A':
			cout << "Excellent!" << endl;
			break;
		case 'B':
			cout << "Very Good!" << endl;
			break;
		case 'C':
			cout << "Well done" << endl;
			break;
		case 'D':
			cout << "You passed" << endl;
			break;
		case 'F':
			cout << "Better try again" << endl;
			break;
		default:
			cout << "Invalid grade" << endl;
	}

    }  cout << "" << endl;
    {
        	char grade = 'A';
	switch(grade) {
		case 'A':
			cout << "Excellent!" << endl;
			break;
		case 'B':
			cout << "Very Good!" << endl;
			break;
		case 'C':
			cout << "Well done" << endl;
			break;
		case 'D':
			cout << "You passed" << endl;
			break;
		case 'F':
			cout << "Better try again" << endl;
			break;
		default:
			cout << "Invalid grade" << endl;
    }
}
 cout << "" << endl;

 // Break statement 
 {
   	int n;
	for (n = 10; n > 0; n--) {
		if (n == 3) {
			cout << "countdown aborted!" << endl;
			break;
		}
	}
 
 }
 cout << "" << endl;
 //continue statement
 {
    int n;
    for (n = 10; n > 0; n--) {
		if (n == 5) continue; 
			cout << n << " , ";
    }
    cout << "End of loop" << endl;
			
		}
     cout << "" << endl;   
 //Goto statement
 {
    int n = 10;
loop:
    cout << n << ", ";
    n--;
    if (n > 0)
        goto loop;
    cout << "End of loop\n";
 }
//Functions
cout << "" << endl;
     {
        int z;
        z = addition (5,3);
        cout << "The result is" << z << endl;
    }




{
    int num1 = 4;
    int num2 = 6;
    cout << "Num1 before calling func: " << num1 << endl;
    cout << "Num2 before calling func: " << num2 << endl;
    int z = func(num1, num2);
    cout << "The result is " << z << endl;
    cout << "Num1 after calling func: " << num1 << endl;
    cout << "Num2 after calling func: " << num2 << endl;
}
}


 
