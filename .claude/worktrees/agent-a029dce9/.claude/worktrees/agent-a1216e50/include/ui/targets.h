#ifndef TARGETS_H
#define TARGETS_H

#include "types.h"

// Forward declarations
class ERC;
class cXPerson;
class Interaction;
class CasEventChangeFocus;
class UIDialog;
class ObjSelector;
class WallTile;
struct structDrawCBparams;

namespace InteractorModule {
    class Interactor {
    public:
        struct CallbackData;
    };
}

// ============================================================================
// UIDialog - base class for dialog callbacks
// ============================================================================
class UIDialog {
public:
    void SelectionCallback(int sel);
    void ZeroInputCallback();
    void DialogClosedCallback();
    void SpawnDialog();
    void ChangeContinueType(int type);
};

// ============================================================================
// targets_s2c - S2C UI target classes
// ============================================================================

// ACTTarget - Action Queue Target
class ACTTarget {
public:
    u8 _pad[0xD0];
    int m_isActive;       // 0xD0
    u8 _pad2[0x04];
    int m_showQueue;      // 0xD8

    void ShowActionQueue();
    void HideActionQueue();
    int IsActionQueueActive();
    int IsActionQueueAvailable(int player) const;
    void DebugListValidation();
};

// BBHTarget - Build/Buy HUD Target
class BBHTarget {
public:
    u8 _pad[0x88];
    int m_isActive;       // 0x88
    u8 _pad2[0x04];
    int m_showHUD;        // 0x90

    int IsBuildBuyHUDActive();
    void ShowBuildBuyHUD();
    void HideBuildBuyHUD();
};

// CRDTarget - Credits Target
class CRDTarget {
public:
    void Draw(ERC* rc);
    void UpdateCredits();
};

// CSMTarget - CSIM Target
class CSMTarget {
public:
    u8 _pad[0x88];
    int m_isActive;       // 0x88
    u8 _pad2[0x04];
    int m_showCSIM;       // 0x90
    u8 _pad3[0x04];
    int m_field98;        // 0x98

    void ShowCSIM();
    void HideCSIM();
    int IsCSIMActive();
};

// CSPTarget - CSP Target
class CSPTarget {
public:
    void Update();
    void onHelpDialogSelection(int sel);
};

// E2ETarget - EyeToy Target
class E2ETarget {
public:
    u8 _pad[0xD8];
    int m_topLevelState;  // 0xD8

    int GetTopLevelState();
};

// FAMTarget - Family Target
class FAMTarget {
public:
    void Shutdown();
    void Update();
    void UpdateText();
    void OnLeftKeyPressed(char* a, char* b);
    void OnRightKeyPressed(char* a, char* b);
    void OnCancelDialog();
    void OnCircleKeyPressed(char* a, char* b);
    int ConvertSelectedFamilyIndexToActualGameIndex(int index);
    int ConvertSelectedLotIndexToActualGameIndex(int index);
};

// FCMTarget - Fire Code Meter Target
class FCMTarget {
public:
    u8 _pad[0x88];
    int m_isActive;       // 0x88
    u8 _pad2[0x04];
    int m_showMeter;      // 0x90

    void HideFireCodeMeter();
    int IsFireCodeMeterActive();
};

// G2DTarget - G2D Target (game 2D UI)
class G2DTarget {
public:
    u8 _pad[0x84];
    int m_isSpawned;      // 0x84
    int m_isActive;       // 0x88
    u8 _padx[0xA8];
    int m_transitionState; // 0x134

    int IsG2DActive();
    int IsG2DSpawned();
    static int IsInitComplete();
    int HasPendingTransition();
};

// H2DTarget - HUD 2D Target
class H2DTarget {
public:
    u8 _pad[0xD0];
    int m_pausePlayer;    // 0xD0
    u8 _pad2[0x0C];
    int m_rewardClosed;   // 0xE0

