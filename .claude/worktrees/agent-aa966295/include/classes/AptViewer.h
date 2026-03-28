#ifndef APTVIEWER_H
#define APTVIEWER_H

#include "types.h"

// AptViewer - struct layout extracted from assembly analysis
// Estimated minimum size: 0x468 (1128 bytes)
// 19 known fields (2 named), 65 methods

class AptViewer {
public:
    // Constructors / Destructors
    AptViewer(void)  // 0x8002328C
    ~AptViewer(void);  // 0x8002341C

    // Methods
    void SetUnmappedControllerRead(int);  // 0x8000E434 (40B)
    void SetUseButtonFilters(bool);  // 0x8000E45C (40B)
    /* ? */ GetNormalizedProjection(void);  // 0x8001923C (68B)
    void casButtonSequencer(void);  // 0x8002654C (280B)
    void NewReadController(int, bool, int, bool);  // 0x80024AA4 (328B)
    void UpdateAll(void);  // 0x80023B8C (356B)
    void Draw(ERC *);  // 0x80023CF0 (2084B)
    void AllowControllerReading(bool);  // 0x8002643C (148B)
    void UnLoad(void);  // 0x80024668 (140B)
    void CallFunction(char *, char *, char *, int,...);  // 0x800234AC (96B)
    void NewCallFunction(char *, char *, char *, int,...);  // 0x8002350C (700B)
    void NewCallFunction2(char *, char *, char *, int, char **);  // 0x800237C8 (700B)
    void Shutdown(void);  // 0x80023A84 (68B)
    void Init(UIObjectBase *);  // 0x80023AC8 (156B)
    void Update(void);  // 0x80023B64 (40B)
    void Load(char *, bool);  // 0x80024514 (200B)
    void LoadActionScript(char *, bool);  // 0x800245DC (140B)
    void ReadController(int, bool, int, bool);  // 0x800246F4 (172B)
    void RepeatClear(int, int);  // 0x800247A0 (172B)
    void RepeatCheck(int, int);  // 0x8002484C (600B)
    void OnePlayerReadController(int, int);  // 0x80024BEC (2600B)
    /* ? */ GetCurrentAptButtonFilter(int);  // 0x80026194 (192B)
    void PushAptButtonFilter(int, char *);  // 0x80025614 (692B)
    /* ? */ GetPlayersController(int);  // 0x80026254 (296B)
    void PopAptButtonFilter(int, unsigned int);  // 0x800258C8 (828B)
    void AddCmdToAptButtonFilter(int, unsigned int, ECTRL_CMD);  // 0x80025C04 (712B)
    void RemoveCmdFromAptButtonFilter(int, unsigned int, ECTRL_CMD);  // 0x80025ECC (712B)
    void NewSetMessageHandler(UIObjectBase *);  // 0x8002637C (72B)
    void NewRemoveMessageHandler(UIObjectBase *);  // 0x800263C4 (72B)
    void UIOn(void);  // 0x8002640C (48B)
    bool IsWaitingForPlayerInput(void);  // 0x800264D0 (80B)
    bool IsReadControllerActive(void);  // 0x80026520 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (Draw, Init)
    u8 _pad_004[0x38];  // 0x004
    u32 m_field_03C;  // 0x03C [R] (OnePlayerReadController)
    u32 m_field_040;  // 0x040 [R] (OnePlayerReadController)
    u8 _pad_044[4];  // 0x044
    u32 m_field_048;  // 0x048 [R] (OnePlayerReadController)
    u32 m_field_04C;  // 0x04C [R] (OnePlayerReadController)
    u8 _pad_050[0x40];  // 0x050
    u32 m_field_090;  // 0x090 [R] (OnePlayerReadController)
    u8 _pad_094[0x2BC];  // 0x094
    u32 m_field_350;  // 0x350 [R/W] (AptViewer, Draw, Load, ...)
    u32 m_field_354;  // 0x354 [R/W] (AptViewer, Draw)
    u8 _pad_358[0x1C];  // 0x358
    u32 m_field_374;  // 0x374 [R/W] (AptViewer, ~AptViewer)
    f32 m_field_378;  // 0x378 [W] (AptViewer)
    f32 m_field_37C;  // 0x37C [W] (AptViewer)
    u8 _pad_380[0x20];  // 0x380
    u32 m_field_3A0;  // 0x3A0 [R/W] (AptViewer, Init)
    u32 m_field_3A4;  // 0x3A4 [R/W] (AptViewer, OnePlayerReadController)
    u32 m_currentAptButtonFilter;  // 0x3A8 [R/W] (AddCmdToAptButtonFilter, AptViewer, GetCurrentAptButtonFilter, ...)
    u32 m_field_3AC;  // 0x3AC [R/W] (AptViewer, NewReadController)
    u8 _pad_3B0[0xA8];  // 0x3B0
    u32 m_field_458;  // 0x458 [W] (AptViewer, Draw)
    u32 m_field_45C;  // 0x45C [W] (AptViewer, Draw)
    u32 m_field_460;  // 0x460 [W] (AptViewer, Draw)
    u32 m_field_464;  // 0x464 [W] (AptViewer, Draw)
};

#endif // APTVIEWER_H
