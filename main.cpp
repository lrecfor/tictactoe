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

/*����������� ���� Gomoku (��������-������).
����������, ��� �������, ��� ������: Board, BoardView.
��� ������������� ����� ������������ ConsoleGraphic.h � ConsoleGraphic.cpp, �������� ��������������,
���� ������������ ����� ���������� 2D ������� C++ �� ���� �����.

! ������, ��� ������ Model ������� ������������ ���������� � ������ ������.*/