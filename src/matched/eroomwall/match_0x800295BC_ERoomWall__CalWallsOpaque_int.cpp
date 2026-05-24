// 0x800295BC ERoomWall::CalWallsOpaque(int) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 31,0x14(3); cmpwi 31,0; bne 0f; addi 9,3,44; rlwinm 0,4,2,0,29; stwx 31,9,0; li 3,0; b 4f; 0:; rlwinm 0,4,2,0,29; addi 9,3,44; li 11,1; stwx 11,9,0; mr 29,0; mr 30,9; b 2f; 1:; lwz 31,0x8(31); 2:; cmpwi 31,0; beq 3f; lwz 3,0x0(31); lwz 9,0x0(3); lha 0,0x168(9); lwz 9,0x16c(9); add 3,3,0; mtspr 8,9; blrl; mr. 3,3; bne 1b; stwx 3,30,29; 3:; lwzx 3,30,29; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

struct ERoomWall {
    void CalWallsOpaque();
};

void ERoomWall::CalWallsOpaque() {
}
