/* include/types/EAnimController.h — canonical layout for EAnimController +
 *                                    EACTrack
 *
 * S17 TypeArchaeologist Phase 1 deliverable #8.
 *
 * Provenance: ported from the mature legacy draft at
 * include/EAnimController.h plus offset-verification from src/matched/
 * eanimcontroller/*.cpp and src/matched/agent/match_*EAnimController*.cpp
 * (110+ matched files). SetTrackBlendSmooth (0x802EE324) is a fully
 * SEMANTIC-style match and the most-cited evidence source for EACTrack
 * field offsets.
 *
 * Position-in-ESim: ESim+0x334 (= 820 decimal) is an embedded EAnimController.
 * SonnetWorker1 confirmed this in typereq:EAnimController (info board); the
 * legacy include/animation/sanimator2.h ESim class also documents the same.
 */
#ifndef SIMS2_TYPES_EANIMCONTROLLER_H
#define SIMS2_TYPES_EANIMCONTROLLER_H

#include "../types.h"

/* Forward decls */
struct EACTrack;
struct EACNodeState;
struct EACTrackStreams;
struct EACEventRange;
struct EAnimNodeDataPos;
struct ERAnim;
struct ERCharacter;
struct ERC;
struct ERModel;
struct ECharacterNode;
struct EMat4;
struct EBound3;

/* Local float-EVec3 (matches sanimator2 + eanim coord space; distinct from
 * the int-EVec3 used by ISimsObjectModel). */
struct EAC_EVec3 {
    /* 0x0 */ float x;
    /* 0x4 */ float y;
    /* 0x8 */ float z;
};

/* Animation track flag bitfield — used to identify tracks. Concrete enum
 * values not yet recovered; treat as opaque bitfield. */
enum eTrackFlags { eTrackFlags_OPAQUE = 0 };
enum eAnimatedObjectType { eAnimatedObjectType_OPAQUE = 0 };

/* ============================================================================
 * EACTrack — a single animation track slot
 *
 * Layout from SEMANTIC-style match at 0x802EE324 (SetTrackBlendSmooth):
 *   0x0E  u8  m_status              (smooth-blend status indicator)
 *   0x54  f32 m_field_54
 *   0x58  f32 m_field_58
 *   0x64  f32 m_field_64            (current blend value)
 *   0x68  f32 m_field_68
 *   0xA0  u8  m_byte_A0             (set to 2 for smooth-blend mode)
 *   0xA8  s32 m_field_A8            (active flag; SetTrackBlendSmooth checks == 1)
 *
 * Legacy include/EAnimController.h documents additional logical names
 * (m_trackId, m_intensity, m_blend, m_phase, m_speed, m_frame, m_anim) at
 * offsets 0x04..0x024 but those have NOT been individually verified by
 * matched code yet — left here as commented hints, not as field decls.
 * ========================================================================== */
struct EACTrack {
    /* 0x00 */ void*           m_vtable;
    /* 0x04 */ u8              _pad04[0x0A];
    /* 0x0E */ u8              m_status;          /* SetTrackBlendSmooth check */
    /* 0x0F */ u8              _pad0F[0x45];
    /* 0x54 */ float           m_field_54;
    /* 0x58 */ float           m_field_58;
    /* 0x5C */ u8              _pad5C[0x08];
    /* 0x64 */ float           m_field_64;        /* current blend value */
    /* 0x68 */ float           m_field_68;
    /* 0x6C */ u8              _pad6C[0x34];
    /* 0xA0 */ u8              m_byte_A0;         /* smooth-blend marker */
    /* 0xA1 */ u8              _padA1[0x07];
    /* 0xA8 */ s32             m_field_A8;        /* active flag (== 1) */
    /* 0xAC */ u8              _padTail[0x40];    /* opaque tail */
};

