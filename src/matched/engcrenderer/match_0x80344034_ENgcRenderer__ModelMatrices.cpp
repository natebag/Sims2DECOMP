// 0x80344034 ENgcRenderer::ModelMatrices (40b)

struct EDLEntry {
    char type;
    unsigned char count;
    unsigned short pad;
    void* data;
};

extern void ModelMatricesImpl(void*, void*, unsigned int);

void ENgcRenderer_ModelMatrices(void* self, EDLEntry* entry) {
    unsigned int count = entry->count;
    void* data = entry->data;
    ModelMatricesImpl(self, data, count);
}
