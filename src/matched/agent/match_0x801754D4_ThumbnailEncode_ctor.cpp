extern int __vt_ThumbEncodeCtor[];

void ThumbEncodeBase(void *);

struct ThumbEncodeCtor {
    char pad_00[0x04];
    int* m_vtable;

    ThumbEncodeCtor();
};

ThumbEncodeCtor::ThumbEncodeCtor() {
    ThumbEncodeBase(this);
    m_vtable = __vt_ThumbEncodeCtor;
}
