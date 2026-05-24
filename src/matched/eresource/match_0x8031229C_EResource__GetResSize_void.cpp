// 0x8031229C EResource::GetResSize(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x10(3); rlwinm 3,3,24,8,31"

struct EResource {
    void GetResSize();
};

void EResource::GetResSize() {
}
