# Algorithm 5


def main():
    N = [int]*6

    for i in range(0, 5):
        N[i] = int(input())

    N[5] = 0
    V = int(input())
    P = int(input())

    for i in range(0, 6):
        print("N[%d] = %d"%(i, N[i]))

    for i in range(5, P, -1):
        N[i] = N[i - 1]

    N[P] = V

    for i in range(0, 6):
        print("N[%d] = %d"%(i, N[i]))

if __name__ == "__main__":
    main()
