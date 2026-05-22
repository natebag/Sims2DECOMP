// 0x80215C90 InteractorModule::InteractorVisualizer::Draw(InteractorModule::WallManipulator (632 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-120(1); mfspr 0,8; stfd f31,0x70(1); stmw 27,0x5c(1); stw 0,0x7c(1); mr 29,3; mr 31,4; addi 3,1,8; addi 30,31,108; bl _s80215C90_0; mr 4,30; addi 3,1,8; bl _s80215C90_1; lwz 3,0x0(31); lis 9,-32697; addi 9,9,23428; rlwinm 3,3,4,0,27; addi 3,3,244; add 3,3,9; bl _s80215C90_2; lis 9,-32704; lwz 0,0xc4(31); lfs f31,-10428(9); mr 27,3; li 11,0; andi. 9,0,1; beq 0f; li 11,1; 0:; cmpwi 11,0; bne 1f; andi. 11,0,16; addi 28,31,32; beq 2f; 1:; addi 9,31,32; lfs f10,0x8(30); lfs f1,0x4(9); mr 28,9; lfs f0,0x8(9); lfs f13,0x20(31); lfs f12,0x6c(31); fsubs f0,f0,f10; lfs f11,0x4(30); fsubs f13,f13,f12; stfs f0,0x50(1); fsubs f1,f1,f11; stfs f13,0x48(1); fmr f2,f13; stfs f1,0x4c(1); bl _s80215C90_3; lis 9,-32704; fmr f31,f1; lfs f0,-10428(9); fcmpu 0,f31,f0; beq 2f; addi 3,1,8; bl _s80215C90_4; 2:; lis 5,1287; mr 6,27; mr 4,31; ori 5,5,9753; addi 7,1,8; mr 3,29; bl _s80215C90_5; addi 3,1,8; bl _s80215C90_6; addi 3,1,8; mr 4,28; bl _s80215C90_7; lwz 0,0xc4(31); li 9,0; andi. 11,0,1; beq 3f; li 9,1; 3:; cmpwi 9,0; bne 4f; andi. 9,0,16; beq 11f; 4:; lis 9,-32704; lfs f0,-10428(9); fcmpu 0,f31,f0; beq 5f; fmr f1,f31; addi 3,1,8; bl _s80215C90_8; 5:; lwz 0,0xc4(31); andi. 9,0,128; beq 6f; lis 5,5437; lis 6,-32696; addi 6,6,32272; mr 3,29; mr 4,31; ori 5,5,19514; addi 7,1,8; bl _s80215C90_9; lwz 0,0xc4(31); andi. 9,0,8; beq 7f; mr 3,29; mr 4,31; bl _s80215C90_10; b 7f; 6:; lis 5,5437; lis 6,-32696; addi 6,6,32284; mr 3,29; mr 4,31; ori 5,5,19514; addi 7,1,8; bl _s80215C90_11; 7:; lfs f13,0x20(31); addi 9,31,96; lfs f0,0x60(31); li 0,0; fcmpu 0,f13,f0; bne 8f; lfs f13,0x4(28); lfs f0,0x4(9); fcmpu 0,f13,f0; bne 8f; lfs f13,0x8(28); lfs f0,0x8(9); fcmpu 0,f13,f0; beq 9f; 8:; li 0,1; 9:; cmpwi 0,0; beq 12f; lwz 0,0xc4(31); andi. 9,0,16; beq 10f; mr 3,29; mr 4,31; bl _s80215C90_12; b 12f; 10:; mr 3,29; mr 4,31; bl _s80215C90_13; b 12f; 11:; lwz 3,0x0(31); lis 9,-32697; addi 9,9,23428; rlwinm 3,3,4,0,27; addi 3,3,244; add 3,3,9; bl _s80215C90_14; mr 6,3; lis 5,-15727; mr 3,29; mr 4,31; ori 5,5,35298; addi 7,1,8; bl _s80215C90_15; 12:; lwz 0,0x7c(1); mtspr 8,0; lmw 27,0x5c(1); lfd f31,0x70(1); addi 1,1,120"
extern "C" void _s80215C90_0();
extern "C" void _s80215C90_1();
extern "C" void _s80215C90_2();
extern "C" void _s80215C90_3();
extern "C" void _s80215C90_4();
extern "C" void _s80215C90_5();
extern "C" void _s80215C90_6();
extern "C" void _s80215C90_7();
extern "C" void _s80215C90_8();
extern "C" void _s80215C90_9();
extern "C" void _s80215C90_10();
extern "C" void _s80215C90_11();
extern "C" void _s80215C90_12();
extern "C" void _s80215C90_13();
extern "C" void _s80215C90_14();
extern "C" void _s80215C90_15();
extern "C" void f_80215C90() {}
