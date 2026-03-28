import os

matched_dir = 'src/matched/agent'
count = 0

# WallManipulator bitfield getters
wm_bitfields = [
    (0x80223F94, 'WallManipulator', 'IsRoomPreview', 0xC4, 4),
    (0x80223FA0, 'WallManipulator', 'IsBuyMode', 0xC4, 2),
    (0x80223FAC, 'WallManipulator', 'IsSellMode', 0xC4, 3),
    (0x80223FB8, 'WallManipulator', 'IsFenceMode', 0xC4, 8),
    (0x80223FC4, 'WallManipulator', 'IsDestructMode', 0xC4, 9),
]

for addr, cls, fname, offset, bit in wm_bitfields:
    filepath = os.path.join(matched_dir, 'match_0x%08X_%s_%s.cpp' % (addr, cls, fname))
    code = 'struct %s {\n    char _pad[0x%02X];\n    unsigned int m_flags;\n    int %s();\n};\nint %s::%s() { return (m_flags >> %d) & 1; }\n' % (cls, offset, fname, cls, fname, bit)
    with open(filepath, 'w') as f:
        f.write(code)
    count += 1

# WallPainter bitfield getters
wp_bitfields = [
    (0x80226960, 'WallPainter', 'IsValidWallSegment', 0x88, 7),
    (0x8022696C, 'WallPainter', 'IsRoomPreview', 0x88, 4),
    (0x80226978, 'WallPainter', 'IsBuyMode', 0x88, 2),
    (0x80226984, 'WallPainter', 'IsSellMode', 0x88, 3),
]

for addr, cls, fname, offset, bit in wp_bitfields:
    filepath = os.path.join(matched_dir, 'match_0x%08X_%s_%s.cpp' % (addr, cls, fname))
    code = 'struct %s {\n    char _pad[0x%02X];\n    unsigned int m_flags;\n    int %s();\n};\nint %s::%s() { return (m_flags >> %d) & 1; }\n' % (cls, offset, fname, cls, fname, bit)
    with open(filepath, 'w') as f:
        f.write(code)
    count += 1

# LightArray::Init
filepath = os.path.join(matched_dir, 'match_0x80228EF4_LightArray_Init.cpp')
code = 'struct LightArray {\n    char _pad[0xD00];\n    int m_initialized;\n    void Init();\n};\nvoid LightArray::Init() { m_initialized = 0; }\n'
with open(filepath, 'w') as f:
    f.write(code)
count += 1

# Register functions
filepath = os.path.join(matched_dir, 'match_0x802295D4_EInstance_RegisterOtherSideFn.cpp')
code = 'struct EInstance {\n    char _pad[0x20];\n    int m_otherSideFn;\n    int m_otherSideData;\n    void RegisterOtherSideFn(int data, int fn);\n};\nvoid EInstance::RegisterOtherSideFn(int data, int fn) { m_otherSideFn = fn; m_otherSideData = data; }\n'
with open(filepath, 'w') as f:
    f.write(code)
count += 1

filepath = os.path.join(matched_dir, 'match_0x80229600_EInstance_RegisterThisSideFn.cpp')
code = 'struct EInstance {\n    char _pad1[0x1C];\n    int m_thisSideFn;\n    char _pad2[0x28 - 0x20];\n    int m_thisSideData;\n    void RegisterThisSideFn(int data, int fn);\n};\nvoid EInstance::RegisterThisSideFn(int data, int fn) { m_thisSideFn = fn; m_thisSideData = data; }\n'
with open(filepath, 'w') as f:
    f.write(code)
count += 1

filepath = os.path.join(matched_dir, 'match_0x8022960C_EInstance_RegisterHiddenFn.cpp')
code = 'struct EInstance {\n    char _pad[0x2C];\n    int m_hiddenData;\n    int m_hiddenFn;\n    void RegisterHiddenFn(int data, int fn);\n};\nvoid EInstance::RegisterHiddenFn(int data, int fn) { m_hiddenFn = fn; m_hiddenData = data; }\n'
with open(filepath, 'w') as f:
    f.write(code)
