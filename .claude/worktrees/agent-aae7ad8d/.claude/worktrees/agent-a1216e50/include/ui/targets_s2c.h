#ifndef TARGETS_S2C_H
#define TARGETS_S2C_H

#include "types.h"

// Forward declarations
class ERC;
class cXPerson;
class Interaction;
class UIDialog;
class ObjSelector;
class WallTile;
struct structDrawCBparams;
class BString2;
class ERShader;

namespace InteractorModule {
    class Interactor {
    public:
        struct CallbackData {
            int m_field00;
            void* m_userData;  // offset 4
        };
    };

    namespace GrabManipulator {
        struct GrabManipulatorParams {
            u8 _pad[0x10];
            void* m_vtable; // offset 0x10
            ~GrabManipulatorParams();
        };
        struct CallbackData;
    }

    namespace PlaceManipulator {
        struct PlaceManipulatorParams {
            u8 _pad[0x10];
            void* m_vtable; // offset 0x10
            ~PlaceManipulatorParams();
        };
        struct CallbackData;
    }

    namespace FloorPainter {
        struct FloorPainterParams {
            u8 _pad[0x10];
            void* m_vtable; // offset 0x10
            ~FloorPainterParams();
        };
        struct CallbackData;
    }

    namespace WallManipulator {
        struct WallManipulatorParams {
            u8 _pad[0x10];
            void* m_vtable; // offset 0x10
            ~WallManipulatorParams();
        };
        struct CallbackData;
    }

    namespace WallPainter {
        struct WallPainterParams {
            u8 _pad[0x10];
            void* m_vtable; // offset 0x10
            ~WallPainterParams();
        };
        struct CallbackData;
    }
}

// ============================================================================
// UIDialog - base class for dialog callbacks
// ============================================================================
class UIDialog {
public:
    virtual void SelectionCallback(int sel);
    virtual void ZeroInputCallback();
    virtual void DialogClosedCallback();
    void SpawnDialog();
    void ChangeContinueType(int type);
};

// ============================================================================
// ACTTarget - Action Queue Target
// ============================================================================
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
    // Large functions (not decompiled here):
    // void RemoveAction(int, Interaction*);
    // void RemoveAllActions(int);
    // void SetIconDisable(bool);
};

// ============================================================================
// BBHTarget - Build/Buy HUD Target
// ============================================================================
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

// ============================================================================
// CRDTarget - Credits Target
// ============================================================================
class CRDTarget {
public:
    void Draw(ERC* rc);
    void UpdateCredits();
};

// ============================================================================
// CSMTarget - CSIM Target
// ============================================================================
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
    void SetIconDisable(bool disable);
};

// ============================================================================
// CSPTarget - CSP Target
// ============================================================================
class CSPTarget {
public:
    void Update();
    void onHelpDialogSelection(int sel);
};

// ============================================================================
// E2ETarget - EyeToy Target (S2C)
// ============================================================================
class E2ETarget {
public:
    u8 _pad[0xA8];
    int m_sliderIndex;     // 0xA8
    int m_sliderCount;     // 0xAC
    u8 _pad2[0x20];
    int m_eyeToyUnplugged; // 0x8C  (at offset 140 per disasm)
    u8 _pad3[0x30];
    int m_topLevelState;   // 0xD8

    // Reconstructed layout from disassembly:
    // 0x88 = m_isActive (136)
    // 0x8C = m_eyeToyUnplugged (140)
    // 0xA8 = m_sliderIndex (168)
    // 0xAC = m_sliderCount (172)
    // 0xC0 = m_savedSlotEyeToy (192)
    // 0xC8 = m_savedHue (200)
    // 0xCC = m_savedBrightness (204)
    // 0xD0 = m_savedSaturation (208)
    // 0xD4 = m_savedExposure (212)
    // 0xD8 = m_topLevelState (216)
    // 0x1F4 = m_helpDialog (500)

