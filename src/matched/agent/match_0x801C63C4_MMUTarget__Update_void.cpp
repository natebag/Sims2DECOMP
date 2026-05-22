// 0x801C63C4 MMUTarget::Update(void) (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; lwz 0,0xfc(29); cmpwi 0,0; beq 1f; lwz 11,0xac(29); cmpwi 11,0; beq 0f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 0:; li 0,0; mr 3,29; stw 0,0xfc(29); li 4,0; stw 0,0xac(29); li 5,0; bl _s801C63C4_0; 1:; lwz 0,0xb0(29); cmpwi 0,4; bne 4f; lwz 0,0x190(29); cmpwi 0,0; beq 3f; lwz 3,-26524(13); li 4,0; bl _s801C63C4_1; mr 31,3; li 4,1; lwz 3,-26524(13); bl _s801C63C4_2; cmpwi 3,0; bne 2f; cmpwi 31,0; beq 4f; li 4,-1; mr 3,31; bl _s801C63C4_3; mr 30,3; li 4,-1; mr 3,31; bl _s801C63C4_4; mr 6,3; mr 5,30; mr 3,31; li 4,6; li 7,0; bl _s801C63C4_5; cmpwi 3,0; beq 4f; 2:; addi 3,29,260; bl _s801C63C4_6; b 4f; 3:; mr 3,29; bl _s801C63C4_7; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801C63C4_0();
extern "C" void _s801C63C4_1();
extern "C" void _s801C63C4_2();
extern "C" void _s801C63C4_3();
extern "C" void _s801C63C4_4();
extern "C" void _s801C63C4_5();
extern "C" void _s801C63C4_6();
extern "C" void _s801C63C4_7();
extern "C" void f_801C63C4() {}
