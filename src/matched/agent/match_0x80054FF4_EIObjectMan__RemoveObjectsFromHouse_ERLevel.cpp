// 0x80054FF4 EIObjectMan::RemoveObjectsFromHouse(ERLevel (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,3; mr 29,4; lwz 31,0x4(28); cmpwi 31,0; beq 1f; 0:; lwz 30,0x1c(31); mr 3,29; mr 4,30; bl _s80054FF4_0; lwz 9,0x0(30); mr 4,29; lha 3,0x190(9); lwz 0,0x194(9); add 3,30,3; mtspr 8,0; blrl; lwz 31,0x10(31); cmpwi 31,0; bne 0b; 1:; lwzu 30,0x4(28); mr 31,28; b 3f; 2:; lwz 11,0x1c(30); lwz 30,0x10(30); lwz 9,0x0(11); lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 3:; li 0,1; cmpwi 30,0; bne 4f; li 0,0; 4:; cmpwi 0,0; bne 2b; mr 3,31; bl _s80054FF4_1; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80054FF4_0();
extern "C" void _s80054FF4_1();
extern "C" void f_80054FF4() {}
