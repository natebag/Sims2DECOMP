// 0x80136848 RoomManager::OffsetWorld(CTilePt (484 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 27,0x4c(1); stw 0,0x64(1); addi 30,1,8; li 29,0; mr 28,3; mr 27,4; stw 29,0x4(30); li 3,36; bl _s80136848_0; stw 3,0x4(30); stw 29,0x8(30); stb 29,0xc(30); stw 29,0x0(3); lwz 11,0x4(30); stw 29,0x4(11); lwz 9,0x4(30); stw 9,0x8(9); lwz 11,0x4(30); stw 11,0xc(11); stw 29,0x18(1); lwz 9,0x14(28); lwz 0,0x8(9); stw 0,0x18(1); stw 0,0x20(1); mr 31,30; addi 29,1,32; b 2f; 0:; mr 3,29; addi 4,4,16; mr 5,27; bl _s80136848_1; lwz 3,-21488(13); mr 4,29; lwz 9,0x0(3); lha 0,0x58(9); lwz 9,0x5c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 1f; lwz 30,0x18(1); mr 4,29; addi 3,1,48; bl _s80136848_2; lwz 11,0x14(30); lwz 12,0x18(30); addi 8,30,20; addi 3,1,40; mr 4,31; stw 11,0x34(1); stw 12,0x38(1); addi 5,1,48; lwz 9,0x8(8); lwz 10,0xc(8); stw 9,0x3c(1); stw 10,0x40(1); bl _s80136848_3; addi 3,1,48; li 4,2; bl _s80136848_4; 1:; mr 3,29; li 4,2; bl _s80136848_5; lwz 3,0x18(1); bl _s80136848_6; stw 3,0x18(1); 2:; addi 11,28,16; lwz 4,0x18(1); lwz 0,0x4(11); li 30,1; cmpw 4,0; stw 0,0x20(1); bne 3f; li 30,0; 3:; cmpwi 30,0; bne 0b; lwz 0,0x4(11); stw 0,0x4(29); lwz 9,0x8(1); lwz 0,0x4(31); stw 9,0x10(28); stw 0,0x4(11); lwz 9,0x18(28); lwz 7,0x8(31); stw 9,0x8(31); lbz 9,0x14(1); lwz 0,0x8(31); lbz 8,0x1c(28); lwz 11,0x20(1); cmpwi 0,0; lwz 10,0x24(1); stb 9,0x1c(28); stw 11,0x8(1); stw 10,0x4(31); stw 7,0x18(28); stb 8,0x14(1); beq 4f; lwz 9,0x4(31); mr 3,31; lwz 4,0x4(9); bl _s80136848_7; lwz 9,0x4(31); stw 9,0x8(9); lwz 11,0x4(31); stw 30,0x4(11); lwz 9,0x4(31); stw 9,0xc(9); stw 30,0x8(31); 4:; lwz 3,0x4(31); cmpwi 3,0; beq 5f; li 4,36; bl _s80136848_8; 5:; lwz 0,0x64(1); mtspr 8,0; lmw 27,0x4c(1); addi 1,1,96"
extern "C" void _s80136848_0();
extern "C" void _s80136848_1();
extern "C" void _s80136848_2();
extern "C" void _s80136848_3();
extern "C" void _s80136848_4();
extern "C" void _s80136848_5();
extern "C" void _s80136848_6();
extern "C" void _s80136848_7();
extern "C" void _s80136848_8();
extern "C" void f_80136848() {}
