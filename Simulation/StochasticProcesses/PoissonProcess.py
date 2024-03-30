import numpy as np
import matplotlib.pyplot as plt
import math

# POISSON PROCESS 

class PoissonProces:
    def __init__(self, avgRate, sim_time):
        self.m_lambda = avgRate
        self.m_simulationTime = sim_time
        self.m_uniformRandomVariablesSet = []
        self.m_interArrivalTimesSet = [0]
        self.m_arrivalTimesSet = [0]
        self.m_numberOfEvents = [0]
        self.generateUniformRandomVariable(self.m_simulationTime)    
        self.generateInterArrivalTimes()

    def generateUniformRandomVariable(self, NumOfRandomVariables):
        self.m_uniformRandomVariablesSet = np.random.uniform(size=NumOfRandomVariables)

    def generateInterArrivalTimes(self):
        self.m_interArrivalTimesSet = [(-math.log(1-x))/self.m_lambda for x in self.m_uniformRandomVariablesSet] 

    def getArrivalTimes(self):
        return self.m_arrivalTimesSet

    def getEvents(self):
        return self.m_numberOfEvents

    def simulate(self,  SimTime = None):
        if SimTime is None:
            SimTime = self.m_simulationTime

        t = 0
        events_count = 0
        for i in self.m_interArrivalTimesSet:
            if t<=SimTime:
                t+=i
                self.m_arrivalTimesSet.append(t)
                events_count+=1
                self.m_numberOfEvents.append(events_count)
 


# SIMULATION DRIVER. 

if __name__ == "__main__":
    SimulationTime = 50
    AverageRate = 0.5
    Process = PoissonProces(AverageRate,SimulationTime)
    Process.simulate()

    x = Process.getArrivalTimes()
    y = Process.getEvents()
    plt.xlim(0,SimulationTime)
    plt.ylim(0,max(y) + 10)
    plt.xlabel("Time")
    plt.ylabel("Total Events")
    plt.title("Poisson Process with   $\lambda$ = " + str(AverageRate))
    plt.step(x,y, where="post")
    plt.show()





