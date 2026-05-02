// 0x802FBB70 (88B) ESubModelShader::~ESubModelShader(void)
// Variant L (3-bl, B-ish): Deallocate + 2 TArray::~TArray member dtors at +0x2c & +0x14 + delete branch.

void ESubModelShader_Deallocate(void* obj);
void TArrayDtor(void* obj, int flag);
void __builtin_delete(void* p);

struct TArrayMember {
    char data[1];
};

struct ESubModelShader {
    char pad_00_13[20];
    TArrayMember m_arr_14;
    char pad_15_2b[23];
    TArrayMember m_arr_2c;
    void dtor(int flag);
};

void ESubModelShader::dtor(int flag) {
    ESubModelShader_Deallocate(this);
    TArrayDtor(&m_arr_2c, 2);
    TArrayDtor(&m_arr_14, 2);
    if (flag & 1) {
        __builtin_delete(this);
    }
}
