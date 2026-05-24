// 0x802939A4 AptCIH::getASChanged(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x5c(3); rlwinm 3,3,17,31,31"

struct AptCIH {
    void getASChanged();
};

void AptCIH::getASChanged() {
}
