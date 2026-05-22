// 0x80194DA4 CASTarget::GotoScreen(UIScreenID) (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32697; mr 31,3; lwz 29,0x5f10(9); mr 30,4; mr 3,29; bl _s80194DA4_0; cmpwi 3,0; bne 1f; lwz 0,0x90(31); cmpw 30,0; beq 1f; mr 3,31; bl _s80194DA4_1; cmpwi 30,16; stw 3,0xa0(31); bne 0f; lwz 0,0x90(31); cmpwi 0,17; beq 0f; stw 3,0xa4(31); 0:; mr 3,31; bl _s80194DA4_2; cmpwi 3,0; beq 1f; stw 30,0x90(31); mr 3,29; lwz 5,0x1360(31); mr 4,30; bl _s80194DA4_3; li 0,0; mr 3,31; stw 0,0x9c(31); bl _s80194DA4_4; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80194DA4_0();
extern "C" void _s80194DA4_1();
extern "C" void _s80194DA4_2();
extern "C" void _s80194DA4_3();
extern "C" void _s80194DA4_4();
extern "C" void f_80194DA4() {}
