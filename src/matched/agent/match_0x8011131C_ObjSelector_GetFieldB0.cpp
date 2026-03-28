/* ObjSelector getter at offset 0xB0 - 0x8011131C - 12 bytes */

struct ObjFnData_B0 {
    char _pad[0xB0];
    short m_fieldB0;
};

class ObjSelector_B0 {
public:
    char _pad[0x38];
    ObjFnData_B0* m_fnData;

    int GetFieldB0(void);
};

int ObjSelector_B0::GetFieldB0(void) {
    return m_fnData->m_fieldB0;
}
