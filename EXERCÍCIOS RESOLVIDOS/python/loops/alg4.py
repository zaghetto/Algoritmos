# Algorithm 4


def main():
    cont = final = 0
    while cont < 2:
        grade = float(input("Grade " + str(cont) + ": "))
        if grade < 0 or grade > 10:
            print("Invalid!")
        else:
            final = final + grade
            cont = cont + 1

    media = final / 2
    print("Final grande = %.2f" % media)


if __name__ == "__main__":
    main()
