import subprocess, re

targets = [
    (0x8008FF18, 24, "LiveModeInitState::DatasetPendingAddRefAsync"),
    (0x8009018C, 24, "ChangeHouseLoadHouse::DatasetPendingAddRefAsync"),
    (0x80090BB8, 24, "LoadingScreenStateMachine::IsReadyToLoad"),
    (0x800922DC, 24, "MUStatesSaveNewGame::Reset"),
    (0x800EAA68, 24, "cXObjectImpl::GetMiscFlag"),
    (0x800EB218, 24, "cXObjectImpl::CountObjectSlots"),
    (0x80146998, 24, "TileWalls::HasWall"),
    (0x8017BF2C, 24, "UIHDTV::IsFoundNumberNegative"),
    (0x80183120, 24, "ActionMenu::MenuItem::GetNthItem"),
    (0x80190DF4, 24, "InteractionHelper::GetNext"),
    (0x801C1144, 24, "M2MTarget::GetMemCardPort"),
    (0x8021CEF0, 24, "FadeSquare::StopDraw"),
]

for addr, size, name in targets:
    print(f"=== {name} @ 0x{addr:08X} ({size}B) ===")
    result = subprocess.run(
        ["bash", "tools/verify_match.sh", "test_audio_eff.cpp", hex(addr), str(size)],
        capture_output=True, text=True
    )
    lines = result.stdout.splitlines() + result.stderr.splitlines()
    # print last lines containing disassembly
    in_disasm = False
    for line in lines:
        if "Disassembly of section .text:" in line:
            in_disasm = True
        if in_disasm:
            print(line)
    print()
