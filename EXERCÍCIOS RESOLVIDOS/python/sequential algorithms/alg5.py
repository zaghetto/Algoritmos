# Algoritmo 5


def main():

    n = int(input("Employee number: "))
    h = int(input("Hours worked: "))
    s = int(input("Money per hour: "))

    sal = h*s

    print("NUMBER = %i" % n)
    print("SALARY = U$ %.2f" % sal)


if __name__ == "__main__":
    main()