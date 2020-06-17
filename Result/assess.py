times = int(input("The sum of the results:"))
for tmp in range(4,times+1):
	inputFile = "./result"+str(tmp)+".txt"
	with open(inputFile) as result:
		num = 0
		correctNotdga = 0
		wrongNotdga = 0
		correctDga = 0
		wrongDga = 0
		for line in result:
			line = line.strip()
			hostinfo = line.split(",")
			label = hostinfo[1]
#			if num < 129194 :
			if num < 100 :
				if label == "notdga":
					correctNotdga += 1
				else:
					wrongNotdga += 1
			else:
				if label == "dga":
					correctDga += 1
				else:
					wrongDga += 1
			num += 1
	with open("./sum.txt","a") as outputFile:
		print(inputFile+":",file=outputFile)
		print("correctNotdga = "+str(correctNotdga),file=outputFile)
		print("wrongNotdga = "+str(wrongNotdga),file=outputFile)
		print("correctDga = "+str(correctDga),file=outputFile)
		print("wrongDga = "+str(wrongDga)+"\n",file=outputFile)

