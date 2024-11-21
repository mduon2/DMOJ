#include <iostream>
#include <cmath>

using namespace std;

int conv_to_base10 (int n, int b) {
    int converted = 0, dig, dig_exp = 0;
    while (n > 0) {
        dig = n % 10;
        converted += dig * pow(b, dig_exp);
        n /= 10;
        dig_exp++;
    }

    return converted;
}

int main() {

int E, N;

cin>>E>>N;

int bases[N];

for (int i = 0; i < N; i++) {
    cin>>bases[i];
}

for (int i = N - 2; i >= 0; i--) {
    bases[i] = conv_to_base10(bases[i], bases[i+1]);
}

cout<<conv_to_base10(E, bases[0])<<endl;
  
  return 0;
}
