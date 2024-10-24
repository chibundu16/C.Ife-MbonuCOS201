#include <iostream>
using namespace std;

/**int main(){
    int a = 13;
    int b = 2;
    int c;

    cout <<"a :"<< a << endl ;
    cout <<"b :"<< b << endl ;
    c = a + b;
    cout <<"a + b :"<< c << endl;

    c = a - b;
    cout <<"a - b :"<< c << endl;

    c = a * b;
    cout <<"a * b :"<< c << endl;

    c = a % b;
    cout <<"a % b :"<< c << endl;

    c = a / b;
    cout <<"a / b :"<< c << endl;

    return 0;
}**/

 /**int main() {
    int a = 5;
    int b = 6;

    cout <<"a = "<< a << "b = " << b << endl;
    if (a == b)
    {
        cout << "(a == b) a is equal to b " << endl;
    }
    else
    {
        cout << " (a == b) a is not equal to b" << endl;
    }
        if (a < b)
    {
        cout << "(a < b) a is less than b " << endl;
    }
    else
    {
        cout << " (a < b) a is not less b" << endl;
    }
          if (a > b)
    {
        cout << "(a > b) a is greater than b " << endl;
    }
    else
    {
        cout << " (a > b) a is not greater than b" << endl;
    }
          if (a <=  b)
    {
        cout << "(a <= b) a is less than \ or equal to b " << endl;
    }
           if (b >=  a)
    {
        cout << "(a <= b) b is greater than \ or equal to a " << endl;
    }
    return 0;
}**/

/**int main(){
    int a = 5;
    int b = 6;

    cout << "a =" << a << "b =" << b << endl;
    if (a < 6 && b < 5)
    {
        cout << "(a < 6)&& (b > 5) is TRUE" << endl;
    }
    else
    {
        cout << "(a < 6)&& (b > 5) is FALSE" << endl;
    }
    if (a < 6 || b < 5)
    {
        cout << "(a < 6) || (b > 5) is TRUE" << endl;
    }
    else
    {
        cout << "(a < 6) || (b > 5) is FALSE" << endl;
    }
    if (!(a < 6))
    {
        cout << "!(a < 6) is TRUE" << endl;
    }
    else
    {
        cout << "!(a < 6) is FALSE" << endl;
    }
    return 0;
}**/

/**int main(){
    // a = 5(000000101), b = 9(00001001)
    int a =5, b = 9;

    // the result is 00000001
    cout << "a =" << a << ","
         << "b =" << b << endl;
    cout << "a & b =" << (a & b) << endl;

    // the result is 00001101
    cout << "a | b =" << (a | b) << endl;

       // the result is 00001100
    cout << "a ^ b =" << (a ^ b) << endl;

       // the result is 11111010
    cout << "~("<< a <<") =" << (~a) << endl;

       // the result is 00010010
    cout << " b << 1"
         << "=" << (b << 1) << endl; 

      // the result is 00000100
    cout << " b >> 1"
         << "=" << (b >> 1) << endl; 

    return 0;
}**/

/**int main (){
   int a = 21;
   int b = 3;
   int c;
      c = a+b;
    cout << "a +b, value of c = : " << c << endl;
      c += a;
    cout << "+= a, value of c = : " << c << endl;
    c -= a;
    cout << "-= a, value of c = : " << c << endl;
       c *= a;
    cout << "*= a, value of c = : " << c << endl;
       c /= a;
    cout << "/= a, value of c = : " << c << endl;
      c = 200;
       c %= a;
    cout << "when c = 200, c %= a, value of c = : " << c << endl;
       c <<= 2;
    cout << "c <<= 2;, value of c = : " << c << endl;
     c >>= 2;
    cout << "c >>= 2;, value of c = : " << c << endl;
     c &= 2;
    cout << "c &= 2;, value of c = : " << c << endl;
     c ^= 2;
    cout << "c ^= 2;, value of c = : " << c << endl;
     c |= 2;
    cout << "c |= 2;, value of c = : " << c << endl;
        return 0;
}**/

int main() {

    {
    double a = 10.2;
    float b = 5.09;
    int c;

    c = (int)a;
    cout <<"(int) a :" << c << endl;

     c = (int)b;
    cout <<"(int) a :" << c << endl; 
    }
    
    {
        int a,b;
        a = ( b = 4, b +7 );
        cout << "a = ( b = 4, b +7 ):" << a << endl;
    }

return 0;}