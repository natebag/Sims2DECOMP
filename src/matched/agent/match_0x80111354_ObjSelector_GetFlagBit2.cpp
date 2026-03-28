/* ObjSelector flag getter bit 2 - 0x80111354 - 16 bytes */

struct ObjFnData_B2b {
    char _pad[0xB2];
    unsigned short m_flags;
};

class ObjSelector_B2b {
public:
    char _pad[0x38];
    ObjFnData_B2b* m_fnData;

    int GetFlagBit2(void);
};

int ObjSelector_B2b::GetFlagBit2(void) {
    return (m_fnData->m_flags >> 2) & 1;
}
