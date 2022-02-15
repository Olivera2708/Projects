//Program je pisan u aprilu 2020. godine
//Slaganje Rubikove kocke metodom koja se koristi za slaganje Rubikove kocke na slepo

#include <stdio.h>
#include <stdlib.h>

int p = 0;

struct side{
    char matrix[3][3];
    char mbackup[3][3];
    void (*sidebackup)(struct side*); //kako bi mogli okretati kocku
    void (*set)(int i, struct side*); //upisivanje kombinacije
    void (*siderotater)(struct side*); //okretanje strane na desno
    void (*siderotatel)(struct side*); //okretanje strane na levo
};

void Set(int i, struct side *S){
    FILE *r;
    r = fopen("scrambled.txt", "r");
    int k = 0;
    int pr = 0;
    while (fgetc(r) != EOF){
        if (k == i || k == i + 1 || k == i + 2){
            fscanf(r, " %c ", &S -> matrix[pr][0]);
            fscanf(r, "%c ", &S -> matrix[pr][1]);
            fscanf(r, "%c", &S -> matrix[pr][2]);
            pr++;
        }
        k++;
    }
    fclose(r);
}

void Sidebackup(struct side *S){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j< 3; j++){
            S -> mbackup[i][j] = S -> matrix[i][j];
        }
    }
}

void Siderotater(struct side *S){
    S -> matrix[0][0] = S -> mbackup[2][0];
    S -> matrix[0][1] = S -> mbackup[1][0];
    S -> matrix[0][2] = S -> mbackup[0][0];
    S -> matrix[1][0] = S -> mbackup[2][1];
    S -> matrix[1][2] = S -> mbackup[0][1];
    S -> matrix[2][0] = S -> mbackup[2][2];
    S -> matrix[2][1] = S -> mbackup[1][2];
    S -> matrix[2][2] = S -> mbackup[0][2];
    //9 delova, ali centar ne pomera poziciju
    //pravim opet backup
    for (int i = 0; i < 3; i++){
        for (int j = 0; j< 3; j++){
            S -> mbackup[i][j] = S -> matrix[i][j];
        }
    }
}

void Siderotatel(struct side *S){
    S -> matrix[0][0] = S -> mbackup[0][2];
    S -> matrix[0][1] = S -> mbackup[1][2];
    S -> matrix[0][2] = S -> mbackup[2][2];
    S -> matrix[1][0] = S -> mbackup[0][1];
    S -> matrix[1][2] = S -> mbackup[2][1];
    S -> matrix[2][0] = S -> mbackup[0][0];
    S -> matrix[2][1] = S -> mbackup[1][0];
    S -> matrix[2][2] = S -> mbackup[2][0];
    //9 delova, ali centar ne pomera poziciju
    //pravim opet backup
    for (int i = 0; i < 3; i++){
        for (int j = 0; j< 3; j++){
            S -> mbackup[i][j] = S -> matrix[i][j];
        }
    }
}

struct RubikovaKocka{
    struct side W, G, R, Y, B, O, B_backup, R_backup, G_backup, O_backup, Y_backup, W_backup;
    void (*readfile)(struct RubikovaKocka*);
    void (*backup)(struct RubikovaKocka*);
    //slaganje
    void (*solveCorners)(struct RubikovaKocka*);
    void (*solveEdges)(struct RubikovaKocka*);
    //provera da li je slozeno
    int (*isSolved)(struct RubikovaKocka*);
    int (*cornersSolved)(struct RubikovaKocka*);
    //provera da li  je nastao parity
    void (*parity)(struct RubikovaKocka*);
    //pokreti
    void (*turn_R)(struct RubikovaKocka*);
    void (*turn_L)(struct RubikovaKocka*);
    void (*turn_F)(struct RubikovaKocka*);
    void (*turn_B)(struct RubikovaKocka*);
    void (*turn_U)(struct RubikovaKocka*);
    void (*turn_D)(struct RubikovaKocka*);
    void (*turn_Ri)(struct RubikovaKocka*);
    void (*turn_Li)(struct RubikovaKocka*);
    void (*turn_Fi)(struct RubikovaKocka*);
    void (*turn_Bi)(struct RubikovaKocka*);
    void (*turn_Ui)(struct RubikovaKocka*);
    void (*turn_Di)(struct RubikovaKocka*);
    //permutacije
    void (*y_perm)(struct RubikovaKocka*);
    void (*t_perm)(struct RubikovaKocka*);
    void (*r_perm)(struct RubikovaKocka*);
    //corners (coskovi)
    void (*cornerB)(struct RubikovaKocka*);
    void (*cornerC)(struct RubikovaKocka*);
    void (*cornerD)(struct RubikovaKocka*);
    void (*cornerF)(struct RubikovaKocka*);
    void (*cornerG)(struct RubikovaKocka*);
    void (*cornerH)(struct RubikovaKocka*);
    void (*cornerI)(struct RubikovaKocka*);
    void (*cornerJ)(struct RubikovaKocka*);
    void (*cornerK)(struct RubikovaKocka*);
    void (*cornerL)(struct RubikovaKocka*);
    void (*cornerM)(struct RubikovaKocka*);
    void (*cornerN)(struct RubikovaKocka*);
    void (*cornerO)(struct RubikovaKocka*);
    void (*cornerP)(struct RubikovaKocka*);
    void (*cornerQ)(struct RubikovaKocka*);
    void (*cornerS)(struct RubikovaKocka*);
    void (*cornerT)(struct RubikovaKocka*);
    void (*cornerX)(struct RubikovaKocka*);
    void (*cornerY)(struct RubikovaKocka*);
    void (*cornerZ)(struct RubikovaKocka*);
    void (*cornerW)(struct RubikovaKocka*);
    //edges (ivice)
    void (*edgeA)(struct RubikovaKocka*);
    void (*edgeC)(struct RubikovaKocka*);
    void (*edgeD)(struct RubikovaKocka*);
    void (*edgeE)(struct RubikovaKocka*);
    void (*edgeF)(struct RubikovaKocka*);
    void (*edgeG)(struct RubikovaKocka*);
    void (*edgeH)(struct RubikovaKocka*);
    void (*edgeI)(struct RubikovaKocka*);
    void (*edgeJ)(struct RubikovaKocka*);
    void (*edgeK)(struct RubikovaKocka*);
    void (*edgeL)(struct RubikovaKocka*);
    void (*edgeN)(struct RubikovaKocka*);
    void (*edgeO)(struct RubikovaKocka*);
    void (*edgeP)(struct RubikovaKocka*);
    void (*edgeQ)(struct RubikovaKocka*);
    void (*edgeR)(struct RubikovaKocka*);
    void (*edgeS)(struct RubikovaKocka*);
    void (*edgeT)(struct RubikovaKocka*);
    void (*edgeX)(struct RubikovaKocka*);
    void (*edgeY)(struct RubikovaKocka*);
    void (*edgeZ)(struct RubikovaKocka*);
    void (*edgeW)(struct RubikovaKocka*);
};

void Readfile(struct RubikovaKocka *cube){
    int i = 0;
    cube -> Y.set = Set; //zuta
    cube -> Y.set(i, &(cube -> Y));
    i += 21;
    cube -> R.set = Set; //crvena
    cube -> R.set(i, &(cube -> R));
    i += 21;
    cube -> B.set = Set; //plava
    cube -> B.set(i, &(cube -> B));
    i += 21;
    cube -> O.set = Set; //narandzasta
    cube -> O.set(i, &(cube -> O));
    i += 21;
    cube -> G.set = Set; //zelena
    cube -> G.set(i, &(cube -> G));
    i += 21;
    cube -> W.set = Set; //bela
    cube -> W.set(i, &(cube -> W));
}

void Backup(struct RubikovaKocka *cube){
    cube -> Y_backup = cube -> Y;
    cube -> B_backup = cube -> B;
    cube -> G_backup = cube -> G;
    cube -> O_backup = cube -> O;
    cube -> W_backup = cube -> W;
    cube -> R_backup = cube -> R;
}