/* ============================================================================
 * EAnimController — animation controller, embedded in ESim at +0x334
 *
 * Layout sketch (legacy include/EAnimController.h, partially verified):
 *   0x00  vtable
 *   0x08  EACTrack* m_tracks         (array)
 *   0x0C  s32       m_numTracks
 *   0x10  s32       m_maxTracks
 *   0x18  eAnimatedObjectType m_objectType
 *   0x20  EACNodeState* m_nodeStates (array)
 *   0x24  s32       m_numNodes
 *   0x28  s32       m_maxNodes
 *   0x2C  EMat4*    m_matrices
 *   0x30  s32       m_numMatrices
 *   0x38  float     m_animTime
 *   0x3C  float     m_animSpeed
 *   0x40  float     m_blendFactor
 *   0x48  float     m_trackIntensity
 *   0x4C  float     m_trackBlend
 *   0x50  float     m_blendTarget
 *   0x54  u32       m_flags
 *   0x60  void*     m_eventRanges
 *   ... opaque tail extending to ~0x400 ...
 *
 * Most of these are NOT individually verified by matched code (the matched
 * EAnimController methods are mostly ASMPROC stubs without semantic source).
 * Treat as best-effort scaffolding pending future verification.
 * ========================================================================== */
struct EAnimController {
    /* 0x00 */ void*           m_vtable;
    /* 0x04 */ void*           m_field_04;
    /* 0x08 */ EACTrack*       m_tracks;
    /* 0x0C */ s32             m_numTracks;
    /* 0x10 */ s32             m_maxTracks;
    /* 0x14 */ void*           m_field_14;
    /* 0x18 */ s32             m_objectType;
    /* 0x1C */ u32             m_field_1C;
    /* 0x20 */ EACNodeState*   m_nodeStates;
    /* 0x24 */ s32             m_numNodes;
    /* 0x28 */ s32             m_maxNodes;
    /* 0x2C */ EMat4*          m_matrices;
    /* 0x30 */ s32             m_numMatrices;
    /* 0x34 */ void*           m_field_34;
    /* 0x38 */ float           m_animTime;
    /* 0x3C */ float           m_animSpeed;
    /* 0x40 */ float           m_blendFactor;
    /* 0x44 */ s32             m_field_44;
    /* 0x48 */ float           m_trackIntensity;
    /* 0x4C */ float           m_trackBlend;
    /* 0x50 */ float           m_blendTarget;
    /* 0x54 */ u32             m_flags;
    /* 0x58 */ s32             m_isSuspended;
    /* 0x5C */ s32             m_isActive;
    /* 0x60 */ void*           m_eventRanges;
    /* 0x64 */ s32             m_numEventRanges;
    /* 0x68 */ u8              _padTail[0x398];   /* opaque tail to ~0x400 */
};

/* ============================================================================
 * Function prototypes — matched EAnimController methods
 * (110+ files total; full list under src/matched/agent/ and
 *  src/matched/eanimcontroller/)
 * ========================================================================== */

/* Lifecycle */
extern "C" void f_802E77A4(void); /* EAnimController::EAnimController(void)    */
extern "C" void f_802E7884(void); /* ~EAnimController()                        */
extern "C" void f_802E78E4(void); /* Deallocate(void)                          */
extern "C" void f_802E79F4(void); /* DeallocateNodes(void)                     */
extern "C" void f_802E7AC8(void); /* Init(u32, eAnimatedObjectType, u32)       */
extern "C" void f_802E7EF4(void); /* Init(char*, eAnimatedObjectType, u32)     */
extern "C" void f_802E7F40(void); /* Shutdown(void)                            */
extern "C" void f_802E7F60(void); /* IsTrackValid(eTrackFlags)                 */

