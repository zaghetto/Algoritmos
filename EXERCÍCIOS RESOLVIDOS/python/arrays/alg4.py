# Algorithm 4


def main():
    N = [int] * 5

    for i in range(0, 5):
        N[i] = int(input())

    X = int(input())

    for i in range(0, X):
        temp = N[4]

        for j in range(4, 0, -1):
            N[j] = N[j - 1]

        N[0] = temp

    for i in range(0, 5):
        print("N[%d] = %d" %(i, N[i]))

if __name__ == "__main__":
    main()
