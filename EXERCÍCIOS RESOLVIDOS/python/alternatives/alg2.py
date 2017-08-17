# Algoritmo 2


def main():

    opc = int(input("Option: "))
    qtt = int(input("Quantity: "))

    total = 0.0
    if opc == 1:
        total = 4.0 * qtt
    elif opc == 2:
        total = 4.5 * qtt
    elif opc == 3:
        total = 5.0 * qtt
    elif opc == 4:
        total = 2.0 * qtt
    else:
        total = 1.5 * qtt

    print("Total: U$ %.2f" % total)


if __name__ == "__main__":
    main()
