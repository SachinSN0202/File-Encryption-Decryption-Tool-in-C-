#include "encrypheader.h"
// File stream is required for file operations
#include <fstream>
// check characters Is it a letter uppercase or lowercase,number?
#include <cctype>


// Perform Ceaser Cipher Function
bool performCeaserCipher(string & content, bool encrypt) {

    // Shift = 3 for encryption, -3 for decryption (ternary operator : condition ? value_if_true : value_if_false)
    int shift = encrypt ? 3 : -3; // Shift right for encryption, left for decryption

    for (char & c : content) {
        // Uses cctype library to check if character is an alphabet
        if (isalpha(c)) { // Check if character is an alphabet
            char base = islower(c) ? 'a' : 'A';
            // Encryption   C = (P + Shift) mod 26 
            c = static_cast<char>(base + (c - base + shift + 26) % 26); // Wrap around using modulo
        }
    }
    return true; // Operation successful
}

bool encryptFile(const string & filename, bool encrypt) {
    // Open the file in binary mode for reading and writing
    ifstream infile(filename);
    if(!infile){
        return false; // File could not be opened
    }

    // Read the Content of file

    // infile → a file opened using ifstream
    // istreambuf_iterator<char> → reads one character at a time
    // All characters are put into the string content
    string content((istreambuf_iterator<char>(infile)),istreambuf_iterator<char>());
    infile.close();

    if(performCeaserCipher(content, encrypt)){
        // Create output file name based and writing the modified content
        ofstream outfile(encrypt ? "encrypted_" + filename : "decrypted_" + filename);
        if(!outfile){
            return false; // File could not be opened for writing
        }

        // Write the modified content back to the file
        outfile.write(content.c_str(), content.size());
        outfile.close();
        return true; // Operation successful
    } else {
        return false; // Cipher operation failed
    }
}