# Algoritmo 4


def main():
    a = int(input("a: "))
    b = int(input("b: "))

    if a % b == 0 or b % a == 0:
        print("Multiples")
    else:
        print("Not multiples")


if __name__ == "__main__":
    main()
