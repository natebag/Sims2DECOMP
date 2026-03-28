// 0x80036E70 (8 bytes) — lwz r3, 0x8(r3); blr

class ESpriteRender {
public:
    int _pad0;
    int _pad4;
    void* m_object;  // 0x008

    void* GetObject();
};

void* ESpriteRender::GetObject() {
    return m_object;
}
