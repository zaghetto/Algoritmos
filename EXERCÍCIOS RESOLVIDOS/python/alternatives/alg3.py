# Algoritmo 3


def main():

    x = int(input("x: "))
    y = int(input("y: "))

    if x == 0 and y == 0:
        print("Origin")
    elif x == 0 and y != 0:
        print("Y axis")
    elif x != 0 and y == 0:
        print("X axis")
    elif x > 0 and y > 0:
        print("Q1")
    elif x < 0 and y > 0:
        print("Q2")
    elif x < 0 and y < 0:
        print("Q3")
    elif x > 0 and y < 0:
        print("Q4")


if __name__ == "__main__":
    main()
