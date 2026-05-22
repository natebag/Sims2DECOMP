// 0x802DC96C EA::Allocator::GeneralAllocator::TrimCore(unsigned (316 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 22,0x10(1); stw 0,0x3c(1); mr 26,3; lwz 3,0x4fc(26); stw 3,0x8(1); cmpwi 3,0; beq 0f; bl _s802DC96C_0; 0:; lwz 30,0x46c(26); addi 0,26,1100; mr 22,0; li 24,0; cmpw 30,0; beq 4f; addi 23,26,52; 1:; lwz 0,0x10(30); cmpwi 0,0; beq 3f; lwz 0,0x4(30); add 9,30,0; addi 11,9,-16; lwz 0,0x4(11); andi. 10,0,1; bne 3f; lwz 0,-16(9); lwz 9,0x0(30); subf 31,0,11; addi 9,9,16; cmplw 31,9; bge 3f; lwz 28,0x8(31); mr 29,30; lwz 27,0xc(31); mr 3,26; mr 4,29; stw 27,0xc(28); lwz 9,0xc(31); lwz 0,0x8(31); stw 0,0x8(9); lwz 30,0x24(30); bl _s802DC96C_1; lwz 25,0x4(29); mr 3,26; mr 4,29; bl _s802DC96C_2; cmpwi 3,0; beq 2f; lwz 0,0x444(26); add 24,24,25; cmpw 31,0; bne 3f; stw 23,0x444(26); mr 3,26; bl _s802DC96C_3; b 3f; 2:; stw 28,0x8(31); mr 5,30; stw 27,0xc(31); mr 3,26; stw 31,0xc(28); mr 4,29; stw 31,0x8(27); mr 30,29; bl _s802DC96C_4; 3:; lwz 30,0x20(30); cmpw 30,22; bne 1b; 4:; lwz 3,0x8(1); cmpwi 3,0; beq 5f; bl _s802DC96C_5; 5:; mr 3,24; lwz 0,0x3c(1); mtspr 8,0; lmw 22,0x10(1); addi 1,1,56"
extern "C" void _s802DC96C_0();
extern "C" void _s802DC96C_1();
extern "C" void _s802DC96C_2();
extern "C" void _s802DC96C_3();
extern "C" void _s802DC96C_4();
extern "C" void _s802DC96C_5();
extern "C" void f_802DC96C() {}
