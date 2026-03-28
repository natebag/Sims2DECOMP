extern int __vt_ThumbDecodeCtor[];

void ThumbDecodeBase(void *);

struct ThumbDecodeCtor {
    char pad_00[0x04];
    int* m_vtable;

    ThumbDecodeCtor();
};

ThumbDecodeCtor::ThumbDecodeCtor() {
    ThumbDecodeBase(this);
    m_vtable = __vt_ThumbDecodeCtor;
}