/* Track suspend/resume/stop */
extern "C" void f_802E80A0(void); /* SuspendTrack(EACTrack*)                   */
extern "C" void f_802E80C4(void); /* SuspendTrack(eTrackFlags)                 */
extern "C" void f_802E820C(void); /* ResumeTrack(eTrackFlags)                  */
extern "C" void f_802EC038(void); /* DeactivateTrack(EACTrack*)                */
extern "C" void f_802EC5A0(void); /* StopTrack(eTrackFlags)                    */
extern "C" void f_802EBFD8(void); /* StopAllTracks(void)                       */
extern "C" void f_802EC198(void); /* CreateStreams(EACTrack*)                  */
extern "C" void f_802EC6E8(void); /* TransferTrack(eTrackFlags, eTrackFlags)   */

/* Blend control */
extern "C" void f_802EE17C(void); /* SetTrackBlend(EACTrack*, float)           */
extern "C" void f_802EE1DC(void); /* SetTrackBlend(eTrackFlags, float)         */
extern "C" void f_802EE324(void); /* SetTrackBlendSmooth(EACTrack*, f, f, f)
                                   * **SEMANTIC-style match** — primary
                                   * evidence source for EACTrack layout. */
extern "C" void f_802EE390(void); /* SetTrackBlendSmooth(eTrackFlags, ...)     */
extern "C" void f_802EE4D8(void); /* SetTrackBlendHermiteSafe(EACTrack*, ...)  */
extern "C" void f_802EE4F8(void); /* SetTrackBlendHermiteSafe(eTrackFlags, ...) */
extern "C" void f_802EE6F8(void); /* SetTrackBlendHermite(eTrackFlags, ...)    */
extern "C" void f_802EF214(void); /* SetTrackBlendFactors(EACTrack*, float*)   */
extern "C" void f_802EF230(void); /* SetTrackBlendFactors(eTrackFlags, float*) */

/* Pos/Phase/Frame */
extern "C" void f_802EEA60(void); /* SetTrackPhaseLock(EACTrack*, EACTrack*, f)*/
extern "C" void f_802EEAFC(void); /* SetProceduralTrack(eTrackFlags, ...)      */
extern "C" void f_802EEEC0(void); /* SetTrackPhase(eTrackFlags, float)         */
extern "C" void f_802EF040(void); /* SetTrackFrame(eTrackFlags, float)         */
extern "C" void f_802EF7B8(void); /* SetTrackPos(EACTrack*, float, bool)       */
extern "C" void f_802EF820(void); /* SetTrackPos(eTrackFlags, float, bool)     */
extern "C" void f_802EF62C(void); /* GetTrackPos(eTrackFlags)                  */
extern "C" void f_802EF374(void); /* GetTrackFrameCount(eTrackFlags)           */
extern "C" void f_802EF4DC(void); /* GetTrackFrame(eTrackFlags)                */
extern "C" void f_802EED14(void); /* RestartTrack(eTrackFlags)                 */

/* Speed / intensity */
extern "C" void f_802EDBF0(void); /* SetAllTrackIntensities(float)             */
extern "C" void f_802EDDCC(void); /* GetTrackIntensity(eTrackFlags)            */
extern "C" void f_802EDF1C(void); /* GetTrackSpeed(eTrackFlags)                */
extern "C" void f_802EFD44(void); /* SetTrackSpeed(EACTrack*, float)           */
extern "C" void f_802EFD88(void); /* SetTrackSpeed(eTrackFlags, float)         */
extern "C" void f_802EFED0(void); /* SetAllTrackSpeed(float)                   */

/* Track queries */
extern "C" void f_802ED7EC(void); /* SetTrackAnim(eTrackFlags, ...)            */
extern "C" void f_802EC990(void); /* GetTrackAnimId(eTrackFlags)               */
extern "C" void f_802ED840(void); /* GetTrackAnimName(eTrackFlags)             */
extern "C" void f_802EFC08(void); /* GetTrackAnimDef(eTrackFlags)              */
extern "C" void f_802EDC70(void); /* GetTrackBlendTarget(eTrackFlags)          */
extern "C" void f_802EF968(void); /* IsTrackAnimComplete(eTrackFlags)          */
extern "C" void f_802EFAC0(void); /* ClearTrackAnimComplete(eTrackFlags)       */
extern "C" void f_802E9B68(void); /* GetFirstRelevantTrack(void)               */

