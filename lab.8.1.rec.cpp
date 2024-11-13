#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;


int FindThirdDot(char* str, int i, int dotCount) {
 
    if (str[i] == '\0') return -1; //якщо дійшло кінця, то буде -1(менше троьх крапок)
    if (str[i] == '.') {
        dotCount++;
        if (dotCount == 3) return i; //якщо = 3, то повертаємо і 
    }
  
    return FindThirdDot(str, i + 1, dotCount); //або йдем до іншого числа 
}


char* ReplaceEveryFourth(char* dest, const char* str, int i) {
   
    if (str[i] == '\0') {
        dest[i] = '\0';
        return dest;
    }
    
    if ((i + 1) % 4 == 0) { //кожен четвертий рядок це крапка
        dest[i] = '.';
    }
    else {
        dest[i] = str[i]; // якщо ні, то копіюємо ці символи 
    }
   
    return ReplaceEveryFourth(dest, str, i + 1); //наступна функція 
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    //1
    int thirdDotIndex = FindThirdDot(str, 0, 0);
    if (thirdDotIndex != -1) {
        cout << "Index of the third dot: " << thirdDotIndex << endl;
    }
    else {
        cout << "There are less than three dots in the string." << endl; //якщо третю крапку знайдено то виводимо її, якщо ні то пише, що їх менше трьох
    }

    //2
    char dest[101];        
    ReplaceEveryFourth(dest, str, 0);
    cout << "Modified string: " << dest << endl; //виводимо рядок з символами 

    return 0;
}
