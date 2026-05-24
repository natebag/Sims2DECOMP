// 0x802C89D8 FAMTarget::GetNumberOfFamilyMembers(Family (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 5,0xc(3); li 4,0; lwz 3,0x8(3); rlwinm 5,5,2,0,29; bl _s802C89D8_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s802C89D8_0();

struct FAMTarget {
    void GetNumberOfFamilyMembers_Family();
};

void FAMTarget::GetNumberOfFamilyMembers_Family() {
}
