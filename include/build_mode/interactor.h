#ifndef INTERACTOR_H
#define INTERACTOR_H

#include "types.h"

// Forward declarations
class ESimsCam;
class cXObject;
class EIObjectMan;
class Interaction;
class PlumbBob;
class ERC;

struct EVec2 {
    f32 x;
    f32 y;
};

struct EVec3 {
    f32 x;
    f32 y;
    f32 z;
};

namespace InteractorModule {

// Forward declarations
class InteractorVisualizer;
class InteractorManager;
class Interactor;

class InteractorInputManager {
public:
    enum InteractorCommand {
        kCmdLeftStickX = 7,
        kCmdLeftStickY = 8,
        kCmdRightStickX = 11,
        kCmdRightStickY = 12,
        kCmdCameraX = 18,
        kCmdCameraY = 19,
    };
};

struct InteractorInfo {
    f32 posX;       // 0x00
    f32 posY;       // 0x04
    u32 field_08;   // 0x08
    u32 field_0C;   // 0x0C
};

// Interactor vtable structure - the vtable is stored at offset 0x5C as a pointer
// (SN Systems style: vtable pointer is NOT at offset 0)

// Base class: Interactor (from interactor.obj)
// Layout matches original binary exactly
class Interactor {
public:
    u32 m_playerId;       // 0x00
    ESimsCam* m_camera;   // 0x04
    EVec3 m_pos;          // 0x08 (x=0x08, y=0x0C, z=0x10)
    EVec3 m_prevPos;      // 0x14 (x=0x14, y=0x18, z=0x1C) - updated from m_pos
    EVec3 m_snappedPos;   // 0x20 (x=0x20, y=0x24, z=0x28) - set by SnapToPos
    u32 m_snapped;        // 0x2C
    u32 m_inputState;     // 0x30
    EVec2 m_leftStick;    // 0x34
    EVec2 m_rightStick;   // 0x3C
    u32 m_leftStickActive;  // 0x44
    u32 m_rightStickActive; // 0x48
    u32 m_drawState;      // 0x4C
    EVec2 m_extents;      // 0x50
    f32 m_idleTime;       // 0x58
    void* m_vtable;       // 0x5C - vtable pointer (SN style)

    void Update(float dt);
    void AttachCamera(ESimsCam* cam);
    ESimsCam* GetAttachedCamera();
    void GetInteractorInfo(InteractorInfo& info);
    void SetExtents(EVec2& extents);
    void UpdateObjectHighlights(EIObjectMan* objMan);

    struct CallbackData {
        u32 state; // 0x00
        u32 field_04; // 0x04
        u32 field_08; // 0x08 - function ptr/callback offset
        u32 field_0C; // 0x0C - function ptr
    };

    struct InteractorParams {
        u32 field_00;
        u32 playerId; // 0x04
        u32 field_08; // callback offset
        u32 field_0C; // callback function ptr
    };

    enum ClientNotificationState {};
    struct OverlapData {};

    void NotifyClient(ClientNotificationState state, CallbackData& data, InteractorParams& params);
    void OnCommandPressed(InteractorInputManager::InteractorCommand cmd, float value);
    void AddIdleTime(float dt);
    void ResetIdleTime();
    void UpdateOverlapIntersection(OverlapData* data);
    void ExecuteObjectActionMenu(cXObject* obj);
    void StopInObjectMenu();
    int ChooseAction(Interaction* interaction);
    EVec3* GetPos();
    EVec3* GetSnappedPos();
    void SnapToPos(EVec3& pos);
    int EitherStickCentered();
    int GetPlayerId();
    void SetDrawState(int state);
    int GetDrawState();
};

// DirectInteractor (from directinteractor.obj)
// Extends Interactor (fields start after Interactor at 0x60)
class DirectInteractor : public Interactor {
public:
    // Offset from DirectInteractor 'this':
    // (Interactor takes 0x00-0x5F = 96 bytes)
    u32 m_field_60;           // 0x60
    u32 m_controlStatus;      // 0x64 (== 100)
    u32 m_field_68;           // 0x68
    u32 m_exitDirectControl;  // 0x6C (== 108)
    cXObject* m_targetObject; // 0x70 (== 112)
    u32 m_field_74;           // 0x74
    void* m_interactorInfo;   // 0x78 (== 120)
    u32 m_field_7C;           // 0x7C
    u32 m_isAutonomous;       // 0x80 (== 128)
    u32 m_cancelTimerActive;  // 0x84 (== 132)
    f32 m_cancelTimerValue;   // 0x88 (== 136)

