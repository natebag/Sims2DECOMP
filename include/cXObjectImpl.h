/* cXObjectImpl struct layout — reverse-engineered from DOL field accesses
 *
 * Sources:
 *   - 38 verified matched functions (IsFromCatalog, SetColorIndex, HierGetChild, etc.)
 *   - 169 functions in src/asm_decomp/cXObjectImpl.cpp (DOL byte analysis)
 *   - 145 unique field offsets identified in docs/systems/cXObjectImpl-fields.md
 *   - Vtable analysis in docs/systems/cXObjectImpl-vtable.md
 *
 * This header represents the EXACT memory layout required for matching code generation.
 * Field offsets are critical — do not change without verifying against DOL.
 */

#ifndef CXOBJECTIMPL_H
#define CXOBJECTIMPL_H

#include "types.h"

/* Forward declarations */
struct EdithVariableSet;
struct ISimInstance;
struct cXObject;
struct ObjSelector;
struct ObjectModule;
struct FTilePt;
struct FTileRect;
struct HierarchySite;
struct PlacementSpec;
struct Behavior;
struct StackElem;
struct XPrimParam;
struct ReconBuffer;
struct StringBuffer;
struct ObjectProbe;
struct InventoryCommandParam;
struct ExpressionParam;
struct AnimateNewParam;
struct PlaySoundParam;
struct KillSoundsParam;
struct CompleteGoalParam;
struct FindGoodLocationParams;
struct DialogParam;

/* ============================================================================
 * Inner object — accessed via this->m_inner (offset 0x04)
 * Has its own vtable at offset 0x04 with numerous virtual dispatch entries
 * ============================================================================ */
struct cXObjectInner {
    /* 0x00 */ void* m_vtable;  /* Inner object's vtable */
    /* 0x04 */ void* m_data;    /* Pointer to actual data */
    /* ... vtable dispatch targets ... */
};

/* Inner vtable entry map (cXObjectInner->m_vt at inner+0x00 or inner+0x04):
 * Offset  Function Ptr          Used By
 * ------  --------------------  ---------------------------------
 * 0x1C8   GetObjDef             RequiresWallAdjacency, IsChair, GetTreeID
 * 0x1E8   SetColorIndex(setter) SetColorIndex
 * 0x2B0   GetNumSlots           GetObjectSlot
 * 0x310   GetObjDef2            IsFromCatalog
 * 0x318   GetObjectType         IsEmissive (2nd call)
 * 0x338   GetAverageLocation    GetAverageLocation
 * 0x418   GetEmissiveFlag       IsEmissive (1st call)
 * 0x488   HierGetChild          HierGetChild
 * 0x4B8   GetColorIndex(getter) SetColorIndex (1st call)
 */

/* ============================================================================
 * Impl sub-object — accessed via this->m_impl (offset 0x58)
 * Has its vtable at impl+0x00 (different from inner's layout)
 * ============================================================================ */
struct cXObjectImplSub {
    /* 0x00 */ void* m_vtable;  /* Impl sub-object's vtable at offset 0 */
    /* 0x04 */ void* m_data;
};

/* Impl vtable entry map (cXObjectImplSub->m_vt at impl+0x00):
 * Offset  Function Ptr          Used By
 * ------  --------------------  ---------------------------------
 * 0x098   GetFirst              GetFirstImpl (1st call)
 * 0x240   EnableSimDispatch     EnableSim
 */

/* ============================================================================
 * Main cXObjectImpl Class
 * 
 * SN Systems ABI notes:
 * - Vtable pointer is at offset 0xEC (not at 0x00 like standard C++)
 * - Multiple sub-objects with their own vtable pointers
 * - Field layout is critical for matching instruction offsets
 * ============================================================================ */
