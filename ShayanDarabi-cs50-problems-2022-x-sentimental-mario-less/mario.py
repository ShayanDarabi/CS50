# TODO

while True:
    try:
        height = int(input("Height: "))
        if height > 0 and height <= 8:
            break
    except ValueError:
        continue

for row in range(height):
    print(" " * (height - 1 - row), end="")
    print("#" * (row + 1), end="\n")