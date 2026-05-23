/* include/types/objectsim_tu.h — translation-unit clarification header
 *
 * S17 TypeArchaeologist Phase 1 deliverable #3.
 *
 * ============================================================================
 *  THIS IS A TU NOTE, NOT A NEW CLASS LAYOUT.
 * ============================================================================
 *
 * The Session 17 attack plan and several typereqs reference "cXObjectSim".
 * **There is no class named cXObjectSim.** That string was the name of a
 * translation unit (`objectsim.obj`), not a C++ class.
 *
 * What `objectsim.obj` actually contains (per the symbol map):
 *
 *   1. **cXObjectImpl methods** — the bulk of the TU. Specifically the
 *      `Try*` family that the behavior-tree interpreter dispatches into:
 *      TryUserEvent, TryUIEffect, TryTestObjectType, TryIsPersonInArea,
 *      TryFindGoodLocation, TrySetBalloon, TryCallNamedTree, ParseUIString,
 *      TryMakeActionString, TryPushAction, TryFind5WorstMotives,
 *      TryRelationship/Relationship2, TryTutorial, TryBurn, TryCreateObject,
 *      TryPreloadObject, TryDropOnto, TryBudget, TrySetToNext,
 *      TryFindFunctionalObject, TryCallFunctionalTree, TryGenericSimCall,
 *      ShowAllObjectDialogs, ChangeSelectedSimL/R, TryDialog,
 *      TransitionToNewHouse, RewriteDialogParamIndices, TryShowString,
 *      TryKillObject, KillSelf, TryIdle, TryUpdate, TryGrab, TryTreeBreak,
 *      TryRandom, TryRoomEffect, TryCheckObject, TryGbaCommunication,
 *      TryAnimateObject, TryCompleteGoal, InventoryCommandParam_GetGuid,
 *      InventoryCommandParam_GetCount, TryInventoryCommand, TryCameraControl,
 *      TryDistanceTo, TryDirectionTo, TryNotifyStackObject,
 *      TryParticleEffect, TryMemory, TryPassiveInfluence,
 *      GetShortComboValue, TryWantsAndFearsNotify, TryChangeWantFearTree,
 *      TrySetMotiveDelta, TryAnimate, Simulate, TryElement, TrySnap,
 *      TryExpression, TryDrop, TryPlaySound, TryKillSounds, TryHUDCreate,
 *      TryHUDAddItem, TryHUDManage, TryHUDData, GosubObjectTree, RunTree,
 *      InterpValue (two overloads), InterpWriteValue, TryFindTreeNew,
 *      Backtrace, TryHUDEffect, TryHUDDestroy. Plus AllowIdleOptimization,
 *      HandleBreakpoint.
 *
 *   2. **Free functions** unique to this TU:
 *      - TryFindSafeLocForSim(cXObject*, FTilePt&, int, cXObject*, int)
 *      - MakeMoneyString(StringBuffer2&, int)
 *      - ParseOneString(BString2&, BString2&, int, int*, int*, int*)
 *      - _MotiveSort(void*, void*)
 *      - StartFireAtObjectLoc(cXObject*, ObjSelector*)
 *      - PresetHouseGameStatus(void)
 *      - GetJobHUDName(short)
 *      - GetJobHUDControlName(short)
 *      - fround(float)
 *      - FTilePt::operator==(FTilePt&) const
 *      - cXObjectImpl::overrideDialogReturnCode (static short global)
 *
 *   3. **TArray<> template instantiations** and a couple of STL container
 *      privates (_Rb_tree, _List_base, __node_alloc) that landed in this TU
 *      due to first-use.
 *
 * Implication for writers:
 *   - For any "convert an objectsim stub" task, the relevant class layout is
 *     already in `include/types/cXObjectImpl.h`. There is no separate
 *     cXObjectSim header needed.
 *   - Free functions above can be declared inline at the .cpp top until they
 *     warrant promotion.
 *   - TArray<> template instances are intentionally left to the existing
 *     `include/templates/*` headers (and to S17 template-blast work).
 *
 * Lane 2 OpusWorker: include this header as a sanity check before writing any
 * `cXObjectSim::*` method signature — there isn't one to write.
 */
#ifndef SIMS2_TYPES_OBJECTSIM_TU_H
#define SIMS2_TYPES_OBJECTSIM_TU_H

#include "cXObjectImpl.h"

#endif /* SIMS2_TYPES_OBJECTSIM_TU_H */
