/* RepTitleSupport::GetRepTitleLevel(int) at 0x8019011C (56B) */
// FLAGS: -fno-elide-constructors

extern int getRepLevelInner(void *, int, int, ...);

void *RepTitle_GetRepTitleLevel(void *self, int param) {
    getRepLevelInner(self, param, 3);
    return self;
}
