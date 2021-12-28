#include <iostream>
#include <string>
using namespace std;


int main() {
    string str;
    int count;
    while(1) {
        getline(cin, str);
        if(str[0] == '#') return 0;
        count = 0;
        for(int i=0; i<str.length(); i++)
            if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
               str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') count++;
        printf("%d\n", count);
    }
}
