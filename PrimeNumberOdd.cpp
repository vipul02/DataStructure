# include<iostream>
# include<stdlib.h>
# include<time.h>
# include<conio.h>
using namespace std;

int checkPrime(int num){
    int flag = 1;
    for(int i=2; i<num; i++){
        if(num%i == 0){
            flag = 0;
            break;
        } 
    }
    return flag;
}

int checkOdd(int num){
    int flag = 1;
    if(num%2 == 0){
        flag = 0;
        return flag;
    }
    return flag;
}

int main(){
    
    int num[100], primeOddCounter=0, oddCounter=0;
    int *primeOdd = NULL;
    int *odd = NULL;
    
    srand(time(NULL));
    for(int i=0; i<100; i++){
        num[i] = rand();
    }
    
    cout<<"All the random numbers:\n";
    for(int i=0; i<100; i++){
        cout<<num[i]<<"\t";
    }
    
    for(int i=0; i<100; i++){
        if(checkOdd(num[i])){
            oddCounter++;
            if(checkPrime(num[i])){
                primeOddCounter++;
            }
        }
    }

    primeOdd = (int*)malloc(sizeof(int)*primeOddCounter);
    odd = (int*)malloc(sizeof(int)*oddCounter);
    primeOddCounter = 0;
    oddCounter = 0;

    for(int i=0; i<100; i++){
        if(checkOdd(num[i])){
            *(odd + oddCounter) = num[i];
            oddCounter++;
            if(checkPrime(num[i])){
                *(primeOdd + primeOddCounter) = num[i];
                primeOddCounter++;
            }
        }
    }
    
    
    cout<<"\nAll the odd numbers out of random numbers are:\n";
    for(int i=0; i<oddCounter; i++){
        cout<<*(odd + i)<<"\t";
    }

    cout<<"\nOf which prime numbers are:\n";
    for(int i=0; i<primeOddCounter; i++){
        cout<<*(primeOdd + i)<<"\t";
    }

    getch();
    return 0;
}