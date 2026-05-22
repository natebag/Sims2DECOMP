// 0x8005B7E8 PlumbBobOwner::GetPlumbBob(int) (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,4; mr 29,3; cmplwi 31,1; bgt 3f; rlwinm 0,31,2,0,29; addi 11,13,-21420; lwzx 9,11,0; mr 30,0; cmpwi 9,0; bne 2f; cmpwi 31,0; beq 0f; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 1f; 0:; li 3,508; bl _s8005B7E8_0; bl _s8005B7E8_1; addi 9,13,-21420; cmpwi 3,0; stwx 3,30,9; beq 3f; mr 4,31; bl _s8005B7E8_2; 1:; addi 9,13,-21420; lwzx 0,30,9; cmpwi 0,0; beq 3f; 2:; addi 9,13,-21420; lwzx 11,30,9; lwz 0,0x16c(11); mr 3,11; cmpw 0,29; beq 4f; 3:; li 3,0; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8005B7E8_0();
extern "C" void _s8005B7E8_1();
extern "C" void _s8005B7E8_2();
extern "C" void f_8005B7E8() {}
