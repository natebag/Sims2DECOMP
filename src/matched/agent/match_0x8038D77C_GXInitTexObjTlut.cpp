struct GXTexObj {
    char _p[0x18];
    unsigned int m_tlut;
};
void GXInitTexObjTlut(GXTexObj *obj, unsigned int tlut);
void GXInitTexObjTlut(GXTexObj *obj, unsigned int tlut) { obj->m_tlut = tlut; }
