typedef unsigned char u8;

extern char g_rumbleStr[16];
u8* findCategory(u8*, char*);
u8* findByName(u8*, u8*, char*);

u8* ObjectFolderImpl_GetRumbleByName(u8* self, char* name) {
    u8* cat = findCategory(*(u8**)(self + 0x690), g_rumbleStr);
    u8* result = findByName(*(u8**)(self + 0x690), cat, name);
    if (result == 0) return 0;
    return result;
}
