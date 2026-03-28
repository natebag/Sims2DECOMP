#ifndef CASSCENE_H
#define CASSCENE_H

#include "types.h"

// CasScene - struct layout extracted from assembly analysis
// Estimated minimum size: 0xB20 (2848 bytes)
// 27 known fields (15 named), 50 methods

class CasScene {
public:
    // Constructors / Destructors
    CasScene(void)  // 0x80443630
    ~CasScene(void);  // 0x8044392C

    // Methods
    void Init(void);  // 0x80443BA4 (228B)
    void LoadLights(char *, int);  // 0x80444798 (1424B)
    void RepositionCamera(unsigned int, float, float);  // 0x80444F94 (1088B)
    void SetMediator(CasMediator *);  // 0x804440B4 (64B)
    /* ? */ GetObjectPosition(unsigned int, EVec3 &, float &);  // 0x804461A4 (416B)
    void DrawRoomClothing(ERC *, EMat4 &);  // 0x804444CC (640B)
    /* ? */ GetRoomFromCameraAngle(unsigned int);  // 0x80449C8C (44B)
    /* ? */ GetAmbientScoreName(void);  // 0x8044A288 (56B)
    bool IsCameraMoving(void);  // 0x80449BD8 (92B)
    void InitCamera(unsigned int);  // 0x804453D4 (492B)
    void Reload(void);  // 0x80443C88 (1068B)
    void Update(float);  // 0x804440F4 (108B)
    void UpdateCamera(float);  // 0x804455C0 (1448B)
    void Draw(ERC *);  // 0x80444160 (620B)
    void SetUpWindow(ERC *);  // 0x80445B68 (416B)
    void DrawRoom(ERC *, CasScene::RoomId, EMat4 &);  // 0x804443CC (256B)
    /* ? */ Get3DWindow(void);  // 0x80449C60 (44B)
    void SetSceneLighting(int, bool);  // 0x80444F28 (108B)
    void SetCameraParams(float, float, float);  // 0x8044474C (76B)
    void SetLights(int);  // 0x80444D28 (512B)
    void HandleEventChangeFocus(CasEventChangeFocus &);  // 0x80445D08 (1180B)
    /* ? */ GetCameraAngle(EVec3 *, EVec3 *);  // 0x80449B70 (104B)
    /* ? */ GetLights(void);  // 0x80449C34 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (CasScene, DrawRoomClothing, UpdateCamera)
    f32 m_field_004;  // 0x004 [R/W] (CasScene, Draw, DrawRoom, ...)
    f32 m_camera_008;  // 0x008 [R/W] (LoadLights, RepositionCamera, UpdateCamera)
    u8 _pad_00C[0xA74];  // 0x00C
    u32 m_lights;  // 0xA80 [R/W] (CasScene, DrawRoomClothing, Reload, ...)
    u32 m_field_A84;  // 0xA84 [R/W] (CasScene, DrawRoomClothing, Reload, ...)
    u32 m_field_A88;  // 0xA88 [R/W] (CasScene, DrawRoomClothing, Reload, ...)
    u32 m_field_A8C;  // 0xA8C [R/W] (CasScene, LoadLights, ~CasScene)
    f32 m_field_A90;  // 0xA90 [R/W] (CasScene, InitCamera, RepositionCamera, ...)
    u8 _pad_A94[8];  // 0xA94
    f32 m_field_A9C;  // 0xA9C [R/W] (CasScene, InitCamera, RepositionCamera, ...)
    u8 _pad_AA0[8];  // 0xAA0
    f32 m_field_AA8;  // 0xAA8 [R/W] (CasScene, InitCamera, RepositionCamera, ...)
    f32 m_camera_AAC;  // 0xAAC [R/W] (CasScene, RepositionCamera, UpdateCamera)
    f32 m_camera_AB0;  // 0xAB0 [R/W] (CasScene, RepositionCamera, UpdateCamera)
    u32 m_field_AB4;  // 0xAB4 [R/W] (CasScene, Draw, InitCamera, ...)
    u32 m_camera_AB8;  // 0xAB8 [W] (CasScene, RepositionCamera, UpdateCamera)
    f32 m_upWindow;  // 0xABC [R/W] (CasScene, DrawRoomClothing, SetUpWindow)
    u32 m_field_AC0;  // 0xAC0 [R/W] (CasScene, HandleEventChangeFocus, Init, ...)
    f32 m_camera_AC4;  // 0xAC4 [R/W] (CasScene, RepositionCamera, UpdateCamera)
    u8 _pad_AC8[8];  // 0xAC8
    f32 m_field_AD0;  // 0xAD0 [R/W] (CasScene, InitCamera, RepositionCamera, ...)
    u8 _pad_AD4[8];  // 0xAD4
    f32 m_camera_ADC;  // 0xADC [R/W] (CasScene, RepositionCamera, UpdateCamera)
    u8 _pad_AE0[8];  // 0xAE0
    f32 m_camera_AE8;  // 0xAE8 [R/W] (CasScene, RepositionCamera, UpdateCamera)
    u8 _pad_AEC[8];  // 0xAEC
    f32 m_camera_AF4;  // 0xAF4 [R/W] (CasScene, RepositionCamera, UpdateCamera)
    u8 _pad_AF8[8];  // 0xAF8
    f32 m_field_B00;  // 0xB00 [R/W] (CasScene, InitCamera, RepositionCamera, ...)
    u8 _pad_B04[8];  // 0xB04
    f32 m_camera_B0C;  // 0xB0C [R/W] (CasScene, RepositionCamera, UpdateCamera)
    f32 m_upWindow_B10;  // 0xB10 [R/W] (CasScene, SetUpWindow)
    f32 m_upWindow_B14;  // 0xB14 [R/W] (CasScene, SetUpWindow)
    u32 m_upWindow_B18;  // 0xB18 [R/W] (CasScene, DrawRoomClothing, SetUpWindow, ...)
    u32 m_field_B1C;  // 0xB1C [R/W] (CasScene, DrawRoomClothing, HandleEventChangeFocus)
};

#endif // CASSCENE_H
