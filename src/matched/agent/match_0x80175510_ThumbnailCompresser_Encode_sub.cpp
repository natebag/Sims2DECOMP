extern int __vt_ThumbEncodeHelper[];

int ThumbEncodeFunc(void *);

struct ThumbEncodeHelper {
    char pad_00[0x04];
    int* m_vtable;

    int EncodeInit();
};

int ThumbEncodeHelper::EncodeInit() {
    m_vtable = __vt_ThumbEncodeHelper;
    return ThumbEncodeFunc(this);
}
