// 0x80030AC4 {anonymous}::IsPartOfDOFForeground(ESim (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32697; mr 30,3; addi 31,9,24012; lwz 3,0xe0(31); bl _s80030AC4_0; mr. 3,3; beq 2f; bl _s80030AC4_1; mr. 3,3; beq 2f; lwz 0,0xc(3); cmpwi 0,1; beq 2f; lwz 0,0xcc(31); addi 9,31,188; lwz 30,0x3d0(30); rlwinm 0,0,2,0,29; lwzx 31,9,0; cmpwi 30,0; beq 2f; cmpwi 31,0; beq 2f; li 29,0; cmpw 31,30; beq 0f; lwz 9,0x4(31); lha 3,0x330(9); lwz 0,0x334(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 1f; lwz 9,0x4(31); lha 3,0x368(9); lwz 0,0x36c(9); add 3,31,3; mtspr 8,0; blrl; cmpw 3,30; bne 1f; 0:; li 29,1; 1:; mr 3,29; b 3f; 2:; li 3,0; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80030AC4_0();
extern "C" void _s80030AC4_1();
extern "C" void f_80030AC4() {}
