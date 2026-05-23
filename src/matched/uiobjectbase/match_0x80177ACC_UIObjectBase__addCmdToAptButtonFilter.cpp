typedef unsigned char u8;
extern u8* g_uiMgr[4];
void addFilterCmd(u8*, u8*, int, unsigned int);
void UIObjectBase_addCmdToAptButtonFilter(u8* self, int cmd, unsigned int ctrl) {
    addFilterCmd((u8*)g_uiMgr[0], self, cmd, ctrl);
}
