from sys import stdin

def reverse(t):
    if t[0] != 'x':
        return t[0]
    s = list()
    cnt = 1
    for k in xrange(4):
        s.append(reverse(t[cnt:]))
        cnt += len(s[-1])
    return 'x' + s[2] + s[3] + s[0] + s[1]

if __name__ == '__main__':
    nTests = input()
    while nTests:
        nTests -= 1
        print reverse(stdin.readline().strip())
