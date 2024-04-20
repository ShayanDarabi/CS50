# TODO
from cs50 import get_float

while True:
    try:
        change = get_float("Change owed: ")
        if change < 0:
            continue
        break
    except:
        continue

# declare variables
total, count = change * 100, 0
# calculate count of coins
for x in [25, 10, 5, 1]:
    while total >= x:
        total -= x
        count += 1
# print result
print(f"{count}")

