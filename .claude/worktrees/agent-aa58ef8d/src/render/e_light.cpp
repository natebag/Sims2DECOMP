// e_light.cpp - Lighting system classes (EILight, EIAmbLight, EIDirLight,
// EIPointLight, EIPointAmbLight, EISpotLight, EIGameInstance,
// EIStaticModel, EIStaticSubModel, EMirrorPortal)
//
// Source obj files: e_ilight.obj, e_iamblight.obj, e_idirlight.obj,
// e_ipointlight.obj, e_ipointamblight.obj, e_ispotlight.obj,
// e_igameinstance.obj, e_istaticmodel.obj, e_istaticsubmodel.obj,
// e_mirrorportal.obj

#include "render/e_light.h"
#include "types.h"

// Placement new
inline void* operator new(unsigned int, void* ptr) { return ptr; }

// External functions
extern EStream& operator<<(EStream& stream, EStorable* obj);
extern EStream& operator>>(EStream& stream, EStorable*& obj);
extern EFile& operator>>(EFile& file, EStorable*& obj);
extern void* EStorable_New(unsigned int size);
extern void EStorable_CreateCopy(EStorable* obj);
extern void EInstance_Init(EInstance* inst);
extern void EInstance_Destruct(EInstance* inst, int mode);
extern void EInstance_RegisterType(ETypeInfo* info, void* newFn, void* constructFn,
                                    void* destructFn, u16 version, char* name, ETypeInfo* parent);
extern void E3DWindow_PopClipStack(E3DWindow& window, int id);
extern float EVec3_Length(EVec3* v);
extern int ERModel_HasModifiableColor(ERModel* model);
extern void EResource_Release(void* res);
extern void* EResource_Load(char* path, void* loader, int a, int b);
extern void ERLevel_InitPortals(ERLevel* level);

// Static member definitions
static int s_haveLightsChanged;

// =============================================================================
// EILight - operator<<(EStream&, EILight*)
// Address: 0x802278E4, Size: 32
// =============================================================================
EStream& operator<<(EStream& stream, EILight* light) {
    return operator<<(stream, (EStorable*)light);
}

// =============================================================================
// EILight - operator>>(EStream&, EILight*&)
// Address: 0x80227904, Size: 64
// NON_MATCHING - standard stream>>storable pattern
// =============================================================================
EStream& operator>>(EStream& stream, EILight*& light) {
    EStorable* tmp;
    operator>>(stream, tmp);
    light = (EILight*)tmp;
    return stream;
}

// =============================================================================
// EILight - operator>>(EFile&, EILight*&)
// Address: 0x80227944, Size: 64
// NON_MATCHING - standard file>>storable pattern
// =============================================================================
EFile& operator>>(EFile& file, EILight*& light) {
    EStorable* tmp;
    operator>>(file, tmp);
    light = (EILight*)tmp;
    return file;
}

// =============================================================================
// EILight::Init
// Address: 0x80227C5C, Size: 52
// Calls vtable function at offset 0x160/0x164
// NON_MATCHING - vtable dispatch
// =============================================================================

// =============================================================================
// EILight::New
// Address: 0x80227F5C, Size: 40
// Allocates 0xAC bytes, then calls EILight constructor
// =============================================================================
EILight* EILight::New() {
    EILight* light = (EILight*)EStorable_New(0xAC);
    // constructor called implicitly
    return light;
}

// =============================================================================
// EILight::Construct
// Address: 0x80227F84, Size: 32
// =============================================================================
void EILight::Construct(EILight* light) {
    // placement new - calls constructor
    new ((void*)light) EILight();
}

// =============================================================================
// EILight::Destruct
// Address: 0x80227FA4, Size: 36
// Calls EInstance_Destruct with mode=2
// =============================================================================
void EILight::Destruct(EILight* light) {
    EInstance_Destruct((EInstance*)light, 2);
}

// =============================================================================
// EILight::SafeDelete
// Address: 0x80227FC8, Size: 64
// Standard SafeDelete pattern
// =============================================================================
void EILight::SafeDelete() {
    if (this != NULL) {
        // vtable dispatch to destructor with mode=3
    }
}

// =============================================================================
// EILight::GetTypeInfo
// Address: 0x80228008, Size: 12
// Returns pointer to static ETypeInfo
// =============================================================================
const ETypeInfo* EILight::GetTypeInfo() const {
    return &m_typeInfo;
}

// =============================================================================
// EILight::GetTypeName
// Address: 0x80228014, Size: 12
// Returns name from ETypeInfo
// =============================================================================
const char* EILight::GetTypeName() const {
    return m_typeInfo.m_name;
}

// =============================================================================
// EILight::GetTypeKey
// Address: 0x80228020, Size: 12
// Returns key from ETypeInfo
// =============================================================================
u32 EILight::GetTypeKey() const {
    return m_typeInfo.m_key;
}

// =============================================================================
// EILight::GetTypeVersion
// Address: 0x8022802C, Size: 12
// Returns version from ETypeInfo
// =============================================================================
u16 EILight::GetTypeVersion() const {
    return m_typeInfo.m_version;
}

// =============================================================================
// EILight::GetTypeInfoStatic
// Address: 0x80228038, Size: 12
// =============================================================================
const ETypeInfo* EILight::GetTypeInfoStatic() {
    return &m_typeInfo;
}

