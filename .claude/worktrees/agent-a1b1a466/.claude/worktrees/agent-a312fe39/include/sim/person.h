#ifndef PERSON_H
#define PERSON_H

#include "types.h"

// Forward declarations
class cXObject;
class cXPersonImpl;
class cXPerson;
class Interaction;
class BString2;
class ReconBuffer;
class StringBuffer;
class StackElem;
class XPrimParam;
class XRoute;
class ObjSelector;
class ObjectModule;
class FTilePt;
class RoutingSlot;
struct MotiveInc;
struct ObjectRecord;
struct ScoredInteraction;
class TileList;

// ============================================================================
// ActionQueue - Manages a sim's queued actions
// Embedded in cXPersonImpl at offset +0x130
// ============================================================================
class ActionQueue {
public:
    ActionQueue();

    int CountVisible() const;
    int IsVisibleAction(Interaction& action) const;
    void AddActionToHUD(int index);
    int FindVisualInsertGUID(unsigned int guid) const;
    void RemoveActionFromHUD(int index);
    void SetActionText(BString2& text, unsigned int index);
    void SetIconObject(cXObject* obj, unsigned int index);
    void UpdateAction(unsigned int index);
    void Insert(Interaction& action, unsigned int index);
    void Remove(unsigned int index);
    void Enqueue(Interaction& action);
    void DisableHUDAccess(int disable);
    void EnableHUDAccess(int enable);

    // +0x000 to +0x2A7: internal data
    char _pad0[0x2A8];        // +0x000
    int m_begin;               // +0x2A8
    int m_end;                 // +0x2AC
};

// ============================================================================
// AutonomyConstantsClient - Client for autonomy behavior constants
// Vtable at 0x80462360
// ============================================================================
class AutonomyConstantsClient {
public:
    AutonomyConstantsClient();
    void UpdateConstants();

    // +0x00: vtable
    char _pad[0x08];
};

// ============================================================================
// _List_node_base - Internal list node for STL list
// ============================================================================
struct _List_node_base {
    _List_node_base* m_next;  // +0x00
    _List_node_base* m_prev;  // +0x04
};

// ============================================================================
// _List_global<bool> - Global list operations for bool-typed list
// ============================================================================
template <typename T>
class _List_global {
public:
    static void _Transfer(_List_node_base* pos, _List_node_base* first, _List_node_base* last);
};

// ============================================================================
// XRoute - A route entry in the route stack
// Size: 0xA4 (164 bytes)
// ============================================================================
struct XRoute {
    char _pad[0x7C];       // +0x00 through +0x7B
    int m_valid;           // +0x7C (used by InvalidateRoutes)
    char _pad2[0x24];      // +0x80 through +0xA3
};

// ============================================================================
// ScoredInteraction
// ============================================================================
struct ScoredInteraction {
    int _pad[2];      // +0x00, +0x04
    float m_score;    // +0x08
};

// ============================================================================
// cXPerson - Base person/sim class
// ============================================================================
class cXPerson {
public:
    cXPerson(int type);
    ~cXPerson();

    cXPerson* CastToPerson();
    void setPersonImpl(cXPersonImpl* impl);
    cXPersonImpl* CAST_IMPL();
};

// ============================================================================
// cXPersonImpl - Implementation of person/sim behavior
//
// Uses a flat struct layout with members at exact offsets.
// ============================================================================
class cXPersonImpl {
public:
    // +0x000: vtable pointer / cXObject base data
    void* m_vtable;                // +0x000 (vtable pointer)
    void* m_pSubObject;            // +0x004 (sub-object pointer, used by IsFemale, IsAdult, etc)
    short m_personData[32];        // +0x008 (PersonData array, [0] = idle state)
    // +0x048:
    short m_visitorStatus;         // +0x048
    char _pad4A[0x0E];             // +0x04A
    short m_socialModeState;       // +0x058
    char _pad5A[0x42];             // +0x05A
    u16 m_visibilityFlags;         // +0x09C
    char _pad9E[0x0A];             // +0x09E
    float m_motives[16];           // +0x0A8 (index 11 = sleep motive at +0xD4)
    float m_oldMotives[16];        // +0x0E8
    char _pad128[0x08];            // +0x128
    ActionQueue m_actionQueue;     // +0x130 (size 0x2B0)
    // +0x3E0 end of ActionQueue
    char _pad3E0[0x14];            // +0x3E0
    void* m_pSAnimator;            // +0x3F4
    char m_destList[0x10];         // +0x3F8 (embedded struct)
    void* m_pMotiveEffects;        // +0x408
    XRoute* m_routeStackBegin;     // +0x40C
    XRoute* m_routeStackEnd;       // +0x410
    char _pad414[0x08];            // +0x414
    u16 m_currentRoom;             // +0x41C
    char _pad41E[0x12];            // +0x41E
    void* m_pRecording;            // +0x430
    int m_recordDuration;          // +0x434
    int m_recordMaxDuration;       // +0x438
    int m_recordCurTicks;          // +0x43C
    int m_recordStartTicks;        // +0x440
    int m_recordTicksElapsed;      // +0x444
    int m_recordSkill;             // +0x448
    char _pad44C[0xE4];            // +0x44C
    int m_changingOutfitMode;      // +0x530
    void* m_currentAction;         // +0x534
    int m_lastMotiveUpdateTick;    // +0x538
    cXObject* m_pIgnoringObject;   // +0x53C
    short m_idleLoopCount;         // +0x540
    char _pad542[0x02];            // +0x542
    int m_firstPlayerInSocialMode; // +0x544
    int m_secondPlayerInSocialMode;// +0x548
    int m_waitingForSocialMode;    // +0x54C

