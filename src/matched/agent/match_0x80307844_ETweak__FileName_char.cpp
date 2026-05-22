// 0x80307844 ETweak::FileName(char (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; mr 27,4; lwz 9,0x20(31); addi 3,31,28; lbz 0,0x0(9); cmpwi 0,0; beq 0f; li 4,0; li 5,0; li 6,0; bl _s80307844_0; 0:; lwz 9,0x18(31); addi 28,31,24; lbz 0,0x0(9); cmpwi 0,0; beq 5f; mr 3,28; addi 29,31,12; bl _s80307844_1; li 0,0; stw 0,0x8(31); lwz 9,0x4(29); b 3f; 1:; lwz 0,0x8(29); lwz 31,0x0(9); cmpwi 0,0; lwz 30,0x4(9); beq 2f; cmpwi 31,0; beq 2f; mr 3,31; lwzu 4,0x4(3); bl _s80307844_2; mr 3,31; bl _s80307844_3; 2:; mr 9,30; 3:; li 0,1; cmpwi 9,0; bne 4f; li 0,0; 4:; cmpwi 0,0; bne 1b; mr 3,29; bl _s80307844_4; 5:; mr 3,28; mr 4,27; bl _s80307844_5; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80307844_0();
extern "C" void _s80307844_1();
extern "C" void _s80307844_2();
extern "C" void _s80307844_3();
extern "C" void _s80307844_4();
extern "C" void _s80307844_5();
extern "C" void f_80307844() {}
