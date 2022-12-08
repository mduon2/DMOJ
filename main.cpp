#include <iostream>
#include <cmath>

using namespace std;

bool isPrime (long long int n) {
    bool isprime = true;
    for (long long int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            isprime = false;
            break;
        }
    }
    return isprime;
}

int main() {

long long int num, rem, answers, ans2[2], ans3[3];
bool isFound = false;

for (long long int i = 0; i < 5; i++) {
    cin>>num;
    if (isPrime(num) == true) {
        cout<<num<<" = "<<num<<endl;
    }
    else {
        for (long long int j = 3; j <= num; j += 2) {
            if (isPrime(j) == true) {
                rem = num - j;
                if (isPrime(rem) == true) {
                    if (j <= rem) {
                        answers = 2;
                        ans2[0] = j;
                        ans2[1] = rem;
                    }
                    else {
                        break;
                    }
                }
                else {
                    isFound = false;
                    for (long long int k = 3; k <= rem; k += 2) {
                        if (isPrime(k) == true && isPrime(rem - k) == true && (rem-k) % 2 != 0) {
                            if (j <= k && k <= rem-k) {
                                answers = 3;
                                ans3[0] = j;
                                ans3[1] = k;
                                ans3[2] = rem - k;
                            }
                            else {
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    if (answers == 2) {
        cout<<num<<" = "<<ans2[0]<<" + "<<ans2[1]<<endl;
    }
    else {
        cout<<num<<" = "<<ans3[0]<<" + "<<ans3[1]<<" + "<<ans3[2]<<endl;
    }
}
  
  return 0;
}