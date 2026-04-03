extern int __vt_ReadCharDataHelper[];

void ReadCharDataFunc(void *);

struct ReadCharDataHelper {
    char pad_00[0x04];
    int* m_vtable;

    void Init(int flag);
};

void ReadCharDataHelper::Init(int flag) {
    m_vtable = __vt_ReadCharDataHelper;
    if (flag & 1) {
        ReadCharDataFunc(this);
    }
}
