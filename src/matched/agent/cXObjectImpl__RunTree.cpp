// FLAGS: -fno-elide-constructors
// 0x80109EC4 (144 bytes) — VERIFIED MATCH
// cXObjectImpl::RunTree(Behavior *, short, char *, short *)
// Runs a behavior tree. First resolves the behavior via virtual dispatch,
// then if successful, dispatches the run through the object's interface chain.

typedef void (*vfn_t)();

struct RT {
    void *RunTree(void *bhvr, short param2, char *param3, short *param4);
};

void *RT::RunTree(void *bhvr, short param2, char *param3, short *param4) {
    char *vt = *(char **)bhvr;
    short adj = *(short *)(vt + 72);
    void *(*fn)(void *, char *) = (void *(*)(void *, char *))*(void **)(vt + 76);
    void *result = fn((char *)bhvr + adj, param3);

    if (result != 0) {
        char *selfPtr = *(char **)this;
        char *inner = *(char **)selfPtr;
        char *vt2 = *(char **)(inner + 24);
        short adj2 = *(short *)(vt2 + 160);
        void *(*fn2)(void *, void *, short, void *, short *) = (void *(*)(void *, void *, short, void *, short *))*(void **)(vt2 + 164);
        return fn2(inner + adj2, bhvr, param2, result, param4);
    }
    return 0;
}