// =============================================================================
// EILight::GetReadVersion
// Address: 0x80228044, Size: 12
// =============================================================================
u16 EILight::GetReadVersion() {
    return m_typeInfo.m_readVersion;
}

// =============================================================================
// EILight::CreateCopy
// Address: 0x802280A4, Size: 32
// =============================================================================
EStorable* EILight::CreateCopy() const {
    EStorable_CreateCopy((EStorable*)this);
    return (EStorable*)this;
}

// =============================================================================
// EILight::LightingParameters (pure virtual stub)
// Address: 0x802280C4, Size: 4
// =============================================================================
void EILight::LightingParameters(EVec3& a, float& b, EVec3& c, EVec3& d) {
    // blr - empty stub
}

// =============================================================================
// EILight::CalcFullIntensityLightOnPoint (pure virtual stub)
// Address: 0x802280C8, Size: 4
// =============================================================================
void EILight::CalcFullIntensityLightOnPoint(EVec3& a, float& b) {
    // blr - empty stub
}

// =============================================================================
// EILight::Setup (pure virtual stub)
// Address: 0x802280CC, Size: 4
// =============================================================================
void EILight::Setup() {
    // blr - empty stub
}

// =============================================================================
// EILight::GetLightType
// Address: 0x802280D0, Size: 8
// Returns 0 (base light type)
// =============================================================================
int EILight::GetLightType() {
    return LIGHTTYPE_BASE;
}

// =============================================================================
// EILight::SetIntensityScale
// Address: 0x802280D8, Size: 32
// Copies EVec3 to m_intensityScale (offset 0x9C)
// =============================================================================
void EILight::SetIntensityScale(EVec3& scale) {
    m_intensityScale.x = scale.x;
    m_intensityScale.y = scale.y;
    m_intensityScale.z = scale.z;
}

// =============================================================================
// EILight::UseScaleIntensity
// Address: 0x802280F8, Size: 8
// Stores bool as int at offset 0xA8
// =============================================================================
void EILight::UseScaleIntensity(bool use) {
    m_useScaleIntensity2 = (int)use;
}

// =============================================================================
// EILight::GetPosition
// Address: 0x80228100, Size: 60
// Returns zero vector (base class has no position)
// =============================================================================
void EILight::GetPosition(EVec3& pos) {
    EVec3 zero;
    zero.x = 0.0f;
    zero.y = 0.0f;
    zero.z = 0.0f;
    pos.x = zero.x;
    pos.y = zero.y;
    pos.z = zero.z;
}

// =============================================================================
// EILight::GetIntensityScale
// Address: 0x8022813C, Size: 36
// Returns pointer to m_intensityScale (copies via EVec3 return)
// =============================================================================
EVec3* EILight::GetIntensityScale() {
    return &m_intensityScale;
}

// =============================================================================
// EILight::SetIntensity
// Address: 0x80228160, Size: 8
// =============================================================================
void EILight::SetIntensity(float intensity) {
    m_intensity = intensity;
}

// =============================================================================
// EILight::GetIntensity
// Address: 0x80228168, Size: 8
// =============================================================================
float EILight::GetIntensity() const {
    return m_intensity;
}

// =============================================================================
// EILight::SetColor
// Address: 0x80228170, Size: 32
// Copies EVec3 to m_color (offset 0x90)
// =============================================================================
void EILight::SetColor(EVec3& color) {
    m_color.x = color.x;
    m_color.y = color.y;
    m_color.z = color.z;
}

// =============================================================================
// EILight::GetColor
// Address: 0x80228190, Size: 8
// Returns pointer to m_color (offset 0x90)
// =============================================================================
EVec3* EILight::GetColor() const {
    return (EVec3*)&m_color;
}

// =============================================================================
// EILight::Enable
// Address: 0x80228198, Size: 8
// =============================================================================
void EILight::Enable(bool enable) {
    m_isEnabled = (int)enable;
}

// =============================================================================
// EILight::IsEnabled
// Address: 0x802281A0, Size: 8
// =============================================================================
int EILight::IsEnabled() {
    return m_isEnabled;
}

// =============================================================================
// EILight::GetFalloffEnd
// Address: 0x802281A8, Size: 12
// Returns constant from rodata
// =============================================================================

// =============================================================================
// EILight::SetHaveLightsChanged
// Address: 0x802281B4, Size: 8
// Static - writes to SDA global
// =============================================================================
void EILight::SetHaveLightsChanged(bool changed) {
    s_haveLightsChanged = (int)changed;
}

// =============================================================================
// EILight::HaveLightsChanged
// Address: 0x802281BC, Size: 8
// Static - reads from SDA global
// =============================================================================
int EILight::HaveLightsChanged() {
    return s_haveLightsChanged;
}

// =============================================================================
// EIAmbLight - operator<<(EStream&, EIAmbLight*)
// Address: 0x80226AF8, Size: 32
// =============================================================================
EStream& operator<<(EStream& stream, EIAmbLight* light) {
    return operator<<(stream, (EStorable*)light);
}

// =============================================================================
// EIAmbLight - operator>>(EStream&, EIAmbLight*&)
// Address: 0x80226B18, Size: 64
// =============================================================================
EStream& operator>>(EStream& stream, EIAmbLight*& light) {
    EStorable* tmp;
    operator>>(stream, tmp);
    light = (EIAmbLight*)tmp;
    return stream;
}

