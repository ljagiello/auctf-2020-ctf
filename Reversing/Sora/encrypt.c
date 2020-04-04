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
