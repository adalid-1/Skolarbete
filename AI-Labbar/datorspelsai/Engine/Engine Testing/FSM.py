
class FiniteStateMachine():

    owner = None

    #Vad man gör just nu
    currentState = None

    #För att kunna fortsätta med något efter nått
    previousState = None

    #Vad gör ägaren alltid
    globalState = None

    #Vad ägaren ska göra efter nuvarande state
    nextState = None
    
        #ger tillgång till ägaren
    def __init__(self, owner):
        self.owner = owner

        #Ittererar varje tick
    def Update(self):
        self.globalState.Execute(self.owner)
        self.currentState.Execute(self.owner)
        
        

      #Byta tillstånd
    def ChangeState(self, newState):
        #Försök inte byta från ditt nuvarande state till samma 
        if (self.currentState != newState):

            #avsluta current state
            self.currentState.Exit(self.owner)
            #Spara föregående state
            self.previousState = self.currentState
            #Ersätt currentState med newState
            self.currentState = newState
            #Kör ingångsfunktionen till det nya tillståndet
            self.currentState.Enter(self.owner)
        else:
            pass

    def HandleMessage(self,message):
        if self.currentState.OnMessage(self.owner, message):
            return True
        elif self.globalState.OnMessage(self.owner, message):
            return True
        return False


        #Setters
    def SetCurrentState(self, newState):
        self.currentState = newState
    def SetGlobalState(self, newState):
        self.globalState = newState
    def SetNextState(self, newState):
        self.nextState = newState
    


#===========================================================================================================
#===========================================================================================================

class State:
    def __init__():
        pass

    def Enter(BaseGameEntity):
        pass

    def Execute(BaseGameEntity):
        pass

    def Exit(BaseGameEntity):
        pass

    def OnMessage(BaseGameEnitity, Message):
        pass
