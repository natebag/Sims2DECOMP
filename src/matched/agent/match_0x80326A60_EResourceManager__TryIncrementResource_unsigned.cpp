// 0x80326A60 EResourceManager::TryIncrementResource(unsigned (388 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,5; li 0,0; mr 29,3; mr 30,4; stw 0,0x0(31); li 4,-1; li 28,0; bl _s80326A60_0; mr 4,30; addi 3,29,3336; mr 5,31; bl _s80326A60_1; cmpwi 3,0; beq 4f; lwz 11,0x0(31); lha 0,0xc(11); cmpwi 0,0; bne 2f; lwz 3,-22652(13); lwz 9,0x0(3); lha 0,0x28(9); lwz 9,0x2c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 1f; lwz 4,0x0(31); lha 0,0xe(4); cmpwi 0,0; bne 0f; addi 3,29,88; bl _s80326A60_2; 0:; lwz 11,0x0(31); mr 3,29; li 28,1; lhz 9,0xe(11); addi 9,9,1; sth 9,0xe(11); bl _s80326A60_3; lwz 11,0x0(31); lwz 9,0x0(11); lha 3,0x70(9); lwz 0,0x74(9); add 3,11,3; mtspr 8,0; blrl; mr 3,29; li 4,-1; bl _s80326A60_4; lwz 11,0x0(31); lhz 9,0xc(11); addi 9,9,1; sth 9,0xc(11); lwz 10,0x0(31); lhz 9,0xe(10); addi 9,9,-1; sth 9,0xe(10); b 4f; 1:; lwz 11,0x0(31); lha 0,0xe(11); cmpwi 0,0; bne 4f; lwz 9,0x0(11); lha 3,0x78(9); lwz 0,0x7c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 4f; lwz 4,0x0(31); addi 3,29,88; li 28,1; bl _s80326A60_5; lwz 11,0x0(31); lhz 9,0xc(11); b 3f; 2:; lhz 9,0xc(11); li 28,1; 3:; addi 9,9,1; sth 9,0xc(11); 4:; mr 3,29; bl _s80326A60_6; cmpwi 28,0; bne 5f; stw 28,0x0(31); 5:; mr 3,28; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80326A60_0();
extern "C" void _s80326A60_1();
extern "C" void _s80326A60_2();
extern "C" void _s80326A60_3();
extern "C" void _s80326A60_4();
extern "C" void _s80326A60_5();
extern "C" void _s80326A60_6();
extern "C" void f_80326A60() {}
