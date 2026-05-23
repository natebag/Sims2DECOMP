/* include/types/cXPersonImpl.h — canonical class layout for cXPersonImpl
 *
 * S17 TypeArchaeologist Phase 1 deliverable #5.
 *
 * Provenance: ASMPROC inject_before stubs in src/matched/agent/ and
 * src/matched/person/ (50+ matched files for this class).
 *
 * ============================================================================
 * Structural relationship to cXObjectImpl (CRITICAL — read before using):
 *
 * cXPersonImpl does NOT inherit from cXObjectImpl in the C++ sense (no
 * base-at-offset-zero layout). Instead, it **embeds** a cXObjectImpl
 * sub-object at offset +0x5C4, with cXPersonImpl-specific person state
 * (motives, actions, awareness, queues) in the PREFIX 0x000..0x5C3.
 *
 * Confirmation from the ctor (cXPersonImpl::cXPersonImpl, 0x8011AE04):
 *   addi  r10, r31, 1476           ; r10 = this + 0x5C4
 *   stw   r10, 0x0(r31)            ; *(this+0x00) = &embedded cXObjectImpl
 *   bl    _s8011AE04_0             ; ctor on the embedded cXObjectImpl
 *   ...
 *   stw   r31, 0x4(r11)            ; *(impl-holder + 4) = this (back-link
 *                                    so the cXObjectImplHolder's
 *                                    m_personImpl slot points back here)
 *
 * The cross-link via cXObject's ImplHolder.m_personImpl explains how game
 * code can call IsInvisible/IsVisitor on what looks like a cXObject and
 * route to the cXPersonImpl-specific implementation.
 * ============================================================================
 */
#ifndef SIMS2_TYPES_CXPERSONIMPL_H
#define SIMS2_TYPES_CXPERSONIMPL_H

#include "../types.h"

/* Forward decls */
struct cXObject;
struct cXObjectImpl;
struct Interaction;
struct XRoute;
struct RoutingSlot;
struct ReconBuffer;
struct StackElem;
struct BString2;
struct cXPerson;
struct Behavior;

/* ============================================================================
 * cXPersonImpl — the person variant impl
 *
 * Total instance size: at least 0x6B8 bytes (extends through ~0x6B8 based on
 * ctor stores). The embedded cXObjectImpl at +0x5C4 makes the tail
 * cXObjectImpl-shaped.
 *
 * Confidence legend in field comments:
 *   [V] = verified by ≥1 matched stub asm
 *   [I] = inferred from ctor zero-init pattern (less specific)
 *   [L] = legacy draft (include/cXPersonImpl.h); needs further verification
 * ========================================================================== */
struct cXPersonImpl {
    /* 0x000 */ cXObjectImpl* m_implPtr;       /* [V] points to embedded
                                                      cXObjectImpl at +0x5C4;
                                                      stored in ctor by
                                                      `addi r10,r31,1476;
                                                       stw r10,0x0(r31)` */
    /* 0x004 */ void*         m_subPtr;        /* [V] points to this+0x578
                                                      sub-region; stored in
                                                      ctor by `stw r11,0x4(r31)`
                                                      where r11=this+0x578 */
    /* 0x008 */ u8            _pad008[0x40];   /* opaque envelope */

    /* 0x048 */ s16           m_visitorStatus; /* [V] IsVisitor (0x8012C8A8)
                                                      `lha 0,0x48(3)` */
    /* 0x04A */ u8            _pad04A[0x52];

    /* 0x09C */ u16           m_flags;         /* [V] IsInvisible (0x8012C8E0)
                                                      `lhz 3,0x9c(3);
                                                       rlwinm 3,3,0,31,31`
                                                      bit 0 = invisible.
                                                      Other bits: bit1 green,
                                                      bit2 ghost, bit3 alien,
                                                      bit4 motive-failure, etc.
                                                      (further bits per legacy
                                                      Is* family of one-liners) */
    /* 0x09E */ u8            _pad09E[0x0A];

    /* 0x0A8 */ float         m_motives[16];   /* [V] GetMotive (0x801253A4)
                                                      `addi 3,3,168;
                                                       lfsx f1,3,index*4`
                                                      16 motives × 4 bytes. */

    /* ------ S18 v2 amendment (OpusArchitect typereq-evidence e350ab65
     * + S17 banked 35ae87de): 16 new offsets across the middle/back-half
     * of the previously-opaque 0x0E8..0x41B envelope.  All read [V] from
     * ASMPROC stubs in src/matched/agent/match_*cXPersonImpl*.cpp ------ */
    /* 0x0E8 */ u8            _pad0E8[0x18];

