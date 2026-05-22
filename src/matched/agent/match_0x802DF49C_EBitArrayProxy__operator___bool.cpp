// 0x802DF49C EBitArrayProxy::operator^=(bool) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 29,0x4(3); mr 31,4; lwz 30,0x0(3); mr 4,29; mr 3,30; bl _s802DF49C_0; cmpwi 3,0; li 0,1; bne 0f; li 0,0; 0:; cmpwi 31,0; beq 1f; cmpwi 0,0; li 5,1; beq 3f; b 2f; 1:; cmpwi 0,0; li 5,1; bne 3f; 2:; li 5,0; 3:; mr 3,30; mr 4,29; bl _s802DF49C_1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802DF49C_0();
extern "C" void _s802DF49C_1();
extern "C" void f_802DF49C() {}
