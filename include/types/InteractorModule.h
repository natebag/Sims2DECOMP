/* include/types/InteractorModule.h — canonical layout for the
 *                                     InteractorModule namespace
 *
 * S18 TypeArchaeologist deliverable #16. Opportunistic legacy promotion
 * via 3-file merge of mature drafts:
 *   - include/build_mode/interactor.h
 *       (Interactor base + DirectInteractor/SimInteractor/SocialModeInteractor +
 *        FadeSquare + InteractorManager + ObjectManipulator/GrabManipulator/
 *        PlaceManipulator + PlacementObject)
 *   - include/build_mode/wallmanipulator.h
 *       (WallManipulator + WallPainter + FloorPainter)
 *   - include/classes/InteractorModule.h
 *       (InteractorModule namespace-level module class itself — 98 fields
 *        documented from assembly analysis)
 *
 * All three live in legacy include/ subdirectories; merging into a single
 * canonical types header gives writers one #include to consume the whole
 * Build-mode interactor stack.
 *
 * ============================================================================
 * Symbol-map coverage: 655 InteractorModule:: entries
 * Matched-agent inject stubs: 403 InteractorModule, 59 WallManipulator,
 *                             42 FloorPainter (= ~504 InteractorModule-family
 *                             stubs awaiting semantic conversion)
 * No SEMANTIC matches yet in src/matched/wallmanipulator/ (dir empty);
 * sub-class evidence is all in src/matched/agent/.
 *
 * Lane 7 SonnetWorker2 (xrouting/eroom/camera) is the eventual consumer once
 * its current scope closes; per MainGuy s18-routing-roadmap the WallManipulator
 * 59-stub blast is queued as the next routing opportunity.
 * ============================================================================
 *
 * Confidence legend (mostly [L] — these classes inherit mostly from legacy
 * drafts with offset evidence not yet individually verified from matched
 * .cpp asm):
 *   [V]  verified by ≥1 matched .cpp ASMPROC stub asm
 *   [L]  legacy draft offsets (need follow-up verify pass as conversions land)
 */
#ifndef SIMS2_TYPES_INTERACTORMODULE_H
#define SIMS2_TYPES_INTERACTORMODULE_H

#include "../types.h"
#include "EVec3.h"   /* canonical EVec3 + EVec2 (drops legacy locals) */

/* Forward decls — out-of-namespace types referenced by InteractorModule */
struct ESimsCam;
struct cXObject;
struct cXObjectImpl;
struct cXPerson;
struct EIObjectMan;
struct Interaction;
struct PlumbBob;
struct ERC;
struct ObjSelector;
struct ISimInstance;
struct CTilePt;
struct FTilePt;
struct TileWallsSegment;
struct DiagonalSideSelector;
template <typename T> struct TNodeList;
enum   TilePtDir { TilePtDir_OPAQUE = 0 };

namespace InteractorModule {

/* Forward decls within namespace */
class  InteractorVisualizer;
class  InteractorManager;
class  Interactor;
struct WallData;
struct WallPaperData;
struct FloorData;
struct PlacementData;
struct PatternSellCount;
struct InvStock;

/* ============================================================================
 * Input enum — controller commands surfaced by the input manager
 * (subset; legacy interactor.h covers; concrete enum values verified for
 * stick + camera axes only)
 * ========================================================================== */
class InteractorInputManager {
public:
    enum InteractorCommand {
        kCmdLeftStickX  = 7,
        kCmdLeftStickY  = 8,
        kCmdRightStickX = 11,
        kCmdRightStickY = 12,
        kCmdCameraX     = 18,
        kCmdCameraY     = 19,
    };
};

/* ============================================================================
 * Small POD value types used across the namespace
 * ========================================================================== */
struct InteractorInfo {
    /* 0x00 */ f32 posX;
    /* 0x04 */ f32 posY;
    /* 0x08 */ u32 field_08;
    /* 0x0C */ u32 field_0C;
};

/* ============================================================================
 * Interactor — base class for all per-player input handlers
 *
 * IMPORTANT LAYOUT NOTE: vtable pointer is at offset +0x5C, NOT +0x00.
 * This is the SN ProDG "vtable-at-end-of-head" convention also seen in
 * cXObjectImpl (+0xEC) and ESimsCam (+0x56C). When constructing Interactor
 * instances, the vtable assignment is the LAST thing the ctor does, after
 * all m_* state has been initialized.
 *
 * Total head size: 0x60 bytes (derived classes' state starts at +0x60).
 * ========================================================================== */
class Interactor {
public:
    /* 0x00 */ u32         m_playerId;
    /* 0x04 */ ESimsCam*   m_camera;
    /* 0x08 */ EVec3       m_pos;             /* current world pos */
    /* 0x14 */ EVec3       m_prevPos;         /* prev frame pos (updated from m_pos) */
    /* 0x20 */ EVec3       m_snappedPos;      /* set by SnapToPos */
    /* 0x2C */ u32         m_snapped;         /* bool: is m_snappedPos current */
    /* 0x30 */ u32         m_inputState;
    /* 0x34 */ EVec2       m_leftStick;
    /* 0x3C */ EVec2       m_rightStick;
    /* 0x44 */ u32         m_leftStickActive;
    /* 0x48 */ u32         m_rightStickActive;
    /* 0x4C */ u32         m_drawState;
    /* 0x50 */ EVec2       m_extents;
    /* 0x58 */ f32         m_idleTime;
    /* 0x5C */ void*       m_vtable;          /* SN-style: vtable at end of head */
    /* total head size 0x60 */

