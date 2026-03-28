struct GXTexObj {
    char _p[0x10];
    void *m_userData;
};
void GXInitTexObjUserData(GXTexObj *obj, void *data);
void GXInitTexObjUserData(GXTexObj *obj, void *data) { obj->m_userData = data; }
