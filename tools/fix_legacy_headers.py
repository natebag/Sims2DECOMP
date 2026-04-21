#!/usr/bin/env python3
"""Batch-fix legacy header size-labels per DVD map.

Each entry is (relpath, from_size, to_size). Finds the first occurrence
of "(FROMSIZEb)" or "(FROMSIZEB)" in the first 3 lines and replaces with
"(TOSIZEB)". Skips files where we can't find the exact pattern.
"""
import re, sys, os

# (path, declared, map)
ENTRIES = [
    # SKIP 0x800251FC — real partial-fake, OpusWorker moves to version_diff
    ("src/matched/agent/match_0x80037A5C_EyeToyClient__ReleaseTexture.cpp", 60, 64),
    ("src/matched/agent/match_0x80037B40_EyeToyClient__ReleaseRenderSurface.cpp", 60, 64),
    ("src/matched/agent/match_0x8003DBE8_GameData__StageEnd.cpp", 28, 80),
    ("src/matched/agent/match_0x8003E00C_GameEffectsManager_GetSingleton.cpp", 52, 60),
    ("src/matched/agent/match_0x8007CEF0_CTGFileImpl_Read.cpp", 48, 56),
    ("src/matched/agent/match_0x80094DB0_InLevelCreateASimState_Reset.cpp", 56, 64),
    ("src/matched/agent/match_0x80095824_TheSimsStartScreenStateMachine_Shutdown.cpp", 76, 80),
    ("src/matched/agent/match_0x80097800_TheSimsMaxisLogoState_Shutdown.cpp", 80, 100),
    ("src/matched/agent/match_0x8009B258_UrbzModeNewGameState_Reset.cpp", 44, 48),
    ("src/matched/agent/match_0x8009C17C_op_eq_char_BString.cpp", 40, 60),
    ("src/matched/agent/match_0x8009C578_op_le_char_BString.cpp", 40, 48),
    ("src/matched/agent/match_0x8009C5A8_op_le_BString_charptr.cpp", 40, 48),
    ("src/matched/agent/match_0x8009C5D8_op_le_BString_char.cpp", 40, 48),
    ("src/matched/agent/match_0x8009FEE8_BString_op_not_equal.cpp", 40, 56),
    ("src/matched/agent/match_0x800A0290_op_eq_uwcharptr_BString2.cpp", 48, 56),
    ("src/matched/agent/match_0x800A02C8_op_eq_wchar_BString2.cpp", 48, 60),
    ("src/matched/agent/match_0x800A0694_op_le_uwcharptr_BString2.cpp", 40, 48),
    ("src/matched/agent/match_0x800A06C4_op_le_wchar_BString2.cpp", 40, 48),
    ("src/matched/agent/match_0x800A06F4_op_le_BString2_uwcharptr.cpp", 40, 48),
    ("src/matched/agent/match_0x800A0724_op_le_BString2_wchar.cpp", 40, 48),
    ("src/matched/agent/match_0x800A7E78_wcslen.cpp", 28, 40),
    ("src/matched/agent/match_0x800B479C_CTilePt__op_neq.cpp", 44, 48),
    ("src/matched/agent/match_0x800B4CDC_CTilePt__Get.cpp", 36, 40),
    ("src/matched/agent/match_0x800B62D0_FamilyImpl_TestMember_cXPerson.cpp", 80, 100),
    ("src/matched/agent/match_0x800B67D4_FamilyImpl_SetName.cpp", 56, 60),
    ("src/matched/agent/match_0x800B8C88_cIGZSndSys_CreateInstance.cpp", 44, 48),
    ("src/matched/agent/match_0x800CCCAC_NeighborhoodImpl_RelationshipsChanged.cpp", 80, 84),
    ("src/matched/agent/match_0x800CE55C_NeighborhoodImpl_GetNeighborSelector.cpp", 60, 72),
    ("src/matched/agent/match_0x800CEC04_NeighborhoodImpl_MakeNewFreePlayFamily.cpp", 80, 96),
    ("src/matched/agent/match_0x800F0884_ObjectFolderImpl_GetPlaceholder.cpp", 48, 60),
    ("src/matched/agent/match_0x80110754_ObjSelector_Writable.cpp", 40, 60),
    ("src/matched/agent/match_0x80134BF0_RelMatrixImpl_GetArraySize.cpp", 72, 84),
    ("src/matched/agent/match_0x8014AE08_WantFear_Bookmark_IsInStoryTree.cpp", 40, 52),
    ("src/matched/agent/match_0x8015AB2C_ObjectDataBehaviorTree_GetNumParams.cpp", 100, 104),
    ("src/matched/agent/match_0x8015ABA0_ObjectDataBehaviorTree_GetNumLocals.cpp", 108, 112),
    ("src/matched/agent/match_0x8017021C_CasSimRendererDynamic__IsShoeIdleAnim.cpp", 36, 40),
    ("src/matched/agent/match_0x801767F8_UI2D_Instance.cpp", 52, 60),
    ("src/matched/agent/match_0x80177038_UI3D_Instance.cpp", 52, 60),
    ("src/matched/agent/match_0x801779dc_UIAUDIO_Instance.cpp", 44, 60),
    ("src/matched/agent/match_0x80177A18_UIAUDIO_Shutdown.cpp", 72, 76),
    ("src/matched/agent/match_0x80178bf8_GetVariableCommandTable_Instance.cpp", 44, 60),
    ("src/matched/agent/match_0x80178C34_GetVariableCommandTable_Shutdown.cpp", 72, 76),
    ("src/matched/agent/match_0x80178c80_SetVariableCommandTable_Instance.cpp", 44, 60),
    ("src/matched/agent/match_0x80178CBC_SetVariableCommandTable_Shutdown.cpp", 72, 76),
    ("src/matched/agent/match_0x80178d08_GetLocalizableCommandTable_Instance.cpp", 44, 60),
    ("src/matched/agent/match_0x80178D44_GetLocalizableCommandTable_Shutdown.cpp", 72, 76),
    ("src/matched/agent/match_0x8017ab18_UIDrawTable_Instance.cpp", 44, 60),
    ("src/matched/agent/match_0x8017AB54_UIDrawTable_Shutdown.cpp", 72, 76),
    ("src/matched/agent/match_0x80181d4c_UIUpdateTable_Instance.cpp", 44, 60),
    ("src/matched/agent/match_0x80181D88_UIUpdateTable_Shutdown.cpp", 72, 76),
    ("src/matched/agent/match_0x80182284_UIUserDrawCBTable_Instance.cpp", 44, 60),
    ("src/matched/agent/match_0x801822C0_UIUserDrawCBTable_Shutdown.cpp", 72, 76),
    ("src/matched/agent/match_0x80186DD4_HUDTarget__IncPause.cpp", 36, 48),
    ("src/matched/agent/match_0x80186E04_HUDTarget__ReleasePause.cpp", 36, 48),
    ("src/matched/agent/match_0x80190224_RepTitleSupport_GetRepTableRawTitle.cpp", 40, 56),
    ("src/matched/agent/match_0x8019025C_RepTitleSupport_GetRepTableRawFriendTitle.cpp", 40, 56),
    ("src/matched/agent/match_0x80190294_RepTitleSupport_GetRepTableRawEnemyTitle.cpp", 40, 56),
    ("src/matched/agent/match_0x801AFCAC_FAMTarget__UnloadScreen.cpp", 40, 44),
    ("src/matched/agent/match_0x801BBBF0_INGTarget__get_current_ingredient.cpp", 36, 52),
    ("src/matched/agent/match_0x801F451C_INVTarget__SetOnMsgInvNextTab.cpp", 40, 52),
    ("src/matched/agent/match_0x80205B78_InteractorModule_DirectInteractor__StopInObjectMenu.cpp", 52, 56),
    ("src/matched/agent/match_0x802119C0_InteractorModule__GetPlumbBob.cpp", 40, 44),
    ("src/matched/agent/match_0x8021A044_InteractorModule_GrabManipulator__OnCreate.cpp", 44, 56),
    ("src/matched/agent/match_0x8021A188_InteractorModule_PlaceManipulator__OnCreate.cpp", 44, 56),
    ("src/matched/agent/match_0x8021E5D8_InteractorModule_SimInteractor__ResetInputState.cpp", 52, 56),
    ("src/matched/agent/match_0x8021F808_InteractorModule_WallManipulator__OnDestroy.cpp", 44, 52),
    ("src/matched/agent/match_0x80229618_EInstance_IsHidden.cpp", 48, 60),
    ("src/matched/agent/match_0x8023AA04_CDirtyXmlNode_getFirstChildNode.cpp", 48, 60),
    ("src/matched/agent/match_0x8032F92C_ENgcGraphics_AllocMovie.cpp", 16, 40),
    ("src/matched/apt/match_0x80010CF0_AptViewer__UnLoad.cpp", 64, 120),
    ("src/matched/bstring/match_0x8009C304_operator_lt_BString_BString.cpp", 40, 44),
    ("src/matched/casmediator/match_0x801620f4_CasMediator__GetNumBodyModels.cpp", 28, 52),
    ("src/matched/casmediator/match_0x80162128_CasMediator__GetNumTattooTextures.cpp", 28, 52),
    ("src/matched/casmediator/match_0x8016215c_CasMediator__GetIconTextureId.cpp", 28, 52),
    ("src/matched/casmediator/match_0x80162190_CasMediator__GetIconTattooTextureId.cpp", 28, 52),
    ("src/matched/casmediator/match_0x801621c4_CasMediator__GetIndexes_BodyPart.cpp", 28, 52),
    ("src/matched/casmediator/match_0x801621f8_CasMediator__GetIndexes_Tattoo.cpp", 28, 52),
    # SKIP 0x80238268 — real partial-fake, OpusWorker moves to version_diff
    # SKIP 0x8003919C EyeToyClient — already manually fixed to (24B) pre-batch
    ("src/matched/familyimpl/match_0x800B6334_FamilyImpl__GetMemberByGUID.cpp", 40, 52),
    ("src/matched/familyimpl/match_0x800B63A4_FamilyImpl__GetIndexedMember.cpp", 40, 52),
    ("src/matched/ifloor/match_0x80047E24_EIFloor__TestCreateFloors.cpp", 40, 48),
    ("src/matched/livemode/match_0x8008CD78_ChangeHouseSaveHouse_Reset.cpp", 12, 36),
    ("src/matched/object/match_0x800DCD70_cXObjectImpl__GetPrevObjectSibling.cpp", 64, 76),
    ("src/matched/objselector/match_0x801115e8_ObjSelector__GetTypeAttributes.cpp", 92, 96),
    ("src/matched/r2ltarget/match_0x801DCDB4_R2LTarget__OldGridIndexToRecordIndex.cpp", 44, 52),
    ("src/matched/r2ltarget/match_0x801DCE00_R2LTarget__ScrollRightEnabled.cpp", 36, 40),
    ("src/matched/sanimator2/match_0x80069920_SAnimator2__setFollowEnd.cpp", 108, 120),
    ("src/matched/simulator/match_0x80141324_cSimulatorImpl__IsPausedAtAll.cpp", 40, 44),
    ("src/matched/simulator/match_0x80141A8C_cSimulatorImpl__IsStopped.cpp", 40, 44),
    # SKIP 0x8024A9B0 — real partial-fake, OpusWorker moves to version_diff
    ("src/matched/versioninfo/match_0x802B62B8_dtor3_802B62B8.cpp", 62, 104),
    ("src/matched/versioninfo/match_0x802F1324_EGraphics__AllocDL.cpp", 20, 44),
]

