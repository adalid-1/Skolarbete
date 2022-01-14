
from graphics import *
import math

class Tile:
    
    

    def __init__(self, Pt1x, Pt1y, Pt2x, Pt2y, letter, adjacencyIndexes):
        self.tile = Rectangle(Point(Pt1x,Pt1y),Point(Pt2x, Pt2y))
        self.middle = [Pt1x + 10, Pt1y + 10 ]
        self.tileType = letter
        self.adjacencyIndexes = adjacencyIndexes

    def setColr(self,colour):
        self.tile.setFill(colour)



class Vertex:
    a = 0
class Graph:
    b = 0


#returnerar storleken på en rad 
def SizeChecker(filecontent):
    #Sizes[0] = Antal chars i listan, [1] = Antal lines [2] = antal chars per line 
    Sizes =[0,0,0, 0]
    for line in filecontent:
        Sizes[1] +=1
        for letter in line:
            #Sizes[0]+=1
            if letter != '\n':
                Sizes[0] +=1
    Sizes[2] = Sizes[0]/Sizes[1]
    return Sizes
        

def pathfindingLoop(start, goal, tileList):
    #will contain unvisited tiles, used as a queue
    frontier = []
    frontier.append(start )
    tileList[goal].setColr("yellow")
    #each index is a key and the value is the index of previously visited tile
    came_from = dict()
    came_from[start] = None


    #while there are tiles in the frontier
    while frontier:
        
      
       current = frontier[0]
       tileList[current].setColr("green")
       if current == goal:
           break
       #for every adjacent index 
       #val = input("Enter your value: ")
       time.sleep(0.02)
       adjalist = [tileList[current].adjacencyIndexes[1],tileList[current].adjacencyIndexes[3],tileList[current].adjacencyIndexes[4],tileList[current].adjacencyIndexes[6],tileList[current].adjacencyIndexes[0],tileList[current].adjacencyIndexes[2],tileList[current].adjacencyIndexes[5],tileList[current].adjacencyIndexes[7]] 

       #for next in tileList[current].adjacencyIndexes:
       for next in adjalist:         

          #check if walkable
          
          if next not in came_from and next != -1 and tileList[next].tileType != 'X':
             #expand frontier
             
             frontier.append(next)
             came_from[next] = current
            

             tileList[next].setColr("aquamarine")
             
       #remove explored tiles from frontier
       frontier.pop(0)
       tileList[current].setColr("aquamarine")
    #Walk backwards from goal to start
    current = goal
    path = []
    while current != start: 
       path.append(current)
       current = came_from[current]
    path.append(start) # optional
    path.reverse() # optional
  
    print(path)  #for debug



    for index in path:
        if index >0 and tileList[int(index)].tileType != 'X' :
            tileList[int(index)].setColr("green")
            #append tile to open
    return


