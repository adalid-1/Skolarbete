
#from random import randint
#from time import clock

#Gör så att man sparar vännen i appointment så behöver man inte ha friend som attribut
import time
from Entity import *
from Places import *
from Message import *
from FSM import *

#===========================================================================================================
#===========================================================================================================
class Miner(BaseGameEntity):
    
    #Miner location
    location = "Home"
    #Distans till nästa plats
    distance = 0

    appointment = None

    #Miners best friend
    friend = ""

    #Referens till miners state machine
    FSM = None
    #a pointer to an instance of a State
    #location = None

    #how many nuggets the miner has in his pocket
    goldCarried = 0
    pocketSize = 10
    def incrementgoldCarriedBy(self, number):
        self.goldCarried += number

    alive = True
    miningGearDurability = 0

    #how much money the miner has deposited in the bank
    moneyInBank = 0
    def incrementmoneyInBankBy(self, number):
        self.moneyInBank += number
    
    #How hungry the miner is and how much hunger he can take 
    hunger = 0
    hungerLimit = 50
    def incrementHungerBy(self, number):
        self.hunger +=number
    foodAtHome = 0
    def incrementFoodAtHomeBy(self, number):
        self.foodAtHome +=number

    #the higher the value, the thirstier the miner
    Thirst = 0
    ThirstLimit = 30
    def incrementThirstBy(self, number):
        self.Thirst += number

   

    #the higher the value, the more tired the miner 
    Fatigue = 0
    FatigueLimit = 40
    def incrementFatigueBy(self, number):
        self.Fatigue += number

    #how lonely is the miner?
    Loneliness = 0
    LonelyLimit = 50
    def incrementLonelinessBy(self, number):
        self.Loneliness += number
   
    #Constructors
    def __init__(self, id, startingState):
        self._myID = id
        
        self.FSM = FiniteStateMachine(self)

        self.FSM.SetCurrentState(startingState)
        
        self.FSM.SetGlobalState(GlobalMinerState)

    def __init__(self, id, startingState, friend):
        self._myID = id
        self.friend = friend
        self.FSM = FiniteStateMachine(self)

        self.FSM.SetCurrentState(startingState)
        
        self.FSM.SetGlobalState(GlobalMinerState)       
          
    def Update(self):
        #Körs varje iteration
        self.FSM.Update()
     
    def HandleMessage(self, message):
        return self.FSM.HandleMessage(message)
        

    def assertNeeds(self):
        #Göra bools som kollas istället för att låta varje state kolla?
        #Dyrare men mer modulärt 
        
        pass

    def SetLocation(self,location):
        self.location = location

    
#===========================================================================================================
#===========================================================================================================


#===========================================================================================================
#===========================================================================================================
class Sleep(State):
    location = "Home"
    def Enter(Character):
        print(Character._myID +": " + "My one true love, the bed!")
        

        #Minska utmattning
    def Execute(Character):
        #If character is not tired anymore
        if(Character.Fatigue < 5):
            #Check if character is hungry
            if(Character.hunger > 0.5*Character.hungerLimit):
                #Check if there is any food at home 
                if(Character.foodAtHome > 0):
                    Character.FSM.SetNextState(EatingState)

                    pass
                #If no food
                else:
                    #go shop food if you have money
                    if (Character.moneyInBank > 5):
                        #go to store
                        #Character.FSM.SetNextState(ShoppingState)
                        pass
                    pass

            Character.fatigue = 0
            print(Character._myID + ": " + "woke")
            Character.FSM.SetNextState(WorkingState)
            Character.FSM.ChangeState(WalkingState)
            return
        Character.incrementFatigueBy(-5)
        
        print(Character._myID + ": " + "Sleeping..")
                        

    def Exit(Character):
        print(Character._myID + ": " + "Feeling rested!")


