
class BaseGameEntity:
    _myID = ""
    _nextID = ""

    def __init__(self, newID):
        _myID = newID
        EntityManager.RegisterEntity(self)

    def setID(value):
        #Se till att ID är större än eller lika med nästa tillgängliga ID 
        #inkrementerar sedan _nextID 
        pass

    def Update():
        pass

    def getID(self):
        return self._myID

    def HandleMessage(self, Message):
       # print ("Message handled by: " + self.getID() + " at" + clock.getTime() )
        pass


class EntityManager:

    class __EntityManager:
        entities = {}
        def __init__(self):
            pass

        def RegisterEntity(self, entity):
            self.entities[entity._myID] = entity
 
        def GetEntityFromID(self, id):
            return self.entities[id]
                  
        def RemoveEntity(self, id):
            self.entities.pop(id)


    #Om man försöker instansiera en ny så händer inget om det redan finns en instans av __EntityManager 
    instance = None
    def __init__(self):
        if not EntityManager.instance:
            EntityManager.instance = EntityManager.__EntityManager()
        else:
            pass

    #Gör så att jag kommer åt attribut/funktioner från instansen av __EntityMngr även om jag bara skriver EntityMngr.someThing
    def __getattr__(self, name):
        return getattr(self.instance,name)