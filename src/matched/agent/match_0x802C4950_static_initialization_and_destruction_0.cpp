// 0x802C4950 __static_initialization_and_destruction_0 (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 4f; cmpwi 3,0; beq 1f; lis 9,-32694; lis 10,-32700; addi 11,9,-11332; addi 0,10,-6476; li 9,178; mtspr 9,9; 0:; lhz 9,-6476(10); stw 0,0x0(11); addi 9,9,1; addi 11,11,4; sth 9,-6476(10); bdnz 0b; b 4f; 1:; lis 9,-32694; addi 9,9,-11332; cmpwi 9,0; beq 4f; addi 31,9,712; cmpw 31,9; beq 4f; mr 30,9; 2:; lwzu 4,-4(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 3f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802C4950_0; 3:; cmpw 31,30; bne 2b; 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802C4950_0();
extern "C" void f_802C4950() {}
