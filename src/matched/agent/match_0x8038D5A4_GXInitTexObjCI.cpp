// 0x8038D5A4 GXInitTexObjCI (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-48(1); stw 31,0x2c(1); lwz 31,0x38(1); stw 30,0x28(1); mr 30,3; bl _s8038D5A4_0; lbz 0,0x1f(30); rlwinm 0,0,0,31,29; stb 0,0x1f(30); stw 31,0x18(30); lwz 0,0x34(1); lwz 31,0x2c(1); lwz 30,0x28(1); addi 1,1,48; mtspr 8,0"
extern "C" void _s8038D5A4_0();
extern "C" void f_8038D5A4() {}
