'''
Create a Tic Tac Toe game. You are free to use any IDE you like.

Here are the requirements:

1. 2 players should be able to play the game (both sitting at the same computer)
2. The board should be printed out every time a player makes a move
3. You should be able to accept input of the player position and then place a symbol on the board
'''


from turtle import *
import titato


def main():

    # Colors
    cores = [(0.2, 0.6, 0.2), (0.2, 0.2, 0.6)]

    # Board setup
    screen = Screen()
    size_canvas = 512
    size_board = 400
    numCells = 3

    # Origin
    Y_Origin = size_board / 2
    X_Origin = -Y_Origin

    # Create turtle
    yertle = Turtle(shape="classic", visible=False)
    yertle.hideturtle()
    yertle.speed(0)

    # Draw board
    titato.drawboard(screen, size_canvas, size_board, yertle, numCells)

    # Initialize board
    board = [[0 for i in range(numCells)] for i in range(numCells)]

    user = 0

    # While game is not over
    over = False
    count = 0
    while not over:

        player = 1+user % 2

        if player == 1:
            radius = 150/numCells
        else:
            radius = 300/numCells

        if not titato.fullBoard(board):

            # Ask for new valid position
            while True:

                print("User:" + str(player))

                x = int(input("Type row:"))
                y = int(input("Type column:"))

                yertle.setheading(0)
                pos = [X_Origin + size_board / (2 * numCells) + y*size_board/(numCells),
                       Y_Origin - size_board / (2 * numCells)-radius - x*size_board/(numCells)]

                if board[x][y] == 0:
                    board[x][y] = player
                    titato.drawSimb(yertle, player, pos, radius, cores[player-1])
                    count += 1
                    if titato.verifywin(board, player, [x, y]):
                        over = True
                        print("Victory! Player " + str(player) + "." )
                    break
                else:
                    print("Posição já ocupara, jogue novamente!")

            user += 1
            # print(board)
        else:
            over = True
            print("Empate!")

    screen.exitonclick()


if __name__ == "__main__":
    main()




