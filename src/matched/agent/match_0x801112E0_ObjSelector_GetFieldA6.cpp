/* ObjSelector getter at offset 0xA6 - 0x801112E0 - 12 bytes */
/* lwz r9, 56(r3); lha r3, 0xA6(r9); blr */

struct ObjFnData_A6 {
    char _pad[0xA6];
    short m_fieldA6;
};

class ObjSelector_A6 {
public:
    char _pad[0x38];
    ObjFnData_A6* m_fnData;

    int GetFieldA6(void);
};

int ObjSelector_A6::GetFieldA6(void) {
    return m_fnData->m_fieldA6;
}
