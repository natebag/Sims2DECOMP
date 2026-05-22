// 0x8008BB68 ELiveMode::Init(int) (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); lis 9,-32707; lis 11,-32697; lfs f0,0x7d40(9); li 29,0; addi 28,11,23428; mr 31,3; stfs f0,0xc(1); mr 30,4; stfs f0,0x8(1); stw 29,0xc0(28); lwz 11,-21508(13); lwz 9,0x0(11); lha 3,0x40(9); lwz 0,0x44(9); add 3,11,3; mtspr 8,0; blrl; stw 30,0x38(31); stw 29,0x3c(31); stw 29,0x1c(31); stw 29,0x20(31); stw 29,0x50(31); lwz 3,0x44(31); cmpwi 3,0; beq 0f; bl _s8008BB68_0; stw 29,0x44(31); 0:; lis 3,-32692; lis 4,-29108; addi 3,3,-17444; ori 4,4,11531; li 5,0; li 6,0; bl _s8008BB68_1; stw 3,0x44(31); stw 29,0xcc(28); stw 29,0xc8(28); bl _s8008BB68_2; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s8008BB68_0();
extern "C" void _s8008BB68_1();
extern "C" void _s8008BB68_2();
extern "C" void f_8008BB68() {}
