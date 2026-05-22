// 0x8030D944 BSplineVolume::Free(void) (552 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 21,0xc(1); stw 0,0x3c(1); mr 31,3; lwz 0,0x94(31); cmpwi 0,0; beq 9f; lwz 0,0x90(31); li 10,0; lis 23,-32692; cmpw 10,0; bge 8f; 0:; lwz 9,0x94(31); rlwinm 11,10,2,0,29; mr 27,11; addi 22,10,1; lwzx 0,11,9; cmpwi 0,0; beq 7f; lwz 0,0x84(31); li 10,0; cmpw 10,0; bge 6f; mr 26,27; li 21,0; 1:; lwzx 11,27,9; addi 24,10,1; rlwinm 9,10,2,0,29; lwzx 0,9,11; mr 29,9; cmpwi 0,0; beq 5f; lwz 0,0x88(31); li 28,0; cmpw 28,0; bge 4f; li 25,0; li 30,0; 2:; lwz 9,0x94(31); lwzx 11,27,9; lwzx 10,29,11; lwzx 4,30,10; cmpwi 4,0; beq 3f; addi 3,23,-27556; bl _s8030D944_0; lwz 9,0x94(31); lwzx 11,27,9; lwzx 10,29,11; stwx 25,30,10; 3:; lwz 0,0x88(31); addi 28,28,1; addi 30,30,4; cmpw 28,0; blt 2b; 4:; lwz 11,0x94(31); addi 3,23,-27556; lwzx 9,26,11; lwzx 4,29,9; bl _s8030D944_1; lwz 9,0x94(31); lwzx 11,26,9; stwx 21,29,11; 5:; lwz 0,0x84(31); mr 10,24; lwz 9,0x94(31); cmpw 10,0; blt 1b; 6:; lwz 9,0x94(31); addi 3,23,-27556; lwzx 4,27,9; bl _s8030D944_2; lwz 9,0x94(31); li 0,0; stwx 0,27,9; 7:; lwz 0,0x90(31); mr 10,22; cmpw 10,0; blt 0b; 8:; lis 3,-32692; lwz 4,0x94(31); addi 3,3,-27556; bl _s8030D944_3; li 0,0; stw 0,0x94(31); 9:; lwz 0,0x98(31); cmpwi 0,0; beq 14f; lwz 0,0x84(31); li 9,0; lis 23,-32692; cmpw 9,0; bge 13f; 10:; lwz 0,0x88(31); li 29,0; addi 27,9,1; rlwinm 28,9,2,0,29; cmpw 29,0; bge 12f; li 30,0; 11:; lwz 9,0x98(31); addi 3,23,-27556; addi 29,29,1; lwzx 11,28,9; lwzx 4,30,11; addi 30,30,4; bl _s8030D944_4; lwz 0,0x88(31); cmpw 29,0; blt 11b; 12:; lwz 9,0x98(31); addi 3,23,-27556; lwzx 4,28,9; bl _s8030D944_5; lwz 0,0x84(31); mr 9,27; cmpw 9,0; blt 10b; 13:; lis 3,-32692; lwz 4,0x98(31); addi 3,3,-27556; bl _s8030D944_6; li 0,0; stw 0,0x98(31); 14:; lwz 4,0xa4(31); cmpwi 4,0; beq 15f; lis 3,-32692; addi 3,3,-27556; bl _s8030D944_7; li 0,0; stw 0,0xa4(31); 15:; lwz 0,0x3c(1); mtspr 8,0; lmw 21,0xc(1); addi 1,1,56"
extern "C" void _s8030D944_0();
extern "C" void _s8030D944_1();
extern "C" void _s8030D944_2();
extern "C" void _s8030D944_3();
extern "C" void _s8030D944_4();
extern "C" void _s8030D944_5();
extern "C" void _s8030D944_6();
extern "C" void _s8030D944_7();
extern "C" void f_8030D944() {}
