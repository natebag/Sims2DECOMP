/* ObjSelector getter at offset 0xA8 - 0x801112EC - 12 bytes */

struct ObjFnData_A8 {
    char _pad[0xA8];
    short m_fieldA8;
};

class ObjSelector_A8 {
public:
    char _pad[0x38];
    ObjFnData_A8* m_fnData;

    int GetFieldA8(void);
};

int ObjSelector_A8::GetFieldA8(void) {
    return m_fnData->m_fieldA8;
}
