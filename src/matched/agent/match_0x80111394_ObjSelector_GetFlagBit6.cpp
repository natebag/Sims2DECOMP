/* ObjSelector flag getter bit 6 - 0x80111394 - 16 bytes */

struct ObjFnData_B2f {
    char _pad[0xB2];
    unsigned short m_flags;
};

class ObjSelector_B2f {
public:
    char _pad[0x38];
    ObjFnData_B2f* m_fnData;

    int GetFlagBit6(void);
};

int ObjSelector_B2f::GetFlagBit6(void) {
    return (m_fnData->m_flags >> 6) & 1;
}
