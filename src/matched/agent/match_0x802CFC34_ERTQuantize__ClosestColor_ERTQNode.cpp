// 0x802CFC34 ERTQuantize::ClosestColor(ERTQNode (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); mr 28,4; mr 30,3; lbz 0,0x32(28); cmpwi 0,0; beq 4f; li 29,0; addi 31,28,34; 0:; lbz 0,0x32(28); sraw 0,0,29; andi. 9,0,1; beq 3f; lhz 9,0x0(31); cmpwi 9,0; beq 1f; mulli 9,9,56; lwz 0,0x108c(30); add 4,0,9; b 2f; 1:; li 4,0; 2:; mr 3,30; bl _s802CFC34_0; 3:; addi 29,29,1; addi 31,31,2; cmplwi 29,7; ble 0b; 4:; lwz 0,0x1c(28); cmpwi 0,0; beq 5f; lbz 9,0x34(28); addi 11,30,7396; lfs f9,0x8(11); addi 3,1,8; mulli 9,9,12; lfs f10,0x4(11); lfs f11,0x1ce4(30); addi 9,9,4324; add 11,30,9; lfsx f0,30,9; lfs f13,0x8(11); lfs f12,0x4(11); fsubs f0,f0,f11; fsubs f13,f13,f9; stfs f0,0x8(1); fsubs f12,f12,f10; stfs f13,0x10(1); stfs f12,0xc(1); bl _s802CFC34_1; lfs f0,0x1cf0(30); fcmpu 0,f1,f0; bge 5f; stfs f1,0x1cf0(30); lbz 0,0x34(28); stw 0,0x10e0(30); 5:; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s802CFC34_0();
extern "C" void _s802CFC34_1();
extern "C" void f_802CFC34() {}
