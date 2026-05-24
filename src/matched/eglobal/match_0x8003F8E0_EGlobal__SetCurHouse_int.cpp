// 0x8003F8E0 EGlobal::SetCurHouse(int) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; mr 31,4; lwz 3,0xc8(30); cmpwi 3,0; beq 0f; li 4,3; bl _s8003F8E0_0; 0:; li 3,296; bl _s8003F8E0_1; lis 9,-32697; addi 11,1,8; addi 9,9,24012; mr 4,11; lfs f0,0xa4(9); mr 5,31; lfs f13,0xa8(9); li 6,0; stfs f0,0x8(1); li 7,1; stfs f13,0x4(11); li 8,1; li 9,1; li 10,0; bl _s8003F8E0_2; stw 3,0xc8(30); lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"

extern "C" void _s8003F8E0_0();
extern "C" void _s8003F8E0_1();
extern "C" void _s8003F8E0_2();

struct EGlobal {
    void SetCurHouse();
};

void EGlobal::SetCurHouse() {
}
