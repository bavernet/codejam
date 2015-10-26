# problem: http://community.topcoder.com/stat?c=problem_statement&pm=14075&rd=16552
# hint: implementation
# level: easy
class SetPartialOrder:
    def compareSets(self, a, b):
        ge = all([item in a for item in b])
        le = all([item in b for item in a])
        if ge and le:
            return "EQUAL"
        elif le:
            return "LESS"
        elif ge:
            return "GREATER"
        return "INCOMPARABLE"

if __name__ == "__main__":
    nTests = input()
    while nTests:
        nTests = nTests - 1
        na, nb = raw_input().split()
        a = raw_input().split()
        b = raw_input().split()
        print SetPartialOrder().compareSets(a, b)
