// 0x80097864 TheSimsMaxisLogoState::Reset(void) (292 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 31,0x1c(1); stw 0,0x24(1); mr 31,3; lwz 3,0x1c(31); bl _s80097864_0; lwz 9,0x20(31); lwz 0,0x4(9); mr 3,9; ori 0,0,1; stw 0,0x4(9); bl _s80097864_1; lis 4,-32697; lis 5,-32706; addi 4,4,24012; addi 5,5,-29792; addi 3,1,16; crxor 6,6,6; bl _s80097864_2; lwz 9,0x10(1); li 6,0; cmpwi 9,0; beq 0f; lwz 6,0x0(9); 0:; lwz 3,0x20(31); li 4,0; li 5,0; bl _s80097864_3; lis 9,-32706; lwz 3,0x20(31); lfs f1,-29772(9); li 4,0; li 5,0; bl _s80097864_4; lwz 3,0x20(31); li 4,0; li 5,0; li 6,5; bl _s80097864_5; lis 9,-32706; lis 11,-32706; lfs f0,-29768(9); addi 10,1,8; lfs f13,-29764(11); mr 6,10; stfs f0,0x8(1); li 4,0; li 5,0; lwz 3,0x20(31); stfs f13,0x4(10); bl _s80097864_6; lis 9,-32706; addi 11,31,36; lfs f0,-29760(9); li 0,16; stw 0,0xc(11); lis 9,-32706; stfs f0,0x8(11); stfs f0,0x24(31); stfs f0,0x4(11); lwz 0,0xc(11); lfs f0,-29756(9); rlwinm 0,0,0,31,27; ori 0,0,1; stw 0,0xc(11); lwz 9,0x20(31); stfs f0,0x30(9); lwz 0,0x24(1); mtspr 8,0; lwz 31,0x1c(1); addi 1,1,32"
extern "C" void _s80097864_0();
extern "C" void _s80097864_1();
extern "C" void _s80097864_2();
extern "C" void _s80097864_3();
extern "C" void _s80097864_4();
extern "C" void _s80097864_5();
extern "C" void _s80097864_6();
extern "C" void f_80097864() {}
