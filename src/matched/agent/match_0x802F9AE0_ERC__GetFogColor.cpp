// FLAGS: -fno-elide-constructors
// ERC::GetFogColor(void) - 0x802F9AE0 (44B)
// Returns 16-byte EColorRGBA at offset 0x5c. NRV + intermediate ptr forces addi-base.

struct EColorRGBA {
    float r;
    float g;
    float b;
    float a;
};

class ERC {
public:
    char _pad[0x5c];
    EColorRGBA m_fogColor;
    EColorRGBA GetFogColor();
};

EColorRGBA ERC::GetFogColor() return c
{
    c.r = m_fogColor.r;
    const EColorRGBA* p = &m_fogColor;
    c.g = p->g;
    c.b = p->b;
    c.a = p->a;
}
