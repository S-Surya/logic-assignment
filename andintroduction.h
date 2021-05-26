#include <iostream>
#include <string.h>

using namespace std;
/**
*   This "and introduction" function iterates over all strings and finds the string containing the '^i' rule.
*    For example if the rule found is like '^i/num1/num2'.
*    Then the statement with num1 is concatinated with '^' and then with statement with num2.
*    Now that new string is compared with statement containing and introduction rule.
*    If both strings are equal then it implies that the statement is valid.
*/
void and_introduction(string s[],int index[],int arr[],int size){
    int count = 0;

    int m;
    int l;
    int strind;
    for(int j=1;j<size;j++){

                /*  searching for the statement containing and introduction rule.
                 */
        if((s[j][index[j]+1] == '^') && (s[j][index[j]+2] == 'i')){
                      count = 0;
            string str,str1;

                /*  str is the string obtained by concatinating the strings corresponding to numbers in the given rule.
                 */

            str[0] = '(';

                /*  s[j][index[j]+4] gives the statement number in char, so converting the number into int by
                 *   subtracting 48(which is ASCII value of zero).
                 */

            for(int k=0;k<index[(s[j][index[j]+4])-48];k++){
                m=k+1;
               str[k+1] = s[s[j][index[j]+4]-48][k];
            }

                /*  adding the and symbol to the string being formed,since its an and introduction rule.
                 */

            str[m+1] = '^';
            for(int k=m+2;k<m+2+index[s[j][index[j]+6]-48];k++){
                l = k;
                str[k] = s[s[j][index[j]+6]-48][k-m-2];
            }
            str[l+1] = ')';

                /*  taking the and introduction string until '/' into str1,inorder to compare it with str to find out
                 *  whether the statement is valid or not.
                 */
            for(int k=0;k<index[j];k++){
                str1[k] = s[j][k];
            }

                /*  now comparing str and str1.
                 */
            for(int k=0;k<index[j];k++){
                if(str1[k]!=str[k]){
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
