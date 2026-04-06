// FLAGS: -msdata=eabi -G 8
// 0x803008A0 EWindow::SetInputCoordinatesAndClip (60b)
extern void SetInputCoordinates(void*, void*);
extern void SetClip(void*, void*);

void SetInputCoordinatesAndClip(void* self, void* rect) {
    SetInputCoordinates(self, rect);
    SetClip(self, rect);
}
