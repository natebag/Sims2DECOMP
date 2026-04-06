// 0x80010038 CreateAptViewer (64b)

extern void* GetHeap(void);
extern void* AllocFromHeap(void*, int, int, int, int);
extern void* InitAptViewer(void*);
extern char g_aptViewer[4];

void* CreateAptViewer() {
    void* heap = GetHeap();
    void* viewer = AllocFromHeap(heap, 1128, 16, 0, 0);
    viewer = InitAptViewer(viewer);
    *(void**)g_aptViewer = viewer;
    return viewer;
}
