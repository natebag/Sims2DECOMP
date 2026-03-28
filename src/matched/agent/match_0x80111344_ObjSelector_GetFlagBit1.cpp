/* ObjSelector flag getter bit 1 - 0x80111344 - 16 bytes */
/* lwz r9, 56(r3); lhz r3, 0xB2(r9); rlwinm r3, r3, 31, 31, 31; blr */
/* Returns (flags >> 1) & 1 */

struct ObjFnData_B2a {
    char _pad[0xB2];
    unsigned short m_flags;
};

class ObjSelector_B2a {
public:
    char _pad[0x38];
    ObjFnData_B2a* m_fnData;

    int GetFlagBit1(void);
};

int ObjSelector_B2a::GetFlagBit1(void) {
    return (m_fnData->m_flags >> 1) & 1;
}