struct cXObjectImpl {
    /* ------------------------------------------------------------------------
     * BASE CLASS / SUB-OBJECT POINTERS (offsets 0x00-0x07)
     * ------------------------------------------------------------------------ */
    /* 0x000 */ void* m_field00;         /* Sub-object pointer 1 (TreeSim-related) */
    /* 0x004 */ cXObjectInner* m_inner;  /* Primary inner object for vtable dispatch */
    
    /* 0x008 */ void* m_field08;         /* R/W: Initialize, InterpValue, ParseUIString */
    /* 0x00C */ void* m_field0C;         /* R/W: HierGetObject, Initialize, InterpValue */
    
    /* ------------------------------------------------------------------------
     * OBJECT VISIBILITY & STATE (offsets 0x10-0x1F)
     * ------------------------------------------------------------------------ */
    /* 0x010 */ void* m_field10;         /* R/W: GetInteractionLeader, IsSpriteVisible */
    /* 0x014 */ short m_numVisible;      /* R/W: IsSpriteVisible count, Initialize */
    /* 0x016 */ short m_field16;         /* R/W: InterpValue, TryCameraControl */
    
    /* 0x018 */ float m_field18;         /* R/W: ExtractContainedSims, Initialize */
    /* 0x01C */ float m_slotHeight;      /* R/W: GetSlotHeight, Initialize, ReconSlots */
    
    /* ------------------------------------------------------------------------
     * LOCATION & PLACEMENT DATA (offsets 0x20-0x3F)
     * ------------------------------------------------------------------------ */
    /* 0x020 */ float m_field20;         /* R: TrySnap */
    /* 0x024 */ float m_field24;         /* R/W: DayPassed, ParseUIString, TrySnap */
    /* 0x028 */ float m_field28;         /* R: Initialize, InterpValue, ParseUIString */
    /* 0x02C */ void* m_field2C;         /* R: ParseUIString */
    /* 0x030 */ float m_field30;         /* R/W: ParseUIString, TrySnap */
    /* 0x034 */ float m_field34;         /* R/W: InterpValue, ParseUIString */
    /* 0x038 */ void* m_field38;         /* R: DayPassed, GetFrontFaceDirection */
    /* 0x03C */ void* m_field3C;         /* R: ParseUIString, TryGenericSimCall */
    
    /* ------------------------------------------------------------------------
     * CATALOG & FLAGS (offsets 0x40-0x57)
     * ------------------------------------------------------------------------ */
    /* 0x040 */ u8 _pad040[4];
    /* 0x044 */ void* m_field44;         /* R: TryGenericSimCall */
    /* 0x046 */ u16 m_field46;           /* R: DayPassed */
    /* 0x048 */ s16 m_field48;           /* R: DayPassed, InterpValue */
    /* 0x04A */ s16 m_field4A;           /* R: DayPassed */
    /* 0x04C */ float m_field4C;         /* R: DayPassed, InterpValue */
    /* 0x04E */ s16 m_field4E;           /* R: IsFromCatalog */
    /* 0x050 */ float m_field50;         /* R: IsFromCatalog, TryCameraControl */
    /* 0x054 */ u8 _pad054[4];
    
    /* ------------------------------------------------------------------------
     * IMPL SUB-OBJECT & SIM DATA (offsets 0x58-0x7F)
     * ------------------------------------------------------------------------ */
    /* 0x058 */ cXObjectImplSub* m_impl; /* R/W: EnableSim, GetFirstImpl */
    /* 0x05A */ u8 _pad05A[2];
    /* 0x05C */ s16 m_field5C;           /* R/W: HideForCutaway */
    /* 0x05E */ u8 _pad05E[2];
    /* 0x060 */ s16 m_field60;           /* R/W: InterpValue, ReconStream */
    /* 0x062 */ s16 m_field62;           /* R: Reset */
    /* 0x064 */ s16 m_sourceID;          /* R/W: EnableSim, TryKillSounds */
    /* 0x066 */ u8 _pad066[2];
    
