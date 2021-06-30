
from graphics import *
import Configuration
import math

class Tile:
    
    

    def __init__(self, Pt1x, Pt1y, Pt2x, Pt2y, letter, adjacencyIndexes):
        self.tile = Rectangle(Point(Pt1x,Pt1y),Point(Pt2x, Pt2y))
        self.middle = [Pt1x + 10, Pt1y + 10 ]
        self.tileType = letter
        self.adjacencyIndexes = adjacencyIndexes

    def setColr(self,colour):
        self.tile.setFill(colour)


class Node:
    
    

    def __init__(self, Pt1x, Pt1y, Pt2x, Pt2y, letter, adjacencyIndexes):
        self.tile = Rectangle(Point(Pt1x,Pt1y),Point(Pt2x, Pt2y))
        self.middle = [Pt1x + 10, Pt1y + 10 ]
        self.tileType = letter
        self.adjacencyIndexes = adjacencyIndexes

    def setColr(self,colour):
        self.tile.setFill(colour)

class Map:
    #List of all tiles
    def __init__(self, tileList, graph):
        self.GameMap = tileList
        self.pathfindingGraph = graph
    #returns tile 
    def getFromGraph(self, index):
        return self.pathfindingGraph[index]
    #Returns distance 
    def getHeuristic(self,_start, _current, _to):
        tileDistanceFromStartAndGoal(getFromGraph(_start),getFromGraph(_current), getFromGraph(_to))
        pass

#returnerar Sizes[0] = Antal chars i listan, [1] = Antal lines [2] = antal chars per line 
def SizeChecker(filecontent):
    Sizes =[0,0,0, 0]
    for line in filecontent:
        Sizes[1] +=1
        for letter in line:
            if letter != '\n':
                Sizes[0] +=1
    Sizes[2] = Sizes[0]/Sizes[1]
    return Sizes
        
def pathfindingLoopAstar(start, goal, tileList):
    #will contain unvisited tiles, used as a queue
    frontier = []
    frontier.append([start,  0] )
    #tileDistance(tileList[start], tileList[start], tileList[goal]
    tileList[goal].setColr("yellow")
    #each index is a key and the value is the index of previously visited tile
    came_from = dict()
    came_from[start] = None



    
    cost_so_far = dict()
    cost_so_far[start] = 0



    #while there are tiles in the frontier
    while frontier:
       #current tile [index, prio]
       current =   frontier.pop(0)

       tileList[current[0]].setColr("green")
       #Early exit if goal is found
       if current[0] == goal:
           break
        

      # time.sleep(.2)
       #adjalist = [tileList[current[0]].adjacencyIndexes[1],tileList[current[0]].adjacencyIndexes[3],tileList[current[0]].adjacencyIndexes[4],tileList[current[0]].adjacencyIndexes[6],tileList[current[0]].adjacencyIndexes[0],tileList[current[0]].adjacencyIndexes[2],tileList[current[0]].adjacencyIndexes[5],tileList[current[0]].adjacencyIndexes[7]] 
       #for every adjacent [index, cost, heuristic]
       for count, next in enumerate(tileList[current[0]].adjacencyIndexes):
       #for next in adjalist:         
            
          #check if walkable
          if next[0] != -1 and tileList[next[0]].tileType != 'X':
              #calculates cost of current cost + cost of moving to next from current
              new_cost = cost_so_far[current[0]] + tileList[current[0]].adjacencyIndexes[count][1]
              if next[0] not in cost_so_far or new_cost < cost_so_far[next[0]]:
                 cost_so_far[next[0]] = new_cost
                 #Priority och cost är inte samma
                 #ÄNDRA I GRAF SKAPANDET
                 priority = new_cost +  tileList[current[0]].adjacencyIndexes[count][2]
                 hasBeenPut= False

                 for count2, edge in enumerate(frontier):
                     #print(frontier)
                     if edge[1] >= priority:
                         frontier.insert(count2,[next[0], priority] )
                         came_from[next[0]] = current[0]
                         hasBeenPut = True
                         break
                 if not hasBeenPut:
                    frontier.append([next[0], priority])
                    came_from[next[0]] = current[0]
                     

            

                 tileList[next[0]].setColr("aquamarine")
             
       #remove explored tiles from frontier
     
       tileList[current[0]].setColr("aquamarine")
    #Walk backwards from goal to start
    #current = goal
    print("gave up")
    path = []
    while current[0] != start: 
       path.append(current[0])
       current[0] = came_from[current[0]]
    path.append(start) # optional
    path.reverse() # optional
  
    print(path)  #for debug
    print(cost_so_far[goal])



    for index in path:
        if index >0 and tileList[int(index)].tileType != 'X' :
            tileList[int(index)].setColr("green")
            #append tile to open
    return

