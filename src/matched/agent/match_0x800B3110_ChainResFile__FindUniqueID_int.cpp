// 0x800B3110 ChainResFile::FindUniqueID(int) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 31,4; li 4,0; bl _s800B3110_0; lwz 11,0x10(30); cmpwi 11,0; beq 0f; lwz 9,0xc(11); mr 4,31; lha 3,0xd0(9); lwz 0,0xd4(9); add 3,11,3; mtspr 8,0; blrl; b 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800B3110_0();
extern "C" void f_800B3110() {}