    /* 0x068 */ int m_tileX;             /* R: CalcShortDistance position X */
    /* 0x06C */ int m_tileY;             /* R: CalcShortDistance position Y */
    
    /* 0x070 */ void* m_field70;         /* R/W: TestIntersection */
    /* 0x074 */ u8 _pad074[8];
    
    /* ------------------------------------------------------------------------
     * GRAPHICS & MODEL DATA (offsets 0x7C-0x9F)
     * ------------------------------------------------------------------------ */
    /* 0x07C */ float m_field7C;         /* R: InterpValue */
    /* 0x080 */ void* m_field80;         /* R/W: GetPlacementSpec, HierGetSite */
    /* 0x084 */ void* m_hilite;          /* R/W: SetHilite */
    /* 0x088 */ void* m_debugName;       /* R/W: ComputeRect, GetDebugName */
    /* 0x08A */ s16 m_field8A;           /* R: IsFromCatalog */
    /* 0x08C */ void* m_model;           /* R/W: GetFrontFaceDirection */
    /* 0x090 */ char* m_slotArray;       /* R: HierGetChild (stride 32 per slot) */
    /* 0x094 */ void* m_field94;         /* R: ReconStream, TryGenericSimCall */
    /* 0x098 */ s16 m_field98;           /* R: TryGenericSimCall */
    /* 0x09A */ u8 _pad09A[6];
    
    /* ------------------------------------------------------------------------
     * TREE & BEHAVIOR DATA (offsets 0xA0-0xBF)
     * ------------------------------------------------------------------------ */
    /* 0x0A0 */ void* m_fieldA0;         /* R/W: TryCallNamedTree */
    /* 0x0A4 */ void* m_fieldA4;         /* R: TryGenericSimCall, TrySnap */
    /* 0x0A8 */ s16 m_fieldA8;           /* R: TryGenericSimCall */
    /* 0x0AA */ u8 _pad0AA[6];
    /* 0x0B0 */ void* m_fieldB0;         /* R/W: AllowIdleOptimization, Simulate */
    /* 0x0B4 */ void* m_fieldB4;         /* R: AllowIdleOptimization, TrySetBalloon */
    /* 0x0B6 */ u16 m_fieldB6;           /* R: TestAndPlace */
    /* 0x0B8 */ s16 m_fieldB8;           /* R: InterpValue, TryCheckObject */
    /* 0x0BA */ u8 _pad0BA[2];
    /* 0x0BC */ void* m_fieldBC;         /* R: TryGenericSimCall */
    
    /* ------------------------------------------------------------------------
     * SYNC & STATE MANAGEMENT (offsets 0xC0-0xDF)
     * ------------------------------------------------------------------------ */
    /* 0x0C0 */ void* m_fieldC0;         /* R/W: TryGenericSimCall */
    /* 0x0C4 */ void* m_fieldC4;         /* R/W: ChangeSelectedSimR */
    /* 0x0C8 */ u8 m_fieldC8;            /* W: cXObjectImpl */
    /* 0x0C9 */ u8 _pad0C9[3];
    /* 0x0CC */ void* m_fieldCC;         /* W: cXObjectImpl */
    /* 0x0D0 */ float m_fieldD0;         /* W: cXObjectImpl */
    /* 0x0D4 */ float m_fieldD4;         /* W: cXObjectImpl */
    /* 0x0D8 */ s16 m_fieldD8;           /* R/W: InterpValue, TryGenericSimCall */
    /* 0x0DA */ u16 m_fieldDA;           /* W: cXObjectImpl */
    /* 0x0DC */ void* m_syncObject;      /* R/W: Initialize, Reset, SetSyncObject */
    /* 0x0E0 */ float m_syncObjectFloat; /* R/W: Initialize, Reset, SetSyncObject */
    /* 0x0E4 */ void* m_fieldE4;         /* W: Initialize, Reset, SetSyncObject */
    /* 0x0E8 */ s16 m_fieldE8;           /* R: TryCameraControl, TrySnap */
    /* 0x0EA */ s16 m_fieldEA;           /* R: TryGenericSimCall */
    
