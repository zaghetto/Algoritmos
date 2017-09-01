#Algorithm 02


def main():

    Nini = int(input("N: "))
    vet = []

    for i in range(0, 10):
        vet.append((2 ** i) * Nini)

    for i in range(0, 10):
        print("N[%d] = %d " %(i, vet[i]))

if __name__ == "__main__":
    main()
