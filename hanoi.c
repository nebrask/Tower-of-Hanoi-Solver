#include <stdio.h>
#include <unistd.h>


void display_pegs(int peg[3][9]){
        int i, j, k;
        for (i = 8; i >= 0; i--){
                for (j = 0; j != 3; j++){
                        for (k = 0; k != 10 - peg[j][i]; k++){
                                printf(" ");
                        }
                        for (k = 0; k != peg[j][i]; k++){
                                printf("+");
                        }
                        printf("|");
                        for (k = 0; k != peg[j][i]; k++){
                                printf("+");
                        }

                        for (k = 0; k != 9 - peg[j][i]; k++){
                                printf(" ");
                        }
                        printf("      ");
                }
                printf("\n");
        }
        printf("XXXXXXXXXXXXXXXXXXXXX     XXXXXXXXXXXXXXXXXXXXX     XXXXXXXXXXXXXXXXXXXXX\n");
}

void sort(int peg1, int peg2, int peg3, int peg[3][9], int n){
        int i, j;
        if (n == 1){
                printf("\n");
                for (i = 0; peg[peg1][i] != 0; i++){
                        if (i == 8){
                                i++;
                                break;
                        }
                }
                for (j = 0; peg[peg3][j] != 0; j++);
                int pres = peg[peg1][i-1];
                peg[peg1][i-1] = 0;
                peg[peg3][j] = pres;
                display_pegs(peg);
                sleep(1);
        }
        else{
                sort(peg1, peg3, peg2, peg, n-1);
                sort(peg1, peg2, peg3, peg, 1);
                sort(peg2, peg1, peg3, peg, n-1);
        }
}

int main(int argc, char* argv[]){
        int i;
        if (argc != 2){
                printf("Sorry, you gave incorrect number of command line arguments\n");
                return 0;
        }
        else{
                for (i = 0; argv[1][i] != '\0'; i++){
                        if (i > 0){
                                printf("Sorry, you gave incorrect command line argument length\n");
                                return 0;
                        }
                        if (!(argv[1][i] >= '1' && argv[1][i] <= '9')){
                                printf("Sorry, you didn't give a digit between 1-9\n");
                                return 0;
                        }
                }
        }

        int peg[3][9] = {{0}};
        int num_of_disks = argv[1][0] - '0';
        printf("Number of disks = %d\n", num_of_disks);
     
        for (i = 0; i != argv[1][0] - '0'; i++){
                peg[0][i] = argv[1][0] - '0' - i;
        }
     
        display_pegs(peg);
        sleep(1);
        sort(0, 2, 1, peg, num_of_disks);
        printf("\n");
        printf("done\n");

        return 0;
}