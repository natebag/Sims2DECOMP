// ERTQuantize4D::GetPaletteEntry(int, unsigned char *) - 0x8035FF50 (44B)
// Wrapper: TransformFromYUVA(m_palette[idx], out).

struct EVec4 {
    float x, y, z, w;
};

class ERTQuantize4D {
public:
    char _pad[0x1060];
    EVec4 m_palette[1];           // +0x1060
    void GetPaletteEntry(int idx, unsigned char* out);
    void TransformFromYUVA(EVec4& v, unsigned char* out);
};

void ERTQuantize4D::GetPaletteEntry(int idx, unsigned char* out)
{
    TransformFromYUVA(m_palette[idx], out);
}
