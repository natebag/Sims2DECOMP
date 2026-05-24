// 0x800B74C4 cSoundPlayer::KillSourceEvent(int) (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 27,0x2c(1); stw 0,0x44(1); mr 30,3; mr 28,4; addi 9,30,24; lis 27,-32692; lwz 11,0x4(9); mr 29,9; lwz 0,0x0(11); stw 0,0x8(1); stw 0,0x10(1); b 4f; 0:; lwz 0,0x4(29); li 9,1; cmpw 11,0; stw 0,0x18(1); bne 1f; li 9,0; 1:; cmpwi 9,0; beq 6f; lwz 9,0x10(1); addi 10,11,8; lwz 0,0x0(9); stw 0,0x10(1); lwz 9,0x8(11); cmpw 9,28; bne 3f; lwz 4,0x4(10); addi 3,27,-14084; bl _s800B74C4_0; lwz 3,0x8(1); stw 3,0x20(1); cmpwi 3,0; lwz 31,0x0(3); lwz 9,0x4(3); stw 31,0x0(9); stw 9,0x4(31); beq 2f; li 4,20; bl _s800B74C4_1; 2:; stw 31,0x18(1); 3:; lwz 0,0x10(1); stw 0,0x8(1); 4:; lwz 11,0x8(1); li 9,1; lwz 0,0x10(30); cmpw 11,0; bne 5f; li 9,0; 5:; cmpwi 9,0; addi 10,30,24; bne 0b; 6:; lwz 0,0x4(10); stw 0,0x10(30); stw 0,0x18(1); lwz 0,0x44(1); mtspr 8,0; lmw 27,0x2c(1); addi 1,1,64"

extern "C" void _s800B74C4_0();
extern "C" void _s800B74C4_1();

struct cSoundPlayer {
    void KillSourceEvent();
};

void cSoundPlayer::KillSourceEvent() {
}
