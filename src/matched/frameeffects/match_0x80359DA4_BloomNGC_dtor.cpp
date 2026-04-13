// 0x80359DA4 BloomNGC::~BloomNGC (52b)
// FLAGS: -fno-elide-constructors

extern int BloomNGC_VT[];
extern void del_fn(void*);

struct BloomNGC {
    char pad[0x10];
    void* vtable;
};

void d_BloomNGC(BloomNGC* self, int __in_chrg) {
    *(int**)((char*)self + 0x10) = BloomNGC_VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
