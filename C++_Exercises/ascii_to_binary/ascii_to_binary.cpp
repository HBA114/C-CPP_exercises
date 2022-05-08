#include <iostream> // importing libraries
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> decimal_to_binary(int number);  // forward declaration of method.

vector<vector<int>> char_to_ascii(string text);

void printVector(vector<int> x);

int main(){
    string text;
    int decision = 1;
    string temp = "";
    int count = 0;
    while (decision) {
        cout << "Enter a text for convert binary..." << endl;
        if (count != 0) getchar();
        getline(cin, text);
        char_to_ascii(text);
        do {
            cout << endl << "For re-enter a text enter 1, for exit enter 0" << endl;
            cin >> temp;
            if (int(temp[0]) == 48) decision = 0;
            if (int(temp[0]) == 49) decision = 1;
        }
        while (temp.size() != 1 || (int(temp[0]) != 48 && int(temp[0]) != 49));// ( decision != 0 && decision != 1);
        count ++;
    }
}

void printVector(vector<int> x) {
    for (int i = x.size() - 1; i >= 0; i--) {
        cout << x[i];
    }
    cout << " ";
}

vector<int> decimal_to_binary(int number) {
    vector<int> binary;
    float sum = number % 2;
    int temp = number;
    binary.push_back(number % 2);
    for (int i = 0; i < 7; i++) {
        binary.push_back(0);
    }
    number -= number % 2;

    if (log2f(number) == log2(number)) {
        binary[log2(number)] = 1;
        return binary;
    }

    float value = int(log2f(number)) + 1;
    value = pow(2,value);

    while (log2f(number) != log2(number)) {
        number -= 2;
    }

    while (sum < value && number > 0) {
        if (log2f(number) == log2(number) && (sum + pow(2,log2f(number))) <= temp) {
            sum += pow(2,log2f(number));
            binary[log2(number)] = 1;
        }
        number /= 2;
    }
    return binary;
}

vector<vector<int>> char_to_ascii(string text) {
    vector<vector<int>> ascii;
    cout << "Text to be converted : " << text << endl;
    for (int i = 0; i < text.size(); i++) {
        ascii.push_back(decimal_to_binary(int(text[i])));
    }
    for (int i = 0; i < ascii.size(); i++) {
        printVector(ascii[i]);
    }
    return ascii;
}