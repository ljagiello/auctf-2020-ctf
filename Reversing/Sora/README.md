# Reversing - Sora

## Challenge
This obnoxious kid with spiky hair keeps telling me his key can open all doors.

Can you generate a key to open this program before he does?

Connect to `challenges.auctf.com 30004`

Author: nadrojisk

## Solution
This is a reverse challenge. First lets see what strings we have in a binary (I will skip not important ones):
```
[…]
aQLpavpKQcCVpfcg
Give me a key!
That's not it!
flag.txt
[…]
```

With Ghidra we can decompile `sora`.

The important function is `encrypt`:
```
void encrypt(char *__block,int __edflag)

{
  size_t size;
  int i;

  i = 0;
  while ((size = strlen(secret), (ulong)(long)i < size &&
         (((int)__block[i] * 8 + 0x13) % 0x3d + 0x41 == (int)(char)secret[i]))) {
    i = i + 1;
  }
  return;
}
```

`secret` string is `aQLpavpKQcCVpfcg`.

To solve this challenge we need to inverse mod operator, simple bruteforce should be helpful here:
```
secret = 'aQLpavpKQcCVpfcg'
i = 0
key = ''

while i <= len(secret)-1:
    for s in range(63, 128):
        if (((s * 8 + 0x13) % 0x3d) + 0x41) == int(ord(secret[i])):
            key = key + chr(s)
    i = i + 1

print key
```

The key is:
```
try_to_break_meG
```

## Links
* https://ghidra-sre.org/

## Flag
```
auctf{that_w@s_2_ezy_29302}
```
