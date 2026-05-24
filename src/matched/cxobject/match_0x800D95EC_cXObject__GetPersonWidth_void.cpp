// 0x800D95EC cXObject::GetPersonWidth(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-31916(13)"

struct cXObject {
    void GetPersonWidth();
};

void cXObject::GetPersonWidth() {
}
