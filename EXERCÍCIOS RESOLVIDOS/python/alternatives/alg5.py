# Algoritmo 5


def main():
    i = int(input("i: "))
    f = int(input("f: "))

    hours = 0
    if f > i:
        hours = f - i
    else:
        hours = (24 - i) + f

    print("The game took %i hours." % hours)

if __name__ == "__main__":
    main()