//pokreti
void Turn_R (struct RubikovaKocka *cube){
    cube -> backup = Backup;
    cube -> backup(&(*cube));

    for (int i = 0; i < 3; i++){
        cube -> W.matrix[i][2] = cube -> G_backup.matrix[i][2];
        cube -> G.matrix[i][2] = cube -> Y_backup.matrix[i][2];
    }
    cube -> Y.matrix[0][2] = cube -> B_backup.matrix[2][0];
    cube -> Y.matrix[1][2] = cube -> B_backup.matrix[1][0];
    cube -> Y.matrix[2][2] = cube -> B_backup.matrix[0][0];

    cube -> B.matrix[2][0] = cube -> W_backup.matrix[0][2];
    cube -> B.matrix[1][0] = cube -> W_backup.matrix[1][2];
    cube -> B.matrix[0][0] = cube -> W_backup.matrix[2][2];

    //okretanje strane
    for (int i = 0; i < 3; i++){
        for (int j = 0; j< 3; j++){
            cube -> R.mbackup[i][j] = cube -> R.matrix[i][j];
        }
    }
    cube -> R.matrix[0][0] = cube -> R.mbackup[2][0];
    cube -> R.matrix[0][1] = cube -> R.mbackup[1][0];
    cube -> R.matrix[0][2] = cube -> R.mbackup[0][0];
    cube -> R.matrix[1][0] = cube -> R.mbackup[2][1];
    cube -> R.matrix[1][2] = cube -> R.mbackup[0][1];
    cube -> R.matrix[2][0] = cube -> R.mbackup[2][2];
    cube -> R.matrix[2][1] = cube -> R.mbackup[1][2];
    cube -> R.matrix[2][2] = cube -> R.mbackup[0][2];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j< 3; j++){
            cube -> R.mbackup[i][j] = cube -> R.matrix[i][j];
        }
    }

    cube -> backup = Backup;
    cube -> backup(&(*cube));
}

void Turn_L (struct RubikovaKocka *cube){
    cube -> backup = Backup;
    cube -> backup(&(*cube));

    for (int i = 0; i < 3; i++){
        cube -> G.matrix[i][0] = cube -> W_backup.matrix[i][0];
        cube -> Y.matrix[i][0] = cube -> G_backup.matrix[i][0];
    }
    cube -> B.matrix[2][2] = cube -> Y_backup.matrix[0][0];
    cube -> B.matrix[1][2] = cube -> Y_backup.matrix[1][0];
    cube -> B.matrix[0][2] = cube -> Y_backup.matrix[2][0];

    cube -> W.matrix[0][0] = cube -> B_backup.matrix[2][2];
    cube -> W.matrix[1][0] = cube -> B_backup.matrix[1][2];
    cube -> W.matrix[2][0] = cube -> B_backup.matrix[0][2];

    //okretanje strane
    for (int i = 0; i < 3; i++){
        for (int j = 0; j< 3; j++){
            cube -> O.mbackup[i][j] = cube -> O.matrix[i][j];
        }
    }
    cube -> O.matrix[0][0] = cube -> O.mbackup[2][0];
    cube -> O.matrix[0][1] = cube -> O.mbackup[1][0];
    cube -> O.matrix[0][2] = cube -> O.mbackup[0][0];
    cube -> O.matrix[1][0] = cube -> O.mbackup[2][1];
    cube -> O.matrix[1][2] = cube -> O.mbackup[0][1];
    cube -> O.matrix[2][0] = cube -> O.mbackup[2][2];
    cube -> O.matrix[2][1] = cube -> O.mbackup[1][2];
    cube -> O.matrix[2][2] = cube -> O.mbackup[0][2];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j< 3; j++){
            cube -> O.mbackup[i][j] = cube -> O.matrix[i][j];
        }
    }

    cube -> backup = Backup;
    cube -> backup(&(*cube));
}

void Turn_F (struct RubikovaKocka *cube){
    cube -> backup = Backup;
    cube -> backup(&(*cube));

    cube -> W.matrix[2][0] = cube -> O_backup.matrix[2][2];
    cube -> W.matrix[2][1] = cube -> O_backup.matrix[1][2];
    cube -> W.matrix[2][2] = cube -> O_backup.matrix[0][2];

    cube -> R.matrix[0][0] = cube -> W_backup.matrix[2][0];
    cube -> R.matrix[1][0] = cube -> W_backup.matrix[2][1];
    cube -> R.matrix[2][0] = cube -> W_backup.matrix[2][2];

    cube -> Y.matrix[0][2] = cube -> R_backup.matrix[0][0];
    cube -> Y.matrix[0][1] = cube -> R_backup.matrix[1][0];
    cube -> Y.matrix[0][0] = cube -> R_backup.matrix[2][0];

    cube -> O.matrix[0][2] = cube -> Y_backup.matrix[0][0];
    cube -> O.matrix[1][2] = cube -> Y_backup.matrix[0][1];
    cube -> O.matrix[2][2] = cube -> Y_backup.matrix[0][2];

    //okretanje strane
    for (int i = 0; i < 3; i++){
        for (int j = 0; j< 3; j++){
            cube -> G.mbackup[i][j] = cube -> G.matrix[i][j];
        }
    }
    cube -> G.matrix[0][0] = cube -> G.mbackup[2][0];
    cube -> G.matrix[0][1] = cube -> G.mbackup[1][0];
    cube -> G.matrix[0][2] = cube -> G.mbackup[0][0];
    cube -> G.matrix[1][0] = cube -> G.mbackup[2][1];
    cube -> G.matrix[1][2] = cube -> G.mbackup[0][1];
    cube -> G.matrix[2][0] = cube -> G.mbackup[2][2];
    cube -> G.matrix[2][1] = cube -> G.mbackup[1][2];
    cube -> G.matrix[2][2] = cube -> G.mbackup[0][2];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j< 3; j++){
            cube -> G.mbackup[i][j] = cube -> G.matrix[i][j];
        }
    }

    cube -> backup = Backup;
    cube -> backup(&(*cube));
}

void Turn_B (struct RubikovaKocka *cube){
    cube -> backup = Backup;
    cube -> backup(&(*cube));

    cube -> W.matrix[0][0] = cube -> R_backup.matrix[0][2];
    cube -> W.matrix[0][1] = cube -> R_backup.matrix[1][2];
    cube -> W.matrix[0][2] = cube -> R_backup.matrix[2][2];

    cube -> R.matrix[0][2] = cube -> Y_backup.matrix[2][0];
    cube -> R.matrix[1][2] = cube -> Y_backup.matrix[2][1];
    cube -> R.matrix[2][2] = cube -> Y_backup.matrix[2][2];

    cube -> Y.matrix[2][0] = cube -> O_backup.matrix[0][0];
    cube -> Y.matrix[2][1] = cube -> O_backup.matrix[1][0];
    cube -> Y.matrix[2][2] = cube -> O_backup.matrix[2][0];

    cube -> O.matrix[0][0] = cube -> W_backup.matrix[0][0];
    cube -> O.matrix[1][0] = cube -> W_backup.matrix[0][1];
    cube -> O.matrix[2][0] = cube -> W_backup.matrix[0][2];

    //okretanje strane
    for (int i = 0; i < 3; i++){
        for (int j = 0; j< 3; j++){
            cube -> B.mbackup[i][j] = cube -> B.matrix[i][j];
        }
    }
    cube -> B.matrix[0][0] = cube -> B.mbackup[2][0];
    cube -> B.matrix[0][1] = cube -> B.mbackup[1][0];
    cube -> B.matrix[0][2] = cube -> B.mbackup[0][0];
    cube -> B.matrix[1][0] = cube -> B.mbackup[2][1];
    cube -> B.matrix[1][2] = cube -> B.mbackup[0][1];
    cube -> B.matrix[2][0] = cube -> B.mbackup[2][2];
    cube -> B.matrix[2][1] = cube -> B.mbackup[1][2];
    cube -> B.matrix[2][2] = cube -> B.mbackup[0][2];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j< 3; j++){
            cube -> B.mbackup[i][j] = cube -> B.matrix[i][j];
        }
    }

    cube -> backup = Backup;
    cube -> backup(&(*cube));
}

