# asm-processor Queue File

**Generated:** S13 Lane D Thrust 1b

**Source:** `src/wip/version_diff/`

**Total files examined:** 201
**Stale (already matched elsewhere):** 0
**Truly open walls queued:** 201

## Cat 1 -- Scheduler-swap candidates (5)

Name pattern: instruction-reorder fingerprint, adjacent-independent-insn diff.

| Address | Symbol | Size | File path | Classifier reason |
|---------|--------|------|-----------|-------------------|
| 0x80140D28 | `0x80140D28_cSimulatorImpl_ComputeTimeOfDay` | 72B | `src/wip/version_diff/match_0x80140D28_cSimulatorImpl_ComputeTimeOfDay.cpp` | scheduler-swap / instruction-reorder fingerprint |
| 0x8022BB8C | `0x8022BB8C_EIStaticModel_GetBoundSphere` | ? | `src/wip/version_diff/match_0x8022BB8C_EIStaticModel__GetBoundSphere.cpp` | scheduler-swap / instruction-reorder fingerprint |
| 0x8022E67C | `0x8022E67C_EIStaticSubModel_GetBoundSphere` | ? | `src/wip/version_diff/match_0x8022E67C_EIStaticSubModel__GetBoundSphere.cpp` | scheduler-swap / instruction-reorder fingerprint |
| 0x8027AB3C | `AptActionInterpreter::_FunctionAptActionStackSwap` | 112B | `src/wip/version_diff/wip_0x8027AB3C_StackSwap_permuter.cpp` | scheduler-swap / instruction-reorder fingerprint |
| 0x80364F64 | `0x80364F64_ETexture_ctor` | ? | `src/wip/version_diff/match_0x80364F64_ETexture__ctor.cpp` | scheduler-swap / instruction-reorder fingerprint |

## Cat 2 -- Register-coloring / FP-alternation (18)

Name pattern: fp_relabel / gpr_relabel candidate.

| Address | Symbol | Size | File path | Classifier reason |
|---------|--------|------|-----------|-------------------|
| 0x8003461C | `0x8003461C_ESim_CompositeSkin` | ? | `src/wip/version_diff/match_0x8003461C_ESim__CompositeSkin.cpp` | register-coloring / FP-alternation candidate |
| 0x8004AFA8 | `0x8004AFA8_InventoryItems_GetNewItemIndex` | ? | `src/wip/version_diff/match_0x8004AFA8_InventoryItems_GetNewItemIndex.cpp` | register-coloring / FP-alternation candidate |
| 0x8004AFA8 | `0x8004AFA8_BBI_InventoryItems_GetNewItemIndex` | 68B | `src/wip/version_diff/wip_match_0x8004AFA8_BBI__InventoryItems__GetNewItemIndex.cpp` | register-coloring / FP-alternation candidate |
| 0x8007AD28 | `0x8007AD28_CopyCharStrToWString` | ? | `src/wip/version_diff/match_0x8007AD28_CopyCharStrToWString.cpp` | register-coloring / FP-alternation candidate |
| 0x800CDD40 | `0x800CDD40_NeighborhoodImpl_FindNeighborByID` | ? | `src/wip/version_diff/match_0x800CDD40_NeighborhoodImpl_FindNeighborByID.cpp` | register-coloring / FP-alternation candidate |
| 0x800CDD40 | `NeighborhoodImpl::FindNeighborByID` | 56B | `src/wip/version_diff/wip_match_0x800CDD40_NeighborhoodImpl__FindNeighborByID.cpp` | register-coloring / FP-alternation candidate |
| 0x800CDEE0 | `0x800CDEE0_NeighborhoodImpl_FindNeighborByType` | ? | `src/wip/version_diff/match_0x800CDEE0_NeighborhoodImpl_FindNeighborByType.cpp` | register-coloring / FP-alternation candidate |
| 0x800D8A84 | `0x800D8A84_NghResFile_SwapFourByteNumber` | 36B | `src/wip/version_diff/match_0x800D8A84_NghResFile__SwapFourByteNumber.cpp` | register-coloring / FP-alternation candidate |
| 0x800DCACC | `0x800DCACC_cXObjectImpl_GetPlacementInfo` | 132B | `src/wip/version_diff/match_0x800DCACC_cXObjectImpl__GetPlacementInfo.cpp` | register-coloring / FP-alternation candidate |
| 0x801069B4 | `0x801069B4_cXObjectImpl_InventoryCommandParam_GetGuid` | ? | `src/wip/version_diff/match_0x801069B4_cXObjectImpl__InventoryCommandParam_GetGuid.cpp` | register-coloring / FP-alternation candidate |
| 0x80106A28 | `0x80106A28_cXObjectImpl_InventoryCommandParam_GetCount` | 100B | `src/wip/version_diff/match_0x80106A28_cXObjectImpl__InventoryCommandParam_GetCount.cpp` | register-coloring / FP-alternation candidate |
| 0x8012B5A0 | `0x8012B5A0_cXPersonImpl_InvalidateRoutes` | 52B | `src/wip/version_diff/match_0x8012B5A0_cXPersonImpl__InvalidateRoutes.cpp` | register-coloring / FP-alternation candidate |
| 0x8012B5A0 | `0x8012B5A0_cXPersonImpl_InvalidateRoutes_void_` | 52B | `src/wip/version_diff/match_0x8012B5A0_cXPersonImpl__InvalidateRoutes_void_.cpp` | register-coloring / FP-alternation candidate |
| 0x8012B5A0 | `0x8012B5A0_cXPersonImpl_InvalidateRoutes` | 52B | `src/wip/version_diff/wip_match_0x8012B5A0_cXPersonImpl__InvalidateRoutes.cpp` | register-coloring / FP-alternation candidate |
| 0x802093AC | `InteractorModule::Interactor::ResetInputState` | 68B | `src/wip/version_diff/match_0x802093AC_Interactor_ResetInputState.cpp` | register-coloring / FP-alternation candidate |
| 0x8021AAB8 | `0x8021AAB8_PlacementObject_ctor` | 56B | `src/wip/version_diff/match_0x8021AAB8_PlacementObject__ctor.cpp` | register-coloring / FP-alternation candidate |
| 0x80346124 | `0x80346124_ENgcRenderer_SetBlendMode` | 56B | `src/wip/version_diff/match_0x80346124_ENgcRenderer__SetBlendMode.cpp` | register-coloring / FP-alternation candidate |
| N/A | `8015E028_TreeTableQuickData_Load` | ? | `src/wip/version_diff/match_8015E028_TreeTableQuickData__Load.cpp` | register-coloring / FP-alternation candidate |

