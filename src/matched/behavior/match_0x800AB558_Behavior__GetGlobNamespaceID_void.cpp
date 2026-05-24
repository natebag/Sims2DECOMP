// 0x800AB558 Behavior::GetGlobNamespaceID(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-31848(13)"

struct Behavior {
    void GetGlobNamespaceID();
};

void Behavior::GetGlobNamespaceID() {
}