#===========================================================================================================
#===========================================================================================================
class EatingState(State):
    location = "Home"
    def Enter(Character):
        print(Character._myID +": " + "Mealtime!")
        

        #Minska utmattning
    def Execute(Character):
        
    
        if(Character.hunger > 0 and Character.foodAtHome > 0):
            Character.incrementFoodAtHomeBy(-1)
            Character.incrementHungerBy(-20)

            print(Character._myID + ": " + "eating..")
        else:
            Character.FSM.SetNextState(WorkingState)
            Character.FSM.ChangeState(WalkingState)

    def Exit(Character):
        print(Character._myID + ": " + "Feeling full!")

#===========================================================================================================
#===========================================================================================================
class WorkingState(State):
    location = "Mine"
    def Enter(Character):
        print(Character._myID + ": " + "All that glimmers is gold!!")
        

        #Öka törst och utmattning lite extra samt öka guld i fickan
    def Execute(Character): 
        Character.incrementFatigueBy(2)
        
        Character.incrementThirstBy(5)

        if (Character.miningGearDurability < 1):
            Character.incrementgoldCarriedBy(1)
            print(Character._myID + ": " + "Working..")
        else:
            Character.incrementgoldCarriedBy(2)
            Character.miningGearDurability -=1
            print(Character._myID + ": " + "Working fast!")
        
        if(Character.goldCarried > 10):
            Character.FSM.SetNextState(DepositGoldState)
            Character.FSM.ChangeState(WalkingState)


    def Exit(Character):
        print(Character._myID + ": " + "That´s enough work for now")


#===========================================================================================================
#===========================================================================================================
class DrinkingState(State):
    location = "Saloon"
    def Enter(Character):
        print(Character._myID + ": " + "*Dramatic entrance at the Saloon*, everyone sighs")
        

        #Minska törst
    def Execute(Character):
        Character.incrementThirstBy(-10)      
        print(Character._myID + ": " + "Drinking..")
        if(Character.Thirst < 1):
            Character.FSM.SetNextState(WorkingState)
            Character.FSM.ChangeState(WalkingState)


    def Exit(Character):
        print(Character._myID + ": " + "Kicked out of the Saloon..")

#===========================================================================================================
#===========================================================================================================
class ShoppinState(State):
    location = "Store"
    def Enter(Character):
        print(Character._myID + ": " + "Walks into store")
        

        #Minska törst
    def Execute(Character):

        print(Character._myID + ": " + "Checks out wares..")
        if(Character.foodAtHome < 4):
            if (Character.moneyInBank > 5):
                Character.incrementFoodAtHome(+2)
                Character.incrementMoneyInBank(-5)
                print(Character._myID + ": " + "This will be a mighty fine meal!")

        elif (Character.moneyInBank > 70):
            print(Character._myID + ": " + "This will make minin' a whole lot easier!")
            Character.miningGearDurability = 30
            Character.incrementMoneyInBank(-70)
            #buy mining equipment
            pass
         
        else: 
            Character.FSM.SetNextState(WorkingState)
            Character.FSM.ChangeState(WalkingState)

    def Exit(Character):
        print(Character._myID + ": " + "Leaving store...")

      
#===========================================================================================================
#===========================================================================================================
class DepositGoldState(State):
    location = "Bank"
    def Enter(Character):
        print(Character._myID + ": " + "Pockets are heavy!")
        

        #Minska guld i fickan öka pengar på banken
    def Execute(Character):
        print(Character._myID + ": " + "Depositing gold..")
        
        Character.incrementgoldCarriedBy(-2)
        
        Character.incrementmoneyInBankBy(20)
        
        if(Character.goldCarried < 1):
            Character.FSM.SetNextState(Sleep)
            Character.FSM.ChangeState(WalkingState)


    def Exit(Character):
        print(Character._myID + ": " + "That´s a lot of money, time for some rest")


