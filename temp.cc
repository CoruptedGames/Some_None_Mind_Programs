#include <iostream>
#include <conio.h>
#include <iomanip>
#include <ctime>
#include <vector>

using namespace std;

void addrendom(vector<vector<int>>& a, int n)
{
    vector<pair<int, int>> empty;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
            {
                empty.push_back({i, j});
            }
        }
    }

    if (!empty.empty())
    {
        int randomIndex = rand() % empty.size();

        int row = empty[randomIndex].first;
        int col = empty[randomIndex].second;

        a[row][col] = 2;
    }
}

void gui(vector<vector<int>>& a, int n)
{
    system("cls");

    cout << "\n\t\t2048\n\n";

    for (int i = 0; i < n; i++)
    {
        cout << "|";

        for (int j = 0; j < n; j++)
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

    cout << "\nPress ESC to Exit\n";
}

bool gameover(vector<vector<int>>& a, int n)
{
    // Empty check
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
            {
                return false;
            }
        }
    }

    // Horizontal merge possible
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (a[i][j] == a[i][j + 1])
            {
                return false;
            }
        }
    }

    // Vertical merge possible
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i][j] == a[i + 1][j])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    srand(time(0));

    int n;

    do
    {
        cout << "Enter matrix size (minimum 3): ";
        cin >> n;
    }
    while (n < 3);

    // Dynamic matrix
    vector<vector<int>> a(n, vector<int>(n, 0));

    addrendom(a, n);
    addrendom(a, n);

    gui(a, n);

    while (true)
    {
        int ch = getch();

        // ESC
        if (ch == 27)
        {
            cout << "\nGame Closed!\n";
            break;
        }

        if (ch == 224)
        {
            ch = getch();

            switch (ch)
            {
            case 72: // UP
                for (int rep = 0; rep < n - 1; rep++)
                {
                    for (int col = 0; col < n; col++)
                    {
                        // shift
                        for (int j = 0; j < n - 1; j++)
                        {
                            if (a[j][col] == 0)
                            {
                                a[j][col] = a[j + 1][col];
                                a[j + 1][col] = 0;
                            }
                        }

                        // merge
                        for (int j = 0; j < n - 1; j++)
                        {
                            if (a[j][col] == a[j + 1][col] &&
                                a[j][col] != 0)
                            {
                                a[j][col] += a[j + 1][col];
                                a[j + 1][col] = 0;
                            }
                        }

                        // shift again
                        for (int j = 0; j < n - 1; j++)
                        {
                            if (a[j][col] == 0)
                            {
                                a[j][col] = a[j + 1][col];
                                a[j + 1][col] = 0;
                            }
                        }
                    }
                }
                break;

            case 80: // DOWN
                for (int rep = 0; rep < n - 1; rep++)
                {
                    for (int col = 0; col < n; col++)
                    {
                        for (int j = n - 1; j > 0; j--)
                        {
                            if (a[j][col] == 0)
                            {
                                a[j][col] = a[j - 1][col];
                                a[j - 1][col] = 0;
                            }
                        }

                        for (int j = n - 1; j > 0; j--)
                        {
                            if (a[j][col] == a[j - 1][col] &&
                                a[j][col] != 0)
                            {
                                a[j][col] += a[j - 1][col];
                                a[j - 1][col] = 0;
                            }
                        }

                        for (int j = n - 1; j > 0; j--)
                        {
                            if (a[j][col] == 0)
                            {
                                a[j][col] = a[j - 1][col];
                                a[j - 1][col] = 0;
                            }
                        }
                    }
                }
                break;

            case 77: // RIGHT
                for (int rep = 0; rep < n - 1; rep++)
                {
                    for (int row = 0; row < n; row++)
                    {
                        for (int j = n - 1; j > 0; j--)
                        {
                            if (a[row][j] == 0)
                            {
                                a[row][j] = a[row][j - 1];
                                a[row][j - 1] = 0;
                            }
                        }

                        for (int j = n - 1; j > 0; j--)
                        {
                            if (a[row][j] == a[row][j - 1] &&
                                a[row][j] != 0)
                            {
                                a[row][j] += a[row][j - 1];
                                a[row][j - 1] = 0;
                            }
                        }

                        for (int j = n - 1; j > 0; j--)
                        {
                            if (a[row][j] == 0)
                            {
                                a[row][j] = a[row][j - 1];
                                a[row][j - 1] = 0;
                            }
                        }
                    }
                }
                break;

            case 75: // LEFT
                for (int rep = 0; rep < n - 1; rep++)
                {
                    for (int row = 0; row < n; row++)
                    {
                        for (int j = 0; j < n - 1; j++)
                        {
                            if (a[row][j] == 0)
                            {
                                a[row][j] = a[row][j + 1];
                                a[row][j + 1] = 0;
                            }
                        }

                        for (int j = 0; j < n - 1; j++)
                        {
                            if (a[row][j] == a[row][j + 1] &&
                                a[row][j] != 0)
                            {
                                a[row][j] += a[row][j + 1];
                                a[row][j + 1] = 0;
                            }
                        }

                        for (int j = 0; j < n - 1; j++)
                        {
                            if (a[row][j] == 0)
                            {
                                a[row][j] = a[row][j + 1];
                                a[row][j + 1] = 0;
                            }
                        }
                    }
                }
                break;
            }

            addrendom(a, n);
            gui(a, n);

            if (gameover(a, n))
            {
                cout << "\nGAME OVER!\n";
                break;
            }
        }
    }

    return 0;
}