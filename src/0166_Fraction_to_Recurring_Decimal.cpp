#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0)
        return "0";

    string output;
    long long int dividend, divisor, remainder;
    if (numerator < 0 && denominator < 0) {
        dividend = 0ll - static_cast<long long int>(numerator);
        divisor = 0ll - static_cast<long long int>(denominator);
    }
    else if (numerator < 0) {
        dividend = 0ll - static_cast<long long int>(numerator);
        divisor = static_cast<long long int>(denominator);
        output.push_back('-');
    }
    else if (denominator < 0) {
        dividend = static_cast<long long int>(numerator);
        divisor = 0ll - static_cast<long long int>(denominator);
        output.push_back('-');
    }
    else {
        dividend = static_cast<long long int>(numerator);
        divisor = static_cast<long long int>(denominator);
    }
    output.append(to_string(dividend / divisor));
    remainder = dividend % divisor;
    if (remainder == 0)
        return output;

    output.push_back('.');
    string fractional;
    unordered_map<long long int, size_t> dividend2decimalPlace;
    while (remainder > 0) {
        dividend = remainder * 10;
        remainder = dividend % divisor;

        if (dividend2decimalPlace.find(dividend) == dividend2decimalPlace.end()) {
            dividend2decimalPlace.insert({dividend, fractional.size()});
            fractional.push_back('0' + (dividend / divisor));
        }
        else {
            size_t idx = dividend2decimalPlace[dividend];
            output = output + fractional.substr(0, idx) + "(" + fractional.substr(idx) + ")";
            return output;
        }
    }

    return output + fractional;
}

int main() {
    int numerator, denominator;
    cin >> numerator >> denominator;
    cout << fractionToDecimal(numerator, denominator) << endl;

    return 0;
}