    /* ------------------------------------------------------------------------
     * VTABLE POINTER (SN ABI: vtable at end of class)
     * ------------------------------------------------------------------------ */
    /* 0x0EC */ void* m_vtable;          /* R/W: Primary vtable pointer */
    
    /* ------------------------------------------------------------------------
     * ERROR & DEBUG DATA (offsets 0xF0-0x13F)
     * ------------------------------------------------------------------------ */
    /* 0x0F0 */ s16 m_fieldF0;           /* R: TryMakeActionString */
    /* 0x0F2 */ u8 _pad0F2[6];
    /* 0x0F8 */ s16 m_fieldF8;           /* R: TestAndPlace, TryFindGoodLocation */
    /* 0x0FA */ u8 _pad0FA[6];
    /* 0x100 */ s16 m_field100;          /* R: TestIntersection, TryGenericSimCall */
    /* 0x102 */ u8 _pad102[0x0A];
    /* 0x10C */ void* m_field10C;        /* W: cXObjectImpl */
    /* 0x110 */ s16 m_field110;          /* R: TryGenericSimCall, TrySnap */
    /* 0x112 */ u8 _pad112[2];
    /* 0x114 */ void* m_field114;        /* R/W: TryGenericSimCall, TrySnap */
    /* 0x118 */ u8 _pad118[8];
    /* 0x120 */ s16 m_field120;          /* R: ReconStream, TryGenericSimCall */
    /* 0x122 */ u8 _pad122[2];
    /* 0x124 */ void* m_field124;        /* R: TryGenericSimCall */
    /* 0x128 */ s16 m_field128;          /* R: TryGenericSimCall */
    /* 0x12A */ u8 _pad12A[2];
    /* 0x12C */ void* m_field12C;        /* R: TryGenericSimCall */
    /* 0x130 */ s16 m_field130;          /* R/W: TryBurn, TryFindGoodLocation */
    /* 0x132 */ u8 _pad132[2];
    /* 0x134 */ void* m_field134;        /* R: TryGenericSimCall */
    /* 0x138 */ s16 m_field138;          /* R: TryFindGoodLocation, TryGenericSimCall */
    /* 0x13A */ u8 _pad13A[2];
    
    /* Total known struct extent so far: 0x13C bytes (316 bytes) */
    /* Full struct extends to at least 0x5C70 based on field analysis */
};

/* Known total minimum size: at least 0x134 bytes (308+ bytes) */
/* Extended fields exist up to offset 0x5C6C */

/* ============================================================================
 * Function Prototypes (key methods that have been matched)
 * ============================================================================ */

/* Hierarchy accessors */
int cXObjectImpl_HierGetChild(void* this, int childIdx);     /* 0x800DD114 */

/* Type checking */
int cXObjectImpl_IsFromCatalog(void* this);                  /* 0x800E225C */
int cXObjectImpl_IsChair(void* this);                        /* 0x800EB758 */
int cXObjectImpl_RequiresWallAdjacency(void* this);          /* 0x800EAC00 */
int cXObjectImpl_IsVehicle(void* this);                      /* 0x800E3050 */
int cXObjectImpl_IsPerson(void* this);                       /* 0x800E3094 */

/* State accessors/mutators */
int cXObjectImpl_SetColorIndex(void* this, unsigned char colorIdx); /* 0x800E3118 */
int cXObjectImpl_EnableSim(void* this, int enabled);         /* 0x800EAFC0 */
int cXObjectImpl_GetTreeID(void* this, short entryPoint);    /* 0x800EAC88 */
int cXObjectImpl_GetFirstImpl(void* this);                   /* 0x800EB84C */

#endif /* CXOBJECTIMPL_H */
