// 0x800CC380 Neighbor::StartNewTree(unsigned (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); mr 28,4; lis 9,-32697; mr 31,3; lwz 4,0x5eec(9); addi 3,1,8; lwz 29,0x194(31); mulli 30,28,12; subfic 6,28,12; subfe 6,6,6; neg 6,6; mr 5,31; bl _s800CC380_0; lwz 8,0x8(1); addi 9,1,8; lwz 10,0x8(9); add 11,30,29; lwz 0,0x4(9); mr 4,31; stwx 8,30,29; stw 10,0x8(11); stw 0,0x4(11); lwz 3,0x194(31); add 3,30,3; bl _s800CC380_1; cmpwi 3,0; beq 0f; mr 3,31; mr 4,28; bl _s800CC380_2; 0:; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s800CC380_0();
extern "C" void _s800CC380_1();
extern "C" void _s800CC380_2();
extern "C" void f_800CC380() {}
