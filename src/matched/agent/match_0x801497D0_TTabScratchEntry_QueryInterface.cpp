// 0x801497D0 (112 bytes) — VERIFIED MATCH
// TTabScratchEntry::QueryInterface(unsigned int, void **)

struct QI_TTabScratchEntry {
    int QueryInterface(unsigned int iid, void **output);
};

int QI_TTabScratchEntry::QueryInterface(unsigned int iid, void **output) {
    if (!output) return 0;
    if (iid == 1 || iid == 0x6BF3222B) {
        int *vtable = *(int **)this;
        short delta = *(short *)((char *)vtable + 16);
        void (*func)(void *, unsigned int) = (void (*)(void *, unsigned int))*(void **)(((char *)vtable) + 20);
        func((char *)this + delta, iid);
        *output = this;
        return 1;
    }
    return 0;
}
