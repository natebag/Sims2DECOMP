// 0x8039B6D4 __VMBASEFlushAlteredCode (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; li 4,4; stw 0,0x14(1); stw 31,0xc(1); mr 31,3; bl _s8039B6D4_0; sync; li 0,0; isync; icbi 31,0; lwz 0,0x14(1); lwz 31,0xc(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s8039B6D4_0();
extern "C" void f_8039B6D4() {}
