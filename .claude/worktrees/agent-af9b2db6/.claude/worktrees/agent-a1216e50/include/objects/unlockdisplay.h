#ifndef UNLOCKDISPLAY_H
#define UNLOCKDISPLAY_H

#include "types.h"

// Forward declarations
class ERC;
class cXPerson;
class ObjectDefinition;
class EAHeap;
struct EMat4;

#include "core/e_vec3.h"

// ============================================================================
// CUnlockDisplay - Display system for unlocked items
// Object file: unlockdisplay.obj
//
// Layout (from disassembly offsets):
//   +0x0350: EVec3 m_ambientLight (12 bytes)
//   +0x0440: int   m_numDirectLights
//   +0x044C: int   m_displayMode (0=object, 1=promotion, 2=?, 3=social)
//   +0x0450: int   m_preloadDone
//   +0x0458: int   m_hidden
//   +0x045C: int   m_isDone
//   +0x0464: void* m_objectList (linked list of CUnlockDisplayObject)
//   +0x0468: float m_displayBoxLeft
//   +0x046C: float m_displayBoxTop
//   +0x0470: float m_displayBoxRight
//   +0x0474: float m_displayBoxBottom
//   +0x0498: float m_viewZoomFactor
//   +0x049C: float m_cameraPosX
//   +0x04A0: float m_cameraPosY
//   +0x04A4: float m_cameraPosZ
// Size: >= 0x04A8
// ============================================================================
class CUnlockDisplay {
public:
    u8  m_pad000[0x350];              // +0x000
    u8  m_ambientLight[12];           // +0x350 - EVec3
    u8  m_pad35C[0xE4];               // +0x35C
    int m_numDirectLights;            // +0x440
    u8  m_pad444[0x08];               // +0x444
    int m_displayMode;                // +0x44C
    int m_preloadDone;                // +0x450
    u8  m_pad454[0x04];               // +0x454
    int m_hidden;                     // +0x458
    int m_isDone;                     // +0x45C
    u8  m_pad460[0x04];               // +0x460
    void* m_objectList;               // +0x464 - linked list head
    float m_displayBoxLeft;           // +0x468
    float m_displayBoxTop;            // +0x46C
    float m_displayBoxRight;          // +0x470
    float m_displayBoxBottom;         // +0x474
    u8  m_pad478[0x20];               // +0x478
    float m_viewZoomFactor;           // +0x498
    float m_cameraPosX;               // +0x49C
    float m_cameraPosY;               // +0x4A0
    float m_cameraPosZ;               // +0x4A4

    CUnlockDisplay();
    ~CUnlockDisplay();
    void makeObjects();
    void destroyObjects();
    void SetupForObject(ObjectDefinition* def, EVec3& pos, EVec3& rot, EVec3& scale);
    void SetupForPromotion(cXPerson* person, void* data);
    void SetupForSocial(void* data);
    void Update();
    void Draw(ERC* rc);
    void SetDisplayBoxLeft(float val);
    void SetDisplayBoxTop(float val);
    void SetDisplayBoxRight(float val);
    void SetDisplayBoxBottom(float val);
    void SetViewZoomFactor(float val);
    void ManualCameraPos(float x, float y, float z);
    void SetAmbientLight(float r, float g, float b);
    void SetDirectLight(float r, float g, float b, int index);
    void SetDirectLightDir(EVec3 dir, bool param, int index);
    bool HasDrawn();
    bool ObjectHasMultiColor();
    void SetMultiColorNumber(int num);
    void RemoveAllDirectLights();
    bool IsDone();
    void Hide();
    void UnHide();
    int DonePreloadObject();
    void GetBedOtherHalfIDs(unsigned int id, unsigned int& out1, unsigned int& out2);

    void* operator new(unsigned int size);
    void operator delete(void* ptr);
};

