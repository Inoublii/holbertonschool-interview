#!/usr/bin/python3
""" Given an n x n 2D matrix, rotate it 90 degrees clockwise """


def rotate_2d_matrix(matrix):
    """ Given an n x n 2D matrix, rotate it 90 degrees clockwise """
    x = len(matrix)
    lists = []
    for i in range(x):
        sub = []
        for q in range(x):
            sub.append(matrix[i][q])
        lists.append(sub)
    for i in range(x):
        for q in range(x):
            matrix[i][q] = lists[x - q - 1][i]
