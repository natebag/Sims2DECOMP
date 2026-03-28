#ifndef CAS_H
#define CAS_H

#include "types.h"
#include "core/e_vec3.h"
#include "sim/simmodel.h"

// Forward declarations
class CasMediator;
class CasSimDescriptionS2C;
class CasSimPartsS2C;
class CasSimRenderer;
class ERC;
class ReconBuffer;
class ETexture;
class EMat4;

// ============================================================================
// ReconObject base - serialization base class
// ============================================================================
class ReconObject {
public:
    virtual ~ReconObject();
    virtual void DoStream(ReconBuffer* buf, int mode);
    virtual u32 GetType();
};

// ============================================================================
// CasEvent - Base class for CAS events
// Size: 0x08 (m_pad00 at +0x00, vtable implicit at +0x04)
// Vtable at 0x80465f20
// Object file: casevent.obj
// ============================================================================
class CasEvent {
public:
    u32 m_pad00;  // +0x00

    virtual ~CasEvent();
    virtual void Log() const;
};

// Forward declare event subclasses
class CasEventChangeFocus;
class CasEventChangeSimS2C;
class CasEventInitSim;
class CasEventResetSim;
class CasEventStoreSim;
class CasEventMorphSimS2C;

// ============================================================================
// CasEventResetSimDraw - Event subclass for sim draw resets
// Size: 0x0C (base CasEvent + m_flag at +0x08)
// Vtable at 0x80466228
// Object file: cassimstate.obj
// ============================================================================
class CasEventResetSimDraw : public CasEvent {
public:
    u32 m_flag;  // +0x08

    virtual ~CasEventResetSimDraw();
    virtual void Log() const;
};

// ============================================================================
// CasListener - Base class for CAS event listeners
// Size: 0x08 (m_pMediator at +0x00, vtable implicit)
// Vtable at 0x80465f68
// Object file: caslistener.obj
// ============================================================================
class CasListener {
public:
    CasMediator* m_pMediator;  // +0x00

    CasListener();
    virtual ~CasListener();

    void SetMediator(CasMediator* mediator);
    CasMediator* GetMediator() const;

    // Virtual event handlers - all empty in base class
    virtual void HandleEventChangeFocus(CasEventChangeFocus& event);
    virtual void HandleEventChangeSim(CasEventChangeSimS2C& event);
    virtual void HandleEventInitSim(CasEventInitSim& event);
    virtual void HandleEventResetSim(CasEventResetSim& event);
    virtual void HandleEventStoreSim(CasEventStoreSim& event);
    virtual void HandleEventMorphSim(CasEventMorphSimS2C& event);
    virtual void HandleEventResetSimDraw(CasEventResetSimDraw& event);

    // Non-virtual
    void HandleEvent(CasEvent& event);
};

// ============================================================================
// CasMediator - Mediator pattern for CAS system
// Size: 0x30
// Object file: casmediator.obj
// ============================================================================
class CasMediator {
public:
    u32 m_pad00;                    // +0x00
    void* m_pListNode;             // +0x04
    u32 m_numListeners;            // +0x08
    u8 m_flag0C;                   // +0x0C
    u8 _pad0D[3];
    void* m_pScene;                // +0x10
    CasSimRenderer* m_pSimRenderer; // +0x14
    void* m_pScene2;               // +0x18
    u32 m_unk1C;                   // +0x1C
    u32 m_controllerFilterId[2];   // +0x20
    u32 m_unk28;                   // +0x28
    u32 m_casMode;                 // +0x2C

    CasMediator();
    ~CasMediator();

    void AddListener(CasListener& listener);
    void RemoveListener(CasListener& listener);
    void RemoveAllListeners();
    u32 GetNumListeners() const;
    void PostEvent(CasEvent& event);

    CasSimDescriptionS2C* GetEditSimDescription();

    u32 GetNumBodyModels(eBodyPartS2C part) const;
    u32 GetNumTattooTextures(eTattooTextureTypeS2C type) const;
    u32 GetIconTextureId(eBodyPartS2C part, unsigned int index) const;
    u32 GetIconTattooTextureId(eTattooTextureTypeS2C type, unsigned int index) const;
    void GetIndexes(eBodyPartS2C part, unsigned char* a, unsigned char* b);
    void GetIndexes(eTattooTextureTypeS2C type, unsigned char* a, unsigned char* b);
    void DrawSim(ERC* rc);

    void SetCasMode(int mode);
    void IsTransitionComplete();
    void SetControllerFilterId(unsigned int slot, unsigned int id);
    u32 GetControllerFilterId(unsigned int slot) const;
};

// ============================================================================
// CasGenetics - Genetics system for CAS
// Object file: casgenetics.obj
// ============================================================================
class CasGenetics {
public:
    struct Grandparent {
        u32 m_unk00;  // +0x00
        u32 m_unk04;  // +0x04

        Grandparent();
    };

    CasGenetics();
    ~CasGenetics();

