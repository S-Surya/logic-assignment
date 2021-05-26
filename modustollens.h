#include <iostream>
#include <string.h>

using namespace std;
/**
*   This "modus tollens" function iterates over all strings and finds the string containing the 'MT' rule.
*    For example if the rule found is like 'MT/num1/num2'.
*    Both the parts(i.e the part to the right and left of the implication) are stored in seperate strings.
*    Consider left part is stored in str1 and right part in str 2.
*    Now str2 is compared with the string num2(num2 is the id of string) and str1 is compared with the statment containing 'MT' rule.
*    If both conditions are satisfied then it implies that the statement is valid.
*/


void modus_tollens(string s[],int index[],int arr[],int size){
    int count =0;
    int l=0;
    for(int j=1;j<size;j++){

        /*  searching for implication elimination rule.
         */

        if((s[j][index[j]+1] == 'M') && (s[j][index[j]+2] == 'T')){

                count=0;
               string str1,str2,str3,str4;

        /*  finding statement number on which implies is present.
         */

                  int z = s[j][index[j]+4] - 48;

        /*  the string containing MT rule is stored in str4.
         */

                    for(int k=1;k<index[j]-1;k++){
                        str4[k-1] = s[j][k];
                    }
        /*  the statement with id num2 is stored in the string str3.
         */

                    int m = s[j][index[j]+6] - 48;
                    for(int k=1;k<index[m]-1;k++){
                        str3[k-1] = s[m][k];
                    }

                    for(int k=0;k<index[z];k++){
                        if(s[z][k] == '('){
                            l++;
                        }
                        else if(s[z][k] == ')'){
                            l--;
                        }

                        if(l==1 && s[z][k] == '>'){


                            str1[0] = '~';
        /*  taking all the required elements left to that outermost '>' and storing in str1.
         *  excluding outermost brackets and appending a '~' as the starting element of str1
         *  inorder to compare with str4
         */

                            for(int y=1;y<k;y++){
                                str1[y] = s[z][y];
                            }
                            str2[0] = '~';

        /*  taking all the elements right to that outermost '>' until '/' and storing in str2.
         *  excluding outermost brackets and appending a '~' as the starting element of str1
         *   inorder to compare with str3.
         */

                            for(int y=k+1;y<index[z]-1;y++){
                                str2[y-k] = s[z][y];
                            }

                        }
                    }
        /*  condition 1: str1 should be equal to str4.
         */
                    for(int k=0;k<index[j]-2;k++){
                        if(str1[k]!=str4[k]){
                            count++;
                        }
                    }

        /*  condition 2: str2 should be equal to str3.
         */
                    for(int k=0;k<index[m]-2;k++){
                        if(str2[k]!=str3[k]){
                            count++;
                        }
                    }
        /*  if both the conditions are satisfied then the statement is valid.
         */
                    if(count==0){
                        arr[j] = 1;
                    }



        }
    }
}