// =============================================================================
// EIAmbLight - operator>>(EFile&, EIAmbLight*&)
// Address: 0x80226B58, Size: 64
// =============================================================================
EFile& operator>>(EFile& file, EIAmbLight*& light) {
    EStorable* tmp;
    operator>>(file, tmp);
    light = (EIAmbLight*)tmp;
    return file;
}

// =============================================================================
// EIAmbLight::Construct
// Address: 0x80226E80, Size: 56
// Calls EILight ctor then sets vtable
// =============================================================================

// =============================================================================
// EIAmbLight::Destruct
// Address: 0x80226EB8, Size: 36
// =============================================================================
void EIAmbLight::Destruct(EIAmbLight* light) {
    EInstance_Destruct((EInstance*)light, 2);
}

// =============================================================================
// EIAmbLight::SafeDelete
// Address: 0x80226EDC, Size: 64
// =============================================================================

// =============================================================================
// EIAmbLight::GetTypeInfo
// Address: 0x80226F1C, Size: 12
// =============================================================================
const ETypeInfo* EIAmbLight::GetTypeInfo() const {
    return &m_typeInfo;
}

// =============================================================================
// EIAmbLight::GetTypeName
// Address: 0x80226F28, Size: 12
// =============================================================================
const char* EIAmbLight::GetTypeName() const {
    return m_typeInfo.m_name;
}

// =============================================================================
// EIAmbLight::GetTypeKey
// Address: 0x80226F34, Size: 12
// =============================================================================
u32 EIAmbLight::GetTypeKey() const {
    return m_typeInfo.m_key;
}

// =============================================================================
// EIAmbLight::GetTypeVersion
// Address: 0x80226F40, Size: 12
// =============================================================================
u16 EIAmbLight::GetTypeVersion() const {
    return m_typeInfo.m_version;
}

// =============================================================================
// EIAmbLight::GetTypeInfoStatic
// Address: 0x80226F4C, Size: 12
// =============================================================================
const ETypeInfo* EIAmbLight::GetTypeInfoStatic() {
    return &m_typeInfo;
}

// =============================================================================
// EIAmbLight::GetReadVersion
// Address: 0x80226F58, Size: 12
// =============================================================================
u16 EIAmbLight::GetReadVersion() {
    return m_typeInfo.m_readVersion;
}

// =============================================================================
// EIAmbLight::CreateCopy
// Address: 0x80226FB8, Size: 32
// =============================================================================
EStorable* EIAmbLight::CreateCopy() const {
    EStorable_CreateCopy((EStorable*)this);
    return (EStorable*)this;
}

// =============================================================================
// EIAmbLight::GetLightType
// Address: 0x80226FD8, Size: 8
// Returns 1 (ambient)
// =============================================================================
int EIAmbLight::GetLightType() {
    return LIGHTTYPE_AMBIENT;
}

// =============================================================================
// EIDirLight - operator<<(EStream&, EIDirLight*)
// Address: 0x8022700C, Size: 32
// =============================================================================
EStream& operator<<(EStream& stream, EIDirLight* light) {
    return operator<<(stream, (EStorable*)light);
}

// =============================================================================
// EIDirLight - operator>>(EStream&, EIDirLight*&)
// Address: 0x8022702C, Size: 64
// =============================================================================
EStream& operator>>(EStream& stream, EIDirLight*& light) {
    EStorable* tmp;
    operator>>(stream, tmp);
    light = (EIDirLight*)tmp;
    return stream;
}

// =============================================================================
// EIDirLight - operator>>(EFile&, EIDirLight*&)
// Address: 0x8022706C, Size: 64
// =============================================================================
EFile& operator>>(EFile& file, EIDirLight*& light) {
    EStorable* tmp;
    operator>>(file, tmp);
    light = (EIDirLight*)tmp;
    return file;
}

// =============================================================================
// EIDirLight::New
// Address: 0x8022736C, Size: 40
// =============================================================================

// =============================================================================
// EIDirLight::Construct
// Address: 0x80227394, Size: 32
// =============================================================================

// =============================================================================
// EIDirLight::Destruct
// Address: 0x802273B4, Size: 36
// =============================================================================
void EIDirLight::Destruct(EIDirLight* light) {
    EInstance_Destruct((EInstance*)light, 2);
}

// =============================================================================
// EIDirLight::SafeDelete
// Address: 0x802273D8, Size: 64
// =============================================================================

// =============================================================================
// EIDirLight::GetTypeInfo
// Address: 0x80227418, Size: 12
// =============================================================================
const ETypeInfo* EIDirLight::GetTypeInfo() const {
    return &m_typeInfo;
}

// =============================================================================
// EIDirLight::GetTypeName
// Address: 0x80227424, Size: 12
// =============================================================================
const char* EIDirLight::GetTypeName() const {
    return m_typeInfo.m_name;
}

// =============================================================================
// EIDirLight::GetTypeKey
// Address: 0x80227430, Size: 12
// =============================================================================
u32 EIDirLight::GetTypeKey() const {
    return m_typeInfo.m_key;
}

// =============================================================================
// EIDirLight::GetTypeVersion
// Address: 0x8022743C, Size: 12
// =============================================================================
u16 EIDirLight::GetTypeVersion() const {
    return m_typeInfo.m_version;
}

// =============================================================================
// EIDirLight::GetTypeInfoStatic
// Address: 0x80227448, Size: 12
// =============================================================================
const ETypeInfo* EIDirLight::GetTypeInfoStatic() {
    return &m_typeInfo;
}

