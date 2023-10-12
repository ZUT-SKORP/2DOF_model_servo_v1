import serial
import time
import operator

import testRandPos as ts

BAUDRATE = 9600

if __name__ == '__main__':
    time.sleep(5)
    ser = serial.Serial('COM13', BAUDRATE)
    filePath = 'posData.bin'
    while True:
        if (ts.strToDat(filePath=filePath)):
            data = ts.datToStr(filePath)
            if data:
                ser.write(data.encode())
        time.sleep(2)