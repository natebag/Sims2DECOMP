// 0x80359DD8 DepthOfFieldNGC::~DepthOfFieldNGC (52b)
// FLAGS: -fno-elide-constructors

extern int DepthOfFieldNGC_VT[];
extern void del_fn(void*);

struct DepthOfFieldNGC {
    char pad[0x10];
    void* vtable;
};

void d_DepthOfFieldNGC(DepthOfFieldNGC* self, int __in_chrg) {
    *(int**)((char*)self + 0x10) = DepthOfFieldNGC_VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