    void Draw(ERC* rc);
    int GetPausePlayer();
    void RewardMomentDialogClosed();
    void SpawnModelessDialog(UIDialog* dialog);
    void CleanupModelessDialogs();
    int CountModelessDialogs();
};

// INGTarget - Ingredients Target
class INGTarget {
public:
    struct TabInfo {
        int m_field00;    // 0x00
        short m_field04;  // 0x04
        u8 _pad[0x02];
        int m_field08;    // 0x08
        TabInfo();
    };

    struct IngInfo {
        int m_field00;    // 0x00
        int m_field04;    // 0x04
        IngInfo();
        void erase();
    };

    u8 _pad[0x8C];
    int m_mealType;           // 0x8C
    u8 _pad2[0x3C8];
    int m_rcpState;           // 0x458

    int is_group_meal() const;
    int RCPOnCancel();
    u32 get_blank_shader_id() const;
    static int SetRefrigeratorLevel(int level);
};

// ITBTarget - Intro Thought Balloon Target
class ITBTarget {
public:
    u8 _pad[0x88];
    int m_isActive;       // 0x88
    u8 _pad2[0x0C];
    int m_showBalloon;    // 0x98
    float m_userReadTime; // 0x9C

    void ShowIntroThoughtBalloon();
    void HideIntroThoughtBalloon();
    int IsIntroThoughtBalloonActive();
    float GetUserReadTime();
};

// K2YTarget - K2Y Target
class K2YTarget {
public:
    static int GetMode();
    static unsigned short* GetSavedFirstName();
    static unsigned short* GetSavedLastName();
};

// M2MTarget - Memory to Memory Target
class M2MTarget {
public:
    u8 _pad[0x10C];
    int m_device;           // 0x10C
    int m_saveGameID;       // 0x110
    u8 _pad2[0x7C];
    int m_playerNum;        // 0x190

    void ZeroInputCallback();
    int GetDevice();
    int GetSaveGameID();
    int GetPlayerNum();
    int IsItemEnabledSaveGameSelect(int index);
    int GetMemCardPort();
};

// MDITarget - Modeless Dialog Target
class MDITarget {
public:
    u8 _pad[0x88];
    int m_dialogCount;    // 0x88
    u8 _pad2[0x08];
    int m_isActive;       // 0x94
    u8 _pad3[0x04];
    int m_showDialog;     // 0x9C

    void ShowModelessDialog();
    void HideModelessDialog();
    void UpdateModelessDialogs();
    int IsModelessDialogActive();
    int CountModelessDialogs();
    void CleanupModelessDialogs();
};

// MMUTarget - Main Menu Target
class MMUTarget {
public:
    enum MMU_MODE {};

    u8 _pad[0x8C];
    int m_curMode;        // 0x8C
    int m_prevMode;       // 0x90
    u8 _pad2[0x10];
    int m_mainScreenChoice; // 0xA4
    u8 _pad3[0x10];
    int m_gameplayChoice;   // 0xB8
    u8 _pad4[0x40];
    int m_creditsClose;     // 0xFC

    static MMUTarget* GetSingleton();
    void OnCreditsClose();
    void ChangeScreenMode(MMU_MODE mode);
    void OnCancelDialog();
    void OnDialog2Close(int sel);
    void OnCancelDialog2();
    int GetCurrentMainScreenChoice() const;
    int GetCurrentGameplayChoice() const;
};

// MODTarget - Mood Target
class MODTarget {
public:
    u8 _pad[0x88];
    int m_isActive;       // 0x88
    u8 _pad2[0x04];
    int m_showMood;       // 0x90
    u8 _pad3[0x64];
    int m_textButtonPressed; // 0xF8

    void ShowMood();
    void HideMood();
    int IsMoodActive();
    void SetTextButtonPressed(bool pressed);
};

