import math

t = int(input())
for _ in range(t):
	a, b, c = map(int, input().split())
	x = c / a
	iter = 100
	for __ in range(iter):
		x -= ((a * x + b * math.sin(x) - c) / (a + b * math.cos(x)))
	print("%.6f" % x)