import sys
import pickle

Usage = f'''
python3 {__file__} <n> <d> <file>
'''
n = int(sys.argv[1])
d = int(sys.argv[2])
filename = sys.argv[3]

with open(filename, 'rb') as f:
    cipher_int = pickle.load(f)
    decrypted_int = [pow(i, d, n) for i in cipher_int]
    decrypted_bytes = bytes(decrypted_int)
    
with open(filename, 'wb') as f:
    f.write(decrypted_bytes)
