
class Places:
    class __Places:
        _places = {  

            #Saloon to:
         "Saloon": {"Saloon" : 0,
             "Store" : 1,
          "Home" :3,
         "Mine" : 4,
          "Bank" : 2},
         #Mine to:
         "Mine": {"Mine" : 0,
             "Store" : 4,
         "Home" : 5,
          "Bank" : 2,
           "Saloon" : 4},
         #Bank to:
         "Bank":  {"Bank" : 0,
             "Store" : 2,
          "Mine" : 2,
          "Home" : 3,
          "Saloon" : 2},
         #Home to:
         "Home": {"Home" : 0,
             "Store" : 3,
          "Bank" : 4,
          "Mine" : 5,
          "Saloon" : 3},
         #Store to:
         "Store":{"Store" : 0,
             "Home" : 3,
         "Bank" : 2,
         "Mine" : 4,
         "Saloon" : 1}
         #Graveyard to:
         }
        
        def __init__(self):
            pass

        def GetDistance(self, froM, tO):
            return self._places[froM][tO]

    instance = None
    def __init__(self):
        if not Places.instance:
            Places.instance = Places.__Places()
        else:
            pass

    def __getattr__(self, name):
        return getattr(self.instance, name)