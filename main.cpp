//
// Created by Empezeeet on 14/10/2023.
//
#include <iostream>
#include <string>
#include <vector>
#include "functions.bse2.h"
int main() {
    std::string key = "-1";
    std::string input;
    std::vector<int> data;

    short menu=0;
    do {
        std::cout << "1-Encrypt, 2-Decrypt, 3-SetKey, 4-ViewKey, 5-Exit" << std::endl;
        std::cout << ">> ";
        std::cin >> menu;
        if ((key == "-1" && menu != 3 && menu != 5)) {
            system("cls");
            std::cout << "Specify key before encryption or decryption!!!" << std::endl << std::endl;
            continue;
        }
        switch (menu) {
            case 1: {
                system("cls");
                std::cout << "text to encrypt: ";
                std::cin.ignore();
                std::getline(std::cin, input);
                data = encrypt(&input, &key);
                std::cout << "Encrypted: ";
                for (int i : data) {
                    std::cout << int_to_hex(i) << " ";
                }
                std::cout << std::endl;
                break;
            }
            case 2: {
                system("cls");
                std::cout << "ciphertext: ";
                std::cin.ignore();
                std::getline(std::cin, input);
                data = decrypt(hexStringToIntVector(input), &key);
                std::cout << "Decrypted: ";
                for (int i: data) {
                    std::cout << (char)i;
                }
                std::cout << std::endl;
                break;
            }
            case 3: {
                do {
                    std::cout << "Enter Binary Key: ";
                    std::cin >> key;
                } while(!isBinary(&key));
                std::system("cls");
                std::cout << "Set key to: " << key << std::endl;
                break;
            }
            case 4: {
                std::system("cls");
                std::cout << "Key: " << key;
                std::cout << std::endl << std::endl;
                break;
            }
            default: {
                break;
            }
        }
    } while (menu!=5);
    std::system("pause");
    return 0;




    /* // FOR TESTING
    // variables
    const std::string key = "0110100101110111";
    std::string input;

    std::vector<int> encrypted;
    std::string enter_encrypted;

    //===[ CODE ]===
    //  get user input
    std::cout << "TXT to ENC: ";
    std::getline(std::cin, input);
    std::cin.ignore();

    //std::cout << std::endl;
    // encrpyt this message;

    encrypted = encrypt(&input, &key);
    std::cout << "Encrypted: ";
    for (int i : encrypted) {
        std::cout << int_to_hex(i) << " ";
    }

    //enter encrypted;
    std::cout << std::endl;
    std::cout << "Enter Encrypted: ";
    getline(std::cin, enter_encrypted);
    std::cin.ignore();

    std::vector<int> enter_encrypted_IV = hexStringToIntVector(enter_encrypted);

    // decrypt
    decrypt(&enter_encrypted_IV, &key);
    std::cout << "Decrypted: ";
    // convert hex to char
    for (int i: enter_encrypted_IV) {
        std::cout << (char)i;
    }
    std::cout << std::endl;
    std::system("pause");
    return 0;
     */

}