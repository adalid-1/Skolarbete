
from Pathfinding import *


def main():
    print("Hello")
    weightedGraph= buildGraph2("Karta Laboration 2.txt")
    window = GraphWin("Cool Rts game", 1440, 900)
    drawMap(weightedGraph, window)
    
    #Finds the start and goal
    goal = 0
    start = 0
    startNgoal = findStartAndGoal(weightedGraph)
   # pathfindingLoopAstar(startNgoal[0], startNgoal[1],weightedGraph)

    print(window.getMouse())
    window.close()



main()
