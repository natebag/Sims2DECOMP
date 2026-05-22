// 0x80327234 EResourceManager::DelRef(EResource (328 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 11,-22652(13); mr 30,3; mr 31,4; mr 29,5; cmpwi 11,0; beq 0f; lwz 9,0x0(11); mr 4,30; lwz 5,0x8(31); lha 3,0x58(9); lwz 0,0x5c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; bne 4f; 0:; lwz 0,0x48(30); cmpwi 0,0; beq 4f; mr 3,30; li 4,-1; bl _s80327234_0; lha 0,0xc(31); cmpwi 0,0; beq 2f; lhz 9,0xc(31); mr 4,31; addi 9,9,-1; sth 9,0xc(31); lwz 11,0xd1c(30); lhz 0,0xc(31); lha 3,0x40(11); lwz 0,0x44(11); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; beq 1f; cmpwi 29,0; beq 1f; lha 0,0xc(31); cmpwi 0,0; bne 2f; lwz 9,0x0(31); lwz 0,0x6c(9); lha 3,0x68(9); mtspr 8,0; add 3,31,3; blrl; lha 0,0xe(31); cmpwi 0,0; bne 2f; mr 4,31; addi 3,30,88; bl _s80327234_1; b 2f; 1:; lha 0,0xc(31); cmpwi 0,0; beq 3f; 2:; mr 3,30; bl _s80327234_2; b 4f; 3:; lwz 4,0x8(31); addi 3,30,3336; bl _s80327234_3; mr 3,30; bl _s80327234_4; lwz 9,0x0(31); lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; mtspr 8,0; blrl; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80327234_0();
extern "C" void _s80327234_1();
extern "C" void _s80327234_2();
extern "C" void _s80327234_3();
extern "C" void _s80327234_4();
extern "C" void f_80327234() {}