    /* 0x100 */ s16           m_field100;      /* [V] singleton short (1 site) */
    /* 0x102 */ u8            _pad102[0x02];
    /* 0x104 */ u16           m_secondaryFlags;/* [V] 2 files, lhz/sth — paralleled
                                                      with m_flags @ 0x9C */
    /* 0x106 */ u8            _pad106[0x22];

    /* 0x128 */ s32           m_field128;      /* [V] ctor-init only */
    /* 0x12C */ void*         m_field12C;      /* [V] rw pointer field */
    /* 0x130 */ u8            _pad130[0xB8];

    /* 0x1E8 */ void*         m_field1E8;      /* [V] mostly-read pointer (3 reads / 1 write) */
    /* 0x1EC */ u8            _pad1EC[0xBC];

    /* 0x2A8 */ void*         m_field2A8;      /* [V] 6 read sites — read-only ptr,
                                                      possibly m_currentJob/m_homeRef */
    /* 0x2AC */ void*         m_field2AC;      /* [V] 4 read sites — companion to 0x2A8 */
    /* 0x2B0 */ u8            _pad2B0[0x134];

    /* 0x3E4 */ void*         m_field3E4;      /* [V] mostly-read (6 reads / 1 write) */
    /* 0x3E8 */ u8            _pad3E8[0x0C];

    /* 0x3F4 */ void*         m_simulator;     /* [V] HOTTEST ptr field after
                                                      m_motives — 16 read sites /
                                                      1 binding writer.

                                                      Writer profile (OpusArchitect
                                                      disambiguation, post cd1c56b7):
                                                       - ctor (0x8011AE04): zero-init
                                                       - Initialize (0x8011E0FC):
                                                         * loads singleton from SDA
                                                           `lwz r3, -21432(r13)`
                                                         * calls two consecutive
                                                           methods on it; 2nd return
                                                           value is the bound ptr
                                                         * stores at this+0x3F4
                                                         * immediately dispatches a
                                                           virtual call through it
                                                           (MI-shape vtable:
                                                            top_offset@+0x10,
                                                            fnptr@+0x14)

                                                      Bind-once-in-Initialize pattern
                                                      (NOT rebound at gameplay time)
                                                      rules out m_currentInteraction.
                                                      Strongest inference is
                                                      m_simulator — a per-instance
                                                      simulator object handed out by
                                                      a game-wide manager. The SDA
                                                      slot at -21432(r13) is hot
                                                      across INVTarget, SAnimator2,
                                                      CTGFileImpl — a top-level
                                                      world/simulator singleton.

                                                      Read sites are all lifecycle/
                                                      dispatch: Reset, Simulate,
                                                      ReconStream, TryChangeSuit,
                                                      ~cXPersonImpl, etc. — i.e.
                                                      "use my simulator", not "what
                                                      am I currently doing".

                                                      Type is `void*` until the
                                                      sim-manager class identity is
                                                      confirmed; upgrade to e.g.
                                                      `CSimulatorImpl*` when a
                                                      sibling class's binding
                                                      reveals it. */
    /* 0x3F8 */ s32           m_field3F8;      /* [V] paired with m_simulator */
    /* 0x3FC */ s32           m_field3FC;
    /* 0x400 */ u8            _pad400[0x08];

    /* 0x408 */ void*         m_field408;      /* [V] rw pointer (3 reads / 1 write) */
    /* 0x40C */ void*         m_field40C;      /* [V] rw pointer (5 reads / 1 write) */
    /* 0x410 */ u8            _pad410[0x0C];

    /* 0x41C */ s16           m_currentRoom;   /* [V] GetCurrentRoom (0x8012C7F4)
                                                      `lhz 3,0x41c(3)` */
    /* 0x41E */ u8            _pad41E[0x02];

    /* 0x420 */ void*         m_field420;      /* [V] 6 reads — likely m_pendingRoom
                                                      or m_currentRoomScratch (adjacent
                                                      to m_currentRoom @ 0x41C) */
    /* 0x424 */ s32           m_field424;
    /* 0x428 */ u8            _pad428[0x148];

    /* 0x570 */ s32           m_field570;      /* [I] zeroed in ctor */
    /* 0x574 */ u8            _pad574[0x04];

    /* 0x578 */ u8            m_subRegion578[0x4C]; /* [V] sub-region pointed at by
                                                            m_subPtr (this+0x4).
                                                            Known write port at
                                                            internal +0x08 (= this+0x580)
                                                            per e350ab65 evidence —
                                                            sub-shape not yet recovered. */

