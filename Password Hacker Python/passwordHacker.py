import sys
import socket
import itertools
import string

args = sys.argv
if len(args) == 3:
    ip = args[1]
    port = int(args[2])
    # msg = args[3]
client_socket = socket.socket()
client_socket.connect((ip, port))
# letters = string.ascii_lowercase + string.digits
# rep = 1
# ok = False
# while not ok:
#     for i in itertools.product(letters, repeat=rep):
#         msg = "".join(i)
#         client_socket.send(msg)
#         response = client_socket.recv(1024)
#         response = response.decode()
#         if response == "Connection success!":
#             ok = True
#             print(msg.decode())
#             break
#     rep += 1


def search():
    with open("/Users/cata/Downloads/passwords.txt", 'r') as f:
        for line in f.readlines():
            for word in itertools.product(*[[letter.upper(), letter.lower()] if letter.isalpha() else letter for letter in line.strip('\n')]):
                msg = ''.join(word)
                msg = msg.encode()
                client_socket.send(msg)
                response = client_socket.recv(1024)
                response = response.decode()
                if response == "Connection success!":
                    print(msg.decode())
                    exit()


search()
