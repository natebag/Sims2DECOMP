// 0x802C8A44 EHashTable::operator[](unsigned (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 31,4; lwz 9,0xc(30); mr 5,31; divwu 0,31,9; mullw 0,0,9; subf 29,0,31; mr 4,29; bl _s802C8A44_0; mr. 3,3; bne 0f; mr 3,30; mr 4,29; mr 5,31; li 6,0; bl _s802C8A44_1; 0:; addi 3,3,16; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802C8A44_0();
extern "C" void _s802C8A44_1();
extern "C" void f_802C8A44() {}
