import random


def main():

    l = int(input("Row: "))
    m = [[None ]*3 ]*3

    opc = input("A(verage) or S(um)? ")
    print(opc)

    for i in range(0, 3):
        for j in range(0, 3):
            m[i][j] = random.random()

    S = 0.0
    for j in range(0, 3):
        S = S + m[l][j]

    if opc == 'S':
        print("%.2lf" % S)
    elif opc == 'A':
        S = S / 3
        print("%.2lf" % S)
    else:
        print("Invalid option!")

if __name__ == "__main__":
    main()