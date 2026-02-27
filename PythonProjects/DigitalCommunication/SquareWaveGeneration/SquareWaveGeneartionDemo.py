import sys
#search path
sys.path.append('//Users//suryaraj//Desktop//git//PythonProjects//DigitalCommunication') 

def square_wave_demo():
    """
    Simulate a square wave signal with given sampling rate
    """
import numpy as np
import matplotlib.pyplot as plt # library for plotting
from signalgen import square_wave # import the function
f = 10 #frequency = 10 Hz
overSampRate = 30 #oversammpling rate
nCyl = 5 # desired number of cycles of the sine wave
(t,g) = square_wave(f,overSampRate,nCyl) #function call
plt.plot(t,g) # plot using pyplot library from matplotlib package
plt.title('Square wave f='+str(f)+' Hz') # plot title
plt.xlabel('Time (s)') # x-axis label
plt.ylabel('Amplitude') # y-axis label
plt.show() # display the figure