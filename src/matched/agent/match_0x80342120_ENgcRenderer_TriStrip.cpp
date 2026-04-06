// 0x80342120 ENgcRenderer::TriStrip (40b)

struct EDLEntry {
    short pad;
    unsigned short count;
    void* data;
};

extern void TriStripImpl(void*, void*, unsigned int);

void ENgcRenderer_TriStrip(void* self, EDLEntry* entry) {
    unsigned int count = entry->count;
    void* data = entry->data;
    TriStripImpl(self, data, count);
}
