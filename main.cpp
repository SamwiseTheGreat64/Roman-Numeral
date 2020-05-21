#include <iostream>
#include <string>

using namespace std;

int RomanToNumber(string userInput) {
    for (int i = userInput.size(); i >= 0; i--) {

    }


    return 0;
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