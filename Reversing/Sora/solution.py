secret = 'aQLpavpKQcCVpfcg'
i = 0
key = ''

while i <= len(secret)-1:
    for s in range(63, 128):
        if (((s * 8 + 0x13) % 0x3d) + 0x41) == int(ord(secret[i])):
            key = key + chr(s)
    i = i + 1

print key
