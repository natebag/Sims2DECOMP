// 0x800AF72C cBoxX::AddToInstanceMap(ERSoundEvent (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 29,0x34(1); stw 0,0x44(1); mr 30,3; mr 31,4; mr 29,5; mr 4,30; addi 3,1,8; mr 5,31; mr 6,29; bl _s800AF72C_0; addi 4,30,32; lwz 9,0x8(1); lwz 0,0x4(4); cmpw 9,0; stw 0,0x10(1); bne 0f; stw 31,0x28(1); addi 3,1,32; stw 29,0x2c(1); addi 5,1,40; stw 31,0x18(1); stw 29,0x1c(1); bl _s800AF72C_1; 0:; lwz 0,0x44(1); mtspr 8,0; lmw 29,0x34(1); addi 1,1,64"
extern "C" void _s800AF72C_0();
extern "C" void _s800AF72C_1();
extern "C" void f_800AF72C() {}
