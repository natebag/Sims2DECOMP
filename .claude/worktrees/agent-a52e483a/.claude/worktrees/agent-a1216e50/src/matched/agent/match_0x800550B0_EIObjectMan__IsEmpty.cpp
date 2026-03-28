/* 0x800550B0 (16 bytes) - EIObjectMan::IsEmpty(void) */
class EIObjectMan {
public:
    char pad[4];
    int m_field_004;
    int IsEmpty(void);
};

int EIObjectMan::IsEmpty(void) {
    return m_field_004 == 0;
}