// MOTTarget - Motives Target
class MOTTarget {
public:
    u8 _pad[0x88];
    int m_isActive;       // 0x88
    u8 _pad2[0x08];
    int m_textButtonPressed; // 0x94
    u8 _pad3[0xC8];
    int m_showMotives;    // 0x160
    u8 _pad4[0x04];
    int m_personChanged;  // 0x168

    void ShowMotives();
    void HideMotives();
    void UpdateMotives();
    int IsMotivesActive();
    void SelectedPersonChanged(cXPerson* person);
    void SetTextButtonPressed(bool pressed);
};

// O2TTarget - Options Target
class O2TTarget {
public:
    void OnCancelDialog();
    void SaveGame(char* a, char* b);
};

// PAZBase - Pause Base
class PAZBase {
public:
    u8 _pad[0x84];
    int m_pausePlayer;    // 0x84

    void Update();
    int GetPausePlayer();
    void UpdateButtonVisibility();
};

// PAZTarget - Pause Target
class PAZTarget : public PAZBase {
public:
    ~PAZTarget();
    const char* GetTLA() const;
};

// PZ1Target - Pause 1 Target
class PZ1Target : public PAZBase {
public:
    const char* GetTLA() const;
};

// PCTTarget - Purchase/Catalog Target
class PCTTarget {
public:
    u8 _pad[0xB4];
    int m_gridPage;       // 0xB4
    u8 _pad2[0x38];
    int m_dialogState;    // 0xF0

    struct cCellInfo {
        cCellInfo();
    };

    unsigned int get_cell_info_array_index(unsigned int col) const;
    int get_motive_rating_label(unsigned int index, unsigned short* buf) const;
    int refresh_text_field(char* name, unsigned int index);
    int set_control_visible(char* name, bool visible);
    void buy_fail_dialog_selection_callback(int sel);
    void ZeroInputCallback();
    void DialogClosedCallback();
    void Draw(ERC* rc);

    static void static_GrabManipulatorCallback(InteractorModule::Interactor::CallbackData* data);
    static void static_PlaceModeCallback(InteractorModule::Interactor::CallbackData* data);
    static void static_WallManipulatorCallback(InteractorModule::Interactor::CallbackData* data);
    static void static_WallPainterCallback(InteractorModule::Interactor::CallbackData* data);
    static void static_FloorPainterCallback(InteractorModule::Interactor::CallbackData* data);
};

// PRGTarget - Progress Target
class PRGTarget {
public:
    void UpdateShaders();
};

// R2LTarget - R2L Target
class R2LTarget {
public:
    u8 _pad[0xB8];
    int m_summaryDialogState; // 0xB8

    void Update();
    void onHelpDialogSelection(int sel);
    void onSummaryDialogZeroInputCallback();
    void onSummaryDialogDialogClosedCallback();
    int RecordIndexToGridIndex(int index);
    int GridIndexToRecordIndex(int index);
    int OldGridIndexToRecordIndex(int index);
    int ScrollLeftEnabled();
    int ScrollRightEnabled();
};

// RCPTarget - Recipe Target
class RCPTarget {
public:
    void Draw(ERC* rc);
};

// SKLTarget - Skills Target
class SKLTarget {
public:
    u8 _pad[0x88];
    int m_isActive;       // 0x88
    u8 _pad2[0x04];
    int m_showSkills;     // 0x90
    u8 _pad3[0x08];
    int m_textButtonPressed; // 0x9C

    void ShowSkills();
    void HideSkills();
    int IsSkillsActive();
    void SetTextButtonPressed(bool pressed);
};

// WAFTarget - Wants and Fears Target
class WAFTarget {
public:
    u8 _pad[0x88];
    int m_isActive;       // 0x88
    u8 _pad2[0x04];
    int m_showWAF;        // 0x90
    u8 _pad3[0x08];
    int m_textButtonPressed; // 0x9C
    u8 _pad4[0x1D0];
    int m_glowEffectActive; // 0x270

