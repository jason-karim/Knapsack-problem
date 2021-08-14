#include <iostream>
using namespace std;

int tab[5][6]={0};
int val[5]={0,3,4,5,6};
int w[5]={0,2,3,4,1};

int knapsack(int i,int k){
    if(i>0&&k>0){
        int a=knapsack(i-1,k-w[i]);
        int b=knapsack(i-1,k);

        if((w[i])<=k){

            if((val[i]+a)>b){

                tab[i][k]=val[i]+a;
                return tab[i][k];

            }
            else{

                tab[i][k]=b;

                return tab[i][k];

            }

        }

        else{
            tab[i][k]=b;
            return tab[i][k];
        }
    }
    else{
    return 0;
    }
}
int knapsack(){

    knapsack(5,6);

    return 0;
}

int bestItems(){
    cout<<endl<<"the best items are: ";
    int i=4;
    int k=5;
    while(k>0&&i>0){
        while(tab[i][k]==tab[i-1][k]){
            i--;
        }
        cout<<i<<",";
        k=k-w[i];
        i--;
    }
    return 0;
}

int main(){

    knapsack();

    for(int i=0;i<5;i++){
            cout<<endl;
            for(int k=0;k<6;k++){
                cout<<tab[i][k]<<"|";
            }
    }
    bestItems();

    return 0;


}


