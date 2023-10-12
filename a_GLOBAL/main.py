import serial
import time
import operator
import math
import socket
import struct
import receiveData as rc

BAUDRATE = 9600
INITSERVOPOS = 90
PITCHINTENSITY = 500
ROLLINTENSITY = 500

if __name__ == '__main__':
    # Create UDP socket.
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    # Bind to LFS.
    sock.bind(('127.0.0.2', 30000))
    ser = serial.Serial('COM13', BAUDRATE)
    
    while True:
        command = 'B'
        pitch = 0
        roll = 0

        pitch, roll = rc.receiveData(sock)

        pitch *= PITCHINTENSITY
        pitch = math.floor(pitch)
        
        roll *= ROLLINTENSITY
        roll = math.floor(roll)

        leftServoPos  = INITSERVOPOS - pitch + roll
        rightServoPos = INITSERVOPOS + pitch + roll
        
        leftServoPos = abs(leftServoPos)
        rightServoPos = abs(rightServoPos)

        if leftServoPos > 180: leftServoPos = 180
        if rightServoPos > 180: rightServoPos = 180
        
        if leftServoPos < 10:     command += f'00{leftServoPos}'
        elif leftServoPos < 100:  command += f'0{leftServoPos}'
        elif leftServoPos >= 100: command += f'{leftServoPos}'

        if rightServoPos < 10:     command += f'00{rightServoPos}'
        elif rightServoPos < 100:  command += f'0{rightServoPos}'
        elif rightServoPos >= 100: command += f'{rightServoPos}'
        
        print(command)
        
        if command:
            ser.write(command.encode())

    sock.close()