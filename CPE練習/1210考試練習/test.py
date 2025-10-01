Case = 0
while True:
    Case += 1
    # input
    Line, Amount = map(int, input().split())
    Array = [["." for i in range(Amount)] for j in range(Line)]
    for i in range(int(Line)):
        Array[i] = list(input())
 
    if Line == 0 and Amount == 0:
        break
    # do something here
    for i in range(Line):
        for j in range(Amount):
            if Array[i][j] != "*":
                a = 0
                for m in range(i - 1, i + 2):
                    for n in range(j - 1, j + 2):
                        if (0 <= m < Line) and (0 <= n < Amount) and (m != i and n != j):
                            if Array[m][n] is "*":
                                a += 1
                if 0 <= i + 1 < Line:
                    if Array[i + 1][j] is "*":
                        a += 1
                if 0 <= i - 1 < Line:
                    if Array[i - 1][j] is "*":
                        a += 1
                if 0 <= j + 1 < Line:
                    if Array[i][j + 1] is "*":
                        a += 1
                if 0 <= j - 1 < Line:
                    if Array[i][j - 1] is "*":
                        a += 1
                Array[i][j] = a
    # output
    print(f"Field #{Case}:")
    for i in range(Line):
        for j in range(Amount):
            print(Array[i][j], end="")
        print("")
 