def pathfindingLoopDepth(start, goal, tileList):
    #will contain unvisited tiles, used as a queue
    frontier = []
    frontier.append(start )
    tileList[goal].setColr("yellow")
    #each index is a key and the value is the index of previously visited tile
    came_from = dict()
    came_from[start] = None


    #while there are tiles in the frontier
    while frontier:
       current = frontier.pop()
       tileList[current].setColr("pink")
       #for every adjacent index 
       for next in tileList[current].adjacencyIndexes:
          #check if walkable
          if next not in came_from and next != -1 and tileList[next].tileType != 'X':
             #expand frontier
             frontier.append(next)
             came_from[next] = current
             if next == goal:
                 break
             time.sleep(0.06)
             tileList[next].setColr("aquamarine")
             
       #remove explored tiles from frontier
       if current == goal:
           break
    
    #Walk backwards from goal to start
    current = goal
    path = []
    while current != start: 
       path.append(current)
       current = came_from[current]
    path.append(start) # optional
    path.reverse() # optional
  
    print(path)  #for debug



    for index in path:
    #if tileList[int(index)].tileType != 'X':
        if index >0 and tileList[int(index)].tileType != 'X' :
            tileList[int(index)].setColr("green")
            #append tile to open
    return
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
#Building graph without weights 
def buildGraph():
    tileList = []
    y= 0
    x= 0
    SizeInfo = []
    currentIndex = 0
    

    mapFile = open("Map3.txt","r")
    if mapFile.mode == "r":
        #Tar in innehållet i textfilen radvis
        contents = mapFile.readlines()
    
    SizeInfo = SizeChecker(contents)
    lineLength = int(SizeInfo[2]) 
    print(lineLength)
    #loopar igenom varje rad
    for line in contents:

    
        
        #Skapa en tile och stoppar in i tilelistan
        for letter in line:
            

            if letter == '\n':
                pass
            else:
                ownIndex = currentIndex
                atRightEdge = (currentIndex % lineLength > (currentIndex+1) % lineLength)
                atLeftEdge =  (currentIndex % lineLength < (currentIndex-1) % lineLength)
                print (str((currentIndex+1) % lineLength) +" "+ str(currentIndex % lineLength) + " at left")
                #Beräknar index för tilen ovanför och under
                IndexAbove = ownIndex -  lineLength
                IndexUnder = ownIndex +  lineLength

                if atRightEdge:
                    #Kollar om indexet ovan eller under är utanför arrayen samt skapar en array med alla närliggande tiles index
                    if IndexAbove >= 0 and IndexUnder < SizeInfo[0]:
                       adjacencyArray = [IndexAbove-1, IndexAbove, -1,   ownIndex-1,-1,    IndexUnder-1,IndexUnder, -1]
                       #[7,8,9,
                      #  4,  6,
                       # 1,2,3]
                    elif IndexAbove < 0:
                       adjacencyArray = [-1, -1, -1,ownIndex-1,-1,IndexUnder-1,IndexUnder,-1]
                    elif IndexUnder > SizeInfo[0]:
                        adjacencyArray = [IndexAbove-1, IndexAbove,-1,ownIndex-1,-1,-1,-1,-1]
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

                
                #0, 2,5,7
                

                newTile = Tile(x,y,x+20,y+20,letter, adjacencyArray)
                #Rectangle(Point(a,i), Point(a+20,i+20))


             
                if letter == 'X':
                    newTile.setColr("black")
                if letter == 'S' or letter == 'G':
                    newTile.setColr("blue")
                tileList.append(newTile)
                x += 20

                currentIndex += 1
            
            
        y+=20
        x= 0
      
        print(letter)

      
    #___________________________________________________________________
#above
    tilePenalty = 0
    
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
            #Could not be assed to put [] in adjacencyArray(1) so here comes some yoloprogramming
            

                
        #___________________________________________________________________
    return tileList

#heuristic
def tileDistance(tile, start, goal):
    
       
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
#Build graph with weights
def buildGraph2(fileName):
    #Stores generated tiles
    tileList = []
    #current index in tileList 
    currentIndex = 0
    #Positionvalues
    y= 0
    x= 0
    #Info about the map-file, line length, nr of chars, nr of chars per line
    SizeInfo = []
    #Weight of moving diagonally 
    diagonalPenalty = 1.3

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
            

            if letter == '\n':
                pass
            else:
                ownIndex = currentIndex
                atRightEdge = (currentIndex % lineLength > (currentIndex+1) % lineLength)
                atLeftEdge =  (currentIndex % lineLength < (currentIndex-1) % lineLength)
                print (str((currentIndex+1) % lineLength) +" "+ str(currentIndex % lineLength) + " at left")
                #Beräknar index för tilen ovanför och under
                IndexAbove = ownIndex - lineLength
                IndexUnder = ownIndex + lineLength

                if atRightEdge:
                    #Kollar om indexet ovan eller under är utanför arrayen samt skapar en array med alla närliggande tiles index
                    if IndexAbove >= 0 and IndexUnder < SizeInfo[0]:
                       adjacencyArray = [IndexAbove-1, IndexAbove, -1,   ownIndex-1,-1,    IndexUnder-1,IndexUnder, -1]
                       #[7,8,9,
                      #  4,  6,
                       # 1,2,3]
                    elif IndexAbove < 0:
                       adjacencyArray = [-1, -1, -1,ownIndex-1,-1,IndexUnder-1,IndexUnder,-1]
                    elif IndexUnder > SizeInfo[0]:
                        adjacencyArray = [IndexAbove-1, IndexAbove,-1,ownIndex-1,-1,-1,-1,-1]
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

                

                newTile = Tile(x,y,x+20,y+20,letter, adjacencyArray)
               


             
                if letter == 'X':
                    newTile.setColr("black")
                if letter == 'S':
                    start = currentIndex
                    newTile.setColr("blue")
                if letter == 'G':
                    goal = currentIndex                    
                    newTile.setColr("blue")
                tileList.append(newTile)
                x += 20

                currentIndex += 1
            
            
        y+=20
        x= 0
      
        print(letter)

      
    #___________________________________________________________________
