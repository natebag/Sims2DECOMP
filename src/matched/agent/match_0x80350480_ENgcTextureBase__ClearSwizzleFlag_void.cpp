// 0x80350480 ENgcTextureBase::ClearSwizzleFlag(void) (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); mr 31,3; lwz 0,0x8(31); andi. 9,0,128; beq 6f; lhz 0,0x16(31); li 4,1; cmplwi 0,1; ble 0f; mr 4,0; 0:; mr 3,31; addi 5,1,8; addi 6,1,12; bl _s80350480_0; lwz 0,0x78(31); mr 30,3; cmpwi 0,0; bne 1f; bl _s80350480_1; mr 4,30; li 5,32; li 6,0; li 7,0; bl _s80350480_2; stw 3,0x78(31); 1:; lwz 9,0x24(31); li 4,2; li 30,0; lha 3,0x38(9); lwz 0,0x3c(9); add 3,31,3; mtspr 8,0; blrl; b 3f; 2:; mr 4,30; addi 5,1,16; addi 6,1,20; mr 3,31; bl _s80350480_3; addi 30,30,1; lwz 9,0x24(31); mr 4,3; lwz 7,0x78(31); lha 3,0xb0(9); lwz 0,0x74(31); add 7,7,4; lwz 9,0xb4(9); add 3,31,3; add 4,0,4; lwz 5,0x10(1); lwz 6,0x14(1); mtspr 8,9; blrl; 3:; lhz 0,0x16(31); cmplwi 0,1; ble 4f; cmpw 30,0; blt 2b; b 5f; 4:; cmpwi 30,0; ble 2b; 5:; lwz 9,0x24(31); lha 3,0x70(9); lwz 0,0x74(9); add 3,31,3; mtspr 8,0; blrl; 6:; lwz 0,0x8(31); rlwinm 0,0,0,25,23; stw 0,0x8(31); lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s80350480_0();
extern "C" void _s80350480_1();
extern "C" void _s80350480_2();
extern "C" void _s80350480_3();
extern "C" void f_80350480() {}
