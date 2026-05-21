// 0x80175300 (88B) CasTweakTool::GetLights(ELights &)

struct ELights {
    char data[248];
};

class CasTweakTool {
public:
    ELights m_lights;
    void GetLights(ELights& out);
};

void CasTweakTool::GetLights(ELights& out) {
    out = m_lights;
}
