// FLAGS: -fno-elide-constructors
// 0x8007ED84 DlgWrapper::SetAlt1Text (60b)
void dlg_refresh_a(void*, int);

void SetAlt1Text_test(char* self, void* text) {
    char* wrapper = *(char**)(self + 172);
    dlg_set_a(*(void**)(wrapper + 72), text);
    dlg_refresh_a(wrapper, 2);
}
