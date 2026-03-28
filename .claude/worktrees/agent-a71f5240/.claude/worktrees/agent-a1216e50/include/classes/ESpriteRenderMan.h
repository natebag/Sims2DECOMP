#ifndef ESPRITERENDERMAN_H
#define ESPRITERENDERMAN_H

#include "types.h"

// ESpriteRenderMan - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 3 known fields (2 named), 18 methods

class ESpriteRenderMan {
public:
    // Constructors / Destructors
    ESpriteRenderMan(void)  // 0x800963D4
    ~ESpriteRenderMan(void);  // 0x80096418

    // Methods
    void Update(void);  // 0x8009647C (132B)
    void RemoveMarkedSprites(void);  // 0x80096500 (268B)
    void DrawIntoOrderTable(void);  // 0x8009660C (124B)
    void DrawDirectly(ERC *);  // 0x80096688 (132B)
    void SetSprite(SpriteSlot *);  // 0x8009670C (204B)
    void AddSprite(cXObject *);  // 0x800967D8 (304B)
    void MarkSprite(cXObject *);  // 0x80096908 (148B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_sprite;  // 0x000 [R] (DrawDirectly, DrawIntoOrderTable, RemoveMarkedSprites, ...)
    u32 m_field_004;  // 0x004 [R] (~ESpriteRenderMan)
    u32 m_sprite_008;  // 0x008 [R/W] (AddSprite, SetSprite, ~ESpriteRenderMan)
};

#endif // ESPRITERENDERMAN_H
