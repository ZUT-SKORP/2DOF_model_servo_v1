import serial
import math
import socket
import game_data



HOST = '127.0.0.2'
PORT = 30000
COM = 'COM13'
BAUDRATE = 9600
INIT_SERVO_POS = 90
MAX_SERVO_POS = 180
PITCH_INTENSITY = 500
ROLL_INTENSITY = 500
BOTH = 'B'
LEFT = 'L'
RIGHT = 'R'



if __name__ == '__main__':
    # Create UDP socket.
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    # Bind to LFS.
    sock.bind((HOST, PORT))
    ser = serial.Serial(COM, BAUDRATE)
    
    while True:
        command = 'B'
        pitch = 0
        roll = 0

        pitch, roll = game_data.receiveData(sock)

        pitch *= PITCH_INTENSITY
        pitch = math.floor(pitch)
        
        roll *= ROLL_INTENSITY
        roll = math.floor(roll)

        leftServoPos  = INIT_SERVO_POS - pitch + roll
        rightServoPos = INIT_SERVO_POS + pitch + roll
        
        leftServoPos = abs(leftServoPos)
        rightServoPos = abs(rightServoPos)

        if leftServoPos > MAX_SERVO_POS: leftServoPos = MAX_SERVO_POS
        if rightServoPos > MAX_SERVO_POS: rightServoPos = MAX_SERVO_POS
        
        # preaparing bytes for broadcast
        command = chr(1) + chr(leftServoPos) + chr(rightServoPos)
        
        print(command)
        
        if command:
            ser.write(command.encode())

    sock.close()