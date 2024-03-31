import numpy as np
import matplotlib.pyplot as plt
import math

# Gambler's Process, a discrete time markov chain

class GamblerRuinProces:
	def __init__(self, p, StartingAmount, FinalMaxAmount):
		self.m_p = p
		self.m_StartingAmount = StartingAmount
		self.m_FinalMaxAmount = FinalMaxAmount
		self.m_x = []
		self.m_y = []
	def simulate(self):
		n = 0
		self.m_x.append(n)
		self.m_y.append(self.m_StartingAmount )
		CurrentAmount = self.m_StartingAmount
		while CurrentAmount != 0 and CurrentAmount != self.m_FinalMaxAmount:
			n+=1
			self.m_x.append(n)	
			u = np.random.uniform(size=1)	
			if u < self.m_p:
				CurrentAmount+=1 
			else:
				CurrentAmount-=1
			self.m_y.append(CurrentAmount)			
	def SimulationPaths(self):
		return self.m_x, self.m_y

	def clear(self):
		self.m_x = []
		self.m_y = []


# SIMULATION DRIVER. 

if __name__ == "__main__":
	p = 0.5
	StartingAmount = 10
	FinalMaxAmount = 20
	gambler = GamblerRuinProces(p,StartingAmount,FinalMaxAmount)
	
	plt.xlabel("Time")
	plt.ylabel("Current Amount")
	plt.title("Gambler's Ruin with P=" + str(p))

	for i in range(1,10):
		gambler.simulate()
		x,y = gambler.SimulationPaths()
		gambler.clear()
		plt.plot(x,y)
	
	plt.show()





