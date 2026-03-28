// 0x80036E78 (8 bytes) — lwz r3, 0x0(r3); blr

class ESpriteRender {
public:
    int m_marked;  // 0x000

    int GetMarked();
};

int ESpriteRender::GetMarked() {
    return m_marked;
}
