// 0x80188724 HUDTarget::IsActionQueueAvailable(int) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; rlwinm 0,30,2,0,29; addi 9,31,236; lwzx 3,9,0; li 29,0; bl _s80188724_0; andi. 0,3,4; bne 1f; mulli 9,30,796; li 11,1; add 9,9,31; lwz 0,0x10c(9); cmpwi 0,0; bne 0f; li 11,0; 0:; cmpwi 11,0; beq 1f; mr 3,31; mr 4,30; bl _s80188724_1; cmpwi 3,0; beq 1f; li 29,1; 1:; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s80188724_0();
extern "C" void _s80188724_1();

struct HUDTarget {
    void IsActionQueueAvailable();
};

void HUDTarget::IsActionQueueAvailable() {
}
