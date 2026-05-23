/* ERTexture::Destruct at 0x80321244 (36 bytes) */

void ERTexture_dtor(void* self, int mode);

void ERTexture_Destruct(void* self)
{
    ERTexture_dtor(self, 2);
}
