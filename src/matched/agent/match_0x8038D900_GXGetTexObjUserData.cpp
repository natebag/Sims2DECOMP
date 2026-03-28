struct GXTexObj {
    char _p[0x10];
    void *m_userData;
};
void *GXGetTexObjUserData(GXTexObj *obj);
void *GXGetTexObjUserData(GXTexObj *obj) { return obj->m_userData; }
