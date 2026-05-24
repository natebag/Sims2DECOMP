// 0x80197958 CASGeneticsTarget::SetVariable(char (500 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 26,0x20(1); stw 0,0x3c(1); mr 30,3; lis 3,-32705; addi 3,3,-15008; bl _s80197958_0; mr 31,3; cmpwi 31,0; bne 5f; lwz 0,0x2f8(30); stw 31,-31440(13); cmpwi 0,0; bne 0f; li 3,60; bl _s80197958_1; bl _s80197958_2; cmpwi 3,0; stw 3,0x2f8(30); beq 1f; 0:; lwz 3,0x2f8(30); lis 4,27935; ori 4,4,2390; bl _s80197958_3; lwz 11,0x2f8(30); li 0,1; li 4,1; addi 6,1,24; stw 31,0x20(11); lwz 9,0x2f8(30); stw 0,0x24(9); lwz 11,0x84(30); lwz 5,0x2f8(30); lwz 10,0x18(11); addi 5,5,12; lwz 9,0x4(10); lha 3,0x70(9); lwz 0,0x74(9); add 3,10,3; mtspr 8,0; blrl; lis 9,-32696; lwz 11,0x2f8(30); lfs f0,0x55c0(9); stfs f0,0x18(11); 1:; lis 9,-32697; lwz 9,0x5bc0(9); lwz 11,0x134c(9); mr 0,11; cmpwi 11,0; bge 2f; addi 0,11,3; 2:; lwz 9,0x1348(9); rlwinm 0,0,0,0,29; subf 0,0,11; addi 29,30,812; srw 9,9,0; addi 27,30,824; andi. 0,9,1; addi 26,30,796; addi 28,1,8; bne 4f; li 0,1; li 31,0; stw 0,0x2f4(30); 3:; mr 4,31; mr 3,30; bl _s80197958_4; addi 31,31,1; cmplwi 31,3; ble 3b; mr 3,30; li 4,0; bl _s80197958_5; mr 3,30; li 4,1; bl _s80197958_6; 4:; mr 3,30; bl _s80197958_7; li 0,0; li 9,1; stw 0,0x410(30); lis 10,-32696; stw 9,0x40c(30); addi 10,10,21920; lwz 11,0x84(30); lis 7,-32696; addi 6,7,32180; lwz 9,0x28(11); mulli 9,9,12; lwzx 11,9,10; add 9,9,10; lwz 0,0x4(9); lwz 8,0x8(9); stw 11,0x32c(30); stw 0,0x4(29); stw 8,0x8(29); lwz 0,0x7db4(7); lwz 9,0x8(6); lwz 11,0x4(6); stw 0,0x338(30); stw 9,0x8(27); stw 11,0x4(27); lfs f11,0x24(10); lfs f0,0x32c(30); lfs f13,0x8(29); lfs f12,0x4(29); fmuls f0,f0,f11; stfs f0,0x8(1); fmuls f13,f13,f11; fmuls f12,f12,f11; stfs f13,0x10(1); stfs f12,0xc(1); lwz 0,0x8(1); lwz 9,0x8(28); lwz 11,0x4(28); stw 0,0x31c(30); stw 9,0x8(26); stw 11,0x4(26); 5:; lwz 0,0x3c(1); mtspr 8,0; lmw 26,0x20(1); addi 1,1,56"

extern "C" void _s80197958_0();
extern "C" void _s80197958_1();
extern "C" void _s80197958_2();
extern "C" void _s80197958_3();
extern "C" void _s80197958_4();
extern "C" void _s80197958_5();
extern "C" void _s80197958_6();
extern "C" void _s80197958_7();

struct CASGeneticsTarget {
    void SetVariable();
};

void CASGeneticsTarget::SetVariable() {
}
