ulong check_2(char *key2)

{
  int iVar1;
  size_t sVar2;
  char *__s1;
  int local_20;

  sVar2 = strlen(key2);
  iVar1 = (int)sVar2;
  __s1 = (char *)malloc((long)(iVar1 + 1) << 3);
  local_20 = 0;
  while (local_20 < iVar1) {
    __s1[local_20] = "si siht egassem terces"[(iVar1 + -1) - local_20];
    local_20 = local_20 + 1;
  }
  iVar1 = strcmp(__s1,key2);
  return (ulong)(iVar1 == 0);
}
