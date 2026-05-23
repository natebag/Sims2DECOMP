/* include/types/SAnimator2.h — canonical class layout for SAnimator2
 *
 * S17 TypeArchaeologist Phase 1 deliverable #7.
 *
 * Provenance: ported from the mature legacy draft at
 * include/animation/sanimator2.h plus offset-verification from
 * src/matched/sanimator2/*.cpp and src/matched/agent/match_*SAnimator2*.cpp
 * (180+ matched stubs for this class).
 *
 * Inheritance: SAnimator2 : public SAnimator (single inheritance).
 * Vtable layout (primary) is at offset 0x00 from this.
 *
 * Confidence:
 *   [V]  verified by ≥1 SEMANTIC-style matched .cpp in src/matched/sanimator2/
 *   [LV] verified by legacy include/animation/sanimator2.h + cross-checked
 *        against matched stubs
 *   [L]  legacy draft, not yet matched but consistent with stub addresses
 */
#ifndef SIMS2_TYPES_SANIMATOR2_H
#define SIMS2_TYPES_SANIMATOR2_H

#include "../types.h"

/* Forward decls */
struct cXPerson;
struct cXObject;
struct ESim;
struct ERC;
struct EShader;
struct E3DWindow;
struct EACTrack;
struct ERAnim;
struct AnimRef;
struct PropRef;
struct ReconBuffer;
struct StackElem;
struct TileList;
struct CTilePt;
struct EAnimNote;
struct REffectsAttachment;
struct RumbleDataElement;
struct CameraBloomDataElement;
struct CameraBlurDataElement;
struct AnimParticleData;
struct IdleAnimateParam;
struct AnimateNewParam;
struct CasSimDescriptionS2C;
struct EBoneParticle;
struct AwarenessManager;
struct EHeadOrient;

/* Local float-EVec3 to match SAnimator2's animation-space coordinates.
 * Distinct from the int-EVec3 used by ISimsObjectModel (see comment in
 * include/types/ISimsObjectModel.h). */
struct SANIM_EVec3 {
    /* 0x0 */ float x;
    /* 0x4 */ float y;
    /* 0x8 */ float z;
};

/* ============================================================================
 * SAnimator2 — primary sim animation controller
 *
 * Size: at least 0x654 bytes (m_savedPauseMultiplier @ +0x650 + 4 = 0x654).
 * ========================================================================== */
struct SAnimator2 {
    /* 0x000 */ void*               m_vtable;             /* [LV] vtable */
    /* 0x004 */ cXPerson*           m_pPerson;            /* [LV] */
    /* 0x008 */ ESim*               m_pSim;               /* [LV] */
    /* 0x00C */ u8                  _pad00C[0x04];
    /* 0x010 */ s32                 m_followState;        /* [L] */
    /* 0x014 */ u8                  _pad014[0x04];
    /* 0x018 */ s32                 m_followMode;         /* [L] */
    /* 0x01C */ SANIM_EVec3         m_pos;                /* [L]  +0x1C..+0x27 */
    /* 0x028 */ u8                  _pad028[0x04];
    /* 0x02C */ s32                 m_animState;          /* [L] */
    /* 0x030 */ float               m_animDirection;      /* [L] */
    /* 0x034 */ u8                  _pad034[0x7C];
    /* 0x0B0 */ s32                 m_desiredAnimState;   /* [L] */
    /* 0x0B4 */ u8                  _pad0B4[0x04];
    /* 0x0B8 */ float               m_cameraZoomRatio;    /* [L] */
    /* 0x0BC */ u8                  _pad0BC[0x0C];
    /* 0x0C8 */ s32                 m_skillTrackIndex;    /* [L] */
    /* 0x0CC */ u8                  _pad0CC[0x04];
    /* 0x0D0 */ float               m_blendTime;          /* [L] */
    /* 0x0D4 */ AnimRef*            m_currentAnimRef;     /* [L] */
    /* 0x0D8 */ u8                  _pad0D8[0x04];
    /* 0x0DC */ s32                 m_prevTick;           /* [L] */
    /* 0x0E0 */ s32                 m_currentTick;        /* [L] */
    /* 0x0E4 */ u8                  _pad0E4[0x18];
    /* 0x0FC */ float               m_timeMultiplier;     /* [L] */
    /* 0x100 */ float               m_desiredTimeMultiplier; /* [L] */
    /* 0x104 */ float               m_pauseMultiplier;    /* [L] */
    /* 0x108 */ u8                  _pad108[0x18];
    /* 0x120 */ s32                 m_idleInitialized;    /* [L] */
    /* 0x124 */ u8                  _pad124[0x0C];
    /* 0x130 */ s32                 m_lastCostume;        /* [L] */
    /* 0x134 */ u8                  _pad134[0x4C];
    /* 0x180 */ u8                  m_headOrient[0x78];   /* [L] EHeadOrient blob */
    /* 0x1F8 */ u8                  _pad1F8[0x400];
    /* 0x5F8 */ s8                  m_portalMode;         /* [V] GetPortalMode 0x800690F8 */
    /* 0x5F9 */ u8                  _pad5F9[0x0B];
    /* 0x604 */ CasSimDescriptionS2C* m_pNormalSimDescription; /* [L] */
    /* 0x608 */ u8                  _pad608[0x04];
    /* 0x60C */ s32                 m_boneIndices[4];     /* [V] SetBoneIndex 0x80069194,
                                                              GetBoneIndex 0x800691C4 */
    /* 0x61C */ u32                 m_flags;              /* [V] GetPlayerControl 0x80069114
                                                              bit 0 = PlayerControl;
                                                              other bits per legacy draft */
    /* 0x620 */ u8                  m_awarenessMgr[0x1C]; /* [L] AwarenessManager blob */
    /* 0x63C */ cXObject*           m_pAwareOfObject;     /* [L] */
    /* 0x640 */ u8                  _pad640[0x10];
    /* 0x650 */ float               m_savedPauseMultiplier; /* [L] */
    /* total 0x654 known */
};

