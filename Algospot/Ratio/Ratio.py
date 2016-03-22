# problem: https://algospot.com/judge/problem/read/RATIO
# hint: math
# level: easy
from sys import stdin
from math import ceil

def getCount(total, win):
    ratio = 100 * win / total
    if ratio >= 99:
        return -1

    needs = (ratio + 1) * total - 100 * win
    needs = int(ceil(float(needs) / (99 - ratio)))
    return needs

if __name__ == '__main__':
    nTests = input()
    for line in stdin:
        n, m = [int(x) for x in line.split()]
        print getCount(n, m)
