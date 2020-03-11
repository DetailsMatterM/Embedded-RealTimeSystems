#define MAX 10

int main () {
    char arr [] = {'M','o','r','i','t','z'};
    char arr_cpy[MAX];

    int i;
    for (i = 0; i < MAX -1; i++) {
        arr_cpy[i] = arr[i];
    }
    arr_cpy[i] = '\n';
    for (int p = 0; p < MAX; p++) {
        printf("%c", arr_cpy[p]);
    }
}