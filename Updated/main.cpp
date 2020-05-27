#include <iostream>
#include <string>
#include <vector>

using namespace std;

int RomanToNumber(string userInput) {
    int arabicNumber = 0;
    vector<int> letterSizes;
    int subNum = 0;
    int addNum = 0;

    for (int i = 0; i < userInput.size(); i++) {
        if ((userInput.at(i) == 'I') || (userInput.at(i) == 'i')) {letterSizes.push_back(1);}
        if ((userInput.at(i) == 'V') || (userInput.at(i) == 'v')) {letterSizes.push_back(2);}
        if ((userInput.at(i) == 'X') || (userInput.at(i) == 'x')) {letterSizes.push_back(3);}
        if ((userInput.at(i) == 'L') || (userInput.at(i) == 'l')) {letterSizes.push_back(4);}
        if ((userInput.at(i) == 'C') || (userInput.at(i) == 'c')) {letterSizes.push_back(5);}
        if ((userInput.at(i) == 'D') || (userInput.at(i) == 'd')) {letterSizes.push_back(6);}
        if ((userInput.at(i) == 'M') || (userInput.at(i) == 'm')) {letterSizes.push_back(7);}
    }

    for (int i = 0; i < userInput.size(); i++) {
        if ((i != userInput.size() - 1) && (letterSizes.at(i) < letterSizes.at(i + 1))) {
            if ((userInput.at(i) == 'I') || (userInput.at(i) == 'i')) {subNum = 1;}
            if ((userInput.at(i) == 'V') || (userInput.at(i) == 'v')) {subNum = 5;}
            if ((userInput.at(i) == 'X') || (userInput.at(i) == 'x')) {subNum = 10;}
            if ((userInput.at(i) == 'L') || (userInput.at(i) == 'l')) {subNum = 50;}
            if ((userInput.at(i) == 'C') || (userInput.at(i) == 'c')) {subNum = 100;}
            if ((userInput.at(i) == 'D') || (userInput.at(i) == 'd')) {subNum = 500;}
            if ((userInput.at(i) == 'M') || (userInput.at(i) == 'm')) {subNum = 1000;}
            if ((userInput.at(i + 1) == 'I') || (userInput.at(i + 1) == 'i')) {addNum = 1;}
            if ((userInput.at(i + 1) == 'V') || (userInput.at(i + 1) == 'v')) {addNum = 5;}
            if ((userInput.at(i + 1) == 'X') || (userInput.at(i + 1) == 'x')) {addNum = 10;}
            if ((userInput.at(i + 1) == 'L') || (userInput.at(i + 1) == 'l')) {addNum = 50;}
            if ((userInput.at(i + 1) == 'C') || (userInput.at(i + 1) == 'c')) {addNum = 100;}
            if ((userInput.at(i + 1) == 'D') || (userInput.at(i + 1) == 'd')) {addNum = 500;}
            if ((userInput.at(i + 1) == 'M') || (userInput.at(i + 1) == 'm')) {addNum = 1000;}
            arabicNumber = arabicNumber + addNum - subNum;
            i++;
        }
        else {
            if ((userInput.at(i) == 'I') || (userInput.at(i) == 'i')) {arabicNumber = arabicNumber + 1;}
            if ((userInput.at(i) == 'V') || (userInput.at(i) == 'v')) {arabicNumber = arabicNumber + 5;}
            if ((userInput.at(i) == 'X') || (userInput.at(i) == 'x')) {arabicNumber = arabicNumber + 10;}
            if ((userInput.at(i) == 'L') || (userInput.at(i) == 'l')) {arabicNumber = arabicNumber + 50;}
            if ((userInput.at(i) == 'C') || (userInput.at(i) == 'c')) {arabicNumber = arabicNumber + 100;}
            if ((userInput.at(i) == 'D') || (userInput.at(i) == 'd')) {arabicNumber = arabicNumber + 500;}
            if ((userInput.at(i) == 'M') || (userInput.at(i) == 'm')) {arabicNumber = arabicNumber + 1000;}
        }
    }

    return arabicNumber;
}

