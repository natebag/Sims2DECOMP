class CasSimRendererDynamic {
public:
    void PlayPersonalityAnim(short);
};

class SomeTargetData {
public:
    char _pad[0x14];
    CasSimRendererDynamic* m_renderer;
};

class CASPersonalTarget {
public:
    char _pad[0x84];
    SomeTargetData* m_data;

    void HandlePersonalityAnimation(char *name);
    short ConvertFromPersonalityTextToEnum(char *name);
};

void CASPersonalTarget::HandlePersonalityAnimation(char *name) {
    CasSimRendererDynamic* renderer = m_data->m_renderer;
    if (renderer != 0) {
        short animEnum = ConvertFromPersonalityTextToEnum(name);
        renderer->PlayPersonalityAnim(animEnum);
    }
}
