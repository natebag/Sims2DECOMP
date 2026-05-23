// 0x801AFCAC FAMTarget::UnloadScreen(void) (44B)
struct FAMTarget;
struct Screen;

extern char g_screenHolder[64];  // non-SDA (0x80475F10 area)
extern void UnloadScreenFn(Screen* s, int id);

void FAMTarget__UnloadScreen(FAMTarget* self) {
    Screen* s = *(Screen**)g_screenHolder;
    UnloadScreenFn(s, 68);
}