    void BlendSimDescriptions(CasSimDescriptionS2C& a, CasSimDescriptionS2C& b, CasSimDescriptionS2C& out, bool flag);
    void BlendSkinColor(signed char a, signed char b);
    void BlendBodyType(signed char a, signed char b);
    void BlendMorphValues(float a, float b);
    void ChooseRandomBodyPart(eBodyPartS2C part, CasSimDescriptionS2C& desc, int param);
    void ChoosePersonalityTraits(CasSimDescriptionS2C& desc);
    void ClearGrandparentsList();
    void LoadGrandparentList(bool flag);
    void CreateNewGrandparentList();
    void SaveGrandparentList();
    void DoStream(ReconBuffer* buf, int mode);
    void LoadGrandparentPortraits();
    void GetGrandparentPortraitName(bool maternal, unsigned int index);
    void GetGrandparent(bool maternal, unsigned int index);
    void UpdateGrandparentDescription(bool maternal, unsigned int index, CasSimDescriptionS2C& desc);
    Grandparent* GetGrandparentData();

    static bool FemaleInnerLayerTorsoLocked(signed char part);
    void FemaleFacialFeatureLocked(signed char part);

    u32 m_unk00;  // +0x00
    u32 m_unk04;  // +0x04
    u32 m_unk08;  // +0x08
    u32 m_unk0C;  // +0x0C
    u32 m_unk10;  // +0x10
};

// ============================================================================
// SimpleReconObject<T> - Serialization wrapper template
// Vtable at 0x80465f40 (for CasGenetics instantiation)
// Object file: casgenetics.obj
// ============================================================================
template <class T>
class SimpleReconObject : public ReconObject {
public:
    T* m_pObject;   // +0x04
    u32 m_type;     // +0x08

    virtual ~SimpleReconObject();
    virtual void DoStream(ReconBuffer* buf, int mode);
    virtual u32 GetType();
};

// ============================================================================
// CasScene - 3D scene for Create-A-Sim
// Size: ~0x0B20
// Vtable at 0x80466048
// Object file: casscene.obj
// ============================================================================
class CasScene : public CasListener {
public:
    enum RoomId {
        ROOM_MAIN = 0
    };

    CasScene();
    virtual ~CasScene();

    void Init();
    void InitCamera(unsigned int cameraId);
    void Reload();
    void LoadLights(char* name, int param);
    void SetMediator(CasMediator* mediator);
    void Update(float dt);
    void UpdateCamera(float dt);
    void Draw(ERC* rc);
    void SetUpWindow(ERC* rc);
    void DrawRoom(ERC* rc, RoomId roomId, EMat4& mat);
    void DrawRoomClothing(ERC* rc, EMat4& mat);
    void SetSceneLighting(int lightSet, bool flag);
    void SetCameraParams(float param1, float param2, float param3);
    void SetLights(int lightSet);
    void RepositionCamera(unsigned int pos, float param1, float param2);
    void GetCameraAngle(EVec3* eye, EVec3* target);
    bool IsCameraMoving();
    void* GetLights();
    void* Get3DWindow() const;
    virtual unsigned int GetRoomFromCameraAngle(unsigned int angle) const;
    const char* GetAmbientScoreName() const;
    virtual const char* GetSceneName() const;
    virtual unsigned int GetRoomModelId(RoomId roomId) const;
    virtual void HandleEventChangeFocus(CasEventChangeFocus& event);
    void GetObjectPosition(unsigned int objId, EVec3& pos, float& rot);

    static const char* s_szLightSetNames[4];

    // Placeholder for full layout (~0x0B20 bytes)
    char _sceneData[0x0B20];
};

// ============================================================================
// CasSceneDefault - Default CAS scene
// Vtable at 0x804662c0
// Object file: casscenedefault.obj
// ============================================================================
class CasSceneDefault : public CasScene {
public:
    CasSceneDefault();
    virtual ~CasSceneDefault();

    virtual const char* GetSceneName() const;
    virtual unsigned int GetRoomModelId(RoomId roomId) const;
};

// ============================================================================
// CasSceneGamecube - GameCube-specific CAS scene
// Vtable at 0x80466370
// Object file: casscenegamecube.obj
// ============================================================================
class CasSceneGamecube : public CasScene {
public:
    CasSceneGamecube();
    virtual ~CasSceneGamecube();

    virtual const char* GetSceneName() const;
    virtual unsigned int GetRoomModelId(RoomId roomId) const;
    virtual unsigned int GetRoomFromCameraAngle(unsigned int angle) const;
};

// ============================================================================
// CasSimState - Manages CAS sim state (current + stored descriptions)
// Size: ~0x250
// Vtable at 0x80466248
// Object file: cassimstate.obj
// ============================================================================
class CasSimState : public CasListener {
public:
    // +0x08: embedded CasSimDescriptionS2C
    // +0x12C: embedded CasSimDescriptionS2C (stored copy)

    CasSimState();
    virtual ~CasSimState();

    CasSimDescriptionS2C* GetSimDescription();
    CasSimDescriptionS2C* GetStoredSimDescription();
};

// ============================================================================
// External declarations
// ============================================================================

// UIDB
class UIDB {
public:
    static void UIDBSetInt(char* key, int value);
};

// CasEventDummyPrintf
extern "C" void CasEventDummyPrintf(char* fmt, ...);

#endif // CAS_H
