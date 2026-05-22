// 0x8036E3E8 vprintf (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,-27948(13); mr 0,3; mr 5,4; lwz 3,0x8(9); mr 4,0; bl _s8036E3E8_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8036E3E8_0();
extern "C" void f_8036E3E8() {}
