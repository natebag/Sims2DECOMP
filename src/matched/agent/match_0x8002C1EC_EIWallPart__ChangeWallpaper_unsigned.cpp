// 0x8002C1EC EIWallPart::ChangeWallpaper(unsigned (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; lis 3,-32692; li 6,0; addi 3,3,-17444; li 5,0; bl _s8002C1EC_0; mr 29,3; lis 4,11134; mr 3,31; mr 5,30; ori 4,4,62066; bl _s8002C1EC_1; lis 4,-15763; mr 5,30; mr 3,31; ori 4,4,22842; bl _s8002C1EC_2; lwz 3,0x3a0(31); cmpwi 3,0; beq 0f; bl _s8002C1EC_3; li 0,0; stw 0,0x3a0(31); 0:; stw 29,0x3a0(31); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8002C1EC_0();
extern "C" void _s8002C1EC_1();
extern "C" void _s8002C1EC_2();
extern "C" void _s8002C1EC_3();
extern "C" void f_8002C1EC() {}
