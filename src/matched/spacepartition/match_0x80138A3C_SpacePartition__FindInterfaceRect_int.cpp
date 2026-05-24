// 0x80138A3C SpacePartition::FindInterfaceRect(int, (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,3; mr 30,5; mr 31,6; bl _s80138A3C_0; mr 28,3; mr 4,30; mr 3,29; bl _s80138A3C_1; mr 5,3; cmpwi 28,0; beq 0f; cmpwi 5,0; bne 1f; 0:; li 0,0; stw 0,0x8(31); stw 0,0x4(31); stw 0,0x0(31); stw 0,0xc(31); b 2f; 1:; mr 3,29; mr 4,28; mr 6,31; bl _s80138A3C_2; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s80138A3C_0();
extern "C" void _s80138A3C_1();
extern "C" void _s80138A3C_2();

struct SpacePartition {
    void FindInterfaceRect();
};

void SpacePartition::FindInterfaceRect() {
}
