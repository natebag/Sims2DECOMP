// egraphics_stubs.cpp - Stub implementations for Egraphics
// Auto-generated from symbols.json - 22 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x80493D3C | 408 bytes
EGraphics::EGraphics(void) { }

// 0x80493F24 | 176 bytes
void EGraphics::Init(void) { }

// 0x80493FD4 | 148 bytes
void EGraphics::DeselectTextures(void) { }

// 0x80494068 | 88 bytes
void EGraphics::BeginFrame(void) { }

// 0x804940C0 | 136 bytes
void EGraphics::EndFrame(void) { }

// 0x80494150 | 148 bytes
void EGraphics::Flush(void) { }

// 0x804941E4 | 108 bytes
void EGraphics::GetOutputRect(TRect<float> &, int) { }

// 0x80494398 | 120 bytes
void EGraphics::Open(RCMode) { }

// 0x80494410 | 176 bytes
void EGraphics::Close(ERC *) { }

// 0x8049458C | 164 bytes
void EGraphics::CreateTexture(ETextureDef &) { }

// 0x804946E8 | 164 bytes
void EGraphics::CreateShader(EShaderDef &) { }

// 0x804947E0 | 164 bytes
void EGraphics::CreateRenderSurface(ERenderSurfaceDef &) { }

// 0x8049495C | 152 bytes
void EGraphics::AllocVertexData(unsigned int) { }

// 0x804949F4 | 80 bytes
void EGraphics::FreeVertexData(void *) { }

// 0x80494A44 | 228 bytes
void EGraphics::ComputeViewport(EViewport &, TRect<float> &) { }

// 0x80494B28 | 124 bytes
void EGraphics::SetUpNormalMapMatrix(void) { }

// 0x80494BA4 | 124 bytes
void EGraphics::LoadSystemFont(void) { }

// 0x80494C20 | 1228 bytes
void EGraphics::DrawTiming(void) { }

// 0x8049511C | 72 bytes
void EGraphics::DisplayTiming(bool, EVec2 &) { }

// 0x80495164 | 140 bytes
void EGraphics::SetCensorRect(EVec3 &, EVec3 &, bool) { }

// 0x80495284 | 100 bytes
void EGraphics::SetBloom(void) { }

// 0x80495400 | 432 bytes
void EGraphics::DrawDebugText(float, float, char *,...) { }
