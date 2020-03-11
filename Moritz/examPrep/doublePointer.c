int main () {
    int num;
    int* ptr;
    int** dptr;

    ptr = &num;
    dptr = &ptr;

    num = 10;
    printf("%d\n", num);
    *ptr = 20;
    printf("%d\n", num);
    **dptr = 30;
    printf("%d\n", num);
    return 0;
}