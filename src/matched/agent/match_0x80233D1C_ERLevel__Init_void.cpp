// 0x80233D1C ERLevel::Init(void) (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 26,3; li 4,0; addis 27,26,3; bl _s80233D1C_0; li 28,0; lwz 0,-15688(27); cmpw 28,0; bge 1f; li 31,0; 0:; addi 30,27,-23880; mr 3,26; lwzx 4,30,31; mr 29,27; addi 28,28,1; bl _s80233D1C_1; lwzx 9,30,31; lwz 0,0x5c(9); ori 0,0,8192; stw 0,0x5c(9); lwzx 11,30,31; addi 31,31,4; lwz 9,0x0(11); lwz 0,0x54(9); lha 3,0x50(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,-15688(29); cmpw 28,0; blt 0b; 1:; addis 30,26,3; addi 3,30,-23964; bl _s80233D1C_2; lis 9,-32704; lis 11,-32704; lfs f0,-2868(9); lfs f13,-2864(11); stfs f0,-24176(30); stfs f13,-24172(30); lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s80233D1C_0();
extern "C" void _s80233D1C_1();
extern "C" void _s80233D1C_2();
extern "C" void f_80233D1C() {}
