// 0x8034FA70 (12 bytes)
// lwz r9, 40(r3); lwz r3, 112(r9); blr
struct ENgcTextureInner {
    char pad[112];
    int m_gxTexFmt;
};
class ENgcTexture {
    char pad[40]; // 0x00-0x27
    ENgcTextureInner* m_inner; // 0x28
public:
    int GetGXTexFmt();
};
int ENgcTexture::GetGXTexFmt() {
    return m_inner->m_gxTexFmt;
}
