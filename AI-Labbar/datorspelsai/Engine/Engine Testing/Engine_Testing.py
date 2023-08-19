import time
import math
from graphics import *
from Entity import *
from Message import *
from FSM import *
from GameClock import *


class Shape:
    
    

    def __init__(self, Pt1x, Pt1y, Pt2x, Pt2y):
        self.rectangle = Rectangle(Point(Pt1x,Pt1y),Point(Pt2x, Pt2y))
        self.middle = Point((Pt1x + Pt2x)/2, (Pt1y + Pt2y)/2 )

    def getCenter(self):
        return self.rectangle.getCenter()

    def setPosition(newPosition):
        self.tile

    def setColr(self,colour):
        self.rectangle.setFill(colour)

class Tile(Shape): 
    def __init__(self, Pt1x, Pt1y, Pt2x, Pt2y, letter, adjacencyIndexes):
        self.rectangle = Rectangle(Point(Pt1x,Pt1y),Point(Pt2x, Pt2y))
        self.middle = [(Pt1x + Pt2x)/2, (Pt1y + Pt2y)/2 ]
        self.tileType = letter
        self.adjacencyIndexes = adjacencyIndexes

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


class TestUnit:
    _Shape = None
    _DirectionVector= None
    _Speed = None
    _Target = None

    _FSM = None
    def __init__(self, posX,posY, width, height, speed, id):
        
        self._Shape = Shape(posX - width , posY - height,posX + width, posY + height)
        self._Speed = speed
         

        self._Target = Point(posX,posY)
        self._myID = id
        
        self._FSM = FiniteStateMachine(self)

        self._FSM.SetCurrentState(IdleState)
        
        self._FSM.SetGlobalState(State)
        return

     #Gör så att den här bara räknas om vid ändring av fart/riktning   
    def GetDx(self):
        return self._DirectionVector.getX() * self._Speed
    def GetDy(self):
        return self._DirectionVector.getY() * self._Speed
    def GetPosition(self):
        return self._Shape.getCenter()
    def Move(self):
        self._Shape.rectangle.move(self.GetDx(),self.GetDy())
    def Stop(self):
        self._DirectionVector.x = 0
        self._DirectionVector.y = 0
    def CheckIfThere(self):
        return checkProximity(self._Speed, self.GetPosition(), self._Target)

    def setColr(self,colour):
        self._Shape.setColr(colour)

    def SetTarget(self, newTarget):
        self._Target = newTarget
        self.SetDirection()



    def MoveTo(self, target):
        if(_Target != target):
            _Target = target
            getUnitVector(GetPosition(), _Target)
        self.Move()
        if():
            Stop()

    def SetDirection(self):
        self._DirectionVector = getUnitVector(self.GetPosition(), self._Target)

    def Update(self):
        #Körs varje iteration
        self._FSM.Update()
        print(self._Target);
        print(self.CheckIfThere() == True)
     
    def HandleMessage(self, message):
        return self._FSM.HandleMessage(message)
        

#===========================================================================================================
#===========================================================================================================
class MoveToState(State):
  
    def Enter(Character):
        if(Character.CheckIfThere()):            #Swap to idle/Await command
            Character._FSM.ChangeState(IdleState)
        Character.SetDirection()
        print("moving")
        
    def Execute(Character):
        Character.Move()
        if(Character.CheckIfThere()):            #Swap to idle/Await command
            Character._FSM.ChangeState(IdleState)
        print("moving")

    def Exit(Character):
        Character.Stop()
        
#===========================================================================================================
#===========================================================================================================
class IdleState(State):
  
    def Enter(Character):
        print("idling")
        if(Character.CheckIfThere() == False):            #Swap to idle/Await command
            Character._FSM.ChangeState(MoveToState)
            print("swapping to move")
        pass
        
    def Execute(Character):
        if(Character.CheckIfThere() == False):            #Swap to idle/Await command
            Character._FSM.ChangeState(MoveToState)
            print("swapping to move")
        print("idling")

    def Exit(Character):
        pass

    def OnMessage(Character):
        pass


    
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

    #Setup test unit
    x = 100
    y = 100
    tileHeight = 30
    tileWidth = 30
    letter = "B"
    testUnit = Tile(x,y,x+tileWidth,y+tileHeight,letter, [])
    testUnit.setColr(color_rgb(40,200,40))
    dx = 0
    dy = 0
    moveSpeedMultiplier = 2
    startPoint = Point(200, 200)
    goToPoint = startPoint;


    testUnit2 = TestUnit(2*x,2*y,tileWidth, tileHeight, moveSpeedMultiplier, 1)
    testUnit2.setColr(color_rgb(200,40,40))

    #vector = getUnitVector(testUnit.tile.getP1(), goToPoint)
    #dx = vector.x * moveSpeedMultiplier
    #dy = vector.y * moveSpeedMultiplier
    
  

    # setup window
    window = GraphWin("Cool Rts game", 1440, 1000)

    #bind unit to window
    testUnit.rectangle.draw(window)
    testUnit2._Shape.rectangle.draw(window);
    

    #setup time
    clock = gameClock()
    tickTimePoint= time.time()
    tickIntervall= 1/21

    




    while True:
        newTimePoint = time.time()
        if(newTimePoint >= tickTimePoint):

            clock.Update()
            testUnit.rectangle.move(dx,dy)
            testUnit2.Update();
            
            #print(clock.getTime())
            tickTimePoint = newTimePoint + tickIntervall

            mouseInput = window.checkMouse()
            print(mouseInput)
            if(mouseInput != None):
                goToPoint = mouseInput
                testUnit2.SetTarget(goToPoint)
            #testUnit.MoveTo(goToPoint)
                vector = getUnitVector(testUnit.rectangle.getCenter(), goToPoint)
                dx = vector.x * moveSpeedMultiplier
                dy = vector.y * moveSpeedMultiplier
            if(checkProximity(2,testUnit.rectangle.getCenter(), goToPoint)):
                dx = 0
                dy = 0
               
                





    while True:
    
        #newPoint = window.getMouse() 
        print(newPoint)
    
        testUnit.rectangle.anchor = newPoint
        #newTile.tile.draw(window)
        testUnit.rectangle.move(20,0)
    #print(window.getMouse())
    window.close()


main()