// 0x80232DF8 ERLevel::ClearJustReadByLevelFlags(void) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addis 3,3,3; li 10,0; lwz 0,-15688(3); cmpw 10,0; bgelr; li 8,0; 0:; addi 9,3,-23880; addi 10,10,1; lwzx 11,9,8; addi 8,8,4; lwz 0,0x5c(11); rlwinm 0,0,0,18,16; stw 0,0x5c(11); lwz 9,-15688(3); cmpw 10,9; blt 0b"

struct ERLevel {
    void ClearJustReadByLevelFlags();
};

void ERLevel::ClearJustReadByLevelFlags() {
}
