number = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
b_sorted = b.copy()
b_sorted.sort(reverse=True)
a_sorted = a.copy()
a_sorted.sort()

s = 0
for i in range(number):
    s += a_sorted[i] * b_sorted[i]
print(s)