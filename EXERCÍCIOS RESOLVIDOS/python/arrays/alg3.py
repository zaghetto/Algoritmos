# Algorithm 3


def main():
    N = [-1] * 100
    F = [0] * 100

    for i in range(0, 100):
        V = int(input())
        if V < 0:
            break
        else:
            N[i] = V
            F[V] += 1

    for i in range(0, 100):
        if F[i] != 0:
            print("Frequencia de %d = %d" %(i, F[i]))

if __name__ == "__main__":
    main()
