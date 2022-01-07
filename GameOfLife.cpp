#include <iostream>
#include <Windows.h>
#include <ctime>
#include <stdlib.h>
using namespace std;
void randomSeed();
int Check(int row, int col);
void fate(int row, int col);

const int x = 32;
const int y = 32;

char grid[x][y];
int newGrid[x][y];


int main() {
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            grid[i][j] = ' ';
            newGrid[i][j] = ' ';
        }
    }


    randomSeed();
    while (true) {
        Sleep(100);
        system("cls");
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                fate(i, j);
            }
        }
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                grid[i][j] = newGrid[i][j];
            }
        }
        for (int i = 0; i < x * 2 + 2; i++) {
            cout << "-";
        }
        cout << endl << '|';
        for (int i = 0; i < y; i++) {
            if (i > 0)
                cout << "|";
            for (int j = 0; j < x; j++) {
                cout << grid[i][j] << " ";
                if (j == x - 1 && i >= 0)
                    cout << "|";
            }
            cout << endl;
        }
        for (int i = 0; i < x * 2 + 2; i++) {
            cout << "-";
        }
    }

    return 0;
}



int Check(int row, int col) {
    int counter = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int xrow = (row + i + y) % y;
            int xcol = (col + j + x) % x;
            if (grid[xrow][xcol] == 'x')
                counter++;
        }
    }
    if (grid[row][col] == 'x')
        counter--;
    return counter;
}


void fate(int row, int col) {
    char state = grid[row][col];

    if (state == ' ' && Check(row, col) == 3)
        newGrid[row][col] = 'x';
    else if (state == 'x' && (Check(row, col) < 2 || Check(row, col) > 3))
        newGrid[row][col] = ' ';
    else
        newGrid[row][col] = state;
}

void randomSeed() {
    srand((unsigned)time(0));
    for (int row = 0; row < y; row++) {
        for (int col = 0; col < x; col++) {
            if ((rand() % 2) == 1)
                grid[row][col] = 'x';
        }
    }
}