# problem: https://algospot.com/judge/problem/read/SUSHI
# hint: dp
# level: easy
from sys import stdin

CACHE_SIZE = 0xFF
cache = [0] * (CACHE_SIZE + 1)

def index(a):
    return (a & CACHE_SIZE)

def getMaxScore(menu, money):
    cache[0] = 0
    for budget in xrange(1, money + 1):
        score = 0
        for price, pref in menu:
            if price <= budget:
                score = max(score, cache[index(budget - price)] + pref)
        cache[index(budget)] = score
    return cache[index(money)]

if __name__ == '__main__':
    nTests = int(stdin.readline())
    while nTests:
        nTests -= 1
        n, m = map(int, stdin.readline().split())
        menu = list()
        for i in xrange(n):
            food = map(int, stdin.readline().split())
            food[0] /= 100
            menu.append(food)
        print getMaxScore(menu, m / 100)
