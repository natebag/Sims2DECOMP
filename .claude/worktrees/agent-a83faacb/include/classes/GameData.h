#ifndef GAMEDATA_H
#define GAMEDATA_H

#include "types.h"

// GameData - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1E34 (7732 bytes)
// 53 known fields (3 named), 112 methods

class GameData {
public:
    // Constructors / Destructors
    GameData(void)  // 0x800A880C
    ~GameData(void);  // 0x800A8A00

    // Methods
    void SetFreePlayMode(bool);  // 0x8000E1CC (40B)
    void SetAuthorMode(bool);  // 0x8000E1F4 (40B)
    void CopyrightFadeOut(void);  // 0x8000E21C (60B)
    /* ? */ GetSelectedFamily(void);  // 0x8000E1A0 (44B)
    bool IsTwoPlayerMode(void);  // 0x80031838 (44B)
    bool IsAuthorMode(void);  // 0x8004D36C (44B)
    /* ? */ GetPlayer(int);  // 0x8008D564 (196B)
    /* ? */ GetPlayerCamera(int);  // 0x800A7D48 (208B)
    /* ? */ GetLocalizedSims2Logo(void);  // 0x800AD474 (268B)
    void SetBlackGraphicsBackgroundColor(void);  // 0x800AD854 (148B)
    void SetTwoPlayerMode(bool);  // 0x800ACDF4 (140B)
    void CopyrightUpdate(float);  // 0x800ACFA4 (368B)
    void CopyrightDraw(ERC *);  // 0x800AD114 (288B)
    void VersionInfoDraw(ERC *);  // 0x800AD234 (576B)
    void LoadDefaultNeighborhood(void);  // 0x800A8D14 (772B)
    bool IsPlayerConnected(unsigned char);  // 0x800ACE80 (176B)
    void GamePlayShutdown(void);  // 0x800A8BA0 (132B)
    void GamePlayReset(void);  // 0x800A8C24 (212B)
    bool IsFreePlayMode(void);  // 0x800B1C64 (44B)
    void LoadSavedNeighborhood(void);  // 0x800A9018 (296B)
    void PrepareSimData(int, int);  // 0x800A9140 (756B)
    void ReplaceSimData(int, bool, int, int);  // 0x800A9434 (812B)
    void LoadCreateASim(int, int);  // 0x800A9760 (76B)
    void SaveCreateASim(void);  // 0x800A97AC (184B)
    void PlayerEnterHouse(void);  // 0x800A9864 (1656B)
    void SetInitialSimSelection(int, int);  // 0x800B1B3C (56B)
    void PrepCreateAFamilyData(int);  // 0x800A9EDC (2564B)
    void CreateAFamilyAddFamilyMember(Family *);  // 0x800AA8E0 (404B)
    void StoreCreateAFamilyData(void);  // 0x800AAA74 (3824B)
    void SaveCreateAFamily(void);  // 0x800AB964 (188B)
    void SystemPreUpdate(void);  // 0x800ABA20 (1192B)
    void SystemPreDraw(ERC *);  // 0x800AC744 (220B)
    void SystemPostUpdate(void);  // 0x800AC820 (40B)
    bool IsDrawCtrlMessageDisabled(void);  // 0x800AC848 (68B)
    void SetCtrlDrawMessageDisable(GameData::eCtrlDisableBits);  // 0x800AC88C (76B)
    void ClearCtrlDrawMessageDisable(GameData::eCtrlDisableBits);  // 0x800AC8D8 (80B)
    void SystemPostDraw(ERC *);  // 0x800AC928 (1228B)
    void GotoLiveMode(void);  // 0x800ACF30 (116B)
    /* ? */ GetLocalizedEAMovie(void);  // 0x800AD580 (484B)
    /* ? */ GetLocalizedSimsIntroMovie(void);  // 0x800AD764 (120B)
    /* ? */ GetLocalizedSimsEndingMovie(void);  // 0x800AD7DC (120B)
    void SetUglyGraphicsBackgroundColor(void);  // 0x800AD8E8 (164B)
    void UseConfigOptions(void);  // 0x800AD98C (68B)
    void StageInitTiming(float *, int);  // 0x800AD9D0 (856B)
    void StageStartFrame(void);  // 0x800ADD28 (68B)
    void StageEndFrame(char *, int, int);  // 0x800ADD6C (696B)
    void StageEnd(char *, char *, bool);  // 0x800AE024 (252B)
    void StageOutputActualTimes(char *);  // 0x800AE120 (44B)
    void GotoXamMode(int, int, int, int);  // 0x800AE14C (732B)
    /* ? */ GetBuildBuyPlayer(void);  // 0x800AE428 (52B)
    void SetBuildBuyPlayer(int);  // 0x800AE45C (240B)
    /* ? */ GetSelectedPlayerFamily(void);  // 0x800AE54C (128B)
    /* ? */ GetMemoryMeterWin(void);  // 0x800C1884 (44B)
    void SetInLevel(bool);  // 0x801B2068 (40B)
    /* ? */ GetGameState(void);  // 0x801C01C4 (44B)
    /* ? */ GetUnlockFamilyNum(void);  // 0x801C0254 (40B)
    void SetGameState(GameData::GameState);  // 0x801D4954 (40B)
    void SetNewStoryGame(bool);  // 0x801D4A40 (40B)
    void CopyrightFadeIn(void);  // 0x801D9240 (56B)
    void CopyrightIsFadedIn(void);  // 0x801D9278 (52B)
    void CopyrightIsFadedOut(void);  // 0x801D931C (52B)
    void CopyrightIsFadeOut(void);  // 0x801D92E8 (52B)
    void CopyrightUpLongEnough(void);  // 0x801D9350 (92B)
    void SetSelectedFamily(int);  // 0x801E9728 (40B)
    /* ? */ GetInitialSimSelection(int);  // 0x802E7F04 (60B)
    /* ? */ GetPlayerPiMenu(int);  // 0x804A1D10 (208B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (CreateAFamilyAddFamilyMember, GameData, LoadDefaultNeighborhood, ...)
    s16 m_field_004;  // 0x004 [R/W] (PlayerEnterHouse, PrepCreateAFamilyData, PrepareSimData)
    u8 _pad_006[0x1E];  // 0x006
    u32 m_field_024;  // 0x024 [R] (StoreCreateAFamilyData)
    u8 _pad_028[4];  // 0x028
    u32 m_field_02C;  // 0x02C [W] (GameData, SystemPreUpdate)
    u32 m_bIsPlayerConnected;  // 0x030 [R/W] (GameData, IsPlayerConnected, SystemPreUpdate)
    u32 m_bIsPlayerConnected_034;  // 0x034 [R/W] (GameData, IsPlayerConnected, PlayerEnterHouse, ...)
    u32 m_field_038;  // 0x038 [R/W] (PrepCreateAFamilyData, StoreCreateAFamilyData)
    u32 m_field_03C;  // 0x03C [W] (GameData)
    u32 m_field_040;  // 0x040 [W] (GameData)
    u32 m_field_044;  // 0x044 [W] (GameData)
    u32 m_field_048;  // 0x048 [W] (GameData)
    u32 m_field_04C;  // 0x04C [W] (GameData)
    u32 m_field_050;  // 0x050 [W] (GameData)
    u32 m_field_054;  // 0x054 [R] (~GameData)
    u8 _pad_058[0x14];  // 0x058
    u32 m_field_06C;  // 0x06C [R/W] (GameData, ~GameData)
    u32 m_field_070;  // 0x070 [R/W] (GameData, ~GameData)
    u32 m_field_074;  // 0x074 [R/W] (GameData, ~GameData)
    u32 m_field_078;  // 0x078 [R/W] (GameData, PrepCreateAFamilyData, PrepareSimData, ...)
    u8 _pad_07C[4];  // 0x07C
    u32 m_field_080;  // 0x080 [W] (GameData)
    u32 m_field_084;  // 0x084 [W] (GameData, GamePlayReset)
    u16 m_field_086;  // 0x086 [W] (LoadDefaultNeighborhood, LoadSavedNeighborhood)
    u16 m_field_088;  // 0x088 [W] (LoadDefaultNeighborhood, PlayerEnterHouse)
    u8 _pad_08A[2];  // 0x08A
    u32 m_field_08C;  // 0x08C [R/W] (GameData, PrepCreateAFamilyData, StoreCreateAFamilyData)
    u32 m_field_090;  // 0x090 [W] (GameData)
    u32 m_field_094;  // 0x094 [W] (GameData)
    u32 m_field_098;  // 0x098 [W] (GameData)
    u32 m_field_09C;  // 0x09C [W] (GameData)
    u32 m_field_0A0;  // 0x0A0 [W] (GameData)
    u16 m_field_0A4;  // 0x0A4 [W] (GameData, ReplaceSimData)
    u8 _pad_0A6[2];  // 0x0A6
    u32 m_field_0A8;  // 0x0A8 [W] (GameData)
    u8 _pad_0AC[4];  // 0x0AC
    u32 m_field_0B0;  // 0x0B0 [W] (GameData)
    u32 m_field_0B4;  // 0x0B4 [W] (GameData)
    u32 m_field_0B8;  // 0x0B8 [W] (GameData)
    u32 m_field_0BC;  // 0x0BC [W] (GameData)
    u32 m_field_0C0;  // 0x0C0 [W] (GameData)
    u32 m_field_0C4;  // 0x0C4 [W] (GameData)
    u32 m_field_0C8;  // 0x0C8 [W] (GameData)
    u32 m_field_0CC;  // 0x0CC [W] (GameData)
    u8 _pad_0D0[8];  // 0x0D0
    u32 m_field_0D8;  // 0x0D8 [W] (GameData)
    f32 m_field_0DC;  // 0x0DC [W] (GameData)
    f32 m_field_0E0;  // 0x0E0 [W] (GameData)
    u32 m_field_0E4;  // 0x0E4 [W] (GameData, GamePlayReset)
    u32 m_field_0E8;  // 0x0E8 [W] (GameData, GamePlayReset)
    u32 m_field_0EC;  // 0x0EC [W] (GameData)
    u32 m_field_0F0;  // 0x0F0 [R/W] (GameData, GamePlayReset, SystemPostDraw)
    u8 _pad_0F4[0x20];  // 0x0F4
    u32 m_field_114;  // 0x114 [R/W] (CopyrightUpdate, GameData)
    f32 m_field_118;  // 0x118 [R/W] (CopyrightDraw, CopyrightUpdate, GameData)
    f32 m_field_11C;  // 0x11C [W] (CopyrightUpdate, GameData)
    f32 m_field_120;  // 0x120 [W] (GameData)
    u32 m_field_124;  // 0x124 [W] (GameData)
    u32 m_field_128;  // 0x128 [W] (GameData)
    u8 _pad_12C[0xDC];  // 0x12C
    u32 m_field_208;  // 0x208 [R] (SystemPreUpdate)
    u8 _pad_20C[0x1C24];  // 0x20C
    f32 m_field_1E30;  // 0x1E30 [R] (SystemPostDraw)
};

#endif // GAMEDATA_H
