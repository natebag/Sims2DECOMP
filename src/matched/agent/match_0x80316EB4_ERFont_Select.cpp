// 0x80316EB4 ERFont::Select (52b)

extern void ERFont_Select_sub(void*, void*);

struct ERFont {
    char pad[0x68];
    int m_selected;
};

void ERFont_Select(ERFont* self, void* erc) {
    ERFont_Select_sub(self, erc);
    self->m_selected = -1;
}
