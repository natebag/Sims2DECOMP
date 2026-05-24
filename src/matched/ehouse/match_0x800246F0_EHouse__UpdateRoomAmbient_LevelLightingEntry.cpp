// 0x800246F0 EHouse::UpdateRoomAmbient(LevelLightingEntry (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 27,3; li 30,1; lwz 0,0x2c(27); mr 29,4; cmpw 30,0; bge 2f; addi 28,29,84; li 26,4; 0:; lwz 9,0x28(27); lwzx 31,26,9; cmpwi 31,0; beq 1f; lwz 3,-21472(13); rlwinm 4,30,0,16,31; bl _s800246F0_0; bl _s800246F0_1; lfs f0,0x60(29); addi 10,31,144; fmuls f0,f0,f1; stfs f0,0x8c(31); lwz 9,0x54(29); lwz 11,0x4(28); lwz 0,0x8(28); stw 9,0x90(31); stw 0,0x8(10); stw 11,0x4(10); 1:; lwz 0,0x2c(27); addi 30,30,1; addi 26,26,4; cmpw 30,0; blt 0b; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"

extern "C" void _s800246F0_0();
extern "C" void _s800246F0_1();

struct EHouse {
    void UpdateRoomAmbient_LevelLightingEntry();
};

void EHouse::UpdateRoomAmbient_LevelLightingEntry() {
}