/* IsStalled (0x80069174) does NOT touch `this` — it reads an SDA global flag.
 * So "stalled" is a global state, not a per-instance one. Documented here so
 * writers don't add a phantom m_isStalled field. */

/* ============================================================================
 * Statics + free helpers (sanimator2.obj scope)
 * ========================================================================== */
extern "C" int    SAnimator2_m_pendingCount;
extern "C" float* SAnimator2_m_DualArmCarryIndexArray;

/* ============================================================================
 * Function prototypes (subset — there are 180+ matched files; see
 * src/matched/sanimator2/ and src/matched/agent/match_*SAnimator2*.cpp
 * for the full set)
 * ========================================================================== */

/* Lifecycle */
extern "C" void f_800A04FC(void); /* SAnimator2::SAnimator2(void)              */
extern "C" void f_80069038(void); /* operator new(u32)                         */
extern "C" void f_8006908C(void); /* operator delete(void*)                    */

/* State getters (all small, mostly already SEMANTIC in src/matched/sanimator2/) */
extern "C" void f_800690F8(void); /* GetPortalMode() — m_portalMode @ +0x5F8   */
extern "C" void f_80069114(void); /* GetPlayerControl() — m_flags @ +0x61C b0  */
extern "C" void f_80069174(void); /* IsStalled() — reads SDA global, NOT this  */
extern "C" void f_80069194(void); /* SetBoneIndex(int, int) — m_boneIndices    */
extern "C" void f_800691C4(void); /* GetBoneIndex(int) — m_boneIndices         */
extern "C" void f_800691F4(void); /* IsRouting()                               */
extern "C" void f_80069208(void); /* IsDirectControlEnabled()                  */
extern "C" void f_800689F4(void); /* SetIdleInitialized(bool)                  */
extern "C" void f_80068fbc(void); /* SetPlayerControl(bool)                    */
extern "C" void f_800689fc(void); /* UpdateAnimationValidity()                 */
extern "C" void f_800608DC(void); /* GetTurnRate()                             */

/* Anim playback / state */
extern "C" void f_8005C78C(void); /* Render(int)                               */
extern "C" void f_8005D014(void); /* adjustAnimationPlayRates()                */
extern "C" void f_8005D124(void); /* SnapToGrid()                              */
extern "C" void f_8005D130(void); /* ForceLocation()                           */
extern "C" void f_8005ED9C(void); /* IsFollowing()                             */
extern "C" void f_80066940(void); /* stopCurAnim(bool)                         */
extern "C" void f_80066F00(void); /* lockHandsUpCarryNodes()                   */
extern "C" void f_80066F40(void); /* lockCarryArmNodes(float*, EACTrack*)      */
extern "C" void f_80066F80(void); /* lockCarryArmNodes(float*, int trackFlags) */
extern "C" void f_800677B0(void); /* PropsHaveAlpha()                          */

/* Particles + events */
extern "C" void f_8005c87c(void); /* checkParticleCleanup()                    */
extern "C" void f_80065ff4(void); /* cleanupParticlesDelayed(...)              */
extern "C" void f_80066054(void); /* cleanupParticlesImmediate(...)            */
extern "C" void f_800661d8(void); /* playRumble(...)                           */
extern "C" void f_8006634c(void); /* triggerCameraBloom(char*)                 */
extern "C" void f_800663A0(void); /* triggerCameraBloom(CameraBloomDataElement*) */
extern "C" void f_800663e8(void); /* triggerCameraBlur(char*)                  */
extern "C" void f_80066470(void); /* footstepEvent(char*)                      */

/* Movement state */
extern "C" void f_8005cc2c(void); /* updateMovementState()                     */
extern "C" void f_80069A14(void); /* defaultVelocity(int)                      */
extern "C" void f_80069A8C(void); /* getAnimDuration(ERAnim*)                  */
extern "C" void f_8006A3AC(void); /* getIsLeftFootUp()                         */
extern "C" void f_8006A69C(void); /* GetMovementVelocityFromStyle(eWalkRunStyle) */
extern "C" void f_8006C850(void); /* StartAutoRun(float)                       */
extern "C" void f_800692E4(void); /* EndAutoRun()                              */

/* Idle */
extern "C" void f_8006BFE8(void); /* stopIdleOverlay()                         */
extern "C" void f_80064750(void); /* LoadOptionalIdleAnim()                    */
extern "C" void f_8006491C(void); /* UnloadOptionalIdleAnim()                  */
extern "C" void f_80064B2C(void); /* UnloadSMOptionalMotionAnims()             */
extern "C" void f_80064c18(void); /* CheckOptionalMotionAnimStatusOnStateChange(eAnimState) */

/* Carry */
extern "C" void f_80069470(void); /* clearSuspendedCarry()                     */
extern "C" void f_800679E8(void); /* DrawPropsShadow(ERC*)                     */
extern "C" void f_8005f7e0(void); /* PreloadDress(PropRef*)                    */
extern "C" void f_80067ABC(void); /* removeAllProps()                          */
extern "C" void f_800676E4(void); /* removeCostume()                           */

#endif /* SIMS2_TYPES_SANIMATOR2_H */