    int GetTopLevelState();
    void OnEnterSettings();
    void ShowHelp();
    void SetDefault(char* a, char* b);
    void SaveCurrentSettings(char* a, char* b);
    void SaveFrame(char* a, char* b);
    void OnUpKeyPressed(char* a, char* b);
    void OnDownKeyPressed(char* a, char* b);
    int IsEyeToyPluggedIn();
    static void EyeToyUnplugCallback(int param);
    void OnEyeToyUnplugged();
    void RestorePreviousSettings();
    void UpdateText();  // large, called by E2ETarget

    // Called by OnUpKeyPressed/OnDownKeyPressed
};

// ============================================================================
// FAMTarget - Family Target
// ============================================================================
class FAMTarget {
public:
    u8 _pad[0x14C];
    int m_selectedItem;   // 0x14C

    void Shutdown();
    void Update();
    void UpdateText();
    void OnLeftKeyPressed(char* a, char* b);
    void OnRightKeyPressed(char* a, char* b);
    void OnCancelDialog();
    void OnCircleKeyPressed(char* a, char* b);
    int ConvertSelectedFamilyIndexToActualGameIndex(int index);
    int ConvertSelectedLotIndexToActualGameIndex(int index);
    void UnloadScreen();
    void UpdateMenuState(char* a, char* b);
    void OnBackoutToMainMenuDialogClose(int sel);
    int GetFamilyInFamilyList(int index);
    int GetFamilyInLot(int index);
    int GetLotForFamily(int index);
    void LaunchLot();
};

// ============================================================================
// FCMTarget - Fire Code Meter Target
// ============================================================================
class FCMTarget {
public:
    u8 _pad[0x88];
    int m_isActive;       // 0x88
    u8 _pad2[0x04];
    int m_showMeter;      // 0x90
    u8 _pad3[0x0C];
    int m_meterHeight;    // 0xA0

    void HideFireCodeMeter();
    int IsFireCodeMeterActive();
    int GetFireCodeMeterLevel();
    void SetMeterHeight(int height);
};

// ============================================================================
// G2DTarget - G2D Target (game 2D UI)
// ============================================================================
class G2DTarget {
public:
    u8 _pad[0x84];
    int m_isSpawned;       // 0x84
    int m_isActive;        // 0x88
    u8 _padx[0xA8];
    int m_transitionState; // 0x134

    int IsG2DActive();
    int IsG2DSpawned();
    static int IsInitComplete();
    int HasPendingTransition();
    void PushAptButtonFilters();
    void UnloadUI();
};

// ============================================================================
// H2DTarget - HUD 2D Target
// ============================================================================
class H2DTarget {
public:
    u8 _pad[0x88];
    void* m_modTargets[2];  // 0x88, 0x8C (offsets 136-143)
    void* m_csimTargets[2]; // 0x90, 0x94 (offsets 144-151)
    u8 _pad1a[0x24];
    void* m_intTargets[2];  // 0xBC, 0xC0 (offsets 188-195)
    u8 _pad2[0x08];
    void* m_mdiTarget;      // 0xC8 (offset 200)
    int m_pausePlayer;      // 0xD0 (offset 208)
    u8 _pad3[0x08];
    int m_rewardClosed;     // 0xE0 (offset 224)

    void Draw(ERC* rc);
    int GetPausePlayer();
    void RewardMomentDialogClosed();
    void SpawnModelessDialog(UIDialog* dialog);
    void CleanupModelessDialogs();
    int CountModelessDialogs();
    void RemoveAction(int player, Interaction* interaction);
    void RemoveAllActions(int player);
    void SKLInWarning(int player, bool warning);
    void MOTInWarning(int player, bool warning);
    void WAFInWarning(int player, bool warning, bool extra);
    void SetMoodMeterValue(int player, float value, bool extra);
    void SetInteractionDisplayValues(int player, unsigned int a, unsigned int b);
    void TriggerInteractionAnimation(int player, unsigned int a, unsigned int b, unsigned int c);
    void DisplayPaused();
    void DisplayFastForward();
    void CSIMSetIconDisable(int player, bool disable);
    void INTMirrorUpArrow(int player, bool state);
    int ShouldH2DBeVisible(int player) const;
    void ACTCancelModeExited(int player);
    void CSIMActive(int player, bool active);
};