// =============================================================================
// EIDirLight::GetReadVersion
// Address: 0x80227454, Size: 12
// =============================================================================
u16 EIDirLight::GetReadVersion() {
    return m_typeInfo.m_readVersion;
}

// =============================================================================
// EIDirLight::CreateCopy
// Address: 0x802274B4, Size: 32
// =============================================================================
EStorable* EIDirLight::CreateCopy() const {
    EStorable_CreateCopy((EStorable*)this);
    return (EStorable*)this;
}

// =============================================================================
// EIDirLight::GetLightType
// Address: 0x802274D4, Size: 8
// Returns 2 (directional)
// =============================================================================
int EIDirLight::GetLightType() {
    return LIGHTTYPE_DIRECTIONAL;
}

// =============================================================================
// EIDirLight::SetDir
// Address: 0x802274DC, Size: 32
// Copies EVec3 to m_dir (offset 0xAC)
// =============================================================================
void EIDirLight::SetDir(EVec3& dir) {
    m_dir.x = dir.x;
    m_dir.y = dir.y;
    m_dir.z = dir.z;
}

// =============================================================================
// EIDirLight::GetDir
// Address: 0x802274FC, Size: 8
// Returns pointer to m_dir (offset 0xAC)
// =============================================================================
EVec3* EIDirLight::GetDir() const {
    return (EVec3*)&m_dir;
}

// =============================================================================
// EIPointLight - operator<<(EStream&, EIPointLight*)
// Address: 0x80229D2C, Size: 32
// =============================================================================
EStream& operator<<(EStream& stream, EIPointLight* light) {
    return operator<<(stream, (EStorable*)light);
}

// =============================================================================
// EIPointLight - operator>>(EStream&, EIPointLight*&)
// Address: 0x80229D4C, Size: 64
// =============================================================================
EStream& operator>>(EStream& stream, EIPointLight*& light) {
    EStorable* tmp;
    operator>>(stream, tmp);
    light = (EIPointLight*)tmp;
    return stream;
}

// =============================================================================
// EIPointLight - operator>>(EFile&, EIPointLight*&)
// Address: 0x80229D8C, Size: 64
// =============================================================================
EFile& operator>>(EFile& file, EIPointLight*& light) {
    EStorable* tmp;
    operator>>(file, tmp);
    light = (EIPointLight*)tmp;
    return file;
}

// =============================================================================
// EIPointLight::Destruct
// Address: 0x8022A4FC, Size: 36
// =============================================================================
void EIPointLight::Destruct(EIPointLight* light) {
    EInstance_Destruct((EInstance*)light, 2);
}

// =============================================================================
// EIPointLight::GetTypeInfo
// Address: 0x8022A560, Size: 12
// =============================================================================
const ETypeInfo* EIPointLight::GetTypeInfo() const {
    return &m_typeInfo;
}

// =============================================================================
// EIPointLight::GetTypeName
// Address: 0x8022A56C, Size: 12
// =============================================================================
const char* EIPointLight::GetTypeName() const {
    return m_typeInfo.m_name;
}

// =============================================================================
// EIPointLight::GetTypeKey
// Address: 0x8022A578, Size: 12
// =============================================================================
u32 EIPointLight::GetTypeKey() const {
    return m_typeInfo.m_key;
}

// =============================================================================
// EIPointLight::GetTypeVersion
// Address: 0x8022A584, Size: 12
// =============================================================================
u16 EIPointLight::GetTypeVersion() const {
    return m_typeInfo.m_version;
}

// =============================================================================
// EIPointLight::GetTypeInfoStatic
// Address: 0x8022A590, Size: 12
// =============================================================================
const ETypeInfo* EIPointLight::GetTypeInfoStatic() {
    return &m_typeInfo;
}

// =============================================================================
// EIPointLight::GetReadVersion
// Address: 0x8022A59C, Size: 12
// =============================================================================
u16 EIPointLight::GetReadVersion() {
    return m_typeInfo.m_readVersion;
}

// =============================================================================
// EIPointLight::CreateCopy
// Address: 0x8022A5FC, Size: 32
// =============================================================================
EStorable* EIPointLight::CreateCopy() const {
    EStorable_CreateCopy((EStorable*)this);
    return (EStorable*)this;
}

// =============================================================================
// EIPointLight::GetLightType
// Address: 0x8022A61C, Size: 8
// Returns 3 (point light)
// =============================================================================
int EIPointLight::GetLightType() {
    return LIGHTTYPE_POINT;
}

// =============================================================================
// EIPointLight::GetPosition
// Address: 0x8022A624, Size: 32
// Copies m_position (offset 0xAC) to output
// =============================================================================
void EIPointLight::GetPosition(EVec3& pos) {
    pos.x = m_position.x;
    pos.y = m_position.y;
    pos.z = m_position.z;
}

// =============================================================================
// EIPointLight::GetFalloffEnd
// Address: 0x8022A644, Size: 8
// Returns m_falloffEnd (offset 0xC8)
// =============================================================================
float EIPointLight::GetFalloffEnd() {
    return m_falloffEnd;
}

// =============================================================================
// EIPointLight::GetRoomId
// Address: 0x8022A64C, Size: 8
// Returns m_roomId (offset 0xC0)
// =============================================================================
int EIPointLight::GetRoomId() {
    return m_roomId;
}

