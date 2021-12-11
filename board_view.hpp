#pragma once

#include "board.hpp"
#include "ConsoleGraphic.hpp"

#include <iostream>
#include <conio.h>

enum class Players { KRESTIK, NOLIK, _COUNT };

class BoardView
{
	Board& board;
	Players current_player;

public:
	BoardView(Board& _board) : board(_board)
	{
		current_player = Players::KRESTIK;
	}

	void run()
	{
		setcolor(202);
		char choice = 'y';
		while (choice == 'y')
		{
			system("cls");
			//clrscr();
			draw();
        	input_move();
			current_player = static_cast<Players>((static_cast<int>(current_player)
				+ 1) % static_cast<int>(Players::_COUNT));

			if (board.get_status_game() == WIN_TYPE::KRESTIK) {
				system("cls");
				draw();
				std::cout << "Player <X> won!" << std::endl;
			}
			if (board.get_status_game() == WIN_TYPE::NOLIK) {
				system("cls");
				draw();
				std::cout << "Player <O> won!" << std::endl;
			}
			if (board.get_status_game() == WIN_TYPE::DRAW) {
				system("cls");
				draw();
				std::cout << "DRAW!" << std::endl;
			}

			if (board.get_status_game() != WIN_TYPE::NONE) {
				std::cout << "Dou you wanna play again? (y/n):";
				choice = _getch();
				board.remove_cells();
				current_player = Players::KRESTIK;
			}
		}
	}

	void input_move()
	{
		int x = -1, y = -1;
		char flag;
		int count = 0;
		CELL_TYPE cell_value = CELL_TYPE::NONE;
		do
		{
			if (current_player == Players::KRESTIK && count == 0) {
				std::cout << "Player <X> move(press q/w/e/a/s/d/z/x/c):" << std::endl;
				count++;
			}
			else if (current_player == Players::NOLIK && count == 0) {
				std::cout << "Player <O> move(press q/w/e/a/s/d/z/x/c):" << std::endl;
				count++;
			}
			flag = _getch();
			flag = toupper(flag);
			switch (flag) {
			case 'Q':
				x = 0;
				y = 0;
				break;
			case 'W':
				x = 1;
				y = 0;
				break;
			case 'E':
				x = 2;
				y = 0;
				break;
			case 'A':
				x = 0;
				y = 1;
				break;
			case 'S':
				x = 1;
				y = 1;
				break;
			case 'D':
				x = 2;
				y = 1;
				break;
			case 'Z':
				x = 0;
				y = 2;
				break;
			case 'X':
				x = 1;
				y = 2;
				break;
			case 'C':
				x = 2;
				y = 2;
				break;
			default:
				break;
			}
			if (current_player == Players::KRESTIK)
				cell_value = CELL_TYPE::KRESTIK;
			else if (current_player == Players::NOLIK)
				cell_value = CELL_TYPE::NOLIK;
		} while (board.set_cell(y, x, cell_value) == false);
	}

	void draw()
	{
		int size = board.get_size();
		char cell;
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				switch (board.get_cell(i, j))
				{
				case CELL_TYPE::NONE:
					cell = ' ';
					break;
				case CELL_TYPE::KRESTIK:
					cell = 'X';
					break;
				case CELL_TYPE::NOLIK:
					cell = 'O';
					break;
				default:
					break;
				}
				std::cout << cell;
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
};