#include <exception>

#include "board.hpp"
#include "board_view.hpp"

int main()
{
	hidecursor();
	try
	{	
		Board board;
		BoardView board_view(board);
		board_view.run();
	}
	catch (const std::exception& ex)
	{
		// logging
	}
	catch (...)
	{
		// logging unknown exception
	}
	return 0;
}

/*Реализовать игру Gomoku (крестики-нолики).
Необходимы, как минимум, два класса: Board, BoardView.
Для псевдографики можно использовать ConsoleGraphic.h и ConsoleGraphic.cpp, выданные преподавателем,
либо использовать любую библиотеку 2D графики C++ на свой выбор.

! Помним, что модуль Model придётся впоследствии переносить в другой проект.*/