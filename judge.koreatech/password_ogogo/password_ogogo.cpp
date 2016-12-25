#include <cstdio>
bool hasPrefix(int i);
bool hasSuffix(int i);
void transformPassword(int start, int end);
int size;
char password[101];
int main() {
    scanf("%d", &size);
    scanf("%s", password);

    for (int i = 0; i < size - 2; i++) {
        if (hasPrefix(i)) {
            int start = i;
            int end = i + 2;
            while ((end + 2) < size && hasSuffix(end + 1)) {
                end += 2;
            }
            transformPassword(start, end);
        }
    }

    for (int i = 0; i < size; i++) {
        if (password[i] != '#') printf("%c", password[i]);
    }
    printf("\n");

    return 0;
}
bool hasPrefix(int i) {
    if (password[i] == 'o' &&
        password[i+1] == 'g' &&
        password[i+2] == 'o') {
        return true;
    }
    return false;
}
bool hasSuffix(int i) {
    if (password[i] == 'g' && password[i+1] == 'o')
        return true;
    return false;
}
void transformPassword(int start, int end) {
    password[start] = password[start+1] = password[start+2] = '*';
    for (int i = start+3; i <= end; i++) {
        password[i] = '#';
    }
}
