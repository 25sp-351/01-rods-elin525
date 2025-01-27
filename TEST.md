# Rod Cutting Test Cases

# test1: general value
Input:
50
10, 15
15, 25
20, 40

Expected Output:
2 @ 20 = 80
1 @ 10 = 15
Remainder: 0
Value: 95

# test2: short rod length
Input:
5
10, 10
15, 20

Expected Output:
Remainder: 5
Value: 0

# test3: exact fit
Input:
25
10, 10
15, 25

Expected Output:
1 @ 15 = 25
1 @ 10 = 10
Remainder: 0
Value: 35

# test4: no cutting possible
Input:
12
15, 20
30, 50

Expected Output:
Remainder: 12
Value: 0

# test5: best solution
Input:
40
10, 10
20, 25
40, 35

Expected Output:
2 @ 20 = 50
Remainder: 0
Value: 50

# test2: large rod length
Input:
100
10, 10
20, 25
50, 70

Expected Output:
2 @ 50 = 140
Remainder: 0
Value: 140