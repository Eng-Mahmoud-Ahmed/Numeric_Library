#include <iostream>
#include <string>
#include "math.hpp"

using namespace std;





int main ()
{   

    cout << "maximum= " << nlib::max(1,0,152,50,12,9595.94) <<endl;
    cout << "minimum= " << nlib::min(-26,1,0,152,50,10,0.62,9595.94) <<endl;
    cout << "sub = " << nlib::sub(100,12,15,-25,10.5) <<endl;
    cout << "sum = " << nlib::sum(100,12,15,-25,10.5) <<endl;

    Custom c1("Hello");
    Custom c2("World");
    cout <<  nlib::sub(c1,c2)<<endl;
   return 0;
}

