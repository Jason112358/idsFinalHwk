num = 0
with open("../Data/top-1m.txt") as inputFile:
	for line in inputFile:
		line = line.strip()
		info = line.split(",")
		with open("../Data/notDga.txt","a") as outputFile:
			print(info[1]+",notdga",file = outputFile)
			num += 1
print(str(num)+"Done")
