/* ObjSelector getter at offset 0xAE - 0x80111310 - 12 bytes */

struct ObjFnData_AE {
    char _pad[0xAE];
    short m_fieldAE;
};

class ObjSelector_AE {
public:
    char _pad[0x38];
    ObjFnData_AE* m_fnData;

    int GetFieldAE(void);
};

int ObjSelector_AE::GetFieldAE(void) {
    return m_fnData->m_fieldAE;
}
