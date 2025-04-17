import serial, time

ser = serial.Serial('COM3', 9600, timeout=0.1)         # 1/timeout is the frequency at which the port is read
while True:

    data = ser.readline().decode().strip()

    if data:
        print(data)
    elif data:
        print(data)