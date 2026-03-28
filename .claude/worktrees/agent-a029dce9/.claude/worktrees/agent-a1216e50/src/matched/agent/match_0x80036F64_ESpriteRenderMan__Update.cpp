/* ESpriteRenderMan::Update(void) at 0x80036F64 (80B) */

struct ESpriteRender {
    void Update(void);
};

struct SpriteNode {
    ESpriteRender* m_sprite;
    char pad[0x04];
    SpriteNode* m_next;
};

struct ESpriteRenderMan {
    SpriteNode* m_head;

    void Update(void);
    void RemoveMarkedSprites(void);
};

void ESpriteRenderMan::Update(void) {
    SpriteNode* node = m_head;
    while (node != 0) {
        node->m_sprite->Update();
        node = node->m_next;
    }
    RemoveMarkedSprites();
}
