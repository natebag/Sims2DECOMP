// 0x80232E3C ERLevel::DestroyInstancesWithoutJustReadByLevelFlags(void) (328 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,3; li 30,0; addis 9,28,3; lwz 0,-15688(9); cmpw 30,0; bge 2f; mr 29,9; li 27,0; addi 31,29,-23880; 0:; lwz 11,0x0(31); lwz 0,0x5c(11); rlwinm 0,0,0,17,18; cmpwi 0,8192; bne 1f; lwz 9,0x0(11); lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; stw 27,0x0(31); 1:; lwz 0,-15688(29); addi 30,30,1; addi 31,31,4; cmpw 30,0; blt 0b; 2:; addis 9,28,3; li 3,0; lwz 0,-15688(9); mr 8,9; li 30,0; li 9,0; cmpw 3,0; bge 7f; mr 31,8; li 7,0; addi 10,8,-23880; li 6,-23880; 3:; lwz 0,0x0(10); addi 4,9,1; rlwinm 5,9,2,0,29; cmpwi 0,0; bne 5f; lwz 11,-15688(8); add 9,6,8; 4:; addi 30,30,1; addi 7,7,4; addi 10,10,4; addi 6,6,4; cmpw 30,11; bge 5f; lwzu 0,0x4(9); cmpwi 0,0; beq 4b; 5:; addi 9,31,-23880; lwzx 11,9,5; cmpwi 11,0; bne 6f; lwzx 0,9,7; addi 3,3,1; stwx 0,9,5; stwx 11,9,7; 6:; lwz 0,-15688(8); addi 30,30,1; mr 9,4; addi 7,7,4; cmpw 30,0; addi 10,10,4; addi 6,6,4; blt 3b; 7:; lwz 0,-15688(8); subf 0,3,0; stw 0,-15688(8); lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

struct ERLevel {
    void DestroyInstancesWithoutJustReadByLevelFlags();
};

void ERLevel::DestroyInstancesWithoutJustReadByLevelFlags() {
}
