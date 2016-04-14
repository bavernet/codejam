# problem: https://algospot.com/judge/problem/read/JAEHASAFE
# hint: string, kmp
# level: moderate
def getDistance(target, source):
    n = len(target)
    n2 = n * 2
    source *= 2
    fail = [-1] * n
    for i in xrange(1, n):
        j = fail[i-1] + 1
        while target[i] != target[j] and j > 0:
            j = fail[j-1] + 1
        if target[i] == target[j]:
            fail[i] = j

    i = j = 0
    while i < n2 and j < n:
        while source[i] != target[j] and j > 0:
            j = fail[j-1] + 1
        if source[i] != target[j]:
            j = -1
        i += 1
        j += 1
    return i - n

def getCountToUnlock(dials):
    cnt = 0
    n = len(dials)
    for i in xrange(1, n):
        if i & 1:
            cnt += getDistance(dials[i-1], dials[i])
        else:
            cnt += getDistance(dials[i], dials[i-1])
    return cnt

if __name__ == '__main__':
    nTests = input()
    while nTests > 0:
        nTests -= 1
        n = input()
        dials = [ raw_input() for _ in xrange(n + 1) ]
        print getCountToUnlock(dials)
