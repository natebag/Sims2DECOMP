#!/usr/bin/env python3
"""Compare compiled slots.o functions against original ELF."""
import subprocess

OBJDUMP = "F:/coding/Decompiles/Tools/devkitPro/devkitPPC/bin/powerpc-eabi-objdump.exe"
ELF = "F:/coding/Decompiles/Sims 2/extracted/files/u2_ngc_release_dvd.elf"
OBJ = "F:/coding/Decompiles/Sims 2/.claude/worktrees/agent-a544fb05/build/check/slots.o"

def disasm_elf(start, stop):
    result = subprocess.run([OBJDUMP, '-d', '-M', 'gekko',
                            f'--start-address={start}', f'--stop-address={stop}', ELF],
                           capture_output=True, text=True)
    lines = []
    for line in result.stdout.strip().split('\n'):
        line = line.strip()
        if ':' in line and '\t' in line:
            parts = line.split('\t')
            if len(parts) >= 2:
                lines.append(parts[1].strip())
    return lines

# Pre-parse obj file
obj_result = subprocess.run([OBJDUMP, '-d', '-M', 'gekko', OBJ],
                           capture_output=True, text=True)
obj_lines = obj_result.stdout.strip().split('\n')

def disasm_obj(symbol):
    in_func = False
    lines = []
    for line in obj_lines:
        if f'<{symbol}>' in line and '>:' in line:
            in_func = True
            continue
        if in_func:
            stripped = line.strip()
            if stripped == '':
                break
            if stripped.endswith('>:') and '<' in stripped:
                break
            if ':' in stripped and '\t' in stripped:
                parts = stripped.split('\t')
                if len(parts) >= 2:
                    lines.append(parts[1].strip())
    return lines

