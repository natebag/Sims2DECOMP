// 0x80305E90 EDebugMenu::ComputeMaxWidth(ERFont (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-304(1); mfspr 0,8; stmw 27,0x11c(1); stw 0,0x134(1); mr 30,3; lis 9,-32702; lfs f0,-1452(9); mr 28,4; lwz 31,0xc(30); stfs f0,0x4(30); cmpwi 31,0; beq 2f; addi 29,1,136; lis 27,-32702; 0:; lwz 9,0x8(31); addi 4,1,8; li 5,128; lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,31,3; blrl; lbz 0,0x8(1); cmpwi 0,0; beq 1f; addi 5,1,8; addi 4,27,-1460; mr 3,29; crxor 6,6,6; bl _s80305E90_0; addi 3,1,272; mr 4,28; mr 5,29; li 6,0; li 7,1; li 8,0; bl _s80305E90_1; lfs f13,0x110(1); lfs f0,0x4(30); fcmpu 0,f13,f0; ble 1f; stfs f13,0x4(30); 1:; lwz 31,0x4(31); cmpwi 31,0; bne 0b; 2:; li 0,0; stw 0,0x8(30); lwz 0,0x134(1); mtspr 8,0; lmw 27,0x11c(1); addi 1,1,304"
extern "C" void _s80305E90_0();
extern "C" void _s80305E90_1();
extern "C" void f_80305E90() {}
