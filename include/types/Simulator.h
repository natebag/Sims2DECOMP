/* include/types/Simulator.h — canonical layout for cSimulator / cSimulatorImpl
 *
 * S18 TypeArchaeologist deliverable #5 (overall S18 #5, catalog #16).
 *
 * Opportunistic legacy promotion of include/core/simulator.h (mature draft).
 *
 * ============================================================================
 * Why this header matters for S18 cXPersonImpl work
 *
 * cXPersonImpl.h v3 (commit 53f34d89f) named the +0x3F4 hot ptr field
 * `m_simulator` based on the bind-once-in-Initialize writer profile and
 * the manager-singleton lookup at SDA -21432(r13). The natural type
 * candidate is `cSimulator*` or `cSimulatorImpl*` — documented here.
 *
 * **RESOLVED (S18 v5):** PersonSlayer's
 * CheckFirstPlayerForFailedSocialModeEntry @ 0x8012B8CC (commit 5d2ecd7fe)
 * answered the question. The dispatch pattern is:
 *   lwz r11,0x3f4(this)   ; r11 = m_simulator
 *   lwz r9,0x0(r11)        ; r9  = *(m_simulator+0) = vtable ptr — SI shape
 *   lha r3,0x138(r9)       ; top_offset for slot 39
 *   lwz r0,0x13c(r9)       ; fnptr for slot 39
 *   add r3,r11,r3 ; mtspr 9,0 ; blrl
 * **Vtable @ offset 0 of the object = SINGLE-INHERITANCE**, so the type
 * IS cSimulator*. cXPersonImpl.h v5 upgrades the field from void* to
 * cSimulator* accordingly.
 *
 * Important nuance: SN ProDG emits MI-thunk-shape SLOT pairs (s16
 * top_offset + s16 pad + void* fnptr = 8B per slot) for SI vtables too.
 * The "SI vs MI" signal is the VTABLE-PTR LOCATION IN THE OBJECT (here:
 * offset 0 = SI; offset > 0 of the object's head + secondary vtable@+0x320
 * etc. = MI as in ISimsObjectModel). The per-slot shape is identical
 * across SI and MI emissions.
 *
 * The SDA slot at `-21432(r13)` is hot across INVTarget, SAnimator2,
 * CTGFileImpl, and cXPersonImpl::Initialize — definitively a game-wide
 * singleton. Whether the returned pointer is a cSimulator instance or
 * something else is the open question.
 * ============================================================================
 */
#ifndef SIMS2_TYPES_SIMULATOR_H
#define SIMS2_TYPES_SIMULATOR_H

#include "../types.h"

/* Forward decls */
struct ReconBuffer;
struct ReconObject;
struct SimLoopProbe;

/* TimeOfDay is documented as an opaque type in the legacy header
 * (likely a small integral or enum representing tick-quantized time). */
typedef s32 TimeOfDay;

/* ============================================================================
 * ExpenseReport — 36B (9 ints) tracking simulator-scope expenses
 *
 * Embedded inside cSimulatorImpl in the +0xB4..+0x174 tail region as one or
 * more ExpenseReport-shaped arrays (per legacy comment). Total tail span 192B.
 *
 * Method:
 *   reset() — zeroes m_data in reverse order (offset+0x1C down to base).
 * ========================================================================== */
struct ExpenseReport {
    /* 0x00 */ u32 m_data[8];   /* 8 category counters */
    /* 0x20 */ u32 m_header;    /* 9th element implied by 36B total */

    void reset(void);
};

/* ============================================================================
 * cSimulator — abstract base for the game simulator
 *
 * Size: 0x08 bytes (vtable + one ptr per legacy).
 *
 * Singleton lifecycle:
 *   static cSimulator* CreateInstance(void);
 *   static void        DestroyInstance(cSimulator*);
 * ========================================================================== */
class cSimulator {
public:
    typedef s32 tFundsPlayerNumber;

    /* Game-mode enum (concrete values 0-3 per legacy; real semantic names
     * not yet recovered — likely Live/Build/Buy/Pause or similar) */
    enum Mode {
        MODE_0 = 0,
        MODE_1 = 1,
        MODE_2 = 2,
        MODE_3 = 3,
    };

    /* 0x00 */ void* m_vtable;   /* primary vtable @ +0x00 (standard C++ shape;
                                     cSimulator does NOT use SN-style vtable-at-
                                     end-of-head — unlike Interactor/cXObjectImpl) */
    /* 0x04 */ void* m_field04;  /* singleton-relevant ptr (legacy notes a 2nd
                                     word; precise field TBD) */
    /* total 0x08 */

    static cSimulator* CreateInstance(void);
    static void        DestroyInstance(cSimulator* sim);

    virtual ~cSimulator(void);
};

/* ============================================================================
 * cSimulatorImpl — full simulator implementation (cSimulator subclass)
 *
 * Size: 0x180 (384 bytes) per legacy. ~40 documented offsets cover speed/
 * pause/time, funds/expenses, mode, lot+arch+objects value, lighting, GBA
 * link, sim-loop probes, and stall counters.
 *
 * Confidence: [L] mostly legacy — verify-pass commits land as agent/ stubs
 * convert. Mark [V] in-place when a SEMANTIC match confirms an offset.
 * ========================================================================== */
class cSimulatorImpl : public cSimulator {
public:
    /* 0x04..0x33 — opaque (legacy notes m_globals[N] short array @ +0x14
     * indexed via SetGlobal/GetGlobal, but the precise extent isn't
     * verified per-element). The "Mode" enum value also lives in this
     * region (m_mode @ +0x3a). */
    /* 0x04 */ u8     _pad04[0x30];

