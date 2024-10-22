import pandas as pd
import serial
import time

ports = serial.tools.list_ports.comports()
ser = serial.Serial()
portlist = []

data = pd.DataFrame(columns=['Time', 'Light Intensity'])  

for comPort in ports:
    portlist.append(str(comPort))

print(portlist)
selectedPort = int(input("Select index for port to use (Use Array Index): "))
if(selectedPort >= len(portlist) or selectedPort < 0):
    print("Invalid option")
    quit()
openPort = portlist[int(selectedPort)]
print(openPort)

ser.baudrate = 9600
ser.port = openPort
ser.open()

cnt = 0
while(cnt < 7200):
    if ser.in_waiting:
        serialMessage = ser.readline().decode('utf')
        currentTime = time.strftime('%Y-%m-%d %H:%M:%S')

        nextRow = {'Time': currentTime, 'Light Intensity': serialMessage}
        data.loc[len(df)] = [currentTime, serialMessage]
        time.sleep(1)

print(data)

data.to_csv('light_intensity_data.csv', index=False)