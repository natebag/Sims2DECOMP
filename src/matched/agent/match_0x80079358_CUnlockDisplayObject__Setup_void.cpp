// 0x80079358 CUnlockDisplayObject::Setup(void) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x80(31); cmpwi 0,0; bne 0f; li 3,120; bl _s80079358_0; bl _s80079358_1; mr 0,3; lwz 4,0x30(31); stw 0,0x10(31); li 5,1; li 6,0; bl _s80079358_2; lwz 9,0x14(31); lwz 11,0x10(31); lfs f0,0x88(9); stfs f0,0x58(11); 0:; lwz 4,0x2c(31); li 5,0; lwz 3,0x1c(31); li 6,0; li 7,0; bl _s80079358_3; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80079358_0();
extern "C" void _s80079358_1();
extern "C" void _s80079358_2();
extern "C" void _s80079358_3();
extern "C" void f_80079358() {}
