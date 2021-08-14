#include <iostream>
using namespace std;

int tab[5][6]={0};
int val[5]={0,3,4,5,6};
int w[5]={0,2,3,4,1};

int main(){

    for(int i=1;i<5;i++){

        for(int k=1;k<6;k++){

            if((w[i])<=k){

                if((val[i]+tab[i-1][k-w[i]])>tab[i-1][k]){

                    tab[i][k]=val[i]+tab[i-1][k-w[i]];

                }
                else{

                    tab[i][k]=tab[i-1][k];

                }

            }

            else{
                tab[i][k]=tab[i-1][k];
            }
        }
    }
    for(int i=0;i<5;i++){
            cout<<endl;
            for(int k=0;k<6;k++){
                cout<<tab[i][k]<<"|";
            }
    }
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


