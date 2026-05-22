// 0x80300648 EWindow::SetInputCoordinates(TRect<float> (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lfs f0,0x0(4); lfs f13,0x40(31); addi 9,31,64; li 0,0; fcmpu 0,f13,f0; bne 0f; lfs f13,0x4(9); lfs f0,0x4(4); fcmpu 0,f13,f0; bne 0f; lfs f13,0x8(9); lfs f0,0x8(4); fcmpu 0,f13,f0; bne 0f; lfs f13,0xc(9); lfs f0,0xc(4); fcmpu 0,f13,f0; beq 1f; 0:; li 0,1; 1:; cmpwi 0,0; beq 2f; lfs f13,0x0(4); addi 9,31,64; mr 3,31; stfs f13,0x40(31); lfs f0,0x4(4); stfs f0,0x4(9); lfs f13,0x8(4); stfs f13,0x8(9); lfs f0,0xc(4); stfs f0,0xc(9); bl _s80300648_0; mr 3,31; bl _s80300648_1; lwz 9,0x9c(31); lha 3,0x20(9); lwz 0,0x24(9); add 3,31,3; mtspr 8,0; blrl; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80300648_0();
extern "C" void _s80300648_1();
extern "C" void f_80300648() {}
