// 0x80035440 ESimScratchPadMan::InitHeap (28B)

extern char g_scratchHeapStart[];
extern char g_scratchHeapEnd[];
extern int g_heapStartPtr;
extern int g_heapEndPtr;

void ESimScratchPadMan_InitHeap() {
    g_heapStartPtr = (int)g_scratchHeapStart;
    g_heapEndPtr = (int)g_scratchHeapEnd;
}
