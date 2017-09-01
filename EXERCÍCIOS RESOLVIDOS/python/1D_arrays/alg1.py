#Algorithm 01


def main():

    vet = []

    for i in range(0, 10):
        var = int(input("Enter value: "))
        if var > 0:
            vet.append(var)
        else:
            vet.append(1)

    for i in range(0, 10):
        print ("X[%i] = %i" %(i, vet[i]))


if __name__ == "__main__":
    main()









