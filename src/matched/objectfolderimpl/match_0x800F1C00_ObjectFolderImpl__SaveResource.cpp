typedef unsigned char u8;

int ObjectFolderImpl_SaveResource(u8* self, int id, int type, u8* strBuf, u8* dataIface) {
    if (id == -1) return 0;
    u8* vt = *(u8**)dataIface;
    short adj = *(short*)(vt + 0x40);
    int (*func)(u8*, int, int, u8*) = *(int (**)(u8*, int, int, u8*))(vt + 0x44);
    return func(dataIface + adj, id, type, strBuf);
}
