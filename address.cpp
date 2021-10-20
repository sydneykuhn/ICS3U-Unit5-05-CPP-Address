// Copyright (c) 2020 Sydney Kuhn All rights reserved
//
// Created by: Sydney Kuhn
// Created on: Oct 2020
// This program formats the users mailing address

#include <iostream>
#include <string>
#include <algorithm>

std::string formatAddress(
    std::string fullName,
    std::string houseNumber,
    std::string streetName,
    std::string cityName,
    std::string provinceName,
    std::string postalCode,
    std::string apartmentNumber = "") {

    // format address
    std::string address;

    // process
    if (apartmentNumber == "") {
        std::string line1 = fullName + "\n";
        std::string line2 = houseNumber + " " + streetName + "\n";
        std::string line3 = cityName + " " + provinceName + "  " + postalCode;
        address = line1 + line2 + line3;

    } else {
        std::string line1 = fullName + "\n";
        std::string line2 = apartmentNumber + " - " + houseNumber  + " " +
        streetName + "\n";
        std::string line3 = cityName + " " + provinceName + "  " + postalCode;
        address = line1 + line2 + line3;
    }
    // https://stackoverflow.com/questions/735204/convert-a-string-in-c-to-upper-case
    std::transform(address.begin(), address.end(), address.begin(), ::toupper);

    // output
    return address;
}

int main() {
    // this function gets the user input

    std::string fullNameFromUser;
    std::string apartmentAnswerFromUser;
    std::string apartmentNumberFromUser;
    std::string houseNumberFromUser;
    std::string streetNameFromUser;
    std::string cityNameFromUser;
    std::string provinceNameFromUser;
    std::string postalCodeFromUser;
    std::string addressFormatted;
    int apartmentNumberAsInt;
    int houseNumberAsInt;
    std::string formattedAddress;

    // input
    std::cout << "Enter your full name : ";
    getline(std::cin, fullNameFromUser);
    std::cout << "Do you live in an apartment? (y/n) : ";
    getline(std::cin, apartmentAnswerFromUser);
        if ((apartmentAnswerFromUser == "y")
        || (apartmentAnswerFromUser == "yes")) {
            std::cout << "Enter your apartment number : ";
            getline(std::cin, apartmentNumberFromUser);
        } else {
            apartmentNumberFromUser = "";
        }
    std::cout << "Enter your house number : ";
    getline(std::cin, houseNumberFromUser);
    std::cout << "Enter your street name and type (Main St, Country Dr... : ";
    getline(std::cin, streetNameFromUser);
    std::cout << "Enter your city : ";
    getline(std::cin, cityNameFromUser);
    std::cout << "Enter your province (as an abbreviation, ex. ON, SK...) : ";
    getline(std::cin, provinceNameFromUser);
    std::cout << "Enter your postal code (A1B 2C3) : ";
    getline(std::cin, postalCodeFromUser);

    try {
        if ((apartmentAnswerFromUser == "y")
        || (apartmentAnswerFromUser == "yes")) {
            apartmentNumberAsInt = std::stoi(apartmentNumberFromUser);
            houseNumberAsInt = std::stoi(houseNumberFromUser);
            formattedAddress = formatAddress(
                fullNameFromUser,
                houseNumberFromUser,
                streetNameFromUser,
                cityNameFromUser,
                provinceNameFromUser,
                postalCodeFromUser,
                apartmentNumberFromUser);
        } else {
            houseNumberAsInt = std::stoi(houseNumberFromUser);
            formattedAddress = formatAddress(
                fullNameFromUser,
                houseNumberFromUser,
                streetNameFromUser,
                cityNameFromUser,
                provinceNameFromUser,
                postalCodeFromUser);
        }

        std::cout << "\n" << formattedAddress << std::endl;
    } catch (std::invalid_argument) {
        std::cout << "\nInvalid input entered, please try again." << std::endl;
    }
    std::cout << "\nDone." << std::endl;
}
