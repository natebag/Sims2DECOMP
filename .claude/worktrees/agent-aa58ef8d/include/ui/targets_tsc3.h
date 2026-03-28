#ifndef TARGETS_TSC3_H
#define TARGETS_TSC3_H

#include "types.h"

// Forward declarations
class ERC;

namespace InteractorModule {
    namespace GrabManipulator { struct CallbackData; }
    namespace PlaceManipulator { struct CallbackData; }
    namespace FloorPainter { struct CallbackData; }
    namespace WallManipulator {
        struct CallbackData;
        struct WallData;
    }
    namespace WallPainter {
        struct CallbackData;
        struct WallPaperData;
    }
    struct FloorData;
}

// Forward declare PDATarget for cross-references
class PDATarget;
class UIDialog;

// ============================================================================
// AptVar - base class for APT variable handlers (TSC3)
// ============================================================================
class AptVar {
public:
    u8 _pad[0x08];
    void* m_vtable_aptvar; // 0x08
    int m_field0C;         // 0x0C

    static int Hash(char* str);
    virtual ~AptVar();
};

// ============================================================================
// SetVar classes - write APT variables
// ============================================================================
struct SetVar_EYE_state : public AptVar {
    ~SetVar_EYE_state();
};

struct SetVar_EYE_topLevelCurrSel : public AptVar {
    ~SetVar_EYE_topLevelCurrSel();
};

struct SetVar_EYE_funframeCurrSel : public AptVar {
    void Handler(char* value);
    ~SetVar_EYE_funframeCurrSel();
};

struct SetVar_EYE_filterCurrSel : public AptVar {
    void Handler(char* value);
    ~SetVar_EYE_filterCurrSel();
};

struct SetVar_EYE_slotCurrSel : public AptVar {
    void Handler(char* value);
    ~SetVar_EYE_slotCurrSel();
};

struct SetVar_EYE_saveToSlotStatus : public AptVar {
    ~SetVar_EYE_saveToSlotStatus();
};

struct SetVar_EYE_settingSliderVal : public AptVar {
    void Handler(char* value);
    ~SetVar_EYE_settingSliderVal();
};

struct SetVar_EYE_opCancelled : public AptVar {
    void Handler(char* value);
    ~SetVar_EYE_opCancelled();
};

// ============================================================================
// GetVar classes - read APT variables
// ============================================================================
struct GetVar_LockedStatus : public AptVar {
    ~GetVar_LockedStatus();
};

struct GetVar_SliderStep : public AptVar {
    void Handler(char* result);
    ~GetVar_SliderStep();
};

struct GetVar_GetCount : public AptVar {
    void Handler(char* result);
    ~GetVar_GetCount();
};

struct GetVar_EYE_exists : public AptVar {
    void Handler(char* result);
    ~GetVar_EYE_exists();
};

struct GetVar_EYE_targetState : public AptVar {
    void Handler(char* result);
    ~GetVar_EYE_targetState();
};

struct GetVar_EYE_settingSliderVal : public AptVar {
    ~GetVar_EYE_settingSliderVal();
};

struct GetVar_SaveRequired : public AptVar {
    ~GetVar_SaveRequired();
};

struct GetVar_SaveStatus : public AptVar {
    void Handler(char* result);
    ~GetVar_SaveStatus();
};

struct GetVar_ImageSlotsAvail : public AptVar {
    ~GetVar_ImageSlotsAvail();
};

struct GetVar_EYE_connectionStatus : public AptVar {
    ~GetVar_EYE_connectionStatus();
};

struct GetVar_Legacy : public AptVar {
    void Handler(char* result);
    ~GetVar_Legacy();
};

// ============================================================================
// EYETarget - EyeToy Target (TSC3 version)
// ============================================================================
class EYETarget {
public:
    u8 _pad[0x88];
    int m_settingsCount;    // 0x88 (offset 136)
    int m_slotSelection;    // 0x8C (offset 140)
    int m_filterSelection;  // 0x90 (offset 144)
    int m_funframeSelection;// 0x94 (offset 148)
    u8 _pad2[0x18];
    int m_eyeToyUnplugged;  // 0xB0 (offset 176)
    u8 _pad3[0x14];
    float m_savedSetting;   // 0xA4 (offset 164)
    void* m_restoreFunc;    // 0xA8 (offset 168)

    enum eState {};

    static void EyeToyUnplugCallback(int param);
    void Update();
    void RestorePreviousSetting();
    void SetState(eState state);  // offset 172
};

// ============================================================================
// GOLTarget - Goals Target (TSC3)
// ============================================================================
class GOLTarget {
public:
    void Update();
    void Draw(ERC* rc);
};

// ============================================================================
// INVTarget - Inventory Target (TSC3)
// ============================================================================
class INVTarget {
public:
    u8 _pad[0x84];
    int m_showObjectInfo;   // 0x88 (offset 136)
    u8 _pad1[0x28];
    int m_tabCount;         // 0xBC (offset 188)
    u8 _pad2[0x14];
    int m_inventoryCount;   // 0xD4 (offset 212)
    u8 _pad3[0x24];
    int m_shaderLoaded[12]; // 0x108 (offset 264, 12 ints)
    u8 _pad4[0xA8];
    int m_bldItemData;      // 0x18EC? large offset
    u8 _pad5[0x2988];
    int m_invBuildItemCount; // 0x32E8 (offset 13032)
    u8 _pad6[0x2DC];
    u8 m_shoppingCatIdx;    // 0x3250 (offset 12880)
    u8 m_shoppingCellIdx;   // 0x3251 (offset 12881)
    u8 _pad7[0x1A];
    int m_isShoppingPanel;  // 0x319C (offset 12696)
    u8 _pad8[0x04];
    int m_playerIndex;      // 0x84 (offset 132)

