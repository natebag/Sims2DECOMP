#ifndef ENGCRC_H
#define ENGCRC_H

#include "types.h"

// ENgcRC - struct layout extracted from assembly analysis
// Estimated minimum size: 0x74 (116 bytes)
// 13 known fields (0 named), 138 methods

class ENgcRC {
public:
    // Constructors / Destructors
    ENgcRC(void)  // 0x808B524C
    ~ENgcRC(void);  // 0x808B5298

    // Methods
    void Init(RCMode);  // 0x808B52E4 (64B)
    void EndCommand(void);  // 0x808B5324 (244B)
    void TriStrip(EGEVert *, int);  // 0x808B5418 (260B)
    void TriStrip(int, float *, float *, unsigned char *, signed char *, unsigned char *, bool);  // 0x808B551C (1872B)
    void TriStripRef(int, float *, float *, unsigned char *, signed char *, unsigned char *, bool);  // 0x808B5C6C (1748B)
    void TriStrip(int, int, unsigned short *, float *, float *, unsigned char *, signed char *, unsigned char *);  // 0x808B6340 (1844B)
    void TriStripRef(int, int, unsigned short *, float *, float *, unsigned char *, signed char *, unsigned char *);  // 0x808B6A74 (1924B)
    void TriStrip(int, short *, short *, unsigned char *, signed char *, unsigned char *, bool);  // 0x808B71F8 (1764B)
    void TriStripRef(int, short *, short *, unsigned char *, signed char *, unsigned char *, bool);  // 0x808B78DC (1288B)
    void TriStrip(int, int, unsigned short *, short *, short *, unsigned char *, signed char *, unsigned char *);  // 0x808B7DE4 (1848B)
    void TriStripRef(int, int, unsigned short *, short *, short *, unsigned char *, signed char *, unsigned char *);  // 0x808B851C (1316B)
    void TextureCacheInvalidate(void);  // 0x808B8A40 (100B)
    void TriStripDL(unsigned char *, int, int, float *, float *, unsigned char *, signed char *);  // 0x808B8AA4 (1672B)
    void TriStripDLRef(unsigned char *, int, int, float *, float *, unsigned char *, signed char *, bool);  // 0x808B912C (1308B)
    void TriStripDL(unsigned char *, int, int, short *, short *, unsigned char *, signed char *);  // 0x808B9648 (1252B)
    void TriStripDLRef(unsigned char *, int, int, short *, short *, unsigned char *, signed char *, bool);  // 0x808B9B2C (1096B)
    void TriList(int, short *, short *, unsigned char *, signed char *, unsigned char *, bool);  // 0x808B9F74 (1328B)
    void TriList(int, float *, float *, unsigned char *, signed char *, unsigned char *, bool);  // 0x808BA4A4 (160B)
    void ScreenTriList(int, float *, float *, unsigned char *);  // 0x808BA544 (148B)
    void ReadMetrics(void);  // 0x808BA5D8 (100B)
    void Shader(ENgcShader *, unsigned int);  // 0x808BA63C (404B)
    void ScrambleRect(EVec2 &, EVec2 &, float);  // 0x808BA7D0 (180B)
    void ModelMatrixList(EMat4 *, int);  // 0x808BA884 (280B)
    void ModelMatrixIndex(int, int);  // 0x808BA99C (484B)
    void ModelMatrices(EMat4 *, int);  // 0x808BAB80 (380B)
    void DisplayList(EDL *);  // 0x808BACFC (644B)
    void Texture(ETexture *, int);  // 0x808BAF80 (608B)
    void SetMipMap(float, int);  // 0x808BB1E0 (40B)
    void EnableGeometryModes(unsigned int);  // 0x808BB208 (192B)
    void DisableGeometryModes(unsigned int);  // 0x808BB2C8 (196B)
    void SetGeometryModes(unsigned int);  // 0x808BB38C (192B)
    void EnableRasterModes(unsigned int, int);  // 0x808BB44C (320B)
    void DisableRasterModes(unsigned int, int);  // 0x808BB58C (324B)
    void SetRasterModes(unsigned int, int);  // 0x808BB6D0 (320B)
    void Viewport(EViewport *);  // 0x808BB810 (292B)
    void ClipRect(TRect<float> &);  // 0x808BB934 (548B)
    void Scissor(TRect<float> *);  // 0x808BBB58 (292B)
    void ViewMatrix(EMat4 *, int, float);  // 0x808BBC7C (300B)
    void ProjectionMatrix(EMat4 *);  // 0x808BBDA8 (292B)
    void WindowMatrix(EMat4 *);  // 0x808BBECC (292B)
    void SaveState(void);  // 0x808BBFF0 (176B)
    void RestoreState(void);  // 0x808BC0A0 (176B)
    void Lights(ELights *);  // 0x808BC150 (500B)
    void Material(EMaterial *);  // 0x808BC344 (292B)
    void Rect(EVec2 &, EVec2 &, EVec2 &, EVec2 &, EVec4 &, float);  // 0x808BC468 (324B)
    void RectList(int, float *, EVec4 &, float);  // 0x808BC5AC (284B)
    void RectListRot(int, float *, EVec4 &, float);  // 0x808BC6C8 (284B)
    void DirectRect(EVec2 &, EVec2 &, EVec4 &, float);  // 0x808BC7E4 (284B)
    void EnvironmentMap(bool, bool, int);  // 0x808BC900 (472B)
    void TextureMatrix(EMat4 *, ETCTransformSource, bool, bool, int);  // 0x808BCAD8 (508B)
    void RecalcMatrices(int, int);  // 0x808BCCD4 (100B)
    void GeometrySetup(void);  // 0x808BCD38 (32B)
    void ZTest(bool, int, int, int);  // 0x808BCD58 (228B)
    void ZClear(float, float, float, float, float);  // 0x808BCE3C (1092B)
    void AlphaTest(bool, int, float, int);  // 0x808BD280 (340B)
    void Stencil(int, int, int);  // 0x808BD3D4 (216B)
    void SetBlendMode(int, int, int, int, float, int);  // 0x808BD4AC (1004B)
    void SetCombineMode(int, int);  // 0x808BD898 (432B)
    void SetAlpha(float);  // 0x808BDA48 (164B)
    void RenderSurface(ERenderSurface *, int);  // 0x808BDAEC (204B)
    void QuadList(int, float *, float *, unsigned char *, signed char *, bool);  // 0x808BDBB8 (1716B)
    void SpriteList(int, float *, float *, unsigned char *, signed char *, unsigned char *);  // 0x808BE26C (360B)
    void LineList(EGEVert *, int);  // 0x808BE3D4 (364B)
    void Debug(unsigned int, unsigned int);  // 0x808BE540 (40B)
    void ParticleListInfo(EGEParticleListInfo *);  // 0x808BE568 (36B)
    void ParticleListBegin(unsigned int, unsigned int);  // 0x808BE58C (88B)
    void ParticleListEnd(unsigned int);  // 0x808BE5E4 (68B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_field_000;  // 0x000 [R/W] (DisplayList, EndCommand, LineList, ...)
    u8 m_field_001;  // 0x001 [W] (QuadList, TriList, TriStrip, ...)
    u16 m_field_002;  // 0x002 [W] (TriStrip, TriStripRef)
    u32 m_field_004;  // 0x004 [W] (QuadList, TriList, TriStrip, ...)
    u32 m_field_008;  // 0x008 [W] (QuadList, TriList, TriStrip, ...)
    u32 m_field_00C;  // 0x00C [R/W] (EndCommand, LineList, ModelMatrixIndex, ...)
    u32 m_field_010;  // 0x010 [W] (QuadList, TriList, TriStrip, ...)
    u32 m_field_014;  // 0x014 [W] (EndCommand, QuadList, ReadMetrics, ...)
    u8 m_field_018;  // 0x018 [R/W] (EndCommand, QuadList, ReadMetrics, ...)
    u8 _pad_019[3];  // 0x019
    u32 m_field_01C;  // 0x01C [W] (QuadList, TriList, TriStrip, ...)
    u8 _pad_020[0x1C];  // 0x020
    u32 m_field_03C;  // 0x03C [R] (DisplayList)
    u8 _pad_040[4];  // 0x040
    u32 m_field_044;  // 0x044 [R/W] (ModelMatrices, ModelMatrixIndex)
    u8 _pad_048[0x28];  // 0x048
    u32 m_field_070;  // 0x070 [R] (EndCommand, EnvironmentMap, ModelMatrices, ...)
};

#endif // ENGCRC_H
