#include <iostream>
#include <conio.h>
#include <iomanip>
#include <ctime>
using namespace std;

int a[3][3];
void addrendom(int a[][3])
{

    int empty[9][2];
    int k = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] == 0)
            {
                empty[k][0] = i; // row
                empty[k][1] = j; // column
                k++;
            }
        }
    }
    if (k > 0)
    {

        int randomIndex = rand() % k;

        int row = empty[randomIndex][0];
        int col = empty[randomIndex][1];

        a[row][col] = 2;
    }
}
void gui(int a[][3])
{
    cout << "       2048     " << endl;
    cout << "+-----------------+" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "|";
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] == 0){
                cout << right << setw(5) << "" << "|";
            }
            else{
                cout << right << setw(5) << a[i][j] << "|";
            }  
            
        }

        cout << endl;
    }
    cout << "+-----------------+" << endl;
}
bool gameover(int a[][3])
{
    // Check empty space
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] == 0)
            {
                return false; // game not over
            }
        }
    }

    // Check horizontal merge
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (a[i][j] == a[i][j + 1])
            {
                return false;
            }
        }
    }

    // Check vertical merge
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 2; i++)
        {
            if (a[i][j] == a[i + 1][j])
            {
                return false;
            }
        }
    }

    return true; // game over
}
int main()
{
    srand(time(0));
    // game
    bool loop = true;
    addrendom(a);
    addrendom(a);
    gui(a);
    while (loop)
    {
        int ch = getch();

        if (ch == 224)
        {

            ch = getch();
            switch (ch)
            {
            case 72: // up

                for (int rep = 0; rep < 2; rep++)

                {
                    for (int col = 0; col < 3; col++)
                    {

                        if (a[0][col] == a[1][col] && a[0][col] != 0)
                        {
                            a[0][col] = a[0][col] + a[1][col];
                            a[1][col] = 0;
                        }
                        else if (a[1][col] == a[2][col] && a[1][col] != 0)
                        {
                            a[1][col] = a[1][col] + a[2][col];
                            a[2][col] = 0;
                        }

                        for (int j = 0; j < 2; j++)
                        {
                            if (a[j][col] == 0)
                            {
                                a[j][col] = a[j + 1][col];
                                a[j + 1][col] = 0;
                            }
                        }
                    }
                }
                addrendom(a);
                gui(a);
                if (gameover(a))
                {
                    cout << "\nGAME OVER!\n";
                    break;
                }
                break;
            case 80: // down

                for (int rep = 0; rep < 2; rep++)
                {
                    for (int col = 0; col < 3; col++)
                    {
                        if (a[2][col] == a[1][col] && a[2][col] != 0)
                        {
                            a[2][col] = a[2][col] + a[1][col];
                            a[1][col] = 0;
                        }
                        else if (a[1][col] == a[0][col] && a[1][col] != 0)
                        {
                            a[1][col] = a[1][col] + a[0][col];
                            a[0][col] = 0;
                        }
                        for (int j = 2; j > 0; j--)
                        {

                            if (a[j][col] == 0)
                            {
                                a[j][col] = a[j - 1][col];
                                a[j - 1][col] = 0;
                            }
                        }
                    }
                }
                addrendom(a);
                gui(a);
                if (gameover(a))
                {
                    cout << "\nGAME OVER!\n";
                    break;
                }
                break;
            case 77: // right

                for (int rep = 0; rep < 2; rep++)
                {
                    for (int row = 0; row < 3; row++)
                    {
                        if (a[row][2] == a[row][1] && a[row][2] != 0)
                        {
                            a[row][2] = a[row][2] + a[row][1];
                            a[row][1] = 0;
                        }
                        else if (a[row][0] == a[row][1] && a[row][1] != 0)
                        {
                            a[row][1] = a[row][0] + a[row][1];
                            a[row][0] = 0;
                        }
                        for (int j = 2; j > 0; j--)
                        {
                            if (a[row][j] == 0)
                            {
                                a[row][j] = a[row][j - 1];
                                a[row][j - 1] = 0;
                            }
                        }
                    }
                }
                addrendom(a);
                gui(a);
                if (gameover(a))
                {
                    cout << "\nGAME OVER!\n";
                    break;
                }
                break;
            case 75: // left

                for (int rep = 0; rep < 2; rep++)
                {
                    for (int row = 0; row < 3; row++)
                    {
                        if (a[row][0] == a[row][1] && a[row][0] != 0)
                        {
                            a[row][0] = a[row][0] + a[row][1];
                            a[row][1] = 0;
                        }
                        else if (a[row][1] == a[row][2] && a[row][1] != 0)
                        {
                            a[row][1] = a[row][1] + a[row][2];
                            a[row][2] = 0;
                        }
                        for (int j = 0; j < 2; j++)
                        {
                            if (a[row][j] == 0)
                            {
                                a[row][j] = a[row][j + 1];
                                a[row][j + 1] = 0;
                            }
                        }
                    }
                }
                addrendom(a);
                gui(a);
                if (gameover(a))
                {
                    cout << "\nGAME OVER!\n";
                    break;
                }
                break;
            default:
                cout << "Unknown Key\n";
            }
        }
        else
        {
            break;
        }
    }
    gui(a);
    return 0;
}