// 0x8005B89C PlumbBobOwner::GrabPlumbBob(int, (300 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,4; mr 28,5; cmplwi 30,1; bgt 3f; rlwinm 0,30,2,0,29; addi 9,13,-21420; lwzx 11,9,0; mr 31,0; mr 29,9; cmpwi 11,0; bne 2f; cmpwi 30,0; beq 0f; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 1f; 0:; li 3,508; bl _s8005B89C_0; bl _s8005B89C_1; stwx 3,31,29; cmpwi 3,0; beq 3f; mr 4,30; bl _s8005B89C_2; 1:; addi 9,13,-21420; lwzx 0,31,9; cmpwi 0,0; beq 3f; 2:; addi 9,13,-21420; lwzx 11,31,9; lwz 0,0x16c(11); b 4f; 3:; li 0,0; 4:; cmpw 0,28; beq 8f; cmplwi 30,1; bgt 8f; rlwinm 0,30,2,0,29; addi 9,13,-21420; lwzx 11,9,0; mr 31,0; mr 29,9; cmpwi 11,0; bne 7f; cmpwi 30,0; beq 5f; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 6f; 5:; li 3,508; bl _s8005B89C_3; bl _s8005B89C_4; stwx 3,31,29; cmpwi 3,0; beq 8f; mr 4,30; bl _s8005B89C_5; 6:; addi 9,13,-21420; lwzx 0,31,9; cmpwi 0,0; beq 8f; 7:; addi 9,13,-21420; lwzx 11,31,9; stw 28,0x16c(11); 8:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8005B89C_0();
extern "C" void _s8005B89C_1();
extern "C" void _s8005B89C_2();
extern "C" void _s8005B89C_3();
extern "C" void _s8005B89C_4();
extern "C" void _s8005B89C_5();
extern "C" void f_8005B89C() {}
