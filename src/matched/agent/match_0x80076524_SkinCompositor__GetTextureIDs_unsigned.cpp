// 0x80076524 SkinCompositor::GetTextureIDs(unsigned (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 31,3; mr 30,4; lwz 9,0x14(31); mr 27,5; mr 25,6; lwz 3,0x24(31); lbz 5,0x88(9); mr 26,7; lbz 4,0x89(9); li 29,0; lbz 6,0x1c(31); extsb 5,5; extsb 4,4; li 28,0; bl _s80076524_0; stw 3,0x0(30); 0:; lwz 5,0x14(31); mr 4,29; lwz 3,0x24(31); li 6,0; bl _s80076524_1; stwx 3,28,25; mr 4,29; lwz 3,0x24(31); addi 29,29,1; lwz 5,0x14(31); bl _s80076524_2; stwx 3,28,26; cmpwi 29,25; addi 28,28,4; ble 0b; lwz 9,0x14(31); li 4,0; lwz 3,0x24(31); lbz 5,0xf2(9); extsb 5,5; bl _s80076524_3; stw 3,0x0(27); li 4,1; lwz 3,0x24(31); lwz 9,0x14(31); lbz 5,0xf3(9); extsb 5,5; bl _s80076524_4; stw 3,0x4(27); li 4,2; lwz 3,0x24(31); lwz 9,0x14(31); lbz 5,0xf4(9); extsb 5,5; bl _s80076524_5; stw 3,0x8(27); lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s80076524_0();
extern "C" void _s80076524_1();
extern "C" void _s80076524_2();
extern "C" void _s80076524_3();
extern "C" void _s80076524_4();
extern "C" void _s80076524_5();
extern "C" void f_80076524() {}
