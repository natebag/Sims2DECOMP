/* 0x803135AC (20 bytes) - FlashBigFile::FlashBigFile(void) */
class FlashBigFile {
public:
    int m_f0, m_f4;
    FlashBigFile();
};
FlashBigFile::FlashBigFile() { m_f4 = 0; m_f0 = 0; }
