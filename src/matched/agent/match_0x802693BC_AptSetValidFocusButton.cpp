extern void* g_aptViewer;
extern void AptViewer_SetValidFocusButton(void* viewer);

void AptSetValidFocusButton() {
    AptViewer_SetValidFocusButton(g_aptViewer);
}
