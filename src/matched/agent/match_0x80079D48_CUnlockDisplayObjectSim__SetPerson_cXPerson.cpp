// 0x80079D48 CUnlockDisplayObjectSim::SetPerson(cXPerson (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; stw 4,0x88(31); bl _s80079D48_0; li 6,0; li 7,0; li 4,1608; li 5,16; bl _s80079D48_1; mr 30,3; li 5,1608; li 4,0; bl _s80079D48_2; lwz 4,0x88(31); mr 3,30; bl _s80079D48_3; stw 3,0x8c(31); lwz 11,0x88(31); lwz 9,0x4(11); lwz 0,0x154(9); lha 3,0x150(9); mtspr 8,0; add 3,11,3; blrl; addi 10,31,144; li 0,288; 0:; lwz 11,0x0(3); addic. 0,0,-24; stw 11,0x0(10); lwz 11,0x4(3); stw 11,0x4(10); lwz 11,0x8(3); stw 11,0x8(10); lwz 11,0xc(3); stw 11,0xc(10); lwz 11,0x10(3); stw 11,0x10(10); lwz 11,0x14(3); addi 3,3,24; stw 11,0x14(10); addi 10,10,24; bne 0b; lwz 11,0x0(3); lis 9,-32707; lfs f0,0x6518(9); addi 0,31,144; stw 11,0x0(10); stw 0,0x1b4(31); lwz 9,0x8c(31); addi 9,9,820; stw 9,0x10(31); stfs f0,0x54(9); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80079D48_0();
extern "C" void _s80079D48_1();
extern "C" void _s80079D48_2();
extern "C" void _s80079D48_3();
extern "C" void f_80079D48() {}
