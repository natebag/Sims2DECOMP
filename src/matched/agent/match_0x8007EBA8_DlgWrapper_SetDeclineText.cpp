// FLAGS: -fno-elide-constructors
// 0x8007EBA8 DlgWrapper::SetDeclineText (60b)
void dlg_refresh_d(void*, int);

void SetDeclineText_test(char* self, void* text) {
    char* wrapper = *(char**)(self + 172);
    dlg_set_d(*(void**)(wrapper + 68), text);
    dlg_refresh_d(wrapper, 1);
}
