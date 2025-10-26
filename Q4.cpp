#include <iostream>
using namespace std;

void concatenate(char s1[], char s2[], char result[]) {
    int i = 0, j = 0;
    while (s1[i] != '\0') {
        result[i] = s1[i];
        i++;
    }
    while (s2[j] != '\0') {
        result[i] = s2[j];
        i++;
        j++;
    }
    result[i] = '\0';
}

void reverseString(char s[]) {
    int len = 0;
    while (s[len] != '\0')
        len++;

    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}

void deleteVowels(char s[], char result[]) {
    int i = 0, j = 0;
    while (s[i] != '\0') {
        char c = s[i];
        if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
              c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')) {
            result[j++] = c;
        }
        i++;
    }
    result[j] = '\0';
}

void sortStrings(char arr[][20], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int k = 0;
            while (arr[j][k] == arr[j + 1][k] && arr[j][k] != '\0')
                k++;
            if (arr[j][k] > arr[j + 1][k]) {
                char temp[20];
                int t = 0;
                while (arr[j][t] != '\0') {
                    temp[t] = arr[j][t];
                    t++;
                }
                temp[t] = '\0';
                int p = 0;
                while (arr[j + 1][p] != '\0') {
                    arr[j][p] = arr[j + 1][p];
                    p++;
                }
                arr[j][p] = '\0';
                int q = 0;
                while (temp[q] != '\0') {
                    arr[j + 1][q] = temp[q];
                    q++;
                }
                arr[j + 1][q] = '\0';
            }
        }
    }
}

char toLowerCase(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

int main() {
    char s1[20] = "Hello";
    char s2[20] = "World";
    char concatenated[40];
    concatenate(s1, s2, concatenated);
    cout << "(a) Concatenated string: " << concatenated << endl;

    char s3[20] = "OpenAI";
    reverseString(s3);
    cout << "(b) Reversed string: " << s3 << endl;

    char s4[30] = "beautifulday";
    char noVowels[30];
    deleteVowels(s4, noVowels);
    cout << "(c) Without vowels: " << noVowels << endl;

    char arr[3][20] = {"banana", "apple", "cherry"};
    sortStrings(arr, 3);
    cout << "(d) Sorted strings:\n";
    for (int i = 0; i < 3; i++)
        cout << "   " << arr[i] << endl;

    char ch = 'M';
    cout << "(e) " << ch << " → " << toLowerCase(ch) << endl;

    return 0;
}
