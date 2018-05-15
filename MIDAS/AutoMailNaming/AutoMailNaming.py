import sys

company = sys.stdin.readline()
name = sys.stdin.readline()

company = company.strip()
company = company.lower()
nameList = name.split(',')

resultList = []

nameDic = {}

for nameItem in nameList:
    idEmail = ''
    companyEmail = ''

    nameFML = []
    nameItem = nameItem.strip()
    nameItem = nameItem.lower()
    #print(nameItem)
    nameSplit = nameItem.split(' ')
    for splitItem in nameSplit:
        if(len(splitItem)):
            nameFML.append(splitItem)

    if(nameFML):
        #remove hipoon
        nameFML[-1] = nameFML[-1].replace("-","")
        idEmail += nameFML[-1]
        idEmail += nameFML[0][0]
        companyEmail += company
        if(idEmail in nameDic):
            nameDic[idEmail] += 1
        else:
            nameDic[idEmail] = 1

        if(nameDic[idEmail] ==1):
            resultList.append(idEmail+'@'+companyEmail+'.com')
        else:
            resultList.append(idEmail +str(nameDic[idEmail])+'@' + companyEmail + '.com')


for i in range(len(resultList)-1):
    print(resultList[i]+',')
print(resultList[-1])