#include <iostream>
#include <bit>
#include <bitset>
#include <cstdint>
#include <chrono>
#include <future>
using namespace std;

int findDigits(int i) {
    int digits = 0;
    while (i > 0) {
        i = i / 10;
        digits++;
    }
    return digits;
}

int rotateNum(int i, int d) {
    int g = d - 1;
    int x = i / (int)(pow(10, g));
    int f = i % (int)(pow(10, g));
    i = f * 10 + x;
    return (i);
}

bool isPrimeCheck(int i) {
    int q;
    for (q = 2; q <= i / 2; q++) {
        if (i % q == 0) {
            return false;
            break;
        }
    }
    return true;
}

bool isCircularPrime(int i) {
    //cout << "Is CP called on " << i << "\n"; 
    if (i < 10) {
        cout << i << " is circular prime" << endl;
    }
    if (i >= 10) {
        int digits = findDigits(i);
        int g = digits - 1;
        //cout << "Detected digits: " << digits << "\n";
        bool q = true;
        int x = 0;
        int w = i;
        int z = i / (int)(pow(10, g));
        if (z == 1 || z == 3 || z == 7 || z == 9) {
            while (q && x <= digits) {
                w = rotateNum(w, digits);
                q = isPrimeCheck(w);
                x++;
            }
            if (q) {
                cout << i << " is circular prime" << endl;
            }
        }
    }
    return true;
}

int sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }   
        }
    }
    for (int p = 2; p <= n; p++) {
        if (is_prime[p]) {
            int f = p / (int)(pow(10, findDigits(p) - 1));
            if (p < 10 || f == 1 || f == 3 || f == 7 || f == 9) {
                future <bool> asyncFunction = async(&isCircularPrime, p);
            }
        }
            
    }
    return 0;      
}


int main() {
    int i, n;
    cout << "Enter a maximum number to check: ";
    cin >> n;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    sieve(n);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl;
    cout << "Enter 0 to exit";
    cin >> n;
    return 0;
}