// 0x800C09EC IFFBehResFile::IFFNodeSize(unsigned (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stmw 27,0x5c(1); stw 0,0x74(1); mr 29,4; li 31,1; mr 30,3; mr 27,5; li 28,0; cmplw 31,29; bgt 2f; 0:; lwz 3,0x138(30); mr 4,27; mr 5,31; li 6,0; bl _s800C09EC_0; mr. 3,3; beq 1f; lwz 5,0x0(3); addi 4,1,8; mr 3,30; bl _s800C09EC_1; cmpwi 3,0; bne 1f; lwz 0,0xc(1); add 28,28,0; 1:; addi 0,31,1; rlwinm 31,0,0,16,31; cmplw 31,29; ble 0b; 2:; mr 3,28; lwz 0,0x74(1); mtspr 8,0; lmw 27,0x5c(1); addi 1,1,112"
extern "C" void _s800C09EC_0();
extern "C" void _s800C09EC_1();
extern "C" void f_800C09EC() {}
