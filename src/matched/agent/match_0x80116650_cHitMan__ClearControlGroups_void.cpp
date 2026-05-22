// 0x80116650 cHitMan::ClearControlGroups(void) (356 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 28,0x40(1); stw 0,0x54(1); li 0,0; mr 31,3; stw 0,0x8(1); addi 11,31,32; lwz 0,0x4(11); stw 0,0x10(1); lwz 9,0x4(11); lwz 0,0x8(9); stw 0,0x8(1); stw 0,0x18(1); addi 29,1,32; addi 28,1,48; b 1f; 0:; addi 9,9,16; li 0,0; lwz 3,0x4(9); stw 0,0x4(9); bl _s80116650_0; lwz 3,0x8(1); bl _s80116650_1; stw 3,0x8(1); 1:; lwz 9,0x8(1); li 30,1; lwz 0,0x10(1); cmpw 9,0; bne 2f; li 30,0; 2:; cmpwi 30,0; bne 0b; stw 30,0x24(1); li 3,24; bl _s80116650_2; stw 3,0x24(1); addi 8,31,32; stw 30,0x8(29); stb 30,0x2c(1); lwz 9,0x24(1); stw 30,0x0(9); lwz 11,0x24(1); stw 30,0x4(11); lwz 9,0x24(1); stw 9,0x8(9); lwz 11,0x24(1); stw 11,0xc(11); lwz 0,0x24(1); lwz 10,0x20(31); stw 0,0x4(28); lwz 9,0x4(8); lwz 0,0x30(1); stw 10,0x20(1); stw 9,0x24(1); lwz 11,0x34(1); stw 0,0x20(31); stw 11,0x4(8); lwz 11,0x28(1); lbz 0,0x2c(1); lwz 10,0x28(31); lbz 9,0x2c(31); stb 0,0x2c(31); cmpwi 10,0; stw 11,0x28(31); stb 9,0x2c(1); stw 10,0x28(1); beq 3f; lwz 9,0x24(1); mr 3,29; lwz 4,0x4(9); bl _s80116650_3; lwz 9,0x24(1); stw 9,0x8(9); lwz 11,0x24(1); stw 30,0x4(11); lwz 9,0x24(1); stw 9,0xc(9); stw 30,0x8(29); 3:; lwz 3,0x24(1); cmpwi 3,0; beq 4f; li 4,24; bl _s80116650_4; 4:; lwz 0,0x54(1); mtspr 8,0; lmw 28,0x40(1); addi 1,1,80"
extern "C" void _s80116650_0();
extern "C" void _s80116650_1();
extern "C" void _s80116650_2();
extern "C" void _s80116650_3();
extern "C" void _s80116650_4();
extern "C" void f_80116650() {}
