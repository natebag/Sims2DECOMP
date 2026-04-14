// 0x801B71B4 UIDialog::SpawnDialog (44b)

extern int g_dialogMgr[];
extern void SpawnDialogImpl(void*, void*);

void UIDialog_SpawnDialog(void* self) {
    void* mgr = *(void**)((char*)g_dialogMgr + 0);
    SpawnDialogImpl(mgr, self);
}
