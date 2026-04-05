# cXObjectImpl Field Offset Table

Extracted from 169 functions in src/asm_decomp/cXObjectImpl.cpp
Total unique field offsets: 145

## Field Map

| Offset | Size | Type | R/W | #Funcs | Key Functions |
|--------|------|------|-----|--------|---------------|
| 0x0000 | 1/2/4 | float | R/W | 113 | AllowIdleOptimization, CalcDistance, CalcDistanceWithPentalties, CalcShortDistanceIn16thsOfTiles (+109) |
| 0x0001 | 1 | byte | R | 1 | TrySetMotiveDelta |
| 0x0002 | 1/2 | short | R/W | 5 | PostLoad, TryCheckObject, TryDirectionTo, TrySetMotiveDelta (+1) |
| 0x0003 | 1 | byte | R | 1 | TrySetMotiveDelta |
| 0x0004 | 1/2/4 | float | R/W | 142 | AllowIdleOptimization, CalcDistance, CalcDistanceWithPentalties, CalcShortDistanceIn16thsOfTiles (+138) |
| 0x0005 | 1 | byte | R | 1 | TryDirectionTo |
| 0x0006 | 1/2 | short | R/W | 5 | InterpValue, PostLoad, TryDirectionTo, TryRelationship2 (+1) |
| 0x0007 | 1 | byte | R | 2 | InterpValue, TryIdle |
| 0x0008 | 4 | float | R/W | 16 | Initialize, InterpValue, ParseUIString, ReconSlots (+12) |
| 0x000C | 4 | int/ptr | R/W | 14 | HierGetObject, Initialize, InterpValue, ParseUIString (+10) |
| 0x000E | 2 | short | R | 1 | ReconStream |
| 0x0010 | 2/4 | float | R/W | 13 | GetInteractionLeader, HierGetObject, Initialize, InterpValue (+9) |
| 0x0012 | 2 | short | R | 1 | IsRoof |
| 0x0014 | 2/4 | float | R/W | 11 | HierGetObject, Initialize, InterpValue, IsSpriteVisible (+7) |
| 0x0016 | 2 | short | R/W | 7 | InterpValue, TryCameraControl, TryCheckObject, TryCreateObject (+3) |
| 0x0018 | 2/4 | float | R/W | 18 | ExtractContainedSims, Initialize, InterpValue, ReconSlots (+14) |
| 0x001A | 2 | short | R | 1 | TryGenericSimCall |
| 0x001C | 2/4 | float | R/W | 8 | GetSlotHeight, Initialize, ReconSlots, TestAndPlace (+4) |
| 0x0020 | 4 | float | R | 1 | TrySnap |
| 0x0024 | 2/4 | float | R/W | 4 | DayPassed, ParseUIString, TrySnap, TryWantsAndFearsNotify |
| 0x0028 | 2/4 | float | R | 4 | Initialize, InterpValue, ParseUIString, TrySnap |
| 0x002C | 4 | int/ptr | R | 1 | ParseUIString |
| 0x0030 | 4 | float | R/W | 3 | ParseUIString, TrySnap, TrySnap |
| 0x0034 | 2/4 | float | R/W | 7 | InterpValue, ParseUIString, TryCameraControl, TryFindGoodLocation (+3) |
| 0x0038 | 2/4 | float | R | 7 | DayPassed, GetFrontFaceDirection, ParseUIString, PostLoad (+3) |
| 0x003C | 4 | int/ptr | R | 2 | ParseUIString, TryGenericSimCall |
| 0x0044 | 4 | int/ptr | R | 1 | TryGenericSimCall |
| 0x0046 | 2 | short | R | 1 | DayPassed |
| 0x0048 | 2 | short | R | 2 | DayPassed, InterpValue |
| 0x004A | 2 | short | R | 1 | DayPassed |
| 0x004C | 2/4 | float | R | 3 | DayPassed, InterpValue, TryCameraControl |
| 0x004E | 2 | short | R | 1 | IsFromCatalog |
| 0x0050 | 2/4 | float | R | 2 | IsFromCatalog, TryCameraControl |
| 0x0058 | 2/4 | int/ptr | R/W | 24 | CalcDistance, Cleanup, EnableSim, Error (+20) |
| 0x005C | 2/4 | int/ptr | R/W | 2 | HideForCutaway, cXObjectImpl |
| 0x0060 | 2/4 | int/ptr | R/W | 6 | InterpValue, ReconStream, TryGenericSimCall, TrySnap (+2) |
| 0x0062 | 2 | short | R | 1 | Reset |
| 0x0064 | 2/4 | int/ptr | R/W | 14 | Cleanup, EnableSim, HierSetSite, InterpValue (+10) |
| 0x0068 | 4 | int/ptr | R/W | 17 | CalcDistanceWithPentalties, CalcShortDistance, CalcShortDistance, CalcShortDistanceIn16thsOfTiles (+13) |
| 0x006C | 4 | int/ptr | R | 15 | CalcDistanceWithPentalties, CalcShortDistance, CalcShortDistance, CalcShortDistanceIn16thsOfTiles (+11) |
| 0x0070 | 4 | int/ptr | R/W | 2 | TestIntersection, cXObjectImpl |
| 0x007C | 4 | float | R | 1 | InterpValue |
| 0x0080 | 4 | int/ptr | R/W | 18 | GetPlacementSpec, HierGetSite, Pickup, Place (+14) |
| 0x0084 | 4 | int/ptr | R/W | 2 | SetHilite, cXObjectImpl |
| 0x0088 | 4 | int/ptr | R/W | 9 | ComputeRect, DayPassed, GetDebugName, GetTileWidth (+5) |
| 0x008A | 2 | short | R | 1 | IsFromCatalog |
| 0x008C | 4 | int/ptr | R/W | 7 | DayPassed, GetDebugName, GetFrontFaceDirection, Initialize (+3) |
| 0x0090 | 2/4 | int/ptr | R/W | 8 | GetObjectSlot, HierGetChild, Initialize, ReconSlots (+4) |
| 0x0094 | 4 | int/ptr | R | 2 | ReconStream, TryGenericSimCall |
| 0x0098 | 2 | short | R | 1 | TryGenericSimCall |
| 0x00A0 | 2/4 | int/ptr | R/W | 6 | TryCallNamedTree, TryFindFunctionalObject, TryGenericSimCall, TrySnap (+2) |
| 0x00A4 | 4 | int/ptr | R | 2 | TryGenericSimCall, TrySnap |
| 0x00A8 | 2 | short | R | 1 | TryGenericSimCall |
| 0x00B0 | 4 | int/ptr | R/W | 5 | AllowIdleOptimization, Simulate, TrySetBalloon, cXObjectImpl (+1) |
| 0x00B4 | 4 | int/ptr | R | 2 | AllowIdleOptimization, TrySetBalloon |
| 0x00B6 | 2 | short | R | 1 | TestAndPlace |
| 0x00B8 | 2 | short | R | 5 | InterpValue, TryCheckObject, TryGenericSimCall, TryRelationship (+1) |
| 0x00BC | 4 | int/ptr | R | 1 | TryGenericSimCall |
| 0x00C0 | 4 | int/ptr | R/W | 2 | TryGenericSimCall, cXObjectImpl |
| 0x00C4 | 4 | int/ptr | R/W | 2 | ChangeSelectedSimR, cXObjectImpl |
| 0x00C8 | 1 | byte | W | 1 | cXObjectImpl |
| 0x00CC | 4 | int/ptr | W | 1 | cXObjectImpl |
| 0x00D0 | 4 | float | W | 1 | cXObjectImpl |
| 0x00D4 | 4 | float | W | 1 | cXObjectImpl |
| 0x00D8 | 2/4 | int/ptr | R/W | 3 | InterpValue, TryGenericSimCall, cXObjectImpl |
| 0x00DA | 2 | short | W | 1 | cXObjectImpl |
| 0x00DC | 4 | int/ptr | R/W | 6 | Initialize, Reset, SetSyncObject, SyncObjectIsReady (+2) |
| 0x00E0 | 4 | float | R/W | 6 | Initialize, Reset, SetSyncObject, SyncObjectIsReady (+2) |
| 0x00E4 | 4 | int/ptr | W | 6 | Initialize, Reset, SetSyncObject, SyncObjectIsReady (+2) |
| 0x00E8 | 2/4 | int/ptr | R | 3 | TryCameraControl, TryGenericSimCall, TrySnap |
| 0x00EA | 2 | short | R | 1 | TryGenericSimCall |
| 0x00EC | 4 | int/ptr | R/W | 11 | Cleanup, HandleError, PostLoad, TryBurn (+7) |
| 0x00F0 | 2 | short | R | 1 | TryMakeActionString |
| 0x00F8 | 2 | short | R | 2 | TestAndPlace, TryFindGoodLocation |
| 0x0100 | 1/2 | short | R | 2 | TestIntersection, TryGenericSimCall |
| 0x010C | 4 | int/ptr | W | 1 | cXObjectImpl |
| 0x0110 | 2 | short | R | 2 | TryGenericSimCall, TrySnap |
| 0x0114 | 4 | int/ptr | R/W | 3 | TryGenericSimCall, TrySnap, cXObjectImpl |
| 0x0120 | 2 | short | R | 2 | ReconStream, TryGenericSimCall |
| 0x0124 | 4 | int/ptr | R | 1 | TryGenericSimCall |
| 0x0128 | 2 | short | R | 1 | TryGenericSimCall |
| 0x012C | 4 | int/ptr | R | 1 | TryGenericSimCall |
| 0x0130 | 2/4 | int/ptr | R/W | 3 | TryBurn, TryFindGoodLocation, TryGenericSimCall |
| 0x0134 | 4 | int/ptr | R | 1 | TryGenericSimCall |
| 0x0138 | 2 | short | R | 2 | TryFindGoodLocation, TryGenericSimCall |
| 0x013C | 4 | int/ptr | R | 1 | TryGenericSimCall |
| 0x0140 | 2 | short | R | 2 | TestIntersection, TryGenericSimCall |
| 0x0144 | 4 | int/ptr | R | 1 | TryGenericSimCall |
| 0x0148 | 2 | short | R | 1 | TryGenericSimCall |
| 0x014C | 4 | int/ptr | R | 1 | TryGenericSimCall |
| 0x0150 | 2 | short | R | 2 | TryGenericSimCall, TrySnap |
| 0x0154 | 4 | int/ptr | R | 2 | TryGenericSimCall, TrySnap |
| 0x0158 | 2 | short | R | 2 | TryGenericSimCall, TrySnap |
| 0x015C | 4 | int/ptr | R | 2 | TryGenericSimCall, TrySnap |
| 0x0160 | 2/4 | int/ptr | R | 2 | TryCameraControl, TryGenericSimCall |
| 0x0164 | 4 | int/ptr | R | 1 | TryGenericSimCall |
| 0x0168 | 2 | short | R | 1 | TryGenericSimCall |
| 0x016C | 4 | int/ptr | R | 1 | TryGenericSimCall |
| 0x0170 | 2 | short | R | 1 | TryGenericSimCall |
| 0x0174 | 4 | int/ptr | R | 1 | TryGenericSimCall |
| 0x0188 | 2 | short | R | 1 | TryGenericSimCall |
| 0x018C | 4 | int/ptr | R | 1 | TryGenericSimCall |
| 0x0198 | 2 | short | R | 1 | TryPlaySound |
| 0x01A8 | 2 | short | R | 3 | TryGenericSimCall, TryRelationship, TryRelationship2 |
| 0x01AC | 4 | int/ptr | R | 1 | TryGenericSimCall |
| 0x01B0 | 2 | short | R | 1 | TryGenericSimCall |
| 0x01B4 | 4 | int/ptr | R | 1 | TryGenericSimCall |
| 0x01B8 | 2 | short | R | 2 | TryGenericSimCall, TrySnap |
| 0x01BC | 4 | int/ptr | R | 1 | TryGenericSimCall |
| 0x01E8 | 2 | short | R | 1 | TryGenericSimCall |
| 0x01EC | 4 | int/ptr | R | 1 | TryGenericSimCall |
| 0x0210 | 2 | short | R | 1 | TryGenericSimCall |
| 0x0214 | 4 | int/ptr | R | 1 | TryGenericSimCall |
| 0x0218 | 2 | short | R | 1 | TryGenericSimCall |
| 0x021C | 4 | int/ptr | R | 1 | TryGenericSimCall |
| 0x0228 | 2 | short | R | 1 | Cleanup |
| 0x0250 | 2 | short | R | 1 | TryFindGoodLocation |
| 0x0260 | 2 | short | R | 3 | TryFindGoodLocation, TryGenericSimCall, TrySnap |
| 0x0264 | 4 | int/ptr | R | 3 | TryFindGoodLocation, TryGenericSimCall, TrySnap |
| 0x02A8 | 4 | int/ptr | R | 1 | InterpValue |
| 0x02AC | 4 | int/ptr | R | 1 | InterpValue |
| 0x02B8 | 2 | short | R | 2 | TryGenericSimCall, TrySnap |
| 0x02BC | 4 | int/ptr | R | 2 | TryGenericSimCall, TrySnap |
| 0x0318 | 2 | short | R | 1 | TrySnap |
| 0x031C | 4 | int/ptr | R | 1 | TrySnap |
| 0x0320 | 4 | int/ptr | R | 2 | TryCameraControl, TryUpdate |
| 0x0328 | 2 | short | R | 1 | TrySnap |
| 0x032C | 4 | int/ptr | R | 1 | TrySnap |
| 0x0338 | 2 | short | R | 1 | TrySnap |
| 0x033C | 4 | int/ptr | R | 1 | TrySnap |
| 0x0340 | 2 | short | R | 1 | TrySnap |
| 0x0344 | 4 | int/ptr | R | 1 | TrySnap |
| 0x0350 | 2 | short | R | 2 | TryFindGoodLocation, TrySnap |
| 0x0354 | 4 | int/ptr | R | 2 | TryFindGoodLocation, TrySnap |
| 0x0378 | 2 | short | R | 1 | Cleanup |
| 0x037C | 4 | int/ptr | R | 1 | Cleanup |
| 0x03D8 | 2 | short | R | 1 | TryGenericSimCall |
| 0x03DC | 4 | int/ptr | R | 1 | TryGenericSimCall |
| 0x03F4 | 4 | int/ptr | R | 3 | TryParticleEffect, TrySnap, TrySnap |
| 0x0488 | 2 | short | R | 14 | GetContainer, GetPlacementSpec, InterpValue, ParseUIString (+10) |
| 0x048C | 4 | int/ptr | R | 3 | TryFindGoodLocation, TryGenericSimCall, TrySnap |
| 0x0520 | 2 | short | R | 2 | TryGenericSimCall, TrySnap |
| 0x0524 | 4 | int/ptr | R | 2 | TryGenericSimCall, TrySnap |
| 0x0540 | 2 | short | W | 1 | TryNotifyStackObject |
| 0x063C | 4 | int/ptr | R | 1 | TryCameraControl |

## Struct Layout (C++ skeleton)

