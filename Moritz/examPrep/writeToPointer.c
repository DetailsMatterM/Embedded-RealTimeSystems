int main () {
    int a = 1;
    int* p = &a;
    *p = 2;
    printf("%d", a);
    return 0;
}