void Turn_U(struct RubikovaKocka *cube){
    cube -> backup = Backup;
    cube -> backup(&(*cube));

    for (int i = 0; i < 3; i++){
        cube -> G.matrix[0][i] = cube -> R_backup.matrix[0][i];
        cube -> R.matrix[0][i] = cube -> B_backup.matrix[0][i];
        cube -> B.matrix[0][i] = cube -> O_backup.matrix[0][i];
        cube -> O.matrix[0][i] = cube -> G_backup.matrix[0][i];
    }

    //okretanje strane
    for (int i = 0; i < 3; i++){
        for (int j = 0; j< 3; j++){
            cube -> W.mbackup[i][j] = cube -> W.matrix[i][j];
        }
    }
    cube -> W.matrix[0][0] = cube -> W.mbackup[2][0];
    cube -> W.matrix[0][1] = cube -> W.mbackup[1][0];
    cube -> W.matrix[0][2] = cube -> W.mbackup[0][0];
    cube -> W.matrix[1][0] = cube -> W.mbackup[2][1];
    cube -> W.matrix[1][2] = cube -> W.mbackup[0][1];
    cube -> W.matrix[2][0] = cube -> W.mbackup[2][2];
    cube -> W.matrix[2][1] = cube -> W.mbackup[1][2];
    cube -> W.matrix[2][2] = cube -> W.mbackup[0][2];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j< 3; j++){
            cube -> W.mbackup[i][j] = cube -> W.matrix[i][j];
        }
    }

    cube -> backup = Backup;
    cube -> backup(&(*cube));
}

void Turn_D(struct RubikovaKocka *cube){
    cube -> backup = Backup;
    cube -> backup(&(*cube));

    for (int i = 0; i < 3; i++){
        cube -> G.matrix[2][i] = cube -> O_backup.matrix[2][i];
        cube -> R.matrix[2][i] = cube -> G_backup.matrix[2][i];
        cube -> B.matrix[2][i] = cube -> R_backup.matrix[2][i];
        cube -> O.matrix[2][i] = cube -> B_backup.matrix[2][i];
    }

    //okretanje strane
    for (int i = 0; i < 3; i++){
        for (int j = 0; j< 3; j++){
            cube -> Y.mbackup[i][j] = cube -> Y.matrix[i][j];
        }
    }
    cube -> Y.matrix[0][0] = cube -> Y.mbackup[2][0];
    cube -> Y.matrix[0][1] = cube -> Y.mbackup[1][0];
    cube -> Y.matrix[0][2] = cube -> Y.mbackup[0][0];
    cube -> Y.matrix[1][0] = cube -> Y.mbackup[2][1];
    cube -> Y.matrix[1][2] = cube -> Y.mbackup[0][1];
    cube -> Y.matrix[2][0] = cube -> Y.mbackup[2][2];
    cube -> Y.matrix[2][1] = cube -> Y.mbackup[1][2];
    cube -> Y.matrix[2][2] = cube -> Y.mbackup[0][2];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j< 3; j++){
            cube -> Y.mbackup[i][j] = cube -> Y.matrix[i][j];
        }
    }

    cube -> backup = Backup;
    cube -> backup(&(*cube));
}

void Turn_Ri(struct RubikovaKocka *cube){
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
}

void Turn_Li(struct RubikovaKocka *cube){
    cube -> turn_L = Turn_L;
    cube -> turn_L(&(*cube));
    cube -> turn_L = Turn_L;
    cube -> turn_L(&(*cube));
    cube -> turn_L = Turn_L;
    cube -> turn_L(&(*cube));
}

void Turn_Fi(struct RubikovaKocka *cube){
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
}

void Turn_Bi(struct RubikovaKocka *cube){
    cube -> turn_B = Turn_B;
    cube -> turn_B(&(*cube));
    cube -> turn_B = Turn_B;
    cube -> turn_B(&(*cube));
    cube -> turn_B = Turn_B;
    cube -> turn_B(&(*cube));
}

void Turn_Ui(struct RubikovaKocka *cube){
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
}

void Turn_Di(struct RubikovaKocka *cube){
    cube -> turn_D = Turn_D;
    cube -> turn_D(&(*cube));
    cube -> turn_D = Turn_D;
    cube -> turn_D(&(*cube));
    cube -> turn_D = Turn_D;
    cube -> turn_D(&(*cube));
}

//perms
void Y_perm(struct RubikovaKocka *cube){
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_Ui = Turn_Ui;
    cube -> turn_Ui(&(*cube));
    cube -> turn_Ri = Turn_Ri;
    cube -> turn_Ri(&(*cube));
    cube -> turn_Ui = Turn_Ui;
    cube -> turn_Ui(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    cube -> turn_Ri = Turn_Ri;
    cube -> turn_Ri(&(*cube));
    cube -> turn_Fi = Turn_Fi;
    cube -> turn_Fi(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    cube -> turn_Ri = Turn_Ri;
    cube -> turn_Ri(&(*cube));
    cube -> turn_Ui = Turn_Ui;
    cube -> turn_Ui(&(*cube));
    cube -> turn_Ri = Turn_Ri;
    cube -> turn_Ri(&(*cube));
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));

    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "R U' R' U' R U R' F' R U R' U' R' F R ");
    fclose(w);
}

void T_perm (struct RubikovaKocka *cube){
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    cube -> turn_Ri = Turn_Ri;
    cube -> turn_Ri(&(*cube));
    cube -> turn_Ui = Turn_Ui;
    cube -> turn_Ui(&(*cube));
    cube -> turn_Ri = Turn_Ri;
    cube -> turn_Ri(&(*cube));
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_Ui = Turn_Ui;
    cube -> turn_Ui(&(*cube));
    cube -> turn_Ri = Turn_Ri;
    cube -> turn_Ri(&(*cube));
    cube -> turn_Ui = Turn_Ui;
    cube -> turn_Ui(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    cube -> turn_Ri = Turn_Ri;
    cube -> turn_Ri(&(*cube));
    cube -> turn_Fi = Turn_Fi;
    cube -> turn_Fi(&(*cube));

    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "R U R' U' R' F R2 U' R' U' R U R' F' ");
    fclose(w);
}

void R_perm (struct RubikovaKocka *cube){

    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_Ui = Turn_Ui;
    cube -> turn_Ui(&(*cube));
    cube -> turn_Ri = Turn_Ri;
    cube -> turn_Ri(&(*cube));
    cube -> turn_Ui = Turn_Ui;
    cube -> turn_Ui(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_D = Turn_D;
    cube -> turn_D(&(*cube));
    cube -> turn_Ri = Turn_Ri;
    cube -> turn_Ri(&(*cube));
    cube -> turn_Ui = Turn_Ui;
    cube -> turn_Ui(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_Di = Turn_Di;
    cube -> turn_Di(&(*cube));
    cube -> turn_Ri = Turn_Ri;
    cube -> turn_Ri(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    cube -> turn_Ri = Turn_Ri;
    cube -> turn_Ri(&(*cube));
    cube -> turn_Ui = Turn_Ui;
    cube -> turn_Ui(&(*cube));

    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "R U' R' U' R U R D R' U' R D' R' U2 R' U'\n");
    fclose(w);
}

//corners (coskovi)
void CornerB (struct RubikovaKocka *cube){
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "R2 ");
    fclose(w);
    cube -> y_perm = Y_perm;
    cube -> y_perm(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "R2\n");
    fclose(f);
}

void CornerC (struct RubikovaKocka *cube){
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_Di = Turn_Di;
    cube -> turn_Di(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "R2 D' ");
    fclose(w);
    cube -> y_perm = Y_perm;
    cube -> y_perm(&(*cube));
    cube -> turn_D = Turn_D;
    cube -> turn_D(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "D R2\n");
    fclose(f);
}

void CornerD (struct RubikovaKocka *cube){
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "F2 ");
    fclose(w);
    cube -> y_perm = Y_perm;
    cube -> y_perm(&(*cube));
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "F2\n");
    fclose(f);
}

