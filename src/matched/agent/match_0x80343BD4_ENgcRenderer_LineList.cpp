// 0x80343BD4 ENgcRenderer::LineList (40b)

struct EDLEntry2 {
    short pad;
    unsigned short count;
    void* data;
};

extern void LineListImpl(void*, void*, unsigned int);

void ENgcRenderer_LineList(void* self, EDLEntry2* entry) {
    unsigned int count = entry->count;
    void* data = entry->data;
    LineListImpl(self, data, count);
}
