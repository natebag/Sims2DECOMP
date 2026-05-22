// 0x8004BC6C EParticleEffect::~EParticleEffect(void) (320 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; lwz 30,0x58(31); cmpwi 30,0; beq 1f; mr 3,30; li 4,16384; li 5,1; bl _s8004BC6C_0; lwz 3,0x58(31); li 4,8; li 5,1; bl _s8004BC6C_1; lwz 11,0x58(31); cmpwi 11,0; beq 0f; lwz 9,0x0(11); li 4,3; lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; 0:; li 0,0; stw 0,0x60(31); stw 0,0x58(31); stw 0,0x68(31); b 3f; 1:; lwz 9,0x5c(31); cmpwi 9,0; beq 2f; lwz 0,0x140(9); ori 0,0,5120; stw 0,0x140(9); lwz 11,0x5c(31); lwz 9,0x144(11); lha 3,0x20(9); lwz 0,0x24(9); add 3,11,3; mtspr 8,0; blrl; stw 30,0x5c(31); b 3f; 2:; lwz 4,0x60(31); cmpwi 4,0; beq 4f; lwz 30,0x64(31); cmpwi 30,0; bne 3f; lis 3,-32692; addi 3,3,6092; bl _s8004BC6C_2; stw 30,0x60(31); stw 30,0x68(31); 3:; lwz 4,0x60(31); cmpwi 4,0; beq 4f; lwz 0,0x64(31); cmpwi 0,1; bne 4f; lis 3,-32692; addi 3,3,-644; bl _s8004BC6C_3; li 0,0; stw 0,0x60(31); stw 0,0x6c(31); 4:; andi. 0,29,1; beq 5f; bl _s8004BC6C_4; mr 4,31; bl _s8004BC6C_5; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8004BC6C_0();
extern "C" void _s8004BC6C_1();
extern "C" void _s8004BC6C_2();
extern "C" void _s8004BC6C_3();
extern "C" void _s8004BC6C_4();
extern "C" void _s8004BC6C_5();
extern "C" void f_8004BC6C() {}
