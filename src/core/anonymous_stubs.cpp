// anonymous_stubs.cpp - Stub implementations for Anonymous
// Auto-generated from symbols.json - 37 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x800034C0 | 396 bytes
void OverrideMotionBlurSettingsFromTokens(FrameEffectsMotionBlurDataElement *, EString *, int) { }

// 0x8000364C | 716 bytes
void OverrideBloomSettingsFromTokens(FrameEffectsBloomDataElement *, EString *, int) { }

// 0x80003918 | 476 bytes
void OverrideDOFSettingsFromTokens(FrameEffectsDepthOfFieldDataElement *, EString *, int) { }

// 0x80021E10 | 76 bytes
void InterpolateSmooth<float>(float *, float &, float, float) { }

// 0x80022028 | 408 bytes
void HandleEffectNote(ESimsCam *, EAnimNote &, anim::PropKind) { }

// 0x8002DA60 | 60 bytes
float InterpolateLinear<float>(float, float, float, float, float) {
    return 0;
}

// 0x8002DA9C | 300 bytes
void InterpolateSmooth<EVec3>(EVec3 *, EVec3 &, float, float) { }

// 0x8004AAE0 | 216 bytes
void IsPartOfDOFForeground(ESim *) { }

// 0x800F4844 | 144 bytes
void RenderPostProcessEffects(int, ERC *) { }

// 0x8022E074 | 32 bytes
void AmbientSoundTest::~AmbientSoundTest(void) { }

// 0x8022F440 | 32 bytes
void CasMediatorTest::~CasMediatorTest(void) { }

// 0x8022F85C | 52 bytes
void CasDummy1::~CasDummy1(void) { }

// 0x8022F890 | 16 bytes
void CasDummy1::HandleEventChangeSim(CasEventChangeSimS2C &) { }

// 0x8022F8A0 | 52 bytes
void CasDummy2::~CasDummy2(void) { }

// 0x8022F8D4 | 16 bytes
void CasDummy2::HandleEventResetSim(CasEventResetSim &) { }

// 0x80230C88 | 32 bytes
void CasSceneTest::~CasSceneTest(void) { }

// 0x80230F3C | 48 bytes
void CasSceneDummy::~CasSceneDummy(void) { }

// 0x80230F6C | 4 bytes
void CasSceneDummy::Update(float) { }

// 0x80230F70 | 4 bytes
void CasSceneDummy::Draw(ERC *) { }

// 0x80230F74 | 148 bytes
void CasSceneDummy::Reload(void) { }

// 0x80231008 | 8 bytes
void CasSceneDummy::GetLights(void) { }

// 0x80231010 | 8 bytes
void CasSceneDummy::CanPlayerRotateSim(void) const { }

// 0x80231018 | 64 bytes
void CasSceneDummy::HandleEventChangeFocus(CasEventChangeFocus &) { }

// 0x80231058 | 8 bytes
void CasSceneDummy::GetMirrorCorners(CasScene::RoomId, EVec3 *) const { }

// 0x80231060 | 12 bytes
void CasSceneDummy::GetSceneName(void) const { }

// 0x8023106C | 8 bytes
void CasSceneDummy::GetRoomModelId(CasScene::RoomId) const { }

// 0x80232418 | 32 bytes
void CasSimRendererTest::~CasSimRendererTest(void) { }

// 0x80233F94 | 32 bytes
void CasSimStateTest::~CasSimStateTest(void) { }

// 0x802355E4 | 32 bytes
void CasUtilsTest::~CasUtilsTest(void) { }

// 0x8023BF20 | 32 bytes
void CompactMapTest::~CompactMapTest(void) { }

// 0x8023BF40 | 68 bytes
void CompactMapTest::CompactMapTest(char *) { }

// 0x80533910 | 264 bytes
EVec3 InterpolateLinear<EVec3>(EVec3, EVec3, float, float, float) { }

// 0x805341D8 | 288 bytes
void CopyEFBToBuffer(void *, int, int, TRect<float> &, EVec2 &) { }

// 0x805342F8 | 852 bytes
void CopyBufferToBufferScaled(void *, _GXTexObj *, int, int, int, int, TRect<float> &, ENgcRenderStateCache *, EVec2 &, EVec2 &) { }

// 0x8053464C | 1996 bytes
void ConstructBloomMipSurface(void *, _GXTexObj *, int, int, float, float, float, int, int, TRect<float> &, ENgcRenderStateCache *) { }

// 0x80534E18 | 2168 bytes
void BlendJitteredScratchBufferWithFrameBuffer(_GXTexObj *, _GXTexObj *, _GXColor &, _GXColor &, TRect<float> &, ENgcRenderStateCache *, _GXRenderModeObj &, EVec2 &, EVec2 &) { }

// 0x80535690 | 836 bytes
void SetDefaultRenderStates(ENgcRenderStateCache *, _GXRenderModeObj &) { }