    // Constructor/Destructor
    cXPersonImpl(int type, ObjSelector* selector, ObjectModule* module);
    ~cXPersonImpl();

    // Static memory management
    static void InitializeStaticMemory();
    static void CleanupStaticMemory();

    // Initialization
    void Initialize();
    void Reset(bool flag);
    void PostLoad(int a, bool b);
    void LoadMotiveEffects();

    // Serialization
    int ReconType();
    void ReconStream(ReconBuffer* buf, int dir, bool flag);

    // Simulation
    void Simulate(int ticks);

    // Motives
    float GetMotive(int index);
    float* GetMotiveRef(int index);
    float* GetOldMotiveRef(int index);
    void SetMotive(int index, float value);
    void SimMotives();
    void CalcHappy();
    float GetAspirationScore();
    void SetAspirationScore(float score);
    int GetAspirationStatus();
    void SpawnAspirationBalloon(int type);
    float* GetMotives();
    void* GetMotiveEffects();

    // Actions
    void RunImmediateAction(Interaction* action);
    int IsIdle();
    void AddAction(Interaction* action);
    void ActionSkipped(Interaction& action);
    void RemoveAction(int index);
    int HasQueuedActionOfPri(int priority) const;
    void CancelLastAction();
    void CancelAllActions();
    void CancelAllButLastActions();
    Interaction* GetIndAction(int index, bool flag);
    Interaction* GetCurrentAction();
    cXObject* GetCurrentInteractionStackObject();
    cXObject* GetCurrentInteractionIconObject();
    void DebugDumpHappyScape();
    int ShouldInterrupt();
    void UpdateCurrentAction();
    void CompleteCurrentAction();
    void DeleteTopAction();
    void SetCurrentAction(Interaction& action);
    int GetPendingAction() const;
    Interaction* GetCurrentInteractionNC();
    int CountActions(bool includeIdle);
    void SetCurrentActionText(BString2& text);

    // Routing
    XRoute* GetCurrentRoute();
    int GetRouteStackSize();
    void InvalidateRoutes();
    int IsRouting();

    // Model / Visual
    int IsModelLoaded();
    void EORDrawStickFigure(int arg);
    int IsPersonDying();
    void SetHilite(int hilite);
    void AttachToHUD(bool attach);
    int Skipping3D();
    void UpdateCurrentRoom();
    void Place(FTilePt& pt, int a, cXObject* obj, int b);
    void UserCanPickup();
    void Turn(int direction);

    // Selection / Player
    int IsSelected();
    int IsSelectableByPlayer(int player);
    int IsPrimarySim(int player);
    int IsPersonInFamily(int family) const;
    void ForceLocation();

    // Person properties
    int IsSleeping();
    int IsDog();
    int IsCat();
    int IsMonkey();
    int IsPet();
    int IsChild();
    int IsMale();
    int IsFemale();
    int IsAdult();

    // Person data
    short GetPersonData(int index) const;
    void SetPersonData(int index, short value);
    short* GetPersonDataArray();
    short GetIdleState();

    // Sim description
    void* GetSimDescription();
    void* GetServiceNPC();
    void* GetNormalSimDescription();
    short GetNeighborID() const;
    void SetNeighborID(short id);

    // Visitor / Ghost / Alien
    int IsVisitor();
    int IsGhost();
    int IsAlien();
    int IsInvisible();
    int IsGreen();
    int IsInMotiveFailure();
    int NeedsWantFearShuffle();
    short GetVisibility();
    void SetInvisible(bool invisible);
    void SetIsAlien(bool alien);

