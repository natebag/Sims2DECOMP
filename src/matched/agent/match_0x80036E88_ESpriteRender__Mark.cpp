/* ESpriteRender::Mark(void) - 0x80036E88 (12 bytes) */

struct ESpriteRender {
    int m_marked;

    void Mark();
};

void ESpriteRender::Mark() {
    m_marked = 1;
}