    /* Nested types used by sub-class callbacks (offsets evidenced by
     * src/matched/agent/match_*Callback*.cpp passing CallbackData* as r4). */
    struct CallbackData {
        /* 0x00 */ u32 state;
        /* 0x04 */ u32 field_04;
        /* 0x08 */ u32 field_08;            /* often a callback offset */
        /* 0x0C */ u32 field_0C;            /* often a callback fnptr  */
    };

    struct InteractorParams {
        /* 0x00 */ u32 field_00;
        /* 0x04 */ u32 playerId;
        /* 0x08 */ u32 field_08;            /* callback offset */
        /* 0x0C */ u32 field_0C;            /* callback fnptr  */
    };

    enum   ClientNotificationState {};
    struct OverlapData {};
};

/* ============================================================================
 * DirectInteractor — direct (action-menu) input mode for an active sim
 *
 * Extends Interactor head (0x00-0x5F = 96B). Own state begins at +0x60.
 * ========================================================================== */
class DirectInteractor : public Interactor {
public:
    /* 0x60 */ u32         m_field_60;
    /* 0x64 */ u32         m_controlStatus;
    /* 0x68 */ u32         m_field_68;
    /* 0x6C */ u32         m_exitDirectControl;
    /* 0x70 */ cXObject*   m_targetObject;
    /* 0x74 */ u32         m_field_74;
    /* 0x78 */ void*       m_interactorInfo;
    /* 0x7C */ u32         m_field_7C;
    /* 0x80 */ u32         m_isAutonomous;
    /* 0x84 */ u32         m_cancelTimerActive;
    /* 0x88 */ f32         m_cancelTimerValue;
};

/* ============================================================================
 * FadeSquare — small UI overlay used by SimInteractor (per-sim plumbbob fade)
 * ========================================================================== */
class FadeSquare {
public:
    /* 0x00 */ EVec3 m_pos;
    /* 0x0C */ u32   m_objPtr;
    /* 0x10 */ f32   m_fadeValue;
    /* 0x14 */ u32   m_fading;
    /* 0x18 */ u32   m_shouldDraw;
};

/* ============================================================================
 * SimInteractor — input mode bound to a controlled sim
 *
 * Extended layout from +0x60 not yet fully verified — leave as opaque tail.
 * (~98 method symbols imply substantial state; legacy draft did not enumerate)
 * ========================================================================== */
class SimInteractor : public Interactor {
public:
    /* 0x60.. opaque tail — sub-fields will be promoted as evidence surfaces */
};

/* ============================================================================
 * SocialModeInteractor — input mode entered when a sim is in a social action
 * ========================================================================== */
class SocialModeInteractor : public Interactor {
public:
    /* 0x60 */ s16 m_chosenActionID;
    /* 0x62 */ u16 m_pad_62;
    /* 0x64 */ u32 m_field_64;
    /* 0x68 */ u32 m_field_68;
    /* 0x6C */ u32 m_timeout;
};

/* ============================================================================
 * ObjectManipulator family — grabbing, placing, painting modes
 * (object/wall/floor manipulation Build-mode tools)
 * ========================================================================== */
class ObjectManipulator : public Interactor {
public:
    /* 0x60 */ void*           m_funcTablePtr;       /* per-mode dispatch table */
    /* 0x64 */ /* PlacementObject embedded starts here */
    /* 0xA8 */ /* m_isCursorModelEnabled (bool) */
    /* opaque tail; legacy noted +0xA8 is m_isCursorModelEnabled */
};

class GrabManipulator  : public ObjectManipulator {};
class PlaceManipulator : public ObjectManipulator {};

class WallManipulator : public Interactor {
public:
    /* 0x60 */ EVec3   m_anchorPos;
    /* 0x6C */ EVec3   m_anchorDrawPos;
    /* gap to 0xC4 — legacy draft did not enumerate intermediate fields */
    /* 0xC4 */ /* m_flags (bit field) */
    /* 0xD8 */ /* m_fenceShaderRef pointer */

