// 0x803489A8 ENgcRenderer::ReadMetrics (40b)

extern void FlushMetrics(void);
extern char g_metricsReady[4];

void ENgcRenderer_ReadMetrics(void*, void*) {
    FlushMetrics();
    *(int*)g_metricsReady = 1;
}
