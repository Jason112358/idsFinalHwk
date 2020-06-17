import re

sum = 0
with open("../Data/360Dga.txt") as inputFile:
	for line in inputFile:
		if line.startswith("#") or line.startswith("\n"):
			continue
		line.strip()
		dgainfo = re.split(" |\t|\n",line)
		with open("../Data/dga.txt","a") as outputFile:
			print(dgainfo[1]+",dga",file = outputFile)
			sum = sum + 1
		if sum%10000 == 0:
			print(sum)
print(str(sum)+" Finished")
