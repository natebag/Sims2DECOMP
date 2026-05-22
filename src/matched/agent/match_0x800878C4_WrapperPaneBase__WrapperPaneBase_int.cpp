// 0x800878C4 WrapperPaneBase::WrapperPaneBase(int, (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); lis 9,-32698; mr 31,3; li 0,0; addi 9,9,-12072; stw 9,0x5c(31); addi 29,31,8; stw 4,0x0(31); addi 9,29,8; stw 0,0x4(31); mr. 28,5; stw 0,0x8(31); stw 0,0x4(29); stw 0,0x4(9); beq 1f; rlwinm 0,28,2,0,29; mr 30,0; cmplwi 0,128; ble 0f; mr 3,30; bl _s800878C4_0; b 2f; 0:; mr 3,30; bl _s800878C4_1; b 2f; 1:; li 3,0; li 30,0; 2:; add 9,3,30; li 0,0; stw 9,0xc(29); mr 11,3; stw 3,0x4(29); addi 9,1,16; stw 0,0x10(1); addi 10,31,28; mr. 0,28; stw 3,0x0(29); mtspr 9,0; addi 8,31,36; beq 4f; 3:; lwz 0,0x0(9); stw 0,0x0(11); addi 11,11,4; bdnz 3b; 4:; lis 9,-32707; stw 11,0x4(29); lfs f13,0x7324(9); li 0,0; lis 9,-32707; stw 0,0x18(31); lfs f0,0x7328(9); mr 3,31; stfs f13,0x1c(31); stfs f13,0x4(10); stfs f0,0x24(31); stfs f0,0x4(8); stfs f0,0x30(31); stw 0,0x3c(31); stfs f0,0x2c(31); stw 0,0x34(31); stw 0,0x38(31); bl _s800878C4_2; mr 3,31; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s800878C4_0();
extern "C" void _s800878C4_1();
extern "C" void _s800878C4_2();
extern "C" void f_800878C4() {}