    void Update();
    void Draw(ERC* rc);
    int CalcLastPageIdx(int totalItems);
    void SetIsShaderLoadedByIndex(int index, bool loaded);
    int GetIsShaderLoadedByIndex(int index) const;
    void SetPriceCheatString(char* buf, int price, unsigned short currency);
    void SetBudgetCheatString(int budget);
    int GetMaxWCharBufSize(unsigned short* str);
    void FireCodeDialogZeroInputCallback();
    void CannotGrabToInventoryDialogZeroInputCallback();
    void StartActionMenu();
    void PlaceModeCallback(InteractorModule::PlaceManipulator::CallbackData* data);
    void WallManipulatorCallback(InteractorModule::WallManipulator::CallbackData* data);
    void WallPainterCallback(InteractorModule::WallPainter::CallbackData* data);
    void FloorModeCallback(InteractorModule::FloorPainter::CallbackData* data);
    void GrabModeCallback(InteractorModule::GrabManipulator::CallbackData* data);
    void InstallBldVariables();
    void InstallShoppingPanelShaders();
    void InstallShoppingCategoryShaders();
    int GetSelectedShoppingCategory();
    int GetSelectedShoppingCategoryListIdx();
    void ExitWallPaperingMode();
    void ExitWallBuildingMode();
    void SetInvBldItemCount();

    // APT message handlers
    void SetOnMsgInvNextTab(char* msg);
    void SetOnMsgInvPrevTab(char* msg);
    void SetOnMsgInvRemoveObjectInfo(char* msg);
    void SetOnMsgInvClose(char* msg);
    void SetOnMsgInvCurrentPanel(char* msg);
    void SetOnMsgInvShpQueryTab(char* msg);
    void SetOnMsgInvShpCurrentCell(char* msg);
    void SetOnMsgInvShpRemoveObjectInfo(char* msg);
    void GetOnMsgInvExists(char* result);
    void GetOnMsgInvBackExitReset(char* result);
    void GetOnMsgInvCurrentTab(char* result);
    void GetOnMsgInvCurrentCell(char* result);
    void GetOnMsgInvTabCount(char* result);
    void GetOnMsgInvInventoryCount(char* result);
    void GetOnMsgInvInventoryReady(char* result);
    void GetOnMsgInvShpCurrentCell(char* result);
    void GetOnMsgInvShpResourcesReady(char* result);
    void GetOnMsgInvShpIsTabEnabled(char* result);
    void GetOnMsgInvShpDefaultColor(char* result);
};

// ============================================================================
// INTTarget - Interest Meter Target (TSC3)
// ============================================================================
class INTTarget {
public:
    u8 _pad[0x88];
    int m_isActive;          // 0x88 (offset 136)
    u8 _pad2[0x04];
    int m_showInterest;      // 0x94 (offset 148)

    void ShowInterestMeter();
    void HideInterestMeter();
    int IsInterestMeterActive();
};

// ============================================================================
// KEYTarget - Keyboard Target (TSC3)
// ============================================================================
class KEYTarget {
public:
    u8 _pad[0x8C];
    int m_mode;              // 0x8C (offset 140)

    int IsModeValid();
};

// ============================================================================
// OPTTarget - Options Target (TSC3)
// ============================================================================
class OPTTarget {
public:
    void Update();
};

// ============================================================================
// PDATarget - PDA Target (TSC3)
// ============================================================================
class PDATarget {
public:
    enum ePDAMode {};

    u8 _pad[0x84];
    u8 m_dialogData[0x20];   // 0x84 (offset 132) - UIDialog inline
    u8 _pad2[0x90];
    INVTarget* m_invTargets[4]; // 0x134 (offset 308, 4 pointers)
    int m_pdaModes[4];       // 0x14C (offset 332, 4 ints)
    u8 _pad3[0x08];
    int m_fireOnExitFlag;    // 0x168 (offset 360)
    int m_startFireOnExit;   // 0x16C (offset 364)

    void Update();
    void SetupFirstOpenMessage(int player, ePDAMode mode);
    int SetStartFireOnExit(bool fire);
    INVTarget* GetINVTarget(int player) const;
    int GetPdaMode(int player);
};

// ============================================================================
// RELTarget - Relationships Target (TSC3)
// ============================================================================
class RELTarget {
public:
    u8 _pad[0x84];
    void* m_headList;  // 0x84 (offset 132)

    int GetFace(int index);
    int GetCrew(int index);
    void* GetRecord(int index);
};

// ============================================================================
// Free functions from targets_tsc3
// ============================================================================
float GetExposureHandler();
int StaticIsSkillUpgradeObject(int guid);
u32 StaticGetShaderId(InteractorModule::WallPainter::WallPaperData* data);
u32 StaticGetShaderId(InteractorModule::WallManipulator::WallData* data);
u32 StaticGetShaderId(InteractorModule::FloorData* data);
int IsObjectLockedByGUID(int guid, int lockType);
int ConvertShoppingCategoryToInventoryCategory(int category);

#endif // TARGETS_TSC3_H