count += 1

# WallPainter::GetShaderID
filepath = os.path.join(matched_dir, 'match_0x80226830_WallPainter_GetShaderID.cpp')
code = 'struct ShaderObj {\n    char _pad[0x08];\n    int m_id;\n};\nstruct WallPainter {\n    char _pad[0x90];\n    ShaderObj *m_shader;\n    int GetShaderID();\n};\nint WallPainter::GetShaderID() { return m_shader->m_id; }\n'
with open(filepath, 'w') as f:
    f.write(code)
count += 1

# Emitter::SetScale
filepath = os.path.join(matched_dir, 'match_0x80238974_Emitter_SetScale.cpp')
code = 'struct EmitterInner {\n    char _pad[0xBC];\n    float m_scale;\n};\nstruct Emitter {\n    char _pad[0x7C];\n    EmitterInner *m_inner;\n    void SetScale(float scale);\n};\nvoid Emitter::SetScale(float scale) { m_inner->m_scale = scale; }\n'
with open(filepath, 'w') as f:
    f.write(code)
count += 1

# EILight::GetFalloffEnd
filepath = os.path.join(matched_dir, 'match_0x802281A8_EILight_GetFalloffEnd.cpp')
code = 'extern float gEILight_FalloffEnd;\n\nstruct EILight {\n    float GetFalloffEnd();\n};\nfloat EILight::GetFalloffEnd() { return gEILight_FalloffEnd; }\n'
with open(filepath, 'w') as f:
    f.write(code)
count += 1

# GetTypeInfo pattern (returns address of static typeinfo)
type_info_funcs = [
    (0x80226F1C, 'EIAmbLight'), (0x80226F4C, 'EIAmbLight'),
    (0x80227418, 'EIDirLight'), (0x80227448, 'EIDirLight'),
    (0x802277FC, 'EIGameInstance'), (0x8022782C, 'EIGameInstance'),
    (0x80228008, 'EILight'), (0x80228038, 'EILight'),
    (0x802293A0, 'EInstance'), (0x802293D0, 'EInstance'),
    (0x80229C44, 'EIPointAmbLight'), (0x80229C74, 'EIPointAmbLight'),
    (0x8022A560, 'EIPointLight'), (0x8022A590, 'EIPointLight'),
    (0x8022B038, 'EIPortalPointLight'), (0x8022B068, 'EIPortalPointLight'),
    (0x8022B818, 'EISpotLight'), (0x8022B848, 'EISpotLight'),
    (0x8022E070, 'EIStaticModel'), (0x8022E0A0, 'EIStaticModel'),
    (0x8022F7D8, 'EIStaticSubModel'), (0x8022F808, 'EIStaticSubModel'),
    (0x802380F4, 'ERLevel'), (0x80238124, 'ERLevel'),
]

fnames_ti = ['GetTypeInfo', 'GetTypeInfoStatic'] * 12
for i, (addr, cls) in enumerate(type_info_funcs):
    fname = fnames_ti[i]
    filepath = os.path.join(matched_dir, 'match_0x%08X_%s_%s.cpp' % (addr, cls, fname))
    code = 'extern int %s_typeinfo;\n\nstruct %s {\n    int *%s();\n};\nint *%s::%s() { return &%s_typeinfo; }\n' % (cls, cls, fname, cls, fname, cls)
    with open(filepath, 'w') as f:
        f.write(code)
    count += 1

