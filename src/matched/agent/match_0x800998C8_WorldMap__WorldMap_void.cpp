// 0x800998C8 WorldMap::WorldMap(void) (480 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; li 30,0; stw 30,0x0(31); addi 3,31,24; stw 30,0x4(31); li 29,1; stw 30,0x8(31); stw 30,0xc(31); stw 30,0x10(31); stw 30,0x14(31); bl _s800998C8_0; lis 9,-32706; lis 11,-32706; lis 10,-32706; lfs f13,-29604(9); lfs f12,-29600(11); li 0,6; lfs f0,-29596(10); lis 3,-32696; stw 30,0xd4(31); lis 4,-17670; stw 30,0x90(31); addi 3,3,32332; stw 30,0x94(31); ori 4,4,49883; stw 30,0x98(31); stw 30,0xcc(31); stw 30,0xd0(31); stw 29,0xd8(31); stfs f13,0xbc(31); stfs f12,0xc0(31); stfs f0,0xc4(31); stw 0,0xc8(31); bl _s800998C8_1; cmpwi 3,0; stw 3,0x8(31); bne 0f; li 3,0; bl _s800998C8_2; stw 29,0x0(31); 0:; lis 3,-32692; lis 4,26961; ori 4,4,21689; addi 3,3,-27556; bl _s800998C8_3; stw 3,0xc(31); lis 4,1510; lis 3,-32693; ori 4,4,29; addi 3,3,11064; bl _s800998C8_4; stw 3,0x10(31); lis 4,26961; lis 3,-32693; ori 4,4,21689; addi 3,3,21144; bl _s800998C8_5; stw 3,0x14(31); lis 3,-32697; addi 3,3,23428; bl _s800998C8_6; mr 4,3; lis 3,-32692; addi 3,3,-17444; bl _s800998C8_7; lis 0,26961; lis 9,1510; ori 0,0,21689; ori 9,9,29; stw 0,0x9c(31); stw 9,0xa4(31); stw 3,0x98(31); bl _s800998C8_8; li 6,0; li 7,0; li 4,1392; li 5,16; bl _s800998C8_9; mr 30,3; li 4,0; li 5,1392; bl _s800998C8_10; mr 3,30; li 4,0; bl _s800998C8_11; stw 3,0x4(31); cmpwi 3,0; beq 1f; bl _s800998C8_12; lwz 3,0x4(31); li 4,1; addi 3,3,16; bl _s800998C8_13; lis 9,-32706; lwz 3,0x4(31); lfs f1,-29592(9); bl _s800998C8_14; lwz 3,0x4(31); lwz 9,0x0(3); lfs f1,0x2c(9); bl _s800998C8_15; lwz 3,0x4(31); bl _s800998C8_16; 1:; lwz 0,0x8(31); cmpwi 0,0; beq 2f; mr 3,31; bl _s800998C8_17; 2:; li 3,0; bl _s800998C8_18; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800998C8_0();
extern "C" void _s800998C8_1();
extern "C" void _s800998C8_2();
extern "C" void _s800998C8_3();
extern "C" void _s800998C8_4();
extern "C" void _s800998C8_5();
extern "C" void _s800998C8_6();
extern "C" void _s800998C8_7();
extern "C" void _s800998C8_8();
extern "C" void _s800998C8_9();
extern "C" void _s800998C8_10();
extern "C" void _s800998C8_11();
extern "C" void _s800998C8_12();
extern "C" void _s800998C8_13();
extern "C" void _s800998C8_14();
extern "C" void _s800998C8_15();
extern "C" void _s800998C8_16();
extern "C" void _s800998C8_17();
extern "C" void _s800998C8_18();
extern "C" void f_800998C8() {}
