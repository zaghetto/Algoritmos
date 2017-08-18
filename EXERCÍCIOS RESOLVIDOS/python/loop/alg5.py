# Algorithm 5


def main():

    N = int(input("N? "))

    fat = 1
    for i in range(2, (N + 1)):
        fat = fat * i

    print("Fatorial = " + str(fat))


if __name__ == "__main__":
    main()











