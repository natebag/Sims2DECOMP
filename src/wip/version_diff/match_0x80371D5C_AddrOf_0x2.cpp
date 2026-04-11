struct Cls_80371D5C {
    char _pad[0x2];
    int m_field;
    int *GetFieldPtr();
};
int *Cls_80371D5C::GetFieldPtr() { return &m_field; }
