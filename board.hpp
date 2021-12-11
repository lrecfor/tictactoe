#pragma once

#include <vector>
#include <iostream>

enum class CELL_TYPE { NONE, KRESTIK, NOLIK };

enum class WIN_TYPE { NONE, KRESTIK, NOLIK, DRAW };

class Board
{
	const int size;
	std::vector<std::vector<CELL_TYPE>> field;
	WIN_TYPE game_status;

public:

	Board(int _size = 3) : size(_size)
	{
		field.resize(size);
		for (int i = 0; i < size; ++i)
		{
			field[i].resize(size, CELL_TYPE::NONE);
		}
		game_status = WIN_TYPE::NONE;
	}

	void remove_cells() {
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j) {
				field[i][j] = CELL_TYPE::NONE;
			}
		}
		game_status = WIN_TYPE::NONE;
	}

	int field_check() {
		int draw_ = 0;
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j) {
				if (field[i][j] != CELL_TYPE::NONE) { draw_++; }
			}
		}
		return draw_;
	}

	int get_size() const { return size; }

	CELL_TYPE get_cell(int i, int j) const
	{
		return field[i][j];
	}

	bool set_cell(unsigned int i, unsigned int j, CELL_TYPE cell_value)
	{
		if (i < size && j < size && field[i][j] == CELL_TYPE::NONE)
		{
			field[i][j] = cell_value;
			return true;
		}
		else
			return false;
	}

	WIN_TYPE get_status_game()
	{

		for (int i = 0; i < size; ++i) {

			if (field[0][i] == field[1][i] && field[0][i] == field[2][i] &&
				field[0][i] == CELL_TYPE::KRESTIK) return WIN_TYPE::KRESTIK;

			else if (field[0][i] == field[1][i] && field[0][i] == field[2][i] &&
				field[0][i] == CELL_TYPE::NOLIK) return WIN_TYPE::NOLIK;

			else if (field[i][0] == field[i][1] && field[i][0] == field[i][2] &&
				field[i][0] == CELL_TYPE::KRESTIK) return WIN_TYPE::KRESTIK;

			else if (field[i][0] == field[i][1] && field[i][0] == field[i][2] &&
				field[i][0] == CELL_TYPE::NOLIK) return WIN_TYPE::NOLIK;

			else if (field[0][2] == field[1][1] && field[0][2] == field[2][0] &&
				field[0][2] == CELL_TYPE::KRESTIK) return WIN_TYPE::KRESTIK;

			else if (field[0][2] == field[1][1] && field[0][2] == field[2][0] &&
				field[0][2] == CELL_TYPE::NOLIK) return WIN_TYPE::NOLIK;

			else if (field[0][0] == field[1][1] && field[0][0] == field[2][2] &&
				field[0][0] == CELL_TYPE::KRESTIK) return WIN_TYPE::KRESTIK;

			else if (field[0][0] == field[1][1] && field[0][0] == field[2][2] &&
				field[0][0] == CELL_TYPE::NOLIK) return WIN_TYPE::NOLIK;

			else if (field_check() == 9) return WIN_TYPE::DRAW;
		}

		return WIN_TYPE::NONE;
	}
};