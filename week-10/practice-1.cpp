#include <iostream>
#include <iterator>
#include <list>
using namespace std;

void showlist(list <int> g)
{
    list <int> :: iterator it;
    for(it = g.begin(); it != g.end(); ++it)
        cout<<'\t'<<*it;
    cout <<'\n';
}

int main()
{
    list <int> gqlist1, gqlist2;
    for (int i = 0; i < 10; ++i)
    {
        gqlist1.push_back(i * 2);
        gqlist2.push_front(i * 3);
    }
    cout<<"\nlist 1 (gqlist1) is : ";
    showlist(gqlist1);

    cout<<"\nlist 2 (gqlist2) is : ";
    showlist(gqlist2);

    cout<<"\nqlist1.front() : "<< gqlist1.front();
    cout<<"\nqlist1.back() : "<<gqlist1.back();

    cout << "\ngqlist1.pop_front() : ";
    gqlist1.pop_front();
    showlist(gqlist1);

    cout<<"\ngqlist2.pop_back() : ";
    gqlist2.pop_back();
    showlist(gqlist2);

    cout<<"\ngqlist1.reverse() :";
    gqlist1.reverse();
    showlist(gqlist1);

    cout<<"\ngqlist2.sort(): ";
    gqlist2.sort();
    showlist(gqlist2);

    return 0;
}