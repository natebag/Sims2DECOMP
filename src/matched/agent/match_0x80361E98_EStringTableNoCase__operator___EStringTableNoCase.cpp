// 0x80361E98 EStringTableNoCase::operator==(EStringTableNoCase (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 29,3; mr 31,4; bl _s80361E98_0; mr 30,3; mr 3,31; bl _s80361E98_1; cmpw 30,3; bne 1f; lwz 30,0x0(31); b 3f; 0:; lwz 4,0xc(30); mr 3,29; lwz 31,0x10(30); addi 5,1,8; bl _s80361E98_2; cmpwi 3,0; beq 1f; lwz 0,0x8(1); cmpw 0,31; beq 2f; 1:; li 3,0; b 5f; 2:; lwz 30,0x4(30); 3:; li 0,1; cmpwi 30,0; bne 4f; li 0,0; 4:; cmpwi 0,0; bne 0b; li 3,1; 5:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s80361E98_0();
extern "C" void _s80361E98_1();
extern "C" void _s80361E98_2();
extern "C" void f_80361E98() {}