// =============================================================================
// EIPortalPointLight - operator<<(EStream&, EIPortalPointLight*)
// Address: 0x8022A680, Size: 32
// =============================================================================
EStream& operator<<(EStream& stream, EIPortalPointLight* light) {
    return operator<<(stream, (EStorable*)light);
}

// =============================================================================
// EIPortalPointLight - operator>>(EStream&, EIPortalPointLight*&)
// Address: 0x8022A6A0, Size: 64
// =============================================================================
EStream& operator>>(EStream& stream, EIPortalPointLight*& light) {
    EStorable* tmp;
    operator>>(stream, tmp);
    light = (EIPortalPointLight*)tmp;
    return stream;
}

// =============================================================================
// EIPortalPointLight - operator>>(EFile&, EIPortalPointLight*&)
// Address: 0x8022A6E0, Size: 64
// =============================================================================
EFile& operator>>(EFile& file, EIPortalPointLight*& light) {
    EStorable* tmp;
    operator>>(file, tmp);
    light = (EIPortalPointLight*)tmp;
    return file;
}

// =============================================================================
// EIPointAmbLight - operator<<(EStream&, EIPointAmbLight*)
// Address: 0x80229770, Size: 32
// =============================================================================
EStream& operator<<(EStream& stream, EIPointAmbLight* light) {
    return operator<<(stream, (EStorable*)light);
}

// =============================================================================
// EIPointAmbLight - operator>>(EStream&, EIPointAmbLight*&)
// Address: 0x80229790, Size: 64
// =============================================================================
EStream& operator>>(EStream& stream, EIPointAmbLight*& light) {
    EStorable* tmp;
    operator>>(stream, tmp);
    light = (EIPointAmbLight*)tmp;
    return stream;
}

// =============================================================================
// EIPointAmbLight - operator>>(EFile&, EIPointAmbLight*&)
// Address: 0x802297D0, Size: 64
// =============================================================================
EFile& operator>>(EFile& file, EIPointAmbLight*& light) {
    EStorable* tmp;
    operator>>(file, tmp);
    light = (EIPointAmbLight*)tmp;
    return file;
}

// =============================================================================
// EIPointAmbLight::Destruct
// Address: 0x80229BE0, Size: 36
// =============================================================================
void EIPointAmbLight::Destruct(EIPointAmbLight* light) {
    EInstance_Destruct((EInstance*)light, 2);
}

// =============================================================================
// EIPointAmbLight::GetTypeInfo
// Address: 0x80229C44, Size: 12
// =============================================================================
const ETypeInfo* EIPointAmbLight::GetTypeInfo() const {
    return &m_typeInfo;
}

// =============================================================================
// EIPointAmbLight::GetTypeName
// Address: 0x80229C50, Size: 12
// =============================================================================
const char* EIPointAmbLight::GetTypeName() const {
    return m_typeInfo.m_name;
}

// =============================================================================
// EIPointAmbLight::GetTypeKey
// Address: 0x80229C5C, Size: 12
// =============================================================================
u32 EIPointAmbLight::GetTypeKey() const {
    return m_typeInfo.m_key;
}

// =============================================================================
// EIPointAmbLight::GetTypeVersion
// Address: 0x80229C68, Size: 12
// =============================================================================
u16 EIPointAmbLight::GetTypeVersion() const {
    return m_typeInfo.m_version;
}

// =============================================================================
// EIPointAmbLight::GetTypeInfoStatic
// Address: 0x80229C74, Size: 12
// =============================================================================
const ETypeInfo* EIPointAmbLight::GetTypeInfoStatic() {
    return &m_typeInfo;
}

// =============================================================================
// EIPointAmbLight::GetReadVersion
// Address: 0x80229C80, Size: 12
// =============================================================================
u16 EIPointAmbLight::GetReadVersion() {
    return m_typeInfo.m_readVersion;
}

// =============================================================================
// EIPointAmbLight::CreateCopy
// Address: 0x80229CE0, Size: 32
// =============================================================================
EStorable* EIPointAmbLight::CreateCopy() const {
    EStorable_CreateCopy((EStorable*)this);
    return (EStorable*)this;
}

// =============================================================================
// EISpotLight - operator<<(EStream&, EISpotLight*)
// Address: 0x8022B140, Size: 32
// =============================================================================
EStream& operator<<(EStream& stream, EISpotLight* light) {
    return operator<<(stream, (EStorable*)light);
}

// =============================================================================
// EISpotLight - operator>>(EStream&, EISpotLight*&)
// Address: 0x8022B160, Size: 64
// =============================================================================
EStream& operator>>(EStream& stream, EISpotLight*& light) {
    EStorable* tmp;
    operator>>(stream, tmp);
    light = (EISpotLight*)tmp;
    return stream;
}

// =============================================================================
// EISpotLight - operator>>(EFile&, EISpotLight*&)
// Address: 0x8022B1A0, Size: 64
// =============================================================================
EFile& operator>>(EFile& file, EISpotLight*& light) {
    EStorable* tmp;
    operator>>(file, tmp);
    light = (EISpotLight*)tmp;
    return file;
}

// =============================================================================
// EISpotLight::Destruct
// Address: 0x8022B7B4, Size: 36
// =============================================================================
void EISpotLight::Destruct(EISpotLight* light) {
    EInstance_Destruct((EInstance*)light, 2);
}

// =============================================================================
// EISpotLight::GetTypeInfo
// Address: 0x8022B818, Size: 12
// =============================================================================
const ETypeInfo* EISpotLight::GetTypeInfo() const {
    return &m_typeInfo;
}