    struct CallbackData { u32 field[4]; };
};

class WallPainter : public Interactor {
public:
    /* 0x60 */ EVec3   m_anchorPos;
    /* 0x6C */ EVec3   m_anchorDrawPos;
    /* 0x78 */ EVec3   m_holdPos;
    /* 0x84 */ f32     m_cursorRotationAdjustment;
    /* 0x88 */ /* m_flags */
    /* 0x90 */ /* shader ref pointer */
    /* 0x9C */ /* wall segment data */

    static f32 m_paperToolHeight;             /* static class-scoped */
};

class FloorPainter : public Interactor {
public:
    /* 0x60 */ /* m_state (byte with bit flags) */
    /* 0x64 */ EVec3   m_anchorPos;
    /* 0x94 */ /* selected floor data pointer region */
    /* 0xA4 */ /* m_isPlaceMode (0 = remove, nonzero = place) */
};

/* ============================================================================
 * PlacementObject — embedded sub-object used by Object/Grab/Place manipulators
 * (lives at ObjectManipulator+0x64 per legacy)
 * ========================================================================== */
class PlacementObject {
public:
    /* 0x00 */ u32 m_object;
    /* 0x04 */ u32 m_field_04;
    /* 0x08 */ u32 m_field_08;
    /* 0x0C */ u32 m_field_0C;
    /* 0x10 */ s16 m_direction;
    /* 0x12 */ u8  m_field_12;
    /* 0x13 */ u8  m_pad_13;
    /* 0x14 */ u32 m_field_14;
    /* 0x18 */ u32 m_field_18;
    /* 0x1C */ u32 m_field_1C;
    /* 0x20 */ u32 m_field_20;
    /* 0x24 */ u32 m_field_24;
    /* 0x28 */ u32 m_field_28;
};

/* ============================================================================
 * InteractorManager — namespace singleton (factory + lookup)
 * ========================================================================== */
class InteractorManager {
public:
    /* 0x00 */ u32 m_initialized;
    /* 0x04 */ u32 m_maxPlayers;

