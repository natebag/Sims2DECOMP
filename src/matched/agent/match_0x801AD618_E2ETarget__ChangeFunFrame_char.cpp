// 0x801AD618 E2ETarget::ChangeFunFrame(char (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; mr 3,5; bl _s801AD618_0; cmpwi 3,99; bne 0f; li 3,-1; 0:; stw 3,0xbc(31); bl _s801AD618_1; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801AD618_0();
extern "C" void _s801AD618_1();
extern "C" void f_801AD618() {}
