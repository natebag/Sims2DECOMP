// 0x802CC338 ENDummy::GetDummyPointOrient(int, (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-192(1); mfspr 0,8; stmw 23,0x9c(1); stw 0,0xc4(1); mr 27,3; mr 31,6; mr 29,4; mr 25,5; mr 3,31; bl _s802CC338_0; lwz 0,0x4c(27); cmpw 29,0; bgt 0f; mulli 11,29,80; lwz 9,0x48(27); addi 3,1,88; lwzx 0,9,11; add 9,9,11; stw 0,0x48(1); addi 10,9,4; addi 4,9,16; lfs f0,0x4(9); stfs f0,0x4c(1); lfs f13,0x4(10); stfs f13,0x50(1); lfs f0,0x8(10); stfs f0,0x54(1); bl _s802CC338_1; mr 5,25; addi 3,1,8; addi 4,1,88; bl _s802CC338_2; addi 9,1,8; lwz 23,0x8(1); lwz 24,0xc(1); lwz 11,0x38(9); lwz 12,0x3c(9); lwz 7,0x8(9); lwz 8,0xc(9); lwz 5,0x10(9); lwz 6,0x14(9); lwz 3,0x18(9); lwz 4,0x1c(9); lwz 29,0x20(9); lwz 30,0x24(9); lwz 27,0x28(9); lwz 28,0x2c(9); lwz 25,0x30(9); lwz 26,0x34(9); stw 11,0x38(31); stw 12,0x3c(31); stw 23,0x0(31); stw 24,0x4(31); stw 7,0x8(31); stw 8,0xc(31); stw 5,0x10(31); stw 6,0x14(31); stw 3,0x18(31); stw 4,0x1c(31); stw 29,0x20(31); stw 30,0x24(31); stw 27,0x28(31); stw 28,0x2c(31); stw 25,0x30(31); stw 26,0x34(31); 0:; lwz 0,0xc4(1); mtspr 8,0; lmw 23,0x9c(1); addi 1,1,192"
extern "C" void _s802CC338_0();
extern "C" void _s802CC338_1();
extern "C" void _s802CC338_2();
extern "C" void f_802CC338() {}
