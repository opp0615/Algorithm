import sys

def DesToBinList(value):
    binList = []
    while (value>1):
        if(value%2 == 0):
            binList.insert(0,0)
        else:
            binList.insert(0,1)

        value = int(value/2)

    binList.insert(0,1)
    return binList

def activeCheck(inputList,activateList):
    minSize = len(inputList)
    windowSize = len(activateList)
    isSet = False
    setIndex = []
    for i in range(len(inputList) - windowSize + 1):
        if (inputList[i] == activateList[0]
                and inputList[i + 1] == activateList[1]
                and inputList[i + 2] == activateList[2]
                and inputList[i + 3] == activateList[3]):
            setIndex.append(i)
            isSet  = True

    if(isSet):
        for indexItem in setIndex:
            setList = []
            for i in range(len(inputList)):
                if(not (i>= indexItem and i<indexItem + windowSize)):
                    setList.append(inputList[i])

            childMin = activeCheck(setList,activateList)
            minSize = min(minSize,childMin)

    return minSize

input = int(sys.stdin.readline())
activate = int(sys.stdin.readline())

inputList = DesToBinList(input)
activateList = DesToBinList(activate)

result = activeCheck(inputList,activateList)

print(result)