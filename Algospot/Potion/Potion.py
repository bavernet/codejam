# problem: https://algospot.com/judge/problem/read/POTION
# hint: math
# level: easy
from sys import stdin
from math import ceil

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def getGCD(recipe):
    ans = 0
    for r in recipe:
        ans = gcd(ans, r)
    return ans

def getNeeds(n, recipe, past):
    nPotions = base = getGCD(recipe)
    for k in xrange(n):
        recipe[k] /= base;
        nPotions = max(nPotions, int(ceil(float(past[k]) / recipe[k])))
    return [ recipe[k] * nPotions - past[k] for k in xrange(n) ]

if __name__ == '__main__':
    nTests = int(stdin.readline())
    while nTests:
        nTests -= 1
        n = int(stdin.readline())
        r = [ int(x) for x in stdin.readline().split() ]
        p = [ int(x) for x in stdin.readline().split() ]
        for need in getNeeds(n, r, p):
            print need,
        print ''
