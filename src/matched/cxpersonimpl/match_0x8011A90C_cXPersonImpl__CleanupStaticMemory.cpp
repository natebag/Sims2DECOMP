// cXPersonImpl::CleanupStaticMemory(void) - 0x8011A90C (120B)
// FLAGS: -msdata=eabi -G 8

extern int g_cXPersonStaticInited;

struct PiecewiseFn {
    char pad[20];
    void SetMaxPoints(int n);
};

struct PiecewiseFnGroup {
    PiecewiseFn* data;
    int count;
};

extern char g_cXPersonPfnGroup[];

struct cXPerson_Cleanup {
    void CleanupStaticMemory();
};

void cXPerson_Cleanup::CleanupStaticMemory() {
    if (!g_cXPersonStaticInited)
        return;
    int i = 0;
    PiecewiseFnGroup* arr = (PiecewiseFnGroup*)g_cXPersonPfnGroup;
    if (i < arr->count) {
        int off = 0;
        do {
            PiecewiseFn* fn = (PiecewiseFn*)((char*)arr->data + off);
            i++;
            fn->SetMaxPoints(0);
            off += 20;
        } while (i < arr->count);
    }
    g_cXPersonStaticInited = 0;
}
