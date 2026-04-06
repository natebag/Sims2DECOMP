// FLAGS: -msdata=eabi -G 8
// 0x8006D35C ESims3DHead::InitShaders (112b)
extern void* s_headShader1;
extern void* s_headShader2;
extern void* EResourceManager_AddRef(void* mgr, unsigned int guid, void* file, int flags);
extern char gModelResourceManager[];

void ESims3DHead_InitShaders() {
    if (s_headShader1 == 0) {
        void* mgr = (void*)gModelResourceManager;
        s_headShader1 = EResourceManager_AddRef(mgr, 0x1A18CA65, 0, 0);
        s_headShader2 = EResourceManager_AddRef(mgr, 0x1239C594, 0, 0);
    }
}
