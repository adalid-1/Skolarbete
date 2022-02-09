import time
import math
from graphics import *
from Entity import *
from Message import *
from FSM import *
from GameClock import *


class Tile:
    
    

    def __init__(self, Pt1x, Pt1y, Pt2x, Pt2y, letter, adjacencyIndexes):
        self.tile = Rectangle(Point(Pt1x,Pt1y),Point(Pt2x, Pt2y))
        self.middle = [Pt1x + 10, Pt1y + 10 ]
        self.tileType = letter
        self.adjacencyIndexes = adjacencyIndexes

    def setPosition(newPosition):
        self.tile

    def setColr(self,colour):
        self.tile.setFill(colour)

def checkProximity(distance, pt1, pt2):
    vx = False
    vy = False
    if(abs(pt1.x - pt2.x) < distance):
        vx = True

    if(abs(pt1.y - pt2.y) < distance):
        vy = True

    if(vx  and vy ):
        return True
    return False
        

def getUnitVector(pt1,pt2):
    # The vector
    vx = pt2.x - pt1.x
    vy = pt2.y - pt1.y

    #Get vector magnitude
    m = math.sqrt(vx * vx + vy * vy)

    #Divide by magnitude
    vx = vx / m
    vy = vy / m
    return Point(vx,vy)

def SetupTestEnvironment():

    print("hello")

def main():
    print("Hello")

    x = 100
    y = 100
    tileHeight = 30
    tileWidth = 30
    letter = "B"

    testUnit = Tile(x,y,x+tileWidth,y+tileHeight,letter, [])

    testUnit.setColr(color_rgb(40,200,40))
    window = GraphWin("Cool Rts game", 1440, 1000)

    testUnit.tile.draw(window)

    clock = gameClock()
    tickTimePoint= time.time()
    tickIntervall=30

    dx = 0
    dy = 0
  
    goToPoint = Point(200, 200)

    vector = getUnitVector(testUnit.tile.getP1(), goToPoint)
    dx = vector.x
    dy = vector.y

    moveSpeedMultiplier = 12

    while True:
        newTimePoint = time.time()
        if(newTimePoint >= tickTimePoint):

            clock.Update()
            testUnit.tile.move(dx,dy)
            #print(clock.getTime())
            tickTimePoint = newTimePoint + (1/tickIntervall) 

            mouseInput = window.checkMouse()
            print(mouseInput)
            if(mouseInput != None):
                goToPoint = mouseInput
                vector = getUnitVector(testUnit.tile.getP1(), goToPoint)
                dx = vector.x * moveSpeedMultiplier
                dy = vector.y * moveSpeedMultiplier
            if(checkProximity(15,testUnit.tile.getP1(), goToPoint)):
                dx = 0
                dy = 0
               





    while True:
    
        #newPoint = window.getMouse() 
        print(newPoint)
    
        testUnit.tile.anchor = newPoint
        #newTile.tile.draw(window)
        testUnit.tile.move(20,0)
    #print(window.getMouse())
    window.close()


main()