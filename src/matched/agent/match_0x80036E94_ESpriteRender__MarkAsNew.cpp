/* ESpriteRender::MarkAsNew(void) - 0x80036E94 (12 bytes) */

struct ESpriteRender {
    int m_field_00;
    int m_markedAsNew;

    void MarkAsNew();
};

void ESpriteRender::MarkAsNew() {
    m_markedAsNew = 1;
}
