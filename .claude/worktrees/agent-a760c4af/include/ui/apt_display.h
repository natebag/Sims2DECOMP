#ifndef APT_DISPLAY_H
#define APT_DISPLAY_H

#include "types.h"
#include "ui/apt_value.h"

// Forward declarations
class AptControl;
class AptCharacter;
class AptCharacterInst;
class AptCIH;
class AptNativeHash;
class AptRenderingContext;
struct AptMatrix;
struct AptRect;
struct AptCXForm;
struct AptnCXForm;
struct AptEventActionSet;
struct AptControlPlaceObject2;
struct AptControlRemoveObject2;
struct AptMovieclipInformation;

// Use int typedef for forward-declared enum
typedef int AptMaskRenderOperation;

// ============================================================================
// AptPseudoData_t - pseudo data for display list management
// ============================================================================
class AptPseudoData_t {
public:
    AptPseudoData_t(AptControl* ctrl, int id, AptCharacter* character);

    void operator delete(void* ptr, unsigned int size);
};

// ============================================================================
// AptPseudoCIH_t - pseudo CIH for display list management
// Layout (partial):
//   0x08: AptPseudoCIH_t* m_next
//   0x0C: AptPseudoCIH_t* m_prev
// ============================================================================
class AptPseudoCIH_t {
public:
    AptPseudoCIH_t(AptControl* ctrl, int id, int depth, AptCharacter* character);

    void operator delete(void* ptr, unsigned int size);
};

// ============================================================================
// AptPseudoDisplayList - linked list of pseudo CIH entries
// ============================================================================
class AptPseudoDisplayList {
public:
    void ClearList();
    int FindInst(int depth, AptPseudoCIH_t** outPrev, AptPseudoCIH_t** outFound);
    void Insert(AptPseudoCIH_t* item);
    void Insert(AptPseudoCIH_t* item, AptPseudoCIH_t* after);
    void Insert(AptPseudoCIH_t* item, AptPseudoCIH_t* after, AptPseudoCIH_t* before);
    void Remove(AptPseudoCIH_t* item);
    void Remove(int depth);
};

// ============================================================================
// AptDisplayListState - state of a display list (linked list of CIH entries)
// Layout (partial):
//   0x00: AptCIH* m_head (first CIH in list)
// Each CIH in the list has:
//   0x50: AptCIH* m_prevInList
//   0x54: AptCIH* m_nextInList
// ============================================================================
class AptDisplayListState {
public:
    AptCIH* m_head;  // 0x00

    AptDisplayListState();
    ~AptDisplayListState();

    void findInst(int depth, EAStringC* name, AptCIH** outPrev, AptCIH** outFound);
    int getLength();
    AptCIH* getValue(int index);
    void RegisterReferences(AptValue* val) const;
    void insert(AptCIH* item, AptCIH* after);
    void insert(int depth, AptVirtualFunctionTable_Indices type, AptCharacterInst* inst, AptCIH* after, AptCIH* before);
    void insert(int depth, AptVirtualFunctionTable_Indices type, AptCharacterInst* inst);
    void insert(int depth, AptCIH* item);
    void insert(int depth, AptCIH* item, AptCIH* after, AptCIH* before);
    void remove(int depth);
    void remove(AptCIH* item);
    int hasRenderData();
    void GetMovieclipInfo(AptMovieclipInformation* info);
};

// ============================================================================
// AptDisplayList - manages character instances on screen
// Layout:
//   0x00: AptDisplayListState* m_state
// ============================================================================
class AptDisplayList {
public:
    AptDisplayListState* m_state;  // 0x00

    AptDisplayList();
    ~AptDisplayList();

    void instantiateCharacter(int depth, AptCharacter* character, EAStringC* name,
                              AptCIH* parent, int flags, int extraFlags,
                              AptCIH** outCIH, int* outResult);
    void removeObject(AptCIH* cih);
    void removeObject(int depth);
    void removeObject(AptControlRemoveObject2* ctrl);
    void removeClonedObject(AptCIH* cih);
    void placeObjectNCXForm(AptCIH* cih, int depth, AptCharacter* character,
                            EAStringC* name, AptCIH* parent, int flags, int extra,
                            AptnCXForm* cxform, AptMatrix* matrix,
                            AptEventActionSet* events, float ratio);
    void placeObject(AptCIH* cih, int depth, AptCharacter* character,
                     EAStringC* name, AptCIH* parent, int flags, int extra,
                     AptCXForm* cxform, AptMatrix* matrix,
                     AptEventActionSet* events, float ratio, AptValue* val);
    void placeObject(AptControlPlaceObject2* ctrl, AptCIH* parent);
    void placeObject(AptPseudoCIH_t* pseudo, AptCIH* parent);
    void clear(bool full);
    void render(AptRenderingContext* ctx, AptMaskRenderOperation op);
    void _getBoundingRect(AptRenderingContext* ctx, AptRect* rect);
    void tick();
    void PreDestroy();
    AptDisplayListState* getState();
    void useState(AptDisplayListState* state);
    void RemoveFromDisplayList(AptNativeHash* hash, AptCIH* cih);
    void AddToDisplayList(AptNativeHash* hash, AptPseudoCIH_t* pseudo, AptCIH* parent);
    void ReplaceDisplyListItem(AptNativeHash* hash, AptCIH* cih,
                               AptPseudoCIH_t* pseudo, AptCIH* parent);
    void mergeState(AptPseudoDisplayList* pseudo, AptNativeHash* hash, bool flag);
    void validate(AptCIH* cih);
    void deallocAssetStringRecursive();
    void _addToSetCaches(AptCIH* cih, int depth);
};

// Forward declare classes whose destructors appear in AptDisplayList.cpp.obj
class AptCharacterSpriteInst;
class AptCharacterMorphInst;
class AptCharacterStaticTextInst;
class AptCharacterShapeInst;

#endif // APT_DISPLAY_H
