#include <iostream>
#include <string.h>

using namespace std;
/**
*   This "implication elimination" function iterates over all strings and finds the string containing the '>e' rule.
*    For example if the rule found is like '>e/num1/num2'.
*    Both the parts(i.e the part to the right and left of the implication) are stored in seperate strings.
*    Consider left part is stored in str1 and right part in str 2.
*    Now str1 is compared with the string num2(num2 is the id of string) and str2 is compared with the statment containing '>e' rule.
*    If both conditions are satisfied then it implies that the statement is valid.
*/

void implication_elimination(string s[],int index[],int arr[],int size){
    int count =0;
    int l=0;
    for(int j=1;j<size;j++){

                /*  searching for implication elimination rule.
                 */

        if((s[j][index[j]+1] == '>') && (s[j][index[j]+2] == 'e')){
                count=0;
               string str1,str2,str3,str4;

                /*  finding statement number on which and elimination is applied
                 */

                    int z = s[j][index[j]+4] - 48;

                /*  storing the statement containing '>e' rule in str4.
                 */

                    for(int k=0;k<index[j];k++){
                        str4[k] = s[j][k];
                    }

                /*  storing the string num2 in str3
                 */

                    int m = s[j][index[j]+6] - 48;
                    for(int k=0;k<index[m];k++){
                        str3[k] = s[m][k];
                    }

                    for(int k=0;k<index[z];k++){
                        if(s[z][k] == '('){
                            l++;
                        }
                        else if(s[z][k] == ')'){
                            l--;
                        }
                        if(l==1 && s[z][k] == '>'){

                /*  taking all the required elements left to that outermost '>' and storing in str1.
                 *  excluding outermost brackets
                 */

                            for(int y=1;y<k;y++){
                                str1[y-1] = s[z][y];
                            }

                /*  taking all the elements right to that outermost '>' until '/' and storing in str2.
                 *  excluding outermost brackets
                 */

                            for(int y=k+1;y<index[z]-1;y++){
                                str2[y-1-k] = s[z][y];
                            }

                        }
                    }
                    for(int k=0;k<index[m];k++){

                /*  condition 1: str1 should be equal to str3.
                 */

                        if(str1[k]!=str3[k]){
                            count++;
                        }
                    }
                    for(int k=0;k<index[j];k++){

                /*  condition 2: str2 should be equal to str4.
                 */

                        if(str2[k]!=str4[k]){
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