// ============================================================================
// INGTarget - Ingredients Target
// ============================================================================
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
    u8 _pad2[0x120];
    void* m_gridIngredients[12]; // 0x1B0 (offset 432, 12 pointers)
    void* m_mixIngredients[4];   // 0x1E0 (offset 480, 4x8 bytes = 32 bytes, next at 0x200)
    u8 _pad3[0x238];
    int m_rcpState;           // 0x458 (offset 1112)

    int is_group_meal() const;
    int RCPOnCancel();
    u32 get_blank_shader_id() const;
    static int SetRefrigeratorLevel(int level);
    void exit_ingredients_dialog_selection_callback(int sel);
    IngInfo* get_mix_ingredient(short id) const;
    IngInfo* get_current_ingredient();
    int get_ingredient_type(IngInfo& info) const;
    IngInfo* get_grid_ingredient(short id);
};

// ============================================================================
// ITBTarget - Intro Thought Balloon Target
// ============================================================================
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

// ============================================================================
// K2YTarget - K2Y Target
// ============================================================================
class K2YTarget {
public:
    static int GetMode();
    static unsigned short* GetSavedFirstName();
    static unsigned short* GetSavedLastName();
    static int IsModeValid();
};

// ============================================================================
// M2MTarget - Memory to Memory Target
// ============================================================================
class M2MTarget {
public:
    struct ResultStruct {
        int m_field00;
        int m_field04;
        int m_field08;
    };

    u8 _pad[0x10C];
    int m_device;           // 0x10C
    int m_saveGameID;       // 0x110
    u8 _pad2[0x7C];
    int m_playerNum;        // 0x190

    void ZeroInputCallback();
    int GetDevice();
    void SetDevice(int device);
    int GetSaveGameID();
    int GetPlayerNum();
    int IsItemEnabledSaveGameSelect(int index);
    int GetMemCardPort();
    void OnSlotSelectItemSelected(int slot, ResultStruct& result);
    int OnGetNumItems(ResultStruct& result);
};

// ============================================================================
// MDITarget - Modeless Dialog Target
// ============================================================================
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

// ============================================================================
// MMUTarget - Main Menu Target
// ============================================================================
class MMUTarget {
public:
    enum MMU_MODE {};

    u8 _pad[0x8C];
    int m_curMode;          // 0x8C
    int m_prevMode;         // 0x90
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
    void OnLeftKeyPressed(char* a, char* b);
    void OnRightKeyPressed(char* a, char* b);
    void OnTopLevelChoiceChange();
    void OnGameplayLevelChoiceChange();
    void OnNumberOfPlayersChoiceChange();
};

// ============================================================================
// MODTarget - Mood Target
// ============================================================================
class MODTarget {
public:
    u8 _pad[0x88];
    int m_isActive;          // 0x88
    u8 _pad2[0x04];
    int m_showMood;          // 0x90
    u8 _pad3[0x64];
    int m_textButtonPressed; // 0xF8

    void ShowMood();
    void HideMood();
    int IsMoodActive();
    void SetTextButtonPressed(bool pressed);
    // Large functions:
    // void InWarning(int mode, bool flag);
    // void SetMoodMeterValue(float value, bool flag);
    // void DisplayPaused();
    // void DisplayFastForward();
};

// ============================================================================
// MOTTarget - Motives Target
// ============================================================================
class MOTTarget {
public:
    u8 _pad[0x88];
    int m_isActive;          // 0x88
    u8 _pad2[0x08];
    int m_textButtonPressed; // 0x94
    u8 _pad3[0xC8];
    int m_showMotives;       // 0x160
    u8 _pad4[0x04];
    int m_personChanged;     // 0x168

    void ShowMotives();
    void HideMotives();
    void UpdateMotives();
    int IsMotivesActive();
    void SelectedPersonChanged(cXPerson* person);
    void SetTextButtonPressed(bool pressed);
};

// ============================================================================
// O2TTarget - Options Target
// ============================================================================
class O2TTarget {
public:
    u8 _pad[0x90];
    int m_showOptions;    // 0x90
    u8 _pad2[0x1BC];
    int m_dialogState;    // 0x250

