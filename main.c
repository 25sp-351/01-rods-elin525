#include <stdio.h>
#include <stdlib.h>

#define MAX_N 20

typedef struct {
    int length;
    int value;
} Piece;

void rodCut(int rod_length, Piece pieces[], int n, int index, int current_value,
            int *max_value, int cuts[]) {
    if (rod_length == 0 || index == n) {
        // save max value if best solution found
        if (current_value > *max_value) {
            *max_value = current_value;
            // print final result
            for (int i = 0; i < n; i++) {
                if (cuts[i] > 0) {
                    printf("%d @ %d = %d\n", cuts[i], pieces[i].length,
                           cuts[i] * pieces[i].value);
                }
            }
            printf("Remainder: %d\n", rod_length);
            printf("Value: %d\n", *max_value);
        }
        return;
    }

    // if current piece can be cut, choose to cut it
    if (rod_length >= pieces[index].length) {
        cuts[index]++;
        rodCut(rod_length - pieces[index].length, pieces, n, index,
               current_value + pieces[index].value, max_value, cuts);
        cuts[index]--;  // withdraw the selection
    }

    
    rodCut(rod_length, pieces, n, index + 1, current_value, max_value, cuts);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <rod_length>\n", argv[0]);
        return 1;
    }

    int rod_length = atoi(argv[1]);
    Piece pieces[MAX_N];
    int count = 0;

    // read pieces from stdin
    while (scanf("%d, %d", &pieces[count].length, &pieces[count].value) == 2)
        count++;

    int max_value   = 0;
    int cuts[MAX_N] = {0};

    rodCut(rod_length, pieces, count, 0, 0, &max_value, cuts);

    return 0;
}