#=====================================================================
# A-star heuristic function, if heuristic is forcemade very low the A-star practically turns into a depth first search
def tileDistanceFromStartAndGoal(tile, start, goal):
    
       
       Xcost = pow(abs(tile.middle[0] - start.middle[0]), 2)
       Ycost =  pow(abs(tile.middle[1] - start.middle[1]),2)
       
       cost = math.sqrt(Xcost + Ycost)
       Xcost = pow(abs(tile.middle[0] - goal.middle[0]), 2)
       Ycost =  pow(abs(tile.middle[1] - goal.middle[1]),2)
       cost += math.sqrt(Xcost + Ycost)

       #manhattan distance, every tile is equal if start and goal is in corners
       #Xcost = abs(tile.middle[0] - start.middle[0])
      # Ycost = abs(tile.middle[1] - start.middle[1])
       
       
      # Xcost += abs(tile.middle[0] - goal.middle[0])
      # Ycost += abs(tile.middle[1] - goal.middle[1])
      # cost = Xcost + Ycost

       
       return cost/7


#=======================================================================



#=======================================================================
#Build graph with weights
def buildGraph2(fileName):
    tileList = []
    y= 0
    x= 0
    tileWidth = 9
    tileHeight = 9
    SizeInfo = []
    currentIndex = 0
    walkingCost = 1.0
    diagonalPenalty = 0.3
    start = -1
    goal = -1
    mapFile = open(fileName,"r")
    if mapFile.mode == "r":
        #Tar in innehållet i textfilen radvis
        contents = mapFile.readlines()
    
    SizeInfo = SizeChecker(contents)
    lineLength = int(SizeInfo[2]) 
    #loopar igenom varje rad
    for line in contents:

    
        
        #Skapa en tile och stoppar in i tilelistan
        for letter in line:
            # Ignorera new line
            if letter == '\n':
                pass

            else:
                ownIndex = currentIndex
                # Checks if the current index is at an edge
                atRightEdge = (currentIndex % lineLength > (currentIndex+1) % lineLength)
                atLeftEdge =  (currentIndex % lineLength < (currentIndex-1) % lineLength)
             
                #Beräknar index för tilen ovanför och under
                IndexAbove = ownIndex - lineLength
                IndexUnder = ownIndex + lineLength
                #Kollar om indexet ovan eller under är utanför arrayen samt skapar en array med alla närliggande tiles index
                if atRightEdge:
                    #Kollar om indexet ovan eller under är utanför arrayen samt skapar en array med alla närliggande tiles index
                    if IndexAbove >= 0 and IndexUnder < SizeInfo[0]:
                       adjacencyArray = [IndexAbove-1, IndexAbove,      -1,
                                         ownIndex-1,                    -1, 
                                         IndexUnder-1,  IndexUnder,     -1]

                    elif IndexAbove < 0:
                       adjacencyArray =  [-1,              -1,        -1,
                                         ownIndex-1,                  -1,
                                         IndexUnder-1,  IndexUnder,   -1]
                    elif IndexUnder > SizeInfo[0]:
                        adjacencyArray = [IndexAbove-1, IndexAbove,   -1,
                                         ownIndex-1,                  -1,
                                         -1,                -1,       -1]
                elif atLeftEdge:
                    #Kollar om indexet ovan eller under är utanför arrayen samt skapar en array med alla närliggande tiles index
                    if IndexAbove >= 0 and IndexUnder < SizeInfo[0]:
                       adjacencyArray = [-1, IndexAbove, IndexAbove+1,   -1,ownIndex+1,   -1,IndexUnder,IndexUnder+1]
                       #[7,8,9,
                      #  4,  6,
                       # 1,2,3]
                    elif IndexAbove < 0:
                       adjacencyArray = [-1, -1, -1,-1,ownIndex+1,-1,IndexUnder,IndexUnder+1]
                    elif IndexUnder > SizeInfo[0]:
                        adjacencyArray = [-1, IndexAbove, IndexAbove+1,-1,ownIndex+1,-1,-1,-1]
                else:
                    #Kollar om indexet ovan eller under är utanför arrayen samt skapar en array med alla närliggande tiles index
                    if IndexAbove >= 0 and IndexUnder < SizeInfo[0]:
                       adjacencyArray = [IndexAbove-1, IndexAbove, IndexAbove+1,   ownIndex-1,ownIndex+1,    IndexUnder-1,IndexUnder,IndexUnder+1]
                       #[7,8,9,
                      #  4,  6,
                       # 1,2,3]
                    elif IndexAbove < 0:
                       adjacencyArray = [-1, -1, -1,ownIndex-1,ownIndex+1,IndexUnder-1,IndexUnder,IndexUnder+1]
                    elif IndexUnder > SizeInfo[0]:
                        adjacencyArray = [IndexAbove-1, IndexAbove, IndexAbove+1,ownIndex-1,ownIndex+1,-1,-1,-1]

                
                #The new tile gets position, type and indexes of adjacent tiles
                newTile = Tile(x,y,x+tileWidth,y+tileHeight,letter, adjacencyArray)
               
                #T = träd, V = vatten, G = sump, B = berg, M = mark

                #Sets tile color based on type, might as well be done in tile constructor
                #Also keeps track of start and goal indexes
                if letter == 'T':
                    newTile.setColr(Configuration.tree['color'])
                if letter == 'V':
                    newTile.setColr("blue")
                if letter == 'G':
                    newTile.setColr("yellow")

                if letter == 'B':
                    newTile.setColr("grey")
                if letter == 'M':
                    newTile.setColr("green")

                tileList.append(newTile)
                x += tileWidth

                currentIndex += 1
            
            
        y+= tileHeight
        x= 0

    GameMap = tileList

    for tile in tileList:
      #  MakeDiagonalsUnwalkable(tileList, tile)
        CalculateCosts(tileList, tile, start, goal, diagonalPenalty)


    return tileList


