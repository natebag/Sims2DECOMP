// 0x80047234 EIFloor::EIFloor(void) (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 30,0x28(1); stw 0,0x34(1); mr 30,3; bl _s80047234_0; lis 9,-32698; lis 11,-32707; addi 9,9,-18488; addi 8,30,284; stw 9,0x0(30); addi 7,30,272; addi 10,1,24; li 6,0; lfs f0,0x2e1c(11); addi 3,30,132; li 4,0; li 5,128; stfs f0,0x8(1); stfs f0,0x10(1); stfs f0,0xc(1); lwz 0,0x8(1); lwz 9,0xc(1); lwz 11,0x10(1); stw 0,0x11c(30); stw 9,0x4(8); stw 11,0x8(8); lwz 0,0x11c(30); stw 0,0x110(30); stw 9,0x4(7); stw 11,0x8(7); stfs f0,0x18(1); stfs f0,0x8(10); lwz 0,0x5c(30); stfs f0,0x4(10); rlwinm 0,0,0,23,21; lwz 9,0x18(1); oris 0,0,1; lwz 10,0x1c(1); lwz 11,0x20(1); stw 9,0x11c(30); stw 0,0x5c(30); stw 11,0x8(8); stw 10,0x4(8); lwz 0,0x11c(30); stw 0,0x110(30); stw 11,0x8(7); stw 10,0x4(7); stw 6,0x80(30); stw 6,0x104(30); bl _s80047234_1; mr 3,30; lwz 0,0x34(1); mtspr 8,0; lmw 30,0x28(1); addi 1,1,48"
extern "C" void _s80047234_0();
extern "C" void _s80047234_1();
extern "C" void f_80047234() {}
