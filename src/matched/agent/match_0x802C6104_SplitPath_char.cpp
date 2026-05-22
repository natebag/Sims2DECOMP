// 0x802C6104 SplitPath(char (484 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; mfcr 12; stmw 24,0x10(1); stw 0,0x34(1); stw 12,0xc(1); mr 30,3; mr 31,4; mr 26,5; mr 25,6; mr 24,7; bl _s802C6104_0; li 27,0; cmpwi 3,0; beq 1f; lbz 0,0x1(30); cmpwi 0,58; bne 1f; cmpwi 31,0; beq 0f; mr 3,31; mr 4,30; li 5,2; bl _s802C6104_1; stb 27,0x2(31); 0:; addi 30,30,2; b 2f; 1:; cmpwi 31,0; beq 2f; li 0,0; stb 0,0x0(31); 2:; lbz 0,0x0(30); li 28,0; mr 29,30; cmpwi 7,26,0; cmpwi 0,0; cmpwi 4,25,0; cmpwi 3,24,0; beq 7f; 3:; lbz 0,0x0(29); extsb 0,0; cmpwi 0,47; beq 4f; cmpwi 0,92; bne 5f; 4:; addi 28,29,1; mr 0,28; b 6f; 5:; cmpwi 0,46; addi 0,29,1; bne 6f; mr 27,29; 6:; mr 29,0; lbz 0,0x0(29); cmpwi 0,0; bne 3b; 7:; cmpwi 28,0; beq 10f; beq cr7,9f; subf 31,30,28; cmplwi 31,255; ble 8f; li 31,255; 8:; mr 4,30; mr 3,26; mr 5,31; bl _s802C6104_2; li 0,0; stbx 0,26,31; 9:; mr 30,28; b 11f; 10:; beq cr7,11f; stb 28,0x0(26); 11:; cmpwi 27,0; beq 15f; cmplw 27,30; blt 15f; beq cr4,13f; subf 31,30,27; cmplwi 31,255; ble 12f; li 31,255; 12:; mr 4,30; mr 3,25; mr 5,31; bl _s802C6104_3; li 0,0; stbx 0,25,31; 13:; beq cr3,18f; subf 31,27,29; cmplwi 31,255; ble 14f; li 31,255; 14:; mr 4,27; mr 3,24; mr 5,31; bl _s802C6104_4; li 0,0; stbx 0,24,31; b 18f; 15:; beq cr4,17f; subf 31,30,29; cmplwi 31,255; ble 16f; li 31,255; 16:; mr 4,30; mr 3,25; mr 5,31; bl _s802C6104_5; li 0,0; stbx 0,25,31; 17:; beq cr3,18f; li 0,0; stb 0,0x0(24); 18:; lwz 0,0x34(1); lwz 12,0xc(1); mtspr 8,0; lmw 24,0x10(1); mtcrf 24,12; addi 1,1,48"
extern "C" void _s802C6104_0();
extern "C" void _s802C6104_1();
extern "C" void _s802C6104_2();
extern "C" void _s802C6104_3();
extern "C" void _s802C6104_4();
extern "C" void _s802C6104_5();
extern "C" void f_802C6104() {}
