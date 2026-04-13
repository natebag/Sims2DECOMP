// 0x80357754 DepthOfField::~DepthOfField (52b)
// FLAGS: -fno-elide-constructors

extern int DepthOfField_VT[];
extern void del_fn(void*);

struct DepthOfField {
    char pad[0x10];
    void* vtable;
};

void d_DepthOfField(DepthOfField* self, int __in_chrg) {
    *(int**)((char*)self + 0x10) = DepthOfField_VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
