// 0x8034F480 ENgcTexture::~ENgcTexture(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lis 9,-32697; lwz 11,0x28(31); addi 9,9,-12424; mr 30,4; stw 9,0x24(31); cmpwi 11,0; beq 0f; lwz 9,0x24(11); li 4,3; lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,0x28(31); 0:; mr 3,31; li 4,0; bl _s8034F480_0; andi. 0,30,1; beq 1f; lis 3,-32692; mr 4,31; addi 3,3,-7364; bl _s8034F480_1; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8034F480_0();
extern "C" void _s8034F480_1();
extern "C" void f_8034F480() {}
