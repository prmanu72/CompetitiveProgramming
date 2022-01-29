#### Add without +
```
^ gives sum without carry
& gives carry, carry has to be added after left shifting 1 bit

#include <iostream>

using namespace std;

int main()
{
    int a = 8;
    int b = 99;
    int sum = 0;
    int carry = 0;
    
    do{
        sum = a ^ b;
        carry =  a & b;
        carry = carry << 1;
        a = sum;
        b = carry;
    }while(carry);
    
    cout<<sum;
    return 0;
}
```
