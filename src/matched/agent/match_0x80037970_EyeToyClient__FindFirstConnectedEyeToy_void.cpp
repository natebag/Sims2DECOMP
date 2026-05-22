// 0x80037970 EyeToyClient::FindFirstConnectedEyeToy(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); bl _s80037970_0; li 31,0; mr 30,3; cmpw 31,30; bge 2f; 0:; mr 3,31; bl _s80037970_1; cmpwi 3,0; beq 1f; mr 3,31; b 3f; 1:; addi 31,31,1; cmpw 31,30; blt 0b; 2:; li 3,-1; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80037970_0();
extern "C" void _s80037970_1();
extern "C" void f_80037970() {}