/* Animation translate/time/velocity */
extern "C" void f_802E94A8(void); /* GetAnimDistance(eTrackFlags)              */
extern "C" void f_802E94D8(void); /* GetAnimTrans(eTrackFlags, EVec3&)         */
extern "C" void f_802E9410(void); /* GetSlavePos(EACTrack*, EACTrack*)         */
extern "C" void f_802E96A8(void); /* GetAnimTranslate(eTrackFlags, ...)        */
extern "C" void f_802E9960(void); /* GetAnimTime(eTrackFlags)                  */
extern "C" void f_802E9B04(void); /* GetAnimVelocity(eTrackFlags, EVec3&)      */

/* Compute / animate */
extern "C" void f_802E83EC(void); /* Update(EVec3*, EVec3*, EVec3)             */
extern "C" void f_802E8864(void); /* ProcessEvents(...)                        */
extern "C" void f_802E89EC(void); /* AddEventRange(...)                        */
extern "C" void f_802E8A58(void); /* UpdateTrack(EACTrack*, ...)               */
extern "C" void f_802E9C24(void); /* AnimateTrack(EACTrack*, ...)              */
extern "C" void f_802E9CDC(void); /* Compute(EMat4&, int)                      */
extern "C" void f_802EA128(void); /* AllocMatrices(void)                       */
extern "C" void f_802EA1DC(void); /* ComputeInverse(EMat4&, int)               */
extern "C" void f_802EA28C(void); /* PrepareForCollision(...)                  */
extern "C" void f_802EA2CC(void); /* PostMultNodeAndDescendents(int, EMat4&)   */
extern "C" void f_802EA404(void); /* PreMultNodeAndDescendents(int, EMat4&)    */
extern "C" void f_802EA53C(void); /* CalcTightBoundBox(EMat4&, EBound3&, ...)  */
extern "C" void f_802EA698(void); /* FixAccumulationForRootNode(EACTrack*)     */
extern "C" void f_802EAD18(void); /* Animate(EACTrack*, EACNodeState*)         */
extern "C" void f_802EB1B0(void); /* Blend(float, EACNodeState&, ...)          */
extern "C" void f_802EB340(void); /* Layer(float, EACNodeState&, ...)          */
extern "C" void f_802EB53C(void); /* CallbackICM(...)                          */
extern "C" void f_802EB570(void); /* ComputeMatrices(EMat4&)                   */
extern "C" void f_802F03B4(void); /* Draw(ERC*)                                */

/* Node accessors */
extern "C" void f_802F055C(void); /* CalcNodeMatrix(int)                       */
extern "C" void f_802F0678(void); /* GetNodeMatrix(int)                        */
extern "C" void f_802F0700(void); /* CalcNodeOrientWithoutLocalRot(int)        */
extern "C" void f_802F085C(void); /* CalcNodeOrient(int)                       */
extern "C" void f_802F0A30(void); /* SetNodeIgnoreAnimatedVisibility(int)      */
extern "C" void f_802F0A8C(void); /* SetNodeVisible(int)                       */
extern "C" void f_802F0AE8(void); /* SetTrackActive(EACTrack*, bool)           */
extern "C" void f_802EFF38(void); /* VisibilityTest(EMat4)                     */
extern "C" void f_803C357C(void); /* GetNonMainTrackFlagFromIndex(int)         */
extern "C" void f_802F0300(void); /* GetAnimRootNodeTrans(EACTrack*)           */
extern "C" void f_802E9C0C(void); /* PrintTracks(void)                         */

#endif /* SIMS2_TYPES_EANIMCONTROLLER_H */
