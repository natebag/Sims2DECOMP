// 0x80284880 AptCharacterAnimation::ExecuteInitActions(AptCIH (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; mfcr 12; stmw 26,0x10(1); stw 0,0x2c(1); stw 12,0xc(1); mr 26,4; mr 27,5; lwz 11,0x4c(26); mr 30,3; mr 4,27; lwz 9,0x8(11); addi 28,9,8; bl _s80284880_0; mr 31,3; cmpwi 31,-1; beq 0f; mr 3,30; mr 4,31; bl _s80284880_1; mr 27,3; cmpwi 27,-1; beq 0f; lwz 0,0x24(30); rlwinm 9,31,4,0,27; rlwinm 8,27,2,0,29; add 9,9,0; lwz 11,0xc(9); lwz 10,0x10(11); addi 30,10,8; lwz 9,0x10(30); lwzx 11,8,9; addi 28,11,8; 0:; lwz 0,0x0(28); cmpwi 4,27,-1; cmpwi 0,0; ble 3f; lwz 9,0x4(28); li 31,0; lwz 0,0x0(9); cmpw 31,0; bge 3f; li 29,0; 1:; lwz 9,0x4(9); lwzx 5,29,9; lwz 0,0x0(5); cmpwi 0,3; bne 2f; lwz 5,0xc(5); cmpwi 5,-1; beq 2f; mr 3,30; mr 4,26; bl _s80284880_2; 2:; lwz 9,0x4(28); addi 31,31,1; addi 29,29,4; lwz 0,0x0(9); cmpw 31,0; blt 1b; 3:; beq cr4,4f; mr 3,30; mr 4,26; mr 5,27; bl _s80284880_3; 4:; lwz 0,0x2c(1); lwz 12,0xc(1); mtspr 8,0; lmw 26,0x10(1); mtcrf 8,12; addi 1,1,40"
extern "C" void _s80284880_0();
extern "C" void _s80284880_1();
extern "C" void _s80284880_2();
extern "C" void _s80284880_3();
extern "C" void f_80284880() {}
