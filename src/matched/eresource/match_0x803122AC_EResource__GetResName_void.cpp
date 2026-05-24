// 0x803122AC EResource::GetResName(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32702; addi 3,3,1176"

struct EResource {
    void GetResName();
};

void EResource::GetResName() {
}
