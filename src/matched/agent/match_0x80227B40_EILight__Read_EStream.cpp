// 0x80227B40 EILight::Read(EStream (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; mr 31,4; bl _s80227B40_0; lis 9,-32688; lhz 0,-13418(9); cmpwi 0,0; bne 3f; lwz 9,0x18(31); addi 4,1,8; li 5,1; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,31,3; blrl; lbz 0,0x8(1); li 9,1; cmpwi 0,0; bne 0f; li 9,0; 0:; stw 9,0x88(30); addi 4,1,8; li 5,1; lwz 9,0x18(31); lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,31,3; blrl; lbz 0,0x8(1); li 9,1; cmpwi 0,0; bne 1f; li 9,0; 1:; stw 9,0x7c(30); addi 4,1,8; li 5,1; lwz 9,0x18(31); lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,31,3; blrl; lbz 0,0x8(1); li 9,1; cmpwi 0,0; bne 2f; li 9,0; 2:; stw 9,0x80(30); addi 4,30,140; li 5,4; lwz 9,0x18(31); lha 3,0x30(9); lwz 0,0x34(9); add 3,31,3; mtspr 8,0; blrl; addi 4,30,144; mr 3,31; bl _s80227B40_1; addi 4,30,132; bl _s80227B40_2; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s80227B40_0();
extern "C" void _s80227B40_1();
extern "C" void _s80227B40_2();
extern "C" void f_80227B40() {}
