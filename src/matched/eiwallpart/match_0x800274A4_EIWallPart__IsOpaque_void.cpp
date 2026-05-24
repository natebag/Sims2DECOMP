// 0x800274A4 EIWallPart::IsOpaque(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s800274A4_0; lis 9,-32707; lfs f0,0xce0(9); fcmpu 0,f1,f0; blt 0f; bl _s800274A4_1; addi 31,31,812; rlwinm 3,3,2,0,29; lwzx 0,31,3; cmpwi 0,31; beq 0f; bl _s800274A4_2; rlwinm 3,3,2,0,29; lwzx 0,31,3; cmpwi 0,21; bne 1f; 0:; li 3,0; b 2f; 1:; li 3,1; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s800274A4_0();
extern "C" void _s800274A4_1();
extern "C" void _s800274A4_2();

struct EIWallPart {
    void IsOpaque();
};

void EIWallPart::IsOpaque() {
}
