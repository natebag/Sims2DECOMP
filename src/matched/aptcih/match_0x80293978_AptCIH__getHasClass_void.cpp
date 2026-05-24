// 0x80293978 AptCIH::getHasClass(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x5c(3); rlwinm 3,3,18,31,31"

struct AptCIH {
    void getHasClass();
};

void AptCIH::getHasClass() {
}
