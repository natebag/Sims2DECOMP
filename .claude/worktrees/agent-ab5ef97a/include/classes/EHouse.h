#ifndef EHOUSE_H
#define EHOUSE_H

#include "types.h"

// EHouse - struct layout extracted from assembly analysis
// Estimated minimum size: 0x3F8 (1016 bytes)
// 27 known fields (11 named), 58 methods

class EHouse {
public:
    // Constructors / Destructors
    EHouse(EVec2 &, int, ERLevel *, bool, bool, bool, bool)  // 0x8005F22C
    ~EHouse(void);  // 0x8005F6BC

    // Methods
    /* ? */ GetLotNum(void);  // 0x8000E4B0 (44B)
    /* ? */ GetWeather(void);  // 0x8000E4DC (48B)
    /* ? */ GetRLevel(void);  // 0x8000E484 (44B)
    /* ? */ GetHouseOff(void);  // 0x8004D408 (44B)
    void Init(void);  // 0x8005F724 (256B)
    /* ? */ GetHouseName(void);  // 0x8005F1E8 (68B)
    void Cleanup(void);  // 0x800618CC (468B)
    void BuildHouse(void);  // 0x8005F824 (1220B)
    void InitRoomLighting(void);  // 0x80062180 (684B)
    void SetWallState(EWallUpDownStateType);  // 0x8005FCE8 (84B)
    void SetNextWallMode(void);  // 0x8005FD3C (244B)
    void Draw(ERC *);  // 0x8006098C (260B)
    void Update(void);  // 0x80060A90 (948B)
    void Refresh(void);  // 0x800626FC (60B)
    void UpdateWeather(void);  // 0x80061344 (1416B)
    void UpdateRoomAmbient(LevelLightingEntry &);  // 0x80060E44 (420B)
    void UpdateRoomLights(void);  // 0x80061CF0 (608B)
    void TriggerLightningEffect(void);  // 0x800610FC (32B)
    void WeatherChanging(void);  // 0x8006111C (228B)
    void Fair(void);  // 0x80061200 (84B)
    void Rain(void);  // 0x80061254 (84B)
    void CleanUpRoomLights(void);  // 0x80062548 (332B)
    void DestroyWalls(void);  // 0x80061AA0 (112B)
    void ReCalcHouse(void);  // 0x80061B10 (480B)
    bool IsBuilt(void);  // 0x800693A4 (44B)
    void SetLightIntensityScaleFromRoom(EILight *);  // 0x80061F50 (360B)
    /* ? */ GetRoomAmbLight(int);  // 0x8006242C (284B)
    void InsertHouseObject(EOrderTableData *);  // 0x80062694 (104B)
    /* ? */ GetWallUpDownState(void);  // 0x8007FD14 (44B)
    /* ? */ GetRainBlend(void);  // 0x800D7EE4 (44B)
    /* ? */ GetERModel(void);  // 0x80110988 (44B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_nextWallMode;  // 0x000 [R/W] (BuildHouse, EHouse, InitRoomLighting, ...)
    u16 m_field_002;  // 0x002 [R] (InitRoomLighting)
    u32 m_field_004;  // 0x004 [R/W] (BuildHouse, Cleanup, EHouse, ...)
    u32 m_nextWallMode_008;  // 0x008 [R/W] (BuildHouse, DestroyWalls, Draw, ...)
    u32 m_field_00C;  // 0x00C [W] (EHouse, Update)
    u16 m_field_010;  // 0x010 [R/W] (BuildHouse, Cleanup, EHouse, ...)
    u8 _pad_012[2];  // 0x012
    u32 m_lightIntensityScaleFromRoom;  // 0x014 [R/W] (BuildHouse, EHouse, ReCalcHouse, ...)
    u32 m_field_018;  // 0x018 [R/W] (BuildHouse, Cleanup, EHouse, ...)
    u32 m_nextWallMode_01C;  // 0x01C [R/W] (BuildHouse, CleanUpRoomLights, Cleanup, ...)
    u32 m_field_020;  // 0x020 [W] (Cleanup, EHouse)
    u32 m_nextWallMode_024;  // 0x024 [R/W] (EHouse, SetNextWallMode)
    u32 m_field_028;  // 0x028 [R/W] (CleanUpRoomLights, EHouse, InitRoomLighting, ...)
    u32 m_field_02C;  // 0x02C [R/W] (BuildHouse, CleanUpRoomLights, EHouse, ...)
    u32 m_field_030;  // 0x030 [R/W] (EHouse, Fair, Rain, ...)
    u32 m_field_034;  // 0x034 [R/W] (BuildHouse, EHouse, ReCalcHouse, ...)
    f32 m_lightIntensityScaleFromRoom_038;  // 0x038 [R/W] (EHouse, SetLightIntensityScaleFromRoom, UpdateRoomLights, ...)
    f32 m_weather;  // 0x03C [R/W] (EHouse, UpdateWeather)
    f32 m_weather_040;  // 0x040 [R/W] (EHouse, Update, UpdateWeather)
    f32 m_roomLights;  // 0x044 [R/W] (Draw, Update, UpdateRoomLights)
    f32 m_field_048;  // 0x048 [R/W] (InitRoomLighting, Update)
    f32 m_field_04C;  // 0x04C [W] (EHouse)
    f32 m_field_050;  // 0x050 [W] (EHouse)
    u32 m_field_054;  // 0x054 [R/W] (EHouse)
    u8 _pad_058[0x70];  // 0x058
    u32 m_weather_0C8;  // 0x0C8 [R] (UpdateWeather)
    u8 _pad_0CC[0x14];  // 0x0CC
    u32 m_field_0E0;  // 0x0E0 [W] (EHouse)
    u8 _pad_0E4[0x40];  // 0x0E4
    u32 m_field_124;  // 0x124 [R/W] (Cleanup, Draw, EHouse, ...)
    u8 _pad_128[0x2CC];  // 0x128
    u32 m_weather_3F4;  // 0x3F4 [R] (UpdateWeather)
};

#endif // EHOUSE_H
