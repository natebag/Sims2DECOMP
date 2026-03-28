/* ESpriteRenderMan::DrawIntoOrderTable(void) at 0x80037048 (68B) */

struct ESpriteRender {
    void DrawIntoOrderTable(void);
};

struct SpriteNode {
    ESpriteRender* m_sprite;
    char pad[0x04];
    SpriteNode* m_next;
};

struct ESpriteRenderMan {
    SpriteNode* m_head;

    void DrawIntoOrderTable(void);
};

void ESpriteRenderMan::DrawIntoOrderTable(void) {
    SpriteNode* node = m_head;
    while (node != 0) {
        node->m_sprite->DrawIntoOrderTable();
        node = node->m_next;
    }
}
