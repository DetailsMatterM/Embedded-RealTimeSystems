
int* max(int *tab, int number);

int main() {
    int number = 5;
    int arr [] = {1,5,7,4,2};
    int * tab = &arr[0];
    max(tab, number);

    return 0;
}

int* max(int *tab, int number){
    int * returnValue;
    *returnValue = *tab;
    for(int i = 0; i < number; i++) {
        int p = *tab;
        tab++;
        int q = *tab;
        if(q > p) {
            returnValue = q;
        }
    }
    printf("%d", *returnValue);
    return returnValue;
}