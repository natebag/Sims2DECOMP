extern void* g_aptViewer_hr;
extern void* AptHasRender_func1(void* sub);
extern int AptHasRender_func2(void* result);

int AptHasRenderData() {
    void* r = AptHasRender_func1((char*)g_aptViewer_hr + 0x28);
    return AptHasRender_func2(r);
}