void CornerF (struct RubikovaKocka *cube){
    cube -> turn_Fi = Turn_Fi;
    cube -> turn_Fi(&(*cube));
    cube -> turn_D = Turn_D;
    cube -> turn_D(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "F' D ");
    fclose(w);
    cube -> y_perm = Y_perm;
    cube -> y_perm(&(*cube));
    cube -> turn_Di = Turn_Di;
    cube -> turn_Di(&(*cube));
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "D' F\n");
    fclose(f);
}

void CornerG (struct RubikovaKocka *cube){
    cube -> turn_Fi = Turn_Fi;
    cube -> turn_Fi(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "F' ");
    fclose(w);
    cube -> y_perm = Y_perm;
    cube -> y_perm(&(*cube));
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "F\n");
    fclose(f);
}

void CornerH (struct RubikovaKocka *cube){
    cube -> turn_D = Turn_D;
    cube -> turn_D(&(*cube));
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    cube -> turn_Ri = Turn_Ri;
    cube -> turn_Ri(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "D F2 R' ");
    fclose(w);
    cube -> y_perm = Y_perm;
    cube -> y_perm(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    cube -> turn_Di = Turn_Di;
    cube -> turn_Di(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "R F2 D'\n");
    fclose(f);
}

void CornerI (struct RubikovaKocka *cube){
    cube -> turn_L = Turn_L;
    cube -> turn_L(&(*cube));
    cube -> turn_D = Turn_D;
    cube -> turn_D(&(*cube));
    cube -> turn_Li = Turn_Li;
    cube -> turn_Li(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "L D L' ");
    fclose(w);
    cube -> y_perm = Y_perm;
    cube -> y_perm(&(*cube));
    cube -> turn_L = Turn_L;
    cube -> turn_L(&(*cube));
    cube -> turn_Di = Turn_Di;
    cube -> turn_Di(&(*cube));
    cube -> turn_Li = Turn_Li;
    cube -> turn_Li(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "L D' L'\n");
    fclose(f);
}

void CornerJ (struct RubikovaKocka *cube){
    cube -> turn_Ri = Turn_Ri;
    cube -> turn_Ri(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "R' ");
    fclose(w);
    cube -> y_perm = Y_perm;
    cube -> y_perm(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "R\n");
    fclose(f);
}

void CornerK (struct RubikovaKocka *cube){
    cube -> turn_Ri = Turn_Ri;
    cube -> turn_Ri(&(*cube));
    cube -> turn_Di = Turn_Di;
    cube -> turn_Di(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "R' D' ");
    fclose(w);
    cube -> y_perm = Y_perm;
    cube -> y_perm(&(*cube));
    cube -> turn_D = Turn_D;
    cube -> turn_D(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "D R\n");
    fclose(f);
}

void CornerL (struct RubikovaKocka *cube){
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    cube -> turn_Ri = Turn_Ri;
    cube -> turn_Ri(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "F2 R' ");
    fclose(w);
    cube -> y_perm = Y_perm;
    cube -> y_perm(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "R F2\n");
    fclose(f);
}

void CornerM (struct RubikovaKocka *cube){
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "F ");
    fclose(w);
    cube -> y_perm = Y_perm;
    cube -> y_perm(&(*cube));
    cube -> turn_Fi = Turn_Fi;
    cube -> turn_Fi(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "F'\n");
    fclose(f);
}

void CornerN (struct RubikovaKocka *cube){
    cube -> turn_Ri = Turn_Ri;
    cube -> turn_Ri(&(*cube));
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "R' F ");
    fclose(w);
    cube -> y_perm = Y_perm;
    cube -> y_perm(&(*cube));
    cube -> turn_Fi = Turn_Fi;
    cube -> turn_Fi(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "F' R\n");
    fclose(f);
}

void CornerO (struct RubikovaKocka *cube){
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "R2 F ");
    fclose(w);
    cube -> y_perm = Y_perm;
    cube -> y_perm(&(*cube));
    cube -> turn_Fi = Turn_Fi;
    cube -> turn_Fi(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "F' R2\n");
    fclose(f);
}

void CornerP (struct RubikovaKocka *cube){
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "R F ");
    fclose(w);
    cube -> y_perm = Y_perm;
    cube -> y_perm(&(*cube));
    cube -> turn_Fi = Turn_Fi;
    cube -> turn_Fi(&(*cube));
    cube -> turn_Ri = Turn_Ri;
    cube -> turn_Ri(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "F' R'\n");
    fclose(f);
}

void CornerQ (struct RubikovaKocka *cube){
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_Di = Turn_Di;
    cube -> turn_Di(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "R D' ");
    fclose(w);
    cube -> y_perm = Y_perm;
    cube -> y_perm(&(*cube));
    cube -> turn_D = Turn_D;
    cube -> turn_D(&(*cube));
    cube -> turn_Ri = Turn_Ri;
    cube -> turn_Ri(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "D R'\n");
    fclose(f);
}

void CornerS (struct RubikovaKocka *cube){
    cube -> turn_Di = Turn_Di;
    cube -> turn_Di(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "D' R2 F ");
    fclose(w);
    cube -> y_perm = Y_perm;
    cube -> y_perm(&(*cube));
    cube -> turn_Fi = Turn_Fi;
    cube -> turn_Fi(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_D = Turn_D;
    cube -> turn_D(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "F' R2 D\n");
    fclose(f);
}

void CornerT (struct RubikovaKocka *cube){
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "R ");
    fclose(w);
    cube -> y_perm = Y_perm;
    cube -> y_perm(&(*cube));
    cube -> turn_Ri = Turn_Ri;
    cube -> turn_Ri(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "R'\n");
    fclose(f);
}

void CornerX (struct RubikovaKocka *cube){
    cube -> turn_D = Turn_D;
    cube -> turn_D(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "D ");
    fclose(w);
    cube -> y_perm = Y_perm;
    cube -> y_perm(&(*cube));
    cube -> turn_Di = Turn_Di;
    cube -> turn_Di(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "D'\n");
    fclose(f);
}

void CornerY (struct RubikovaKocka *cube){
    cube -> y_perm = Y_perm;
    cube -> y_perm(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "\n");
    fclose(w);
}

void CornerZ (struct RubikovaKocka *cube){
    cube -> turn_Di = Turn_Di;
    cube -> turn_Di(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "D' ");
    fclose(w);
    cube -> y_perm = Y_perm;
    cube -> y_perm(&(*cube));
    cube -> turn_D = Turn_D;
    cube -> turn_D(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "D\n");
    fclose(f);
}

void CornerW (struct RubikovaKocka *cube){
    cube -> turn_D = Turn_D;
    cube -> turn_D(&(*cube));
    cube -> turn_D = Turn_D;
    cube -> turn_D(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "D2 ");
    fclose(w);
    cube -> y_perm = Y_perm;
    cube -> y_perm(&(*cube));
    cube -> turn_D = Turn_D;
    cube -> turn_D(&(*cube));
    cube -> turn_D = Turn_D;
    cube -> turn_D(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "D2\n");
    fclose(f);
}

