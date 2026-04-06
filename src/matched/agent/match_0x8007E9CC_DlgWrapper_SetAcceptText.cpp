// FLAGS: -fno-elide-constructors
// 0x8007E9CC DlgWrapper::SetAcceptText (60b)
void dlg_refresh(void*, int);

void SetAcceptText_test(char* self, void* text) {
    char* wrapper = *(char**)(self + 172);
    dlg_set_text(*(void**)(wrapper + 64), text);
    dlg_refresh(wrapper, 0);
}
