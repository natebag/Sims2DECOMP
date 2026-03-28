
void CBMemberTranslator1_ParentInit(void *, int);

struct CBMemberTranslator1_Thunk {
    char _pad_000[0x28];
    int m_field_028;
    int m_field_02C;
    int m_field_030;
    int m_field_034;

    CBMemberTranslator1_Thunk(void);
};

CBMemberTranslator1_Thunk::CBMemberTranslator1_Thunk(void) {
    CBMemberTranslator1_ParentInit(this, 0);
    m_field_028 = 0;
    m_field_02C = 0;
    m_field_030 = 0;
    m_field_034 = 0;
}
