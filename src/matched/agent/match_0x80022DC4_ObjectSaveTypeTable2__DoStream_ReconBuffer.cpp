// 0x80022DC4 ObjectSaveTypeTable2::DoStream(ReconBuffer (320 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; mfcr 12; stmw 26,0x28(1); stw 0,0x44(1); stw 12,0x24(1); mr 28,3; mr 31,4; mr 29,5; addi 3,1,8; bl _s80022DC4_0; li 0,0; addi 4,1,20; stw 0,0x1c(1); mr 26,4; stw 0,0x18(1); mr 3,31; lwz 30,-21508(13); li 5,1; bl _s80022DC4_1; lwz 0,0x14(1); cmpwi 0,0; beq 5f; cmpwi 4,29,1; li 27,-1; cmpwi 29,0; mfcr 29; 0:; mtcrf 128,29; ble 1f; mr 3,31; addi 4,1,24; li 5,1; bl _s80022DC4_2; mr 3,31; addi 4,1,28; li 5,1; bl _s80022DC4_3; 1:; mr 3,31; addi 4,1,16; li 5,1; bl _s80022DC4_4; ble cr4,2f; mr 3,31; addi 4,1,18; li 5,1; bl _s80022DC4_5; b 3f; 2:; sth 27,0x12(1); 3:; mr 3,31; addi 4,1,8; bl _s80022DC4_6; lwz 9,0x0(30); lwz 4,0x14(1); lha 3,0x78(9); lwz 0,0x7c(9); add 3,30,3; mtspr 8,0; blrl; mr. 3,3; beq 4f; mr 4,28; li 5,0; bl _s80022DC4_7; 4:; mr 3,31; mr 4,26; li 5,1; bl _s80022DC4_8; lwz 0,0x14(1); cmpwi 0,0; bne 0b; 5:; addi 3,1,8; li 4,2; bl _s80022DC4_9; lwz 0,0x44(1); lwz 12,0x24(1); mtspr 8,0; lmw 26,0x28(1); mtcrf 8,12; addi 1,1,64"
extern "C" void _s80022DC4_0();
extern "C" void _s80022DC4_1();
extern "C" void _s80022DC4_2();
extern "C" void _s80022DC4_3();
extern "C" void _s80022DC4_4();
extern "C" void _s80022DC4_5();
extern "C" void _s80022DC4_6();
extern "C" void _s80022DC4_7();
extern "C" void _s80022DC4_8();
extern "C" void _s80022DC4_9();
extern "C" void f_80022DC4() {}
