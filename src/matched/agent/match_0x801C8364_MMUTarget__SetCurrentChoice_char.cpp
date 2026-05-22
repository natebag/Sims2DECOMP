// 0x801C8364 MMUTarget::SetCurrentChoice(char (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 0,0xb0(31); cmpwi 0,1; bne 0f; lwz 9,0x80(31); lis 4,-32705; addi 4,4,10332; mr 5,30; lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; 0:; lwz 0,0xb0(31); cmpwi 0,0; bne 1f; lwz 9,0x80(31); lis 4,-32705; addi 4,4,10356; mr 5,30; lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; 1:; lwz 0,0xb0(31); cmpwi 0,4; bne 2f; lwz 9,0x80(31); lis 4,-32705; addi 4,4,10384; mr 5,30; lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_801C8364() {}
