// FLAGS: -msdata=eabi -G 8
// 0x8034F43C ENgcTexture::ENgcTexture (68b)
extern void ETextureImpl_ctor(void*);
extern int ENgcTexture_VTable[];

struct ENgcTexture {
    char pad[36];
    int* vtable_36;
    int field_40;
};

ENgcTexture* ENgcTexture_ctor(ENgcTexture* self) {
    ETextureImpl_ctor(self);
    self->field_40 = 0;
    self->vtable_36 = ENgcTexture_VTable;
    return self;
}
