#include <iostream>
#include "encrypheader.h"

using namespace std;

int main(){
    
    string filename;

    // Encryption or Decryption choice
    char choice;

    cout<<"Enter the file name: ";
    // ws ignore all leading whitespace characters
    getline(cin >>ws, filename);


     // Encryption or Decryption choice
    cout << "Would you like to Encrypt (e)  or Decrypt (d) a file ?";
    cin >> choice;

    
    // Conditional Statements

    // For Any Alphabet Case Input  (Upper or Lower)
    if(choice == 'e' || choice == 'E'){
        if(encryptFile(filename, true)){
            cout << "File Encrypted Successfully!" << endl;
        } else {
            cout << "Error: Unable to perform encryption.\n Encryption Failed!" << endl;
        }
    }
    else if(choice == 'd' || choice == 'D'){
        if(encryptFile(filename, false)){
            cout << "File Decrypted Successfully!" << endl;
        } else {
            cout << "Error: Unable to perform decryption.\n Decryption Failed!" << endl;
        }
    }
    else{
        cout << "Invalid Choice!" << endl;
    }


    return 0;

}