    void ShowWantsAndFears();
    void HideWantsAndFears();
    int IsWantsAndFearsActive();
    void OnGlowEffectComplete();
    void SetTextButtonPressed(bool pressed);
};

// WXFTarget - WXF Target
class WXFTarget {
public:
    void Update();
};

// ============================================================================
// targets_cas - CAS UI target classes
// ============================================================================

// CASTarget - Create-A-Sim Target
// Note: This is a very large class (~0x1634 bytes)
class CASTarget {
public:
    u8 _pad[0x8C];
    int m_handleInput;        // 0x8C
    u8 _pad2[0x10];
    int m_prevUIFocus;        // 0xA0
    int m_curPartUIFocus;     // 0xA4
    u8 _pad3[0x5C];
    int m_cfcMode;            // 0x104
    u8 _pad4[0xE44];
    int m_simSlotBits;        // 0x1348
    int m_currentSimNumber;   // 0x134C
    u8 _pad5[0x04];
    int m_npcEditor;          // 0x1354
    u8 _pad5b[0x18];
    int m_geneticsTarget;     // 0x1370
    u8 _pad6[0x2BC];
    int m_isShuttingDown;     // 0x1630

    void DialogNoSelectionCallback();
    int IsShuttingdown();
    int GetPrevUIFocus();
    int GetCurPartUIFocus();
    int GetCurrentSimNumber();
    void SetHandleInput(bool handle);
    void* GetGeneticsTarget();
    void* GetNPCEditor();
    int HasSimInSlot(int slot) const;
    void* GetSimRenderer(int simIndex);
    static int GetLotNumberFromMode(int mode);
    void GotoBase();
    int CFCShouldGotoBodyScreenNext();
    int IsViewingCAR();
};

// CASBodyTarget - CAS Body Target
class CASBodyTarget {
public:
    void SetVariable(char* name, char* value);
    char* GetVariable(char* name);
};

// CASFashionTarget - CAS Fashion Target
class CASFashionTarget {
public:
    u8 _pad[0x8C];
    int m_focusValue;     // 0x8C

    void RandomizeFashion();
    void HandleEventChangeFocus(CasEventChangeFocus& event);
};

// CASMiscTarget - CAS Misc Target
class CASMiscTarget {
public:
    void SetVariable(char* name, char* value);
    char* GetVariable(char* name);
};

// CASMorphTarget - CAS Morph Target
class CASMorphTarget {
public:
    u8 _pad[0x1C0];
    int m_exitMorphDone;  // 0x1C0

    void ExitMorphScreenDone();
};

// CASPersonalTarget - CAS Personal Target
class CASPersonalTarget {
public:
    u8 _pad[0x8C];
    // char m_savedPersVals[]; // at offset 0x8C
    signed char GetSavedPersVal(signed char index);
};

// CASSelectionTarget - CAS Selection Target
class CASSelectionTarget {
public:
    u8 _pad[0x548];
    int m_gridColumns;    // 0x548

    unsigned int ConvertGridIdxToOptionIdx(unsigned int gridIdx);
    int ConvertColRowToOptionIdx(char col, int row);
    void ClearTextures();
};

// CASGeneticsTarget - CAS Genetics Target
class CASGeneticsTarget {
public:
    u8 _pad[0x94];
    void* m_casGenetics;  // 0x94
    u8 _pad2[0x268];
    int m_flags;          // 0x300

    void* GetCasGenetics();
    void SetWarnOnGenerate(bool warn);
    int GetWarnOnGenerate();
    void SetGenerateDefaultSim(bool generate);
    static int IsGenerating();
};

// CASRoommateTarget - CAS Roommate Target
class CASRoommateTarget {
public:
    u8 _pad[0x90];
    int m_selectedSlot;   // 0x90

    int GetSelectedSlot() const;
};

// Free functions
u32 get_blank_shader_id();
int DumpObjectFolder(char* folder);

#endif // TARGETS_H
