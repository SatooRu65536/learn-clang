import random

def main():
    n_list = [i for i in range(100)]
    random.shuffle(n_list)
    with open("numlist.txt", "w") as f:
        [f.write(str(n) + "\n") for n in n_list]


if __name__ == "__main__":
    main()
