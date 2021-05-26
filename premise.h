#include <iostream>
#include <string.h>

using namespace std;
/**
*   This "premise" function iterates over all strings and finds the string containing the 'P' character after '/'.
*    If found then the statement is marked as valid.
*/

void premise(string s[],int index[],int arr[],int size){

    /*  if premise, that statement is valid , so changing the value of that to 1.
     */

    for(int j=1;j<size;j++){

    /*  if the character after '/' is 'P' it is premise.
     */

        if(s[j][index[j]+1] == 'P'){
            arr[j] = 1;
        }
    }
}
