#!/usr/bin/python3
import sys

try:
    with open(sys.argv[1], 'r') as my_file:
        a = my_file.read().split("\n")
        for n in a[0:-1]:
            n = int(n)
            if n % 2 == 0:
                print("{}={}*2".format(n, int(n / 2)))
                continue
            c = True
            for i in range(3, int(n ** 0.5) + 1, 2):
                if (n % i == 0):
                    print("{}={}*{}".format(n, int(n / i), i))
                    c = False
                    break
            if c:
                print("{}={}*1".format(n, n))
except:
    sys.exit(1)