def findStartAndGoal(tileList):
    start = 0
    goal = 0
    for tile in tileList:
        if tile.tileType == 'S':
            start = tileList.index(tile)
        if tile.tileType == 'G':
            goal = tileList.index(tile)


    startAndGoal = (start, goal)
    return startAndGoal
  
def drawMap(tileList, win):
        for tile in tileList:
            tile.tile.draw(win)


def assbutt(tileList):
    
    
          
    #___________________________________________________________________
    #This part makes diagonals adjacent to obstacles unwalkable 
    for tile in tileList:
        if tile.tileType != 'X':

            if tile.adjacencyIndexes[1] != -1 and tileList[tile.adjacencyIndexes[1]].tileType == 'X':
                tile.adjacencyIndexes[1] = -1
                tile.adjacencyIndexes[0] = -1
                tile.adjacencyIndexes[2] = -1
                pass
            #left
            if tile.adjacencyIndexes[3] != -1 and tileList[tile.adjacencyIndexes[3]].tileType == 'X':
                tile.adjacencyIndexes[3] = -1
                tile.adjacencyIndexes[0] = -1
                tile.adjacencyIndexes[5] = -1
                pass
            #right
            if tile.adjacencyIndexes[4] != -1 and tileList[tile.adjacencyIndexes[4]].tileType == 'X':
                tile.adjacencyIndexes[4] = -1
                tile.adjacencyIndexes[2] = -1
                tile.adjacencyIndexes[7] = -1
                pass


            if tile.adjacencyIndexes[6] != -1 and tileList[tile.adjacencyIndexes[6]].tileType == 'X':
                tile.adjacencyIndexes[6] = -1
                tile.adjacencyIndexes[5] = -1
                tile.adjacencyIndexes[7] = -1
                pass
            
            #Here I add some aditional data about the adjacent tiles in a very dirt manner
            adjacencyArray2 = []
            for index in tile.adjacencyIndexes:
                #index, general walkcost, heuristic
                adjacencyArray2.append([index, walkingCost , 0])

                
            # Adds diagonal costpenalty for the diagonals
            adjacencyArray2[0][1] += diagonalPenalty
            adjacencyArray2[2][1] += diagonalPenalty
            adjacencyArray2[5][1] += diagonalPenalty
            adjacencyArray2[7][1] += diagonalPenalty

            tile.adjacencyIndexes = adjacencyArray2

        #___________________________________________________________________}

def MakeDiagonalsUnwalkable(tileList, tile):
    
    if tile.tileType != 'X':

        if tile.adjacencyIndexes[1] != -1 and tileList[tile.adjacencyIndexes[1]].tileType == 'X':
            tile.adjacencyIndexes[1] = -1
            tile.adjacencyIndexes[0] = -1
            tile.adjacencyIndexes[2] = -1
            pass
        #left
        if tile.adjacencyIndexes[3] != -1 and tileList[tile.adjacencyIndexes[3]].tileType == 'X':
            tile.adjacencyIndexes[3] = -1
            tile.adjacencyIndexes[0] = -1
            tile.adjacencyIndexes[5] = -1
            pass
        #right
        if tile.adjacencyIndexes[4] != -1 and tileList[tile.adjacencyIndexes[4]].tileType == 'X':
            tile.adjacencyIndexes[4] = -1
            tile.adjacencyIndexes[2] = -1
            tile.adjacencyIndexes[7] = -1
            pass


        if tile.adjacencyIndexes[6] != -1 and tileList[tile.adjacencyIndexes[6]].tileType == 'X':
            tile.adjacencyIndexes[6] = -1
            tile.adjacencyIndexes[5] = -1
            tile.adjacencyIndexes[7] = -1
            pass
            

    return 
#Funkar inte att pre räkna ut heuristics så här när det inte är bestämda Start och Mål 
def CalculateCosts(tileList, tile, start, goal, diagonalPenalty):
    
    adjacencyArray2 = []
    #adds cost for traversing tiles, [index, basecost, heuristic]
    for index in tile.adjacencyIndexes:
        adjacencyArray2.append([index, 1 , tileDistanceFromStartAndGoal(tileList[index],tileList[start],tileList[goal])])

                
    print(adjacencyArray2)
    #add diagonal penalty to diagonals
    adjacencyArray2[0][1] += diagonalPenalty
    adjacencyArray2[2][1] += diagonalPenalty
    adjacencyArray2[5][1] += diagonalPenalty
    adjacencyArray2[7][1] += diagonalPenalty

    tile.adjacencyIndexes = adjacencyArray2
    
    return