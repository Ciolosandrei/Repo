#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <time.h>

int i, j, B, gameOver = 0, latime = 20, lungime = 20, x, y, fructX, fructY, scor;

void Init() {
    srand((unsigned int)time(NULL));
    x = lungime / 2;
    y = latime / 2;
    scor = 0;

    do {
        fructX = rand() % lungime;   //punctul bonus sau fructul apare intr-o zona aleatoare
        fructY = rand() % latime;
    } while (fructX <= 0 || fructY <= 0 || fructX == x || fructY == y || fructX > lungime || fructY > latime);
}

void Nivel()
{
    system("cls");
    for (i = 0; i < lungime; i++) {
        for (j = 0; j < latime; j++) {
            if (i == 0 || i == latime - 1 || j == 0 || j == lungime - 1) {
                printf("#");            // limita spatiu de joc
            }
            else {
                if (i == x && j == y)
                    printf("C");        // Pacman
                else if (i == fructX && j == fructY)
                    printf("*");        // punctul bonus pt scor
                else
                    printf(" ");
            }
        }
        printf("\n");
    }

    printf(" Scor: %d", scor);
    printf("\n");
    printf(" Instructiuni: \n");
    printf(" W sus \n");
    printf(" A stanga \n");
    printf(" S jos \n");
    printf(" D dreapta \n");
    printf(" Colectati cat mai multe puncte fara a parasi zona de joc! \n");
    printf(" X pentru a inchide jocul!");
}

void Butoane() {
    // clasicul WASD pentru miscare
    if (_kbhit()) {
        switch (_getch()) {
        case 'w':
            B = 1;
            break;
        case 's':
            B = 2;
            break;
        case 'a':
            B = 3;
            break;
        case 'd':
            B = 4;
            break;
        case 'x':
            gameOver = 1;
            break;
        }
    }
}

void Reguli() {
    
    switch (B) {
    case 1:
        x--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y--;
        break;
    case 4:
        y++;
        break;
    default:
        break;
    }


    if (x > 18 || y > 18 || x <= 0 || y <= 0) { //parasire zona de joc
        gameOver = 1;
    }

    if (x == fructX && y == fructY) {   //incrementare scor
        scor += 1;
        
        do {
            fructX = rand() % lungime; //noul punct bonus (fruct)
            fructY = rand() % latime;
        } while (fructX <= 0 || fructY <= 0 || fructX == x || fructY == y || fructX > lungime || fructY > latime);
    }
}

int main()
{
    Init();

    while (gameOver != 1) {
        Butoane();
        Reguli();
        Nivel();
        Sleep(200);  // viteza lui Pacman 
    }
    
    return 0;
}