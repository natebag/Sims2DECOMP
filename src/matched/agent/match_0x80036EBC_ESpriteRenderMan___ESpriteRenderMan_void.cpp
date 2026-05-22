// 0x80036EBC ESpriteRenderMan::~ESpriteRenderMan(void) (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; lwz 9,0x4(30); b 2f; 0:; lwz 0,0x8(30); lwz 11,0x0(9); cmpwi 0,0; lwz 31,0x4(9); beq 1f; cmpwi 11,0; beq 1f; lwz 9,0xe8(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 1:; mr 9,31; 2:; li 0,1; cmpwi 9,0; bne 3f; li 0,0; 3:; cmpwi 0,0; bne 0b; mr 3,30; bl _s80036EBC_0; mr 3,30; bl _s80036EBC_1; andi. 0,29,1; beq 4f; mr 3,30; bl _s80036EBC_2; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80036EBC_0();
extern "C" void _s80036EBC_1();
extern "C" void _s80036EBC_2();
extern "C" void f_80036EBC() {}
