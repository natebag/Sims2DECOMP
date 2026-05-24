// FLAGS: -fno-schedule-insns
// 0x8034FA70 ENgcTexture::GetGXTexFmt(void) (12B)
// lwz r9,0x28(r3); lwz r3,0x70(r9); blr
struct TextureData { char pad[0x70]; int m_gxTexFmt; };
struct ENgcTexture { char pad[0x28]; TextureData* m_data; int GetGXTexFmt() const; };
int ENgcTexture::GetGXTexFmt() const { return m_data->m_gxTexFmt; }
