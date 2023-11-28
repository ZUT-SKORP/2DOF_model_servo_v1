import struct

def receiveData(sock) -> float:

    # Receive data.
    data = sock.recv(256)

    if not data:
        raise(Exception) # Lost connection

    # Unpack the data.
    outsim_pack = struct.unpack('I12f3i', data)
    pitch = outsim_pack[5]
    roll = outsim_pack[6]

    return pitch, roll