// =============================================================================
// EISpotLight::GetTypeName
// Address: 0x8022B824, Size: 12
// =============================================================================
const char* EISpotLight::GetTypeName() const {
    return m_typeInfo.m_name;
}

// =============================================================================
// EISpotLight::GetTypeKey
// Address: 0x8022B830, Size: 12
// =============================================================================
u32 EISpotLight::GetTypeKey() const {
    return m_typeInfo.m_key;
}

// =============================================================================
// EISpotLight::GetTypeVersion
// Address: 0x8022B83C, Size: 12
// =============================================================================
u16 EISpotLight::GetTypeVersion() const {
    return m_typeInfo.m_version;
}

// =============================================================================
// EISpotLight::GetTypeInfoStatic
// Address: 0x8022B848, Size: 12
// =============================================================================
const ETypeInfo* EISpotLight::GetTypeInfoStatic() {
    return &m_typeInfo;
}

// =============================================================================
// EISpotLight::GetReadVersion
// Address: 0x8022B854, Size: 12
// =============================================================================
u16 EISpotLight::GetReadVersion() {
    return m_typeInfo.m_readVersion;
}

// =============================================================================
// EISpotLight::CreateCopy
// Address: 0x8022B8B4, Size: 32
// =============================================================================
EStorable* EISpotLight::CreateCopy() const {
    EStorable_CreateCopy((EStorable*)this);
    return (EStorable*)this;
}

// =============================================================================
// EIGameInstance - operator<<(EStream&, EIGameInstance*)
// Address: 0x802275D4, Size: 32
// =============================================================================
EStream& operator<<(EStream& stream, EIGameInstance* inst) {
    return operator<<(stream, (EStorable*)inst);
}

// =============================================================================
// EIGameInstance - operator>>(EStream&, EIGameInstance*&)
// Address: 0x802275F4, Size: 64
// =============================================================================
EStream& operator>>(EStream& stream, EIGameInstance*& inst) {
    EStorable* tmp;
    operator>>(stream, tmp);
    inst = (EIGameInstance*)tmp;
    return stream;
}

// =============================================================================
// EIGameInstance - operator>>(EFile&, EIGameInstance*&)
// Address: 0x80227634, Size: 64
// =============================================================================
EFile& operator>>(EFile& file, EIGameInstance*& inst) {
    EStorable* tmp;
    operator>>(file, tmp);
    inst = (EIGameInstance*)tmp;
    return file;
}

// =============================================================================
// EIGameInstance::Destruct
// Address: 0x80227798, Size: 36
// =============================================================================
void EIGameInstance::Destruct(EIGameInstance* inst) {
    EInstance_Destruct((EInstance*)inst, 2);
}

// =============================================================================
// EIGameInstance::GetTypeInfo
// Address: 0x802277FC, Size: 12
// =============================================================================
const ETypeInfo* EIGameInstance::GetTypeInfo() const {
    return &m_typeInfo;
}

// =============================================================================
// EIGameInstance::GetTypeName
// Address: 0x80227808, Size: 12
// =============================================================================
const char* EIGameInstance::GetTypeName() const {
    return m_typeInfo.m_name;
}

// =============================================================================
// EIGameInstance::GetTypeKey
// Address: 0x80227814, Size: 12
// =============================================================================
u32 EIGameInstance::GetTypeKey() const {
    return m_typeInfo.m_key;
}

// =============================================================================
// EIGameInstance::GetTypeVersion
// Address: 0x80227820, Size: 12
// =============================================================================
u16 EIGameInstance::GetTypeVersion() const {
    return m_typeInfo.m_version;
}

// =============================================================================
// EIGameInstance::GetTypeInfoStatic
// Address: 0x8022782C, Size: 12
// =============================================================================
const ETypeInfo* EIGameInstance::GetTypeInfoStatic() {
    return &m_typeInfo;
}

// =============================================================================
// EIGameInstance::GetReadVersion
// Address: 0x80227838, Size: 12
// =============================================================================
u16 EIGameInstance::GetReadVersion() {
    return m_typeInfo.m_readVersion;
}

// =============================================================================
// EIGameInstance::CreateCopy
// Address: 0x80227898, Size: 32
// =============================================================================
EStorable* EIGameInstance::CreateCopy() const {
    EStorable_CreateCopy((EStorable*)this);
    return (EStorable*)this;
}

// =============================================================================
// EIStaticModel - operator<<(EStream&, EIStaticModel*)
// Address: 0x8022B900, Size: 32
// =============================================================================
EStream& operator<<(EStream& stream, EIStaticModel* model) {
    return operator<<(stream, (EStorable*)model);
}

// =============================================================================
// EIStaticModel - operator>>(EStream&, EIStaticModel*&)
// Address: 0x8022B920, Size: 64
// =============================================================================
EStream& operator>>(EStream& stream, EIStaticModel*& model) {
    EStorable* tmp;
    operator>>(stream, tmp);
    model = (EIStaticModel*)tmp;
    return stream;
}

// =============================================================================
// EIStaticModel - operator>>(EFile&, EIStaticModel*&)
// Address: 0x8022B960, Size: 64
// =============================================================================
EFile& operator>>(EFile& file, EIStaticModel*& model) {
    EStorable* tmp;
    operator>>(file, tmp);
    model = (EIStaticModel*)tmp;
    return file;
}

