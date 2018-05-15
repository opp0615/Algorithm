import sys

def isBetween(value1,value2,compareValue):
    if(compareValue > value1 and compareValue< value2):
        return True
    else:
        return False

n = int(sys.stdin.readline())
recList = []
for i in range(n):
    list = []
    rec = sys.stdin.readline()
    rec = rec.strip()
    rec = rec.split(',')
    rec = [int(i) for i in  rec]
    recList .append(rec)

maxResult = -9999

for item in recList:
    x1 = item[0]
    x2 = item[2]
    y1 = item[1]
    y2 = item[3]

    for targetitem in recList:
        if (item != targetitem):
            tx1 = targetitem[0]
            tx2 = targetitem[2]
            ty1 = targetitem[1]
            ty2 = targetitem[3]
            xbase = x2 - x1-1
            ybase = y2 - y1-1
            if(isBetween(x1,x2,tx1)):
                xbase = max (tx1 - x1 - 1, x2 - tx1 - 1)
            if(isBetween(x1, x2, tx2)):
                xbase = max(tx2 - x1 - 1, x2 - tx2 - 1)
            if(isBetween(y1, y2, ty1)):
                ybase = max( ty1 - y1 - 1, y2 - ty1 - 1)
            if(isBetween(y1, y2, ty2)):
                ybase = max(ty2 - y1 - 1, y2 - ty2 - 1)

            maxResult = max(maxResult,xbase*ybase)


print(maxResult)