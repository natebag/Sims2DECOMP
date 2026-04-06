// 0x800885C0 WrapperPaneBase::SetAcceptText (60b)
void wpb_set_SetAcceptText(void*, void*);
void wpb_refresh_SetAcceptText(void*, int);

void WPB_SetAcceptText(char* self, void* text) {
    wpb_set_SetAcceptText(*(void**)(self + 64), text);
    wpb_refresh_SetAcceptText(self, 0);
}
