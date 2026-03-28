struct GXTexObj {
    char _p[0x14];
    int m_fmt;
};
int GXGetTexObjFmt(GXTexObj *obj);
int GXGetTexObjFmt(GXTexObj *obj) { return obj->m_fmt; }
