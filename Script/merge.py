with open("../Data/dga.txt") as inputFile:
	with open("../Data/bigtrain.txt","a") as outputFile:
		for line in inputFile:
			print(line.strip(),file = outputFile)
