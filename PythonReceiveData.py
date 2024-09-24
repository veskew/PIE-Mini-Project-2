#      ******************************************************************
#      *                                                                *
#      *    Receive data for a 3d scan from the Arduino                 *
#      *                                                                *
#      *    Notes: The script was developed in python 3. The script uses "pyserial".
#      *    While the script is running, the Arduino can not be re-programed.
#      *    Exit this script before downloading a new Arduino sketch.
#      *                                                                *
#      ******************************************************************

import gitignore
import serial
import csv

arduinoComPort = gitignore.SerialPort     # Serial port for the Arduino.
baudRate = 9600             # Baud rate of the Arduino.

# open the serial port
serialPort = serial.Serial(arduinoComPort, baudRate, timeout=1)

fileName = "Scan_1.csv"     # Name of the file to save the data.
dataFields = ["Distance", "Pan Angle", "Tilt angle"]

with open(fileName, 'w') as csvfile:
  csvWriter= csv.DictWriter(csvfile, fieldnames=dataFields)
  csvWriter.writeheader()

# main loop to read data from the Arduino and write it in a JSON file.
while True:
  #
  # Read a line of data from the serial port, then convert it from an
  # array of bytes to a string using ".decode()".
  #
  lineOfData = serialPort.readline().decode()

  if len(lineOfData) > 0:  # If data was received
    print("*" + lineOfData)
    sensor_distance, servo_pan_angle, servo_tilt_angle = (int(x) for x in lineOfData.split(',')) # Convert it to 3 data integers

    with open(fileName, 'a') as csvfile:
      csvWriter= csv.writer(csvfile)
      csvWriter.writerow([sensor_distance, servo_pan_angle, servo_tilt_angle])
      csvfile.close()
    
    """
    print("Distance = " + str(sensor_distance), end="")
    print(", Pan Angle = " + str(servo_pan_angle), end="")
    print(", Tilt angle = " + str(servo_tilt_angle))
"""
