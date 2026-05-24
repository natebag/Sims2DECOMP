// 0x80233EA4 ERLevel::UnregisterFloorOTDs(EInstance (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); addis 29,3,3; mr 27,4; lwz 0,-23884(29); li 31,0; addic. 9,0,1; ble 1f; li 28,0; 0:; lwz 3,-23928(29); mr 4,27; mr 30,29; addi 31,31,1; add 3,3,28; bl _s80233EA4_0; addi 28,28,4; lwz 9,-23884(30); addi 9,9,1; cmpw 31,9; blt 0b; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s80233EA4_0();

struct ERLevel {
    void UnregisterFloorOTDs_EInstance();
};

void ERLevel::UnregisterFloorOTDs_EInstance() {
}
