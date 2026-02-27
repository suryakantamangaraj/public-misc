import sys
#search path
sys.path.append('//Users//suryaraj//Desktop//git//PythonProjects//DigitalCommunication') 

def sine_wave_demo():
    """
    Simulate a sinusoidal signal with given sampling rate
    """
import numpy as np
import matplotlib.pyplot as plt # library for plotting
from signalgen import sine_wave # import the function
f = 10 #frequency = 10 Hz
overSampRate = 30 #oversammpling rate
phase = 1/3*np.pi #phase shift in radians
nCyl = 5 # desired number of cycles of the sine wave
(t,g) = sine_wave(f,overSampRate,phase,nCyl) #function call
plt.plot(t,g) # plot using pyplot library from matplotlib package
plt.title('Sine wave f='+str(f)+' Hz') # plot title
plt.xlabel('Time (s)') # x-axis label
plt.ylabel('Amplitude') # y-axis label
plt.show() # display the figure