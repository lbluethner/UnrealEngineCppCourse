#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty - 1;
    std::cout << " secure server room...\nEnter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    int NumberA = rand() % Difficulty + Difficulty;
    int NumberB = rand() % Difficulty + Difficulty;
    int NumberC = rand() % Difficulty + Difficulty;

    int NumberSum = NumberA + NumberB + NumberC;
    int NumberProduct = NumberA * NumberB * NumberC;

    // Print NumberSum and CodeProduct to the terminal
    std::cout << "+ There are three numbers in the code";
    std::cout << "\n+ The numbers in the code add-up to give: " << NumberSum;
    std::cout << "\n+ The numbers in the code multiply to give: " << NumberProduct << std::endl;

    // Store player's guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the player's guess is correct
    if (GuessSum == NumberSum && GuessProduct == NumberProduct)
    {
        std::cout << "\n*** Well done agent! You have extracted a file! Keep going! ***";
        return true;
    }
    else
    {
        std::cout << "\n*** You entered the wrong code! Carefule agent! Try again! ***";
        return false;
    }
}

int main()
{
    srand(time(NULL)); // create a new random sequence based on the time of day

    int LevelDifficulty = 2;
    const int MaxLevelDifficulty = 5;

    while (LevelDifficulty <= MaxLevelDifficulty) // Loop game until all levels are complte
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }

    std::cout << "\n*** Great work agent! You got all the files! Now get out of there! ***\n";
    
    return 0;
}