    void OnCreate();
    void OnDestroy();
    void GetInteractorInfo(InteractorInfo& info);
    void StartCancelTimer();
    void ClearCancelTimer();
    int CheckCancelTimer();
    void PreDraw(InteractorVisualizer& vis);
    void Draw(InteractorVisualizer& vis);
    void OnCommandUpdate(InteractorInputManager::InteractorCommand cmd, float value);
    void ResetInputState();
    f32 GetSelectionRadius();
    void StopInObjectMenu();
    void SetAutonomous();
    u32 GetControlStatus();
    void ExitDirectControl();
    int IsAutonomous();
};

// FadeSquare (from siminteractor.obj)
class FadeSquare {
public:
    EVec3 m_pos;       // 0x00
    u32 m_objPtr;      // 0x0C
    f32 m_fadeValue;   // 0x10
    u32 m_fading;      // 0x14
    u32 m_shouldDraw;  // 0x18

    void StartDraw(EVec3& pos, bool draw);
    void StartFade();
    void StopDraw();
    int ShouldDraw();
};

// SimInteractor (from siminteractor.obj)
class SimInteractor : public Interactor {
public:
    // Extended fields beyond Interactor base (0x60)
    // 0x60 to 0x63: first FadeSquare data or padding
    // Lots of fields in between...
    // Use raw byte offsets from 'this' in the implementations

    void OnCreate();
    void OnDestroy();
    void GetInteractorInfo_SI(InteractorInfo& info);
    void PreDraw(InteractorVisualizer& vis);
    void Draw(InteractorVisualizer& vis);
    void OnCommandUpdate(InteractorInputManager::InteractorCommand cmd, float value);
    void ResetInputState();
    void ResetSnapTimer();
    f32 GetSelectionRadius();
    void ReturnPlumbobToSim(PlumbBob* plumbBob, EVec3& pos);
    void SetupCutToSim();
    FadeSquare* GetFadeSquare(int index);
    void SetPlumbBobShadowSave(u32 value);
    u32 GetPlumbBobShadowSave();
};

// SocialModeInteractor (from socialmodeinteractor.obj)
class SocialModeInteractor : public Interactor {
public:
    s16 m_chosenActionID;  // 0x60
    u16 m_pad_62;          // 0x62
    u32 m_field_64;        // 0x64
    u32 m_field_68;        // 0x68
    u32 m_timeout;         // 0x6C

    void OnCreate();
    void OnDestroy();
    void GetInteractorInfo_SMI(InteractorInfo& info);
    void OnCommandPressed_SMI(InteractorInputManager::InteractorCommand cmd, float value);
    void OnCommandReleased(InteractorInputManager::InteractorCommand cmd);
    void OnCommandUpdate_SMI(InteractorInputManager::InteractorCommand cmd, float value);
    void ResetInputState();
    void PreDraw(InteractorVisualizer& vis);
    void Draw(InteractorVisualizer& vis);
    f32 GetSelectionRadius();
    int ChooseAction(Interaction* interaction);
    s16 GetChosenActionID();
    void ResetChosenAction();
    int GetTimout();
    void SetTimout(int timeout);
};

// InteractorManager (from interactormanager.obj)
class InteractorManager {
public:
    u32 m_initialized;     // 0x00
    u32 m_maxPlayers;      // 0x04

    static InteractorManager* GetSingleton();
    static InteractorInputManager* GetInputManager();
    static InteractorVisualizer* GetVisualizer();
    u32 IsInitialized();
    int IsValidPlayerId(int playerId) const;
};

// ObjectManipulator (from objectmanipulator.obj)
class ObjectManipulator : public Interactor {
public:
    // +0x60 (96): func table ptr
    // +0x64 (100): PlacementObject start
    // +0xA8 (168): m_isCursorModelEnabled

    void OnCreate();
    void OnDestroy();
    void OnStop();
    void OnCommandPressed_OM(InteractorInputManager::InteractorCommand cmd, float value);
    void PreDraw(InteractorVisualizer& vis);
    void Draw(InteractorVisualizer& vis);
    void SetUIDebugName(cXObject* obj);
    void SetIsCursorModelEnabled(bool enabled);
    int GetIsCursorModelEnabled() const;
    void* GetPlacementObject();
};

// GrabManipulator (from objectmanipulator.obj)
class GrabManipulator : public ObjectManipulator {
public:
    void OnCreate();
};

// PlaceManipulator (from objectmanipulator.obj)
class PlaceManipulator : public ObjectManipulator {
public:
    void OnCreate();
    void OnStart(Interactor::InteractorParams* params);
};

// PlacementObject (from objectmanipulator.obj)
class PlacementObject {
public:
    u32 m_object;       // 0x00
    u32 m_field_04;     // 0x04
    u32 m_field_08;     // 0x08
    u32 m_field_0C;     // 0x0C
    s16 m_direction;    // 0x10
    u8 m_field_12;      // 0x12
    u8 m_pad_13;        // 0x13
    u32 m_field_14;     // 0x14
    u32 m_field_18;     // 0x18
    u32 m_field_1C;     // 0x1C
    u32 m_field_20;     // 0x20
    u32 m_field_24;     // 0x24
    u32 m_field_28;     // 0x28

    PlacementObject();
    int CanObjectBeDestroyed();
    void ResetDirection();
};

} // namespace InteractorModule

#endif // INTERACTOR_H
