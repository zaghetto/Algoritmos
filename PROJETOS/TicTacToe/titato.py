import math
import numpy as np


def drawboard(screen, size_canvas, size_board, yertle, numCells):

    # Initial setup
    screen.title("Welcome to the jungle!")
    ScreeWidth = size_canvas
    ScreeHeitht = ScreeWidth
    screen.setup(ScreeWidth, ScreeHeitht)
    l_board = size_board

    # Point to the beginning of the board
    yertle.penup()
    Y_Origin = l_board/2
    X_Origin = -Y_Origin
    yertle.setposition(X_Origin, Y_Origin)
    yertle.pendown()

    # Draw the limits of the board
    for i in [0, 1, 2, 3]:  # repeat four times
        yertle.forward(l_board)
        yertle.left(-90)

    # Draw the grid
    yertle.left(-90)
    direc = 1
    lines = [x for x in range(2,2*numCells,2) for y in range(2)]
    for i in lines:
        if direc == 1:
            pos = [X_Origin + direc*int(i) * abs(X_Origin) / numCells, Y_Origin]
        else:
            pos = [X_Origin, Y_Origin + direc * int(i) * abs(Y_Origin) / numCells]

        drawLine(pos, 0, l_board, yertle, 4, (0.6, 0.2, 0.2))
        yertle.left(direc*90)
        direc = - direc

    # Write coordinates to help player
    writeCoords(numCells, X_Origin, Y_Origin, l_board, yertle)


def drawLine(pos, ang, l_board, yertle, linewidth, cor):
    yertle.pencolor(cor)
    yertle.width(linewidth)
    yertle.penup()
    yertle.setposition(pos)
    yertle.pendown()
    yertle.left(ang)
    yertle.forward(l_board)


def writeCoords(numCells, X_Origin, Y_Origin, l_board, yertle):

    yertle.width(2)
    tup = (0.2, 0.6, 0.2)
    yertle.pencolor(tup)
    valid_positions = []
    radius = 5

    for i in range(numCells):
        for j in range(numCells):
            aux = [X_Origin+l_board/(2*numCells) + j*l_board/numCells,
                   Y_Origin-l_board/(2*numCells) - i*l_board/numCells]
            yertle.penup()
            yertle.setposition(aux)
            yertle.pendown()
            yertle.dot(radius)
            yertle.write((i,j))


def drawSimb(yertle, player, pos, radius, cor):

    if player == 1:
        drawCirc(yertle, pos, radius, cor)
    else:
        drawX(yertle, pos, radius, cor)


def drawX(yertle, pos, radius, cor):

    yertle.pencolor(cor)

    poso = pos
    pos[0] = pos[0] - (radius / math.sqrt(2)) / 2
    pos[1] = pos[1] + radius
    pos[1] = pos[1] - (radius / math.sqrt(2)) / 2

    yertle.penup()
    yertle.setposition(pos)
    yertle.pendown()
    yertle.left(45)
    yertle.forward(radius)

    poso[0] = poso[0] + (radius / math.sqrt(2))
    poso[1] = poso[1]

    yertle.penup()
    yertle.setposition(pos)
    yertle.pendown()
    yertle.left(90)
    yertle.forward(radius)


def drawCirc(yertle, pos, radius, cor):
    yertle.pencolor(cor)
    yertle.penup()
    yertle.setposition(pos)
    yertle.pendown()
    yertle.circle(radius)


def verifywin(board, player, pos):

    board = np.array(board)

    victoryCheck1 = False
    victoryCheck2 = False
    victoryCheck3 = False
    victoryCheck4 = False

    # Verify line of last play
    linha = board[pos[0]]
    victoryCheck1 = verifyRow(player, linha)
    print("v1: " + str(victoryCheck1))

    # Transpose board and do the same
    aux = pos[1]
    pos[1] = pos[0]
    pos[0] = -aux+2
    board = np.rot90(board)

    linha = board[pos[0]]
    victoryCheck2 = verifyRow(player, linha)
    print("v2: " + str(victoryCheck2))

    # Verify if move was in the center
    if pos == [0, 0] or pos == [1, 1] or pos == [2, 2]\
            or pos == [0, 2] or pos == [2, 0]:
        linha = [board[0, 2], board[1, 1], board[2, 0]]
        victoryCheck3 = verifyRow(player, linha)
        print("v3: " + str(victoryCheck3))

        linha = [board[0, 0], board[1, 1], board[2, 2]]
        victoryCheck4 = verifyRow(player, linha)
        print("v4: " + str(victoryCheck4))

    victory = victoryCheck1 or victoryCheck2 or victoryCheck3 or victoryCheck4

    return victory


def verifyRow(player, linha):

    print(player)
    print(linha)

    for jogada in range(len(linha)):
        if linha[0] == player and linha[0] == linha[1] and linha[1] == linha[2]:
            return True
        return False


def fullBoard(board):

    for i in range(0, 3):
        for j in range(0, 3):
            if board[i][j] == 0:
                return False
    return True
