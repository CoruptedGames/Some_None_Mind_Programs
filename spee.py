import random
import os

def create_grid(n):
    return [[0 for _ in range(n)] for _ in range(n)]

def add_random(grid, n):
    empty = [(i, j) for i in range(n) for j in range(n) if grid[i][j] == 0]

    if empty:
        i, j = random.choice(empty)
        grid[i][j] = 2

def show(grid, n):
    os.system("cls" if os.name == "nt" else "clear")

    print("\n2048 GAME\n")
    for i in range(n):
        print("|", end="")
        for j in range(n):
            print(f"{grid[i][j]:5}", end="|")
        print()

def game_over(grid, n):
    for i in range(n):
        for j in range(n):
            if grid[i][j] == 0:
                return False

    for i in range(n):
        for j in range(n - 1):
            if grid[i][j] == grid[i][j + 1]:
                return False

    for j in range(n):
        for i in range(n - 1):
            if grid[i][j] == grid[i + 1][j]:
                return False

    return True


def move_left(grid, n):
    for row in range(n):
        new = [x for x in grid[row] if x != 0]

        merged = []
        skip = False

        for i in range(len(new)):
            if skip:
                skip = False
                continue

            if i + 1 < len(new) and new[i] == new[i + 1]:
                merged.append(new[i] * 2)
                skip = True
            else:
                merged.append(new[i])

        merged += [0] * (n - len(merged))
        grid[row] = merged


def move_right(grid, n):
    for row in range(n):
        grid[row].reverse()
        move_left(grid, n)
        grid[row].reverse()


def transpose(grid, n):
    return [[grid[j][i] for j in range(n)] for i in range(n)]


def move_up(grid, n):
    grid[:] = transpose(grid, n)
    move_left(grid, n)
    grid[:] = transpose(grid, n)


def move_down(grid, n):
    grid[:] = transpose(grid, n)
    move_right(grid, n)
    grid[:] = transpose(grid, n)


def main():
    n = int(input("Enter size (3+ recommended): "))

    grid = create_grid(n)

    add_random(grid, n)
    add_random(grid, n)

    while True:
        show(grid, n)

        if game_over(grid, n):
            print("\nGAME OVER!")
            break

        move = input("Move (WASD, Q=quit): ").lower()

        if move == "q":
            break
        elif move == "a":
            move_left(grid, n)
        elif move == "d":
            move_right(grid, n)
        elif move == "w":
            move_up(grid, n)
        elif move == "s":
            move_down(grid, n)
        else:
            continue

        add_random(grid, n)


if __name__ == "__main__":
    main()