# Algoritmo 3


def main():

    name = input("Name: ")
    salary = int(input("Salary: "))
    sells = int(input("Sells: "))

    total = salary + (sells * 0.15)

    print("TOTAL = R$ %.2lf" % total)


if __name__ == "__main__":
    main()