/* ObjSelector flag getter bit 5 - 0x80111384 - 16 bytes */

struct ObjFnData_B2e {
    char _pad[0xB2];
    unsigned short m_flags;
};

class ObjSelector_B2e {
public:
    char _pad[0x38];
    ObjFnData_B2e* m_fnData;

    int GetFlagBit5(void);
};

int ObjSelector_B2e::GetFlagBit5(void) {
    return (m_fnData->m_flags >> 5) & 1;
}