    /* statics */
    static InteractorManager*       GetSingleton();
    static InteractorInputManager*  GetInputManager();
    static InteractorVisualizer*    GetVisualizer();
};

/* ============================================================================
 * InteractorModule — the namespace-level MODULE class
 *
 * NOTE: name clash. This single class shares the namespace name. Field
 * layout is from legacy include/classes/InteractorModule.h (98 fields
 * documented from assembly analysis), minimum size 0x60C bytes, 90+ method
 * symbols in the map.
 *
 * Most fields not yet semantic-named — promoted as the field name "m_field_NNN"
 * (matching the legacy draft) until per-method evidence resolves a real name.
 * Field comments in legacy doc include the method-name hit list per offset
 * (e.g., DirectInteractor::CancelQueuedActions, FloorPainter::OnStart, etc.) —
 * those are preserved on the most-referenced fields below.
 * ========================================================================== */
class InteractorModule_ {  /* trailing _ to avoid C++ "class same-as-namespace" clash;
                              real-source symbol is `InteractorModule::InteractorModule`
                              if it exists, OR the namespace-scoped state lives in a
                              different containing class entirely. Treat this struct
                              as the canonical layout for the 0x60C-byte module-state
                              region documented in the legacy header. */
public:
    /* head fields (heavily-touched across many methods — see legacy doc for
     * the per-field method hit list; preserved here as comments on the
     * high-frequency-touched offsets only) */
    /* 0x000 */ f32 m_field_000;          /* CanObjectBeDestroyed, ClampPosToWorld,
                                              ConvertVertsToTiles, ... — high-freq */
    /* 0x002 */ u16 m_field_002;          /* PlacementObject::CreateGridTile */
    /* 0x004 */ f32 m_field_004;          /* CanObjectBeDestroyed, ClampPosToWorld,
                                              CheckNewSimInSocialMode, ... */
    /* 0x007 */ u8  m_field_007;          /* PlacementObject::Rotate */
    /* 0x008 */ f32 m_field_008;
    /* 0x00C */ f32 m_field_00C;
    /* 0x010 */ f32 m_field_010;
    /* 0x014 */ f32 m_field_014;
    /* 0x016 */ s16 m_field_016;          /* ObjectManipulator::Update */
    /* 0x017 */ u8  m_field_017;
    /* 0x018 */ f32 m_field_018;
    /* 0x01C */ u32 m_field_01C;
    /* 0x020 */ f32 m_field_020;
    /* 0x024 */ f32 m_field_024;
    /* 0x028 */ u32 m_field_028;          /* InteractorResourceSet::AddTexture / ClearSet / GetTexture */
    /* 0x02C */ f32 m_field_02C;
    /* 0x030 */ f32 m_field_030;
    /* 0x034 */ f32 m_field_034;
    /* 0x038 */ f32 m_field_038;
    /* 0x03C */ f32 m_field_03C;
    /* 0x040 */ f32 m_field_040;
    /* 0x044 */ u32 m_field_044;
    /* 0x048 */ f32 m_field_048;
    /* 0x04C */ f32 m_field_04C;
    /* 0x050 */ f32 m_field_050;
    /* 0x054 */ f32 m_field_054;
    /* 0x058 */ f32 m_field_058;
    /* 0x05C */ u32 m_field_05C;
    /* 0x060 */ f32 m_field_060;
    /* 0x064 */ f32 m_field_064;
    /* 0x068 */ f32 m_field_068;
    /* 0x06C */ u32 m_field_06C;
    /* 0x070 */ f32 m_field_070;
    /* 0x074 */ f32 m_field_074;
    /* 0x078 */ u32 m_field_078;
    /* 0x07C */ u32 m_field_07C;
    /* 0x080 */ u32 m_field_080;
    /* 0x084 */ f32 m_field_084;
    /* 0x088 */ u32 m_field_088;          /* WallManipulator::CommittTransaction / ctor / dtor */
    /* 0x08C */ u8  _pad_08C[4];
    /* 0x090 */ u32 m_field_090;
    /* 0x094 */ u32 m_field_094;
    /* 0x098 */ f32 m_field_098;
    /* 0x09C */ u32 m_field_09C;
    /* 0x0A0 */ f32 m_field_0A0;
    /* 0x0A4 */ f32 m_field_0A4;
    /* 0x0A8 */ u32 m_field_0A8;
    /* 0x0AC */ u32 m_field_0AC;
    /* 0x0B0 */ u32 m_field_0B0;
    /* 0x0B4 */ f32 m_field_0B4;
    /* 0x0B8 */ f32 m_field_0B8;
    /* 0x0BC */ u32 m_field_0BC;
    /* 0x0C0 */ f32 m_field_0C0;
    /* 0x0C4 */ f32 m_field_0C4;
    /* 0x0C8 */ f32 m_field_0C8;
    /* 0x0CC */ s16 m_field_0CC;
    /* 0x0CE */ u8  _pad_0CE[2];
    /* 0x0D0 */ u32 m_field_0D0;
    /* 0x0D4 */ u32 m_field_0D4;
    /* 0x0D8 */ u32 m_field_0D8;
    /* 0x0DC */ u32 m_field_0DC;
    /* 0x0E0 */ u32 m_field_0E0;
    /* 0x0E4 */ u8  _pad_0E4[0x0C];
    /* 0x0F0 */ f32 m_field_0F0;
    /* 0x0F4 */ u32 m_field_0F4;
    /* 0x0F8 */ u32 m_field_0F8;
    /* 0x0FC */ u32 m_field_0FC;
    /* 0x100 */ u32 m_field_100;
    /* 0x104 */ u32 m_field_104;
    /* 0x108 */ u8  _pad_108[4];
    /* 0x10C */ u32 m_field_10C;
    /* 0x110 */ f32 m_field_110;
    /* 0x114 */ f32 m_field_114;
    /* 0x118 */ u8  _pad_118[8];
    /* 0x120 */ u32 m_field_120;
    /* 0x124 */ u8  _pad_124[0x3C];
    /* 0x160 */ u32 m_field_160;
    /* 0x164 */ u8  _pad_164[0x18];
    /* 0x17C */ u32 m_field_17C;
    /* 0x180 */ f32 m_field_180;
    /* 0x184 */ f32 m_field_184;
    /* 0x188 */ u32 m_field_188;
    /* 0x18C */ u32 m_field_18C;
    /* 0x190 */ u32 m_field_190;
    /* 0x194 */ u32 m_field_194;
    /* 0x198 */ u32 m_field_198;
    /* 0x19C */ u32 m_field_19C;
    /* 0x1A0 */ u8  _pad_1A0[0x30];
    /* 0x1D0 */ f32 m_field_1D0;
    /* 0x1D4 */ u8  _pad_1D4[4];
    /* 0x1D8 */ f32 m_field_1D8;
    /* 0x1DC */ f32 m_field_1DC;
    /* 0x1E0 */ f32 m_field_1E0;
    /* 0x1E4 */ u8  _pad_1E4[8];
    /* 0x1EC */ f32 m_field_1EC;
    /* 0x1F0 */ u8  _pad_1F0[8];
    /* 0x1F8 */ f32 m_field_1F8;
    /* 0x1FC */ u8  _pad_1FC[8];
    /* 0x204 */ f32 m_field_204;
    /* 0x208 */ u8  _pad_208[0x0C];
    /* 0x214 */ u32 m_field_214;
    /* 0x218 */ u32 m_field_218;
    /* 0x21C */ u8  _pad_21C[8];
    /* 0x224 */ u32 m_field_224;
    /* 0x228 */ u32 m_field_228;
    /* 0x22C */ u8  _pad_22C[0x0C];
    /* 0x238 */ u32 m_field_238;
    /* 0x23C */ u8  _pad_23C[0xE4];
    /* 0x320 */ u32 m_field_320;
    /* 0x324 */ u8  _pad_324[0x8C];
    /* 0x3B0 */ u32 m_field_3B0;
    /* 0x3B4 */ u8  _pad_3B4[8];
    /* 0x3BC */ u32 m_field_3BC;
    /* 0x3C0 */ u8  _pad_3C0[0x58];
    /* 0x418 */ f32 m_field_418;
    /* 0x41C */ u8  _pad_41C[0x20];
    /* 0x43C */ f32 m_field_43C;
    /* 0x440 */ u8  _pad_440[0x1C8];
    /* 0x608 */ f32 m_field_608;
    /* total minimum 0x60C bytes — actual class size may be larger */
};

} /* namespace InteractorModule */

