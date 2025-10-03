#include <iostream>
#include <vector>

enum class Piece {empty, black, white};
enum class Status {ongoing, blackWins, whiteWins, draw};

void gameRules ()
{
    std::cout << "====================== Gomoku Rules ======================" << '\n';
    std::cout << "\nObjective of Gomoku - The first player to form an unbroken line of five stones in any direction wins the game." << '\n';
    std::cout << "\nPlayers will alternate placing stone pieces on the board. The player using black stones will always go first." << '\n';
    std::cout << "Once a player has places a stone piece on the board it connot be moved or removed for the duration of the game." << '\n';
    std::cout << "==========================================================" << '\n';
}   

std::vector<std::vector<Piece>> makeBoard (int rows, int columns)
{
    return std::vector<std::vector<Piece>>(rows, std::vector<Piece>(columns, Piece::empty));
}

void displayBoard(const std::vector<std::vector<Piece>>& board)
{
    std::cout << '\n';
    int columns = 15;
    int rows = 15;

    for (int columnHeaders = 0; columnHeaders <= columns - 6; columnHeaders++)
    {
        std::cout << "  " << columnHeaders + 1 << " ";
    }

    for (int columnHeaders = 10; columnHeaders <= columns - 1; columnHeaders++)
    {
        std::cout << " " << columnHeaders + 1 << " ";
    }
    
    std::cout << '\n';

    for (int rowHeaders = 0; rowHeaders <= rows - 1; rowHeaders++)
    {
        std::cout << rowHeaders + 1 << '\n';
    }

    for (const auto& row : board){
        for (const auto& cell : row)
        {
           //working here
            if (cell == Piece::empty) std::cout << " [] ";
            else if (cell == Piece::black) std::cout << " B ";
            else if (cell == Piece::white) std::cout << " W ";
        }
        std::cout << '\n';
    }
}

int main()
{
    gameRules();
    auto board = makeBoard(15,15);
    displayBoard(board);

    return 0;
}