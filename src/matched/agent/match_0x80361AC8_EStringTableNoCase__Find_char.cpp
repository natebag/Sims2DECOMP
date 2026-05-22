// 0x80361AC8 EStringTableNoCase::Find(char (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; mfcr 12; stmw 29,0xc(1); stw 0,0x1c(1); stw 12,0x8(1); mr 31,3; mr 30,4; lwz 0,0x8(31); mr 29,5; cmpwi 0,0; bne 0f; lwz 4,0xc(31); bl _s80361AC8_0; 0:; mr 3,31; mr 4,30; bl _s80361AC8_1; lwz 9,0x8(31); rlwinm 3,3,2,0,29; lwzx 31,3,9; cmpwi 31,0; beq 4f; cmpwi 4,29,0; 1:; addi 3,31,12; mr 4,30; bl _s80361AC8_2; cmpwi 3,0; bne 3f; beq cr4,2f; lwz 0,0x10(31); stw 0,0x0(29); 2:; mr 3,31; b 5f; 3:; lwz 31,0x8(31); cmpwi 31,0; bne 1b; 4:; li 3,0; 5:; lwz 0,0x1c(1); lwz 12,0x8(1); mtspr 8,0; lmw 29,0xc(1); mtcrf 8,12; addi 1,1,24"
extern "C" void _s80361AC8_0();
extern "C" void _s80361AC8_1();
extern "C" void _s80361AC8_2();
extern "C" void f_80361AC8() {}
