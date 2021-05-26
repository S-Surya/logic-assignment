#include <iostream>
#include <string.h>

using namespace std;
/**
*   This "or introduction" function iterates over all strings and finds the string containing the 'Vi' rule.
*    For example if the rule found is like 'Vinum1/num2'.(note that num1 takes the value only 1 or 2).
*    Which part of the present string need to be taken is decided by the value of num1.
*    Now that new string is compared with the string num2(num2 is the id of string).
*    If both strings are equal then it implies that the statement is valid.
*/

void or_introduction(string s[],int index[],int arr[],int size){

    int count=0;
    int z,l=0,w=1;
    for(int j=1;j<size;j++){

               /*  searching for or introduction rule.
                */

        if((s[j][index[j]+1] == 'V') && (s[j][index[j]+2] == 'i')){
                count = 0;
                 string str1,str2;

                /*  finding statement number on which or introduction is applied
                 */

                    z = s[j][index[j]+5] - 48;

                /*  searching for the outermost 'V'(i.e topmost in parse tree).
                 */

                    for(int k=0;k<index[j];k++){
                        if(s[j][k] == '('){
                            l++;
                        }
                        else if(s[j][k] == ')'){
                            l--;
                        }

                        if(l==1 && s[j][k] == 'V'){

                /*  if rule is like Vi1/statement no.
                 */

                            if(s[j][index[j]+3] == '1'){

                /*  taking all the required elements left to that outermost 'V' and storing in str2.
                 *  excluding outermost brackets
                 */

                                for(int y=1;y<k;y++){
                                    str2[y-1] = s[j][y];
                                }
                            }

                /*  if rule is like Vi2/statement no.
                 */

                            if(s[j][index[j]+3] == '2'){

                /*  taking all the elements right to that outermost 'V' until '/' and storing in str2.
                 *  excluding outermost brackets
                 */

                                for(int y=k+1;y<index[j]-1;y++){
                                    str2[y-1-k] = s[j][y];
                                }
                            }
                        }
                    }

                /*  storing the string on which or introduction is applied until character '/'.
                 */

                 for(int k=0;k<index[z];k++){
                    str1[k] = s[z][k];
                 }

                /*  comparing both strings
                 */

                 for(int k=0;k<index[z];k++){
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
