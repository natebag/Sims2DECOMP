struct GXData {
    char _p[0x50];
    int m_overflowCount;
};
extern GXData *__GXData;
void GXResetOverflowCount();