/* ============================================================================
 * Matched-method address index (subset — full roster is 655 InteractorModule::
 * symbols in extracted/files/u2_ngc_release.map)
 *
 * Use these for cross-referencing when converting an ASMPROC inject stub:
 *   grep for the function name in extracted/files/u2_ngc_release.map to get
 *   the byte length + decorated signature; then locate the matching
 *   src/matched/agent/match_<VA>_*.cpp file.
 * ========================================================================== */

/* InteractorModule namespace-scoped free functions (the "module API") */
extern "C" void f_805CC1B4(void); /* InitializeInteractorModule()      328B */
extern "C" void f_805CC2FC(void); /* ShutdownInteractorModule()        108B */
extern "C" void f_805CC368(void); /* GetPersonPosition(EVec3*,...)     668B */
extern "C" void f_805CC604(void); /* GetObjectPosition(EVec3*,...)     216B */
extern "C" void f_805CC6DC(void); /* SnapPositionToTile(...)           372B */
extern "C" void f_805CC850(void); /* GetCameraRelativeStickAngle(...)  532B */
extern "C" void f_805CCA64(void); /* MoveCursorAlongCameraTargetVector1196B */
extern "C" void f_805CCF10(void); /* MoveCursorOneTileAlongCameraTV   924B */
extern "C" void f_805CD2AC(void); /* ClampPosToWorld(EVec3&)           552B */
extern "C" void f_805CD4D4(void); /* IsPosOutsideWorld(EVec3&)         436B */
extern "C" void f_805CD688(void); /* GetSnapPos(int&,int&,EVec3&)      604B */
extern "C" void f_805CD8E4(void); /* GetSnapPosWithOffset(EVec3&)      224B */
extern "C" void f_805CD9C4(void); /* CreateObjectFromSelector          324B */
extern "C" void f_805CDB08(void); /* CreateObjectFromGUID(uint)        380B */
extern "C" void f_805CDC84(void); /* DestroyObject(cXObject*)          316B */
extern "C" void f_805CDDC0(void); /* CanObjectBeDestroyed              728B */
extern "C" void f_805CE098(void); /* GetCursorIntersectionObjects(...) 476B */
extern "C" void f_805CE274(void); /* GetObjectFromInt16(short)         156B */
extern "C" void f_805CE310(void); /* GetLeadObjectImpl(cXObject*)      292B */
extern "C" void f_805CE434(void); /* GetPlumbBob(int)                   84B */
extern "C" void f_805CE488(void); /* AllPlayersActiveInputInteractors  376B */
extern "C" void f_805CE600(void); /* IsObjectInRange(cXObject*)        480B */
extern "C" void f_805CF220(void); /* IsLegalToPlaceAtLocation          476B */
extern "C" void f_805CF3FC(void); /* FinalUserPlaceObject              780B */
extern "C" void f_805CF708(void); /* UpdateAllObjectsAfterPlace        488B */
extern "C" void f_805CF8F0(void); /* RecomputeLightingGrid             168B */
extern "C" void f_805CF998(void); /* SetDirection(int, cXObject*)      868B */
extern "C" void f_805CFCFC(void); /* GetObjectInstancesList            800B */
extern "C" void f_805D001C(void); /* ShadeModelToShowValidState       1648B */
extern "C" void f_805D068C(void); /* GetVisibleSideOfWall(...)        1024B */
extern "C" void f_805D0A8C(void); /* ConvertVertsToTiles(...)         2152B */
extern "C" void f_805D12F4(void); /* GetAdjacentTileCoordinates        904B */
extern "C" void f_805D167C(void); /* GetRoomIdFromPoint(CTilePt&)      900B */
extern "C" void f_805D1A00(void); /* ForcePointDir(CTilePt&, CTilePt&)1036B */
extern "C" void f_805D1E0C(void); /* EorGetAdjacentTile(...)           492B */
extern "C" void f_805D1FF8(void); /* GetInteractorResourceSet           88B */
extern "C" void f_805D2050(void); /* IsCameraDirectorInControl(int)    152B */
extern "C" void f_805D20E8(void); /* SetCameraFilter(int)              184B */
extern "C" void f_805D21A0(void); /* ClearCameraFilter(int)            168B */
extern "C" void f_805D2248(void); /* IncrementSellCountForPattern      236B */
extern "C" void f_805D2334(void); /* IncrementSellCountForObjectGuid   228B */
extern "C" void f_805D2418(void); /* CheckNewSimInSocialMode           804B */

/* InteractorModule::* sub-class lifecycle (DirectInteractor sample — full
 * coverage in src/matched/agent/match_*InteractorModule__*.cpp) */
extern "C" void f_80203D70(void); /* DirectInteractor::DirectInteractor */
extern "C" void f_80203DD0(void); /* DirectInteractor::~DirectInteractor */
extern "C" void f_80203E04(void); /* DirectInteractor::OnCreate */

/* Cross-class callbacks (CallbackData consumers) */
extern "C" void f_802F5E98(void); /* PCTTarget::static_GrabManipulatorCallback */
extern "C" void f_802FCC14(void); /* PCTTarget::GrabManipulatorCallback */
extern "C" void f_802F5F4C(void); /* PCTTarget::static_PlaceModeCallback */
extern "C" void f_802FD8AC(void); /* PCTTarget::PlaceModeCallback */
extern "C" void f_802F6000(void); /* PCTTarget::static_WallManipulatorCallback */
extern "C" void f_802FDEE4(void); /* PCTTarget::WallManipulatorCallback */

#endif /* SIMS2_TYPES_INTERACTORMODULE_H */
