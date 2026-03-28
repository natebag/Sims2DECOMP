struct GXTexObj {
    char _p[0x18];
    int m_tlut;
};
int GXGetTexObjTlut(GXTexObj *obj);
int GXGetTexObjTlut(GXTexObj *obj) { return obj->m_tlut; }
