// 0x8015A070 (112 bytes) — VERIFIED MATCH
// QuickDataBehaviorConstants::QueryInterface(unsigned int, void **)

struct QI_QuickDataBehaviorConstants {
    int QueryInterface(unsigned int iid, void **output);
};

int QI_QuickDataBehaviorConstants::QueryInterface(unsigned int iid, void **output) {
    if (!output) return 0;
    if (iid == 1 || iid == 0xEBD8CAB4) {
        int *vtable = *(int **)this;
        short delta = *(short *)((char *)vtable + 16);
        void (*func)(void *, unsigned int) = (void (*)(void *, unsigned int))*(void **)(((char *)vtable) + 20);
        func((char *)this + delta, iid);
        *output = this;
        return 1;
    }
    return 0;
}
