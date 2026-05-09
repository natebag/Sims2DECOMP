// 0x80181678 (40B) UIButtonImages::GetButtonMinSize(int)
// SDA pointer to image table; absolute fallback float at 0x803E3D78.

struct UIButtonImagesData {
    char pad[112];
    float sizes[1];
};

extern UIButtonImagesData* g_uiButtonImages;   // SDA -31492(r13)
extern float kButtonMinSizeDefault[4];          // 0x803E3D78 — [4] forces non-SDA absolute load

class UIButtonImages {
public:
    static float GetButtonMinSize(int idx);
};

float UIButtonImages::GetButtonMinSize(int idx)
{
    UIButtonImagesData* p = g_uiButtonImages;
    if (p == 0) return kButtonMinSizeDefault[0];
    return p->sizes[idx];
}
