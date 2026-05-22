// 0x802C8C3C EHashTable::Remove(unsigned (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 5,4; lwz 9,0xc(31); divwu 0,4,9; mullw 0,0,9; subf 30,0,4; mr 4,30; bl _s802C8C3C_0; mr. 5,3; li 3,0; beq 0f; mr 3,31; mr 4,30; bl _s802C8C3C_1; li 3,1; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802C8C3C_0();
extern "C" void _s802C8C3C_1();
extern "C" void f_802C8C3C() {}
