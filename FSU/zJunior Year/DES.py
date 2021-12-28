# Marshall Copeland
# mtc19a
# Due Date: 11/05/2021
# The program in this file is the individual work of Marshall Copeland

import random
from datetime import datetime

def encrypt(plaintext, key):
    encrypt = True
    blocks = []

    ciphertext = 0

    text_length = len(plaintext)

    for i in plaintext:
        ciphertext = ciphertext | ord(i)
        ciphertext = ciphertext << 8

    ciphertext = ciphertext >> 8

    count = 0

    while text_length % 8 != 0:
        count = count + 1
        text_length = text_length +1

    ciphertext = ciphertext << 8 * count

    bit_length = text_length * 8
    loop = int(bit_length / 64)
    shift = bit_length - 64

    for i in range(0, loop):
        blocks.append(ciphertext >> shift)
        ciphertext = ((ciphertext << 64) % (1 << bit_length)) | (ciphertext >> (64 - 1))

    ciphertext = ""

    shift = 56

    for i in blocks:
        temp_ciphertext = DES(i,key,encrypt)
        for i in range(0,8):
            ciphertext += chr(temp_ciphertext >> shift)
            temp_ciphertext = ((temp_ciphertext << 8) % (1 << 64)) | (temp_ciphertext >> (64 - 1))

    return ciphertext

def decrypt(ciphertext, key):
    decrypt = False
    blocks = []
    plaintext = 0
    
    text_length = len(ciphertext)
    
    for i in ciphertext:
        plaintext = plaintext | ord(i)
        plaintext = plaintext << 8
    plaintext = plaintext >> 8
    
    
    bit_length = text_length * 8
    loop = int(bit_length / 64)
    shift = bit_length - 64

    for i in range(0, loop):
        blocks.append(plaintext >> shift)
        plaintext = ((plaintext << 64) % (1 << bit_length)) | (plaintext >> (64 - 1))

    plaintext = ""

    shift = 56
    
    for i in blocks:
        temp_plaintext = DES(i,key,encrypt)
        for i in range(0,8):
            plaintext += chr(temp_plaintext >> shift)
            temp_plaintext = ((temp_plaintext << 8) % (1 << 64)) | (temp_plaintext >> (64 - 1))
    
    return plaintext

def DES(number, key, mode):
    IP = [58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8, 57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7]

    EP = [32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9, 8, 9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17, 16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25, 24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1]

    PC2 = [14, 17, 11, 24, 1,  5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13,  2, 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32]

    sbox_row0 = [14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7]
    sbox_row1 = [0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8]
    sbox_row2 = [4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0]
    sbox_row3 = [15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13]

    P = [16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10, 2, 8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25]

    final_perm = [40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29, 36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25]

    keys = [0] * 16

    for i in range(0,16):
        keys[i] = ((key << (i + 1)) % (1 << 64)) | (key >> (64 - 1))

    if mode == False:
        keys.reverse()

    new_number = 0

    for i in range(63, -1, -1):
        shift = IP[i] - 1
        shifted_number = number >> shift

        if shifted_number % 2 == 0:
            bit = 0
        else:
            bit = 1

        new_number = new_number | bit

        if IP[i] == 58:
            new_number = new_number << 1

    number = new_number
    left_half = 0
    right_half = 0

    for i in range(1,17):
        if i == 0:
            left_half = number >> 32
            right_half = ((number << 32) % (1 << 64)) | (number >> (64 - 1))
            old_right_half = right_half
            right_half = right_half >> 32

        else:
            old_right_half = ((number << 32) % (1 << 64)) | (number >> (64 - 1))
        
        key = keys[i-1]
        new_key = 0

        for i in range(47, -1, -1):
            shift = PC2[i]
            shifted_key = key >> shift

            if shifted_key % 2 == 0:
                bit = 0
            else:
                bit = 1

            new_key = new_key | bit

            if PC2[i] != 14:
                new_key = new_key << 1
            
        key = new_key

        new_right_half = 0

        for i in range(47, -1, -1):
            shift = EP[i]
            shifted_right_half = right_half >> shift

            if shifted_right_half % 2 == 0:
                bit = 0
            else:
                bit = 1

            new_right_half = new_right_half | bit

            if PC2[i] != 32:
                new_right_half = new_right_half << 1

        right_half = new_right_half ^ key
    
        block = 0
        temp_block = 0
        row = 0
        col = 0

        for i in range(0,48,6):
            if i == 0:
                temp_block = right_half >> 42
                row = temp_block >> 5
                row << 1
                row = row | (((temp_block << 5) % (1 << 6)) | (temp_block >> (6 - 1)) >> 5)
                col = (((temp_block << 2) % (1 << 6)) | (temp_block >> (6 - 1))) >> 2
                
                if row == 0:
                    temp_block = sbox_row0[col]
                elif row == 1:
                    temp_block = sbox_row1[col]
                elif row == 2:
                    temp_block = sbox_row2[col]
                elif row == 3:
                    temp_block = sbox_row3[col]

                block = temp_block << 4

            else:
                temp_block = (((right_half << i) % (1 << 48)) | (right_half >> (48 - 1))) >> 42
                row = temp_block >> 5
                row << 1
                row = row | (((temp_block << 5) % (1 << 6)) | (temp_block >> (6 - 1)) >> 5)
                col = (((temp_block << 2) % (1 << 6)) | (temp_block >> (6 - 1))) >> 2

                if row == 0:
                    temp_block = sbox_row0[col]
                elif row == 1:
                    temp_block = sbox_row1[col]
                elif row == 2:
                    temp_block = sbox_row2[col]
                elif row == 3:
                    temp_block = sbox_row3[col]

                block = block << 4
                block = block | temp_block

        right_half = block


        for i in range(31,-1,-1):
            shift = P[i]
            shifted_right_half = right_half >> shift
        
            if shifted_right_half % 2 == 0:
                bit = 0
            else:
                bit = 1

            new_right_half = shifted_right_half | bit

            if P[i] != 16:
                new_right_half = new_right_half << 1

        right_half = new_right_half ^ left_half
        left_half = right_half

        number = left_half
        number = number << 32
        number = number | right_half

        for i in range(63,-1,-1):
            shift = final_perm[i]
            shifted_number = number >> shift
        
            if shifted_number % 2 == 0:
                bit = 0
            else:
                bit = 1

            new_number = shifted_number | bit

            if final_perm[i] != 40:
                new_number = new_number << 1

        left_half = old_right_half
        number = new_number

    return number

if __name__ == "__main__":
    print("DES Implementation:")
    plaintext = input("Enter text to encrypt (\"Exit\" to quit): ")

    while plaintext != "Exit":
        random.seed(datetime.now())
        key = random.getrandbits(56)

        ciphertext = encrypt(plaintext, key)
        print("Encrypted text: ")
        print(ciphertext)

        print("Decrypted text: ", end="")
        print(decrypt(ciphertext, key))

        plaintext = input("Next text (\"Exit\" to quit): ")