#===========================================================================================================
#===========================================================================================================
class GlobalMinerState(State):

    #increment values that will naturally increase, hunger and fatigue
    def Execute(Character):
        Character.incrementFatigueBy(1)
        Character.incrementHungerBy(1)
        Character.incrementLonelinessBy(1)


        if(Character.Fatigue+5 > Character.FatigueLimit and Character.FSM.nextState != Sleep):
            Character.FSM.SetNextState(Sleep)
            Character.FSM.ChangeState(WalkingState)
            if(Character.appointment and Character.appointment.time_ - clock.getHours() < Places.instance.GetDistance(Character.location, Character.appointment.place_)):
                MessageDispatcher.instance.DispatchMessage(Character._myID, Character.friend,"Cancel_Appointment", 0,  None )
                #Cancel appointment
                Character.appointment = None
                pass            

        elif(Character.Thirst+5 > Character.ThirstLimit and Character.FSM.nextState != DrinkingState and Character.location != "Saloon" and Character.FSM.nextState != Sleep):
            print(Character._myID +": I´m thusty!")
            Character.FSM.SetNextState(DrinkingState)    
            Character.FSM.ChangeState(WalkingState)
            if(Character.appointment and Character.appointment.time_ - clock.getHours() < Places.instance.GetDistance(Character.location, Character.appointment.place_)):
                MessageDispatcher.instance.DispatchMessage(Character._myID, Character.friend,"Cancel_Appointment", 0,  None )
                Character.appointment = None
                #Cancel appointment
                pass    
        elif(Character.appointment and  Character.FSM.currentState != WalkingState and  Character.FSM.currentState != HangOut):
            print(Character._myID + ": " + Character.location + "<-char location, appointment-> " + Character.appointment.place_+ " appointment time ->" + str(Character.appointment.time_ - clock.getHours()))
            if(Character.appointment.time_ - clock.getHours() <= Places.instance.GetDistance(Character.location, Character.appointment.place_) + 1):
                print(Character._myID +": Walking to see firend")
                Character.FSM.SetNextState(HangOut)
                Character.FSM.ChangeState(WalkingState)

        elif(Character.Loneliness > Character.LonelyLimit  and not Character.appointment):
            XtraInfo = Appointment( int(clock.getHours()+8) , "Home")

            delay =  Places.instance.GetDistance(Character.location, EntityManager.instance.GetEntityFromID(Character.friend).location)
            MessageDispatcher.instance.DispatchMessage(Character._myID, Character.friend,"Let´s_meet_up!", delay,  XtraInfo )
           # XtraInfo.time_+= delay
            Character.appointment =  XtraInfo
           # print(Character.location + "<-char location, appointment-> " + Character.appointment.place_+ " appointment time ->" + str(Character.appointment.time_))
           
              #Drinking message 
    #        for x in EntityManager.instance.people:
    #            if x != Character._myID:
    #                MessageDispatcher.instance.DispatchMessage(Character._myID, x,1, 0, 0)

    def OnMessage(Reciever, Message):
      if (Message.Msg == "Good_day!"):
          print (Message.Sender + Message.Msg)
          print (Reciever.getID() + Message.Msg)
          EntityManager.instance.GetEntityFromID(Message.Sender).incrementLonelinessBy(-10)
          Reciever.incrementLonelinessBy(-10)
      elif (Message.Msg == "Let´s_meet_up!"):
          Reciever.appointment = Message.ExtraInfo
      elif (Message.Msg == "see_you_soon_ole_friend"):
          if Reciever.FSM.currentState == HangOut:
            Reciever.FSM.SetNextState(WorkingState)   
            Reciever.FSM.SetCurrentState(WalkingState)
          pass
      elif (Message.Msg == "Cancel_Appointment"):
          Reciever.appointment = None
         
          #svara och bli glad 
       
        #Drinking message 
        # if Reciever.Thirst > 20 and Reciever.FSM.nextState != Sleep and Reciever.FSM.currentState != Sleep:
         #   print(Reciever._myID + ": I´m thusty too!")
          #  Reciever.FSM.SetNextState(Drink)
         #   Reciever.FSM.ChangeState(walkState)

        
#===========================================================================================================
#===========================================================================================================

