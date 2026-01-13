#include <iostream>
using namespace std;

string toHex(int num) {
    if (num == 0)
        return "0";

    string output;
    bool flag_leading0 = true;
    for (int shift = 28; shift >= 0; shift -= 4) {
        int hex_digit = (num >> shift) & 0b1111;
        if (hex_digit == 0 && flag_leading0)
            continue;

        flag_leading0 = false;
        if (hex_digit < 10)
            output += ('0' + hex_digit);
        else
            output += ('a' + (hex_digit - 10));
    }

    return output;
}

int main() {
    int num;
    cin >> num;
    cout << toHex(num) << endl;

    return 0;
}