def fix(path, from_sz, to_sz):
    if not os.path.exists(path):
        return "MISSING"
    with open(path, 'rb') as f:
        data = f.read()
    # Try match first ~400 bytes (header region)
    head = data[:400]
    # Variations: "(NNb)", "(NNB)", " NNb ", " NNB "
    patterns = [
        (f"({from_sz}B)".encode(), f"({to_sz}B)".encode()),
        (f"({from_sz}b)".encode(), f"({to_sz}B)".encode()),
        (f"({from_sz} bytes)".encode(), f"({to_sz} bytes)".encode()),
    ]
    for old, new in patterns:
        if old in head:
            new_data = data.replace(old, new, 1)
            with open(path, 'wb') as f:
                f.write(new_data)
            return f"OK {old.decode()} -> {new.decode()}"
    return f"NO_PATTERN (head starts with: {head[:60]!r})"

ok = 0
skip = 0
miss = 0
for path, frm, to in ENTRIES:
    result = fix(path, frm, to)
    if result.startswith("OK"):
        ok += 1
    elif result == "MISSING":
        miss += 1
        print(f"MISSING: {path}")
    else:
        skip += 1
        print(f"SKIP: {path} ({frm}->{to}): {result}")
print(f"\n{ok} fixed, {skip} skipped, {miss} missing out of {len(ENTRIES)} total")