    // Social mode
    int IsInSocialMode();
    int IsFirstPlayerInSocialMode();
    int IsSecondPlayerInSocialMode();
    int IsWaitingForSocialMode();
    void SetFirstPlayerInSocialMode(bool mode);
    void SetSecondPlayerInSocialMode(bool mode);
    void SetWaitingForSocialMode(bool mode);
    void* GetSocialModeTarget();
    void IncrementSimSocialInterest(float amount);
    void GetSimSocialInterestAsMotiveValue(cXPerson* person);
    void SetSimSocialIntrestFromMotiveValue(cXPerson* person, float value);
    void CheckFirstPlayerForFailedSocialModeEntry();
    void CheckSecondPlayerForFailedSocialModeEntry();

    // Recording
    void* GetRecording();
    int GetRecordDuration();
    void SetRecordDuration(int duration);
    int GetRecordMaxDuration();
    void SetRecordMaxDuration(int duration);
    int GetRecordStartTicks();
    int GetRecordCurTicks();
    int GetRecordTicksElapsed();
    int GetRecordSkill();
    void StartRecording(int a, int b);
    void StopRecording();
    void ClearRecording();
    int TickRecording();

    // Stubs / Debug
    void LogEvent(char* a, char* b, char* c);
    void Track();
    void GetJobSuitTex(StringBuffer& a, StringBuffer& b, StringBuffer& c);

    // Misc
    void DumpDestList(char* label);
    void SetIdleLoopCount(short count);
    void SetChangingOutfitMode(bool mode);
    int GetLastMotiveUpdateTick();
    void SetLastMotiveUpdateTick(int tick);

    // Ignoring objects
    cXObject* IgnoringObject();
    void SetIgnoringObject(cXObject* obj);
    void ClearIgnoringObject();

    // Awareness
    void SetAwareOfObject(cXObject* obj);
    void SetAwareOfObjectKilled(cXObject* obj);
    void ClearAwareOfObject(cXObject* obj);

    // Object control
    cXObject* GetControllingObject();

    // Casting
    cXPersonImpl* CastToPersonImpl();
    cXPersonImpl* GetPersonImplementation();

    // Room
    u16 GetCurrentRoom() const;

    // SAnimator
    void* GetSAnimator() const;

    // DestList
    void* GetDestList();

    // Wants/Fears
    void InitWantFearIcons();
    void SpawnWantFearDialog(unsigned int id) const;
    void SetIdlePlayerSimAutonomous();
    int IsCarryingDCObject();
    int IsCarrying();

    // Tree / Stack
    void GosubObjectTree(cXObject* obj, short* tree, short param, bool flag);
    void StackJustPopped();
    void Cleanup(cXObject* obj);
    void PreSave();

    // Interaction primitives
    void TrySetMotiveDelta(StackElem* elem, XPrimParam* param);
    void TryGosubFoundAction(StackElem* elem);
    void TryLookTowards(StackElem* elem, XPrimParam* param);
    void TryGotoRoutingSlot(StackElem* elem, XPrimParam* param);
    void TryGotoRoutingSlot(StackElem* elem, RoutingSlot* slot);
    void TryRoomRouting(XRoute* route);
    void AskOthersToMove(XRoute* route);
    void InitRoute(XRoute* route);
    void MoveOutOfWay(XRoute* route, TileList& tileList);
    void MoveOutOfWay(int arg);
    void TryGotoRelative(StackElem* elem, XPrimParam* param);
    void TryGetReachInfo(StackElem* elem, XPrimParam* param, cXObject** a, cXObject** b, int* c, float* d);
    void TryReach(StackElem* elem, XPrimParam* param);
    void NetTrySnapTo(StackElem* elem, XPrimParam* param);
    void TryElement(StackElem* elem, short code, XPrimParam* param);
    void TryChangeSuit(StackElem* elem, XPrimParam* param);
    void TryFindBestAction(StackElem* elem);
    void TryIdleForInput(StackElem* elem, XPrimParam* param);
    void TryIdleAnimate(StackElem* elem, XPrimParam* param);
    void TryTestInteractingWith(StackElem* elem, XPrimParam* param);
    void TrySocialMode(StackElem* elem, XPrimParam* param);
    void executeInterruptOnIdlePrimitve(StackElem* elem, short* a, bool b);

    // Static members
    static int sHappyMotives[];
    static int sHappyCurvesSetup;
};

// Free functions in person.obj
AutonomyConstantsClient* GetAutonomyConstantsClient();
int IsPermittedToRunCheckTreeForAds(int guid, int adType);
bool operator<(ScoredInteraction& a, ScoredInteraction& b);
int IsMoveOutOfWay(Interaction* action);
int IsAskedToMove(cXPersonImpl* person);

#endif // PERSON_H
