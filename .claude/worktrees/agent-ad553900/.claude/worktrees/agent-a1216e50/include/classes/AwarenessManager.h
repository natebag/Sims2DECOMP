#ifndef AWARENESSMANAGER_H
#define AWARENESSMANAGER_H

#include "types.h"

// AwarenessManager - struct layout extracted from assembly analysis
// Estimated minimum size: 0xB4 (180 bytes)
// 22 known fields (13 named), 100 methods

class AwarenessManager {
public:
    // Constructors / Destructors
    AwarenessManager(void)  // 0x80029DA4
    ~AwarenessManager(void);  // 0x8002A080

    // Methods
    void Init(SAnimator2 *, EAnimController *);  // 0x80029E68 (320B)
    void Reset(void);  // 0x80029FA8 (216B)
    void MemoryAwarenessClearAction(void);  // 0x8002C0C0 (1056B)
    void StopPassiveInfluenceAnimation(void);  // 0x8002C790 (344B)
    void AwarenessCheck(unsigned int);  // 0x8002A0EC (284B)
    void MemoryAwarenessCheck(unsigned int);  // 0x8002C5C0 (464B)
    void PassiveInfluenceAwarenessCheck(unsigned int);  // 0x8002CB18 (1564B)
    void RainAwarenessCheck(void);  // 0x8002CAA0 (120B)
    void UpdateAwarenessAngle(unsigned int);  // 0x8002C4E0 (224B)
    void handleAwarenessAnimations(unsigned int);  // 0x8002A208 (84B)
    void handleMemoryAwarenessAnimation(unsigned int);  // 0x8002AF78 (188B)
    void handleAwarenessTurningAnimation(void);  // 0x8002B034 (220B)
    void handlePassiveInfluenceAnimation(unsigned int);  // 0x8002AD5C (540B)
    void SetIsRaining(bool);  // 0x8002A25C (44B)
    void AwarenessAutoRunCheck(float);  // 0x8002A288 (228B)
    void SetPlayerControl(bool);  // 0x8002A36C (76B)
    /* ? */ GetFirstNodeRotation(float, float);  // 0x8002A3B8 (404B)
    /* ? */ GetSecondNodeRotation(float);  // 0x8002A54C (252B)
    void AwarenessAnimateHeadLeadsMotion(unsigned int, EACTrack *, EMat4 &, ERCharacter *, EACNodeState *);  // 0x8002A648 (736B)
    void AwarenessAnimateTorsoLeadsMotion(unsigned int, EACTrack *, EMat4 &, ERCharacter *, EACNodeState *);  // 0x8002A928 (736B)
    void SetAwarenessTargetAngle(cXObject *);  // 0x8002AC08 (340B)
    /* ? */ GetDeltaAngleToTargetObject(cXObject *);  // 0x8002D1AC (768B)
    void StartMemoryAwarenessAnimation(AwarenessManager::eAwarenessAction, int);  // 0x8002BB58 (784B)
    void SetAwareOfObject(cXObject *);  // 0x8002B110 (124B)
    void SetAwareOfObjectKilled(cXObject *);  // 0x8002B18C (100B)
    void ClearAwareOfObject(cXObject *);  // 0x8002B1F0 (136B)
    bool IsTimeToCheckMemoryAwareness(unsigned int);  // 0x8002B278 (220B)
    void ShouldAwarenessBeActive(unsigned int);  // 0x80031864 (392B)
    bool CanSeePlayer(void);  // 0x8002B354 (864B)
    /* ? */ GetActiveMemoryCategory(cXObject *, int &, int &);  // 0x8002B6B4 (496B)
    void StarMemoryAwarenessSprite(void);  // 0x8002B8A4 (540B)
    void SetPendingMemoryAwarenessAnim(AwarenessManager::eAwarenessAction, int);  // 0x8002BAC0 (152B)
    void getAwarenessSkillID(int, int, AnimRef *&);  // 0x80031CA8 (560B)
    void SetMemoryAwarenessActionToTry(cXObject *);  // 0x8002BE68 (600B)
    bool IsMemoryAwarenessAnimDone(void);  // 0x80031AF8 (156B)
    /* ? */ GetPlayerObject(int);  // 0x8002D134 (120B)
    void StartPassiveInfluenceAnimation(AnimRef *);  // 0x8002C8E8 (440B)
    void shouldAutoCarry(void);  // 0x80031ED8 (544B)
    void startAutoCarry(void);  // 0x800320F8 (792B)
    void endAutoCarry(void);  // 0x80032410 (312B)
    void getPassiveInfluenceSkillID(signed char, AnimRef *&);  // 0x80031B94 (276B)
    /* ? */ GetAwarenessAction(void);  // 0x80030E5C (44B)
    /* ? */ GetAwareOfObject(void);  // 0x80030E88 (44B)
    bool IsMemoryAwarenessAnimPending(void);  // 0x80030EB4 (52B)
    bool IsAutoCarryActive(void);  // 0x80030EE8 (52B)
    void SetTimeMultiplier(float);  // 0x80030F1C (40B)
    void SetPauseMultiplier(float);  // 0x80030F44 (40B)
    /* ? */ GetStateFlags(void);  // 0x80030F6C (44B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_firstNodeRotation;  // 0x000 [R/W] (AwarenessAutoRunCheck, AwarenessCheck, ClearAwareOfObject, ...)
    f32 m_activeMemoryCategory;  // 0x004 [R/W] (GetActiveMemoryCategory, GetDeltaAngleToTargetObject, GetFirstNodeRotation, ...)
    f32 m_firstNodeRotation_008;  // 0x008 [R/W] (GetFirstNodeRotation, GetSecondNodeRotation, Init, ...)
    f32 m_firstNodeRotation_00C;  // 0x00C [W] (GetFirstNodeRotation, GetSecondNodeRotation, Init, ...)
    u8 m_field_00D;  // 0x00D [W] (StartMemoryAwarenessAnimation, StartPassiveInfluenceAnimation)
    u8 _pad_00E[2];  // 0x00E
    f32 m_bIsTimeToCheckMemoryAwareness;  // 0x010 [R/W] (Init, IsTimeToCheckMemoryAwareness, MemoryAwarenessClearAction, ...)
    u32 m_memoryAwarenessActionToTry;  // 0x014 [R/W] (Init, MemoryAwarenessCheck, MemoryAwarenessClearAction, ...)
    u32 m_bIsMemoryAwarenessAnimDone;  // 0x018 [R/W] (Init, IsMemoryAwarenessAnimDone, MemoryAwarenessCheck, ...)
    u8 m_field_01A;  // 0x01A [R] (PassiveInfluenceAwarenessCheck)
    u8 _pad_01B[1];  // 0x01B
    u32 m_bIsTimeToCheckMemoryAwareness_01C;  // 0x01C [R/W] (ClearAwareOfObject, Init, IsTimeToCheckMemoryAwareness, ...)
    f32 m_awarenessTargetAngle;  // 0x020 [R/W] (ClearAwareOfObject, Init, MemoryAwarenessCheck, ...)
    u32 m_field_024;  // 0x024 [W] (Init)
    u32 m_field_028;  // 0x028 [W] (Init)
    f32 m_bIsTimeToCheckMemoryAwareness_02C;  // 0x02C [R/W] (Init, IsTimeToCheckMemoryAwareness, StartMemoryAwarenessAnimation, ...)
    f32 m_bIsTimeToCheckMemoryAwareness_030;  // 0x030 [R/W] (Init, IsTimeToCheckMemoryAwareness)
    u32 m_activeMemoryCategory_034;  // 0x034 [R/W] (AwarenessCheck, CanSeePlayer, GetActiveMemoryCategory, ...)
    u32 m_field_038;  // 0x038 [R/W] (AwarenessCheck, Init, shouldAutoCarry)
    f32 m_field_03C;  // 0x03C [R/W] (Init, PassiveInfluenceAwarenessCheck, Reset, ...)
    u32 m_field_040;  // 0x040 [R/W] (Init, PassiveInfluenceAwarenessCheck, Reset, ...)
    u32 m_bIsTimeToCheckMemoryAwareness_044;  // 0x044 [R/W] (IsTimeToCheckMemoryAwareness, MemoryAwarenessClearAction, ShouldAwarenessBeActive, ...)
    u32 m_field_048;  // 0x048 [R/W] (MemoryAwarenessClearAction)
    u8 _pad_04C[0x64];  // 0x04C
    u32 m_field_0B0;  // 0x0B0 [R] (MemoryAwarenessClearAction, StarMemoryAwarenessSprite)
};

#endif // AWARENESSMANAGER_H
