undefined8 check(void)

{
  int check_result;
  undefined8 uVar1;
  long in_FS_OFFSET;
  char local_2018 [8200];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  puts("Give me a key!");
  fgets(local_2018,0x2000,stdin);
  remove_newline(local_2018);
  check_result = check_1(local_2018);
  if (check_result != 0) {
    puts("You have passed the first test! Now I need another key!");
    fgets(local_2018,0x2000,stdin);
    remove_newline(local_2018);
    check_result = check_2(local_2018);
    if (check_result != 0) {
      puts("Nice work! You\'ve passes the second test, we aren\'t done yet!");
      fgets(local_2018,0x2000,stdin);
      remove_newline(local_2018);
      check_result = check_3(local_2018);
      if (check_result != 0) {
        puts("Congrats you finished! Here is your flag!");
        uVar1 = 1;
        goto LAB_00101450;
      }
    }
  }
  uVar1 = 0;
LAB_00101450:
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar1;
}
