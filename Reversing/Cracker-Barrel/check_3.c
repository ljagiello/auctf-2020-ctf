ulong check_3(char *key3)

{
  bool bVar1;
  size_t sVar2;
  void *pvVar3;
  long in_FS_OFFSET;
  int local_5c;
  int local_54;
  int local_48 [4];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  long local_20;

  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_48[0] = 0x7a;
  local_48[1] = 0x21;
  local_48[2] = 0x21;
  local_48[3] = 0x62;
  local_38 = 0x36;
  local_34 = 0x7e;
  local_30 = 0x77;
  local_2c = 0x6e;
  local_28 = 0x26;
  local_24 = 0x60;
  sVar2 = strlen(key3);
  pvVar3 = malloc(sVar2 << 2);
  local_5c = 0;
  while (sVar2 = strlen(key3), (ulong)(long)local_5c < sVar2) {
    *(uint *)((long)pvVar3 + (long)local_5c * 4) = (int)key3[local_5c] + 2U ^ 0x14;
    local_5c = local_5c + 1;
  }
  bVar1 = false;
  local_54 = 0;
  while (sVar2 = strlen(key3), (ulong)(long)local_54 < sVar2) {
    if (*(int *)((long)pvVar3 + (long)local_54 * 4) != local_48[local_54]) {
      bVar1 = true;
    }
    local_54 = local_54 + 1;
  }
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (ulong)!bVar1;
}
