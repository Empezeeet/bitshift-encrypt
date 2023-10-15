//
// Created by Empezeeet on 14/10/2023.
//

#ifndef BITSHIFTENCRYPT2_FUNCTIONS_BSE2_H
#define BITSHIFTENCRYPT2_FUNCTIONS_BSE2_H

#include <sstream>
#include <iomanip>
#include <vector>

#endif //BITSHIFTENCRYPT2_FUNCTIONS_BSE2_H

unsigned int convertToRange(unsigned int max, unsigned int num) {
    if (num < max) return num;
    return num%max;
}

std::vector<int> encrypt(const std::string* input, const std::string* key) {
    // convert string to vector of int values of chars
    std::vector<int> intText;
    int bitshift;
    // convert input to int vector
    for (char c : *input) intText.push_back((int) c);


    for (int i=0; i<intText.size(); i++) {
         bitshift = 1 + int((*key)[convertToRange((*key).length(), i)]-'0');

         intText[i] = (intText[i] << bitshift) + bitshift;
    }
    return intText;
}
template< typename T >
std::string int_to_hex( T i )
{
    std::stringstream stream;
    stream << std::hex << i;
    return stream.str();
}
std::vector<int> hexStringToIntVector(const std::string& str) {
    std::vector<int> intVector;
    std::istringstream iss(str);
    std::string hexValue;

    while (iss >> hexValue) {
        int intValue;
        if (std::stringstream(hexValue) >> std::hex >> intValue) {
            intVector.push_back(intValue);
        }
    }

    return intVector;
}
std::vector<int> decrypt(std::vector<int> buffer, const std::string* key) {
    int bitshift;


    for (int i = 0; i < buffer.size(); i++) {
        bitshift = 1 + int((*key)[convertToRange((*key).length(), i)]-'0');

        // Reverse the operations
        buffer[i] = (buffer[i] - bitshift) >> bitshift;
    }
    return buffer;

}
bool isBinary(const std::string* input)
{
    for (char c : *input) {
        if (c != '0' && c != '1') {
            return false;
        }
    }
    return true;
}
