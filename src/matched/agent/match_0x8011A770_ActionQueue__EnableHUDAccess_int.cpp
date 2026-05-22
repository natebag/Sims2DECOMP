// 0x8011A770 ActionQueue::EnableHUDAccess(int) (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32697; mr 30,3; lwz 3,0x5bcc(9); mr 31,4; li 29,0; cmpwi 3,0; beq 0f; bl _s8011A770_0; cmpwi 3,0; beq 0f; li 29,1; 0:; cmpwi 29,0; beq 3f; li 0,0; stb 31,0x2b1(30); stb 0,0x2b0(30); lis 9,-32697; lwz 3,0x5bcc(9); cmpwi 3,0; beq 1f; mr 4,31; bl _s8011A770_1; 1:; lwz 9,0x2ac(30); li 31,0; lwz 0,0x2a8(30); cmpw 9,0; beq 3f; 2:; mr 4,31; mr 3,30; bl _s8011A770_2; addi 31,31,1; lwz 0,0x2ac(30); lwz 9,0x2a8(30); subf 0,9,0; cmplw 31,0; blt 2b; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8011A770_0();
extern "C" void _s8011A770_1();
extern "C" void _s8011A770_2();
extern "C" void f_8011A770() {}
