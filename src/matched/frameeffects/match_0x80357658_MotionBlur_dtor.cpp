// PRAGMA_STUB: MotionBlur::~MotionBlur(void)
// 0x80357658 MotionBlur::~MotionBlur (52b)
// FLAGS: -fno-elide-constructors

extern int MotionBlur_VT[];
extern void del_fn(void*);

struct MotionBlur {
    char pad[0x10];
    void* vtable;
};

void d_MotionBlur(MotionBlur* self, int __in_chrg) {
    *(int**)((char*)self + 0x10) = MotionBlur_VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
