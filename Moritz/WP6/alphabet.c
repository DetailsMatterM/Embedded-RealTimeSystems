int main() {
    char letter = 'a';
    printf("main is executing\n");
    for (int i = 0; i < 26; i++) {
      printf("%c\n", letter);
      letter++;
    }
}