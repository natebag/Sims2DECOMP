// 0x80059AF4 PlumbBob::Startup(void) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x164(31); cmpwi 0,0; bne 0f; li 3,60; bl _s80059AF4_0; bl _s80059AF4_1; stw 3,0x164(31); lis 4,27935; ori 4,4,2390; mr 3,31; bl _s80059AF4_2; lis 9,-32696; lwz 11,0x164(31); lfs f0,0x55c0(9); lis 4,29601; mr 3,31; ori 4,4,47194; stfs f0,0x18(11); bl _s80059AF4_3; lis 4,-31838; mr 3,31; ori 4,4,2564; bl _s80059AF4_4; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80059AF4_0();
extern "C" void _s80059AF4_1();
extern "C" void _s80059AF4_2();
extern "C" void _s80059AF4_3();
extern "C" void _s80059AF4_4();
extern "C" void f_80059AF4() {}
