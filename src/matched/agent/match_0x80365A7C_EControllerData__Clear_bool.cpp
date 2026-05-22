// 0x80365A7C EControllerData::Clear(bool) (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 0,0; lis 9,-32702; stw 0,0x78(31); lfs f0,0x31b0(9); li 11,0; stw 0,0xc(31); addi 9,31,104; stw 0,0x1c(31); li 30,2; stw 0,0x24(31); 0:; stfs f0,-44(9); addic. 30,30,-1; stfs f0,-48(9); stfs f0,-60(9); stfs f0,-64(9); stfs f0,-12(9); stfs f0,-16(9); stfs f0,-28(9); stfs f0,-32(9); stw 11,0x4(9); stw 11,0x0(9); addi 9,9,8; bne 0b; cmpwi 4,0; li 0,0; bne 1f; li 0,-1; 1:; stw 0,0x10(31); stw 0,0x14(31); li 0,0; li 30,0; stw 0,0x20(31); stw 0,0x0(31); stw 0,0x4(31); stw 0,0x8(31); stw 0,0x18(31); 2:; mr 4,30; mr 3,31; li 5,0; bl _s80365A7C_0; mr 4,30; mr 3,31; li 5,0; addi 30,30,1; bl _s80365A7C_1; cmpwi 30,31; ble 2b; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80365A7C_0();
extern "C" void _s80365A7C_1();
extern "C" void f_80365A7C() {}
