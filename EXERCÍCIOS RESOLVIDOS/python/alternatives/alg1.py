# Algoritmo 1


def main():

    A = int(input("A: "))
    B = int(input("B: "))
    C = int(input("C: "))
    D = int(input("D: "))

    if  B > C and D > A and (C + D) > (A + B) and C > 0 and D > 0 and (A % 2) == 0:
        print("Values accepted.")
    else:
        print("Values rejected.")


if __name__ == "__main__":
    main()