// =============================================================================
// EIStaticModel::ModifyColor
// Address: 0x8022DAE0, Size: 8
// Stores color at offset 0x114
// =============================================================================
void EIStaticModel::ModifyColor(u32 color) {
    m_modColor = color;
}

// =============================================================================
// EIStaticModel::GetModifiableColor
// Address: 0x8022DAE8, Size: 8
// Returns color at offset 0x114
// =============================================================================
int EIStaticModel::GetModifiableColor() {
    return (int)m_modColor;
}

// =============================================================================
// EIStaticModel::Destruct
// Address: 0x8022E00C, Size: 36
// =============================================================================
void EIStaticModel::Destruct(EIStaticModel* model) {
    EInstance_Destruct((EInstance*)model, 2);
}

// =============================================================================
// EIStaticModel::GetTypeInfo
// Address: 0x8022E070, Size: 12
// =============================================================================
const ETypeInfo* EIStaticModel::GetTypeInfo() const {
    return &m_typeInfo;
}

// =============================================================================
// EIStaticModel::GetTypeName
// Address: 0x8022E07C, Size: 12
// =============================================================================
const char* EIStaticModel::GetTypeName() const {
    return m_typeInfo.m_name;
}

// =============================================================================
// EIStaticModel::GetTypeKey
// Address: 0x8022E088, Size: 12
// =============================================================================
u32 EIStaticModel::GetTypeKey() const {
    return m_typeInfo.m_key;
}

// =============================================================================
// EIStaticModel::GetTypeVersion
// Address: 0x8022E094, Size: 12
// =============================================================================
u16 EIStaticModel::GetTypeVersion() const {
    return m_typeInfo.m_version;
}

// =============================================================================
// EIStaticModel::GetTypeInfoStatic
// Address: 0x8022E0A0, Size: 12
// =============================================================================
const ETypeInfo* EIStaticModel::GetTypeInfoStatic() {
    return &m_typeInfo;
}

// =============================================================================
// EIStaticModel::GetReadVersion
// Address: 0x8022E0AC, Size: 12
// =============================================================================
u16 EIStaticModel::GetReadVersion() {
    return m_typeInfo.m_readVersion;
}

// =============================================================================
// EIStaticModel::CreateCopy
// Address: 0x8022E10C, Size: 32
// =============================================================================
EStorable* EIStaticModel::CreateCopy() const {
    EStorable_CreateCopy((EStorable*)this);
    return (EStorable*)this;
}

// =============================================================================
// EIStaticModel::operator new(unsigned int, void*)
// Address: 0x8022E16C, Size: 8
// Placement new - returns ptr
// =============================================================================
void* EIStaticModel::operator new(unsigned int size, void* ptr) {
    return ptr;
}

// =============================================================================
// EIStaticModel::GetPos
// Address: 0x8022E1A8, Size: 32
// Copies pos from offset 0xF0
// =============================================================================
void EIStaticModel::GetPos(EVec3& pos) {
    pos.x = m_pos.x;
    pos.y = m_pos.y;
    pos.z = m_pos.z;
}

// =============================================================================
// EIStaticModel::GetModelId
// Address: 0x8022E274, Size: 8
// Returns m_modelId (offset 0x110)
// =============================================================================
u32 EIStaticModel::GetModelId() {
    return m_modelId;
}

// =============================================================================
// EIStaticModel::GetModel
// Address: 0x8022E27C, Size: 8
// Returns m_model (offset 0x120)
// =============================================================================
ERModel* EIStaticModel::GetModel() {
    return m_model;
}

// =============================================================================
// EIStaticModel::GetDrawMatrix
// Address: 0x8022E284, Size: 8
// Returns pointer to m_drawMatrix (offset 0x80)
// =============================================================================
EMat4* EIStaticModel::GetDrawMatrix() {
    return (EMat4*)m_drawMatrix;
}

// =============================================================================
// EIStaticModel::GetOrient
// Address: 0x8022E28C, Size: 8
// Returns pointer to m_orient (offset 0xC0)
// =============================================================================
EMat4* EIStaticModel::GetOrient() const {
    return (EMat4*)m_orient;
}

// =============================================================================
// EIStaticSubModel - operator<<(EStream&, EIStaticSubModel*)
// Address: 0x8022E2C0, Size: 32
// =============================================================================
EStream& operator<<(EStream& stream, EIStaticSubModel* model) {
    return operator<<(stream, (EStorable*)model);
}

// =============================================================================
// EIStaticSubModel - operator>>(EStream&, EIStaticSubModel*&)
// Address: 0x8022E2E0, Size: 64
// =============================================================================
EStream& operator>>(EStream& stream, EIStaticSubModel*& model) {
    EStorable* tmp;
    operator>>(stream, tmp);
    model = (EIStaticSubModel*)tmp;
    return stream;
}

// =============================================================================
// EIStaticSubModel - operator>>(EFile&, EIStaticSubModel*&)
// Address: 0x8022E320, Size: 64
// =============================================================================
EFile& operator>>(EFile& file, EIStaticSubModel*& model) {
    EStorable* tmp;
    operator>>(file, tmp);
    model = (EIStaticSubModel*)tmp;
    return file;
}

// =============================================================================
// EIStaticSubModel::ModifyColor
// Address: 0x8022F588, Size: 8
// Stores color at offset 0x94
// =============================================================================
void EIStaticSubModel::ModifyColor(u32 color) {
    m_modColor2 = color;
}

