# Algoritmo 2


def opt0(qtt):
    return 4.0 * qtt


def opt1(qtt):
    return 4.5 * qtt


def opt2(qtt):
    return 5.0 * qtt


def opt3(qtt):
    return 2.0 * qtt


def optgeral(qtt):
    return 1.5 * qtt


def main():

    options = {0: opt0, 1: opt1, 2: opt2, 3: opt3}

    opc = int(input("Option: "))
    qtt = int(input("Quantity: "))

    opcao = options.get(opc, optgeral)
    total = opcao(qtt)

    print("Total: U$ %.2f" % total)


if __name__ == "__main__":
    main()