## Cat 3 -- RTL/CFG/structural (25)

Escalation-only, NOT for batch run.

| Address | Symbol | Size | File path | Classifier reason |
|---------|--------|------|-----------|-------------------|
| 0x800169E8 | `0x800169E8_ESimsCam_SetFov` | 52B | `src/wip/version_diff/match_0x800169E8_ESimsCam__SetFov.cpp` | RTL/CFG/structural wall |
| 0x80016A8C | `0x80016A8C_ESimsCam_Init` | 44B | `src/wip/version_diff/match_0x80016A8C_ESimsCam__Init.cpp` | RTL/CFG/structural wall |
| 0x80016A8C | `ESimsCam::Init` | 44B | `src/wip/version_diff/wip_match_0x80016A8C_ESimsCam__Init.cpp` | RTL/CFG/structural wall |
| 0x8001A074 | `0x8001A074_ESimsCam_GetCursorLimitDepth` | 56B | `src/wip/version_diff/match_0x8001A074_ESimsCam__GetCursorLimitDepth.cpp` | RTL/CFG/structural wall |
| 0x800251FC | `LightLocation` | 20B | `src/wip/version_diff/wip_0x800251FC_LightLocation_2.cpp` | RTL/CFG/structural wall |
| 0x800C7D14 | `0x800C7D14_cXMTObjectImpl_GetFirstMultiTileObject` | 48B | `src/wip/version_diff/match_0x800C7D14_cXMTObjectImpl__GetFirstMultiTileObject.cpp` | RTL/CFG/structural wall |
| 0x800C7D14 | `cXMTObjectImpl::GetFirstMultiTileObject` | 48B | `src/wip/version_diff/wip_match_0x800C7D14_cXMTObjectImpl__GetFirstMultiTileObject.cpp` | RTL/CFG/structural wall |
| 0x801056EC | `0x801056EC_cXObjectImpl_KillSelf` | 148B | `src/wip/version_diff/match_0x801056EC_cXObjectImpl__KillSelf.cpp` | RTL/CFG/structural wall |
| 0x801D1AD0 | `IsSkillCatalogRating` | 44B | `src/wip/version_diff/wip_match_0x801D1AD0_IsSkillCatalogRating.cpp` | RTL/CFG/structural wall |
| 0x802096F8 | `0x802096F8_InteractorModule_InteractorInputManager_InstanceData_InstanceData` | 52B | `src/wip/version_diff/wip_match_0x802096F8_InteractorModule__InteractorInputManager__InstanceData__InstanceData.cpp` | RTL/CFG/structural wall |
| 0x8020BDBC | `0x8020BDBC_IM_InteractorManager_IsValidPlayerId` | 56B | `src/wip/version_diff/match_0x8020BDBC_IM__InteractorManager__IsValidPlayerId.cpp` | RTL/CFG/structural wall |
| 0x8020BDBC | `0x8020BDBC_InteractorManager_IsValidPlayerId` | ? | `src/wip/version_diff/match_0x8020BDBC_InteractorManager_IsValidPlayerId.cpp` | RTL/CFG/structural wall |
| 0x8020BDBC | `0x8020BDBC_InteractorManager_IsValidPlayerId` | 56B | `src/wip/version_diff/match_0x8020BDBC_InteractorManager__IsValidPlayerId.cpp` | RTL/CFG/structural wall |
| 0x8020BDBC | `InteractorModule::InteractorManager::IsValidPlayerId` | 56B | `src/wip/version_diff/match_0x8020bdbc_InteractorModule_InteractorManager__IsValidPlayerId.cpp` | RTL/CFG/structural wall |
| 0x8020BDBC | `0x8020BDBC_IsValidPlayerId` | ? | `src/wip/version_diff/vd_0x8020BDBC_IsValidPlayerId.cpp` | RTL/CFG/structural wall |
| 0x8020BDBC | `InteractorModule::InteractorManager::IsValidPlayerId` | 56B | `src/wip/version_diff/wip_match_0x8020BDBC_InteractorModule__InteractorManager__IsValidPlayerId.cpp` | RTL/CFG/structural wall |
| 0x80213700 | `InteractorModule::IsCameraDirectorInControl` | 76B | `src/wip/version_diff/wip_match_0x80213700_InteractorModule__IsCameraDirectorInControl.cpp` | RTL/CFG/structural wall |
| 0x8021AAB8 | `InteractorModule::PlacementObject::PlacementObject` | 56B | `src/wip/version_diff/wip_match_0x8021AAB8_InteractorModule__PlacementObject__PlacementObject.cpp` | RTL/CFG/structural wall |
| 0x8021BE8C | `0x8021BE8C_PlacementObject_IsLegalToPlaceAtLocation` | 88B | `src/wip/version_diff/wip_match_0x8021BE8C_PlacementObject__IsLegalToPlaceAtLocation.cpp` | RTL/CFG/structural wall |
| 0x8021E8A8 | `0x8021E8A8_SimInteractor_GetSelectionRadius` | 64B | `src/wip/version_diff/wip_match_0x8021E8A8_SimInteractor__GetSelectionRadius.cpp` | RTL/CFG/structural wall |
| 0x80238268 | `ERLevel::SetIdMapTableSize` | 8B | `src/wip/version_diff/wip_0x80238268_ERLevel__SetIdMapTableSize.cpp` | RTL/CFG/structural wall |
| 0x8024A9B0 | `match_0x8024A9B0_TArray_EVec3__op_assign` | 9B | `src/wip/version_diff/wip_0x8024A9B0_TArray_EVec3__op_assign.cpp` | RTL/CFG/structural wall |
| 0x8033B6EC | `0x8033B6EC_ENgcRenderer_dtor` | 52B | `src/wip/version_diff/wip_match_0x8033B6EC_ENgcRenderer__dtor.cpp` | RTL/CFG/structural wall |
| N/A | `800169E8_ESimsCam_SetFov` | ? | `src/wip/version_diff/match_800169E8_ESimsCam_SetFov.cpp` | RTL/CFG/structural wall |
| N/A | `800169E8_ESimsCam_SetFov_2` | ? | `src/wip/version_diff/match_800169E8_ESimsCam_SetFov_2.cpp` | RTL/CFG/structural wall |

