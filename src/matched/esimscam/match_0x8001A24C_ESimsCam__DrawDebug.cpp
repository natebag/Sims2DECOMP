// 0x8001A24C (108B) ESimsCam::DrawDebug(ERC*)

class ERC;

struct Quad {
    char pad[48];
    void Draw(ERC* erc, unsigned int color) const;
};

struct CamDebugCfg {
    char m_pad0[120];
    int m_78_drawAxes;
    char m_pad120[164 - 124];
    int m_A4_drawCenter;
};

extern char g_camDebugCfg_0x80473514[16];

class ESimsCam {
public:
    char m_pad0[864];
    Quad m_360;
    Quad m_390;
    void DrawDebug(ERC* erc);
};

void ESimsCam::DrawDebug(ERC* erc) {
    CamDebugCfg* cfg = (CamDebugCfg*)g_camDebugCfg_0x80473514;
    if (cfg->m_78_drawAxes != 0) {
        m_360.Draw(erc, 0x40800000);
    }
    if (cfg->m_A4_drawCenter != 0) {
        m_390.Draw(erc, 0x40000080);
    }
}
