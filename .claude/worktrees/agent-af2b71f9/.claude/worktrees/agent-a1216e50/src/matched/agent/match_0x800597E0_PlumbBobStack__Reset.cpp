/* 0x800597E0 (12 bytes) - PlumbBobStack::Reset(void) */
class PlumbBobStack {
public:
    int m_field_000;
    void Reset(void);
};

void PlumbBobStack::Reset(void) {
    m_field_000 = 0;
}
