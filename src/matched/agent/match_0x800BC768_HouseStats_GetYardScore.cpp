// 0x800BC768 HouseStats::GetYardScore(void) (80B)
// NaN-coax sibling: clamp(field2c * scale, 0, 100) → int.

struct YardSrc {
    char pad[0x2c];
    float m_field2c;  // 0x2c
};

extern YardSrc* g_yardSrc;       // SDA
extern float g_yardScoreScale;   // SDA

class HouseStats {
public:
    int GetYardScore();
};

int HouseStats::GetYardScore() {
    YardSrc* src = g_yardSrc;
    float scale = g_yardScoreScale;
    float val = src->m_field2c * scale;
    if (val < 0.0f) val = 0.0f;
    if (val > 100.0f) val = 100.0f;
    return (int)val;
}
