# include<iostream>
# include<stdlib.h>
# include<time.h>

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

int main(){
    int num[100], prime[100], j=0;
    srand(time(NULL));
    for(int i=0; i<100; i++){
        num[i] = rand();
    }
    cout<<"All the random numbers:\n";
    for(int i=0; i<100; i++){
        cout<<num[i]<<"\t";
    }
    for(int i=0; i<100; i++){
        if(checkPrime(num[i])){
            prime[j] = num[i];
            j++;
        }
    }
    cout<<"\nAll the prime numbers out of random numbers:\n";
    for(int i=0; i<j; i++){
        cout<<prime[i]<<"\t";
    }
}