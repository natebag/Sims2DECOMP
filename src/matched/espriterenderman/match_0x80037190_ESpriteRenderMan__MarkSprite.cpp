// ESpriteRenderMan::MarkSprite(cXObject *) at 0x80037190 (52 bytes)
// Linked-list walk: marks sprites whose m_obj matches the arg.

class cXObject;

struct SpriteData {
    int m_marked;
    char _pad[4];
    cXObject* m_obj;
};

struct SpriteNode {
    SpriteData* m_data;
    char _pad[4];
    SpriteNode* m_next;
};

struct ESpriteRenderMan_MS {
    SpriteNode* m_head;

    void MarkSprite(cXObject* obj);
};

void ESpriteRenderMan_MS::MarkSprite(cXObject* obj) {
    SpriteNode* node = m_head;
    while (node) {
        SpriteData* data = node->m_data;
        if (data->m_obj == obj) {
            data->m_marked = 1;
        }
        node = node->m_next;
    }
}