//Provera da li su svi coskovi slozeni
int CornersSolved (struct RubikovaKocka *cube){
    if ((cube -> W.matrix[0][0] == 'w') && (cube -> W.matrix[0][2] == 'w') && (cube -> W.matrix[2][0] == 'w') && (cube -> W.matrix[2][2] == 'w') &&
        (cube -> G.matrix[0][0] == 'g') && (cube -> G.matrix[0][2] == 'g') && (cube -> G.matrix[2][0] == 'g') && (cube -> G.matrix[2][2] == 'g') &&
        (cube -> R.matrix[0][0] == 'r') && (cube -> R.matrix[0][2] == 'r') && (cube -> R.matrix[2][0] == 'r') && (cube -> R.matrix[2][2] == 'r') &&
        (cube -> B.matrix[0][0] == 'b') && (cube -> B.matrix[0][2] == 'b') && (cube -> B.matrix[2][0] == 'b') && (cube -> B.matrix[2][2] == 'b') &&
        (cube -> O.matrix[0][0] == 'o') && (cube -> O.matrix[0][2] == 'o') && (cube -> O.matrix[2][0] == 'o') && (cube -> O.matrix[2][2] == 'o') &&
        (cube -> Y.matrix[0][0] == 'y') && (cube -> Y.matrix[0][2] == 'y') && (cube -> Y.matrix[2][0] == 'y') && (cube -> Y.matrix[2][2] == 'y')){
        return 1;
    }
    return 0;
}

//Slaganje coskova
void SolveCorners (struct RubikovaKocka *cube){
    cube -> cornersSolved = CornersSolved;
    int k = cube -> cornersSolved(&(*cube));
    while (k == 0){
        cube -> cornersSolved = CornersSolved;
        k = cube -> cornersSolved(&(*cube));

        //Ako je buffer na svom mestu (rotiran ili slozen) a coskovi nisu jos slozeni
        if (((cube -> W.matrix[0][0] == 'w') && (cube -> O.matrix[0][0] == 'o')) ||
            ((cube -> W.matrix[0][0] == 'b') && (cube -> O.matrix[0][0] == 'w')) ||
            ((cube -> W.matrix[0][0] == 'o') && (cube -> O.matrix[0][0] == 'b'))){
                if (cube -> W.matrix[0][2] != 'w') {
                    cube -> cornerB = CornerB;
                    cube -> cornerB(&(*cube));
                    p++;
                }
                else if (cube -> W.matrix[2][2] != 'w'){
                    cube -> cornerC = CornerC;
                    cube -> cornerC(&(*cube));
                    p++;
                }
                else if (cube -> W.matrix[2][0] != 'w'){
                    cube -> cornerD = CornerD;
                    cube -> cornerD(&(*cube));
                    p++;
                }
                else if (cube -> O.matrix[0][2] != 'o'){
                    cube -> cornerF = CornerF;
                    cube -> cornerF(&(*cube));
                    p++;
                }
                else if (cube -> O.matrix[2][2] != 'o'){
                    cube -> cornerG = CornerG;
                    cube -> cornerG(&(*cube));
                    p++;
                }
                else if (cube -> O.matrix[2][0] != 'o'){
                    cube -> cornerH = CornerH;
                    cube -> cornerH(&(*cube));
                    p++;
                }
                else if (cube -> G.matrix[0][0] != 'g'){
                    cube -> cornerI = CornerI;
                    cube -> cornerI(&(*cube));
                    p++;
                }
                else if (cube -> G.matrix[0][2] != 'g'){
                    cube -> cornerJ = CornerJ;
                    cube -> cornerJ(&(*cube));
                    p++;
                }
                else if (cube -> G.matrix[2][2] != 'g'){
                    cube -> cornerK = CornerK;
                    cube -> cornerK(&(*cube));
                    p++;
                }
                else if (cube -> G.matrix[2][0] != 'g'){
                    cube -> cornerL = CornerL;
                    cube -> cornerL(&(*cube));
                    p++;
                }
                else if (cube -> R.matrix[0][0] != 'r'){
                    cube -> cornerM = CornerM;
                    cube -> cornerM(&(*cube));
                    p++;
                }
                else if (cube -> R.matrix[0][2] != 'r'){
                    cube -> cornerN = CornerN;
                    cube -> cornerN(&(*cube));
                    p++;
                }
                else if (cube -> R.matrix[2][2] != 'r'){
                    cube -> cornerO = CornerO;
                    cube -> cornerO(&(*cube));
                    p++;
                }
                else if (cube -> R.matrix[2][0] != 'r'){
                    cube -> cornerP = CornerP;
                    cube -> cornerP(&(*cube));
                    p++;
                }
                else if (cube -> B.matrix[0][0] != 'b'){
                    cube -> cornerQ = CornerQ;
                    cube -> cornerQ(&(*cube));
                    p++;
                }
                else if (cube -> B.matrix[2][2] != 'b'){
                    cube -> cornerS = CornerS;
                    cube -> cornerS(&(*cube));
                    p++;
                }
                else if (cube -> B.matrix[2][0] != 'b'){
                    cube -> cornerT = CornerT;
                    cube -> cornerT(&(*cube));
                    p++;
                }
                else if (cube -> Y.matrix[0][0] != 'y'){
                    cube -> cornerX = CornerX;
                    cube -> cornerX(&(*cube));
                    p++;
                }
                else if (cube -> Y.matrix[0][2] != 'y'){
                    cube -> cornerY = CornerY;
                    cube -> cornerY(&(*cube));
                    p++;
                }
                else if (cube -> Y.matrix[2][2] != 'y'){
                    cube -> cornerZ = CornerZ;
                    cube -> cornerZ(&(*cube));
                    p++;
                }
                else if (cube -> Y.matrix[2][0] != 'y'){
                    cube -> cornerW = CornerW;
                    cube -> cornerW(&(*cube));
                    p++;
                }
        }
        else{
            if (cube -> W.matrix[0][0] == 'w'){
                if (cube -> O.matrix[0][0] == 'r'){
                    cube -> cornerM = CornerM;
                    cube -> cornerM(&(*cube));
                    p++;
                }
                else if (cube -> O.matrix[0][0] == 'b'){
                    cube -> cornerQ = CornerQ;
                    cube -> cornerQ(&(*cube));
                    p++;
                }
                else if (cube -> O.matrix[0][0] == 'g'){
                    cube -> cornerI = CornerI;
                    cube -> cornerI(&(*cube));
                    p++;
                }
            }
            else if (cube -> W.matrix[0][0] == 'y'){
                if (cube -> O.matrix[0][0] == 'g'){
                    cube -> cornerK = CornerK;
                    cube -> cornerK(&(*cube));
                    p++;
                }
                else if (cube -> O.matrix[0][0] == 'o'){
                    cube -> cornerG = CornerG;
                    cube -> cornerG(&(*cube));
                    p++;
                }
                else if (cube -> O.matrix[0][0] == 'r'){
                    cube -> cornerO = CornerO;
                    cube -> cornerO(&(*cube));
                    p++;
                }
                else if (cube -> O.matrix[0][0] == 'b'){
                    cube -> cornerS = CornerS;
                    cube -> cornerS(&(*cube));
                    p++;
                }
            }
            else if (cube -> W.matrix[0][0] == 'g'){
                if (cube -> O.matrix[0][0] == 'o'){
                    cube -> cornerF = CornerF;
                    cube -> cornerF(&(*cube));
                    p++;
                }
                else if (cube -> O.matrix[0][0] == 'w'){
                    cube -> cornerC = CornerC;
                    cube -> cornerC(&(*cube));
                    p++;
                }
                else if (cube -> O.matrix[0][0] == 'r'){
                    cube -> cornerP = CornerP;
                    cube -> cornerP(&(*cube));
                    p++;
                }
                else if (cube -> O.matrix[0][0] == 'y'){
                    cube -> cornerX = CornerX;
                    cube -> cornerX(&(*cube));
                    p++;
                }
            }
            else if (cube -> W.matrix[0][0] == 'r'){
                if (cube -> O.matrix[0][0] == 'g'){
                    cube -> cornerJ = CornerJ;
                    cube -> cornerJ(&(*cube));
                    p++;
                }
                else if (cube -> O.matrix[0][0] == 'y'){
                    cube -> cornerY = CornerY;
                    cube -> cornerY(&(*cube));
                    p++;
                }
                else if (cube -> O.matrix[0][0] == 'w'){
                    cube -> cornerB = CornerB;
                    cube -> cornerB(&(*cube));
                    p++;
                }
                else if (cube -> O.matrix[0][0] == 'b'){
                    cube -> cornerT = CornerT;
                    cube -> cornerT(&(*cube));
                    p++;
                }
            }
            else if (cube -> W.matrix[0][0] == 'o'){
                if (cube -> O.matrix[0][0] == 'w'){
                    cube -> cornerD = CornerD;
                    cube -> cornerD(&(*cube));
                    p++;
                }
                else if (cube -> O.matrix[0][0] == 'g'){
                    cube -> cornerL = CornerL;
                    cube -> cornerL(&(*cube));
                    p++;
                }
                else if (cube -> O.matrix[0][0] == 'y'){
                    cube -> cornerW = CornerW;
                    cube -> cornerW(&(*cube));
                    p++;
                }
            }
            else if (cube -> W.matrix[0][0] == 'b'){
                if (cube -> O.matrix[0][0] == 'r'){
                    cube -> cornerN = CornerN;
                    cube -> cornerN(&(*cube));
                    p++;
                }
                else if (cube -> O.matrix[0][0] == 'y'){
                    cube -> cornerZ = CornerZ;
                    cube -> cornerZ(&(*cube));
                    p++;
                }
                else if (cube -> O.matrix[0][0] == 'o'){
                    cube -> cornerH = CornerH;
                    cube -> cornerH(&(*cube));
                    p++;
                }
            }
        }
    }
    FILE *q = fopen("solved.txt", "a");
    fprintf(q, "\n");
    fclose(q);
}

