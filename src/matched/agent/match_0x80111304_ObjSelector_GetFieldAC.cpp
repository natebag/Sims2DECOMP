/* ObjSelector getter at offset 0xAC - 0x80111304 - 12 bytes */

struct ObjFnData_AC {
    char _pad[0xAC];
    short m_fieldAC;
};

class ObjSelector_AC {
public:
    char _pad[0x38];
    ObjFnData_AC* m_fnData;

    int GetFieldAC(void);
};

int ObjSelector_AC::GetFieldAC(void) {
    return m_fnData->m_fieldAC;
}
