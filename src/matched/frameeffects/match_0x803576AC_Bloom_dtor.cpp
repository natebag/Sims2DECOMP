// 0x803576AC Bloom::~Bloom (52b)
// FLAGS: -fno-elide-constructors

extern int Bloom_VT[];
extern void del_fn(void*);

struct Bloom {
    char pad[0x10];
    void* vtable;
};

void d_Bloom(Bloom* self, int __in_chrg) {
    *(int**)((char*)self + 0x10) = Bloom_VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
