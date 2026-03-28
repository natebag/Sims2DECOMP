/* ERTexture::Load at 0x80320DF0 (36 bytes) */

void ERTexture_LoadImpl(void* self, unsigned char* data);

void ERTexture_Load(void* self, unsigned char* buf)
{
    ERTexture_LoadImpl(self, buf + 4);
}
