typedef unsigned char u8;

struct PropEntry {
    int m_propId;
    int m_flag;
    void* m_resource;
};

struct SAnimator2 {
    char pad[0x168];
    PropEntry** m_props;
    PropEntry** m_propsEnd;
};

int SAnimator2_PropsHaveAlpha(SAnimator2* self) {
    int result = 0;
    PropEntry** begin = self->m_props;
    PropEntry** end = self->m_propsEnd;
    int count = ((int)end - (int)begin) >> 2;
    
    for (int i = 0; i < count; i++) {
        PropEntry* entry = begin[i];
        void* res = entry->m_resource;
        if (res) {
            int hasAlpha = *(int*)((char*)res + 0x100) != 0;
            result = result | hasAlpha;
        }
    }
    return result;
}
