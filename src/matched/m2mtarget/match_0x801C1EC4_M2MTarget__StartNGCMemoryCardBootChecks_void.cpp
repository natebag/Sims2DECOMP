// 0x801C1EC4 M2MTarget::StartNGCMemoryCardBootChecks(void) (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 0,0; li 9,2; li 11,-1; lis 3,-32705; stw 0,0x10c(31); stw 0,0x158(31); addi 3,3,8636; stw 0,0x15c(31); li 4,0; stw 9,0x11c(31); stw 11,0x110(31); bl _s801C1EC4_0; lwz 0,0x118(31); cmpwi 0,0; bne 1f; li 3,360; bl _s801C1EC4_1; mr 30,3; mr 3,31; bl _s801C1EC4_2; mr 5,3; mr 4,31; mr 3,30; li 6,250; bl _s801C1EC4_3; mr. 3,3; li 0,0; beq 0f; addi 0,3,268; 0:; stw 0,0x118(31); 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s801C1EC4_0();
extern "C" void _s801C1EC4_1();
extern "C" void _s801C1EC4_2();
extern "C" void _s801C1EC4_3();

struct M2MTarget {
    void StartNGCMemoryCardBootChecks();
};

void M2MTarget::StartNGCMemoryCardBootChecks() {
}
