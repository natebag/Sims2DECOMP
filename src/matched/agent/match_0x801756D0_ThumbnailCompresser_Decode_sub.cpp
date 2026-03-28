extern int __vt_ThumbDecodeHelper[];

int ThumbDecodeFunc(void *);

struct ThumbDecodeHelper {
    char pad_00[0x04];
    int* m_vtable;

    int DecodeInit();
};

int ThumbDecodeHelper::DecodeInit() {
    m_vtable = __vt_ThumbDecodeHelper;
    return ThumbDecodeFunc(this);
}
