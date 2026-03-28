#ifndef ELIGHTGRID_H
#define ELIGHTGRID_H

#include "types.h"

// ELightGrid - struct layout extracted from assembly analysis
// Estimated minimum size: 0x6058 (24664 bytes)
// 17 known fields (0 named), 43 methods

class ELightGrid {
public:
    // Constructors / Destructors
    ELightGrid(void)  // 0x8063AF48

    // Methods
    /* ? */ GetRoomData(int);  // 0x800D7D64 (164B)
    /* ? */ GetLights(void);  // 0x800D7E08 (44B)
    /* ? */ GetOuterLotLights(void);  // 0x80637C98 (48B)
    void AddRoomToVertex(int, int, int);  // 0x8063B250 (552B)
    /* ? */ GetLightsAtLocation(EVec3 &, int);  // 0x8063D74C (352B)
    /* ? */ GetLightWeightsAtLocation(EVec3 &, int, ELightGrid::LightWeight *);  // 0x8063D3E8 (868B)
    void Flush(void);  // 0x8063B070 (380B)
    void DumpGrid(char *, int);  // 0x8063B478 (616B)
    void Update(TNodeList<EILight *> &, EInstance **, int, int);  // 0x8063B6E0 (1364B)
    void EvaluatePointLights(int, int);  // 0x8063C394 (616B)
    void ConnectPortalLights(ELightGrid::RoomData *);  // 0x8063BC34 (1048B)
    void EvaluatePortalLights(int, int);  // 0x8063CCDC (360B)
    void AddLightsToVertices(void);  // 0x8063C5FC (1096B)
    void EvaluateOuterLotLights(void);  // 0x8063CA94 (208B)
    void EvaluateLights(void);  // 0x8063CA44 (80B)
    void EvaluatePointLights(void);  // 0x80640040 (64B)
    void EvaluateAmbientAndDirectionalLights(void);  // 0x8063CB64 (116B)
    void EvaluatePortalLights(void);  // 0x80640080 (64B)
    void EvaluatePortalLight(ELightGrid::LightData *, ELightGrid::PortalData *);  // 0x8063CE44 (840B)
    bool IsRoomAtLocation(EVec3 &, int);  // 0x8063D8AC (284B)
    void EvaluateLamps(void);  // 0x8063DA74 (64B)
    void EvaluateLampsOn(void);  // 0x8063DAB4 (408B)
    /* ? */ GetAmbient(EVec3 &, int);  // 0x80650788 (84B)
    /* ? */ GetDirectional(EDirLight &, int);  // 0x806507DC (128B)
    void SetOutdated(bool);  // 0x80650888 (40B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_field_000;  // 0x000 [R/W] (AddRoomToVertex, EvaluatePointLights, EvaluatePortalLight, ...)
    f32 m_field_004;  // 0x004 [R/W] (EvaluatePortalLight, Flush, LightData::Clear, ...)
    f32 m_field_008;  // 0x008 [R/W] (ELightGrid, EvaluatePortalLight, LightData::Clear, ...)
    f32 m_field_00C;  // 0x00C [R/W] (EvaluatePortalLight, Flush, LightData::Clear, ...)
    f32 m_field_010;  // 0x010 [R/W] (EvaluateLamps, EvaluateLampsOn, EvaluateLights, ...)
    u32 m_field_014;  // 0x014 [R/W] (EvaluateLamps, EvaluateLampsOn, EvaluateLights, ...)
    u32 m_field_018;  // 0x018 [R/W] (EvaluateLamps, EvaluateLampsOn, EvaluateLights, ...)
    u32 m_field_01C;  // 0x01C [R/W] (EvaluateLamps, EvaluateLampsOn, EvaluateLights, ...)
    u8 _pad_020[0x1C];  // 0x020
    u32 m_field_03C;  // 0x03C [R] (RoomData::EvaluateAmbientAndDirectionalLights)
    u8 _pad_040[4];  // 0x040
    u32 m_field_044;  // 0x044 [R/W] (AddLightsToVertices, RoomData::Flush)
    u32 m_field_048;  // 0x048 [R/W] (AddLightsToVertices, RoomData::Flush)
    u32 m_field_04C;  // 0x04C [R/W] (AddLightsToVertices, ConnectPortalLights, RoomData::Flush)
    u32 m_field_050;  // 0x050 [R/W] (AddLightsToVertices, ConnectPortalLights, RoomData::Flush)
    u8 _pad_054[0x5FCC];  // 0x054
    u32 m_field_6020;  // 0x6020 [R/W] (EvaluateAmbientAndDirectionalLights, EvaluateOuterLotLights, Flush, ...)
    u8 _pad_6024[0x10];  // 0x6024
    u32 m_field_6034;  // 0x6034 [R] (EvaluateOuterLotLights)
    u8 _pad_6038[0xC];  // 0x6038
    u32 m_field_6044;  // 0x6044 [R] (EvaluateOuterLotLights)
    u8 _pad_6048[0xC];  // 0x6048
    u32 m_field_6054;  // 0x6054 [R] (EvaluateOuterLotLights)
};

#endif // ELIGHTGRID_H
