// 0x80328FC8 FreeResourceManager::AddItem(EResource (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 0,0x1c(31); cmpwi 0,0; beq 1f; li 4,-1; bl _s80328FC8_0; lwz 9,0xca0(31); lwz 0,0xca4(31); cmpw 9,0; bne 0f; mr 3,31; bl _s80328FC8_1; li 4,5; mr 3,31; bl _s80328FC8_2; mr 3,31; li 4,-1; bl _s80328FC8_3; lwz 9,0xca0(31); lwz 0,0xca4(31); cmpw 9,0; bne 0f; mr 3,31; bl _s80328FC8_4; lwz 9,0x0(30); lha 3,0x8(9); lwz 0,0xc(9); add 3,30,3; mtspr 8,0; blrl; b 1f; 0:; lwz 0,0xca0(31); addi 11,31,32; mr 3,31; rlwinm 0,0,2,0,29; stwx 30,11,0; lwz 9,0xca0(31); addi 9,9,1; stw 9,0xca0(31); bl _s80328FC8_5; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80328FC8_0();
extern "C" void _s80328FC8_1();
extern "C" void _s80328FC8_2();
extern "C" void _s80328FC8_3();
extern "C" void _s80328FC8_4();
extern "C" void _s80328FC8_5();
extern "C" void f_80328FC8() {}
