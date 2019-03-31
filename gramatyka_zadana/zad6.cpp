#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> signs;



bool isS(const string &expression, size_t &idx);

bool isW(const string &expression, size_t &idx);

bool isZ(const string &expression, size_t &idx);

bool isWp(const string &expression, size_t &idx);

bool isP(const string &expression, size_t &idx);

bool isR(const string &expression, size_t &idx);

bool isRp(const string &expression, size_t &idx);

bool isL(const string &expression, size_t &idx);

bool isLp(const string &expression, size_t &idx);

bool isC(const string &expression, size_t &idx);

bool isO(const string &expression, size_t &idx);

bool analyze(const string &expression) {
    size_t idx = 0;
    return isS(expression, idx);
}

int main() {
    signs.push_back('+');
    signs.push_back('-');
    signs.push_back('/');
    signs.push_back('*');
    signs.push_back('^');

    cout << "expression: " << endl;
    string expression;
    cin >> expression;

    if (analyze(expression))
        cout << "accepted" << endl;
    else
        cout << "rejected" << endl;

    return 0;
}

bool proceed(const string &expression, size_t &idx) {
    idx++;
    return expression.size() - 1 > idx;
}

// S
bool isS(const string &expression, size_t &idx) {
    if (isW(expression, idx))
        if (expression[idx] == ';' && proceed(expression, idx))
            return isZ(expression, idx);

    return false;
}

// Z 
bool isZ(const string &expression, size_t &idx) {
    if (isW(expression, idx)) {
        if (expression[idx] == ';' && !proceed(expression, idx))
            return isZ(expression, idx);
        return false;
    }

    return true;
}

// W 
bool isW(const string &expression, size_t &idx) {
    if (isP(expression, idx)) {
        return isWp(expression, idx);
    }
    return false;
}

// P 
bool isP(const string &expression, size_t &idx) {
    if (expression[idx] == '(' && proceed(expression, idx)) {
        if (isW(expression, idx)) {
            return expression[idx] == ')' && proceed(expression, idx);
        }
    }

    return isR(expression, idx);

}

// R 
bool isR(const string &expression, size_t &idx) {
    if (isL(expression, idx)) {
        return isRp(expression, idx);
    }
    return false;
}

// R'
bool isRp(const string &expression, size_t &idx) {
    if (expression[idx] == '.') {
        return proceed(expression, idx) && isL(expression, idx);
    }

    return true;
}

// L 
bool isL(const string &expression, size_t &idx) {
    return isC(expression, idx) && isLp(expression, idx);
}

// C
bool isC(const string &expression, size_t &idx) {
    return isdigit(expression[idx]) && proceed(expression, idx);
}

// L'
bool isLp(const string &expression, size_t &idx) {
    isL(expression, idx);
    return true;
}

// W'
bool isWp(const string &expression, size_t &idx) {
    if (isO(expression, idx)) {
        return isW(expression, idx);
    }

    return true;
}

// O
bool isO(const string &expression, size_t &idx) {
    return (find(signs.begin(), signs.end(), expression[idx]) != signs.end()) && proceed(expression, idx);
}