## Appendix -- Needs OpusReviewGuy (153)

Walls that do not classify cleanly.

| Address | Symbol | Size | File path | Classifier reason |
|---------|--------|------|-----------|-------------------|
| 0x80003468 | `0x80003468_init_hardware` | ? | `src/wip/version_diff/match_0x80003468___init_hardware.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80003468 | `0x80003468_init_hardware_2` | ? | `src/wip/version_diff/match_0x80003468___init_hardware_2.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8000DFA8 | `0x8000DFA8_AptLine_UnlinkWord_VERSION_DIFF` | 80B | `src/wip/version_diff/match_0x8000DFA8_AptLine__UnlinkWord_VERSION_DIFF.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x800131C4 | `0x800131C4_AptLine_UnlinkWord` | ? | `src/wip/version_diff/match_0x800131C4_AptLine__UnlinkWord.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80014028 | `0x80014028_AwarenessManager_GetPlayerObject` | ? | `src/wip/version_diff/match_0x80014028_AwarenessManager_GetPlayerObject.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80016A1C | `0x80016A1C_ESimsCam_ForceFullScreenViewport` | ? | `src/wip/version_diff/match_0x80016A1C_ESimsCam_ForceFullScreenViewport.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x800210E4 | `0x800210E4_ECheatLookup_ECheatLookup` | 64B | `src/wip/version_diff/match_0x800210E4_ECheatLookup__ECheatLookup.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x800251FC | `LightLocation` | 20B | `src/wip/version_diff/match_0x800251FC_LightLocation_2.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x800304D0 | `0x800304D0_EIWallPart_Construct` | ? | `src/wip/version_diff/match_0x800304D0_EIWallPart__Construct.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x800342CC | `0x800342CC_ESim_SetAnim` | ? | `src/wip/version_diff/match_0x800342CC_ESim__SetAnim.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x800391B4 | `0x800391B4_EyeToyClient_IsSlotOpenForCASImage` | 40B | `src/wip/version_diff/match_0x800391B4_EyeToyClient__IsSlotOpenForCASImage.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8003DDA8 | `0x8003DDA8_GameData_SetBuildBuyPlayer` | ? | `src/wip/version_diff/match_0x8003DDA8_GameData__SetBuildBuyPlayer.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80045520 | `EFloorShdTblNode::EFloorShdTblNode` | 1B | `src/wip/version_diff/match_0x80045520_EFloorShdTblNode_ctor.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80048570 | `ObjectList::ObjectList` | 32B | `src/wip/version_diff/match_0x80048570_ObjectList__ctor.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8004A2E0 | `BBI::InventoryItem::CopyTo` | 60B | `src/wip/version_diff/match_0x8004A2E0_BBI_InventoryItem__CopyTo.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8004B078 | `0x8004B078_BBI_InventoryItems_CreateNewItemFromGuid` | 80B | `src/wip/version_diff/match_0x8004B078_BBI_InventoryItems_CreateNewItemFromGuid.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8004B598 | `0x8004B598_less_int16_t` | ? | `src/wip/version_diff/match_0x8004B598_less_int16_t.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80058F8C | `0x80058F8C_Physics_Physics` | ? | `src/wip/version_diff/match_0x80058F8C_Physics__Physics.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x800596E0 | `0x800596E0_static_initialization_and_destruction_0_player` | ? | `src/wip/version_diff/match_0x800596E0___static_initialization_and_destruction_0_player.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8005BDA4 | `0x8005BDA4_IsUsingDirectControlInteractor` | 100B | `src/wip/version_diff/match_0x8005BDA4_IsUsingDirectControlInteractor.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8006CA38 | `0x8006CA38_ScrollingTextBox_SetPosition` | ? | `src/wip/version_diff/match_0x8006CA38_ScrollingTextBox_SetPosition.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80089A14 | `EGameStateMan::EGameStateMan` | 40B | `src/wip/version_diff/match_0x80089A14_EGameStateMan_ctor.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80090F7C | `0x80090F7C_LoadingScreenStateMachine_IsFadingIn` | ? | `src/wip/version_diff/match_0x80090F7C_LoadingScreenStateMachine_IsFadingIn.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80090F7C | `0x80090F7C_LoadingScreenStateMachine_IsFadingIn` | 40B | `src/wip/version_diff/match_0x80090F7C_LoadingScreenStateMachine__IsFadingIn.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80095D38 | `0x80095D38_StateMachine_DrawTopmost` | ? | `src/wip/version_diff/match_0x80095D38_StateMachine__DrawTopmost.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x800961BC | `0x800961BC_StateMachine_FindStateById` | ? | `src/wip/version_diff/match_0x800961BC_StateMachine_FindStateById.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x800961BC | `0x800961BC_StateMachine_FindStateById` | ? | `src/wip/version_diff/match_0x800961BC_StateMachine__FindStateById.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80096628 | `0x80096628_StateMachineManager_FindMachineById` | ? | `src/wip/version_diff/match_0x80096628_StateMachineManager__FindMachineById.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80096668 | `0x80096668_StateMachineManager_FindMachine` | ? | `src/wip/version_diff/match_0x80096668_StateMachineManager__FindMachine.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x800966A4 | `0x800966A4_StateMachineManager_Startup` | ? | `src/wip/version_diff/match_0x800966A4_StateMachineManager__Startup.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8009B924 | `0x8009B924_BitArray64_operator_and_eq` | 40B | `src/wip/version_diff/match_0x8009B924_BitArray64__operator_and_eq.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8009B94C | `0x8009B94C_BitArray64_operator_xor_eq` | 40B | `src/wip/version_diff/match_0x8009B94C_BitArray64__operator_xor_eq.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x800A76AC | `QuickStringSet::GetString` | 80B | `src/wip/version_diff/match_0x800A76AC_QuickStringSet_GetString.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x800A76FC | `0x800A76FC_QuickStringSet_GetLocString` | ? | `src/wip/version_diff/match_0x800A76FC_QuickStringSet__GetLocString.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x800A7EA0 | `0x800A7EA0_wcscmp` | ? | `src/wip/version_diff/match_0x800A7EA0_wcscmp.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x800AA9BC | `0x800AA9BC_AmbientSoundPlayer_IsFinished` | ? | `src/wip/version_diff/match_0x800AA9BC_AmbientSoundPlayer__IsFinished.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x800AAA40 | `castSkillToString` | 68B | `src/wip/version_diff/match_0x800AAA40_castSkillToString.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x800B0320 | `cSoundModeManager::cSoundModeManager` | 1B | `src/wip/version_diff/match_0x800B0320_cSoundModeManager_ctor.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x800B4214 | `Commander::Commander` | 60B | `src/wip/version_diff/match_0x800B4214_Commander_ctor.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x800B86D8 | `0x800B86D8_GoalUnlock_GetObjectIndexFromGuid` | ? | `src/wip/version_diff/match_0x800B86D8_GoalUnlock_GetObjectIndexFromGuid.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x800B87CC | `GoalUnlock_IsUnlocked` | 180B | `src/wip/version_diff/0x800B87CC_GoalUnlock_IsUnlocked.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x800B8A6C | `0x800B8A6C_GoalUnlock_IsRecentlyUnlocked` | ? | `src/wip/version_diff/match_0x800B8A6C_GoalUnlock_IsRecentlyUnlocked.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x800BC00C | `0x800BC00C_HouseImpl_IsResident` | 212B | `src/wip/version_diff/match_0x800BC00C_HouseImpl_IsResident.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x800EF9E8 | `0x800EF9E8_ObjectFolderImpl_CreateNewUserSelector` | 76B | `src/wip/version_diff/match_0x800EF9E8_ObjectFolderImpl_CreateNewUserSelector.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x800EFD20 | `0x800EFD20_ObjectFolderImpl_CreatingInstance` | ? | `src/wip/version_diff/match_0x800EFD20_ObjectFolderImpl__CreatingInstance.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x800F9620 | `0x800F9620_ObjectModuleImpl_GetObjectFromID` | ? | `src/wip/version_diff/match_0x800F9620_ObjectModuleImpl_GetObjectFromID.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x800F9620 | `ObjectModuleImpl::GetObjectFromID` | 72B | `src/wip/version_diff/match_0x800F9620_ObjectModuleImpl__GetObjectFromID.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x800F97CC | `0x800F97CC_ObjectModuleImpl_GetObject` | ? | `src/wip/version_diff/match_0x800F97CC_ObjectModuleImpl_GetObject.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x800F97CC | `ObjectModuleImpl::GetObject` | 84B | `src/wip/version_diff/match_0x800F97CC_ObjectModuleImpl__GetObject.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80108384 | `0x80108384_cXObjectImpl_TryParticleEffect` | ? | `src/wip/version_diff/match_0x80108384_cXObjectImpl__TryParticleEffect.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80109264 | `0x80109264_cXObjectImpl_TryChangeWantFearTree` | 256B | `src/wip/version_diff/match_0x80109264_cXObjectImpl__TryChangeWantFearTree.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x801104B4 | `0x801104B4_ObjSelector_sub` | ? | `src/wip/version_diff/match_0x801104B4_ObjSelector_sub.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x801107DC | `ObjSelector::GetEffectiveTreeTableID` | 76B | `src/wip/version_diff/match_0x801107dc_ObjSelector__GetEffectiveTreeTableID.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80113174 | `0x80113174_InteractionList_remove` | ? | `src/wip/version_diff/match_0x80113174_InteractionList_remove.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80119088 | `cSampleChannel::cSampleChannel` | 60B | `src/wip/version_diff/match_0x80119088_cSampleChannel_ctor.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x801190C4 | `0x801190C4_cSampleChannel_dtor` | 76B | `src/wip/version_diff/match_0x801190C4_cSampleChannel_dtor.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80123704 | `0x80123704_cXPersonImpl_GetCurrentRoute` | ? | `src/wip/version_diff/match_0x80123704_cXPersonImpl_GetCurrentRoute.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80123704 | `0x80123704_cXPersonImpl_GetCurrentRoute_void_` | 56B | `src/wip/version_diff/match_0x80123704_cXPersonImpl__GetCurrentRoute_void_.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80129804 | `0x80129804_cXPersonImpl_AttachToHUD` | ? | `src/wip/version_diff/match_0x80129804_cXPersonImpl__AttachToHUD.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80129804 | `0x80129804_cXPersonImpl_AttachToHUD_2` | ? | `src/wip/version_diff/match_0x80129804_cXPersonImpl__AttachToHUD_2.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80132C60 | `0x80132C60_QuickResFile_GetString` | 188B | `src/wip/version_diff/match_0x80132C60_QuickResFile__GetString.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80146680 | `TileWalls::DirToWallSeg` | 84B | `src/wip/version_diff/match_0x80146680_TileWalls__DirToWallSeg.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80147A34 | `0x80147A34_TreeSimImpl_Reset` | 108B | `src/wip/version_diff/match_0x80147A34_TreeSimImpl__Reset.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8015A7CC | `0x8015A7CC_QuickDataBehaviorConstants_GetValue` | ? | `src/wip/version_diff/match_0x8015A7CC_QuickDataBehaviorConstants_GetValue.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8015E900 | `0x8015E900_TreeTableQuickData_CountEntries` | 44B | `src/wip/version_diff/match_0x8015E900_TreeTableQuickData_CountEntries.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8015EEB0 | `CasClothingUnlocks::IsLocked` | 108B | `src/wip/version_diff/match_0x8015EEB0_CasClothingUnlocks__IsLocked_BodyPart.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x801617FC | `CasGenetics_GetGrandparent` | 68B | `src/wip/version_diff/0x801617FC_CasGenetics_GetGrandparent.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x801773D4 | `0x801773D4_UIAUDIO_InstallEntry` | 168B | `src/wip/version_diff/match_0x801773D4_UIAUDIO__InstallEntry.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8017A860 | `0x8017A860_UIDrawTable_RemoveRecord` | ? | `src/wip/version_diff/match_0x8017A860_UIDrawTable_RemoveRecord.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8017EA1C | `0x8017EA1C_UIReflow_Reflow_Id` | 148B | `src/wip/version_diff/match_0x8017EA1C_UIReflow__Reflow_Id.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80184CDC | `0x80184CDC_ActionQueueHUD_SelectPriorAction` | ? | `src/wip/version_diff/match_0x80184CDC_ActionQueueHUD_SelectPriorAction.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80184E50 | `ActionQueueHUD::SelectAction` | 60B | `src/wip/version_diff/match_0x80184E50_ActionQueueHUD_SelectAction.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80185758 | `0x80185758_ActionQueueHUD_CatchUpPendingActions` | ? | `src/wip/version_diff/match_0x80185758_ActionQueueHUD_CatchUpPendingActions.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x801857B8 | `0x801857B8_ActionQueueHUD_RunActionQueue` | ? | `src/wip/version_diff/match_0x801857B8_ActionQueueHUD_RunActionQueue.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80190DF4 | `InteractionHelper::GetNext` | 24B | `src/wip/version_diff/match_0x80190df4_InteractionHelper__GetNext.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8019314C | `0x8019314C_CASTarget_GetLotNumberFromMode` | 40B | `src/wip/version_diff/match_0x8019314C_CASTarget_GetLotNumberFromMode.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x801B8BA4 | `0x801B8BA4_H2DTarget_SelectedPersonChanged` | 152B | `src/wip/version_diff/match_0x801B8BA4_H2DTarget_SelectedPersonChanged.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x801C10C8 | `0x801C10C8_M2MTarget_OnGetNumItems` | 64B | `src/wip/version_diff/match_0x801C10C8_M2MTarget__OnGetNumItems.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x801D1AD0 | `0x801D1AD0_IsSkillCatalogRating` | 44B | `src/wip/version_diff/match_0x801D1AD0_IsSkillCatalogRating.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80203D30 | `0x80203D30_INVTarget_GetSelectedShoppingCategory` | 56B | `src/wip/version_diff/match_0x80203D30_INVTarget_GetSelectedShoppingCategory.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80203D70 | `0x80203D70_DirectInteractor_ctor` | ? | `src/wip/version_diff/vd_0x80203D70_DirectInteractor_ctor.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8020415C | `DirectInteractor::ParseControls` | 112B | `src/wip/version_diff/match_0x8020415C_DirectInteractor__ParseControls.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x802091BC | `0x802091BC_InteractorModule_Interactor_Interactor` | ? | `src/wip/version_diff/match_0x802091BC_InteractorModule_Interactor_Interactor.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x802091BC | `0x802091BC_InteractorModule_Interactor_Interactor_2` | ? | `src/wip/version_diff/match_0x802091BC_InteractorModule_Interactor_Interactor_2.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80209354 | `0x80209354_Interactor_OnCommandUpdate` | ? | `src/wip/version_diff/vd_0x80209354_Interactor_OnCommandUpdate.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x802096F8 | `0x802096F8_InstanceData_ctor` | 52B | `src/wip/version_diff/match_0x802096F8_InstanceData_ctor.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80213700 | `InteractorModule::IsCameraDirectorInControl` | 76B | `src/wip/version_diff/match_0x80213700_InteractorModule_IsCameraDirectorInControl.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8021374C | `0x8021374C_SetCameraFilter` | ? | `src/wip/version_diff/vd_0x8021374C_SetCameraFilter.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8021E8A8 | `InteractorModule::SimInteractor::GetSelectionRadius` | 64B | `src/wip/version_diff/match_0x8021e8a8_InteractorModule_SimInteractor__GetSelectionRadius.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x802384B0 | `0x802384B0_cSoundPlayer_Register` | ? | `src/wip/version_diff/match_0x802384B0_cSoundPlayer__Register.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8023850C | `0x8023850C_cSoundPlayer_SetGameMode` | ? | `src/wip/version_diff/match_0x8023850C_cSoundPlayer__SetGameMode.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8023A504 | `0x8023A504_CDirtyXml_createNode` | ? | `src/wip/version_diff/match_0x8023A504_CDirtyXml__createNode.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8023A72C | `_Parse` | 116B | `src/wip/version_diff/match_0x8023A72C__Parse.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8023AB24 | `0x8023AB24_CDirtyXmlNode_nodeName` | ? | `src/wip/version_diff/match_0x8023AB24_CDirtyXmlNode__nodeName.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8023AB88 | `0x8023AB88_CDirtyXmlNode_nodeValue` | ? | `src/wip/version_diff/match_0x8023AB88_CDirtyXmlNode__nodeValue.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8023EE40 | `0x8023EE40_PCinit` | 8B | `src/wip/version_diff/match_0x8023EE40_PCinit.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8023EE48 | `PCcreat` | 4B | `src/wip/version_diff/match_0x8023EE48_PCcreat.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8023EE50 | `PCopen` | 4B | `src/wip/version_diff/match_0x8023EE50_PCopen.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8023EFF4 | `0x8023EFF4_SNInitInterrupts` | ? | `src/wip/version_diff/match_0x8023EFF4_SNInitInterrupts.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80249640 | `0x80249640_exit` | 8B | `src/wip/version_diff/match_0x80249640__exit.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8024A9B0 | `match_0x8024A9B0_TArray_EVec3__op_assign` | 9B | `src/wip/version_diff/match_0x8024A9B0_TArray_EVec3__op_assign.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8024AE30 | `0x8024AE30_PPCMfmsr` | 8B | `src/wip/version_diff/match_0x8024AE30_PPCMfmsr.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8024DFA0 | `0x8024DFA0_OSVReport` | ? | `src/wip/version_diff/match_0x8024DFA0_OSVReport.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80251808 | `0x80251808_OSGetResetSwitchState` | ? | `src/wip/version_diff/match_0x80251808_OSGetResetSwitchState.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8029B450 | `0x8029B450_AptDisplayList_deallocAssetStringRecursive` | 152B | `src/wip/version_diff/match_0x8029B450_AptDisplayList__deallocAssetStringRecursive.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x802AB5CC | `0x802AB5CC_AptRenderingContext_appendVertexMatrix` | ? | `src/wip/version_diff/match_0x802AB5CC_AptRenderingContext__appendVertexMatrix.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x802AB5CC | `0x802AB5CC_AptRenderingContext_appendVertexMatrix_2` | ? | `src/wip/version_diff/match_0x802AB5CC_AptRenderingContext__appendVertexMatrix_2.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x802BBC7C | `AptFloat::AptFloat` | 80B | `src/wip/version_diff/match_0x802BBC7C_AptFloat_AptFloat.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x802C6048 | `EFile::EFile` | ? | `src/wip/version_diff/match_0x802C6048_EFile_ctor.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x802CA720 | `EMat4::ExtractAxisRotation` | 64B | `src/wip/version_diff/match_0x802CA720_EMat4_ExtractAxisRotation.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x802D803C | `ENgcSNFile::Seek` | 68B | `src/wip/version_diff/match_0x802D803C_ENgcSNFile_Seek.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x802EFD44 | `0x802EFD44_EAnimController_SetTrackSpeed` | ? | `src/wip/version_diff/match_0x802EFD44_EAnimController__SetTrackSpeed.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x802F24A4 | `EMirrorPortal::GetCorner` | 40B | `src/wip/version_diff/match_0x802F24A4_EMirrorPortal_GetCorner.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8030C71C | `0x8030C71C_Add1Byte` | ? | `src/wip/version_diff/match_0x8030C71C_Add1Byte.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80311DC8 | `0x80311DC8_EResource_EResource` | 48B | `src/wip/version_diff/match_0x80311DC8_EResource__EResource.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8031811C | `0x8031811C_ERModel_DelRefSubResources` | 100B | `src/wip/version_diff/match_0x8031811C_ERModel__DelRefSubResources.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80318950 | `0x80318950_ERModel_DrawGeometry` | 108B | `src/wip/version_diff/match_0x80318950_ERModel__DrawGeometry.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8031A7FC | `0x8031A7FC_ERModel_GetAttachmentID` | 80B | `src/wip/version_diff/match_0x8031A7FC_ERModel__GetAttachmentID.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80328130 | `0x80328130_static_init` | 84B | `src/wip/version_diff/match_0x80328130_static_init.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80328CE4 | `0x80328CE4_EyeToyManager_GetPhysicalConnectionCount` | ? | `src/wip/version_diff/match_0x80328CE4_EyeToyManager__GetPhysicalConnectionCount.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8032B898 | `0x8032B898_EPMDesc_EPMDesc` | ? | `src/wip/version_diff/match_0x8032B898_EPMDesc__EPMDesc.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x80345120 | `0x80345120_ENgcRenderer_Material` | ? | `src/wip/version_diff/match_0x80345120_ENgcRenderer__Material.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x8035AD78 | `0x8035AD78_fake_InteractorManager_Update_WRONG_ADDR` | 84B | `src/wip/version_diff/wip_match_0x8035AD78_fake_InteractorManager__Update_WRONG_ADDR.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x803A29F0 | `0x803A29F0_Rb_tree_int_pair_M_erase` | ? | `src/wip/version_diff/match_0x803A29F0_Rb_tree_int_pair_M_erase.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x803AD714 | `ReconLoadVector_SlotDescriptor` | 52B | `src/wip/version_diff/match_0x803AD714_ReconLoadVector_SlotDescriptor.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x803AD7B4 | `ReconSaveVector_SlotDescriptor` | 52B | `src/wip/version_diff/match_0x803AD7B4_ReconSaveVector_SlotDescriptor.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x803C4694 | `0x803C4694_TArray_ENDummy_Destruct` | ? | `src/wip/version_diff/match_0x803C4694_TArray_ENDummy_Destruct.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| 0x803CA284 | `0x803CA284_TArray_SndEvtHitPatch_Copy` | ? | `src/wip/version_diff/match_0x803CA284_TArray_SndEvtHitPatch_Copy.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| N/A | `CheatMenuParams::CheatMenuParams` | 24B | `src/wip/version_diff/CheatMenuParams.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| N/A | `GoalUnlock` | ? | `src/wip/version_diff/GoalUnlock.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| N/A | `80016FFC_ESimsCam_ApplyZoom` | ? | `src/wip/version_diff/match_80016FFC_ESimsCam_ApplyZoom.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| N/A | `800595B8_Player_GetPrimaryNeighbor` | ? | `src/wip/version_diff/match_800595B8_Player__GetPrimaryNeighbor.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| N/A | `800A76AC_QuickStringSet_GetString` | 80B | `src/wip/version_diff/match_800A76AC_QuickStringSet__GetString.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| N/A | `800C2D5C_global_ctor_redAspMotiveDecayMult` | ? | `src/wip/version_diff/match_800C2D5C_global_ctor_redAspMotiveDecayMult.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| N/A | `800CC678_global_ctor_Interests` | ? | `src/wip/version_diff/match_800CC678_global_ctor_Interests.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| N/A | `800CC6A4_global_dtor_Interests` | ? | `src/wip/version_diff/match_800CC6A4_global_dtor_Interests.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| N/A | `800D22E4_c2DArray_CopyFrom_BString` | ? | `src/wip/version_diff/match_800D22E4__c2DArray__CopyFrom_BString.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| N/A | `800D2394_c2DArray_CopyTo` | ? | `src/wip/version_diff/match_800D2394__c2DArray__CopyTo.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| N/A | `80140D28_cSimulatorImpl_ComputeTimeOfDay` | 72B | `src/wip/version_diff/match_80140D28_cSimulatorImpl__ComputeTimeOfDay.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| N/A | `80147A34_TreeSimImpl_Reset` | ? | `src/wip/version_diff/match_80147A34_TreeSimImpl__Reset.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| N/A | `801490D0_TreeStack_GetNthFrame` | ? | `src/wip/version_diff/match_801490D0_TreeStack__GetNthFrame.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| N/A | `801491BC_TreeSim_GetPrimName` | ? | `src/wip/version_diff/match_801491BC_TreeSim__GetPrimName.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| N/A | `80183138_ActionMenu_MenuItem_IsObjectInMenu` | ? | `src/wip/version_diff/match_80183138_ActionMenu__MenuItem__IsObjectInMenu.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| N/A | `8018458C_GetActionMenu` | ? | `src/wip/version_diff/match_8018458C_GetActionMenu.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| N/A | `80190DF4_InteractionHelper_GetNext` | ? | `src/wip/version_diff/match_80190DF4_InteractionHelper__GetNext.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| N/A | `80195C40_CASTarget_ShowAllCFAOptions` | ? | `src/wip/version_diff/match_80195C40_CASTarget__ShowAllCFAOptions.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| N/A | `801B2994_FAMTarget_GetNumberOfChoicesInState` | ? | `src/wip/version_diff/match_801B2994_FAMTarget__GetNumberOfChoicesInState.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| N/A | `8021f480_SocialModeInteractor_SetupInteractionMenu` | ? | `src/wip/version_diff/match_8021f480_SocialModeInteractor_SetupInteractionMenu.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| N/A | `8024BACC_OSDBJump` | ? | `src/wip/version_diff/match_8024BACC_OSDBJump.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| N/A | `802E2D5C_EEngine_RetraceUpdate` | ? | `src/wip/version_diff/match_802E2D5C_EEngine__RetraceUpdate.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| N/A | `802E391C_MainInit` | ? | `src/wip/version_diff/match_802E391C_MainInit.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| N/A | `802F6A2C_ERC_TriStripRef` | ? | `src/wip/version_diff/match_802F6A2C_ERC_TriStripRef.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
| N/A | `80349F30_ENgcRenderer_ProcessFrameEffectsfloat,_float,_float,_float,_EVec3_&,_EVec3_&` | ? | `src/wip/version_diff/match_80349F30_ENgcRenderer_ProcessFrameEffectsfloat,_float,_float,_float,_EVec3_&,_EVec3_&.cpp` | Needs OpusReviewGuy -- no clear classifier signature |
