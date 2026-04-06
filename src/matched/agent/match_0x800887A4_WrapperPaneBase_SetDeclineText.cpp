// 0x800887A4 WrapperPaneBase::SetDeclineText (60b)
void wpb_set_SetDeclineText(void*, void*);
void wpb_refresh_SetDeclineText(void*, int);

void WPB_SetDeclineText(char* self, void* text) {
    wpb_set_SetDeclineText(*(void**)(self + 68), text);
    wpb_refresh_SetDeclineText(self, 1);
}
