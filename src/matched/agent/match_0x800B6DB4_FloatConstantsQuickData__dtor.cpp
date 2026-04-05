// FLAGS: -fno-elide-constructors
typedef unsigned char u8;
extern int VT_FQD2[];
void del_fqd2(void*);
void d_FloatConstantsQuickData2(u8* self, int __in_chrg) {
    *(int*)(self + 0x0C) = 0;
    *(int**)(self) = VT_FQD2;
    if (__in_chrg & 1) {
        del_fqd2(self);
    }
}
