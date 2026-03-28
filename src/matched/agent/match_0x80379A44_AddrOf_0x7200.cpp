struct Cls_80379A44 {
    char _pad[0x7200];
    int m_field;
    int *GetFieldPtr();
};
int *Cls_80379A44::GetFieldPtr() { return &m_field; }
