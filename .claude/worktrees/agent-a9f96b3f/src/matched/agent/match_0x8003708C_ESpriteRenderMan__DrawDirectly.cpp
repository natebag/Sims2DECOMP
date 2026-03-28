/* ESpriteRenderMan::DrawDirectly(ERC *) at 0x8003708C (76B) */

struct ERC;

struct ESpriteRender {
    void DrawDirectly(ERC *);
};

struct SpriteNode {
    ESpriteRender* m_sprite;
    char pad[0x04];
    SpriteNode* m_next;
};

struct ESpriteRenderMan {
    SpriteNode* m_head;

    void DrawDirectly(ERC *);
};

void ESpriteRenderMan::DrawDirectly(ERC* rc) {
    SpriteNode* node = m_head;
    while (node != 0) {
        node->m_sprite->DrawDirectly(rc);
        node = node->m_next;
    }
}
