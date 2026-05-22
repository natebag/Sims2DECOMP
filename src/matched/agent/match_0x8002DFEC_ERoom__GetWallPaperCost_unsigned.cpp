// 0x8002DFEC ERoom::GetWallPaperCost(unsigned (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32697; mr 29,5; lwz 11,0x5ea4(9); li 28,0; li 8,0; lwz 11,0x0(11); cmpwi 11,0; beq 0f; lwz 8,-4(11); 0:; addi 3,3,148; li 10,0; cmpw 28,8; bge 3f; lwz 9,0x0(11); b 2f; 1:; addi 10,10,1; cmpw 10,8; bge 3f; rlwinm 9,10,2,0,29; lwzx 9,11,9; 2:; lwz 0,0x8(9); cmpw 4,0; bne 1b; lwz 28,0x0(9); 3:; mr 4,29; li 5,0; bl _s8002DFEC_0; li 30,0; mr. 3,3; beq 5f; lwz 3,0x1c(3); cmpwi 3,0; beq 5f; lwz 31,0x0(3); cmpwi 31,0; beq 5f; 4:; lwz 3,0x0(31); mr 4,28; mr 5,29; bl _s8002DFEC_1; lwz 31,0x8(31); add 30,30,3; cmpwi 31,0; bne 4b; 5:; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8002DFEC_0();
extern "C" void _s8002DFEC_1();
extern "C" void f_8002DFEC() {}
