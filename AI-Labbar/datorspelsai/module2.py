

from random import randint
from time import clock




class BaseGameEntity:
    _myID = None
    def __init__(self, ID):
        self._myID = ID

class State:
    def Enter(BaseGameEntity):
        pass
    def Execute(BaseGameEntity):
        pass
    def Exit(BaseGameEntity):
        pass


class EntityManager:

    class __EntityManager:
        _entityList = {}

        def AddEntity(self, Entity):
            self._entityList[Entity._myID] = Entity

        def GetEntityFromID(self, ID):
            return self._entityList[ID]
    
        def RemoveEntity(self, id):
            self.people.pop(id)

    #Kod för singleton funktionalitet    
    instance = None
    def __init__(self):
        if not EntityManager.instance:
            EntityManager.instance = EntityManager.__EntityManager()
        else:
            pass

    
    def __getattr__(self, name):
        return getattr(self.instance,name)

class Worker(BaseGameEntity):

    





    def __init__(self, ID, hungerlimit, thirstLimit, pocketSize, fatigueLimit):
        
        #Settable values ID and limiters 
        self._myID = ID
        self._hungerLimit = hungerlimit
        self._thirstLimit = thirstLimit
        self._pocetSize = pocketSize
        self._fatigueLimit = fatigueLimit

        #Startvalues
        self._hunger = 0
        self._thirst = 0
        self._moneyInBank = 50
        self._valuables = 0
        self._location = "Home"
        self._distanceToNextLocation = 0
        self._fatigue = 0

    
    def IncrementHungerBy(self, number):
        self._hunger += number
    def IncrementThirstBy(self, number):
        self._thirst += number
    def IncrementValuablesBy(self, number):
        self._valuables += number
    def IncrementMoneyBy(self, number):
        self._moneyInBank += number
    def IncrementDistanceBy(self, number):
        self._distanceToNextLocation += number
    def IncrementFatigueBy(self, number):
        self._fatigue += number
    
class FiniteStateMachine:
    _currentState = None
    _previousState = None
    _globalState = None

    _owner

    def __init__(self, owner, globalState):
        self._owner = owner
        self._globalState = globalState



    def Update(self):
        _currentState.Execute()

    def ChangeState(self, newState):
        self._currentState.Exit()
        self._previousState = self._currentState
        self._currentState = newState
        self._currentState.Enter()

    def RevertState(self):
        self._currentState.Exit()
        self._currentState = self._previousState
        self._currentState.Enter()

    def HandleMessage(self,message):
        if self.currentState.OnMessage(self.owner, message):
            return True
        if self.globalState.OnMessage(self.owner, message):
            return True
        return False


    
class Telegram:
    
    Sender = None

    
    Reciever = None

    
    Msg = None

    DispatchDelay = 0

    #Eventuell extra info som man kan vilja skicka med
    ExtraInfo = None

    def __init__(self, senderID, Rcvr, Msg, DispatchTime, XtraInfo):
        self.Sender = senderID
        self.Reciever = Rcvr
        self.Msg = Msg
        self.DispatchTime = DispatchTime
        self.ExtraInfo = XtraInfo

class GlobalWorker(State):
    def Execute(Character):
        Character.IncrementHungerBy(1)

    def OnMessage(Reciever, Message):
        pass #Hantera meddelanden

class Drinking(State):
    _location = "Saloon"

    def Enter(Character):

        #StateBlip till walkingstate
        if Character._location != self._location:
            Character.FSM.ChangeState(WalkingState)

    def Execute(Character):
        Character.IncrementThirstBy(-5)
        Character.IncrementMoneyBy(-1)

class GraveRobbing(State):
    _location = "Graveyard"

    def Enter(Character):
        if Character._location != self._location:
            Character.FSM.ChangeState(WalkingState)

    def Execute(Character):
        print(Character._myID + ": Digging..")
        Character.IncrementValuablesBy(1)
        Character.IncrementFatigueBy(4)
        Character.IncrementThirstBy(4)

        


class Programming(State):
    _location = "Sweet Home"

    def Enter(Character):
        if Character._location != self._location:
            Character.FSM.ChangeState(WalkingState)

    def Execute(Character):
        print(Character._myID + ": *frantic keyboard usage*")
        Character.IncrementFatigueBy(2)
        Character.IncrementMoneyBy(2)

class Shopping(State):
    _location = "Store"

    def Enter(Character):
        if Character._location != self._location:
            Character.FSM.ChangeState(WalkingState)

    def Execute(Character):
        pass

class EatingAtHome(State):
    _location = "Sweet Home"

    def Enter(Character):
        if Character._location != self._location:
            Character.FSM.ChangeState(WalkingState)

    def Execute(Character):
        if Character._hunger < 10:
            Character.IncrementHungerBy(-10)
        else:
            Character.IncrementHungerBy(-2)


class Sleeping(State):
    _location = "Sweet Home"

    def Execute(Character):
        print(Character._myID + ": Zzzz..")
        

class WalkingState(State):
    def Enter(Character):
        print(Character._myID + ": Puttin´ on my boots..")

    def Execute(Character):
        print(Character._myID+": Walking to " + Character.FSM.previousState._location)
        Character.IncrementDistanceBy(-1)
        
        if Character._distanceToNextLocation < 1:
            print(Character._myID + ": Finally here..")
            Character._location = Character.FSM._previousState._location
            if EntityManager.instance.GetEntityFromID(Character.friend)._location == Character._location and (Character._location == "Store" or Character._location == "Saloon"):
                pass #send message greeting 
            Character.FSM.RevertState()




bert = Worker("bert", 80,40,10, 60)
tickTimePoint= time.time()
tickIntervall=2

while True:
    newTimePoint = time.time()
    if(newTimePoint >= tickTimePoint):
     #   bert.Update()
        #tom.Update()
     #   print(str(tom.Thirst) + "  " + str(tom.Fatigue) + "  " + str(tom.goldCarried) + "  " + str(tom.distance))
        #clock.Update()
        #print(clock.getTime())
        tickTimePoint = newTimePoint + (1/tickIntervall)
