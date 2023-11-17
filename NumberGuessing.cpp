#include <bits/stdc++.h>
using namespace std;
void hint1(int number)
{
    if (number % 2 == 0)
    {
        cout << "1. It is Even" << endl;
    }
    else
    {
        cout << "1. It is odd" << endl;
    }
}
void hint2(int number, int ub)
{
    int mid = ub / 2;
    if (number > mid)
    {
        cout << "2. The number lies between " << mid << " to " << ub << endl;
    }
    else
    {
        cout << "2. The number lies between 1 and " << mid - 1 << endl;
    }
}
void hint3(int number)
{
    cout << "3. The last digit of the number is: " << number % 10 << endl;
}
void hint4(int number, int answer)
{
    if (answer - number > 0)
    {
        cout << "4. Your guessed value is greater than actual" << endl;
    }
    else
    {
        cout << "4. Your guessed value is lesser than actual\n";
    }
}
int game(int ub)
{
    int lb = 1,
        srand(time(0));
    int randomNumber = (rand() % (ub - lb + 1)) + lb;
    int attempt = 3, flag = 0;
    int GuessNumber = 0;
    while (attempt != 0)
    {
        cout << "Guess the number between " << lb << " and  " << ub << endl;
        cin >> GuessNumber;
        if (GuessNumber == randomNumber)
        {
            flag = 1;
            break;
        }
        else
        {
            cout << "Wrong guess! Try again!" << endl;
            cout << "************************HINTS***************************************" << endl;
            hint1(randomNumber);
            hint2(randomNumber, ub);
            hint3(randomNumber);
            hint4(randomNumber, GuessNumber);
            flag = 0;
            --attempt;
        }
        cout << endl;
        cout << "Your Attempt remaining :" << attempt << endl;
    }
    cout << "The answer was :" << randomNumber << endl;
    return flag;
}
int main()
{
    char choice;
    int lb = 1, ub;
    do
    {
        cout << "Enter the range you want to guess the number from 1 - ";
        cin >> ub;
        int flag = game(ub);
        if (flag == 1)
        {
            cout << "\nYou won ! Congrats on winning this game." << endl;
        }
        cout << "\nDo you wanna try again !?" << endl;
        cout << "[Y/N]\n";
        cin >> choice;
    } while (choice != 'N' && choice != 'n');

    return 0;
}