from sklearn.ensemble import RandomForestClassifier
import numpy as np

domainlist = []
testdmlist = []
testlist = []
class Domain:
        def __init__(self,_name,_label):
                self.name = _name
                self.label = _label

        def returnData(self):
                vowelSum = 0
                consSum = 0
                others = 0
                digit = 0
                for letter in self.name:
                        if letter == 'a'or letter == 'e' or letter == 'i' or letter == 'o' or letter == 'u':
                                vowelSum = vowelSum + 1
                        elif letter != '.' and letter.isdigit() == False:
                                consSum = consSum + 1
                        elif letter.isdigit() == True:
                                digit += 1
                        else :
                                others += 1
                total = vowelSum + consSum
                ratio = float(vowelSum)/total
                return [ratio,total,digit,others]

        def returnLabel(self):
                if self.label == "notdga":
                        return 0
                else:
                        return 1

def initData(filename):
        with open(filename) as f:
                for line in f:
                        line = line.strip()
                        if line.startswith("#") or line =="":
                                continue
                        tokens = line.split(",")
                        name = tokens[0]
                        label = tokens[1]
                        domainlist.append(Domain(name,label))

def readTest(filename):
        with open(filename) as f:
                for line in f:
                        vowelSum = 0
                        consSum = 0
                        others = 0
                        digit = 0
                        line = line.strip()
                        if line.startswith("#") or line == "":
                                continue
                        for letter in line:
                                if letter == 'a'or letter == 'e' or letter == 'i' or letter == 'o' or letter == 'u':
                                        vowelSum =  vowelSum + 1
                                elif letter != '.' and letter.isdigit() == False:
                                        consSum = consSum + 1
                                elif letter.isdigit() == True:
                                        digit += 1
                                else :
                                        others += 1
                        total = vowelSum + consSum
                        ratio = float(vowelSum)/total
#                        print(line)
#                        print(str(ratio)+" "+str(total))
                        testdmlist.append(line)
                        testlist.append([ratio,total,digit,others])

def main():
        tmp = 0
        initData("bigtrain.txt")
        readTest("teachertest.txt")
        featureMatrix = []
        labelList = []
        for item in domainlist:
                featureMatrix.append(item.returnData())
                labelList.append(item.returnLabel())
        clf = RandomForestClassifier(random_state=0)
        clf.fit(featureMatrix,labelList)
        prelist = clf.predict(testlist)
        with open('result.txt','wt') as resfile:
                for each in prelist:
                    if each == 1:
                            print(testdmlist[tmp].strip()+",dga",file = resfile)
                    else:
                            print(testdmlist[tmp].strip()+",notdga",file = resfile)
                    tmp = tmp + 1

if __name__ == '__main__':
        main()
        print("FINISHED")
