// 0x80320BCC ERTexture::Attach (52b)

extern void ERTexture_Detach(void*);

struct ERTexture {
    char pad[0x14];
    void* m_texture;
};

void ERTexture_Attach(ERTexture* self, void* tex) {
    ERTexture_Detach(self);
    self->m_texture = tex;
}
