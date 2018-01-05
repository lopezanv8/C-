// beaufort cipher, http://practicalcryptography.com/ciphers/classical-era/beaufort/
#include<iostream>
using std::cout; using std::cin; using std::endl;
#include<string>
using std::string;
#include <algorithm>

/*
Ana Lopez
Project 5 Section 11
10/16/17

working with strings and string manipulation. 

*/

const string alphabet = "abcdefghijklmnopqrstuvwxyz";

string rotate_left(int rotations, string s) {
    string rotated_s = alphabet.substr(0, rotations); //string of the alphabet only up until the number of rotations entered.
    //unsigned int i=0;
    int rotated_s_mod = 0;
    string rotated_s_front = " ";
    string rotated_s_back = " ";
     if (rotations < 0) { //rotation amount has to be positive
            return s;
    }
    // for (i=0; i < s.length(); i++){
        rotated_s_mod = rotations % s.length(); //if rotation longer than the string length, mod reduces it actually rotating all 
        rotated_s_front = s.substr(0, rotations); //takes the first part of the string up until the number of rotations. will be set to a different string
        rotated_s_back = s.substr(rotations); //takes the part after the first part of the string. will be set to a different string
        rotated_s = (rotated_s_back + rotated_s_front); //combines both of the strings, but it is now rotated because the beginning part is moved to the back
        //s.push_back(rotated_s);
      
    // }
    return rotated_s;
}

char beaufort_letter(char plain_letter, char key_letter) {
    if (!islower(plain_letter) || !islower(key_letter)) {
        return plain_letter;
    } // check for error, if they are not lower case characters then return original plaintext letter.
    int n = key_letter - plain_letter;
    if (n < 0)
        n += 26; //n not being over the number of letters in alphabet
    string new_apl = rotate_left(n, alphabet);
    return new_apl[0]; //first ch
}

char vigenere_letter(char plain_letter, char key_letter) {
   if (!islower(plain_letter) || !islower(key_letter)) {
        return plain_letter;
    }//check for error, if they are not lower case characters then return original plaintext letter.
    int index_of_key = 0;
    int index_of_plain = 0;
    int vig_index = 0;
    char vig_char = ' ';
    index_of_key = alphabet.find(key_letter); //finds the index of ch plain_letter in the alphabet 
    index_of_plain = alphabet.find(plain_letter); //finds the index of ch key_letter in the alphabet 
    
    vig_index = index_of_plain + index_of_key; //combines the two indexes of key and plain letter to obtain the index of the vigenere letter
    vig_index %= 26; //keeps range of indexes within the range of the alphabet
    vig_char = alphabet[vig_index]; //changes the index of the vigenere letter to its actual character
    
    return vig_char;
}

string encode_beaufort (string plain_text, string key) 
{
    //unsigned int i = 0;
    int difference = 0;
    string encoded_str = "";
    char encoded_ch = ' ';

    //checks whether the key is shorter than the plain text
    if (plain_text.length() > key.length()) {
        difference = plain_text.length() - key.length(); //find how mcuh longer the plain text is than the key. 
        key += key.substr(0, difference); //takes the number of characters in the key that are the difference between plain text and the key and adds them back onto the key. 
       // key = key.push_back(char_diff);
        
    }
    for (unsigned int i = 0; i < plain_text.length(); i++) 
    {
        if (islower(plain_text[i]) && isalpha(plain_text[i]))
        { //checks that plain test is letter case letter and actual alphabetic characters
            encoded_ch = beaufort_letter(plain_text[i], key[i]); //finds the character where plain test and the key intersect
            encoded_str.push_back(encoded_ch); //adds that character back to the beaufort string 
        }
    }
    return encoded_str;
}

string encode_vigenere (string plain_text, string key) {
    
    int difference = 0;
    string encoded_str = "";
    char encoded_ch = ' ';

    //checks whether the key is shorter than the plain text
    if (plain_text.length() > key.length()) {
        difference = plain_text.length() - key.length(); //find how mcuh longer the plain text is than the key. 
        key += key.substr(0, difference); //takes the number of characters in the key that are the difference between plain text and the key and adds them back onto the key. 
    }
    for (unsigned int i = 0; i < plain_text.length(); i++) 
    {
        if (islower(plain_text[i]) && isalpha(plain_text[i]))
        { //checks that plain test is letter case letter and actual alphabetic characters
            encoded_ch = vigenere_letter(plain_text[i], key[i]); //finds the character where plain test and the key intersect
            
        //   cout << "here --" << i << "--" << plain_text[i] << "--" << key[i] << "--" << encoded_ch << "--" << endl; 
            encoded_str.push_back(encoded_ch); //adds that character back to the beaufort string 
        }
    }
    return encoded_str;
}


int main() {
  int case_number;
  cin >> case_number;

  switch (case_number){

  case 1: {
    int rotations;
    cin >> rotations;
    string s;
    cin >> s;
    cout << rotate_left(rotations, s) << endl;
    break;
  }
 
  case 2: {
    char plain_letter;
    char key_letter;
    cin >> plain_letter >> key_letter;
    cout << beaufort_letter(plain_letter, key_letter) << endl;
    break;
  }

  case 3:{
    char plain_letter;
    char key_letter;
    cin >> plain_letter >> key_letter;
    cout << vigenere_letter(plain_letter, key_letter) << endl;
    break;
  }

  case 4:{
    string plain_text;
    string key;
    cin.ignore(100, '\n');
    getline(cin, plain_text);
    getline(cin, key);
    cout << encode_beaufort(plain_text, key) << endl;
    break;
  }
 
  case 5:{
    string plain_text;
    string key;
    cin.ignore(100, '\n');
    getline(cin, plain_text);
    getline(cin, key);
    cout << encode_vigenere(plain_text, key) << endl;
    break;
  }

  } // of switch
  
}// of main
