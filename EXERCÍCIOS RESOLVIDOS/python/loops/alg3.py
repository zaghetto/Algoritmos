# Algorithm 3


def main():

    n = int(input("N? "))
    for i in range(0, n):
        x = int(input("X? "))
        y = int(input("Y? "))
        soma = 0
        if x < y:
            for j in range((x + 1), y):
                if (j % 2) != 0:
                    soma = soma + j
        else:
            for j in range((y + 1), x):
                if (j % 2) != 0:
                    soma = soma + j
        print("Sum = " + str(soma))


if __name__ == "__main__":
    main()



