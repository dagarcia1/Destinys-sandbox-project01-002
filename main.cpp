#include <iostream>
#include <vector>
#include <string>

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
    std::cout << "\n  ";
    int rows = static_cast <int> (board.size());
    int columns = static_cast <int> (board[0].size());



    for (int columnHeaders = 0; columnHeaders < columns; columnHeaders++)
	{
		std:: cout << "   ";
	    if (columnHeaders < 9)
	    {
	        std::cout << "0" << columnHeaders + 1;
	    }
	    
	    else if (columnHeaders < 15)
	    {
	        std::cout << columnHeaders + 1;
	    }
	}
	

	for (int rowHeaders = 0; rowHeaders < rows; rowHeaders++)
	{
	    if (rowHeaders < 9)
	    {
	        std::cout << "\n" << "0" << rowHeaders + 1 << " ";
	    }
	    
	    else if (rowHeaders < 16)
	    {
	        std::cout << "\n" << rowHeaders + 1 << " ";
	    }
	    
	    for (const auto& cell:board[rowHeaders])
	        {
	            if (cell == Piece::empty) 
				{
					std::cout << " [ ] ";
				}
	            else if (cell == Piece::black) 
				{
					std::cout << "  B  ";
				}
	            else if (cell == Piece::white) 
				{
					std::cout << "  W  ";
				}
	        }
	}
	
	std::cout << "\n";
}

int getCount(const std::vector<std::vector<Piece>>& board)
{
	int count = 0;
	int rows = static_cast <int> (board.size());
	int columns = static_cast <int> (board[0].size());

	if (board.empty() || board[0].empty())
	{
		return 0;
	}

	for (const auto& rows : board)
	{
		for (const auto& cells : rows)
		{
			
			if (cells != Piece::empty)
			{
				count++;
			}
		}
	}

	//int totalCells = rows*columns;
	//int piecesOnBoard = totalCells - count;
	//int emptyCellsAmount = totalCells - count;
	

	//std::cout << "Amount of cells: " << totalCells << "\n";

	//std::cout << "Amount of empty cells: " << emptyCellsAmount << "\n";

	//std::cout << "Amount of Pieces on Board: " << piecesOnBoard << "\n";

	
	//return 0;

	return count;
}
		
Piece getPlayersTurn (const std::vector<std::vector<Piece>>& board)
{
	int count=getCount(board);
	if (count %2 == 0)
	{
		return Piece::black;
	}
	else 
	{
		return Piece::white;
	}
}



void play(std::vector<std::vector<Piece>>& board, int rows, int columns)
{
	if (board[rows][columns] == Piece::empty)
	{
		(board[rows][columns]) = getPlayersTurn(board);
	}
}

Status gameStatus(const std::vector<std::vector<Piece>>& board)
{
	int rows = static_cast <int> (board.size());
    int columns = static_cast <int> (board[0].size());

	if (board.empty() || board[0].empty())
	{
		return Status::ongoing;
	}

	//horizaontal
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c <= columns - 4; c++)
		{
			if (board[r][c] != Piece::empty &&
				board[r][c] == board[r][c + 1] &&
                board[r][c] == board[r][c + 2] &&
                board[r][c] == board[r][c + 3] &&
				board[r][c] == board[r][c + 4]) {
                return (board[r][c] == Piece::black) ? Status::blackWins : Status::whiteWins;
            }
        }
    }

	//vertical
	return Status::ongoing;
}



int main()
{
    gameRules();
    auto board = makeBoard(15,15);
    
	
	while(gameStatus(board) == Status::ongoing)
	{
		displayBoard(board);
		std::cout << "Players turn: ";

		if (getPlayersTurn(board) == Piece::black)
		{
			std::cout << "Black" << '\n';
		}

		else if (getPlayersTurn(board) == Piece::white)
		{
			std::cout << "White" << '\n';
		}

		int column;
		int row;

		std::cout << "Select column: ";
		std::cin >> column;

		std::cout << "Select row: ";
		std::cin >> row;

		play(board, row - 1, column - 1);
		
		

	}

	displayBoard(board);
	
	if (gameStatus(board) == Status::blackWins)
	{
		std::cout << "Black Wins!" << '\n';
	}

	else if (gameStatus(board) == Status::whiteWins)
	{
		std::cout << "White Wins!" << '\n';
	}

	else 
	{
		std::cout << "Cat wins the Game!" << '\n';
	}

	std::cout << (gameStatus(board) == Status::blackWins) ? "Black Wins!\n" : "White Wins!\n";
	

    return 0;
}