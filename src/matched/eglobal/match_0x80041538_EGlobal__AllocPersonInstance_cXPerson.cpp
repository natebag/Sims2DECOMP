// 0x80041538 EGlobal::AllocPersonInstance(cXPerson (348 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,4; bl _s80041538_0; li 6,0; li 7,0; li 4,1608; li 5,16; bl _s80041538_1; mr 30,3; li 5,1608; li 4,0; bl _s80041538_2; mr 3,30; mr 4,28; bl _s80041538_3; lis 30,-32697; mr 31,3; addi 30,30,24012; mr 4,31; lwz 9,0xc8(30); lwz 3,0x4(9); bl _s80041538_4; lwz 9,0xc8(30); mr 4,31; li 5,0; lwz 3,0x1c(9); bl _s80041538_5; cmpwi 28,0; beq 0f; lwz 9,0x0(28); li 4,5; lwz 3,0x0(9); bl _s80041538_6; mr 29,3; b 1f; 0:; li 29,0; 1:; lwz 9,0x0(31); lha 3,0x1a0(9); lwz 0,0x1a4(9); add 3,31,3; mtspr 8,0; blrl; mr. 30,3; beq 2f; lwz 0,0x5c(30); lis 11,-32697; mr 4,30; li 5,0; oris 0,0,4; stw 0,0x5c(30); lwz 9,0x5e94(11); lwz 3,0x1c(9); bl _s80041538_7; lis 11,-32763; lis 9,-32763; addi 11,11,-6384; addi 9,9,-6252; stw 9,0x30(30); stw 11,0x1c(30); stw 29,0x28(30); stw 29,0x2c(30); 2:; lis 9,-32763; lis 11,-32763; addi 9,9,-6384; addi 11,11,-6252; stw 9,0x1c(31); cmpwi 31,0; stw 29,0x2c(31); li 0,0; stw 11,0x30(31); stw 29,0x28(31); lwz 9,0x0(28); beq 3f; addi 0,31,800; 3:; lwz 9,0x0(9); stw 0,0x10(9); lwz 11,0x0(28); lwz 9,0x0(11); stw 31,0x14(9); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s80041538_0();
extern "C" void _s80041538_1();
extern "C" void _s80041538_2();
extern "C" void _s80041538_3();
extern "C" void _s80041538_4();
extern "C" void _s80041538_5();
extern "C" void _s80041538_6();
extern "C" void _s80041538_7();

struct EGlobal {
    void AllocPersonInstance();
};

void EGlobal::AllocPersonInstance() {
}
