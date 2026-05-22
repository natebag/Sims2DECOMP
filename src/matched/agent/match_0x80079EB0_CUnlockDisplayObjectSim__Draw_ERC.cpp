// 0x80079EB0 CUnlockDisplayObjectSim::Draw(ERC (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 30,0x58(1); stw 0,0x64(1); mr 31,3; mr 30,4; lwz 0,0xc(31); cmpwi 0,0; beq 2f; lwz 0,0x10(31); cmpwi 0,0; beq 2f; lwz 3,0x8c(31); bl _s80079EB0_0; lwz 3,0x8c(31); bl _s80079EB0_1; cmpwi 3,0; bne 2f; lis 9,-32707; addi 11,1,72; lfs f0,0x651c(9); mr 5,11; addi 6,1,8; addi 3,31,60; stfs f0,0x48(1); addi 4,31,72; stfs f0,0x8(11); stfs f0,0x4(11); bl _s80079EB0_2; lwz 3,0x10(31); addi 4,1,8; lwz 5,-26812(13); bl _s80079EB0_3; lwz 9,0x10(31); lwz 6,0x24(9); cmpwi 6,0; beq 0f; lwz 6,0x18(6); b 1f; 0:; li 6,0; 1:; lwz 9,0x10(31); mr 4,30; lwz 3,0x8c(31); lwz 5,0x10(9); bl _s80079EB0_4; 2:; lwz 0,0x64(1); mtspr 8,0; lmw 30,0x58(1); addi 1,1,96"
extern "C" void _s80079EB0_0();
extern "C" void _s80079EB0_1();
extern "C" void _s80079EB0_2();
extern "C" void _s80079EB0_3();
extern "C" void _s80079EB0_4();
extern "C" void f_80079EB0() {}
