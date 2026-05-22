// 0x80365C60 EControllerData::operator=(EControllerData (304 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,4; mr 30,3; lwz 9,0x0(29); li 0,2; mtspr 9,0; addi 10,30,108; stw 9,0x0(30); addi 11,29,108; lwz 0,0x4(29); stw 0,0x4(30); lwz 9,0x8(29); stw 9,0x8(30); lwz 0,0xc(29); stw 0,0xc(30); lwz 9,0x10(29); stw 9,0x10(30); lwz 0,0x14(29); stw 0,0x14(30); lwz 9,0x18(29); stw 9,0x18(30); lwz 0,0x20(29); stw 0,0x20(30); lwz 9,0x1c(29); stw 9,0x1c(30); lwz 0,0x24(29); stw 0,0x24(30); 0:; lfs f0,-68(11); stfs f0,-68(10); lfs f13,-64(11); stfs f13,-64(10); lfs f0,-52(11); stfs f0,-52(10); lfs f13,-48(11); stfs f13,-48(10); lfs f0,-36(11); stfs f0,-36(10); lfs f13,-32(11); stfs f13,-32(10); lfs f0,-20(11); stfs f0,-20(10); lfs f13,-16(11); stfs f13,-16(10); lwz 0,-4(11); stw 0,-4(10); lwz 9,0x0(11); addi 11,11,8; stw 9,0x0(10); addi 10,10,8; bdnz 0b; li 31,0; 1:; mr 4,31; mr 3,29; bl _s80365C60_0; mr 5,3; mr 4,31; mr 3,30; bl _s80365C60_1; mr 4,31; mr 3,29; bl _s80365C60_2; mr 5,3; mr 4,31; mr 3,30; addi 31,31,1; bl _s80365C60_3; cmpwi 31,31; ble 1b; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80365C60_0();
extern "C" void _s80365C60_1();
extern "C" void _s80365C60_2();
extern "C" void _s80365C60_3();
extern "C" void f_80365C60() {}
