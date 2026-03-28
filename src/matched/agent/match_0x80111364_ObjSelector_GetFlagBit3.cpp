/* ObjSelector flag getter bit 3 - 0x80111364 - 16 bytes */

struct ObjFnData_B2c {
    char _pad[0xB2];
    unsigned short m_flags;
};

class ObjSelector_B2c {
public:
    char _pad[0x38];
    ObjFnData_B2c* m_fnData;

    int GetFlagBit3(void);
};

int ObjSelector_B2c::GetFlagBit3(void) {
    return (m_fnData->m_flags >> 3) & 1;
}
