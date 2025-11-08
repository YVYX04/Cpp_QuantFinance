/*
multi_array.cpp
This file is part of a project that demonstrates the use of multi-dimensional arrays with Boost.
The reader should note that multi arrays are especially useful for representing grids or matrices
and are widely used in lattice methods such as binary lattice models for option pricing. Here, we
are only showcasing a simple 2D array (matrix) implementation but Boost.MultiArray supports arrays
of arbitrary dimensions.

Author: Yvan Richard
Date: Fall 2025
*/

#include <iostream>
#include <boost/multi_array.hpp>

boost::multi_array<int, 2> CreateBoard(size_t n = 3, size_t m = 3);
void PrintBoard(const boost::multi_array<int, 2>& board);

int main()
{
    // Create Board
    boost::multi_array<int, 2> board = CreateBoard();

    // Print initial board
    PrintBoard(board);

    return 0;
}

void PrintBoard(const boost::multi_array<int, 2>& board)
{
    for (size_t i = 0; i < board.shape()[0]; ++i)
    {
        for (size_t j = 0; j < board.shape()[1]; ++j)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

boost::multi_array<int, 2> CreateBoard(size_t n, size_t m)
{
    boost::multi_array<int, 2> board{boost::extents[n][m]};
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j)
        {
            board[i][j] = 0;
        }
    }
    return board;
}