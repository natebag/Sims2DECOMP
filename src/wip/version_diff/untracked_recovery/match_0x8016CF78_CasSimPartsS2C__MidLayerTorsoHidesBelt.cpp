// 0x8016CF78 CasSimPartsS2C::MidLayerTorsoHidesBelt (128B)

extern unsigned char g_beltHideTable1[19*6] __attribute__((section(".data")));
extern unsigned char g_beltHideTable2[22*6] __attribute__((section(".data")));

struct Sim {
    enum MidLayerTorsoStyleS2C { kStyleCount = 6 };
};

class CasSimPartsS2C {
    int m_field_8;
public:
    int MidLayerTorsoHidesBelt(unsigned int a, Sim::MidLayerTorsoStyleS2C style, unsigned int c) const;
};

int CasSimPartsS2C::MidLayerTorsoHidesBelt(unsigned int a, Sim::MidLayerTorsoStyleS2C style, unsigned int c) const {
    if (m_field_8 == 0) {
        if (a >= 22) return 0;
        int r = 1;
        if (g_beltHideTable2[a * 6 + style] == 0) r = 0;
        return r;
    }
    if (c == 2) return 0;
    if (a >= 19) return 0;
    int r = 1;
    if (g_beltHideTable1[a * 6 + style] == 0) r = 0;
    return r;
}