string NumberToRoman(string userInput) {
    int userNum = stoi(userInput);
    string RomanReturn;

    if (userNum >= 1000) {      // x > 999
        for (int i = 0; i < (userNum / 1000); i++) {
            RomanReturn.push_back('M');
        }
        userNum = userNum - (1000 * (userNum / 1000));
    }
    if (userNum >= 900) {       // 1000 > x > 899
        RomanReturn.push_back('C');
        RomanReturn.push_back('M');
        userNum = userNum - 900;
    }
    if (userNum >= 500) {       // 900 > x > 499
        RomanReturn.push_back('D');
        userNum = userNum - 500;
    }
    if (userNum >= 400) {       // 500 > x > 399
        RomanReturn.push_back('C');
        RomanReturn.push_back('D');
        userNum = userNum - 400;
    }
    if (userNum >= 100) {       // 400 > x > 99
        for (int i = 0; i < (userNum / 100); i++) {
            RomanReturn.push_back('C');
        }
        userNum = userNum - (100 * (userNum / 100));
    }
    if (userNum >= 90) {        // 100 > x > 89
        RomanReturn.push_back('X');
        RomanReturn.push_back('C');
        userNum = userNum - 90;
    }
    if (userNum >= 50) {        // 90 > x > 49
        RomanReturn.push_back('L');
        userNum = userNum - 50;
    }
    if (userNum >= 40) {        // 50 > x > 39
        if (RomanReturn.empty() || (RomanReturn.at(RomanReturn.size() - 1) != 'L')) {
            RomanReturn.push_back('X');
            RomanReturn.push_back('L');
        }
        else {
            RomanReturn.insert(RomanReturn.size() - 1, "X");
        }
        userNum = userNum - 40;
    }
    if (userNum >= 10) {        // 40 > x > 9
        for (int i = 0; i < (userNum / 10); i++) {
            RomanReturn.push_back('X');
        }
        userNum = userNum - (10 * (userNum / 10));
    }
    if (userNum >= 9) {         // 10 > x > 8  |  Basically if it is 9
        RomanReturn.push_back('I');
        RomanReturn.push_back('X');
        userNum = userNum - 9;
    }
    if (userNum >= 5) {         // 9 > x > 4
        RomanReturn.push_back('V');
        userNum = userNum - 5;
    }
    if (userNum >= 4) {         // 5 > x > 3  |  Basically if it is 4
        if (RomanReturn.empty() || (RomanReturn.at(RomanReturn.size() - 1) != 'V')) {
            RomanReturn.push_back('I');
            RomanReturn.push_back('V');
        }
        else {
            RomanReturn.insert(RomanReturn.size() - 1, "I");
        }
        userNum = userNum - 4;
    }
    if (userNum >= 1) {         // 4 > x > 0
        for (int i = 0; i < userNum; i++) {
            RomanReturn.push_back('I');
        }
        userNum = 0;
    }

    return RomanReturn;
}

int main() {
    string userInput;
    string inputType;

    cout << "Welcome to the Roman Numeral Converter!" << endl;
    cout << "Please enter a natural number (no decimal, negative, or zero) as either a Roman Numeral or an Arabic Number." << endl;
    cout << "Enter \"stop\" to exit." << endl;

    while (userInput != "stop") {
        cin >> userInput;

        // Roman to Arabic
        if (isalpha(userInput.at(0))) {
            cout << userInput << " as an Arabic number is " << RomanToNumber(userInput) << "." << endl;
        }

        // Arabic to Roman
        else if (isdigit(userInput.at(0))) {
            cout << userInput << " in Roman Numerals is " << NumberToRoman(userInput) << "." << endl;
        }
    }

    return 0;
}