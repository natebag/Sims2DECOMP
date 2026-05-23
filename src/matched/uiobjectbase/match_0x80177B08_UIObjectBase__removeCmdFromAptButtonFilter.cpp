typedef unsigned char u8;
extern u8* g_uiMgr2[4];
void removeFilterCmd(u8*, u8*, int, unsigned int);
void UIObjectBase_removeCmdFromAptButtonFilter(u8* self, int cmd, unsigned int ctrl) {
    removeFilterCmd((u8*)g_uiMgr2[0], self, cmd, ctrl);
}
