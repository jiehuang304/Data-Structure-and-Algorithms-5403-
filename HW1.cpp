#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

// Created by Jie Huang 
// N#: 12687614
//Solution for HW#2 prob.3

using namespace std;

class Solution {
    
public:

    string encipher(string Text, string keyword, char VigenerTable[][26]) {
        string text = "";
        for (int i = 0; i < Text.length(); i++) {
            if (Text[i] != ' ') {
                text += Text[i];
            }
        }

        int n = text.length();
	    string Keyword = "";

	    while (Keyword.length() < n) {
	        Keyword += keyword;
        }

	    if (Keyword.length() > n) {
	        Keyword = Keyword.substr(0, n + 1);
	    }

	    string result = "";
	    for (int k = 0; k < n; k++) {
	        char i = toupper(Keyword[k]);
	        char j = toupper(text[k]);

	        result += VigenerTable[(int)(i - 'A')][(int)(j - 'A')];
	    }

	    return result;
    }

public:

    string decipher(string code, string keyword, char VigenerTable[][26]) {
	    string result = "";

	    for (int k = 0; k < code.length(); k++) {
	        int count = k;
	       	while (count >= keyword.length()) {
	            count -= keyword.length();
            }

	        int i = (int)(toupper(keyword[count]) - 'A');
	        int j = -1;

	        for (int l = 0; l < 26; l++) {
	            if (VigenerTable[i][l] == code[k]) {
	                j = l;
	            }
	        }
            
            result += (char)('A' + j);
	        
	    }

	    return result;
    }
};

int main()
{   
    // Print the vigenere Table by rows
    char vigenereTable[26][26];
    char ALPH[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    
    for(int i = 0; i < 26; i++) {
        int k = i;

        for(int j = 0; j < 26; j++) {
            if(k < 26) {
                vigenereTable[i][j] = ALPH[k];
            }
            else {
                vigenereTable[i][j] = ALPH[(k%26)];
            }
            k++;
        }
    }
    
    for(int i=0;i<26;i++){
		for(int j=0;j<26;j++){
			printf("%c ",vigenereTable[i][j]);
		}
		printf("\n");
      
	}
    
      printf("\n\n");
    
    // Print the vigenere Table by colomns
    char vigenereTable2[26][26];
    /*char ALPH[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}; */
    
    for(int i = 0; i < 26; i++) {
         int k = i;
        
        for(int j = 0; j < 26; j++) {
           
            if(k < 26) {
                vigenereTable2[j][i] = ALPH[k];
            }
            else {
                vigenereTable2[j][i] = ALPH[(k%26)];
            }
            k++;
        }
    }
    
    for(int i=0;i<26;i++){
		for(int j=0;j<26;j++){
			printf("%c ",vigenereTable2[i][j]);
		}
		printf("\n");
	}
    
    
    // Print the  Enciper
    Solution solution;

    string toEncipher = "to be ot not to be that is the question";
    string keyword = "RELATIONS";
    
   string code = solution.encipher(toEncipher, keyword, vigenereTable);
   
    int count = 0;
    for (int i = 0; i < code.length(); i++) {
        if (count != 0 && count % 5 == 0) {
            cout<<" ";
        }
        cout<<code[i];
        count++;
    }
    cout << endl;

     // Print the  Deciper
    count = 0;
  
    string back = solution.decipher(code, keyword, vigenereTable);
  
    for (int i = 0; i < back.length(); i++) {
        if (count != 0 && count % 5 == 0) {
            cout<<" ";
        }
        
        char temp = tolower(back[i]);
        cout<<temp;
        count++;
    }
    cout << endl;
    
    return 0;
}




