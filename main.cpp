#include <iostream>
#include <string>

using std::cout;
using std::cin;
using namespace std;;

char input[100];
char input1[100];

int buffer[100];
int bufferMulti[100][100];
int bufferCount[200] = {0};

int a[100];
int b[100];

int cSum[200];
int cDiff[200];
int cMulti[200];

int sumCount = 0;
int diffCount = 0;
int multiCount = 0;

int counter = 0;

int sum(){
    for(int i = 199; i >= 0; i-=1){
        
        bufferCount[i - 100] = (a[i - 100] + b[i - 100] + bufferCount[i - 99]) / 10;
        
        cSum[i] += (a[i - 100] + b[i - 100] + bufferCount[i - 99]) % 10;
        
        
        
        //DEBUG
        //cout << "\n";
        //cout << a[i] << " A index " << i << "\n";
        //cout << b[i] << " B index " << i << "\n";
        //cout << bufferCount[i] << " Buffer index " << i << "\n";
        //cout << cSum[i] << " C index " << i << "\n";
    }
    for(int i = 99; i >= 0; i-=1) if(a[i] != 0 or b[i] != 0 or bufferCount[i - 100] != 0) sumCount++;
    return 0;
}

int diff(){
    for(int i = 199; i >= 0; i-=1){
        
        if (a[i - 100] - b[i - 100] < 0){
            
            bufferCount[i - 100] = -1;
            cDiff[i] += (a[i - 100] + 10) - b[i - 100];
        }
        else
        {
            bufferCount[i - 100] = 0;
            cDiff[i] += a[i - 100] - b[i - 100];
        }
        
        cDiff[i - 1] += bufferCount[i - 100];
        
        //DEBUG
        //cout << "\n";
        //cout << a[i] << " A index " << i << "\n";
        //cout << b[i] << " B index " << i << "\n";
        //cout << bufferCount[i] << " Buffer index " << i << "\n";
        //cout << cDiff[i] << " C index " << i << "\n";
    }
    for(int i = 99; i >= 0; i-=1) if(a[i] != 0 or b[i] != 0 or bufferCount[i] != 0) diffCount++;
    return 0;
}

int multi(){
    for(int i = 99; i >= 0; i-=1){
        
        for(int d = 0; d < 100; i++){
            //bufferCount[i - 100] = (a[i - 100] * b[i - 100] + bufferCount[i - 99]) / 10;
        
            bufferMulti[i][d] = (a[d] * b[i] * 10^d) % 10;
            
            bufferCount[i] = bufferMulti[i][d] / 10;
            cMulti[i + 100]+=bufferMulti[i][d] + bufferCount[i] % 10; 
            
            cout << bufferMulti[i][d] << " i = " << i << " d =  " << d << "\n";
        }
        
    }
    
    
    
    for(int i = 99; i >= 0; i-=1) if(a[i] != 0 or b[i] != 0 or bufferCount[i - 100] != 0) multiCount++;
    return 0;
}

int main()
{
    cout << "Enter first number\n";
    scanf("%s", input);
    
    for(int i = 0; i < 100; i++) buffer[i] = input[i] - '0';
    
    for(int i = 0; i < 100; i++){
        if(buffer[i] != -48) counter++;
    }
    
    for(int i = 0; i < counter; i++){
        a[(100 - counter) + i] = buffer[i];
    }
    
    counter = 0;
    //DEBUG
    //cout<<"Buffer";
    //for(int i = 0; i < 100; i++) cout << buffer[i];
    //cout<<"a";
    //for(int i = 0; i < 100; i++) cout << a[i];
    
    cout << "Enter second number\n";
    scanf("%s", input1);
    
    for(int i = 0; i < 100; i++) buffer[i] = input1[i] - '0';
    
    for(int i = 0; i < 100; i++){
        if(buffer[i] != -48) counter++;
    }
    
    for(int i = 0; i < counter; i++){
        b[(100 - counter) + i] = buffer[i];
    }
    
    sum();
    cout << "\n" << "Sum: ";
    for(int i = 199 - sumCount; i < 200; i++) cout << cSum[i];
    
    diff();
    cout << "\n" << "Diff: ";
    for(int i = 199 - diffCount; i < 200; i++) cout << cDiff[i];
    
    //multi();
    //cout << "\n" << "Multi: ";
    //for(int i = 0; i < 200; i++) cout << cMulti[i];
    
}
