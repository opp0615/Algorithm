import sys

N = sys.stdin.readline()
N = int(N)
graph = {}

for i in range(N):
    fromTo = sys.stdin.readline()
    fromTo = fromTo.strip()
    fromTo = fromTo.split(',')
    start = fromTo[0]
    end = fromTo[1]
    if(not start in graph):
        graph[start] = [end]
    else:
        graph[start].append(end)


candidate = sys.stdin.readline()
candidate = candidate.strip()

def isCandidateGoal(state):
    if(state == candidate):
        return True
    else:
        return False

def isGoal(state):
    if(state == 'Z'):
        return True
    else:
        return False

hopCount = 0
nowState = 'A'
fringe = []
succesor = graph[nowState]
for item in succesor:
    fringe.append(item)

while(1):

    nowState = fringe.pop(0)
    hopCount +=1

    if(isCandidateGoal(nowState)):
        break;

    if (nowState in graph):
        succesor = graph[nowState]
    for item in succesor:
        fringe.append(item)


fringe = []
succesor = graph[nowState]
for item in succesor:
    fringe.append(item)
while(1):
    nowState = fringe.pop(0)
    hopCount +=1

    if (isGoal(nowState)):
        break;

    if(nowState in graph):
        succesor = graph[nowState]
    for item in succesor:
        fringe.append(item)


print(hopCount)