// 0x800BF690 IFFResFile2::SetID(Memory::HandleNode (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 28,0x50(1); stw 0,0x64(1); mr 31,3; addi 30,1,8; mr 29,4; mr 28,5; addi 4,30,8; li 5,64; mr 3,30; bl _s800BF690_0; lwz 9,0xc(31); mr 4,29; mr 5,30; lwz 0,0xa4(9); lha 3,0xa0(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0xc(31); mr 4,29; lwz 0,0xc4(9); lha 3,0xc0(9); mtspr 8,0; add 3,31,3; blrl; lwz 0,0x4(31); mr 7,3; cmpwi 0,0; bne 0f; lwz 9,0xc(31); mr 4,29; mr 5,28; mr 6,30; lha 3,0x118(9); lwz 0,0x11c(9); add 3,31,3; mtspr 8,0; blrl; 0:; lwz 0,0x64(1); mtspr 8,0; lmw 28,0x50(1); addi 1,1,96"
extern "C" void _s800BF690_0();
extern "C" void f_800BF690() {}
