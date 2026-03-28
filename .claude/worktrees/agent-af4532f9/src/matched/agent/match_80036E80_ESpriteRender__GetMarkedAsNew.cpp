// 0x80036E80 (8 bytes) — lwz r3, 0x4(r3); blr

class ESpriteRender {
public:
    int _pad0;
    int m_markedAsNew;  // 0x004

    int GetMarkedAsNew();
};

int ESpriteRender::GetMarkedAsNew() {
    return m_markedAsNew;
}
