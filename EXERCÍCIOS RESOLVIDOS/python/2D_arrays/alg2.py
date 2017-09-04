import random


def main():

    N = 3
    l = int(input("Row: "))
    m = [[None ]*N]*N

    opc = input("A(verage) or S(um)? ")
    print(opc)

    for i in range(0, N):
        for j in range(0, N):
            m[i][j] = random.randint(10)

    S = 0.0
    k = 1
    cont = 0
    for i in range(0, N):
        for j in range(k, N):
            S = S + m[i][j]
            cont += 1
        k=k+1


if __name__ == "__main__":
    main()