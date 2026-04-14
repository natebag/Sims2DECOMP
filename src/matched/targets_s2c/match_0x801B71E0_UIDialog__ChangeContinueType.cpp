// 0x801B71E0 UIDialog::ChangeContinueType (40b)

extern int g_dialogPtr[];

extern void ChangeContinueTypeImpl(void*);

void UIDialog_ChangeContinueType(void* self, int type) {
    void* ptr = *(void**)((char*)g_dialogPtr + 0);
    ChangeContinueTypeImpl(ptr);
}
