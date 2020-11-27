#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void printPole();
bool checkPole();
enum { SIZE = 3 };
char pole[SIZE][SIZE];
int start = 0;

int main() {

    int x;
    int y;

    printPole();
    start++;
    for (int k = 0; k < SIZE*SIZE;) {
        for(;;) {
            printf("Write coords X:\n");
            scanf("%i", &x);
            scanf("%i", &y);
            if (pole[x][y] == '_') {
                pole[x][y] = 'X';
                if (k > SIZE && checkPole()) {
                    return 0;
                }
                k++;
                break;
            } else {
                printf("Fail :)\n");
            }
        }
        printPole();
        for(;;) {
            printf("Write coords O:\n");
            scanf("%i", &x);
            scanf("%i", &y);
            if (pole[x][y] == '_') {
                pole[x][y] = 'O';
                if (k > SIZE && checkPole()) {
                    return 0;
                }
                k++;
                break;
            } else {
                printf("Fail :)\n");
            }

        }
        printPole();


    }
    printf("Draw");
    return 0;
}

void printPole() {
    for (int i = 0; i < sizeof(pole) / SIZE; i++) {
        for (int j = 0; j < sizeof(pole) / SIZE; j++) {
            if (start == 0) {
                pole[i][j] = '_';
            }
            printf("%c ", pole[i][j]);
        }
        printf("\n");
    }
}
bool checkPole() {
    printf("Checking pole...\n");
    char suspect = 'X';
    for (int k = 0; k < 2; k++) {
        if (k==0){
            suspect = 'X';
        }else{
            suspect = 'O';
        }
        int chars_in_a_row = 0;
        int chars_in_a_column = 0;
        int chars_in_a_diagonal1 = 0;
        int chars_in_a_diagonal2 = 0;

        for (int i = 0; i < sizeof(pole) / SIZE; i++) {
            for (int j = 0; j < sizeof(pole) / SIZE; j++) {
                if (pole[i][j] == suspect) printf("%c found at: %i, %i\n", suspect, i, j);
                if (pole[i][j] == suspect) {
                    chars_in_a_row++;
                }
                if (pole[j][i] == suspect) {
                    chars_in_a_column++;

                }
                if (pole[j][j] == suspect) {
                    chars_in_a_diagonal1++;
                }
                if (pole[j][SIZE-1-j] == suspect) {
                    chars_in_a_diagonal2++;
                }
            }
            if (chars_in_a_row == SIZE || chars_in_a_column == SIZE || chars_in_a_diagonal1 == SIZE || chars_in_a_diagonal2 == SIZE) {
                printf("%c - won!", suspect);
                return true;
            }
            chars_in_a_row = 0;
            chars_in_a_column = 0;
            chars_in_a_diagonal1 = 0;
        }
    }
    return false;

}