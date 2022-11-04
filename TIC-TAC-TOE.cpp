// TIC TAC TOE GAME IN C++

#include <iostream>
#include <conio.h>
#include <process.h>

using namespace std;

void display();
char arr[3][3];

void init()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            ::arr[i][j] = '-';
    }
    cout << "\n";
    for (i = 0; i < 3; i++)
    {
        cout << "\n\n\n\t\t\t\t";
        for (j = 0; j < 3; j++)
            cout << ::arr[i][j] << "\t";
        cout << "\n";
    }
}
void input(char ch)
{
    int i, j;
err:
    cout << "\nRow:";
    cin >> i;
    cout << "\nColumn:";
    cin >> j;
    if (i < 1 || i > 3 || j < 1 || j > 3)
    {
        cout << "Please enter the values between 1 & 3";
        goto err;
    }
    else
    {
        i--;
        j--;
        if (::arr[i][j] == '-')
            ::arr[i][j] = ch;
        else
        {
            cout << "The chosen place is already full. ";
            cout << "Please choose a blank one......";
            goto err;
        }
        display();
    }
}
void display()
{
    int i, j;
    cout << "\n";
    for (i = 0; i < 3; i++)
    {
        cout << "\n\n\n\t\t\t\t";
        for (j = 0; j < 3; j++)
            cout << ::arr[i][j] << "\t";
        cout << "\n";
    }
}
void check()
{
    int i, j;
    if (::arr[0][0] == ::arr[1][1] && ::arr[1][1] == ::arr[2][2] && ::arr[0][0] != '-')
    {
        if (::arr[0][0] == 'X')
            cout << "\n\n\n\n\n\t\t\t\tCongratulations, Player 1 Wins";
        else if (::arr[0][0] == '0')
            cout << "\n\n\n\n\n\t\t\t\tCongratulations, Player 2 Wins";

        getch();

        exit(0);
    }
    else if (::arr[0][2] == ::arr[1][1] && ::arr[1][1] == ::arr[2][0] && ::arr[1][1] != '-')
    {
        if (::arr[1][1] == 'X')
            cout << "\n\n\n\n\n\t\t\t\tCongratulations, Player 1 Wins";
        else if (::arr[1][1] == '0')
            cout << "\n\n\n\n\n\t\t\t\tCongratulations, Player 2 Wins";

        getch();

        exit(1);
    }
    else
        for (i = 0; i < 3; i++)
        {
            if (::arr[i][0] == ::arr[i][1] && ::arr[i][1] == ::arr[i][2] && ::arr[i][0] != '-')
            {
                if (::arr[i][0] == 'X')
                    cout << "\n\n\n\n\n\t\t\t\tCongratulations, Player 1 Wins";
                else if (::arr[i][0] == '0')
                    cout << "\n\n\n\n\n\t\t\t\tCongratulations, Player 2 Wins";

                getch();

                exit(2);
            }
        }
    for (i = 0; i < 3; i++)
    {
        if (::arr[0][i] == ::arr[1][i] && ::arr[1][i] == ::arr[2][i] && ::arr[0][i] != '-')
        {
            if (::arr[0][i] == 'X')
                cout << "\n\n\n\n\n\t\t\t\tCongratulations, Player 1 Wins";
            else if (::arr[0][i] == '0')
                cout << "\n\n\n\n\n\t\t\t\tCongratulations, Player 2 Wins";

            getch();

            exit(3);
        }
    }
}

void instruct()
{
    cout << "TIC-TAC-TOE:-" << endl;
    cout << "\n";
    cout << "\n\n\n\t\t\t HAPPY PLAYING";
}

int main()
{
    instruct();
    cout << "\n\n\n\nPress any key to continue.......";

    getch();
    init();
    int c = 0;
    while (c < 9)
    {
        cout << "\n\n\nPlayer1(X):";
        cout << "Enter your choice:";
        input('X');
        c++;
        check();
        if (c >= 9)
            break;
        cout << "\n\n\nPlayer2(0):";
        cout << "Enter your choice:";
        input('0');
        c++;
        check();
    }
    cout << "\n\n\n\t\t\t\tSorry,no places left......";
    cout << "\n\n\n\t\t\t\tThe Game has ended in a DRAW!!!!";

    getch();
    return 0;
}
