#include <iostream>
#include <cmath>
using namespace std;
double power(double a, int n) {
    if (n == 0) {
        return 1;
    }
    else if (n % 2 == 0) {
        double temp = power(a, n/2);
        return temp * temp;
    }
    else {
        return a * power(a, n-1);
    }
}

double power_binary_expansion(double a, int n) {
    double result = 1.0;
    int k = log2(n);
    for (int i = k; i >= 0; i--) {
        result *= power(a, pow(2, i) * ((n >> i) & 1));
    }
    return result;
}

int main() {
    double a = 5.0;
    int n = 3;
    cout << a <<"^"<< n<< "=" << power_binary_expansion(a, n) <<endl;
    return 0;
}