    /* ------ Speed / pause control ------ */
    /* 0x34 */ s16    m_speed;
    /* 0x36 */ s16    m_pauseCount;
    /* 0x38 */ u8     _pad38[0x02];
    /* 0x3A */ s16    m_mode;             /* cSimulator::Mode value */
    /* 0x3C */ u8     _pad3C[0x10];

    /* ------ Day / time tracking ------ */
    /* 0x4C */ s16    m_daysRunning;
    /* 0x4E */ u8     _pad4E[0x08];

    /* ------ Asset value tracking (split into low/high halves) ------ */
    /* 0x56 */ s16    m_objectsValLow;
    /* 0x58 */ s16    m_objectsValHigh;
    /* 0x5A */ s16    m_archValLow;
    /* 0x5C */ s16    m_archValHigh;

    /* 0x5E */ s16    m_pauseTimer;
    /* 0x60 */ u8     _pad60[0x08];

    /* ------ Lighting state ------ */
    /* 0x68 */ u16    m_lightingFlags;    /* bits 0-8 intensity, bit 9 strobe */

    /* ------ GBA link state (Sims 2 GC/GBA cross-platform feature) ------ */
    /* 0x6A */ s16    m_gbaStatus;
    /* 0x6C */ s16    m_gbaMoney;
    /* 0x6E */ s16    m_gbaNumMinigames;

    /* 0x70 */ u8     _pad70[0x04];       /* possibly m_timerHours/Minutes per
                                              legacy +0x70/+0x72 comment */

    /* ------ Funds + ticks ------ */
    /* 0x74 */ s32    m_funds;
    /* 0x78 */ s32    m_pendingFunds;
    /* 0x7C */ s32    m_ticks;
    /* 0x80 */ s32    m_postSecondOfDay;

    /* ------ Aggregated values ------ */
    /* 0x84 */ s32    m_lotValue;
    /* 0x88 */ s32    m_objectsValue;
    /* 0x8C */ s32    m_archValue;
    /* 0x90 */ u8     _pad90[0x04];

    /* ------ Sim loop probe (instrumentation hook) ------ */
    /* 0x94 */ SimLoopProbe* m_probe;

    /* ------ Stall tracking ------ */
    /* 0x98 */ s32    m_stalledCount;
    /* 0x9C */ s32    m_pauseStallCount;

    /* ------ Dt + speed scaling ------ */
    /* 0xA0 */ f32    m_accumulator;
    /* 0xA4 */ f32    m_dtOverride;
    /* 0xA8 */ f32    m_speedMultiplier;
    /* 0xAC */ /* legacy notes m_timerAccum @ +0xAC + m_timerTarget @ +0xB0
                  but they overlap the _padAC opaque tail below — promote
                  when matched evidence surfaces */
    /* 0xAC */ u8     _padAC[0xC8];       /* expense data + tail (ExpenseReport
                                              arrays nest here per legacy) */

    /* 0x174 */ SimLoopProbe* m_passiveInfluence;
    /* 0x178 */ s32    m_stopFlag;
    /* 0x17C */ s32    m_updateFlag;
    /* total 0x180 */
};

/* ============================================================================
 * Vtable slot index — observed slots used by writers
 *
 * SN ProDG vtable layout (used by both SI and MI emissions):
 *   each slot is 8 bytes: { s16 top_offset; s16 _pad; void* fnptr; }
 *   slot N base address inside vtable = N * 8 = 0x008*N (decimal: 8N)
 *
 * **Slot 39 (vtable offset 0x138 / 0x13C) — no-args verb method.**
 * Sites observed:
 *   - cXPersonImpl::CheckFirstPlayerForFailedSocialModeEntry @ 0x8012B8CC
 *     calls slot 39 on m_simulator (= this+0x3F4 cSimulator*).
 *   - cXPersonImpl::CheckSecondPlayerForFailedSocialModeEntry @ 0x8012B978
 *     calls slot 39 on a different register-source object — could be
 *     another cSimulator-shaped instance (player 2's simulator?), or a
 *     sibling class that shares vtable layout. Cross-evidence wanted.
 * Candidate semantic names from PersonSlayer's analysis:
 *   OnSocialModeFailed / BumpFailureCounter / OnFirstPlayerFailed
 * Treat as placeholder `// SLOT39: void Method(void)` until cross-evidence
 * locks the name. Add the real name here when a sibling site disambiguates.
 *
 * Caveat: slot 39 is FAR into the vtable (39 vmethods). cSimulator/
 * cSimulatorImpl as documented in the legacy header has maybe 4-5
 * virtuals. The full vmethod surface is much richer than the legacy
 * enumerates — expect more vtable slots to surface as writers crack
 * additional cSimulator-touching functions.
 * ========================================================================== */

/* ============================================================================
 * Free function
 * ========================================================================== */
extern "C" int BeingReset(void);

/* ============================================================================
 * Sample matched method prototypes (cSimulatorImpl small accessors — many
 * already SEMANTIC-converted in src/matched/csimulatorimpl/ if that
 * directory exists; otherwise present as ASMPROC stubs in agent/)
 *
 * Use these to cross-reference when converting; full roster comes from
 * `grep cSimulatorImpl:: extracted/files/u2_ngc_release.map`.
 * ========================================================================== */
extern "C" void f_simAccessors_placeholder(void); /* see git map for actual VAs */

#endif /* SIMS2_TYPES_SIMULATOR_H */
