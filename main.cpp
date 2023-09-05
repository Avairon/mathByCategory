#include <iostream>
#include <string>

using std::cout;
using std::cin;
using namespace std;;

char input[100];

int a[100];
int b[100];

int c[200];


int main()
{
    cout << "Enter first number\n";
    scanf("%s", input);
    
    for(int i = 0; i < 100; i++) a[i] = input[i] - '0';
    for(int i = 0; i < 100; i++) cout << a[i];
    
    cout << "Enter second number\n";
    scanf("%s", input);
    *b = (int)*input;
    
   
    *c = *a + *b;
    cout << *c;
}
