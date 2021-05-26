#include <iostream>
#include <string.h>
#include <time.h>
#include "premise.h"
#include "andintroduction.h"
#include "andelimination.h"
#include "orintroduction.h"
#include "implicationelimination.h"
#include "modustollens.h"

using namespace std;

int main()
{
    int n,count=0;

        /*  n stores the value of the number of statements.
         */

    cin >> n;
    int k=0;

        /*  index array stores the index of first '/' in every statement.
         */

    int index[n+1];

        /*  each value of arr array can be 1 or 0,1 representing that particular statement is valid,
         *  0 representing that the statement is invalid.
         */

    int arr[n+1];

        /*  initializing all values of arr to zero.
         */

    for(int i=0;i<n+1;i++){
        arr[i] = 0;
    }

        /*  creating a string array so that all the strings entered can be stored in this array.
         */

    string s[n+1];

    for(int i=0;i<n+1;i++){
        getline(cin,s[i]);
    }

        /*  starting clock.
         */

    clock_t tStart = clock();
    for(int i=0;i<n+1;i++){
        if(i!=0){
        while(s[i][k] != '/'){
            k++;
        }
        index[i] = k;
        k=0;
        }
    }

        /*  testing all rules over the proof and marking them as valid
         *  so, after this process even if one statement is not valid , then the whole proof is not valid.
         */

    premise(s,index,arr,n+1);
    and_introduction(s,index,arr,n+1);
    and_elimination(s,index,arr,n+1);
    or_introduction(s,index,arr,n+1);
    implication_elimination(s,index,arr,n+1);
    modus_tollens(s,index,arr,n+1);

        /*  checking the proof is valid or invalid
         *  if all the values in the array is 1 it means that all statements are valid hence the proof is valid.
         */

    for(int i=1;i<n+1;i++){
        if(arr[i]!=1){
            count++;
        }
    }
        if(count!=0){
            cout << "invalid proof";
        }
        else{
            cout << "valid proof";
        }
    cout << endl;
    cout << "Time taken for running:" <<  (double)(clock() - tStart)/CLOCKS_PER_SEC;
    return 0;
}
