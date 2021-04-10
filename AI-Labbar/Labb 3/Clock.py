
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