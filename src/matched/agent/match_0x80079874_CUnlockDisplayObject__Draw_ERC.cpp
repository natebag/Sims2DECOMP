// 0x80079874 CUnlockDisplayObject::Draw(ERC (300 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 30,0x48(1); stw 0,0x54(1); mr 31,3; mr 30,4; lwz 0,0xc(31); cmpwi 0,0; beq 6f; lwz 0,0x80(31); cmpwi 0,0; bne 4f; lwz 3,0x10(31); cmpwi 3,0; beq 4f; lwz 5,-26812(13); lwz 4,0x24(31); bl _s80079874_0; lwz 9,0x10(31); lwz 5,0x24(9); cmpwi 5,0; beq 0f; lwz 5,0x18(5); b 1f; 0:; li 5,0; 1:; lwz 9,0x1c(31); lwz 11,0x10(31); lwz 10,0x120(9); lwz 4,0x10(11); lwz 0,0x8c(10); cmpwi 0,0; beq 2f; lwz 9,0x70(30); lha 3,0xd8(9); lwz 0,0xdc(9); add 3,30,3; mtspr 8,0; blrl; b 3f; 2:; lwz 9,0x70(30); lha 3,0xe8(9); lwz 0,0xec(9); add 3,30,3; mtspr 8,0; blrl; 3:; lwz 3,0x1c(31); mr 4,30; lwz 5,0x10(31); bl _s80079874_1; b 5f; 4:; lwz 3,0x14(31); bl _s80079874_2; mr 4,3; lwz 5,0x24(31); addi 3,1,8; bl _s80079874_3; lwz 9,0x70(30); addi 4,1,8; li 5,1; lha 3,0xe8(9); lwz 0,0xec(9); add 3,30,3; mtspr 8,0; blrl; lwz 3,0x1c(31); mr 4,30; li 5,0; bl _s80079874_4; 5:; li 0,1; stw 0,0x7c(31); 6:; lwz 0,0x54(1); mtspr 8,0; lmw 30,0x48(1); addi 1,1,80"
extern "C" void _s80079874_0();
extern "C" void _s80079874_1();
extern "C" void _s80079874_2();
extern "C" void _s80079874_3();
extern "C" void _s80079874_4();
extern "C" void f_80079874() {}
