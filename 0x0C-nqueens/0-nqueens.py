#!/usr/bin/python3
""" app solves the N queens problem
"""
import sys


def valid(chess, x, a):
    """ Validating That The Queen Placement is Correct """
    for i in range(x):
        if(chess[i] == a):
            return False
        if(chess[i] + x - i == a):
            return False
        if(chess[i] + i - x == a):
            return False
    return True


def add(Board, x):
    """ fills each line with  index
    """
    for i in range(len(Board)):
        if valid(Board, x, i):
            Board[x] = i
            if x < len(Board) - 1:
                add(Board, x + 1)
            else:
                print([[i, Board[i]] for i in range(len(Board))])


def main():
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    try:
        n = int(sys.argv[1])
    except:
        print("N must be a number")
        sys.exit(1)
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    Board = [-1 for i in range(n)]
    add(Board, 0)

main()
