import sys

id = sys.stdin.readline()
pas = sys.stdin.readline()

id = id.strip()
pas = pas.strip()

print(id)
print(pas)

idOk = True
pasOk = True

#len
if(not (len(id)>=6 and len(id)<=12)):
    idOk = False
    #print ("id is not in 6~12 length")
if(not (len(pas)>=8 and len(pas)<=16)):
    pasOk = False
    #print("id is not in 8~16 length")

isThereAlpha = False
isThereNumber = False
#only small alphabet, number
for idItem in id:
    #97~122 a~z 48~57 0~9
    if((ord(idItem)>=97 and ord(idItem)<=122)):
        isThereAlpha = True
    elif((ord(idItem)>=48 and ord(idItem)<=57)):
        isThereNumber = True
    else:
        idOk = False

#less on alpha and number
if(not isThereAlpha):
    idOk = False
if(not isThereNumber):
    idOk = False


isThereAlpha = False
isThereNumber = False
for pasItem in pas:
    if ((ord(pasItem) >= 97 and ord(pasItem) <= 122)):
        isThereAlpha = True
    elif ((ord(pasItem) >= 48 and ord(pasItem) <= 57)):
        isThereNumber = True
    else:
        pasOk = False

#less on alpha and number
if(not isThereAlpha):
    pasOk = False
if(not isThereNumber):
    pasOk = False


#password not serial char over 3

for i in range(len(pas)-2):
    if((pas[i] == pas[i+1]) and (pas[i+1] == pas[i+2])):
        pasOk = False

#Result
if(idOk and pasOk):
    print("T")
else:
    print("F")

