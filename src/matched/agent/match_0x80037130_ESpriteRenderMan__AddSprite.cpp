/* ESpriteRenderMan::AddSprite(cXObject *) at 0x80037130 (96B) */

typedef unsigned int uint;

struct EAHeap {
    void *MallocAligned(uint size, uint align, uint flags, int extra);
};

EAHeap *MainHeap(void);

struct cXObject;

struct ESpriteRender {
    ESpriteRender(void);
    char pad[8];
    cXObject *m_object;
};

struct ENodeList {
    void AddTail(uint node);
};

inline void *operator new(uint, void *p) { return p; }

struct ESpriteRenderMan : public ENodeList {
    ESpriteRender *AddSprite(cXObject *obj);
};

ESpriteRender *ESpriteRenderMan::AddSprite(cXObject *obj) {
    EAHeap *heap = MainHeap();
    void *p = heap->MallocAligned(236, 16, 0, 0);
    ESpriteRender *sprite = new(p) ESpriteRender;
    sprite->m_object = obj;
    AddTail((uint)sprite);
    return sprite;
}
