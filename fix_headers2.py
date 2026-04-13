import os

fixes = {
    'src/matched/memorymeterwin/match_0x80057998_EMemoryMeterWin__Init_void.cpp': '// 0x80057998 EMemoryMeterWin::Init (4b)',
    'src/matched/memorymeterwin/match_0x8005799C_EMemoryMeterWin__Reset_void.cpp': '// 0x8005799C EMemoryMeterWin::Reset (4b)',
    'src/matched/memorymeterwin/match_0x800579A0_sub_passthrough.cpp': '// 0x800579A0 EMemoryMeterWin::SetState (32b)',
    'src/matched/memorymeterwin/match_80057940_EMemoryMeterWin__dtor.cpp': '// 0x80057940 EMemoryMeterWin::~EMemoryMeterWin (88b)',
    'src/matched/espriterenderman/match_0x80036F64_ESpriteRenderMan__Update.cpp': '// 0x80036F64 ESpriteRenderMan::Update (80b)',
    'src/matched/espriterenderman/match_0x80037048_ESpriteRenderMan__DrawIntoOrderTable.cpp': '// 0x80037048 ESpriteRenderMan::DrawIntoOrderTable (68b)',
    'src/matched/espriterenderman/match_0x8003708C_ESpriteRenderMan__DrawDirectly.cpp': '// 0x8003708C ESpriteRenderMan::DrawDirectly (76b)',
    'src/matched/espriterenderman/match_0x80037130_ESpriteRenderMan__AddSprite.cpp': '// 0x80037130 ESpriteRenderMan::AddSprite (96b)',
    'src/matched/esimscratchpadman/match_0x800353D4_Default2dArrayAlloc.cpp': '// 0x800353D4 _Default2dArrayAlloc (56b)',
    'src/matched/esimscratchpadman/match_0x8003540C_Default2dArrayFree.cpp': '// 0x8003540C _Default2dArrayFree (52b)',
    'src/matched/esimscratchpadman/match_0x8003545C_ESimScratchPadMan__EmptyHeap.cpp': '// 0x8003545C ESimScratchPadMan::EmptyHeap (4b)',
    'src/matched/motivecurve/match_0x800C2D8c_ESimsApp_CleanupAfterMovie.cpp': '// 0x800C2D8C MotiveCurveSet::PrintMotiveGraph (4b)',
    'src/matched/motivecurve/match_0x800C2E98_MotiveCurveSet__LoadFromStringSet.cpp': '// 0x800C2E98 MotiveCurveSet::LoadFromStringSet (116b)',
}

for path, header in fixes.items():
    with open(path, 'r') as fp:
        content = fp.read()
    lines = content.split('\n')
    if lines[0].startswith('// FLAGS:'):
        new_content = header + '\n' + content
    else:
        new_content = header + '\n' + '\n'.join(lines[1:])
    with open(path, 'w') as fp:
        fp.write(new_content)
    print(f'Fixed: {path}')