class WalkingState(State):

    def Enter(Character):
        
        if(Character.FSM.nextState == HangOut):
            if(Character.location == Character.appointment.place_):
                Character.distance = 0
            else:
                Character.distance = Places.instance.GetDistance(Character.location,  Character.appointment.place_)
            
        else:
            Character.distance = Places.instance.GetDistance(Character.location,  Character.FSM.nextState.location)
        print(Character._myID + ": Walking to " + Character.FSM.nextState.location + "...")
        


    def Execute(Character):
        if Character.distance <1:
            if(Character.appointment):
                Character.SetLocation(Character.appointment.place_)
            else:
                Character.SetLocation(Character.FSM.nextState.location)
            Character.FSM.ChangeState(Character.FSM.nextState)
            
        else:
            Character.distance -=1
            print(Character._myID + ": Walking... ")
        
    def Exit(Character):
        print(Character._myID + ": Finally Here!")
        if EntityManager.instance.GetEntityFromID(Character.friend).location == Character.location and (Character.location == "Store" or Character.location == "Saloon"):
            MessageDispatcher.instance.DispatchMessage(Character._myID, Character.friend,"Good_day!", 0, 0)
            pass #send message greeting 
        pass
        
#===========================================================================================================
#===========================================================================================================
class WaitingState(State):

    def Enter(Character):
        pass


    def Execute(Character):
        pass
    def Exit(Character):
        pass


    #===========================================================================================================
#===========================================================================================================
class HangOut(State):
    location =  ""
    def Enter(Character):
        print(Character._myID + ": Eyyyyy ")
        pass


    def Execute(Character):
        
        if EntityManager.instance.GetEntityFromID(Character.friend).FSM.currentState == HangOut:
            print(Character._myID + str(Character.Loneliness) +  ": Catchin up with.. " +  Character.friend)
            Character.incrementLonelinessBy(-10)
            if (Character.Loneliness < 1 and EntityManager.instance.GetEntityFromID(Character.friend).Loneliness < 1):
                Character.FSM.SetNextState(WorkingState)
                Character.FSM.ChangeState(WalkingState) 
                Character.appointment = None
        else:
             print(Character._myID + str(Character.Loneliness) +  ": Waiting for.. " +  Character.friend)

        pass
    def Exit(Character):

        print(Character._myID + ": See you soon ole friend! ")
        MessageDispatcher.instance.DispatchMessage(Character._myID, Character.friend,"see_you_soon_ole_friend", 0,  None)
        Character.appointment = None

        pass
                
#===========================================================================================================
#===========================================================================================================
class gameClock():
    seconds = 0
    minutes = 0
    hours = 0
    days = 0
    hoursTotal = 0
    
    def __init__(self):
        pass
    def Update(self):
        #self.seconds +=1
        self.hours +=1
        self.hoursTotal +=1
        if self.seconds == 60:
            self.minutes +=1
            self.seconds = 0
            if self.minutes == 60:
                self.hours +=1
                self.minutes = 0
        if self.hours == 24:
            self.days +=1
            self.hours = 0

    def getTime(self):
        return str("time: " + str(self.seconds) + "s  " +str(self.minutes) +"min  " +str(self.hours) + "h  "+ str(self.days)+ "days")
    def getHours(self):
        return self.hoursTotal
   
        


#============
#Miner tester
tom = Miner("tom", Sleep, "bert")
bert = Miner("bert", Sleep, "tom" )
#hakon = Miner("hakon", Sleep)
#maria = Miner("maria", Sleep)



#print(bert._myID)
plc = Places()
placea = Places()
clock = gameClock()
Dispatch = MessageDispatcher()

print (plc._places["Saloon"])

EntMng = EntityManager()
EntMng2 = EntityManager()

EntMng.RegisterEntity(tom)
EntMng.RegisterEntity(bert)

for x in EntMng.people:
    print(x)
for x in plc.instance._places:
    print(x)

bert.ThirstLimit = 50

tickTimePoint= time.time()
tickIntervall=30


while True:
    newTimePoint = time.time()
    if(newTimePoint >= tickTimePoint):
        bert.Update()
        tom.Update()
        print(str(tom.Thirst) + "  " + str(tom.Fatigue) + "  " + str(tom.goldCarried) + "  " + str(tom.distance) + "  " + str(tom.Loneliness))
        clock.Update()
        print(clock.getTime())
        tickTimePoint = newTimePoint + (1/tickIntervall)
        if (tom.fatigue > 10):
            raise Exception('tom is tired')
#while True:
