import sys
import pickle

Usage = f'''
python3 {__file__} <n> <e> <file>
'''
n = int(sys.argv[1])
e = int(sys.argv[2])
filename = sys.argv[3]

plain_bytes = b''
with open(filename, 'rb') as f:
    plain_bytes = f.read()
cipher_int = [pow(i, e, n) for i in plain_bytes]
with open(filename, 'wb') as f:
    pickle.dump(cipher_int, f)
