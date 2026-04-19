// 0x803135AC (20B) FlashBigFile::ctor — 8B zero-init POD
// volatile pointer forces mr r9,r3 save + stw order.

class FlashBigFile {
public:
    int m_field_0;
    int m_field_4;
    FlashBigFile(void);
};

FlashBigFile::FlashBigFile(void) {
    volatile int* p = (volatile int*)this;
    p[1] = 0;
    p[0] = 0;
}
