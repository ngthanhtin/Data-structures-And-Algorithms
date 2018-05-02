# -*- coding: utf-8 -*-
"""
Created on Wed May  2 15:04:35 2018

@author: Admin
https://www.datacamp.com/community/tutorials/markov-chains-python-tutorial
"""


import numpy as np
import random as rm
#the statespace
states = ["Sleep", "Icecream", "Run"]
#possilbe sequence of events
transitionName = [["SS", "SR", "SI"], ["RS", "RR", "RI"], ["IS", "IR", "II"]]
#probabilities matrix (transition maxtrix)
transitionMatrix = [[0.2,0.6,0.2], [0.1,0.6,0.3], [0.2,0.7,0.1]]

if sum(transitionMatrix[0]) + sum(transitionMatrix[1]) + sum(transitionMatrix[2]) != 3:
    print("Somewhere, something went wrong. Transition matrix, perhaps ?")
else:
    print("All is gonna be ok, you should move on")
#a function that implements the Markov model to forecast the state/mood
def activity_forecast(days):
    #choose the starting state
    activityToday = "Sleep"
    #print("Start state: " + activityToday)
    # Shall store the sequence of states taken.
    #So, this only has the starting state for now.
    activityList = [activityToday]
    i = 0
    # To calculate the probability of the activityList
    prob = 1
    while i != days:
        if activityToday == "Sleep":
            change = np.random.choice(transitionName[0], replace = True, p=transitionMatrix[0])
            if change == "SS":
                prob = prob * 0.2
                activityList.append("Sleep") # no need to update activityToday
                pass
            elif change == "SR":
                prob = prob * 0.6
                activityToday = "Run"
                activityList.append("Run")
            else:
                prob = prob * 0.2
                activityToday = "Icecream"
                activityList.append("Icecream")
        elif activityToday == "Run":
            change = np.random.choice(transitionName[1],replace=True,p=transitionMatrix[1])
            if change == "RR":
                prob = prob * 0.5
                activityList.append("Run")
                pass
            elif change == "RS":
                prob = prob * 0.2
                activityToday = "Sleep"
                activityList.append("Sleep")
            else:
                prob = prob * 0.3
                activityToday = "Icecream"
                activityList.append("Icecream")
        elif activityToday == "Icecream":
            change = np.random.choice(transitionName[2],replace=True,p=transitionMatrix[2])
            if change == "II":
                prob = prob * 0.1
                activityList.append("Icecream")
                pass
            elif change == "IS":
                prob = prob * 0.2
                activityToday = "Sleep"
                activityList.append("Sleep")
            else:
                prob = prob * 0.7
                activityToday = "Run"
                activityList.append("Run")
        i = i + 1
    #end while
    return activityList

# To save every activityList
list_activity = []
count = 0
# `Range` starts from the first count up until but excluding the last count
for iterations in range(1,10000):
        list_activity.append(activity_forecast(2))
# Check out all the `activityList` we collected    
#print(list_activity)
# Iterate through the list to get a count of all activities ending in state:'Run'
for smaller_list in list_activity:
    if(smaller_list[2] == "Run"):
        count += 1
# Calculate the probability of starting from state:'Sleep' and ending at state:'Run'
percentage = (count/10000) * 100
print("The probability of starting at state:'Sleep' and ending at state:'Run'= " \
      + str(percentage) + "%")
                
            