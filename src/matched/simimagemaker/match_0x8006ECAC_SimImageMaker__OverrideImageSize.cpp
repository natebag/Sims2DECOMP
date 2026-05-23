/* 0x8006ECAC (16 bytes) - SimImageMaker::OverrideImageSize(unsigned int, unsigned int, unsigned int) */
class SimImageMaker {
public:
    unsigned int m_field_000;
    unsigned int m_field_004;
    unsigned int m_field_008;
    void OverrideImageSize(unsigned int a, unsigned int b, unsigned int c);
};

void SimImageMaker::OverrideImageSize(unsigned int a, unsigned int b, unsigned int c) {
    m_field_000 = a;
    m_field_004 = b;
    m_field_008 = c;
}
