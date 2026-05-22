// 0x8030B108 TextureUtils::LoadTexture(unsigned (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,4; mr. 4,3; beq 0f; cmpwi 31,0; li 3,0; beq 7f; lis 3,-32692; li 5,0; addi 3,3,-7364; li 6,0; bl _s8030B108_0; li 29,0; mr. 30,3; beq 0f; lwz 0,0x14(30); mr 3,0; cmpwi 0,0; beq 0f; cmpw 3,31; bne 1f; mr 3,30; bl _s8030B108_1; 0:; li 3,0; b 7f; 1:; lbz 0,0x1a(3); cmpwi 0,32; bne 2f; lbz 0,0x1a(31); cmpwi 0,32; bne 2f; mr 4,31; bl _s8030B108_2; b 5f; 2:; lbz 0,0x1a(3); cmpwi 0,8; bne 3f; lbz 0,0x1a(31); cmpwi 0,32; bne 3f; mr 4,31; bl _s8030B108_3; b 5f; 3:; lbz 0,0x1a(3); cmpwi 0,32; bne 4f; lbz 0,0x1a(31); cmpwi 0,8; bne 4f; mr 4,31; bl _s8030B108_4; b 5f; 4:; lbz 0,0x1a(3); cmpwi 0,8; bne 6f; lbz 0,0x1a(31); cmpwi 0,8; bne 6f; mr 4,31; bl _s8030B108_5; 5:; mr 29,3; 6:; mr 3,30; bl _s8030B108_6; mr 3,29; 7:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8030B108_0();
extern "C" void _s8030B108_1();
extern "C" void _s8030B108_2();
extern "C" void _s8030B108_3();
extern "C" void _s8030B108_4();
extern "C" void _s8030B108_5();
extern "C" void _s8030B108_6();
extern "C" void f_8030B108() {}