funcs = [
    ("Slot::WriteSlot", 0x80142990, 0x80142994, "_ZN4Slot9WriteSlotEP14SlotDescriptor"),
    ("Slot::Slot(void)", 0x80142968, 0x8014297c, "_ZN4SlotC1Ev"),
    ("Slot::Slot(desc)", 0x8014297c, 0x80142990, "_ZN4SlotC1EP14SlotDescriptor"),
    ("RoutingSlot::SetIsOnTopOfObject", 0x80142b54, 0x80142b64, "_ZN11RoutingSlot18SetIsOnTopOfObjectEv"),
    ("RoutingSlot::AllowDirection", 0x80142b64, 0x80142b84, "_ZN11RoutingSlot14AllowDirectionEi"),
    ("RoutingSlot::AllowAnyRotation", 0x80142b84, 0x80142b94, "_ZN11RoutingSlot16AllowAnyRotationEv"),
    ("RoutingSlot::AllowAnyFacing", 0x80142b94, 0x80142ba0, "_ZN11RoutingSlot14AllowAnyFacingEv"),
    ("RoutingSlot::FaceTowardsObject", 0x80142ba0, 0x80142bac, "_ZN11RoutingSlot17FaceTowardsObjectEv"),
    ("RoutingSlot::FaceAwayFromObject", 0x80142bac, 0x80142bb8, "_ZN11RoutingSlot18FaceAwayFromObjectEv"),
    ("RoutingSlot::SetFacingDirection", 0x80142bb8, 0x80142bc8, "_ZN11RoutingSlot18SetFacingDirectionEi"),
    ("RoutingSlot::SetDistances", 0x80142bc8, 0x80142bd8, "_ZN11RoutingSlot12SetDistancesEiii"),
    ("RoutingSlot::SetMultiplier", 0x80142c30, 0x80142c40, "_ZN11RoutingSlot13SetMultiplierENS_16VerticalPositionEi"),
    ("RoutingSlot::SetIgnoreRooms", 0x80145560, 0x80145580, "_ZN11RoutingSlot14SetIgnoreRoomsEb"),
    ("RoutingSlot::SetHasRandomScoring", 0x8014561c, 0x8014563c, "_ZN11RoutingSlot19SetHasRandomScoringEb"),
    ("RoutingSlot::SetAllowFailureTrees", 0x8014563c, 0x8014565c, "_ZN11RoutingSlot20SetAllowFailureTreesEb"),
    ("RoutingSlot::SetAllowDifferentAlts", 0x80145668, 0x80145688, "_ZN11RoutingSlot21SetAllowDifferentAltsEb"),
    ("RoutingSlot::SetUseAverageObjectLocation", 0x80145694, 0x801456b4, "_ZN11RoutingSlot27SetUseAverageObjectLocationEb"),
    ("RoutingSlot::SetResolution", 0x801456c0, 0x801456c8, "_ZN11RoutingSlot13SetResolutionEi"),
    ("RoutingSlot::IsOnTopOfObject", 0x801454c0, 0x801454d0, "_ZNK11RoutingSlot15IsOnTopOfObjectEv"),
    ("RoutingSlot::IsDirectionAllowed", 0x801454d0, 0x801454ec, "_ZNK11RoutingSlot18IsDirectionAllowedEi"),
    ("RoutingSlot::IsAnyRotationAllowed", 0x801454ec, 0x80145504, "_ZNK11RoutingSlot20IsAnyRotationAllowedEv"),
    ("RoutingSlot::IsAnyFacingAllowed", 0x80145504, 0x80145518, "_ZNK11RoutingSlot18IsAnyFacingAllowedEv"),
    ("RoutingSlot::IsFacingTowardsObject", 0x80145518, 0x8014552c, "_ZNK11RoutingSlot21IsFacingTowardsObjectEv"),
    ("RoutingSlot::IsFacingAwayFromObject", 0x8014552c, 0x80145540, "_ZNK11RoutingSlot22IsFacingAwayFromObjectEv"),
    ("RoutingSlot::GetFacingDirection", 0x80145540, 0x80145548, "_ZNK11RoutingSlot18GetFacingDirectionEv"),
    ("RoutingSlot::GetIgnoreRooms", 0x80145548, 0x80145560, "_ZNK11RoutingSlot14GetIgnoreRoomsEv"),
    ("RoutingSlot::GetMinDist", 0x80145580, 0x80145588, "_ZNK11RoutingSlot10GetMinDistEv"),
    ("RoutingSlot::GetMaxDist", 0x80145588, 0x80145590, "_ZNK11RoutingSlot10GetMaxDistEv"),
    ("RoutingSlot::GetOptimalDist", 0x80145590, 0x80145598, "_ZNK11RoutingSlot14GetOptimalDistEv"),
    ("RoutingSlot::GetResolution", 0x80145598, 0x801455a0, "_ZNK11RoutingSlot13GetResolutionEv"),
    ("RoutingSlot::GetGradient", 0x801455a0, 0x801455a8, "_ZNK11RoutingSlot11GetGradientEv"),
    ("RoutingSlot::GetMultiplier", 0x801455a8, 0x801455b8, "_ZNK11RoutingSlot13GetMultiplierENS_16VerticalPositionE"),
    ("RoutingSlot::GetSnapTargetSlot", 0x801455b8, 0x801455c0, "_ZNK11RoutingSlot17GetSnapTargetSlotEv"),
    ("RoutingSlot::SnapsToDirection", 0x801455c0, 0x801455d8, "_ZNK11RoutingSlot16SnapsToDirectionEv"),
    ("RoutingSlot::GetSnapDirection", 0x801455d8, 0x80145604, "_ZNK11RoutingSlot16GetSnapDirectionEv"),
    ("RoutingSlot::Absolute", 0x80145604, 0x80145610, "_ZNK11RoutingSlot8AbsoluteEv"),
    ("RoutingSlot::HasRandomScoring", 0x80145610, 0x8014561c, "_ZNK11RoutingSlot16HasRandomScoringEv"),
    ("RoutingSlot::GetAllowFailureTrees", 0x8014565c, 0x80145668, "_ZNK11RoutingSlot20GetAllowFailureTreesEv"),
    ("RoutingSlot::GetAllowDifferentAlts", 0x80145688, 0x80145694, "_ZNK11RoutingSlot21GetAllowDifferentAltsEv"),
    ("RoutingSlot::GetUseAverageObjectLocation", 0x801456b4, 0x801456c0, "_ZNK11RoutingSlot27GetUseAverageObjectLocationEv"),
    ("RoutingSlot::GetXOffset", 0x801456c8, 0x801456d0, "_ZNK11RoutingSlot10GetXOffsetEv"),
    ("RoutingSlot::GetYOffset", 0x801456d0, 0x801456d8, "_ZNK11RoutingSlot10GetYOffsetEv"),
    ("RoutingSlot::GetAltOffset", 0x801456d8, 0x801456e0, "_ZNK11RoutingSlot12GetAltOffsetEv"),
    ("ObjectSlot::GetHeight", 0x80145328, 0x80145330, "_ZN10ObjectSlot9GetHeightEv"),
    ("ObjectSlot::IsSurface", 0x80145330, 0x80145348, "_ZN10ObjectSlot9IsSurfaceEv"),
    ("ObjectSlot::IsFreePos", 0x80145348, 0x80145354, "_ZN10ObjectSlot9IsFreePosEv"),
    ("ObjectSlot::GetHeightMask", 0x80145354, 0x80145364, "_ZN10ObjectSlot13GetHeightMaskE9StdHeight"),
    ("SpriteSlot::GetTicksPerFrame", 0x80145364, 0x8014536c, "_ZN10SpriteSlot16GetTicksPerFrameEv"),
    ("SpriteSlot::UseBalloonSprite", 0x801453cc, 0x801453d4, "_ZN10SpriteSlot16UseBalloonSpriteEi"),
    ("SpriteSlot::UseOverlaySprite", 0x801453d4, 0x801453dc, "_ZN10SpriteSlot16UseOverlaySpriteEi"),
    ("SpriteSlot::SetOptions", 0x801453dc, 0x801453e4, "_ZN10SpriteSlot10SetOptionsEi"),
    ("SpriteSlot::SetPopSize", 0x801453e4, 0x801453ec, "_ZN10SpriteSlot10SetPopSizeEf"),
    ("SpriteSlot::GetSpriteID", 0x80145408, 0x80145410, "_ZNK10SpriteSlot11GetSpriteIDEv"),
    ("SpriteSlot::GetBalloonSpriteID", 0x80145410, 0x80145418, "_ZNK10SpriteSlot18GetBalloonSpriteIDEv"),
    ("SpriteSlot::GetOverlaySpriteID", 0x80145418, 0x80145420, "_ZNK10SpriteSlot18GetOverlaySpriteIDEv"),
    ("SpriteSlot::GetCurrentFrame", 0x80145420, 0x80145428, "_ZNK10SpriteSlot15GetCurrentFrameEv"),
    ("SpriteSlot::GetPPerson", 0x80145428, 0x80145430, "_ZN10SpriteSlot10GetPPersonEv"),
    ("SpriteSlot::SetPriority", 0x80145430, 0x80145438, "_ZN10SpriteSlot11SetPriorityEi"),
    ("SpriteSlot::GetPriority", 0x80145438, 0x80145440, "_ZNK10SpriteSlot11GetPriorityEv"),
    ("SpriteSlot::GetOptions", 0x80145440, 0x80145448, "_ZNK10SpriteSlot10GetOptionsEv"),
    ("SpriteSlot::GetIsSkillMeter", 0x80145448, 0x80145454, "_ZNK10SpriteSlot15GetIsSkillMeterEv"),
    ("SpriteSlot::GetShowOverInactivePeople", 0x80145454, 0x8014545c, "_ZNK10SpriteSlot25GetShowOverInactivePeopleEv"),
    ("SpriteSlot::SetShowOverInactivePeople", 0x8014545c, 0x80145464, "_ZN10SpriteSlot25SetShowOverInactivePeopleEb"),
    ("SpriteSlot::GetAltOffset", 0x80145464, 0x8014546c, "_ZNK10SpriteSlot12GetAltOffsetEv"),
    ("SpriteSlot::SetAltOffset", 0x8014546c, 0x80145474, "_ZN10SpriteSlot12SetAltOffsetEf"),
    ("SpriteSlot::GetSizeMultiplierX", 0x80145474, 0x8014547c, "_ZNK10SpriteSlot18GetSizeMultiplierXEv"),
    ("SpriteSlot::GetSizeMultiplierY", 0x8014547c, 0x80145484, "_ZNK10SpriteSlot18GetSizeMultiplierYEv"),
    ("SpriteSlot::GetAlpha", 0x80145484, 0x8014548c, "_ZNK10SpriteSlot8GetAlphaEv"),
    ("SpriteSlot::GetSelector", 0x801453ec, 0x80145408, "_ZNK10SpriteSlot11GetSelectorEv"),
    ("SpriteSlot::IsActive", 0x801453b4, 0x801453cc, "_ZNK10SpriteSlot8IsActiveEv"),
    ("SpriteSlot::ActivateForever", 0x8014536c, 0x80145390, "_ZN10SpriteSlot15ActivateForeverEv"),
    ("SpriteSlot::Deactivate", 0x80145390, 0x801453b4, "_ZN10SpriteSlot10DeactivateEv"),
    ("SpriteSlot::AlternateWithSprite", 0x801430bc, 0x801430d4, "_ZN10SpriteSlot19AlternateWithSpriteEii"),
    ("SlotLoader::SlotLoader", 0x80143814, 0x80143828, "_ZN10SlotLoaderC1Ej"),
    ("SlotLoader::Save", 0x801445c4, 0x801445cc, "_ZN10SlotLoader4SaveEsPvS0_S0_P8cXObject"),
    ("SlotLoader::GetSlotName", 0x801445cc, 0x801445d0, "_ZN10SlotLoader11GetSlotNameEP4SlotR7BStringi"),
    ("QuickData::SaveDataByID", 0x80145170, 0x80145178, "_ZN21QuickDataSlotDescList12SaveDataByIDER12ObjectDataID"),
    ("QuickData::GetDataSourceType", 0x80145178, 0x80145180, "_ZNK21QuickDataSlotDescList17GetDataSourceTypeEv"),
    ("QuickData::LoadOnlyNameAndID", 0x80145180, 0x80145188, "_ZN21QuickDataSlotDescList26LoadOnlyNameAndIDFromIndexEji"),
    ("QuickData::AddSlot", 0x8014512c, 0x80145134, "_ZN21QuickDataSlotDescList7AddSlotER14SlotDescriptor"),
    ("QuickData::RemoveSlot", 0x80145134, 0x8014513c, "_ZN21QuickDataSlotDescList10RemoveSlotEi"),
    ("QuickData::GetStringSetID", 0x80145164, 0x8014516c, "_ZNK21QuickDataSlotDescList14GetStringSetIDEv"),
    ("QuickData::SetStringSetID", 0x8014516c, 0x80145170, "_ZN21QuickDataSlotDescList14SetStringSetIDEi"),
    ("QuickData::GetSlot", 0x80145154, 0x80145164, "_ZN21QuickDataSlotDescList7GetSlotEi"),
    ("QuickData::AddRef", 0x801448f0, 0x80144904, "_ZN21QuickDataSlotDescList6AddRefEv"),
    ("QuickData::GetNumSlots", 0x8014513c, 0x80145154, "_ZN21QuickDataSlotDescList11GetNumSlotsEv"),
    ("IFF::GetDataSourceType", 0x801452b8, 0x801452c0, "_ZNK15IFFSlotDescList17GetDataSourceTypeEv"),
    ("IFF::GetStringSetID", 0x801452ac, 0x801452b4, "_ZNK15IFFSlotDescList14GetStringSetIDEv"),
    ("IFF::SetStringSetID", 0x801452b4, 0x801452b8, "_ZN15IFFSlotDescList14SetStringSetIDEi"),
    ("IFF::GetSlot", 0x8014529c, 0x801452ac, "_ZN15IFFSlotDescList7GetSlotEi"),
    ("IFF::AddRef", 0x80145014, 0x80145028, "_ZN15IFFSlotDescList6AddRefEv"),
    ("IFF::GetNumSlots", 0x8014527c, 0x8014529c, "_ZN15IFFSlotDescList11GetNumSlotsEv"),
]

matching = 0
non_matching = 0
total = len(funcs)

for name, start, stop, symbol in funcs:
    orig = disasm_elf(f'0x{start:08X}', f'0x{stop:08X}')
    comp = disasm_obj(symbol)

    if orig == comp:
        matching += 1
        print(f"OK {name}")
    else:
        non_matching += 1
        diff_info = ""
        for i, (o, c) in enumerate(zip(orig, comp)):
            if o != c:
                diff_info = f" @insn{i}: orig=[{o}] comp=[{c}]"
                break
        if len(orig) != len(comp):
            diff_info += f" (insns: orig={len(orig)} comp={len(comp)})"
        print(f"XX {name}{diff_info}")

print(f"\n=== {matching}/{total} MATCHING, {non_matching} differ ===")
