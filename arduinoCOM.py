#Shivane Rathore Arduino/Python Communication + Graph

#packages
import serial
import pandas as pd
import matplotlib.pyplot as plt
import time

ser = serial.Serial('/dev/cu.usbmodem14101', 9600) #serial port and baud rate
dbList = []
df = pd.DataFrame() #empty data frame

#creates a graph
with open("db.csv", "a") as graph:
    plt.ion() #turns on interactive mode for Matplotlib
    while ser:
        data = ser.readline().decode('utf-8').strip() #reads a line of data from the serial port and decode it as UTF-8
        print(data) 
        dbList.append(data)
        graph.write(data + "\n")  #writes the data to the file, followed by a newline character
        df['New Column'] = pd.Series(dbList)
        plt.clf() #clears the current figure
        plt.plot(dbList)
        plt.title('Graph of db')
        plt.draw() #draw the updated plot
        plt.savefig('graph.png') #save the plot as an image
        plt.pause(0.01) #pauses to allow time for the plot to update
        #time.sleep(500)
        

