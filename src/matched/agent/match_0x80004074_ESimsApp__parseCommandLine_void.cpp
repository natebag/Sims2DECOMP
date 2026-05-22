// 0x80004074 ESimsApp::parseCommandLine(void) (716 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; mfcr 12; stmw 22,0x10(1); stw 0,0x3c(1); stw 12,0xc(1); mr 23,3; lis 9,-32697; lwz 25,0x348(23); li 0,0; lwz 27,0x34c(23); lis 3,-32707; addi 3,3,-19972; stb 0,-6480(9); crxor 6,6,6; bl _s80004074_0; li 30,0; lis 3,-32707; mr 4,25; addi 3,3,-19936; mr 5,27; crxor 6,6,6; bl _s80004074_1; cmpw 30,25; bge 1f; lis 29,-32707; mr 31,27; 0:; lwz 5,0x0(31); mr 4,30; addi 3,29,-19912; addi 30,30,1; crxor 6,6,6; bl _s80004074_2; addi 31,31,4; cmpw 30,25; blt 0b; 1:; cmpwi 27,0; beq 20f; cmpwi 25,0; ble 20f; lwz 4,0x0(27); cmpwi 4,0; beq 20f; lis 3,-32697; addi 3,3,-6480; bl _s80004074_3; cmpwi 25,1; ble 20f; li 24,0; cmpw 24,25; bge 20f; li 22,1; 2:; lwz 31,0x0(27); addi 24,24,1; cmpw cr3,24,25; addi 27,27,4; 3:; mr 3,31; li 4,32; bl _s80004074_4; li 26,0; mr. 29,3; beq 4f; stb 26,0x0(29); addi 3,29,1; li 4,32; li 30,0; bl _s80004074_5; mr. 26,3; beq 4f; stb 30,0x0(26); 4:; lbz 0,0x0(31); li 28,0; cmpwi 4,29,0; cmpwi 0,45; bne 16f; addi 31,31,1; li 30,0; bge cr3,5f; lwz 30,0x0(27); 5:; beq cr4,6f; addi 30,29,1; 6:; cmpwi 30,0; beq 7f; lbz 0,0x0(30); cmpwi 0,0; bne 7f; li 30,0; 7:; lbz 0,0x0(31); extsb 0,0; cmpwi 0,84; beq 12f; bgt 8f; cmpwi 0,76; beq 10f; cmpwi 0,78; beq 11f; b 16f; 8:; cmpwi 0,110; beq 11f; bgt 9f; cmpwi 0,108; beq 10f; b 16f; 9:; cmpwi 0,116; beq 12f; b 16f; 10:; lis 4,-32707; mr 3,31; addi 4,4,-19896; li 5,3; bl _s80004074_6; cmpwi 3,0; bne 16f; mr 3,30; bl _s80004074_7; addi 0,3,-1; cmplwi 0,15; bgt 15f; stw 3,-32752(13); b 15f; 11:; lis 4,-32707; mr 3,31; addi 4,4,-19892; li 5,3; bl _s80004074_8; cmpwi 3,0; bne 16f; mr 4,30; li 28,1; mr 3,23; bl _s80004074_9; b 16f; 12:; lis 4,-32707; mr 3,31; addi 4,4,-19888; bl _s80004074_10; cmpwi 3,0; beq 13f; lis 4,-32707; mr 3,31; addi 4,4,-19876; bl _s80004074_11; cmpwi 3,0; bne 14f; 13:; stw 22,-32756(13); b 16f; 14:; lis 4,-32707; mr 3,31; addi 4,4,-19864; bl _s80004074_12; cmpwi 3,0; bne 16f; cmpwi 30,0; beq 16f; stw 22,-32756(13); 15:; li 28,1; 16:; cmpwi 28,0; beq 17f; beq cr4,18f; mr 29,26; li 28,0; 17:; cmpwi 29,0; beq 18f; mr 31,29; b 3b; 18:; cmpwi 28,0; beq 19f; rlwinm 0,28,2,0,29; add 24,24,28; add 27,27,0; 19:; cmpw 24,25; blt 2b; 20:; lwz 0,0x3c(1); lwz 12,0xc(1); mtspr 8,0; lmw 22,0x10(1); mtcrf 24,12; addi 1,1,56"
extern "C" void _s80004074_0();
extern "C" void _s80004074_1();
extern "C" void _s80004074_2();
extern "C" void _s80004074_3();
extern "C" void _s80004074_4();
extern "C" void _s80004074_5();
extern "C" void _s80004074_6();
extern "C" void _s80004074_7();
extern "C" void _s80004074_8();
extern "C" void _s80004074_9();
extern "C" void _s80004074_10();
extern "C" void _s80004074_11();
extern "C" void _s80004074_12();
extern "C" void f_80004074() {}
