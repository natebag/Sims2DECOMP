// 0x80038FE0 EyeToyClient::IsSessionEyeToyDisconnected(void) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,-32576(13); li 3,1; cmpwi 0,-1; beq 0f; mr 3,0; bl _s80038FE0_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80038FE0_0();
extern "C" void f_80038FE0() {}
