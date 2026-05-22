// 0x802E61FC E3DWindow::TransformToScreen(EVec3 (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stfd f31,0x30(1); stmw 30,0x28(1); stw 0,0x3c(1); lis 9,-32702; lfs f0,0x0(4); lfs f13,0x4(4); mr 31,3; lfs f12,0x8(4); mr 30,5; lfs f31,-5020(9); addi 3,1,8; stfs f0,0x18(1); addi 4,1,24; stfs f13,0x1c(1); addi 5,31,288; stfs f12,0x20(1); stfs f31,0x24(1); bl _s802E61FC_0; lis 9,-32702; lfs f13,0x14(1); lfs f0,-5016(9); fcmpu 0,f13,f0; ble 1f; fdivs f11,f31,f13; li 0,2; mtspr 9,0; addi 10,31,592; addi 11,1,8; addi 3,31,576; li 9,0; 0:; lfsx f0,9,11; lfsx f12,9,3; lfsx f13,9,10; fmuls f0,f0,f11; fmadds f0,f0,f12,f13; stfsx f0,9,30; addi 9,9,4; bdnz 0b; li 3,1; b 2f; 1:; li 3,0; 2:; lwz 0,0x3c(1); mtspr 8,0; lmw 30,0x28(1); lfd f31,0x30(1); addi 1,1,56"
extern "C" void _s802E61FC_0();
extern "C" void f_802E61FC() {}
