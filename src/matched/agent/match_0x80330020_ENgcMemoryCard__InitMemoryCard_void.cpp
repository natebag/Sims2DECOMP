// 0x80330020 ENgcMemoryCard::InitMemoryCard(void) (412 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,3; addi 29,1,8; mr 31,29; bl _s80330020_0; bl _s80330020_1; mr 3,30; bl _s80330020_2; lis 4,-32702; mr 3,29; addi 4,4,6296; bl _s80330020_3; cmpwi 3,0; beq 1f; lwz 3,0x8(1); li 4,0; li 30,2040; bl _s80330020_4; lwz 11,0x0(3); lis 9,-32700; addi 9,9,1792; lwz 11,0x8(11); 0:; lwz 0,0x0(11); addic. 30,30,-24; stw 0,0x0(9); lwz 0,0x4(11); stw 0,0x4(9); lwz 0,0x8(11); stw 0,0x8(9); lwz 0,0xc(11); stw 0,0xc(9); lwz 0,0x10(11); stw 0,0x10(9); lwz 0,0x14(11); addi 11,11,24; stw 0,0x14(9); addi 9,9,24; bne 0b; lwz 0,0x0(11); stw 0,0x0(9); lwz 0,0x4(11); stw 0,0x4(9); bl _s80330020_5; lwz 4,0x8(1); bl _s80330020_6; stw 30,0x8(1); b 2f; 1:; lis 3,-32700; li 4,127; addi 3,3,1792; li 5,2048; bl _s80330020_7; 2:; lis 4,-32702; mr 3,31; addi 4,4,6308; bl _s80330020_8; cmpwi 3,0; beq 4f; lwz 3,0x8(1); li 4,0; li 30,6144; bl _s80330020_9; lwz 11,0x0(3); lis 9,-32700; addi 9,9,-4352; lwz 11,0x8(11); 3:; lwz 0,0x0(11); addic. 30,30,-24; stw 0,0x0(9); lwz 0,0x4(11); stw 0,0x4(9); lwz 0,0x8(11); stw 0,0x8(9); lwz 0,0xc(11); stw 0,0xc(9); lwz 0,0x10(11); stw 0,0x10(9); lwz 0,0x14(11); addi 11,11,24; stw 0,0x14(9); addi 9,9,24; bne 3b; bl _s80330020_10; lwz 4,0x8(1); bl _s80330020_11; stw 30,0x8(1); b 5f; 4:; lis 3,-32700; li 4,127; addi 3,3,-4352; li 5,6144; bl _s80330020_12; 5:; li 0,0; li 3,1; stw 0,-26380(13); lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s80330020_0();
extern "C" void _s80330020_1();
extern "C" void _s80330020_2();
extern "C" void _s80330020_3();
extern "C" void _s80330020_4();
extern "C" void _s80330020_5();
extern "C" void _s80330020_6();
extern "C" void _s80330020_7();
extern "C" void _s80330020_8();
extern "C" void _s80330020_9();
extern "C" void _s80330020_10();
extern "C" void _s80330020_11();
extern "C" void _s80330020_12();
extern "C" void f_80330020() {}