    void OnCancelDialog();
    void SaveGame(char* a, char* b);
    void RememberAudioOptions();
    void RememberGameOptions();
    void RestoreGameOptions();
    void QuitGame(char* a, char* b);
};

// ============================================================================
// PAZBase - Pause Base
// ============================================================================
class PAZBase {
public:
    u8 _pad[0x84];
    int m_pausePlayer;    // 0x84

    void Update();
    int GetPausePlayer();
    void UpdateButtonVisibility();
};

// ============================================================================
// PAZTarget - Pause Target
// ============================================================================
class PAZTarget : public PAZBase {
public:
    u8 _pad_paz[0x04];
    int m_field8C;  // offset 0x8C from PAZBase start (actually 0x80 + 0x0C = 140 total)

    ~PAZTarget();
    const char* GetTLA() const;
};

// ============================================================================
// PZ1Target - Pause 1 Target
// ============================================================================
class PZ1Target : public PAZBase {
public:
    const char* GetTLA() const;
};

// ============================================================================
// PCTTarget - Purchase/Catalog Target
// ============================================================================
class PCTTarget {
public:
    struct cCellInfo {
        int m_field00;
        int m_field04;
        int m_field08;
        int m_field0C;
        int m_field10;
        int m_field14;
        cCellInfo();
    };

    u8 _pad[0xB4];
    int m_gridPage;       // 0xB4
    u8 _pad1a[0x10];
    void* m_drawCallback; // 0xE4 (offset 228)
    u8 _pad2[0x08];
    int m_dialogState;    // 0xF0

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

// ============================================================================
// PRGTarget - Progress Target
// ============================================================================
class PRGTarget {
public:
    void UpdateShaders();
};

// ============================================================================
// R2LTarget - R2L Target
// ============================================================================
class R2LTarget {
public:
    u8 _pad[0x9C];
    int m_totalRecords;        // 0x9C (offset 156)
    u8 _pad1a[0x04];
    int m_currentPage;         // 0xA4 (offset 164)
    int m_oldPage;             // 0xA8 (offset 168)
    u8 _pad2[0x0C];
    int m_summaryDialogState;  // 0xB8 (offset 184)

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

// ============================================================================
// RCPTarget - Recipe Target
// ============================================================================
class RCPTarget {
public:
    void Draw(ERC* rc);
};

// ============================================================================
// SKLTarget - Skills Target
// ============================================================================
class SKLTarget {
public:
    u8 _pad[0x88];
    int m_isActive;          // 0x88
    u8 _pad2[0x04];
    int m_showSkills;        // 0x90
    u8 _pad3[0x08];
    int m_textButtonPressed; // 0x9C

    void ShowSkills();
    void HideSkills();
    int IsSkillsActive();
    void SetTextButtonPressed(bool pressed);
};

// ============================================================================
// WAFTarget - Wants and Fears Target
// ============================================================================
class WAFTarget {
public:
    u8 _pad[0x88];
    int m_isActive;          // 0x88
    u8 _pad2[0x04];
    int m_showWAF;           // 0x90
    u8 _pad3[0x08];
    int m_textButtonPressed; // 0x9C
    u8 _pad4[0x1D0];
    int m_glowEffectActive;  // 0x270

    static WAFTarget* GetSingleton();

    void ShowWantsAndFears();
    void HideWantsAndFears();
    int IsWantsAndFearsActive();
    void OnGlowEffectComplete();
    void SetTextButtonPressed(bool pressed);
};

// ============================================================================
// WXFTarget - WXF Target
// ============================================================================
class WXFTarget {
public:
    u8 _pad[0x130];
    int m_helpState;  // 0x130 (offset 304)

    void Update();
    void onHelpDialogSelection(int sel);
};

// ============================================================================
// Free functions from targets_s2c
// ============================================================================
u32 get_blank_shader_id();
int DumpObjectFolder(char* folder);
int GetResDataFromSelector(ObjSelector* selector);
int IsSkillCatalogRating(int rating);
int filter_wallpaper(WallTile* tile);

// External function used by GetTheExposureHandler
float GetTheExposureHandler();

#endif // TARGETS_S2C_H
