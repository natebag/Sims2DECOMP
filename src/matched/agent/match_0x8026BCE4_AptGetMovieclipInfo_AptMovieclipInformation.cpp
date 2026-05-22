// 0x8026BCE4 AptGetMovieclipInfo(AptMovieclipInformation (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 9,-23008(13); mr 30,3; addi 3,9,40; bl _s8026BCE4_0; mr 4,30; bl _s8026BCE4_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8026BCE4_0();
extern "C" void _s8026BCE4_1();
extern "C" void f_8026BCE4() {}
