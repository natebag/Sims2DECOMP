/* ObjSelector getter at offset 0xAA - 0x801112F8 - 12 bytes */

struct ObjFnData_AA {
    char _pad[0xAA];
    short m_fieldAA;
};

class ObjSelector_AA {
public:
    char _pad[0x38];
    ObjFnData_AA* m_fnData;

    int GetFieldAA(void);
};

int ObjSelector_AA::GetFieldAA(void) {
    return m_fnData->m_fieldAA;
}
