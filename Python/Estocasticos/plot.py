import matplotlib.pyplot as plt
f = open("output.out")
x = []
y = []
colors = ["b", "r", "m", "g", "c", "#FFA500", "#8B0000", "#2F4F4F", "#8B4513"]
N = [1, 2, 5, 10, 20, 30, 50, 100, 200]
cnt = 0
for line in f:
    if line == "$\n":
        plt.plot(x, y, colors[cnt], label="n = {:d}".format(N[cnt]))
        x = []
        y = []
        print(cnt)
        cnt += 1
        continue
    ar = line.split(" ")
    x.append(ar[0])
    y.append(ar[1])
plt.ylabel(r"$\theta(p)$", fontsize=20)
plt.xlabel(r"$p$", fontsize=20)
plt.legend()
#plt.show()
plt.savefig("fig1.pdf")
