// engcrc_stubs.cpp - Stub implementations for Engcrc
// Auto-generated from symbols.json - 59 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x80512498 | 60 bytes
ENgcRC::ENgcRC(void) { }

// 0x805124D4 | 48 bytes
ENgcRC::~ENgcRC(void) { }

// 0x80512504 | 32 bytes
void ENgcRC::Init(RCMode) { }

// 0x80512524 | 104 bytes
void ENgcRC::EndCommand(void) { }

// 0x8051258C | 92 bytes
void ENgcRC::TriStrip(EGEVert *, int) { }

// 0x8051293C | 504 bytes
void ENgcRC::TriStripRef(int, float *, float *, unsigned char *, signed char *, unsigned char *, bool) { }

// 0x80513A30 | 92 bytes
void ENgcRC::TextureCacheInvalidate(void) { }

// 0x80513A8C | 560 bytes
void ENgcRC::TriStripDL(unsigned char *, int, int, float *, float *, unsigned char *, signed char *) { }

// 0x80513CBC | 356 bytes
void ENgcRC::TriStripDLRef(unsigned char *, int, int, float *, float *, unsigned char *, signed char *, bool) { }

// 0x805140FC | 548 bytes
void ENgcRC::TriList(int, short *, short *, unsigned char *, signed char *, unsigned char *, bool) { }

// 0x80514324 | 4 bytes
void ENgcRC::ScreenTriList(int, float *, float *, unsigned char *) { }

// 0x80514328 | 92 bytes
void ENgcRC::ReadMetrics(void) { }

// 0x80514384 | 72 bytes
void ENgcRC::Shader(ENgcShader *, unsigned int) { }

// 0x805143CC | 40 bytes
void ENgcRC::ScrambleRect(EVec2 &, EVec2 &, float) { }

// 0x805143F4 | 44 bytes
void ENgcRC::ModelMatrixList(EMat4 *, int) { }

// 0x80514420 | 84 bytes
void ENgcRC::ModelMatrixIndex(int, int) { }

// 0x80514474 | 160 bytes
void ENgcRC::ModelMatrices(EMat4 *, int) { }

// 0x80514514 | 128 bytes
void ENgcRC::DisplayList(EDL *) { }

// 0x80514594 | 80 bytes
void ENgcRC::Texture(ETexture *, int) { }

// 0x805145E4 | 4 bytes
void ENgcRC::SetMipMap(float, int) { }

// 0x805145E8 | 56 bytes
void ENgcRC::EnableGeometryModes(unsigned int) { }

// 0x80514620 | 60 bytes
void ENgcRC::DisableGeometryModes(unsigned int) { }

// 0x8051465C | 56 bytes
void ENgcRC::SetGeometryModes(unsigned int) { }

// 0x80514694 | 60 bytes
void ENgcRC::EnableRasterModes(unsigned int, int) { }

// 0x805146D0 | 64 bytes
void ENgcRC::DisableRasterModes(unsigned int, int) { }

// 0x80514710 | 60 bytes
void ENgcRC::SetRasterModes(unsigned int, int) { }

// 0x8051474C | 56 bytes
void ENgcRC::Viewport(EViewport *) { }

// 0x80514784 | 88 bytes
void ENgcRC::ClipRect(TRect<float> &) { }

// 0x805147DC | 56 bytes
void ENgcRC::Scissor(TRect<float> *) { }

// 0x80514814 | 56 bytes
void ENgcRC::ViewMatrix(EMat4 *, int, float) { }

// 0x8051484C | 56 bytes
void ENgcRC::ProjectionMatrix(EMat4 *) { }

// 0x80514884 | 56 bytes
void ENgcRC::WindowMatrix(EMat4 *) { }

// 0x805148BC | 52 bytes
void ENgcRC::SaveState(void) { }

// 0x805148F0 | 52 bytes
void ENgcRC::RestoreState(void) { }

// 0x80514924 | 92 bytes
void ENgcRC::Lights(ELights *) { }

// 0x80514980 | 56 bytes
void ENgcRC::Material(EMaterial *) { }

// 0x805149B8 | 156 bytes
void ENgcRC::Rect(EVec2 &, EVec2 &, EVec2 &, EVec2 &, EVec4 &, float) { }

// 0x80514A54 | 104 bytes
void ENgcRC::RectList(int, float *, EVec4 &, float) { }

// 0x80514ABC | 104 bytes
void ENgcRC::RectListRot(int, float *, EVec4 &, float) { }

// 0x80514B24 | 120 bytes
void ENgcRC::DirectRect(EVec2 &, EVec2 &, EVec4 &, float) { }

// 0x80514B9C | 148 bytes
void ENgcRC::EnvironmentMap(bool, bool, int) { }

// 0x80514C30 | 164 bytes
void ENgcRC::TextureMatrix(EMat4 *, ETCTransformSource, bool, bool, int) { }

// 0x80514CD4 | 60 bytes
void ENgcRC::RecalcMatrices(int, int) { }

// 0x80514D10 | 4 bytes
void ENgcRC::GeometrySetup(void) { }

// 0x80514D14 | 68 bytes
void ENgcRC::ZTest(bool, int, int, int) { }

// 0x80514D58 | 600 bytes
void ENgcRC::ZClear(float, float, float, float, float) { }

// 0x80514FB0 | 124 bytes
void ENgcRC::AlphaTest(bool, int, float, int) { }

// 0x8051502C | 64 bytes
void ENgcRC::Stencil(int, int, int) { }

// 0x8051506C | 120 bytes
void ENgcRC::SetBlendMode(int, int, int, int, float, int) { }

// 0x805150E4 | 60 bytes
void ENgcRC::SetCombineMode(int, int) { }

// 0x80515120 | 40 bytes
void ENgcRC::SetAlpha(float) { }

// 0x80515148 | 60 bytes
void ENgcRC::RenderSurface(ERenderSurface *, int) { }

// 0x80515184 | 740 bytes
void ENgcRC::QuadList(int, float *, float *, unsigned char *, signed char *, bool) { }

// 0x80515468 | 76 bytes
void ENgcRC::SpriteList(int, float *, float *, unsigned char *, signed char *, unsigned char *) { }

// 0x805154B4 | 92 bytes
void ENgcRC::LineList(EGEVert *, int) { }

// 0x80515510 | 4 bytes
void ENgcRC::Debug(unsigned int, unsigned int) { }

// 0x80515514 | 4 bytes
void ENgcRC::ParticleListInfo(EGEParticleListInfo *) { }

// 0x80515518 | 40 bytes
void ENgcRC::ParticleListBegin(unsigned int, unsigned int) { }

// 0x80515540 | 40 bytes
void ENgcRC::ParticleListEnd(unsigned int) { }
