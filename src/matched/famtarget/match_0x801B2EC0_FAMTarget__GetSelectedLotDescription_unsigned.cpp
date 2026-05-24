// 0x801B2EC0 FAMTarget::GetSelectedLotDescription(unsigned (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr 31,4; lwz 4,0x14c(3); bl _s801B2EC0_0; bl _s801B2EC0_1; mr 5,3; lis 4,-32697; addi 4,4,24012; addi 3,1,8; crxor 6,6,6; bl _s801B2EC0_2; lwz 9,0x8(1); li 4,0; cmpwi 9,0; beq 0f; lwz 4,0x0(9); 0:; mr 3,31; bl _s801B2EC0_3; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"

extern "C" void _s801B2EC0_0();
extern "C" void _s801B2EC0_1();
extern "C" void _s801B2EC0_2();
extern "C" void _s801B2EC0_3();

struct FAMTarget {
    void GetSelectedLotDescription();
};

void FAMTarget::GetSelectedLotDescription() {
}