    /* 0x5C4 */ cXObjectImpl* m_embeddedImpl_ptr_alias; /* [V] same as m_implPtr;
                                                              start of embedded
                                                              cXObjectImpl block.
                                                              See ctor delegation.
                                                              Treat this offset
                                                              as opaque tail. */
    /* (cXObjectImpl layout follows from here; see include/types/cXObjectImpl.h
        for the offsets inside it. Use that header to access embedded fields,
        offset by +0x5C4 from cXPersonImpl base.) */
    /* 0x5C8+ ... opaque tail extending through end of instance ... */
    /* 0x5C8 */ u8            _padTail[0x100];
};

/* ============================================================================
 * Function prototypes — matched cXPersonImpl methods
 * (subset — there are 90+ matched files; full list in src/matched/agent/
 * and src/matched/person/)
 * ========================================================================== */

/* Construction / lifecycle */
extern "C" void f_8011AE04(void); /* cXPersonImpl::cXPersonImpl(int, ...)     */
extern "C" void f_8011C77C(void); /* cXPersonImpl::~cXPersonImpl(void)        */
extern "C" void f_8011A824(void); /* cXPersonImpl::InitializeStaticMemory()   */
extern "C" void f_8011A90C(void); /* cXPersonImpl::CleanupStaticMemory()      */
extern "C" void f_8011E0FC(void); /* cXPersonImpl::Initialize(void)           */
extern "C" void f_8011EB78(void); /* cXPersonImpl::Reset(bool)                */
extern "C" void f_8012A04C(void); /* cXPersonImpl::Cleanup(cXObject*)         */
extern "C" void f_8011EC7C(void); /* cXPersonImpl::PostLoad(int)              */
extern "C" void f_8011F06C(void); /* cXPersonImpl::PreSave(void)              */
extern "C" void f_80125048(void); /* cXPersonImpl::ReconStream(ReconBuffer*)  */

/* Motive accessors */
extern "C" void f_801253A4(void); /* cXPersonImpl::GetMotive(int)             */
extern "C" void f_801253E4(void); /* cXPersonImpl::SimMotives(void)           */
extern "C" void f_8011EF40(void); /* cXPersonImpl::LoadMotiveEffects(void)    */
extern "C" void f_8011F0BC(void); /* cXPersonImpl::TrySetMotiveDelta(...)     */

/* State queries (the Is* family — all 8B-24B tiny stubs around 0x8012Cxxx) */
extern "C" void f_8012C8A8(void); /* IsVisitor()           — +0x48           */
extern "C" void f_8012C8E0(void); /* IsInvisible()         — +0x9C bit 0      */
extern "C" void f_8012C7F4(void); /* GetCurrentRoom()      — +0x41C           */
extern "C" void f_8012B1D4(void); /* IsDog()               — pet variant      */
extern "C" void f_8012B254(void); /* IsCat()                                  */
extern "C" void f_8012B2D4(void); /* IsMonkey()                               */
extern "C" void f_8012B354(void); /* IsPet()                                  */
extern "C" void f_8012B42C(void); /* IsChild()                                */
extern "C" void f_8012B4AC(void); /* IsMale()                                 */
extern "C" void f_8012B528(void); /* IsFemale()                               */
extern "C" void f_8012B564(void); /* IsAdult()                                */

/* Action management */
extern "C" void f_80125ADC(void); /* AddAction(Interaction*)                  */
extern "C" void f_80125E64(void); /* RemoveAction(int)                        */
extern "C" void f_80125FE8(void); /* HasQueuedActionOfPri(int)                */
extern "C" void f_8012606C(void); /* CancelLastAction(void)                   */
extern "C" void f_80126194(void); /* CancelAllActions(void)                   */
extern "C" void f_801262B0(void); /* CancelAllButLastActions(void)            */
extern "C" void f_80126360(void); /* GetIndAction(int)                        */
extern "C" void f_801263C8(void); /* GetCurrentAction(void)                   */
extern "C" void f_8012AC7C(void); /* CompleteCurrentAction(void)              */
extern "C" void f_80129F10(void); /* UpdateCurrentAction(void)                */
extern "C" void f_8012AD28(void); /* DeleteTopAction(void)                    */
extern "C" void f_8012AD98(void); /* ActionSkipped(Interaction*)              */

/* Routing */
extern "C" void f_80123A30(void); /* InvalidateRoutes equivalent (S12 family) */
extern "C" void f_8012B5A0(void); /* InvalidateRoutes(void)                   */

/* Awareness */
extern "C" void f_8012CAA8(void); /* SetAwareOfObject(cXObject*)              */
extern "C" void f_8012CAE0(void); /* SetAwareOfObjectKilled(cXObject*)        */
extern "C" void f_8012CB18(void); /* ClearAwareOfObject(cXObject*)            */

#endif /* SIMS2_TYPES_CXPERSONIMPL_H */
