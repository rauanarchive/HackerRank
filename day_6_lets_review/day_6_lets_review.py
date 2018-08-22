import sys

if __name__ == '__main__':
    for line in sys.stdin:
        n = len(line)
        # print(n)
        for i in range (0,n,2):
            # print("even: i={}".format(i))
            sys.stdout.write(line[i])
        for i in range (1,n-1,2):
            # print("odd: i={}".format(i))
            sys.stdout.write(line[i])

        sys.stdout.write('\n')
