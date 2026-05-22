// 0x80361B78 EStringTableNoCase::Find(unsigned (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; lwz 0,0x8(31); mr 29,5; cmpwi 0,0; bne 0f; lwz 4,0xc(31); bl _s80361B78_0; 0:; lwz 11,0x8(31); rlwinm 9,30,2,0,29; lwzx 31,9,11; cmpwi 31,0; beq 3f; 1:; addi 3,31,12; mr 4,29; bl _s80361B78_1; cmpwi 3,0; bne 2f; mr 3,31; b 4f; 2:; lwz 31,0x8(31); cmpwi 31,0; bne 1b; 3:; li 3,0; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80361B78_0();
extern "C" void _s80361B78_1();
extern "C" void f_80361B78() {}
