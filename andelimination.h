#include <iostream>
#include <string.h>

using namespace std;
/**
*   This "and elimination" function iterates over all strings and finds the string containing the '^e' rule.
*    For example if the rule found is like '^enum1/num2'(note that num1 can be only 1 or 2, no other value).
*    Which part of the string num2(num2 is the id of string) need to be taken is decided by the value of num1.
*    Now that new string is compared with statement containing and elimination rule.
*    If both strings are equal then it implies that the statement is valid.
*/

void and_elimination(string s[],int index[],int arr[],int size){
    int count=0;
    int z,l=0,w=1;
    for(int j=1;j<size;j++){

            /*  searching for and elimination rule.
             */

        if((s[j][index[j]+1] == '^') && (s[j][index[j]+2] == 'e')){
            count = 0;
            string str1,str2;

            /*  finding statement number on which and elimination is applied
             */

            z = s[j][index[j]+5] - 48;

                for(int k=0;k<index[z];k++){

            /*  searching for the outermost '^'(i.e topmost in parse tree).
             */

                    if(s[z][k] == '('){
                        l++;
                    }
                    else if(s[z][k] == ')'){
                        l--;
                    }

                    if(l==1 && s[z][k] == '^'){

            /*  if rule is like e1/statement no.
             */
                        if(s[j][index[j]+3] == '1'){

            /*  taking all the required elements left to that outermost 'V' and storing in str2.
             *  excluding outermost brackets
             */

                            for(int y=1;y<k;y++){
                                str2[y-1] = s[z][y];
                            }
                        }
            /*   if rule is like e2/statement no.
             */
                        if(s[j][index[j]+3] == '2'){

            /*  taking all the elements right to that outermost 'V' until '/' and storing in str2.
             *  excluding outermost brackets
             */

                            for(int y=k+1;y<index[z]-1;y++){
                                str2[y-1-k] = s[z][y];
                            }
                        }
                    }
                }

            /*  storing the statement containing the rule in the str1
             */

                for(int k=0;k<index[j];k++){
                    str1[k] = s[j][k];
                }

            /*  comparing both strings
             */

                for(int k=0;k<index[j];k++){
                    if(str1[k]!=str2[k]){
                        count++;
                    }
                }

            /*  if both the statements are equal then the statement is valid.
             */

                if(count==0){
                    arr[j] = 1;
                }
        }
    }
}
