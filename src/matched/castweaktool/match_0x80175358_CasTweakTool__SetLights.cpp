// 0x80175358 (88B) CasTweakTool::SetLights(ELights &)

struct ELights {
    char data[248];
};

class CasTweakTool {
public:
    ELights m_lights;
    void SetLights(ELights& in);
};

void CasTweakTool::SetLights(ELights& in) {
    m_lights = in;
}