// =============================================================================
// EIStaticSubModel::GetModifiableColor
// Address: 0x8022F590, Size: 8
// Returns color at offset 0x94
// =============================================================================
int EIStaticSubModel::GetModifiableColor() {
    return (int)m_modColor2;
}

// =============================================================================
// EIStaticSubModel::Destruct
// Address: 0x8022F774, Size: 36
// =============================================================================
void EIStaticSubModel::Destruct(EIStaticSubModel* model) {
    EInstance_Destruct((EInstance*)model, 2);
}

// =============================================================================
// EIStaticSubModel::GetTypeInfo
// Address: 0x8022F7D8, Size: 12
// =============================================================================
const ETypeInfo* EIStaticSubModel::GetTypeInfo() const {
    return &m_typeInfo;
}

// =============================================================================
// EIStaticSubModel::GetTypeName
// Address: 0x8022F7E4, Size: 12
// =============================================================================
const char* EIStaticSubModel::GetTypeName() const {
    return m_typeInfo.m_name;
}

// =============================================================================
// EIStaticSubModel::GetTypeKey
// Address: 0x8022F7F0, Size: 12
// =============================================================================
u32 EIStaticSubModel::GetTypeKey() const {
    return m_typeInfo.m_key;
}

// =============================================================================
// EIStaticSubModel::GetTypeVersion
// Address: 0x8022F7FC, Size: 12
// =============================================================================
u16 EIStaticSubModel::GetTypeVersion() const {
    return m_typeInfo.m_version;
}

// =============================================================================
// EIStaticSubModel::GetTypeInfoStatic
// Address: 0x8022F808, Size: 12
// =============================================================================
const ETypeInfo* EIStaticSubModel::GetTypeInfoStatic() {
    return &m_typeInfo;
}

// =============================================================================
// EIStaticSubModel::GetReadVersion
// Address: 0x8022F814, Size: 12
// =============================================================================
u16 EIStaticSubModel::GetReadVersion() {
    return m_typeInfo.m_readVersion;
}

// =============================================================================
// EIStaticSubModel::CreateCopy
// Address: 0x8022F874, Size: 32
// =============================================================================
EStorable* EIStaticSubModel::CreateCopy() const {
    EStorable_CreateCopy((EStorable*)this);
    return (EStorable*)this;
}

// =============================================================================
// EIStaticSubModel::operator new(unsigned int, void*)
// Address: 0x8022F8D4, Size: 8
// =============================================================================
void* EIStaticSubModel::operator new(unsigned int size, void* ptr) {
    return ptr;
}

// =============================================================================
// EIStaticSubModel::GetBoundSphere (no-arg version)
// Address: 0x8022F910, Size: 8
// Returns pointer to m_boundSphere (offset 0x80)
// =============================================================================
EBoundSphere* EIStaticSubModel::GetBoundSphere() {
    return (EBoundSphere*)m_boundSphere;
}

// =============================================================================
// EMirrorPortal::SetNumCorners
// Address: 0x802F249C, Size: 8
// =============================================================================
void EMirrorPortal::SetNumCorners(int n) {
    m_numCorners = n;
}

// =============================================================================
// EMirrorPortal::SetFieldOfView
// Address: 0x802F2550, Size: 8
// Stores float at offset 0x00 of this
// =============================================================================
void EMirrorPortal::SetFieldOfView(float fov) {
    *(float*)this = fov;
}

// =============================================================================
// EMirrorPortal::PopPortal
// Address: 0x802F2DA0, Size: 44
// =============================================================================
void EMirrorPortal::PopPortal(E3DWindow& window) {
    E3DWindow_PopClipStack(window, m_portalStackId);
}

// =============================================================================
// ERC::SetColorModulation (stub)
// Address: 0x802F8DE0, Size: 4
// =============================================================================

// =============================================================================
// ERC::SetAlphaPlane (stub)
// Address: 0x802F9798, Size: 4
// =============================================================================

// =============================================================================
// ERC::SetFog (stub)
// Address: 0x802F979C, Size: 4
// =============================================================================

// =============================================================================
// ERC::LightsRadiosity (stub)
// Address: 0x802F9ABC, Size: 4
// =============================================================================

// =============================================================================
// EVec4::Print (stub)
// Address: 0x80361F34, Size: 4
// =============================================================================

// =============================================================================
// EInstance functions from e_ilight.obj
// =============================================================================

// =============================================================================
// EInstance - operator<<(EStream&, EInstance*)
// Address: 0x802281F0, Size: 32 (from e_ilight.obj)
// =============================================================================

// =============================================================================
// EInstance::SetOrient (stub)
// Address: 0x80229484, Size: 4
// =============================================================================

// =============================================================================
// EInstance::GetShadowCenter (stub)
// Address: 0x8022965C, Size: 4
// =============================================================================

// =============================================================================
// EInstance::GetVelocity
// Address: 0x80229690, Size: 24
// Returns zero vector
// =============================================================================

// =============================================================================
// EInstance::GetPos
// Address: 0x802296A8, Size: 24
// Returns zero vector
// =============================================================================

// =============================================================================
// EInstance::AddedToLevel (stub)
// Address: 0x802296F8, Size: 4
// =============================================================================

// =============================================================================
// EInstance::AboutToBeRemovedFromLevel (stub)
// Address: 0x802296FC, Size: 4
// =============================================================================

// =============================================================================
// EInstance::RemovedFromLevel (stub)
// Address: 0x80229700, Size: 4
// =============================================================================
