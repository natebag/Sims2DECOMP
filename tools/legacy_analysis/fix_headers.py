import os, re

fixes = {
    'src/matched/caslistener/match_0x80161BA0_setter_0x0.cpp': '// 0x80161BA0 CasListener::SetMediator (8b)',
    'src/matched/caslistener/match_0x80161BA8_getter_0x0.cpp': '// 0x80161BA8 CasListener::GetMediator (8b)',
    'src/matched/caslistener/match_80161B50_CasListener__CasListener.cpp': '// 0x80161B50 CasListener::CasListener (28b)',
    'src/matched/objectdatafactory/match_8015BA04_tcf_0.cpp': '// 0x8015BA04 __tcf_0 (40b)',
    'src/matched/objectdatafactory/match_8015BA2C_ObjectDataFactoryQuickData_StringSet__operator.cpp': '// 0x8015BA2C ObjectDataFactoryQuickData<StringSet>::operator() (32b)',
    'src/matched/objectdatafactory/match_8015BA54_ObjectDataFactoryDatabaseStringSet__operator.cpp': '// 0x8015BA54 ObjectDataFactoryDatabase<StringSet>::operator() (8b)',
    'src/matched/objectdatafactory/match_8015BA5C_ObjectDataFactoryQuickData_ObjFnTable__operator.cpp': '// 0x8015BA5C ObjectDataFactoryQuickData<ObjFnTable>::operator() (32b)',
    'src/matched/objectdatafactory/match_8015BA7C_ObjectDataFactoryIFFObjFnTable__operator.cpp': '// 0x8015BA7C ObjectDataFactoryIFF<ObjFnTable>::operator() (8b)',
    'src/matched/objectdatafactory/match_8015BA84_ObjectDataFactoryDatabaseObjFnTable__operator.cpp': '// 0x8015BA84 ObjectDataFactoryDatabase<ObjFnTable>::operator() (8b)',
    'src/matched/objectdatafactory/match_8015BA8C_ObjectDataFactoryQuickData_FloatConstants__operator.cpp': '// 0x8015BA8C ObjectDataFactoryQuickData<FloatConstants>::operator() (32b)',
    'src/matched/objectdatafactory/match_8015BAAC_ObjectDataFactoryIFFFloatConstants__operator.cpp': '// 0x8015BAAC ObjectDataFactoryIFF<FloatConstants>::operator() (8b)',
    'src/matched/objectdatafactory/match_8015BAB4_ObjectDataFactoryDatabaseFloatConstants__operator.cpp': '// 0x8015BAB4 ObjectDataFactoryDatabase<FloatConstants>::operator() (8b)',
    'src/matched/objectdatafactory/match_8015BABC_ObjectDataFactoryQuickData_ITreeTable__operator.cpp': '// 0x8015BABC ObjectDataFactoryQuickData<ITreeTable>::operator() (40b)',
    'src/matched/objectdatafactory/match_8015BAE4_ObjectDataFactoryIFFITreeTable__operator.cpp': '// 0x8015BAE4 ObjectDataFactoryIFF<ITreeTable>::operator() (8b)',
    'src/matched/objectdatafactory/match_8015BAEC_ObjectDataFactoryDatabaseITreeTable__operator.cpp': '// 0x8015BAEC ObjectDataFactoryDatabase<ITreeTable>::operator() (8b)',
    'src/matched/movieplayer/match_0x80058778_MoviePlayerEndgameMovieState_GotoGame.cpp': '// 0x80058778 MoviePlayerEndgameMovieState::GotoGame (112b)',
    'src/matched/movieplayer/match_0x80058820_MoviePlayerEndgameMovieState_ctor.cpp': '// 0x80058820 MoviePlayerEndgameMovieState::MoviePlayerEndgameMovieState (56b)',
    'src/matched/movieplayer/match_0x80058858_sub_lwz_member.cpp': '// 0x80058858 MoviePlayerEndgameMovieState::SetFlowStateCurrent (36b)',
    'src/matched/movieplayer/match_0x803A024C_StateMachineState__Startup_void.cpp': '// 0x803A024C StateMachineState::Startup (4b)',
    'src/matched/movieplayer/match_0x803A02BC_StateMachineState__Shutdown_void.cpp': '// 0x803A02BC StateMachineState::Shutdown (4b)',
    'src/matched/movieplayer/match_0x803A02C0_StateMachineState__Reset_void.cpp': '// 0x803A02C0 StateMachineState::Reset (4b)',
    'src/matched/movieplayer/match_0x803A02C4_StateMachineState__Update_float.cpp': '// 0x803A02C4 StateMachineState::Update (4b)',
}

for path, header in fixes.items():
    with open(path, 'r') as fp:
        content = fp.read()
    # Check if first line is FLAGS
    lines = content.split('\n')
    if lines[0].startswith('// FLAGS:'):
        new_content = header + '\n' + content
    else:
        new_content = header + '\n' + '\n'.join(lines[1:])
    with open(path, 'w') as fp:
        fp.write(new_content)
    print(f'Fixed: {path}')