# GetTypeName/GetTypeKey
type_name_funcs = [
    (0x80226F28, 'EIAmbLight', 'GetTypeName'),
    (0x80226F34, 'EIAmbLight', 'GetTypeKey'),
    (0x80227424, 'EIDirLight', 'GetTypeName'),
    (0x80227430, 'EIDirLight', 'GetTypeKey'),
    (0x80227808, 'EIGameInstance', 'GetTypeName'),
    (0x80227814, 'EIGameInstance', 'GetTypeKey'),
    (0x80228014, 'EILight', 'GetTypeName'),
    (0x80228020, 'EILight', 'GetTypeKey'),
    (0x802293AC, 'EInstance', 'GetTypeName'),
    (0x802293B8, 'EInstance', 'GetTypeKey'),
    (0x80229C50, 'EIPointAmbLight', 'GetTypeName'),
    (0x80229C5C, 'EIPointAmbLight', 'GetTypeKey'),
    (0x8022A56C, 'EIPointLight', 'GetTypeName'),
    (0x8022A578, 'EIPointLight', 'GetTypeKey'),
    (0x8022B044, 'EIPortalPointLight', 'GetTypeName'),
    (0x8022B050, 'EIPortalPointLight', 'GetTypeKey'),
    (0x8022B824, 'EISpotLight', 'GetTypeName'),
    (0x8022B830, 'EISpotLight', 'GetTypeKey'),
    (0x8022E07C, 'EIStaticModel', 'GetTypeName'),
    (0x8022E088, 'EIStaticModel', 'GetTypeKey'),
    (0x8022F7E4, 'EIStaticSubModel', 'GetTypeName'),
    (0x8022F7F0, 'EIStaticSubModel', 'GetTypeKey'),
    (0x80238100, 'ERLevel', 'GetTypeName'),
    (0x8023810C, 'ERLevel', 'GetTypeKey'),
]

for addr, cls, fname in type_name_funcs:
    filepath = os.path.join(matched_dir, 'match_0x%08X_%s_%s.cpp' % (addr, cls, fname))
    code = 'extern int %s_%s_val;\n\nstruct %s {\n    int %s();\n};\nint %s::%s() { return %s_%s_val; }\n' % (cls, fname, cls, fname, cls, fname, cls, fname)
    with open(filepath, 'w') as f:
        f.write(code)
    count += 1

# GetTypeVersion/GetReadVersion (returns short)
type_ver_funcs = [
    (0x80226F40, 'EIAmbLight', 'GetTypeVersion'),
    (0x80226F58, 'EIAmbLight', 'GetReadVersion'),
    (0x8022743C, 'EIDirLight', 'GetTypeVersion'),
    (0x80227454, 'EIDirLight', 'GetReadVersion'),
    (0x80227820, 'EIGameInstance', 'GetTypeVersion'),
    (0x80227838, 'EIGameInstance', 'GetReadVersion'),
    (0x8022802C, 'EILight', 'GetTypeVersion'),
    (0x80228044, 'EILight', 'GetReadVersion'),
    (0x802293C4, 'EInstance', 'GetTypeVersion'),
    (0x802293DC, 'EInstance', 'GetReadVersion'),
    (0x80229C68, 'EIPointAmbLight', 'GetTypeVersion'),
    (0x80229C80, 'EIPointAmbLight', 'GetReadVersion'),
    (0x8022A584, 'EIPointLight', 'GetTypeVersion'),
    (0x8022A59C, 'EIPointLight', 'GetReadVersion'),
    (0x8022B05C, 'EIPortalPointLight', 'GetTypeVersion'),
    (0x8022B074, 'EIPortalPointLight', 'GetReadVersion'),
    (0x8022B83C, 'EISpotLight', 'GetTypeVersion'),
    (0x8022B854, 'EISpotLight', 'GetReadVersion'),
    (0x8022E094, 'EIStaticModel', 'GetTypeVersion'),
    (0x8022E0AC, 'EIStaticModel', 'GetReadVersion'),
    (0x8022F7FC, 'EIStaticSubModel', 'GetTypeVersion'),
    (0x8022F814, 'EIStaticSubModel', 'GetReadVersion'),
    (0x80238118, 'ERLevel', 'GetTypeVersion'),
    (0x80238130, 'ERLevel', 'GetReadVersion'),
]

