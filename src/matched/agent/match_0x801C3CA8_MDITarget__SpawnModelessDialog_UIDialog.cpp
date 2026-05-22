// 0x801C3CA8 MDITarget::SpawnModelessDialog(UIDialog (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,3; mr 29,4; li 3,36; li 27,0; bl _s801C3CA8_0; mr 31,3; addi 30,31,4; bl _s801C3CA8_1; mr 3,30; bl _s801C3CA8_2; lwz 9,0x88(28); addi 4,29,40; mr 3,31; addi 9,9,1; stw 9,0x88(28); bl _s801C3CA8_3; addi 4,29,44; mr 3,30; bl _s801C3CA8_4; lwz 3,0x3c(29); lwz 4,0x40(29); stw 27,0x20(31); cmpwi 3,0; stw 3,0x8(31); stw 4,0xc(31); beq 0f; bl _s801C3CA8_5; stw 27,0xc(31); b 1f; 0:; cmpwi 4,0; beq 1f; lis 3,-32692; addi 3,3,-17444; bl _s801C3CA8_6; stw 3,0x8(31); 1:; lwz 3,0x44(29); stw 3,0x10(31); cmpwi 3,0; beq 2f; bl _s801C3CA8_7; 2:; lwz 0,0x18(29); lha 9,0x48(29); lha 11,0x4a(29); cmpwi 0,-1; stw 9,0x14(31); stw 11,0x18(31); li 0,2; bne 3f; li 0,1; 3:; stw 0,0x1c(31); mr 3,28; mr 4,31; bl _s801C3CA8_8; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s801C3CA8_0();
extern "C" void _s801C3CA8_1();
extern "C" void _s801C3CA8_2();
extern "C" void _s801C3CA8_3();
extern "C" void _s801C3CA8_4();
extern "C" void _s801C3CA8_5();
extern "C" void _s801C3CA8_6();
extern "C" void _s801C3CA8_7();
extern "C" void _s801C3CA8_8();
extern "C" void f_801C3CA8() {}
