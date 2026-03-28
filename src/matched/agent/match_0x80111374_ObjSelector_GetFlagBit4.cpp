/* ObjSelector flag getter bit 4 - 0x80111374 - 16 bytes */

struct ObjFnData_B2d {
    char _pad[0xB2];
    unsigned short m_flags;
};

class ObjSelector_B2d {
public:
    char _pad[0x38];
    ObjFnData_B2d* m_fnData;

    int GetFlagBit4(void);
};

int ObjSelector_B2d::GetFlagBit4(void) {
    return (m_fnData->m_flags >> 4) & 1;
}