for addr, cls, fname in type_ver_funcs:
    filepath = os.path.join(matched_dir, 'match_0x%08X_%s_%s.cpp' % (addr, cls, fname))
    code = 'extern short %s_%s_val;\n\nstruct %s {\n    short %s();\n};\nshort %s::%s() { return %s_%s_val; }\n' % (cls, fname, cls, fname, cls, fname, cls, fname)
    with open(filepath, 'w') as f:
        f.write(code)
    count += 1

# ERLevel large-offset functions
erlevel_ptr = [
    (0x80238214, 'GetSun', 0x2E2F0),
    (0x80238220, 'GetSunAmbient', 0x2E3A8),
]
for addr, fname, offset in erlevel_ptr:
    filepath = os.path.join(matched_dir, 'match_0x%08X_ERLevel_%s.cpp' % (addr, fname))
    code = 'struct ERLevel {\n    char _pad[0x%X];\n    int m_%s;\n    int *%s();\n};\nint *ERLevel::%s() { return &m_%s; }\n' % (offset, fname, fname, fname, fname)
    with open(filepath, 'w') as f:
        f.write(code)
    count += 1

erlevel_get = [
    (0x80238298, 'IsInUse', 0x2A2B0),
    (0x802382A4, 'GetRoomCount', 0x2A2B4),
    (0x80238348, 'GetNumInstances', 0x2C2B8),
    (0x80238368, 'GetNumVisibleInstances', 0x2E2CC),
    (0x802382EC, 'GetStorableVersion', 0x2A198),
    (0x8023825C, 'WallFadeState', 0x2E2D4),
]
for addr, fname, offset in erlevel_get:
    filepath = os.path.join(matched_dir, 'match_0x%08X_ERLevel_%s.cpp' % (addr, fname))
    code = 'struct ERLevel {\n    char _pad[0x%X];\n    int m_%s;\n    int %s();\n};\nint ERLevel::%s() { return m_%s; }\n' % (offset, fname, fname, fname, fname)
    with open(filepath, 'w') as f:
        f.write(code)
    count += 1

erlevel_set = [
    (0x8023822C, 'SetDayNightLightTable', 0x2E454),
    (0x80238238, 'SetRainInfoTable', 0x2E458),
    (0x80238250, 'SetWallFadeState', 0x2E2D4),
    (0x80238388, 'SetDrawWallShadowsFunc', 0x2E2D8),
]
for addr, fname, offset in erlevel_set:
    filepath = os.path.join(matched_dir, 'match_0x%08X_ERLevel_%s.cpp' % (addr, fname))
    code = 'struct ERLevel {\n    char _pad[0x%X];\n    int m_%s;\n    void %s(int val);\n};\nvoid ERLevel::%s(int val) { m_%s = val; }\n' % (offset, fname, fname, fname, fname)
    with open(filepath, 'w') as f:
        f.write(code)
    count += 1

# ERLevel float setters
filepath = os.path.join(matched_dir, 'match_0x802382E0_ERLevel_SetRainBlend.cpp')
with open(filepath, 'w') as f:
    f.write('struct ERLevel {\n    char _pad[0x2E2E8];\n    float m_rainBlend;\n    void SetRainBlend(float val);\n};\nvoid ERLevel::SetRainBlend(float val) { m_rainBlend = val; }\n')
count += 1

filepath = os.path.join(matched_dir, 'match_0x80238244_ERLevel_SetSunYawOffset.cpp')
with open(filepath, 'w') as f:
    f.write('struct ERLevel {\n    char _pad[0x2E45C];\n    float m_sunYawOffset;\n    void SetSunYawOffset(float val);\n};\nvoid ERLevel::SetSunYawOffset(float val) { m_sunYawOffset = val; }\n')
count += 1

print('Created %d files' % count)
