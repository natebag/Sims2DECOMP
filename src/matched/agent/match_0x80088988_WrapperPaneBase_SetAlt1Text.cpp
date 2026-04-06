// 0x80088988 WrapperPaneBase::SetAlt1Text (60b)
void wpb_set_SetAlt1Text(void*, void*);
void wpb_refresh_SetAlt1Text(void*, int);

void WPB_SetAlt1Text(char* self, void* text) {
    wpb_set_SetAlt1Text(*(void**)(self + 72), text);
    wpb_refresh_SetAlt1Text(self, 2);
}
