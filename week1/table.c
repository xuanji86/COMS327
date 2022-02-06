#include<stdio.h>

#define DIM 12

void fill_times_table(int table[DIM][DIM]){
    int i,j;
        // Fill in the table.
    for (j = 0; j < DIM; j++) { // row {better performance with this as outside loop}
        for (i = 0; i < DIM; i++) { // column
            table[j][i] = (j + 1) * (i + 1);
        }
    } 
}
unsigned fib(unsigned i){
    if(i<2){
        return i;
    }
    return fib(i-1)+fib(i-2);
}
int main(int argc, char *argv[]) {
    int table[DIM][DIM];
    int i, j;

    fill_times_table(table);

    // Print the table.
    for (j = 0; j < DIM; j++) { 
        for (i = 0; i < DIM; i++) { 
            printf("%3d ", table[j][i]); // 3 is the field width
        }
        printf("\n");
    } 
    return 0;
}