
from Entity import *
class Telegram:
    #Avsändare
    Sender = None

    #Mottagare
    Reciever = None

    #Meddelandet
    Msg = None

    #Fördröjning innan meddelandet "kommer fram"
    DispatchTime = 0

    #Eventuell extra info som man kan vilja skicka med
    ExtraInfo = None

    def __init__(self, senderID, Rcvr, Msg, DispatchTime, XtraInfo):
        self.Sender = senderID
        self.Reciever = Rcvr
        self.Msg = Msg
        self.DispatchTime = DispatchTime
        self.ExtraInfo = XtraInfo

class Appointment:

    time_ = 0
    place_ = ""
    def __init__(self, t, p):
        self.time_ = t
        self.place_ = p


class MessageDispatcher:
    
      #Gör en privat innre klass som användaren inte kommer åt direkt 
    class __MessageDispatcher:
 #Nått att containa meddelanden i (helst sorterat)
        PriorityQue = {}
        PushingList = []
        def __init__(self):
            pass

        

        #Skicka iväg meddelande genom att anropa meddelandemottagning hos mottagaren 
        def Discharge(self, Reciever, Msg):
            Reciever.HandleMessage(Msg)

        #Skicka
        def DispatchMessage(self,Sender, Rcvr, Msg, Delay, XtraInfo):
            Message = Telegram(Sender, Rcvr, Msg, Delay, XtraInfo)
            if Delay < 1:
                Reciever = EntityManager.instance.GetEntityFromID(Rcvr)
                self.Discharge(Reciever,Message)
            else:
                self.PushingList.append
  
        def DispatchDelayedMessage(self):
            for Message in self.PushingList:
                if Message.DispatchTime == 0:
                    self.Discharge(Message)
                else:
                    Message.DispatchTime +=1
                    

                        

    instance = None
#    #Om man försöker initiera en Singleton så kollar vi först om det finns
#    #en instans, om det gör det så byter vi värde på den existerande om inte  
#    #så skapas en instans.
    def __init__(self):
        if not MessageDispatcher.instance:
           MessageDispatcher.instance = MessageDispatcher.__MessageDispatcher()
        else:
            pass
    
   
#    #Get attribute omdirigerar anrop till den enda instansen som finns 
#    #Försöker man skapa flera så blir de bara proxy till samma instans. 
    def __getattr__(self, name):
        return getattr(self.instance,name)


