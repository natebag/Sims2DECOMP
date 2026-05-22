// 0x802C8B1C EHashTable::Insert(unsigned (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,3; mr 30,4; lwz 9,0xc(29); mr 28,5; cmpwi 6,0; divwu 0,30,9; mullw 0,0,9; subf 31,0,30; beq 0f; mr 4,31; mr 5,30; mr 6,28; bl _s802C8B1C_0; b 1f; 0:; mr 3,29; mr 4,31; mr 5,30; bl _s802C8B1C_1; cmpwi 3,0; li 3,0; bne 1f; mr 3,29; mr 4,31; mr 5,30; mr 6,28; bl _s802C8B1C_2; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802C8B1C_0();
extern "C" void _s802C8B1C_1();
extern "C" void _s802C8B1C_2();
extern "C" void f_802C8B1C() {}
