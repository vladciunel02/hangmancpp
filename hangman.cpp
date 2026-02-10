#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cstring>
using namespace std;
void displayDetails(int remaining_tries);                              // also displays the hangman and the rules of the game
string getSecretWord();                                                // gets a random word from the list of words
void replaceDashes(char word[], int size);                             // replaces the dashes
void displayWord(char word[], int size);                               // displays the current state of the guessed word
int isGuessTrue(string secretWrd, char word[], int size, char letter); // checks if the guessed letter is in the secret word and updates the guessed word accordingly
void displayHangman(int remaining);                                    // displays the hangman based on the number of remaining tries
int main()
{
    int max_wrong = 5;
    int won = 0;
    int remaining_wrong = max_wrong;
    string secretWord;
    char guessletter;
    displayDetails(remaining_wrong);
    srand(time(0));
    secretWord = getSecretWord();
    char guessWord[secretWord.size() + 1];
    replaceDashes(guessWord, secretWord.size());
    guessWord[secretWord.size()] = '\0';
    cout << "Your word to guess is: " << endl;
    displayWord(guessWord, secretWord.size());
    while (remaining_wrong > 0)
    {
        cout << "Enter you letter" << endl;
        cin >> guessletter;
        if (isGuessTrue(secretWord, guessWord, secretWord.size(), guessletter) == 1)
        {
            cout << "Correct guess!" << endl;
            displayWord(guessWord, secretWord.size());
        }
        else
        {
            remaining_wrong--;
            displayHangman(remaining_wrong);
            cout << "Wrong guess! You have " << remaining_wrong << " tries remaining." << endl;
        }
        if (strcmp(guessWord, secretWord.c_str()) == 0)
        {
            won = 1;
            cout << "Congratulations! You guessed the word: " << endl;
            displayWord(guessWord, secretWord.size());
            break;
            return 0;
        }
    }
    if (won == 0)
    {
        cout << "You lost! The secret word was: " << secretWord << endl;
        displayHangman(0);
    }
    return 0;
}
void displayHangman(int remaining)
{
    switch (remaining)
    {
    case 5:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 4:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 3:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << "  |   |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 2:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << " /|   |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 1:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << " /|\\  |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 0:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << " /|\\  |" << endl;
        cout << " / \\  |" << endl;
        cout << "=========" << endl;
        break;
    default:
        break;
    }
}
int isGuessTrue(string secretWrd, char word[], int size, char letter)
{
    int ok = 0;
    for (int i = 0; i < size; i++)
    {
        if (secretWrd[i] == letter)
        {
            word[i] = letter;
            ok = 1;
        }
    }
    if (ok == 1)
    {
        return 1;
    }
    return 0;
}
void displayWord(char word[], int size)
{
    cout << word << endl;
}
void replaceDashes(char word[], int size)
{
    for (int i = 0; i < size; i++)
    {
        word[i] = '-';
    }
}
string getSecretWord()
{
    string wordList[] = {"programming", "hangman", "computer", "science", "cplusplus",
                         "algorithm", "data", "structure", "function", "variable", "pointer", "reference", "class", "object", "inheritance"};
    int wordCount = sizeof(wordList) / sizeof(wordList[0]);
    int index = rand() % wordCount;
    return wordList[index];
}
void displayDetails(int remaining_tries)
{
    cout << "Welcome to Hangman!" << endl;
    cout << "You have " << remaining_tries << " tries remaining." << endl;
    cout << "The rules of the game are as follows:" << endl;
    cout << "1. You will be given a secret word to guess." << endl;
    cout << "2. You can guess one letter at a time." << endl;
    cout << "3. If you guess a letter correctly, it will be revealed in the secret word." << endl;
    cout << "4. If you guess a letter incorrectly, you will lose a try." << endl;
    cout << "5. The game ends when you either guess the secret word correctly or run out of tries." << endl;
    cout << "Good luck!" << endl;
}