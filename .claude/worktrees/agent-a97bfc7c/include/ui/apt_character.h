#ifndef APT_CHARACTER_H
#define APT_CHARACTER_H

#include "types.h"
#include "ui/apt_value.h"

// Forward declarations
class AptRenderingContext;
class AptCIH;
class AptDisplayList;
class AptNativeHash;
class AptControl;
struct AptMatrix;
struct AptRect;
struct TextFormat;

// AptMaskRenderOperation - rendering mask mode
typedef int AptMaskRenderOperation;

// ============================================================================
// AptCharacter - base class for APT display characters (sprites, text, shapes)
// ============================================================================
class AptCharacter {
public:
    void render(AptRenderingContext* ctx, AptMaskRenderOperation op, AptMatrix* matrix);
    void _getBoundingRect(AptRenderingContext* ctx, AptRect* rect, AptMatrix* matrix);
};

// ============================================================================
// AptCharacterInst - instantiated character with ActionScript members
// Layout (partial, from disassembly):
//   0x0C: AptValue* m_nativeHash (pointer to native hash or null)
//   0x10: u32 m_gcFlag (set to 1 when GC pointers destroyed)
// ============================================================================
class AptCharacterInst : public AptValue {
public:
    void PreDestroy();
    ~AptCharacterInst();
    void DestroyGCPointers();

    // ActionScript methods (static dispatchers)
    static AptValue* sMethod_gotoAndStop(AptValue* thisObj, int argc);
    static AptValue* sMethod_gotoAndPlay(AptValue* thisObj, int argc);
    AptValue* _gotoAndX(AptValue* thisObj, int argc, int playFlag);
    static AptValue* sMethod_nextFrame(AptValue* thisObj, int argc);
    static AptValue* sMethod_prevFrame(AptValue* thisObj, int argc);
};

// ============================================================================
// AptCharacterSpriteInstBase - base for sprite instances
// Layout (partial):
//   0x1C: u32 m_clipActionFlags (bits 8-31 = clip actions, bits 0-7 = other)
//   0x24: AptDisplayList* m_displayList (at offset 0x24 from this)
// ============================================================================
class AptCharacterSpriteInstBase : public AptCharacterInst {
public:
    AptCharacterSpriteInstBase();
    ~AptCharacterSpriteInstBase();
    void PreDestroy();
    void SetClipAction(int action);
    void RemoveClipAction(int action);
    int HasClipAction(int action);
};

// ============================================================================
// AptCharacterTextInst - text field instance
// ============================================================================
class AptCharacterTextInst : public AptCharacterSpriteInstBase {
public:
    AptCharacterTextInst();
    ~AptCharacterTextInst();
    void SetText(AptCIH* cih);
    void UpdateText(AptCIH* cih);

    void* operator new(unsigned int size);
    void operator delete(void* ptr, unsigned int size);
    void* operator new[](unsigned int size);
    void operator delete[](void* ptr);
};

// ============================================================================
// TextFormat - text formatting object
// ============================================================================
struct TextFormat {
    void copyTextFormatObj(TextFormat* src);
};

#endif // APT_CHARACTER_H
