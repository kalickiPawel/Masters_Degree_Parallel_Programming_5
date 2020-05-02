//
//  main.cpp
//  Lab05_labirynt
//
//  Created by Paweł Kalicki on 17/04/2020.
//  Copyright © 2020 Paweł Kalicki. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <tuple>

#define N 441

using namespace std;

static unsigned char color[N][N][3];

int color_r = rand() % 256;
int color_g = rand() % 256;
int color_b = rand() % 256;

int randomX, randomY;

const int MAP_WIDTH = 21;
const int MAP_HEIGHT = 21;

int world_map[MAP_WIDTH][MAP_HEIGHT] =
    {1, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
     1, 9, 1, 9, 9, 9, 1, 9, 9, 9, 9, 9, 1, 9, 9, 9, 9, 9, 9, 9, 1,
     1, 9, 1, 9, 1, 9, 1, 1, 1, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 1,
     1, 9, 1, 9, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 1, 9, 1, 9, 9, 9, 1,
     1, 9, 1, 1, 1, 1, 1, 9, 1, 1, 1, 1, 1, 9, 1, 9, 1, 1, 1, 9, 1,
     1, 9, 1, 9, 1, 9, 9, 9, 1, 9, 9, 9, 1, 9, 9, 9, 9, 9, 1, 9, 1,
     1, 9, 1, 9, 1, 1, 1, 9, 1, 9, 1, 9, 1, 9, 1, 1, 1, 1, 1, 9, 1,
     1, 9, 9, 9, 9, 9, 1, 9, 9, 9, 1, 9, 1, 9, 9, 9, 9, 9, 9, 9, 1,
     1, 1, 1, 9, 1, 1, 1, 1, 1, 9, 1, 9, 1, 1, 1, 9, 1, 9, 1, 1, 1,
     1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 1, 9, 9, 9, 1, 9, 1, 9, 9, 9, 1,
     1, 9, 1, 9, 1, 1, 1, 9, 1, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
     1, 9, 1, 9, 9, 9, 1, 9, 1, 9, 9, 9, 9, 9, 1, 9, 1, 9, 9, 9, 1,
     1, 1, 1, 1, 1, 1, 1, 9, 1, 9, 1, 1, 1, 1, 1, 9, 1, 1, 1, 9, 1,
     1, 9, 9, 9, 1, 9, 1, 9, 1, 9, 9, 9, 1, 9, 9, 9, 9, 9, 9, 9, 1,
     1, 9, 1, 1, 1, 9, 1, 9, 1, 1, 1, 9, 1, 9, 1, 9, 1, 1, 1, 9, 1,
     1, 9, 1, 9, 9, 9, 9, 9, 9, 9, 1, 9, 1, 9, 1, 9, 1, 9, 9, 9, 1,
     1, 9, 1, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 1, 1, 1, 9, 1,
     1, 9, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 1, 9, 1, 9, 1, 9, 1, 9, 1,
     1, 9, 1, 9, 1, 9, 1, 1, 1, 1, 1, 9, 1, 9, 1, 1, 1, 9, 1, 9, 1,
     1, 9, 9, 9, 1, 9, 9, 9, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 1,
     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

void drawLabirynth()
{
    // Here I create a color value with
    // empty maze black/white
    int i, j, k;
    for (i = 0; i <= N; i++)
        for (j = 0; j <= N; j++)
            for (k = 0; k < 3; k++)
            {
                if (world_map[i / 21][j / 21] == 9)
                    color[i][j][k] = 255;
            }
}

int getRandomColor()
{
    return rand() % 256;
}

void drawing_points(int x, int y, int color_r, int color_g, int color_b)
{
    // Drawing points
    int i, j;
    for (i = 0; i < 21; i++)
        for (j = 0; j < 21; j++)
        {
            color[x * 21 + i][y * 21 + j][0] = color_r;
            color[x * 21 + i][y * 21 + j][1] = color_g;
            color[x * 21 + i][y * 21 + j][2] = color_b;
        }
}

void changeColor()
{
    color_r = rand() % 256;
    color_g = rand() % 256;
    color_b = rand() % 256;
}

void getRandomStart()
{
    // Selecting start point
    randomX = (rand() % (N / 21));
    randomY = (rand() % (N / 21));

    while (world_map[randomX][randomY] == 1)
    {
        randomX = (rand() % (N / 21));
        randomY = (rand() % (N / 21));
    }
}

bool checkLeft(int x, int y)
{
    return (world_map[x][y - 1] == 1);
}
bool checkRight(int x, int y)
{
    return (world_map[x][y + 1] == 1);
}
bool checkUp(int x, int y)
{
    return (world_map[x + 1][y] == 1);
}
bool checkDown(int x, int y)
{
    return (world_map[x - 1][y] == 1);
}

void mazeSolution()
{
    cout << "X: " << randomX << " Y: " << randomY << endl;
    bool up = checkUp(randomX, randomY);
    cout << "Sciana gora: " << up << endl;
    bool down = checkDown(randomX, randomY);
    cout << "Sciana dol: " << down << endl;
    bool right = checkRight(randomX, randomY);
    cout << "Sciana prawo: " << right << endl;
    bool left = checkLeft(randomX, randomY);
    cout << "Sciana lewo: " << left << endl;
    int ilosc = !up + !down + !right + !left;
    int tmpX = randomX;
    int tmpY = randomY;
    cout << tmpX << tmpY << endl;
    int checking_value;
    if (up != true)
    {
        checking_value = 0;
    }
    if (down != true)
    {
        checking_value = 1;
    }
    if (right != true)
    {
        checking_value = 2;
    }
    if (left != true)
    {
        checking_value = 3;
    }

    cout << "Ile korytarzy?: " << ilosc << endl;
    while (ilosc != 0)
    {
        switch (ilosc)
        {
        case 0:
            cout << "In case: " << ilosc << endl;
            ilosc = 0;
            break;
        case 1:
            cout << checking_value << endl;
            if (checking_value == 0)
            {
                tmpX += 1;
            }
            if (checking_value == 1)
            {
                tmpX -= 1;
            }
            if (checking_value == 2)
            {
                tmpY += 1;
            }
            if (checking_value == 3)
            {
                tmpY -= 1;
            }
            drawing_points(tmpX, tmpY, color_r, color_g, color_b);

            ilosc = 0;
            break;
        case 2:
            cout << "In case: " << ilosc << endl;
            ilosc = 0;
            break;
        case 3:
            cout << "In case: " << ilosc << endl;
            ilosc = 0;
            break;
        case 4:
            cout << "In case: " << ilosc << endl;
            ilosc = 0;
            break;
        }
    }
}

int main(int argc, const char *argv[])
{
    srand((unsigned)time(0));
    FILE *fp;
    char const *filename = "labirynt.ppm";
    char const *comment = "# "; /* comment should start with # */

    drawLabirynth();

    getRandomStart();

    // Draw start point
    drawing_points(randomX, randomY, color_r, color_g, color_b);

    // Maze solution
    mazeSolution();

    fp = fopen(filename, "wb");
    fprintf(fp, "P6\n %s\n %d\n %d\n %d\n", comment, N, N, 255);
    fwrite(color, 1, 3 * N * N, fp);
    fclose(fp);

    return 0;
}
