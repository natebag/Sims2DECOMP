// 0x800D95F4 cXObject::GetFreeWill(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-31912(13)"

struct cXObject {
    void GetFreeWill();
};

void cXObject::GetFreeWill() {
}
