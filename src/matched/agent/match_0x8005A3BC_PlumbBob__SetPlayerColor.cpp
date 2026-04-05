struct PlumbBob;
extern char gPlayerColorArray[];
extern void SetPlayerColor_impl(PlumbBob* self, void* colorData);

void PlumbBob__SetPlayerColor(PlumbBob* self, int colorIndex) {
    SetPlayerColor_impl(self, gPlayerColorArray + colorIndex * 12);
}
