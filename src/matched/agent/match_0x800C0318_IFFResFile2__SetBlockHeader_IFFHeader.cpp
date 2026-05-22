// 0x800C0318 IFFResFile2::SetBlockHeader(IFFHeader (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; li 0,1; lwz 9,0x140(31); mr 29,4; mr 30,5; stw 0,0x144(31); cmpwi 9,0; beq 0f; addi 4,31,16; li 5,0; bl _s800C0318_0; mr. 3,3; bne 1f; 0:; addi 31,31,16; mr 4,30; mr 3,31; bl _s800C0318_1; mr. 3,3; bne 1f; li 0,76; mr 3,31; stw 0,0x8(1); mr 4,29; addi 5,1,8; bl _s800C0318_2; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s800C0318_0();
extern "C" void _s800C0318_1();
extern "C" void _s800C0318_2();
extern "C" void f_800C0318() {}
