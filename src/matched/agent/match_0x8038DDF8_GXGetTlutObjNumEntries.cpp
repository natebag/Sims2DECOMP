struct GXTlutObj {
    char _p[0x08];
    unsigned short m_numEntries;
};
unsigned short GXGetTlutObjNumEntries(GXTlutObj *obj);
unsigned short GXGetTlutObjNumEntries(GXTlutObj *obj) { return obj->m_numEntries; }
