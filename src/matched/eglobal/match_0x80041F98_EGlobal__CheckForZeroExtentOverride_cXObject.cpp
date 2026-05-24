// 0x80041F98 EGlobal::CheckForZeroExtentOverride(cXObject (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0x4(4); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,4,3; blrl; lhz 0,0xb6(3); li 3,1; rlwinm 0,0,0,29,30; cmpwi 0,0; bne 0f; li 3,0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

struct EGlobal {
    void CheckForZeroExtentOverride_cXObject();
};

void EGlobal::CheckForZeroExtentOverride_cXObject() {
}
