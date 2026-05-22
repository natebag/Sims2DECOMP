// 0x800D79F8 CTGFileImpl::ReadFloat(float (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-21432(13); bl _s800D79F8_0; cmpwi 28,1; beq 0f; addi 3,31,40; addi 4,1,8; bl _s800D79F8_1; stb 24,0x134(31); 0:; mr 3,28; lwz 0,0x13c(1); mtspr 8,0; lmw 24,0x118(1); addi 1,1,312"
extern "C" void _s800D79F8_0();
extern "C" void _s800D79F8_1();
extern "C" void f_800D79F8() {}