// ============================================================================
// CUnlockDisplayObject - Individual object in unlock display
// Object file: unlockdisplayobject.obj
//
// Layout (from disassembly offsets):
//   +0x00: CUnlockDisplayObject* m_next (linked list)
//   +0x04: int   m_type
//   +0x08: int   m_state
//   +0x0C: void* m_object
//   +0x14: void* m_model
//   +0x28: float m_radius
//   +0x2C: u32   m_modelID
//   +0x30: u32   m_characterID
//   +0x34: u32   m_animationID
//   +0x38: u32   m_animationLoops
//   +0x3C: EVec3 m_pos (12 bytes)
//   +0x48: EVec3 m_rot (12 bytes)
//   +0x54: EVec3 m_rotAdd (12 bytes)
//   +0x60: EVec3 m_center (12 bytes)
//   +0x6C: int   m_playAndHold
//   +0x70: int   m_triggered
//   +0x74: int   m_isReady
//   +0x78: int   m_done
//   +0x7C: int   m_hasDrawn
//   +0x80: int   m_isSimple
// Size: >= 0x84
// ============================================================================
class CUnlockDisplayObject {
public:
    CUnlockDisplayObject* m_next;     // +0x00
    int   m_type;                     // +0x04
    int   m_state;                    // +0x08
    void* m_object;                   // +0x0C
    u8    m_pad10[0x04];              // +0x10
    void* m_model;                    // +0x14
    u8    m_pad18[0x10];              // +0x18
    float m_radius;                   // +0x28
    u32   m_modelID;                  // +0x2C
    u32   m_characterID;              // +0x30
    u32   m_animationID;              // +0x34
    u32   m_animationLoops;           // +0x38
    float m_posX;                     // +0x3C
    float m_posY;                     // +0x40
    float m_posZ;                     // +0x44
    float m_rotX;                     // +0x48
    float m_rotY;                     // +0x4C
    float m_rotZ;                     // +0x50
    float m_rotAddX;                  // +0x54
    float m_rotAddY;                  // +0x58
    float m_rotAddZ;                  // +0x5C
    float m_centerX;                  // +0x60
    float m_centerY;                  // +0x64
    float m_centerZ;                  // +0x68
    int   m_playAndHold;              // +0x6C
    int   m_triggered;                // +0x70
    int   m_isReady;                  // +0x74
    int   m_done;                     // +0x78
    int   m_hasDrawn;                 // +0x7C
    int   m_isSimple;                 // +0x80

    CUnlockDisplayObject();
    ~CUnlockDisplayObject();
    void ServiceDataReady();
    void Setup();
    void Update();
    void Draw(ERC* rc);
    void SetMultiColorIndex(int index);

    virtual bool IsActive();
    void* GetModel();
    bool IsSimple();
    void SetModelID(unsigned int id);
    void SetCharacterID(unsigned int id);
    void SetAnimationID(unsigned int id);
    void SetPos(EVec3& pos);
    EVec3 GetPos();
    void SetRot(EVec3& rot);
    EVec3 GetRot();
    void SetRotAdd(EVec3& rotAdd);
    EVec3 GetRotAdd();
    void SetAnimationLoops(unsigned int loops);
    void SetPlayAndHold(bool hold);
    void SetOrient(EMat4& mat);
    bool IsReady();
    void SetTrigger();
    bool IsDone();
    float GetRadius();
    EVec3 GetCenter();
    bool HasDrawn();
    int GetType();
};

// ============================================================================
// CUnlockDisplayObjectSim - Sim-specific unlock display object
// Object file: unlockdisplayobjectsim.obj
// Inherits from CUnlockDisplayObject
//
// Layout (additional fields):
//   +0x1B4: void* m_person (cXPerson*)
// ============================================================================
class CUnlockDisplayObjectSim : public CUnlockDisplayObject {
public:
    u8    m_simPad[0x130];            // padding up to +0x1B4 from base
    void* m_person;                   // +0x1B4 (from base)

    CUnlockDisplayObjectSim();
    ~CUnlockDisplayObjectSim();
    void SetPerson(cXPerson* person);
    void ServiceDataReady();
    void Setup();
    void Draw(ERC* rc);
    int IsMale();
    int IsAdult();
};

#endif // UNLOCKDISPLAY_H
