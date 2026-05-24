// 0x8002E1C4 ERoom::CalAllRoomOpaque(int) (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); lwz 30,0x94(3); mr 26,4; lwz 28,0xa0(3); cmpwi 30,0; beq 4f; rlwinm 27,26,2,0,29; li 25,1; 0:; lwz 9,0x1c(28); lwz 11,0x1c(30); addi 9,9,16; stwx 25,9,27; mr 29,9; lwz 31,0x0(11); b 2f; 1:; lwz 31,0x8(31); 2:; cmpwi 31,0; beq 3f; lwz 3,0x0(31); mr 4,26; lwz 9,0x3c(3); lha 0,0x20(9); lwz 9,0x24(9); add 3,3,0; mtspr 8,9; blrl; mr. 3,3; bne 1b; stwx 3,29,27; 3:; lwz 30,0x10(30); lwz 28,0x10(28); cmpwi 30,0; bne 0b; 4:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"

struct ERoom {
    void CalAllRoomOpaque();
};

void ERoom::CalAllRoomOpaque() {
}
