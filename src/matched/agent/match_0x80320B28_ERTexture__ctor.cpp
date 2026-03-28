/* ERTexture::ERTexture at 0x80320B28 (68 bytes) */

extern int ERTexture_vtable[];

void EResourceInit(void*);

struct ERTexture {
    int* _vtable;
    char _pad_04[0x10];
    int m_field_14;

    ERTexture();
};

ERTexture::ERTexture()
{
    EResourceInit(this);
    m_field_14 = 0;
    _vtable = ERTexture_vtable;
}
