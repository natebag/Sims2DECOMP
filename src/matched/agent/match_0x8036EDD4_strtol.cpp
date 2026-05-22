// 0x8036EDD4 strtol (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 0,3; mr 9,4; mr 6,5; lwz 3,-27948(13); mr 4,0; mr 5,9; bl _s8036EDD4_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8036EDD4_0();
extern "C" void f_8036EDD4() {}
