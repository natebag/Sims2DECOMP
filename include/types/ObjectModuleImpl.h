/* include/types/ObjectModuleImpl.h — canonical layout for ObjectModuleImpl
 * (objectmoduleimpl.obj / object.obj).
 *
 * S19 TypeArchaeologist proactive deliverable. ObjectModuleImpl is the global
 * registry/manager for all live objects, people, portals and the per-tile
 * object grid in a loaded lot. High forced density (64 fns / ~27.5KB) and
 * flagged as an S19 matcher target.
 *
 * Provenance: UNUSUALLY STRONG — most field offsets here come from already
 * CLEAN, hand-written matches in src/matched/objectmoduleimpl/ and
 * src/matched/object/ (GetNumPeople, GetNumPortals, GetNumObjects,
 * GetGlobalRoutingSlot, GetTileObjectID, GetFirst), not just ASMPROC asm.
 * Those matches define the offsets directly in their local structs; this
 * header consolidates them into one canonical layout. The MI head (vtables /
 * embedded sub-objects at 0x00..0x33) is from the ctor asm (0x800F2CBC) and is
 * less certain, so it is documented conservatively.
 *
 * Shape-only header — no ASMPROC, no inline asm, no byte injection.
 *
 * ============================================================================
 * Singleton note
 * ============================================================================
 * Some "accessors" return globals, NOT instance fields:
 *   - GetSim()    -> a file-static  s_sim    (not this->...)
 *   - GetFolder() -> SDA global at -21508(r13)
 * So treat ObjectModuleImpl as an effectively-singleton manager; not every
 * Get* maps to an m_ field. The fields below are the ones genuinely read off
 * `this`.
 * ============================================================================
 */
#ifndef SIMS2_TYPES_OBJECTMODULEIMPL_H
#define SIMS2_TYPES_OBJECTMODULEIMPL_H

#include "../types.h"

/* Forward decls — element types of the registry arrays (opaque here). */
struct cXObject;
struct cXPerson;
struct cXPortal;

struct ObjectModuleImpl {
    /* ---- MI head (from ctor 0x800F2CBC; conservative) -------------------- */
    /* 0x00 */ void*  m_vtable;     /* primary vtable (ctor stores ...6888 here) */
    /* 0x04 */ u8     _sub04[0x0C]; /* embedded member sub-object constructed in
                                       place (ctor: addi r3,r30,4; bl ctor).
                                       Extent ~12B, runs up to the secondary
                                       vtable; opaque.                          */
    /* 0x10 */ void*  m_vtable2;    /* secondary (MI base) vtable (ctor ...6856) */
    /* 0x14 */ u8     _pad14[0x08]; /* 0x1C/0x20 zeroed in ctor (stw 0,...);
                                       small scalar fields, purpose TBD.         */
    /* 0x1C */ s32    m_field1C;    /* zeroed in ctor                            */
    /* 0x20 */ s32    m_field20;    /* zeroed in ctor                            */
    /* 0x24 */ u8     _pad24[0x08]; /* opaque                                    */

    /* 0x2C */ void*  m_firstNode;  /* head of an intrusive node list. GetFirst
                                       (0x800F9968): node ? ((void**)node)[1] : 0 */
    /* 0x30 */ u8     _pad30[0x04]; /* opaque (alignment before the grid)        */

    /* ---- per-tile object id grid ---------------------------------------- */
    /* 0x34 */ s16    m_tileObjectIDs[64][64]; /* 64*64*2 = 0x2000 bytes,
                                       spans 0x0034..0x2033. GetTileObjectID
                                       (0x800F9668): bounds-check x,y in [0,63],
                                       return m_tileObjectIDs[y][x].             */

    /* ---- sub-object band (ctor inits several at 0x2034+) ---------------- */
    /* 0x2034 */ u8   _band2034[0x24]; /* sub-objects constructed in ctor at
                                          0x2034, 0x2044, ...; opaque. Runs up to
                                          the people array at 0x2058.            */

    /* ---- parallel registry arrays (TArray-style begin/end, stride 4) ----- */
    /* 0x2058 */ cXPerson** m_peopleBegin;  /* GetNumPeople: (end-begin)>>2      */
    /* 0x205C */ cXPerson** m_peopleEnd;
    /* 0x2060 */ u8     _pad2060[0x08];      /* TArray capacity/owner tail        */
    /* 0x2068 */ cXPortal** m_portalsBegin; /* GetNumPortals: (end-begin)>>2     */
    /* 0x206C */ cXPortal** m_portalsEnd;
    /* 0x2070 */ u8     _pad2070[0x08];      /* TArray tail                       */

    /* 0x2078 */ char*  m_globalRoutingSlots; /* GetGlobalRoutingSlot(i):
                                       base + i*60 (60-byte routing-slot stride). */
    /* 0x207C */ u8     _pad207C[0x14];      /* opaque (0x207C..0x208F)           */

    /* 0x2090 */ cXObject** m_objectArrayBegin; /* GetNumObjects: (end-begin)>>2
                                       PLUS the non-null count of m_fixedObjects. */
    /* 0x2094 */ cXObject** m_objectArrayEnd;
    /* 0x2098 */ u8     _pad2098[0x08];      /* TArray tail                       */
    /* 0x20A0 */ cXObject*  m_fixedObjects[16]; /* 16 fixed object slots; counted
                                       in GetNumObjects.                          */
    /* 0x20E0 */ u8     _padTail[0x40];      /* OPAQUE extent — class is larger;
                                       more fields read past 0x20E0 by other
                                       methods. Total size unverified.           */
};

/* ============================================================================
 * Function prototypes — selected matched ObjectModuleImpl methods
 * (105 files exist; these are the layout-defining accessors). Most of the
 * larger registry methods remain forced and are the redo targets.
 * ========================================================================== */
extern "C" void f_800F2CBC(void); /* ObjectModuleImpl::ObjectModuleImpl(void)   */
extern "C" void f_800F45A8(void); /* ObjectModuleImpl::Init(void)               */
extern "C" void f_800F9668(void); /* GetTileObjectID(CTilePt&)                  */
extern "C" void f_800F96E4(void); /* SetTileObjectID(...)                       */
extern "C" void f_800F9820(void); /* GetNumObjects(void)                        */
extern "C" void f_800F99A8(void); /* GetNumPeople(void)                         */
extern "C" void f_800F99CC(void); /* GetNumPortals(void)                        */
extern "C" void f_800F99E0(void); /* GetGlobalRoutingSlot(int)                  */
extern "C" void f_800F9968(void); /* GetFirst(void)                             */
extern "C" void f_800F97CC(void); /* GetObject(...)                             */
extern "C" void f_800F9860(void); /* GetNextPerson(unsigned)                    */
extern "C" void f_800F48F8(void); /* GetObjectByGUID(int)                       */
extern "C" void f_800F4A14(void); /* GetPersonByGUID(int)                       */

#endif /* SIMS2_TYPES_OBJECTMODULEIMPL_H */
