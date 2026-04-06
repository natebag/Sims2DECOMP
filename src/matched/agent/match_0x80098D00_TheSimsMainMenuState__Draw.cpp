extern void* gMainMenuRenderer;
extern "C" void drawRenderer(void*, void*);
void TheSimsMainMenuState_Draw(void* self, void* erc) {
    if (gMainMenuRenderer) { drawRenderer(gMainMenuRenderer, erc); }
}
