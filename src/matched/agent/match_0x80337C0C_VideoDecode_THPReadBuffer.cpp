// 0x80337C0C VideoDecode(THPReadBuffer (296 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); lis 11,-32691; mr 25,3; addi 30,11,14656; lwz 9,0x0(25); lwz 0,0x6c(30); li 27,0; addi 26,9,8; rlwinm 0,0,2,0,29; add 9,9,0; addi 28,9,8; bl _s80337C0C_0; lwz 0,0x6c(30); mr 31,3; cmplw 27,0; bge 5f; mr 29,30; lis 23,-32691; addi 24,29,112; 0:; lbzx 30,24,27; cmpwi 30,0; bne 4f; lwz 4,0x0(31); mr 3,28; lwz 5,0x4(31); lwz 6,0x8(31); lwz 7,0x9c(29); bl _s80337C0C_1; cmpwi 3,0; stw 3,0xac(29); beq 2f; lwz 0,-22544(13); cmpwi 0,0; beq 1f; li 3,0; bl _s80337C0C_2; stw 30,-22544(13); 1:; addi 3,23,4704; bl _s80337C0C_3; 2:; lwz 0,0x4(25); mr 3,31; stw 0,0xc(31); bl _s80337C0C_4; bl _s80337C0C_5; cmpwi 3,0; li 3,1; bne 3f; li 3,0; 3:; lwz 9,0xd8(29); addi 9,9,1; stw 9,0xd8(29); bl _s80337C0C_6; 4:; lwz 9,0x0(26); addi 27,27,1; lwz 0,0x6c(29); addi 26,26,4; add 28,28,9; cmplw 27,0; blt 0b; 5:; lwz 0,-22544(13); cmpwi 0,0; beq 6f; li 3,1; bl _s80337C0C_7; li 0,0; stw 0,-22544(13); 6:; lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"
extern "C" void _s80337C0C_0();
extern "C" void _s80337C0C_1();
extern "C" void _s80337C0C_2();
extern "C" void _s80337C0C_3();
extern "C" void _s80337C0C_4();
extern "C" void _s80337C0C_5();
extern "C" void _s80337C0C_6();
extern "C" void _s80337C0C_7();
extern "C" void f_80337C0C() {}
