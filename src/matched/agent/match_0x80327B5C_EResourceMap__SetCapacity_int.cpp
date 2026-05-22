// 0x80327B5C EResourceMap::SetCapacity(int, (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; lwz 0,0x8(31); cmpw 30,0; ble 0f; bl _s80327B5C_0; rlwinm 4,30,3,0,28; li 5,0; bl _s80327B5C_1; mr. 29,3; beq 0f; lwz 5,0x8(31); mr 3,29; lwz 4,0x0(31); rlwinm 5,5,3,0,28; crxor 6,6,6; bl _s80327B5C_2; bl _s80327B5C_3; lwz 4,0x0(31); bl _s80327B5C_4; stw 30,0x8(31); stw 29,0x0(31); 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80327B5C_0();
extern "C" void _s80327B5C_1();
extern "C" void _s80327B5C_2();
extern "C" void _s80327B5C_3();
extern "C" void _s80327B5C_4();
extern "C" void f_80327B5C() {}