#above
    for tile in tileList:
        MakeDiagonalsUnwalkable(tileList, tile)
        CalculateCosts(tileList, tile, start, goal, diagonalPenalty)

        #___________________________________________________________________
    return tileList




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
#måste göras per tile
def CalculateCosts(tileList, tile, start, goal, diagonalPenalty):
    
    adjacencyArray2 = []
    #adds cost for traversing tiles, [index, basecost, heuristic]
    for index in tile.adjacencyIndexes:
        adjacencyArray2.append([index, 1 , tileDistance(tileList[index],tileList[start],tileList[goal])])

                
    print(adjacencyArray2)
    #add diagonal penalty to diagonals
    adjacencyArray2[0][1] += diagonalPenalty
    adjacencyArray2[2][1] += diagonalPenalty
    adjacencyArray2[5][1] += diagonalPenalty
    adjacencyArray2[7][1] += diagonalPenalty

    tile.adjacencyIndexes = adjacencyArray2
    
    return

def main():

    unweightedGraph = buildGraph()
    weightedGraph= buildGraph2("Map2.txt")
    win = GraphWin("My Circle", 1440, 900)
    c= Rectangle(Point(50,50), Point(60,60))
 
    c.setFill("red")


    
    start = 0
    goal = 0

   # weightedGraph = unweightedGraph
    for tile in weightedGraph:
        if tile.tileType == 'S':
            start = weightedGraph.index(tile)
        if tile.tileType == 'G':
            goal = weightedGraph.index(tile)
        tile.tile.draw(win)

    print("köttbulle")

   # pathfindingLoop(start, goal, unweightedGraph)
    #pathfindingLoopDepth(start, goal, unweightedGraph)
    pathfindingLoopAstar(start, goal,weightedGraph)
    myposition = 74
    val = -1
    running = True
    while running:

            #append tile to open
        val = input("Enter your value: ") 
        for index in weightedGraph[myposition].adjacencyIndexes:
            #if weightedGraph[int(index)].tileType != 'X':
        
            if index[0] >0 and weightedGraph[int(index[0])].tileType != 'X' :
                weightedGraph[int(index[0])].setColr("white")
        print(val)
        if val == "1":
            if weightedGraph[myposition].adjacencyIndexes[1][0] >0 and weightedGraph[weightedGraph[myposition].adjacencyIndexes[1][0]].tileType != 'X' :
                myposition = weightedGraph[myposition].adjacencyIndexes[1][0]
                print(tileDistance(weightedGraph[myposition], weightedGraph[start], weightedGraph[goal]))
                print(weightedGraph[myposition].middle)
            pass
        if val == "2":
            if weightedGraph[myposition].adjacencyIndexes[6][0] >0 and weightedGraph[weightedGraph[myposition].adjacencyIndexes[6][0]].tileType != 'X' :
                myposition = weightedGraph[myposition].adjacencyIndexes[6][0]
                print(tileDistance(weightedGraph[myposition], weightedGraph[start], weightedGraph[goal]))
        if val == "3":
            if weightedGraph[myposition].adjacencyIndexes[3][0] >0 and weightedGraph[weightedGraph[myposition].adjacencyIndexes[3][0]].tileType != 'X' :
                myposition = weightedGraph[myposition].adjacencyIndexes[3][0]
                print(tileDistance(weightedGraph[myposition], weightedGraph[start], weightedGraph[goal]))
        if val == "4":
            if weightedGraph[myposition].adjacencyIndexes[4][0] >0 and weightedGraph[weightedGraph[myposition].adjacencyIndexes[4][0]].tileType != 'X' :
                myposition = weightedGraph[myposition].adjacencyIndexes[4][0]
                print(tileDistance(weightedGraph[myposition], weightedGraph[start], weightedGraph[goal]))
        print(val)
        if val == "6":
            running = False
         
        print(myposition)
        for index in weightedGraph[myposition].adjacencyIndexes:
            if index[0] >0 and weightedGraph[int(index[0])].tileType != 'X' :
                weightedGraph[int(index[0])].setColr("pink")
       


        

    print(win.getMouse())
    
   #read from file

    win.close()


main()