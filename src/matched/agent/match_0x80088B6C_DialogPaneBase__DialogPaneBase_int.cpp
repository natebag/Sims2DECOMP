// 0x80088B6C DialogPaneBase::DialogPaneBase(int, (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); lis 9,-32698; mr 31,3; li 0,0; addi 9,9,-12072; stw 9,0x5c(31); addi 29,31,8; stw 4,0x0(31); addi 9,29,8; stw 0,0x4(31); addic. 28,5,2; stw 0,0x8(31); stw 0,0x4(29); stw 0,0x4(9); beq 1f; rlwinm 0,28,2,0,29; mr 30,0; cmplwi 0,128; ble 0f; mr 3,30; bl _s80088B6C_0; b 2f; 0:; mr 3,30; bl _s80088B6C_1; b 2f; 1:; li 3,0; li 30,0; 2:; add 9,3,30; li 0,0; stw 9,0xc(29); addi 11,1,16; stw 3,0x4(29); mr 9,3; stw 0,0x10(1); addi 10,31,28; mr. 0,28; stw 3,0x0(29); mtspr 9,0; addi 8,31,36; beq 4f; 3:; lwz 0,0x0(11); stw 0,0x0(9); addi 9,9,4; bdnz 3b; 4:; stw 9,0x4(29); li 30,0; stw 30,0x18(31); lis 9,-32707; lis 11,-32707; mr 3,31; lfs f0,0x732c(9); stfs f0,0x1c(31); stfs f0,0x4(10); lfs f13,0x7330(11); stfs f13,0x24(31); stfs f13,0x4(8); stw 30,0x34(31); stw 30,0x38(31); stw 30,0x3c(31); stfs f13,0x30(31); stfs f13,0x2c(31); bl _s80088B6C_2; lis 9,-32698; stw 30,0x64(31); addi 9,9,-12136; stw 30,0x60(31); mr 3,31; stw 9,0x5c(31); bl _s80088B6C_3; mr 3,31; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s80088B6C_0();
extern "C" void _s80088B6C_1();
extern "C" void _s80088B6C_2();
extern "C" void _s80088B6C_3();
extern "C" void f_80088B6C() {}
