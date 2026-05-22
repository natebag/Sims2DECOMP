// 0x8005BB94 PlumbBobOwner::PopPlumbBobOwner(int, (468 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,4; mr 28,5; cmplwi 30,1; bgt 3f; rlwinm 0,30,2,0,29; addi 9,13,-21420; lwzx 11,9,0; mr 31,0; mr 27,9; cmpwi 11,0; bne 2f; cmpwi 30,0; beq 0f; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 1f; 0:; li 3,508; bl _s8005BB94_0; bl _s8005BB94_1; stwx 3,31,27; cmpwi 3,0; beq 3f; mr 4,30; bl _s8005BB94_2; 1:; addi 9,13,-21420; lwzx 0,31,9; cmpwi 0,0; beq 3f; 2:; addi 9,13,-21420; lwzx 11,31,9; lwz 29,0x16c(11); b 4f; 3:; li 29,0; 4:; cmpw 29,28; bne 13f; cmpwi 29,0; beq 13f; cmplwi 30,1; bgt 8f; rlwinm 0,30,2,0,29; addi 9,13,-21420; lwzx 11,9,0; mr 31,0; mr 27,9; cmpwi 11,0; bne 7f; cmpwi 30,0; beq 5f; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 6f; 5:; li 3,508; bl _s8005BB94_3; bl _s8005BB94_4; stwx 3,31,27; cmpwi 3,0; beq 8f; mr 4,30; bl _s8005BB94_5; 6:; addi 9,13,-21420; lwzx 0,31,9; cmpwi 0,0; beq 8f; 7:; addi 9,13,-21420; lwzx 11,31,9; lwz 0,0x16c(11); mr 31,11; cmpw 0,29; beq 9f; 8:; li 31,0; 9:; cmpwi 31,0; beq 13f; addi 3,31,368; mr 4,31; bl _s8005BB94_6; lwz 29,0x16c(31); cmplwi 30,1; bgt 13f; rlwinm 0,30,2,0,29; addi 9,13,-21420; lwzx 11,9,0; mr 31,0; mr 27,9; cmpwi 11,0; bne 12f; cmpwi 30,0; beq 10f; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 11f; 10:; li 3,508; bl _s8005BB94_7; bl _s8005BB94_8; stwx 3,31,27; cmpwi 3,0; beq 13f; mr 4,30; bl _s8005BB94_9; 11:; addi 9,13,-21420; lwzx 0,31,9; cmpwi 0,0; beq 13f; 12:; addi 9,13,-21420; lwzx 11,31,9; stw 29,0x16c(11); 13:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8005BB94_0();
extern "C" void _s8005BB94_1();
extern "C" void _s8005BB94_2();
extern "C" void _s8005BB94_3();
extern "C" void _s8005BB94_4();
extern "C" void _s8005BB94_5();
extern "C" void _s8005BB94_6();
extern "C" void _s8005BB94_7();
extern "C" void _s8005BB94_8();
extern "C" void _s8005BB94_9();
extern "C" void f_8005BB94() {}