//Provera da li je kocka slozena
int IsSolved (struct RubikovaKocka *cube){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if ((cube -> W.matrix[i][j] != 'w') || (cube -> G.matrix[i][j] != 'g') || (cube -> R.matrix[i][j] != 'r') ||
                (cube -> B.matrix[i][j] != 'b') || (cube -> O.matrix[i][j] != 'o') || (cube -> Y.matrix[i][j] != 'y')){
                    return 0;
            }
        }
    }
    return 1;
}

//edges (ivice)
void EdgeA (struct RubikovaKocka *cube){
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_Ui = Turn_Ui;
    cube -> turn_Ui(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "R2 U' R2 ");
    fclose(w);
    cube -> t_perm = T_perm;
    cube -> t_perm(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "R2 U R2\n");
    fclose(f);
}

void EdgeC (struct RubikovaKocka *cube){
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "R2 U R2 ");
    fclose(w);
    cube -> t_perm = T_perm;
    cube -> t_perm(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_Ui = Turn_Ui;
    cube -> turn_Ui(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "R2 U' R2\n");
    fclose(f);
}

void EdgeD (struct RubikovaKocka *cube){
    cube -> t_perm = T_perm;
    cube -> t_perm(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "\n");
    fclose(f);
}

void EdgeE (struct RubikovaKocka *cube){
    cube -> turn_Li = Turn_Li;
    cube -> turn_Li(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    cube -> turn_Bi = Turn_Bi;
    cube -> turn_Bi(&(*cube));
    cube -> turn_Ui = Turn_Ui;
    cube -> turn_Ui(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "L' U B' U' ");
    fclose(w);
    cube -> t_perm = T_perm;
    cube -> t_perm(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    cube -> turn_B = Turn_B;
    cube -> turn_B(&(*cube));
    cube -> turn_Ui = Turn_Ui;
    cube -> turn_Ui(&(*cube));
    cube -> turn_L = Turn_L;
    cube -> turn_L(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "U B U' L\n");
    fclose(f);
}

void EdgeF (struct RubikovaKocka *cube){
    cube -> turn_Ui = Turn_Ui;
    cube -> turn_Ui(&(*cube));
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "U' F U ");
    fclose(w);
    cube -> t_perm = T_perm;
    cube -> t_perm(&(*cube));
    cube -> turn_Ui = Turn_Ui;
    cube -> turn_Ui(&(*cube));
    cube -> turn_Fi = Turn_Fi;
    cube -> turn_Fi(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "U' F' U\n");
    fclose(f);
}

void EdgeG (struct RubikovaKocka *cube){
    cube -> turn_Li = Turn_Li;
    cube -> turn_Li(&(*cube));
    cube -> turn_Ui = Turn_Ui;
    cube -> turn_Ui(&(*cube));
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "L' U' F U ");
    fclose(w);
    cube -> t_perm = T_perm;
    cube -> t_perm(&(*cube));
    cube -> turn_Ui = Turn_Ui;
    cube -> turn_Ui(&(*cube));
    cube -> turn_Fi = Turn_Fi;
    cube -> turn_Fi(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    cube -> turn_L = Turn_L;
    cube -> turn_L(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "U' F' U L\n");
    fclose(f);
}

void EdgeH (struct RubikovaKocka *cube){
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    cube -> turn_Bi = Turn_Bi;
    cube -> turn_Bi(&(*cube));
    cube -> turn_Ui = Turn_Ui;
    cube -> turn_Ui(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "U B' U' ");
    fclose(w);
    cube -> t_perm = T_perm;
    cube -> t_perm(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    cube -> turn_B = Turn_B;
    cube -> turn_B(&(*cube));
    cube -> turn_Ui = Turn_Ui;
    cube -> turn_Ui(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "U B U'\n");
    fclose(f);
}

void EdgeI (struct RubikovaKocka *cube){
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_Fi = Turn_Fi;
    cube -> turn_Fi(&(*cube));
    cube -> turn_Li = Turn_Li;
    cube -> turn_Li(&(*cube));
    cube -> turn_Ri = Turn_Ri;
    cube -> turn_Ri(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "R F' L' R' ");
    fclose(w);
    cube -> t_perm = T_perm;
    cube -> t_perm(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_L = Turn_L;
    cube -> turn_L(&(*cube));
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    cube -> turn_Ri = Turn_Ri;
    cube -> turn_Ri(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "R L F R'\n");
    fclose(f);
}

void EdgeJ (struct RubikovaKocka *cube){
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "U2 R U2 ");
    fclose(w);
    cube -> t_perm = T_perm;
    cube -> t_perm(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    cube -> turn_Ri = Turn_Ri;
    cube -> turn_Ri(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "U2 R' U2\n");
    fclose(f);
}

void EdgeK (struct RubikovaKocka *cube){
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    cube -> turn_Li = Turn_Li;
    cube -> turn_Li(&(*cube));
    cube -> turn_Fi = Turn_Fi;
    cube -> turn_Fi(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "F L' F' ");
    fclose(w);
    cube -> t_perm = T_perm;
    cube -> t_perm(&(*cube));
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    cube -> turn_L = Turn_L;
    cube -> turn_L(&(*cube));
    cube -> turn_Fi = Turn_Fi;
    cube -> turn_Fi(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "F L F'\n");
    fclose(f);
}

void EdgeL (struct RubikovaKocka *cube){
    cube -> turn_Li = Turn_Li;
    cube -> turn_Li(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "L' ");
    fclose(w);
    cube -> t_perm = T_perm;
    cube -> t_perm(&(*cube));
    cube -> turn_L = Turn_L;
    cube -> turn_L(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "L\n");
    fclose(f);
}

void EdgeN (struct RubikovaKocka *cube){
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    cube -> turn_B = Turn_B;
    cube -> turn_B(&(*cube));
    cube -> turn_Ui = Turn_Ui;
    cube -> turn_Ui(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "U B U' ");
    fclose(f);
    cube -> t_perm = T_perm;
    cube -> t_perm(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    cube -> turn_Bi = Turn_Bi;
    cube -> turn_Bi(&(*cube));
    cube -> turn_Ui = Turn_Ui;
    cube -> turn_Ui(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "U B' U'\n");
    fclose(w);
}

void EdgeO (struct RubikovaKocka *cube){
    cube -> turn_Di = Turn_Di;
    cube -> turn_Di(&(*cube));
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    cube -> turn_Li = Turn_Li;
    cube -> turn_Li(&(*cube));
    cube -> turn_Fi = Turn_Fi;
    cube -> turn_Fi(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "D' F L' F' ");
    fclose(w);
    cube -> t_perm = T_perm;
    cube -> t_perm(&(*cube));
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    cube -> turn_L = Turn_L;
    cube -> turn_L(&(*cube));
    cube -> turn_Fi = Turn_Fi;
    cube -> turn_Fi(&(*cube));
    cube -> turn_D = Turn_D;
    cube -> turn_D(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "F L F' D\n");
    fclose(f);
}

void EdgeP (struct RubikovaKocka *cube){
    cube -> turn_Ui = Turn_Ui;
    cube -> turn_Ui(&(*cube));
    cube -> turn_Fi = Turn_Fi;
    cube -> turn_Fi(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "U' F' U ");
    fclose(f);
    cube -> t_perm = T_perm;
    cube -> t_perm(&(*cube));
    cube -> turn_Ui = Turn_Ui;
    cube -> turn_Ui(&(*cube));
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "U' F U\n");
    fclose(w);
}

void EdgeQ (struct RubikovaKocka *cube){
    cube -> turn_Ri = Turn_Ri;
    cube -> turn_Ri(&(*cube));
    cube -> turn_B = Turn_B;
    cube -> turn_B(&(*cube));
    cube -> turn_L = Turn_L;
    cube -> turn_L(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "R' B L R ");
    fclose(w);
    cube -> t_perm = T_perm;
    cube -> t_perm(&(*cube));
    cube -> turn_Ri = Turn_Ri;
    cube -> turn_Ri(&(*cube));
    cube -> turn_Li = Turn_Li;
    cube -> turn_Li(&(*cube));
    cube -> turn_Bi = Turn_Bi;
    cube -> turn_Bi(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "R' L' B' R\n");
    fclose(f);
}

void EdgeR (struct RubikovaKocka *cube){
    cube -> turn_L = Turn_L;
    cube -> turn_L(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "L ");
    fclose(w);
    cube -> t_perm = T_perm;
    cube -> t_perm(&(*cube));
    cube -> turn_Li = Turn_Li;
    cube -> turn_Li(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "L'\n");
    fclose(f);
}

void EdgeS (struct RubikovaKocka *cube){
    cube -> turn_D = Turn_D;
    cube -> turn_D(&(*cube));
    cube -> turn_D = Turn_D;
    cube -> turn_D(&(*cube));
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    cube -> turn_Li = Turn_Li;
    cube -> turn_Li(&(*cube));
    cube -> turn_Fi = Turn_Fi;
    cube -> turn_Fi(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "D2 F L' F' ");
    fclose(w);
    cube -> t_perm = T_perm;
    cube -> t_perm(&(*cube));
    cube -> turn_F = Turn_F;
    cube -> turn_F(&(*cube));
    cube -> turn_L = Turn_L;
    cube -> turn_L(&(*cube));
    cube -> turn_Fi = Turn_Fi;
    cube -> turn_Fi(&(*cube));
    cube -> turn_D = Turn_D;
    cube -> turn_D(&(*cube));
    cube -> turn_D = Turn_D;
    cube -> turn_D(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "F L F' D2\n");
    fclose(f);
}

void EdgeT (struct RubikovaKocka *cube){
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    cube -> turn_Ri = Turn_Ri;
    cube -> turn_Ri(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "U2 R' U2 ");
    fclose(w);
    cube -> t_perm = T_perm;
    cube -> t_perm(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    cube -> turn_R = Turn_R;
    cube -> turn_R(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    cube -> turn_U = Turn_U;
    cube -> turn_U(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "U2 R U2\n");
    fclose(f);
}

void EdgeX (struct RubikovaKocka *cube){
    cube -> turn_Di = Turn_Di;
    cube -> turn_Di(&(*cube));
    cube -> turn_L = Turn_L;
    cube -> turn_L(&(*cube));
    cube -> turn_L = Turn_L;
    cube -> turn_L(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "D' L2 ");
    fclose(w);
    cube -> t_perm = T_perm;
    cube -> t_perm(&(*cube));
    cube -> turn_L = Turn_L;
    cube -> turn_L(&(*cube));
    cube -> turn_L = Turn_L;
    cube -> turn_L(&(*cube));
    cube -> turn_D = Turn_D;
    cube -> turn_D(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "L2 D\n");
    fclose(f);
}

void EdgeY (struct RubikovaKocka *cube){
    cube -> turn_D = Turn_D;
    cube -> turn_D(&(*cube));
    cube -> turn_D = Turn_D;
    cube -> turn_D(&(*cube));
    cube -> turn_L = Turn_L;
    cube -> turn_L(&(*cube));
    cube -> turn_L = Turn_L;
    cube -> turn_L(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "D2 L2 ");
    fclose(w);
    cube -> t_perm = T_perm;
    cube -> t_perm(&(*cube));
    cube -> turn_L = Turn_L;
    cube -> turn_L(&(*cube));
    cube -> turn_L = Turn_L;
    cube -> turn_L(&(*cube));
    cube -> turn_D = Turn_D;
    cube -> turn_D(&(*cube));
    cube -> turn_D = Turn_D;
    cube -> turn_D(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "L2 D2\n");
    fclose(f);
}

void EdgeZ (struct RubikovaKocka *cube){
    cube -> turn_D = Turn_D;
    cube -> turn_D(&(*cube));
    cube -> turn_L = Turn_L;
    cube -> turn_L(&(*cube));
    cube -> turn_L = Turn_L;
    cube -> turn_L(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "D L2 ");
    fclose(w);
    cube -> t_perm = T_perm;
    cube -> t_perm(&(*cube));
    cube -> turn_L = Turn_L;
    cube -> turn_L(&(*cube));
    cube -> turn_L = Turn_L;
    cube -> turn_L(&(*cube));
    cube -> turn_Di = Turn_Di;
    cube -> turn_Di(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "L2 D'\n");
    fclose(f);
}

void EdgeW (struct RubikovaKocka *cube){
    cube -> turn_L = Turn_L;
    cube -> turn_L(&(*cube));
    cube -> turn_L = Turn_L;
    cube -> turn_L(&(*cube));
    FILE *w = fopen("solved.txt", "a");
    fprintf(w, "L2 ");
    fclose(w);
    cube -> t_perm = T_perm;
    cube -> t_perm(&(*cube));
    cube -> turn_L = Turn_L;
    cube -> turn_L(&(*cube));
    cube -> turn_L = Turn_L;
    cube -> turn_L(&(*cube));
    FILE *f = fopen("solved.txt", "a");
    fprintf(f, "L2 \n");
    fclose(f);
}

//Slaganje ivica
void SolveEdges (struct RubikovaKocka *cube){
    cube -> isSolved = IsSolved;
    int k = cube -> isSolved(&(*cube));

    while (k == 0){
        cube -> isSolved = IsSolved;
        k = cube -> isSolved(&(*cube));

        //Ako je buffer okrenut naopako ili dobro okrenut ali kocka nije slozena
        if (((cube -> W.matrix[1][2] == 'w') && (cube -> R.matrix[0][1] == 'r')) ||
            ((cube -> W.matrix[1][2] == 'r') && (cube -> R.matrix[0][1] == 'w'))){
                if (cube -> W.matrix[0][1] != 'w'){
                    cube -> edgeA = EdgeA;
                    cube -> edgeA(&(*cube));
                }
                else if (cube -> W.matrix[2][1] != 'w'){
                    cube -> edgeC = EdgeC;
                    cube -> edgeC(&(*cube));
                }
                else if (cube -> W.matrix[1][0] != 'w'){
                    cube -> edgeD = EdgeD;
                    cube -> edgeD(&(*cube));
                }
                else if (cube -> O.matrix[0][1] != 'o'){
                    cube -> edgeE = EdgeE;
                    cube -> edgeE(&(*cube));
                }
                else if (cube -> O.matrix[1][2] != 'o'){
                    cube -> edgeF = EdgeF;
                    cube -> edgeF(&(*cube));
                }
                else if (cube -> O.matrix[2][1] != 'o'){
                    cube -> edgeG = EdgeG;
                    cube -> edgeG(&(*cube));
                }
                else if (cube -> O.matrix[1][0] != 'o'){
                    cube -> edgeH = EdgeH;
                    cube -> edgeH(&(*cube));
                }
                else if (cube -> G.matrix[0][1] != 'g'){
                    cube -> edgeI = EdgeI;
                    cube -> edgeI(&(*cube));
                }
                else if (cube -> G.matrix[1][2] != 'g'){
                    cube -> edgeJ = EdgeJ;
                    cube -> edgeJ(&(*cube));
                }
                else if (cube -> G.matrix[2][1] != 'g'){
                    cube -> edgeK = EdgeK;
                    cube -> edgeK(&(*cube));
                }
                else if (cube -> G.matrix[1][0] != 'g'){
                    cube -> edgeL = EdgeL;
                    cube -> edgeL(&(*cube));
                }
                else if (cube -> R.matrix[1][2] != 'r'){
                    cube -> edgeN = EdgeN;
                    cube -> edgeN(&(*cube));
                }
                else if (cube -> R.matrix[2][1] != 'r'){
                    cube -> edgeO = EdgeO;
                    cube -> edgeO(&(*cube));
                }
                else if (cube -> R.matrix[1][0] != 'r'){
                    cube -> edgeP = EdgeP;
                    cube -> edgeP(&(*cube));
                }
                else if (cube -> B.matrix[0][1] != 'b'){
                    cube -> edgeQ = EdgeQ;
                    cube -> edgeQ(&(*cube));
                }
                else if (cube -> B.matrix[1][2] != 'b'){
                    cube -> edgeR = EdgeR;
                    cube -> edgeR(&(*cube));
                }
                else if (cube -> B.matrix[2][1] != 'b'){
                    cube -> edgeS = EdgeS;
                    cube -> edgeS(&(*cube));
                }
                else if (cube -> B.matrix[1][0] != 'b'){
                    cube -> edgeT = EdgeT;
                    cube -> edgeT(&(*cube));
                }
                else if (cube -> Y.matrix[0][1] != 'y'){
                    cube -> edgeX = EdgeX;
                    cube -> edgeX(&(*cube));
                }
                else if (cube -> Y.matrix[1][2] != 'y'){
                    cube -> edgeY = EdgeY;
                    cube -> edgeY(&(*cube));
                }
                else if (cube -> Y.matrix[2][1] != 'y'){
                    cube -> edgeZ = EdgeZ;
                    cube -> edgeZ(&(*cube));
                }
                else if (cube -> Y.matrix[1][0] != 'y'){
                    cube -> edgeW = EdgeW;
                    cube -> edgeW(&(*cube));
                }
        }
        else {
            if (cube -> W.matrix[1][2] == 'w'){
                if (cube -> R.matrix[0][1] == 'b'){
                    cube -> edgeA = EdgeA;
                    cube -> edgeA(&(*cube));
                }
                else if (cube -> R.matrix[0][1] == 'g'){
                    cube -> edgeC = EdgeC;
                    cube -> edgeC(&(*cube));
                }
                else if (cube -> R.matrix[0][1] == 'o'){
                    cube -> edgeD = EdgeD;
                    cube -> edgeD(&(*cube));
                }
            }
            else if (cube -> W.matrix[1][2] == 'y'){
                if (cube -> R.matrix[0][1] == 'g'){
                    cube -> edgeX = EdgeX;
                    cube -> edgeX(&(*cube));
                }
                else if (cube -> R.matrix[0][1] == 'r'){
                    cube -> edgeY = EdgeY;
                    cube -> edgeY(&(*cube));
                }
                else if (cube -> R.matrix[0][1] == 'b'){
                    cube -> edgeZ = EdgeZ;
                    cube -> edgeZ(&(*cube));
                }
                else if (cube -> R.matrix[0][1] == 'o'){
                    cube -> edgeW = EdgeW;
                    cube -> edgeW(&(*cube));
                }
            }
            else if (cube -> W.matrix[1][2] == 'g'){
                if (cube -> R.matrix[0][1] == 'w'){
                    cube -> edgeI = EdgeI;
                    cube -> edgeI(&(*cube));
                }
                else if (cube -> R.matrix[0][1] == 'r'){
                    cube -> edgeJ = EdgeJ;
                    cube -> edgeJ(&(*cube));
                }
                else if (cube -> R.matrix[0][1] == 'y'){
                    cube -> edgeK= EdgeK;
                    cube -> edgeK(&(*cube));
                }
                else if (cube -> R.matrix[0][1] == 'o'){
                    cube -> edgeL = EdgeL;
                    cube -> edgeL(&(*cube));
                }
            }
            else if (cube -> W.matrix[1][2] == 'r'){
                if (cube -> R.matrix[0][1] == 'b'){
                    cube -> edgeN = EdgeN;
                    cube -> edgeN(&(*cube));
                }
                else if (cube -> R.matrix[0][1] == 'y'){
                    cube -> edgeO = EdgeO;
                    cube -> edgeO(&(*cube));
                }
                else if (cube -> R.matrix[0][1] == 'g'){
                    cube -> edgeP = EdgeP;
                    cube -> edgeP(&(*cube));
                }
            }
            else if (cube -> W.matrix[1][2] == 'o'){
                if (cube -> R.matrix[0][1] == 'w'){
                    cube -> edgeE = EdgeE;
                    cube -> edgeE(&(*cube));
                }
                else if (cube -> R.matrix[0][1] == 'g'){
                    cube -> edgeF = EdgeF;
                    cube -> edgeF(&(*cube));
                }
                else if (cube -> R.matrix[0][1] == 'y'){
                    cube -> edgeG = EdgeG;
                    cube -> edgeG(&(*cube));
                }
                else if (cube -> R.matrix[0][1] == 'b'){
                    cube -> edgeH = EdgeH;
                    cube -> edgeH(&(*cube));
                }
            }
            else if (cube -> W.matrix[1][2] == 'b'){
                if (cube -> R.matrix[0][1] == 'w'){
                    cube -> edgeQ = EdgeQ;
                    cube -> edgeQ(&(*cube));
                }
                else if (cube -> R.matrix[0][1] == 'o'){
                    cube -> edgeR = EdgeR;
                    cube -> edgeR(&(*cube));
                }
                else if (cube -> R.matrix[0][1] == 'y'){
                    cube -> edgeS = EdgeS;
                    cube -> edgeS(&(*cube));
                }
                else if (cube -> R.matrix[0][1] == 'r'){
                    cube -> edgeT = EdgeT;
                    cube -> edgeT(&(*cube));
                }
            }
        }
    }
}

//Provera da li je nastao parity
void Parity (struct RubikovaKocka *cube){
    if (p % 2 != 0){
        cube -> r_perm = R_perm;
        cube -> r_perm(&(*cube));
    }
}

//main metod samo poziv funkcija
int main(){
    struct RubikovaKocka cube;

    //Upisivanje orijentacije u izlazni fajl
    FILE *file = fopen ("solved.txt", "a");
    fprintf(file, "Kocku drzite tako da je bela strana gore, a zelena ispred \n\n");
    fclose(file);

    //ucitamo iz fajla podatke
    cube.readfile = Readfile;
    cube.readfile(&cube);

    //slaganje coskova
    cube.solveCorners = SolveCorners;
    cube.solveCorners(&cube);

    //provera parity
    cube.parity = Parity;
    cube.parity(&cube);

    //slaganje ivica
    cube.solveEdges = SolveEdges;
    cube.solveEdges(&cube);

}
