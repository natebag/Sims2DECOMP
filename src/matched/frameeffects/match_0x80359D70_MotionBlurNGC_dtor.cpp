// 0x80359D70 MotionBlurNGC::~MotionBlurNGC (52b)
// FLAGS: -fno-elide-constructors

extern int MotionBlurNGC_VT[];
extern void del_fn(void*);

struct MotionBlurNGC {
    char pad[0x10];
    void* vtable;
};

void d_MotionBlurNGC(MotionBlurNGC* self, int __in_chrg) {
    *(int**)((char*)self + 0x10) = MotionBlurNGC_VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
