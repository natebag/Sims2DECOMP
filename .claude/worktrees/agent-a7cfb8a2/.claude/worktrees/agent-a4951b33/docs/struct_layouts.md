# Struct Layouts - Sims 2 GameCube Decompilation

Auto-generated from assembly analysis of `src/asm_decomp/` files and symbol map files.
Field names are inferred from getter/setter patterns in the assembly.

**Total classes with field layouts:** 714
**Total fields discovered:** 9910 (2940 with inferred names)

## Class Summary

| Class | Fields | Named | Methods | Base | Min Size |
|-------|--------|-------|---------|------|----------|
| `EGlobal` | 211 | 36 | 198 | - | 0x654 |
| `cXObjectImpl` | 146 | 22 | 544 | - | 0x5C70 |
| `ENgcRenderer` | 119 | 33 | 288 | - | 0x4668 |
| `E3DWindow` | 118 | 33 | 90 | - | 0x348 |
| `ACTTarget` | 107 | 15 | 52 | - | 0x658 |
| `cXPersonImpl` | 106 | 21 | 348 | - | 0x66B0 |
| `SAnimator2` | 106 | 22 | 452 | - | 0x46F4 |
| `InteractorModule` | 98 | 7 | 90 | - | 0x60C |
| `ESim` | 97 | 21 | 152 | - | 0x648 |
| `CameraDirector` | 90 | 35 | 99 | - | 0x44C |
| `ISimsObjectModel` | 88 | 28 | 162 | - | 0x323C |
| `INVTarget` | 82 | 31 | 302 | - | 0x5EAC |
| `SimsCameraParameters` | 80 | 1 | 10 | - | 0x1C8 |
| `CasSimDescriptionS2C` | 74 | 38 | 77 | - | 0x122 |
| `CasSimState` | 72 | 47 | 50 | - | 0x120 |
| `G2DTarget` | 72 | 40 | 58 | - | 0xDE0 |
| `PCTTarget` | 70 | 27 | 114 | - | 0x47F4 |
| `M2MTarget` | 69 | 26 | 96 | - | 0x23E8 |
| `ESimsCam` | 66 | 32 | 166 | - | 0x570 |
| `Effects` | 65 | 0 | 50 | - | 0x1A8 |
| `cSimulatorImpl` | 59 | 16 | 110 | - | 0x180 |
| `EIWallPart` | 59 | 40 | 80 | - | 0xDBC |
| `WAFTarget` | 59 | 14 | 58 | - | 0x288 |
| `E2ETarget` | 56 | 15 | 96 | - | 0x288 |
| `O2TTarget` | 56 | 19 | 80 | - | 0x25C |
| `SaveGameTarget` | 55 | 1 | 62 | - | 0x168 |
| `ESpriteRender` | 53 | 49 | 30 | - | 0x5E98 |
| `GameData` | 53 | 3 | 112 | - | 0x1E34 |
| `INGTarget` | 53 | 29 | 66 | - | 0x468 |
| `MUWrapper` | 53 | 20 | 48 | - | 0x118 |
| `MMUTarget` | 52 | 15 | 106 | - | 0x360 |
| `PDATarget` | 52 | 13 | 34 | - | 0x178 |
| `ERLevel` | 51 | 9 | 222 | - | 0x60A4 |
| `CRDTarget` | 50 | 20 | 34 | - | 0xF8 |
| `ENgcRenderStateCache` | 50 | 0 | 37 | - | 0x9DC |
| `LoadGameTarget` | 50 | 1 | 70 | - | 0x14C |
| `NewControlParms` | 49 | 1 | 10 | - | 0xC4 |
| `CASSelectionTarget` | 48 | 10 | 50 | - | 0x5DB |
| `HUDTarget` | 48 | 23 | 134 | - | 0x8B8 |
| `FAMTarget` | 47 | 24 | 104 | - | 0x450 |
| `Neighbor` | 47 | 5 | 124 | - | 0x1B8 |
| `XRoute` | 47 | 4 | 74 | - | 0x4A8 |
| `CASGeneticsTarget` | 46 | 13 | 44 | - | 0x41C |
| `EGraphics` | 46 | 24 | 188 | - | 0x33C |
| `R2LTarget` | 46 | 20 | 38 | - | 0x1EC |
| `MODTarget` | 45 | 21 | 40 | - | 0x100 |
| `PlumbBob` | 45 | 16 | 70 | - | 0x440 |
| `CSPTarget` | 44 | 29 | 24 | - | 0x1A4 |
| `DlgWrapper` | 44 | 11 | 134 | - | 0x698C |
| `EIStaticModel` | 44 | 28 | 112 | - | 0x31C |
| `NeighborhoodImpl` | 43 | 9 | 148 | - | 0x450 |
| `SimModel` | 42 | 17 | 139 | - | 0x158 |
| `EACTrack` | 41 | 0 | 5 | - | 0xB0 |
| `ELiveMode` | 41 | 20 | 60 | - | 0x7E8C |
| `ERShader` | 41 | 14 | 132 | - | 0x17BC |
| `H2DTarget` | 41 | 9 | 76 | - | 0x5C74 |
| `EAnimController` | 40 | 32 | 230 | - | 0xB4 |
| `ERTQuantize4D` | 40 | 10 | 62 | - | 0x20FC |
| `MUStateMachine` | 40 | 1 | 34 | - | 0x108 |
| `RCPTarget` | 40 | 19 | 28 | - | 0x14C |
| `ERModel` | 39 | 16 | 170 | - | 0x294 |
| `ObjectFolderImpl` | 39 | 10 | 142 | - | 0x6D4 |
| `AptAnimationPoolData` | 38 | 1 | 68 | - | 0xAC |
| `CASTattooTarget` | 38 | 1 | 12 | - | 0x120 |
| `ESimsApp` | 38 | 6 | 62 | - | 0xD24 |
| `CSMTarget` | 37 | 11 | 22 | - | 0xF0 |
| `EYETarget` | 37 | 3 | 24 | - | 0xD8 |
| `ObjectModuleImpl` | 37 | 9 | 182 | - | 0x209C |
| `EShader` | 36 | 10 | 100 | - | 0x8DC |
| `ObjSelector` | 35 | 26 | 121 | - | 0xA8 |
| `SKLTarget` | 35 | 18 | 22 | - | 0xC4 |
| `TrapezoidFade` | 35 | 30 | 11 | - | 0xC8 |
| `CASMorphTarget` | 34 | 15 | 18 | - | 0x1C4 |
| `OptionsRecon` | 34 | 1 | 27 | - | 0xF4 |
| `AptFormat` | 33 | 0 | 14 | - | 0x90 |
| `CASPersonalTarget` | 32 | 16 | 28 | - | 0x122 |
| `INTTarget` | 32 | 12 | 28 | - | 0xE0 |
| `MDITarget` | 32 | 17 | 32 | - | 0x2654 |
| `Room` | 32 | 13 | 57 | - | 0xA4 |
| `SimImageMaker` | 32 | 15 | 41 | - | 0x53E4 |
| `ESims3DHead` | 31 | 3 | 16 | - | 0x514C |
| `EWindow` | 31 | 7 | 62 | - | 0x904 |
| `GOLTarget` | 31 | 12 | 22 | - | 0x5C60 |
| `TheSimsMaxisLogoState` | 31 | 1 | 14 | - | 0x6178 |
| `CUnlockDisplay` | 30 | 15 | 54 | - | 0x5FAC |
| `MOTTarget` | 30 | 11 | 32 | - | 0x16C |
| `RMDTarget` | 30 | 8 | 20 | - | 0x54A8 |
| `TheSimsStateMachine` | 30 | 1 | 18 | - | 0x47C |
| `WXFTarget` | 30 | 11 | 36 | - | 0x19C |
| `CASRoommateTarget` | 29 | 5 | 22 | - | 0x134C |
| `EParticleEffect` | 29 | 13 | 12 | - | 0x150 |
| `InLevelBaseState` | 29 | 1 | 26 | - | 0xF0 |
| `LevelLightingTuning` | 29 | 0 | 12 | - | 0xB8 |
| `BBHTarget` | 28 | 10 | 26 | - | 0xA8 |
| `CUnlockDisplayObject` | 28 | 10 | 58 | - | 0x88 |
| `ERTQuantize` | 28 | 8 | 60 | - | 0x1CF8 |
| `FCMTarget` | 28 | 11 | 24 | - | 0xA8 |
| `FONTarget` | 28 | 7 | 10 | - | 0x5BC8 |
| `OPTTarget` | 28 | 3 | 22 | - | 0x9C |
| `ActionMenu` | 27 | 6 | 43 | - | 0x398 |
| `AptCIH` | 27 | 16 | 144 | - | 0x5ACC |
| `CasScene` | 27 | 15 | 50 | - | 0xB20 |
| `CasSimRendererDynamic` | 27 | 8 | 44 | - | 0x1E28 |
| `CLoadingScreen` | 27 | 18 | 12 | - | 0x5580 |
| `EHouse` | 27 | 11 | 58 | - | 0x3F8 |
| `ERC` | 27 | 5 | 208 | - | 0x74 |
| `PAZBase` | 27 | 14 | 20 | - | 0xBC |
| `TheSimsNGCLicenseState` | 27 | 0 | 12 | - | 0xF4 |
| `AptActionInterpreter` | 26 | 0 | 350 | - | 0x94 |
| `BSplineVolume` | 26 | 3 | 30 | - | 0xE0 |
| `EResourceLoaderImpl` | 26 | 5 | 92 | - | 0xD08 |
| `ERoom` | 26 | 3 | 50 | - | 0xB4 |
| `ITBTarget` | 26 | 9 | 24 | - | 0xA0 |
| `RELTarget` | 26 | 14 | 22 | - | 0xA4 |
| `SpriteSlot` | 26 | 8 | 75 | - | 0x68 |
| `AptDisplayList` | 25 | 1 | 50 | - | 0x70 |
| `EyeToyClient` | 25 | 11 | 100 | - | 0x5EB8 |
| `LoadingScreenStateMachine` | 25 | 2 | 54 | - | 0xAC |
| `SlotLoader` | 25 | 0 | 10 | - | 0x6C |
| `StateMachine` | 25 | 2 | 72 | - | 0x98 |
| `WorldMap` | 25 | 1 | 16 | - | 0x11C |
| `cTrack` | 24 | 13 | 66 | - | 0x98 |
| `ENeighborhoodCustomChar` | 24 | 0 | 2 | - | 0x178 |
| `K2YTarget` | 24 | 7 | 26 | - | 0x108 |
| `SKNTarget` | 24 | 9 | 14 | - | 0x98 |
| `AptCharacterInst` | 23 | 0 | 78 | - | 0x78 |
| `HelpDialog` | 23 | 1 | 10 | - | 0x90 |
| `KEYTarget` | 23 | 5 | 12 | - | 0x90 |
| `MSGTarget` | 23 | 8 | 14 | - | 0xA0 |
| `PlumbBobParms` | 23 | 1 | 12 | - | 0x4264 |
| `PRGTarget` | 23 | 5 | 38 | - | 0x94 |
| `PSETarget` | 23 | 4 | 12 | - | 0x94 |
| `RGTTarget` | 23 | 6 | 14 | - | 0x94 |
| `AptDisplayListState` | 22 | 1 | 30 | - | 0x64 |
| `AwarenessManager` | 22 | 13 | 100 | - | 0xB4 |
| `cGZSndSys` | 22 | 1 | 30 | - | 0x41C |
| `EController` | 22 | 11 | 166 | - | 0x20C |
| `EdithDialogPrimitive` | 22 | 11 | 14 | - | 0x8C |
| `EIFloor` | 22 | 4 | 54 | - | 0x120 |
| `EIStaticSubModel` | 22 | 9 | 74 | - | 0xF4 |
| `EResPrefetch` | 22 | 5 | 42 | - | 0x418 |
| `ERoomWall` | 22 | 15 | 44 | - | 0x114 |
| `AptDate` | 21 | 1 | 94 | - | 0x68 |
| `CASFashionTarget` | 21 | 3 | 22 | - | 0x90 |
| `cFixedWorldImpl` | 21 | 12 | 80 | - | 0x62 |
| `ENgcTextureBase` | 21 | 6 | 42 | - | 0x9C |
| `FlowGotoTarget` | 21 | 5 | 14 | - | 0x8C |
| `ImageProcessingManager` | 21 | 6 | 26 | - | 0x74 |
| `Path` | 21 | 1 | 21 | - | 0x70 |
| `WrapperPaneBase` | 21 | 14 | 270 | - | 0xF4 |
| `ActionQueueHUD` | 20 | 6 | 54 | - | 0x31A |
| `CASBodyTarget` | 20 | 1 | 18 | - | 0x8C |
| `CASMiscTarget` | 20 | 2 | 10 | - | 0x8C |
| `cXMTObjectImpl` | 20 | 10 | 70 | - | 0xC4 |
| `HoodManager` | 20 | 5 | 22 | - | 0x618C |
| `LiveModeChangeHouseStateMachine` | 20 | 1 | 14 | - | 0x98 |
| `PZ1Target` | 20 | 1 | 6 | - | 0xC0 |
| `ScalarDecomp` | 20 | 20 | 23 | - | 0x44 |
| `ScrollingTextBox` | 20 | 7 | 24 | - | 0x4F78 |
| `TheSimsStartScreenStateMachine` | 20 | 1 | 12 | - | 0x98 |
| `UIDialog` | 20 | 1 | 16 | - | 0x88 |
| `AptViewer` | 19 | 2 | 65 | - | 0x468 |
| `cXPortalImpl` | 19 | 9 | 40 | - | 0x188 |
| `DialogPaneBase` | 19 | 1 | 52 | - | 0x7330 |
| `Interaction` | 19 | 7 | 126 | - | 0x15A |
| `PAZTarget` | 19 | 1 | 6 | - | 0x90 |
| `ReconBuffer` | 19 | 0 | 45 | - | 0xA2 |
| `SpacePartition` | 19 | 6 | 40 | - | 0x58 |
| `TextBlock` | 19 | 11 | 53 | - | 0x4C |
| `UIAnalog` | 19 | 3 | 6 | - | 0x84 |
| `EBoneParticle` | 18 | 6 | 13 | - | 0x8C |
| `Emitter` | 18 | 3 | 40 | - | 0xBC |
| `ENgcAudioSampleManager` | 18 | 1 | 30 | - | 0xD28 |
| `ENgcTextureC8_32` | 18 | 3 | 20 | - | 0xD8 |
| `ERFont` | 18 | 8 | 80 | - | 0xF4 |
| `NghResFile` | 18 | 10 | 196 | - | 0x194 |
| `SlotDescriptor` | 18 | 0 | 4 | - | 0x48 |
| `UIAUDIOTarget` | 18 | 2 | 6 | - | 0x84 |
| `UIDBTarget` | 18 | 1 | 8 | - | 0x84 |
| `UIQDTarget` | 18 | 1 | 12 | - | 0x84 |
| `UIScreenManager` | 18 | 1 | 38 | - | 0x84 |
| `EIPointLight` | 17 | 11 | 48 | - | 0xD0 |
| `ELightGrid` | 17 | 0 | 43 | - | 0x6058 |
| `ENgcTextureC4_32` | 17 | 3 | 16 | - | 0xD4 |
| `ENgcTextureUtil` | 17 | 0 | 14 | - | 0x28 |
| `ERotDecomp` | 17 | 12 | 23 | - | 0x64 |
| `ESubModelShader` | 17 | 5 | 96 | - | 0x74 |
| `RainEffect` | 17 | 7 | 10 | - | 0xEA |
| `AptRenderingContext` | 16 | 0 | 20 | - | 0x3C0 |
| `AptShaderWord` | 16 | 4 | 12 | - | 0x1A8 |
| `CasSimRenderer` | 16 | 8 | 48 | - | 0x218 |
| `cGZSnd` | 16 | 7 | 46 | - | 0x3C |
| `EILight` | 16 | 5 | 74 | - | 0xAC |
| `EMat4` | 16 | 8 | 144 | - | 0x40 |
| `ENgcShader` | 16 | 0 | 12 | - | 0xF4 |
| `EVec3Decomp` | 16 | 10 | 23 | - | 0x54 |
| `PyramidFade` | 16 | 14 | 17 | - | 0xB0 |
| `UIButtonImages` | 16 | 1 | 20 | - | 0xB0 |
| `UIRouter` | 16 | 3 | 8 | - | 0x8C |
| `AptCharacterTextInst` | 15 | 8 | 8 | - | 0x78 |
| `AptParagraph` | 15 | 2 | 18 | - | 0x68 |
| `AptTextFormat` | 15 | 1 | 10 | - | 0x44 |
| `cBoxX` | 15 | 8 | 70 | - | 0x7C |
| `EIPortalPointLight` | 15 | 8 | 52 | - | 0xD8 |
| `ERAmbientSound` | 15 | 1 | 9 | - | 0x28 |
| `LogInteractionSample` | 15 | 0 | 6 | - | 0x3C |
| `Quad` | 15 | 0 | 10 | - | 0xF4 |
| `RoutingSlot` | 15 | 4 | 91 | - | 0x3C |
| `AmbientScorePlayer` | 14 | 6 | 52 | - | 0x3C |
| `CasMediator` | 14 | 5 | 51 | - | 0xAB0 |
| `CasNpcEditor` | 14 | 3 | 38 | - | 0x68 |
| `cHitMan` | 14 | 1 | 46 | - | 0x54 |
| `EApp` | 14 | 4 | 66 | - | 0x474 |
| `ENgcGraphics` | 14 | 1 | 42 | - | 0x32C |
| `ENgcMovie` | 14 | 7 | 50 | - | 0xA5 |
| `FamilyImpl` | 14 | 2 | 100 | - | 0x38 |
| `IFFResFile2` | 14 | 8 | 92 | - | 0x150 |
| `LogPersonTracker` | 14 | 9 | 15 | - | 0x370 |
| `PlumbBobModel` | 14 | 8 | 15 | - | 0x3C |
| `RoomManager` | 14 | 3 | 56 | - | 0x38 |
| `StartScreenVars` | 14 | 0 | 11 | - | 0x38 |
| `TextBaseItem` | 14 | 9 | 76 | - | 0x6324 |
| `UI2D` | 14 | 3 | 28 | - | 0x5C |
| `WantFear` | 14 | 0 | 0 | - | 0xA2 |
| `AmbientSoundPlayer` | 13 | 12 | 35 | - | 0x30 |
| `AptCharacterAnimation` | 13 | 3 | 20 | - | 0x50 |
| `AptValue` | 13 | 1 | 198 | - | 0x1F28 |
| `EInstance` | 13 | 7 | 162 | - | 0x60 |
| `ENgcRC` | 13 | 0 | 138 | - | 0x74 |
| `EStream` | 13 | 0 | 20 | - | 0x48 |
| `LogPersonState` | 13 | 10 | 4 | - | 0x40 |
| `PassiveInfluenceSystem` | 13 | 3 | 24 | - | 0x30 |
| `TreeSimImpl` | 13 | 4 | 58 | - | 0x44 |
| `WantFearManager` | 13 | 6 | 24 | - | 0x2C |
| `Bloom` | 12 | 12 | 16 | - | 0x74 |
| `DepthOfField` | 12 | 11 | 16 | - | 0x50 |
| `EFileSystem` | 12 | 1 | 40 | - | 0x24 |
| `EMirrorPortal` | 12 | 1 | 28 | - | 0xF4 |
| `EPrimitive` | 12 | 0 | 24 | - | 0x74 |
| `ESimsDataManager` | 12 | 3 | 28 | - | 0xD38 |
| `ISimsWallObjectModel` | 12 | 10 | 34 | - | 0x464 |
| `Motives` | 12 | 0 | 7 | - | 0x84 |
| `TGA_INFO` | 12 | 0 | 6 | - | 0x14 |
| `cSoundModeManager` | 11 | 10 | 48 | - | 0x34 |
| `CUnlockDisplayObjectSim` | 11 | 9 | 16 | - | 0x1B8 |
| `DepthOfFieldNGC` | 11 | 1 | 5 | - | 0x9DC |
| `EControllerData` | 11 | 1 | 16 | - | 0x7C |
| `EISpotLight` | 11 | 7 | 34 | - | 0xE0 |
| `ENgcAudio` | 11 | 4 | 58 | - | 0x60 |
| `ERAmbientScore` | 11 | 1 | 32 | - | 0x34 |
| `EResourceManager` | 11 | 5 | 130 | - | 0xD20 |
| `ETypeInfo` | 11 | 1 | 15 | - | 0x28 |
| `IconItem` | 11 | 4 | 26 | - | 0x34 |
| `MotionBlur` | 11 | 11 | 15 | - | 0x34 |
| `MUStatesSaveNewGame` | 11 | 0 | 12 | - | 0x58DC |
| `PreGameState` | 11 | 0 | 12 | - | 0x88 |
| `StartScreenStartState` | 11 | 0 | 17 | - | 0x190 |
| `TileWalls` | 11 | 7 | 78 | - | 0x38 |
| `AptArray` | 10 | 2 | 62 | - | 0x30 |
| `AptCharacterSpriteInstBase` | 10 | 1 | 12 | - | 0x30 |
| `AptString` | 10 | 0 | 60 | - | 0x28 |
| `BloomNGC` | 10 | 1 | 5 | - | 0x2C78 |
| `ButtonItem` | 10 | 1 | 6 | - | 0x70 |
| `CameraMotionSystem` | 10 | 0 | 21 | - | 0x58 |
| `DOGMA_PoolManager` | 10 | 1 | 23 | - | 0x20 |
| `EDL` | 10 | 2 | 20 | - | 0x68 |
| `EIObjectMan` | 10 | 2 | 38 | - | 0xC4 |
| `EMemoryMeterWin` | 10 | 2 | 16 | - | 0x28 |
| `ENgcFile` | 10 | 0 | 24 | - | 0x78 |
| `ENgcSNFile` | 10 | 0 | 24 | - | 0x40 |
| `ISimsCounterTopObject` | 10 | 9 | 34 | - | 0x3D0 |
| `MenuItem` | 10 | 1 | 6 | - | 0x70 |
| `ObjectDataObjDefinition` | 10 | 5 | 52 | - | 0x20 |
| `PassiveInfluenceMap` | 10 | 3 | 32 | - | 0x330 |
| `Physics` | 10 | 0 | 18 | - | 0x30 |
| `SkinCompositor` | 10 | 6 | 28 | - | 0x28 |
| `SmartDataFactory` | 10 | 2 | 20 | - | 0x68 |
| `TextItem` | 10 | 1 | 6 | - | 0x70 |
| `UI3D` | 10 | 1 | 27 | - | 0x28 |
| `AptXmlNode` | 9 | 0 | 24 | - | 0x2C |
| `cGZMusic` | 9 | 2 | 48 | - | 0x24 |
| `ENCamera` | 9 | 7 | 27 | - | 0x60 |
| `ERAnim` | 9 | 1 | 34 | - | 0x8C |
| `EThread` | 9 | 5 | 60 | - | 0x33C |
| `FrameEffectsManager` | 9 | 0 | 10 | - | 0x2B60 |
| `IFFBehResFile` | 9 | 1 | 9 | - | 0x148 |
| `IFFSlotDescList` | 9 | 1 | 32 | - | 0x68 |
| `ISimInstance` | 9 | 3 | 84 | - | 0x3C4 |
| `ISimsMultiTileObjectModel` | 9 | 7 | 32 | - | 0x460 |
| `LineFade` | 9 | 9 | 8 | - | 0x40 |
| `TGAWriter` | 9 | 0 | 16 | - | 0x2C |
| `TTabScratchEntry` | 9 | 1 | 132 | - | 0x11C |
| `WidgetScreenFormat` | 9 | 7 | 18 | - | 0x20 |
| `AptLoadVars` | 8 | 1 | 20 | - | 0x28 |
| `AptMemoryAllocationsT` | 8 | 1 | 7 | - | 0x20 |
| `AptScriptFunction2` | 8 | 8 | 24 | - | 0x38 |
| `AptScriptFunctionBase` | 8 | 3 | 40 | - | 0x32 |
| `AptSound` | 8 | 1 | 14 | - | 0x30 |
| `AptWord` | 8 | 5 | 18 | - | 0x30 |
| `AptXml` | 8 | 1 | 20 | - | 0x28 |
| `CareersImpl` | 8 | 3 | 32 | - | 0x20 |
| `CreateASimBaseState` | 8 | 0 | 28 | - | 0x1634 |
| `cXPortal` | 8 | 0 | 22 | - | 0x30 |
| `ECheatLookup` | 8 | 0 | 20 | - | 0x60 |
| `EFile` | 8 | 5 | 36 | - | 0x2C |
| `EFontData` | 8 | 1 | 36 | - | 0x28 |
| `EIPointAmbLight` | 8 | 5 | 34 | - | 0xC4 |
| `EResPrefetchFile` | 8 | 7 | 30 | - | 0x44 |
| `EShaderDef` | 8 | 0 | 7 | - | 0x34 |
| `EStringRedBlackTreeNoCase` | 8 | 1 | 58 | - | 0x20 |
| `ETexture` | 8 | 1 | 62 | - | 0x28 |
| `ETweak` | 8 | 0 | 18 | - | 0x28 |
| `FadeSquare` | 8 | 0 | 17 | - | 0x440 |
| `HouseImpl` | 8 | 5 | 42 | - | 0x74 |
| `IFFResMap` | 8 | 7 | 42 | - | 0x18 |
| `MemFile` | 8 | 3 | 34 | - | 0x128 |
| `NamespaceSelector` | 8 | 5 | 29 | - | 0x34 |
| `ObjectSlot` | 8 | 3 | 19 | - | 0x20 |
| `ObjTestSim` | 8 | 2 | 23 | - | 0xA2 |
| `ThumbnailLoader` | 8 | 0 | 7 | - | 0x400 |
| `AptKey` | 7 | 1 | 24 | - | 0x28 |
| `AptMathObj` | 7 | 1 | 44 | - | 0x28 |
| `AptNativeHash` | 7 | 3 | 46 | - | 0x14 |
| `ArcFileInfo` | 7 | 2 | 26 | - | 0x2C |
| `BackgroundImpl` | 7 | 1 | 24 | - | 0x34C |
| `CasGenetics` | 7 | 1 | 39 | - | 0x88 |
| `cSoundPlayer` | 7 | 2 | 65 | - | 0x20 |
| `CTGMicroTimer` | 7 | 7 | 7 | - | 0x1C |
| `cXMTObject` | 7 | 1 | 10 | - | 0x28 |
| `EAudioStreamManager` | 7 | 1 | 10 | - | 0xD20 |
| `EFontSize` | 7 | 1 | 40 | - | 0x2C |
| `EMsgQueue` | 7 | 3 | 26 | - | 0x4C |
| `ENDummy` | 7 | 4 | 29 | - | 0x58 |
| `EQuickdataManager` | 7 | 0 | 20 | - | 0xD28 |
| `ERDataset` | 7 | 1 | 38 | - | 0x20 |
| `ERedBlackTree` | 7 | 1 | 57 | - | 0x20 |
| `EResLoaderMsgQueue` | 7 | 5 | 11 | - | 0x50 |
| `ERMovie` | 7 | 2 | 14 | - | 0x28 |
| `IFFResList` | 7 | 1 | 8 | - | 0x18 |
| `IShrubObject` | 7 | 5 | 32 | - | 0x3CC |
| `MemoryCardCache` | 7 | 4 | 30 | - | 0x1C |
| `ResourceBehaviorTree` | 7 | 4 | 22 | - | 0x68 |
| `SetVar_EYE_state` | 7 | 3 | 6 | - | 0xB0 |
| `StackElem` | 7 | 7 | 26 | - | 0x14 |
| `TextFormat` | 7 | 0 | 6 | - | 0x20 |
| `UIAUDIO` | 7 | 2 | 31 | - | 0x78 |
| `ActionQueue` | 6 | 2 | 33 | - | 0x2B2 |
| `AptError` | 6 | 1 | 14 | - | 0x2C |
| `AptScriptColour` | 6 | 1 | 20 | - | 0x5DCC |
| `AptScriptFunctionByteCodeBlock` | 6 | 0 | 18 | - | 0x48 |
| `AptStage` | 6 | 1 | 12 | - | 0x21 |
| `Behavior` | 6 | 6 | 58 | - | 0x10 |
| `BitMatrix64` | 6 | 1 | 32 | - | 0x18 |
| `CasTweakTool` | 6 | 6 | 20 | - | 0x18 |
| `CDirtyXmlNode` | 6 | 1 | 45 | - | 0x20 |
| `EAHeap` | 6 | 0 | 68 | - | 0x538 |
| `EAllocGroup` | 6 | 1 | 17 | - | 0x18 |
| `ECheatDMI` | 6 | 3 | 14 | - | 0x54 |
| `EDebugMenu` | 6 | 0 | 12 | - | 0x1C |
| `EEngine` | 6 | 1 | 68 | - | 0x34 |
| `EFenceWall` | 6 | 0 | 10 | - | 0x40 |
| `EFloatTree` | 6 | 1 | 51 | - | 0x20 |
| `EFloorShdTblNode` | 6 | 0 | 24 | - | 0xB8 |
| `EParticleObj` | 6 | 2 | 8 | - | 0x1C |
| `ERenderSurface` | 6 | 2 | 18 | - | 0x18 |
| `EStringTableNoCase` | 6 | 2 | 56 | - | 0x18 |
| `FastAllocPool` | 6 | 1 | 36 | - | 0x18 |
| `FlashBigFile` | 6 | 3 | 18 | - | 0x18 |
| `FlashPiMenu` | 6 | 1 | 32 | - | 0x60 |
| `FreeResourceManager` | 6 | 2 | 13 | - | 0xCA8 |
| `IFFBehaviorConstants` | 6 | 1 | 26 | - | 0x64 |
| `IFFBehaviorTree` | 6 | 1 | 24 | - | 0x64 |
| `InfluenceMap` | 6 | 3 | 22 | - | 0x1C |
| `InteractionHelper` | 6 | 1 | 13 | - | 0x1C |
| `LogInteraction` | 6 | 1 | 15 | - | 0x18 |
| `MotionBlurNGC` | 6 | 1 | 5 | - | 0x9DC |
| `MUStatesLoadGame` | 6 | 0 | 12 | - | 0x58DC |
| `PassiveInfluencePerson` | 6 | 1 | 14 | - | 0x2C |
| `QuickDataSlotDescList` | 6 | 1 | 32 | - | 0x60 |
| `QuickDataSoundInfo` | 6 | 1 | 20 | - | 0x5C |
| `REffectsAttachment` | 6 | 1 | 34 | - | 0x20 |
| `REffectsEmitter` | 6 | 1 | 56 | - | 0x24 |
| `RelMatrixImpl` | 6 | 3 | 30 | - | 0x40 |
| `ResourceBehavior` | 6 | 4 | 18 | - | 0x20 |
| `SetVar_EYE_saveToSlotStatus` | 6 | 3 | 6 | - | 0x28 |
| `SimLog` | 6 | 6 | 16 | - | 0x18 |
| `StringPool` | 6 | 6 | 17 | - | 0x14 |
| `TreeTableEntryQuickData` | 6 | 5 | 126 | - | 0x1C |
| `TreeTableQuickData` | 6 | 4 | 74 | - | 0x28 |
| `UIDrawTable` | 6 | 1 | 25 | - | 0x18 |
| `UIUpdateTable` | 6 | 1 | 25 | - | 0x18 |
| `UIUserDrawCBTable` | 6 | 1 | 23 | - | 0x18 |
| `WallFadeParms` | 6 | 0 | 10 | - | 0x28 |
| `Wrapper` | 6 | 0 | 45 | - | 0xA4 |
| `AptActionQueueC` | 5 | 3 | 30 | - | 0x14 |
| `AptCharacterButtonInst` | 5 | 1 | 6 | - | 0x18 |
| `AptMovie` | 5 | 0 | 14 | - | 0x50 |
| `AptPseudoCIH_t` | 5 | 1 | 3 | - | 0x14 |
| `AptScriptFunction1` | 5 | 5 | 20 | - | 0x38 |
| `_c2DArray` | 5 | 5 | 38 | - | 0x18 |
| `CDirtyXml` | 5 | 1 | 77 | - | 0x24 |
| `ChangeHouseLoadHouse` | 5 | 0 | 14 | - | 0x20 |
| `cSamplePatch` | 5 | 1 | 19 | - | 0x1C |
| `CTilePt` | 5 | 4 | 102 | - | 0xC |
| `EAStringC` | 5 | 0 | 234 | - | 0x6 |
| `EBitArray` | 5 | 4 | 114 | - | 0x14 |
| `ECheats` | 5 | 0 | 22 | - | 0x10C |
| `EConfig` | 5 | 2 | 41 | - | 0x18 |
| `EDataHeader` | 5 | 2 | 18 | - | 0x14 |
| `EFloorTileGroup` | 5 | 1 | 4 | - | 0x14 |
| `EGEVert` | 5 | 0 | 6 | - | 0x24 |
| `EHashTable` | 5 | 4 | 56 | - | 0x14 |
| `EIFenceWall` | 5 | 1 | 38 | - | 0x3B0 |
| `ENgcControllerManager` | 5 | 0 | 10 | - | 0x20C |
| `ENgcRenderSurface` | 5 | 0 | 22 | - | 0x2C |
| `ENgcScheduler` | 5 | 0 | 32 | - | 0x3A4 |
| `ENgcTexture` | 5 | 2 | 40 | - | 0x2C |
| `EPMDesc` | 5 | 1 | 4 | - | 0x14 |
| `EREdithTreeSet` | 5 | 3 | 44 | - | 0x20 |
| `EResourceMap` | 5 | 2 | 42 | - | 0x14 |
| `ERSoundTrackData` | 5 | 1 | 34 | - | 0x1C |
| `EScratchBuffMan` | 5 | 1 | 12 | - | 0x14 |
| `FloatConstantsQuickData` | 5 | 1 | 38 | - | 0x34 |
| `GetLocalizableCommandTable` | 5 | 5 | 23 | - | 0x14 |
| `GetVariableCommandTable` | 5 | 5 | 23 | - | 0x14 |
| `GlobalSkillTables` | 5 | 0 | 3 | - | 0x40 |
| `HDDThread` | 5 | 4 | 44 | - | 0x5D0 |
| `HouseRecon` | 5 | 1 | 10 | - | 0x6008 |
| `HouseStats` | 5 | 5 | 24 | - | 0x28 |
| `LiveModeInitState` | 5 | 0 | 18 | - | 0x28 |
| `MotiveEffects` | 5 | 5 | 7 | - | 0xC4 |
| `MUStatesFormat` | 5 | 0 | 12 | - | 0x9C |
| `ObjectIterator` | 5 | 1 | 11 | - | 0x98 |
| `ObjFnTableQuickData` | 5 | 3 | 42 | - | 0x30 |
| `QuickDataBehaviorConstants` | 5 | 1 | 24 | - | 0x20 |
| `QuickStringSet` | 5 | 5 | 88 | - | 0x18 |
| `RepTitleSupport` | 5 | 5 | 14 | - | 0x1C |
| `RParticle` | 5 | 1 | 44 | - | 0x20 |
| `SetVariableCommandTable` | 5 | 5 | 23 | - | 0x14 |
| `TextureUtils` | 5 | 0 | 36 | - | 0x1B |
| `TreeStack` | 5 | 3 | 28 | - | 0x1C |
| `UIReflow` | 5 | 2 | 98 | - | 0x14 |
| `UrbzModeNewGameState` | 5 | 0 | 8 | - | 0xF4 |
| `AptLine` | 4 | 1 | 9 | - | 0x30 |
| `AptObject` | 4 | 1 | 30 | - | 0x28 |
| `ArcCopier` | 4 | 1 | 12 | - | 0x10 |
| `basic_string_ref` | 4 | 1 | 24 | - | 0x10 |
| `basic_string_ref2` | 4 | 1 | 24 | - | 0x10 |
| `BString` | 4 | 0 | 184 | - | 0x10 |
| `BString2` | 4 | 0 | 187 | - | 0x10 |
| `CameraManager` | 4 | 0 | 16 | - | 0x570 |
| `CasSimPartsS2C` | 4 | 3 | 73 | - | 0x10 |
| `CatalogResource` | 4 | 1 | 7 | - | 0x10 |
| `cSoundCacheItem` | 4 | 1 | 17 | - | 0x18 |
| `EBound3` | 4 | 4 | 46 | - | 0x10 |
| `EBoundSphere` | 4 | 0 | 9 | - | 0x10 |
| `EBoundTreeNode` | 4 | 0 | 36 | - | 0x28 |
| `ECullPlane` | 4 | 4 | 5 | - | 0x10 |
| `EFontCharacter` | 4 | 0 | 33 | - | 0x10 |
| `EIDirLight` | 4 | 1 | 42 | - | 0xB0 |
| `EIObjTileBoundRect` | 4 | 0 | 23 | - | 0x10 |
| `EMemoryWriteStream` | 4 | 0 | 20 | - | 0x24 |
| `EMovieMan` | 4 | 0 | 12 | - | 0xD24 |
| `ENgcSFXStreamer` | 4 | 2 | 30 | - | 0x1B6 |
| `EQuat` | 4 | 0 | 44 | - | 0x10 |
| `ERBinary` | 4 | 1 | 36 | - | 0x1C |
| `ERQuickdata` | 4 | 1 | 36 | - | 0x1C |
| `ERSoundEvent` | 4 | 1 | 42 | - | 0x34 |
| `ERTexture` | 4 | 2 | 44 | - | 0x28 |
| `ESemaphore` | 4 | 1 | 34 | - | 0x10 |
| `ESubModel` | 4 | 3 | 60 | - | 0xF4 |
| `FileList` | 4 | 2 | 11 | - | 0xD |
| `GetVar_EYE_settingSliderVal` | 4 | 4 | 6 | - | 0x10 |
| `GetVar_LockedStatus` | 4 | 4 | 6 | - | 0x10 |
| `GetVar_SliderStep` | 4 | 4 | 6 | - | 0x10 |
| `IconGroupImpl` | 4 | 4 | 16 | - | 0x10 |
| `IFFResNode` | 4 | 0 | 5 | - | 0xC |
| `IRect` | 4 | 4 | 11 | - | 0x10 |
| `KeyMembersIndex` | 4 | 0 | 3 | - | 0x8 |
| `MUStatesAutoSaveNew` | 4 | 0 | 8 | - | 0x9C |
| `MUStatesLoadHouse` | 4 | 0 | 12 | - | 0x94 |
| `MUStatesSaveExistingGame` | 4 | 0 | 12 | - | 0x94 |
| `MUStatesTransitionAutoSaveExisting` | 4 | 0 | 10 | - | 0x28 |
| `MUStatesTransitionSaveExistingGame` | 4 | 0 | 12 | - | 0x28 |
| `ObjectDataBehaviorConstants` | 4 | 4 | 28 | - | 0x18 |
| `ObjectDataBehaviorTree` | 4 | 2 | 38 | - | 0x58 |
| `ObjectList` | 4 | 1 | 10 | - | 0x10 |
| `PassiveInfluenceTarget` | 4 | 1 | 10 | - | 0x10 |
| `PiecewiseFn` | 4 | 4 | 14 | - | 0x10 |
| `Player` | 4 | 2 | 12 | - | 0x10 |
| `QuickResFile` | 4 | 3 | 74 | - | 0x14 |
| `RelationsCmp` | 4 | 0 | 4 | - | 0xEA |
| `SetVar_EYE_settingSliderVal` | 4 | 4 | 6 | - | 0x10 |
| `SimsMemCardWrap` | 4 | 1 | 62 | - | 0xCC |
| `SpriteMembersIndex` | 4 | 0 | 3 | - | 0x8 |
| `StageMembersIndex` | 4 | 0 | 3 | - | 0x8 |
| `TreeSim` | 4 | 0 | 50 | - | 0x10 |
| `XmlMemberIndex` | 4 | 0 | 3 | - | 0x8 |
| `AptFloat` | 3 | 1 | 16 | - | 0x10 |
| `AptGlobal` | 3 | 0 | 12 | - | 0x21 |
| `AptPrototype` | 3 | 2 | 16 | - | 0x24 |
| `AptValueFactory` | 3 | 1 | 14 | - | 0x10 |
| `AptValueVector` | 3 | 1 | 14 | - | 0xC |
| `AptXmlAttributes` | 3 | 0 | 8 | - | 0x28 |
| `AutonomyConstantsClient` | 3 | 3 | 4 | - | 0x70 |
| `CasCostumes` | 3 | 1 | 24 | - | 0xC |
| `CatalogResourceImpl` | 3 | 0 | 12 | - | 0x10 |
| `CDirtyXmlImpl` | 3 | 1 | 3 | - | 0x24 |
| `ChainResFile` | 3 | 3 | 80 | - | 0x14 |
| `CheatMenuParams` | 3 | 1 | 14 | - | 0xC |
| `cHitControlGroup` | 3 | 3 | 5 | - | 0xC |
| `cSampleChannel` | 3 | 2 | 24 | - | 0x1C |
| `cXPerson` | 3 | 1 | 10 | - | 0x28 |
| `EControllerManager` | 3 | 2 | 100 | - | 0x20C |
| `EDatasetManager` | 3 | 0 | 46 | - | 0xD24 |
| `EFontPage` | 3 | 0 | 36 | - | 0x14 |
| `EGameStateMan` | 3 | 3 | 18 | - | 0xC |
| `EGrowPool` | 3 | 1 | 17 | - | 0xC |
| `EIAmbLight` | 3 | 1 | 35 | - | 0x94 |
| `EMemoryBufferWriteStream` | 3 | 0 | 10 | - | 0x24 |
| `EmitterSpr3d` | 3 | 0 | 15 | - | 0x8C |
| `ENgcController` | 3 | 3 | 24 | - | 0x210 |
| `ENodeList` | 3 | 2 | 38 | - | 0xC |
| `EPathUtil` | 3 | 0 | 20 | - | 0x3 |
| `ERCharacter` | 3 | 1 | 38 | - | 0xB4 |
| `EResource` | 3 | 1 | 76 | - | 0xE |
| `ERFlash` | 3 | 1 | 34 | - | 0x18 |
| `ERSampledata` | 3 | 1 | 12 | - | 0x1C |
| `ESingleLock` | 3 | 1 | 10 | - | 0xC |
| `ESpriteRenderMan` | 3 | 2 | 18 | - | 0xC |
| `EThreadMutex` | 3 | 1 | 8 | - | 0x40 |
| `FrameEffect` | 3 | 3 | 19 | - | 0x14 |
| `GetVar_EYE_connectionStatus` | 3 | 3 | 6 | - | 0xC |
| `GetVar_EYE_exists` | 3 | 3 | 6 | - | 0xC |
| `GetVar_EYE_targetState` | 3 | 3 | 6 | - | 0xC |
| `GetVar_GetCount` | 3 | 3 | 6 | - | 0xC |
| `GetVar_ImageSlotsAvail` | 3 | 3 | 6 | - | 0xC |
| `GetVar_Legacy` | 3 | 3 | 6 | - | 0xC |
| `GetVar_SaveRequired` | 3 | 3 | 6 | - | 0xC |
| `GetVar_SaveStatus` | 3 | 3 | 6 | - | 0xC |
| `GoalUnlock` | 3 | 3 | 28 | - | 0xE |
| `IFFBehavior` | 3 | 1 | 16 | - | 0x14 |
| `IngredientManager` | 3 | 3 | 16 | - | 0x10 |
| `InLevelCreateASimState` | 3 | 0 | 8 | - | 0x30 |
| `LoadingScreenFadeOutState` | 3 | 1 | 14 | - | 0xB8 |
| `MotiveConstantsClient` | 3 | 3 | 4 | - | 0x70 |
| `MUStatesAutoSaveExisting` | 3 | 0 | 10 | - | 0x24 |
| `MUStatesProcessRequests` | 3 | 0 | 8 | - | 0x28 |
| `MUStatesSlotSelectSaveNoSkip` | 3 | 0 | 8 | - | 0x9C |
| `NeighborhoodConstants` | 3 | 3 | 4 | - | 0x70 |
| `NeighborList` | 3 | 1 | 4 | - | 0xC |
| `ObjectIndex` | 3 | 0 | 3 | - | 0x7 |
| `ObjectSaveTypeTable` | 3 | 0 | 3 | - | 0xC |
| `ObjectTypeAttrBlock` | 3 | 1 | 11 | - | 0xC |
| `PaneItem` | 3 | 3 | 60 | - | 0x20 |
| `PassiveInfluenceObject` | 3 | 1 | 9 | - | 0x10 |
| `PlayerCheats` | 3 | 0 | 13 | - | 0x1C |
| `PlayerFamilyImpl` | 3 | 1 | 26 | - | 0xD68 |
| `PreGameCasPlayer1State` | 3 | 0 | 12 | - | 0x30 |
| `PreGameCasPlayer2State` | 3 | 0 | 12 | - | 0x30 |
| `PreGameCreateAFamilyState` | 3 | 0 | 8 | - | 0x30 |
| `ReconBuilder` | 3 | 1 | 14 | - | 0xC |
| `RelMatrix` | 3 | 1 | 7 | - | 0xC |
| `RoomScoreConstants` | 3 | 3 | 4 | - | 0x70 |
| `SeqResFile` | 3 | 1 | 26 | - | 0x138 |
| `SetVar_EYE_filterCurrSel` | 3 | 3 | 6 | - | 0xC |
| `SetVar_EYE_funframeCurrSel` | 3 | 3 | 6 | - | 0xC |
| `SetVar_EYE_opCancelled` | 3 | 3 | 6 | - | 0xC |
| `SetVar_EYE_slotCurrSel` | 3 | 3 | 6 | - | 0xC |
| `SetVar_EYE_topLevelCurrSel` | 3 | 3 | 6 | - | 0xC |
| `StateMachineStatus` | 3 | 3 | 24 | - | 0x18 |
| `TextFormatMembersIndex` | 3 | 0 | 3 | - | 0x8 |
| `TextMembersIndex` | 3 | 0 | 3 | - | 0x9 |
| `TheSimsMainMenuState` | 3 | 0 | 22 | - | 0x94 |
| `TheSimsMemCardCheckState` | 3 | 0 | 12 | - | 0x190 |
| `TheSimsSimsIntroMovieState` | 3 | 0 | 10 | - | 0x28 |
| `ThumbnailCompresser` | 3 | 0 | 4 | - | 0xC |
| `XObjLang` | 3 | 3 | 28 | - | 0x10 |
| `AnimTableImpl` | 2 | 0 | 14 | - | 0xC |
| `AptBoolean` | 2 | 0 | 16 | - | 0x10 |
| `AptCharacter` | 2 | 0 | 4 | - | 0x1C |
| `AptCharacterMorphInst` | 2 | 0 | 3 | - | 0x18 |
| `AptCharacterShapeInst` | 2 | 0 | 3 | - | 0x18 |
| `AptCharacterStaticTextInst` | 2 | 0 | 3 | - | 0x18 |
| `AptFrameStack` | 2 | 0 | 12 | - | 0x24 |
| `AptGC` | 2 | 1 | 8 | - | 0xC |
| `AptInteger` | 2 | 0 | 16 | - | 0x10 |
| `AptSavedInputCheckpoints` | 2 | 1 | 10 | - | 0xC |
| `AptStringObject` | 2 | 0 | 7 | - | 0x28 |
| `AptValueGC_PoolManager` | 2 | 2 | 14 | - | 0x8 |
| `BackgroundPane` | 2 | 0 | 3 | - | 0x60 |
| `BitArray64` | 2 | 2 | 32 | - | 0x8 |
| `cAudioInfo` | 2 | 2 | 8 | - | 0x8 |
| `CollisionMap` | 2 | 1 | 6 | - | 0x8 |
| `Commander` | 2 | 1 | 10 | - | 0x10 |
| `cSoundCache` | 2 | 1 | 26 | - | 0x104 |
| `CTGFileImpl` | 2 | 2 | 46 | - | 0x114 |
| `cXObject` | 2 | 2 | 36 | - | 0x8 |
| `DialogPane` | 2 | 0 | 3 | - | 0x60 |
| `DigestGeomShaderPtr` | 2 | 2 | 2 | - | 0xC |
| `EBitArrayProxy` | 2 | 0 | 9 | - | 0x8 |
| `ECharacterManager` | 2 | 0 | 11 | - | 0xC |
| `EdithResFile` | 2 | 0 | 6 | - | 0xD4 |
| `EFixedString` | 2 | 0 | 98 | - | 0x8 |
| `EFontManager` | 2 | 0 | 9 | - | 0xC |
| `EFrameAllocGroup` | 2 | 1 | 10 | - | 0x38 |
| `EMemoryReadStream` | 2 | 0 | 10 | - | 0x24 |
| `EmitterGeom3d` | 2 | 0 | 5 | - | 0x8C |
| `EmitterGeom3dTab` | 2 | 0 | 5 | - | 0x8C |
| `EMovie` | 2 | 0 | 16 | - | 0x74 |
| `ENgcAram` | 2 | 1 | 16 | - | 0x8 |
| `ENgcEngine` | 2 | 1 | 18 | - | 0x54 |
| `EShaderManager` | 2 | 0 | 13 | - | 0xC |
| `ESimShadow` | 2 | 2 | 8 | - | 0x324 |
| `ETextureManager` | 2 | 0 | 13 | - | 0xC |
| `EVibrate` | 2 | 1 | 49 | - | 0x8 |
| `GameEffectsManager` | 2 | 0 | 8 | - | 0xAC |
| `InteractionList` | 2 | 1 | 18 | - | 0x8 |
| `iResFile` | 2 | 1 | 28 | - | 0x10 |
| `LoadingScreenFadeInState` | 2 | 1 | 14 | - | 0xAC |
| `LoadingScreenUpdateState` | 2 | 1 | 14 | - | 0xAC |
| `MenuDialogPane` | 2 | 0 | 13 | - | 0x60 |
| `MorphUtilities` | 2 | 0 | 20 | - | 0x124 |
| `MotiveCurveSet` | 2 | 0 | 13 | - | 0x8 |
| `MultiShaderInfo` | 2 | 0 | 5 | - | 0x14 |
| `MUStatesLoadConfig` | 2 | 0 | 12 | - | 0x20 |
| `MUStatesSlotSelectSave` | 2 | 0 | 8 | - | 0x94 |
| `ObjResFile` | 2 | 0 | 8 | - | 0x10 |
| `PreGameFreeplayState` | 2 | 0 | 18 | - | 0x20 |
| `PropTableImpl` | 2 | 0 | 14 | - | 0xC |
| `ProtectedAllocPool` | 2 | 0 | 10 | - | 0x1C |
| `REffectsSequencer` | 2 | 1 | 40 | - | 0x14 |
| `SimRenderer` | 2 | 0 | 8 | - | 0x124 |
| `StateMachineManager` | 2 | 2 | 24 | - | 0x8 |
| `StdResFile` | 2 | 0 | 8 | - | 0xD4 |
| `TheSimsEnterMainMenuState` | 2 | 0 | 16 | - | 0x20 |
| `TileList` | 2 | 0 | 4 | - | 0x8 |
| `TrackDataReader` | 2 | 0 | 20 | - | 0x8 |
| `TreeTableAdQuickData` | 2 | 0 | 30 | - | 0xC |
| `TreeTableAdScratch` | 2 | 0 | 28 | - | 0x10 |
| `TreeTableEntry` | 2 | 2 | 34 | - | 0x8 |
| `UIDB` | 2 | 0 | 18 | - | 0xC |
| `UIHDTV` | 2 | 0 | 28 | - | 0x10 |

## Detailed Layouts (Top 50 by field count)

### `EGlobal`

**Size:** >= 0x654 (1620 bytes) | **Fields:** 211 (36 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `s16` | **`m_newUIString`** | R/W | `AllocPersonInstance`, `ConvertUnicodeToShiftJIS`, `CreateThumbnail`, ... |
| 0x001 | `u8` | **`m_nghHouseName`** | R | `GetNghHouseName` |
| 0x002 | `u16` | **`m_nghFamilyName`** | R/W | `ConvertUnicodeToShiftJIS`, `GetNghFamilyName`, `GetNghHouseName`, ... |
| 0x004 | `u16` | **`m_urbzButtonsRow`** | R/W | `ConvertSpriteIdToResId`, `ConvertUnicodeToShiftJIS`, `EGlobal`, ... |
| 0x006 | `u16` | `m_field_006` | W | `InitPlayerCheats` |
| 0x008 | `u16` | **`m_cursorPosAsFtile`** | R/W | `GetCursorPosAsFtile`, `GetNameFromSkill`, `InitPlayerCheats`, ... |
| 0x00A | `u16` | `m_field_00A` | W | `InitPlayerCheats` |
| 0x00C | `u16` | **`m_urbzButtonsRow_00C`** | R/W | `ConvertSpriteIdToResId`, `ConvertUnicodeToShiftJIS`, `GetMessagesTableRow`, ... |
| 0x00E | `u16` | `m_field_00E` | W | `InitPlayerCheats` |
| 0x010 | `u16` | **`m_defaults`** | R/W | `InitPlayerCheats`, `SetDefaults` |
| 0x012 | `u16` | `m_field_012` | W | `InitPlayerCheats` |
| 0x014 | `u16` | **`m_defaults_014`** | R/W | `InitPlayerCheats`, `SetDefaults` |
| 0x016 | `u16` | `m_field_016` | W | `InitPlayerCheats` |
| 0x018 | `u16` | `m_field_018` | R/W | `AllocInstance`, `InitPlayerCheats` |
| 0x01A | `u16` | `m_field_01A` | W | `InitPlayerCheats` |
| 0x01C | `u16` | `m_field_01C` | W | `AllocPersonInstance`, `InitPlayerCheats` |
| 0x01E | `u16` | `m_field_01E` | W | `InitPlayerCheats` |
| 0x020 | `u16` | `m_field_020` | W | `InitPlayerCheats` |
| 0x022 | `u16` | `m_field_022` | W | `InitPlayerCheats` |
| 0x024 | `u16` | **`m_houseLevelId`** | R/W | `GetHouseLevelId`, `InitPlayerCheats` |
| 0x026 | `u16` | `m_field_026` | W | `InitPlayerCheats` |
| 0x028 | `u16` | **`m_houseGrassShaderId`** | R/W | `AllocPersonInstance`, `GetHouseGrassShaderId`, `InitPlayerCheats` |
| 0x02A | `u16` | `m_field_02A` | W | `InitPlayerCheats` |
| 0x02C | `u16` | `m_field_02C` | W | `AllocPersonInstance`, `InitPlayerCheats` |
| 0x02E | `u16` | `m_field_02E` | W | `InitPlayerCheats` |
| 0x030 | `u16` | `m_field_030` | W | `AllocPersonInstance`, `InitPlayerCheats` |
| 0x032 | `u16` | `m_field_032` | W | `InitPlayerCheats` |
| 0x034 | `u16` | `m_field_034` | W | `InitPlayerCheats` |
| 0x036 | `u16` | `m_field_036` | W | `InitPlayerCheats` |
| 0x038 | `u16` | `m_field_038` | W | `InitPlayerCheats` |
| 0x03A | `u16` | `m_field_03A` | W | `InitPlayerCheats` |
| 0x03C | `u16` | `m_field_03C` | W | `InitPlayerCheats` |
| 0x03E | `u16` | `m_field_03E` | W | `InitPlayerCheats` |
| 0x040 | `u16` | `m_field_040` | W | `InitPlayerCheats` |
| 0x042 | `u16` | `m_field_042` | W | `InitPlayerCheats` |
| 0x044 | `u16` | `m_field_044` | W | `InitPlayerCheats` |
| 0x046 | `u16` | `m_field_046` | W | `InitPlayerCheats` |
| 0x048 | `u16` | `m_field_048` | W | `InitPlayerCheats` |
| 0x04A | `u16` | `m_field_04A` | W | `InitPlayerCheats` |
| 0x04C | `u16` | `m_field_04C` | W | `InitPlayerCheats` |
| 0x04E | `u16` | `m_field_04E` | W | `InitPlayerCheats` |
| 0x050 | `u16` | `m_field_050` | W | `InitPlayerCheats` |
| 0x052 | `u16` | `m_field_052` | W | `InitPlayerCheats` |
| 0x054 | `u16` | `m_field_054` | W | `InitPlayerCheats` |
| 0x056 | `u16` | `m_field_056` | W | `InitPlayerCheats` |
| 0x058 | `u16` | `m_field_058` | W | `InitPlayerCheats` |
| 0x05A | `u16` | `m_field_05A` | W | `InitPlayerCheats` |
| 0x05C | `u16` | `m_field_05C` | R/W | `AllocPersonInstance`, `InitPlayerCheats` |
| 0x05E | `u16` | `m_field_05E` | W | `InitPlayerCheats` |
| 0x060 | `u16` | `m_field_060` | W | `InitPlayerCheats` |
| 0x062 | `u16` | `m_field_062` | W | `InitPlayerCheats` |
| 0x064 | `s16` | `m_field_064` | R/W | `InitPlayerCheats`, `SelectNextInFamily`, `SelectPrevInFamily` |
| 0x066 | `u16` | `m_field_066` | W | `InitPlayerCheats` |
| 0x068 | `u16` | `m_field_068` | W | `InitPlayerCheats` |
| 0x06A | `u16` | `m_field_06A` | W | `InitPlayerCheats` |
| 0x06C | `u16` | `m_field_06C` | W | `InitPlayerCheats` |
| 0x06E | `u16` | `m_field_06E` | W | `InitPlayerCheats` |
| 0x070 | `u16` | `m_field_070` | W | `InitPlayerCheats` |
| 0x072 | `u16` | `m_field_072` | W | `InitPlayerCheats` |
| 0x074 | `u16` | `m_field_074` | W | `InitPlayerCheats` |
| 0x076 | `u16` | `m_field_076` | W | `InitPlayerCheats` |
| 0x078 | `u16` | **`m_defaults_078`** | R/W | `InitPlayerCheats`, `SetDefaults` |
| 0x07A | `u16` | `m_field_07A` | W | `InitPlayerCheats` |
| 0x07C | `u16` | `m_field_07C` | W | `InitPlayerCheats` |
| 0x07E | `u16` | `m_field_07E` | W | `InitPlayerCheats` |
| 0x080 | `u16` | `m_field_080` | W | `InitPlayerCheats` |
| 0x082 | `u16` | `m_field_082` | W | `InitPlayerCheats` |
| 0x084 | `u16` | `m_field_084` | W | `InitPlayerCheats` |
| 0x086 | `u8[0x16]` | _(gap)_ | - | - |
| 0x09C | `u16` | `m_field_09C` | R/W | `EGlobal`, `TogglePlayerCheat` |
| 0x0A0 | `u32` | **`m_defaults_0A0`** | W | `EGlobal`, `SetDefaults` |
| 0x0A4 | `f32` | **`m_defaults_0A4`** | W | `SetDefaults` |
| 0x0A8 | `f32` | **`m_defaults_0A8`** | W | `SetDefaults` |
| 0x0AC | `u32` | `m_field_0AC` | W | `EGlobal` |
| 0x0B0 | `u32` | `m_field_0B0` | W | `EGlobal` |
| 0x0B4 | `u32` | `m_field_0B4` | R/W | `EGlobal`, `LoadIntroRequirements`, `Reset` |
| 0x0B6 | `u16` | `m_field_0B6` | R | `CheckForZeroExtentOverride` |
| 0x0B8 | `u8` | `m_field_0B8` | W | `EGlobal` |
| 0x0B9 | `u8` | `m_field_0B9` | W | `EGlobal` |
| 0x0BC | `u32` | **`m_bIsObjectInUseByPlayer`** | R/W | `EGlobal`, `IsObjectInUseByPlayer`, `SetDefaults`, ... |
| 0x0C0 | `u32` | **`m_bIsObjectInUseByPlayer_0C0`** | R/W | `EGlobal`, `IsObjectInUseByPlayer`, `SetDefaults`, ... |
| 0x0C8 | `u32` | **`m_curHouse`** | R/W | `AllocInstance`, `AllocPersonInstance`, `ClearCurHouse`, ... |
| 0x0D0 | `u32` | **`m_defaults_0D0`** | R/W | `EGlobal`, `Reset`, `SelectWin`, ... |
| 0x0D4 | `u32` | **`m_floorIndex`** | R/W | `GetFloorIndex`, `SetDefaults` |
| 0x0D8 | `u32` | **`m_wallIndex`** | R/W | `GetWallIndex`, `SetDefaults` |
| 0x0DC | `u32` | **`m_fenceIndex`** | R/W | `GetFenceIndex`, `SetDefaults` |
| 0x0E4 | `u32` | `m_field_0E4` | R/W | `ConvertUnicodeToShiftJIS`, `EGlobal`, `LoadIntroRequirements`, ... |
| 0x0E8 | `u32` | **`m_houseLevelId_0E8`** | R/W | `EGlobal`, `GetGoalsLegendRow`, `GetHUDUIString`, ... |
| 0x0EC | `u32` | **`m_defaults_0EC`** | R/W | `ConvertSpriteIdToResId`, `EGlobal`, `Reset`, ... |
| 0x0F0 | `u32` | **`m_defaults_0F0`** | R/W | `EGlobal`, `Reset`, `SetDefaults` |
| 0x0F4 | `u32` | **`m_defaults_0F4`** | R/W | `EGlobal`, `Reset`, `SetDefaults` |
| 0x0F8 | `u32` | **`m_defaults_0F8`** | R/W | `EGlobal`, `SetDefaults` |
| 0x0FC | `u32` | `m_field_0FC` | R/W | `EGlobal`, `LoadIntroRequirements`, `Reset` |
| 0x100 | `u32` | **`m_defaults_100`** | R/W | `EGlobal`, `Reset`, `SetDefaults` |
| 0x104 | `u32` | `m_field_104` | R/W | `EGlobal`, `LoadIntroRequirements`, `Reset` |
| 0x108 | `u32` | **`m_defaults_108`** | R/W | `EGlobal`, `Reset`, `SetDefaults` |
| 0x10C | `u32` | **`m_defaults_10C`** | R/W | `EGlobal`, `Reset`, `SetDefaults` |
| 0x110 | `u32` | **`m_defaults_110`** | R/W | `EGlobal`, `Reset`, `SetDefaults` |
| 0x114 | `u32` | `m_field_114` | R/W | `EGlobal`, `LoadPreGlobalRequirements`, `Reset` |
| 0x118 | `u32` | `m_field_118` | W | `EGlobal` |
| 0x11C | `u32` | `m_field_11C` | W | `EGlobal` |
| 0x120 | `u32` | **`m_defaults_120`** | R/W | `EGlobal`, `Reset`, `SetDefaults` |
| 0x124 | `u32` | `m_field_124` | R/W | `EGlobal`, `LoadIntroRequirements`, `Reset` |
| 0x128 | `u32` | `m_field_128` | R/W | `EGlobal`, `LoadIntroRequirements`, `Reset` |
| 0x12C | `u32` | `m_field_12C` | R/W | `EGlobal`, `LoadIntroRequirements`, `Reset` |
| 0x130 | `u32` | `m_field_130` | R/W | `EGlobal`, `LoadIntroRequirements`, `Reset` |
| 0x134 | `u32` | `m_field_134` | R/W | `EGlobal`, `LoadIntroRequirements`, `Reset` |
| 0x138 | `u32` | `m_field_138` | W | `EGlobal` |
| 0x13C | `u32` | `m_field_13C` | R/W | `EGlobal`, `LoadIntroRequirements`, `Reset` |
| 0x140 | `u32` | `m_field_140` | R/W | `EGlobal`, `LoadIntroRequirements`, `Reset` |
| 0x144 | `u32` | `m_field_144` | R/W | `LoadIntroRequirements` |
| 0x148 | `u32` | `m_field_148` | R/W | `EGlobal`, `LoadIntroRequirements`, `Reset` |
| 0x14C | `u32` | `m_field_14C` | W | `EGlobal` |
| 0x150 | `u32` | `m_field_150` | W | `EGlobal` |
| 0x154 | `u32` | `m_field_154` | W | `EGlobal` |
| 0x160 | `u32` | **`m_defaults_160`** | W | `SetDefaults` |
| 0x168 | `u32` | `m_field_168` | W | `EGlobal` |
| 0x16C | `u8[0x1C]` | _(gap)_ | - | - |
| 0x188 | `u32` | `m_field_188` | W | `EGlobal` |
| 0x18C | `u8` | `m_field_18C` | W | `EGlobal` |
| 0x190 | `u32` | `m_field_190` | W | `EGlobal` |
| 0x194 | `u8` | `m_field_194` | W | `EGlobal` |
| 0x198 | `u32` | `m_field_198` | W | `EGlobal` |
| 0x1A4 | `u8` | `m_field_1A4` | W | `EGlobal` |
| 0x1A5 | `u8[0x17B]` | _(gap)_ | - | - |
| 0x320 | `u32` | `m_field_320` | R | `AllocInstance` |
| 0x324 | `u32` | `m_field_324` | W | `EGlobal` |
| 0x328 | `u8` | `m_field_328` | W | `EGlobal` |
| 0x32C | `u8` | `m_field_32C` | W | `EGlobal` |
| 0x32D | `u8` | `m_field_32D` | W | `EGlobal` |
| 0x330 | `u32` | `m_field_330` | W | `EGlobal` |
| 0x334 | `u32` | `m_field_334` | W | `EGlobal` |
| 0x338 | `u32` | `m_field_338` | W | `EGlobal` |
| 0x33C | `u32` | `m_field_33C` | W | `EGlobal` |
| 0x340 | `u32` | `m_field_340` | W | `EGlobal` |
| 0x344 | `u32` | `m_field_344` | W | `EGlobal` |
| 0x348 | `u32` | `m_field_348` | W | `EGlobal` |
| 0x34C | `u32` | `m_field_34C` | W | `EGlobal` |
| 0x350 | `u32` | `m_field_350` | W | `EGlobal` |
| 0x354 | `u32` | `m_field_354` | W | `EGlobal` |
| 0x358 | `u32` | `m_field_358` | W | `EGlobal` |
| 0x35C | `u32` | `m_field_35C` | W | `EGlobal` |
| 0x360 | `u32` | `m_field_360` | W | `EGlobal` |
| 0x364 | `u32` | `m_field_364` | W | `EGlobal` |
| 0x368 | `u32` | `m_field_368` | W | `EGlobal` |
| 0x36C | `u32` | `m_field_36C` | W | `EGlobal` |
| 0x370 | `u32` | `m_field_370` | W | `EGlobal` |
| 0x374 | `u32` | `m_field_374` | W | `EGlobal` |
| 0x378 | `u32` | `m_field_378` | W | `EGlobal` |
| 0x37C | `u32` | `m_field_37C` | W | `EGlobal` |
| 0x380 | `u32` | `m_field_380` | W | `EGlobal` |
| 0x384 | `u8` | `m_field_384` | W | `EGlobal` |
| 0x388 | `u32` | `m_field_388` | W | `EGlobal` |
| 0x38C | `u32` | `m_field_38C` | W | `EGlobal` |
| 0x390 | `u32` | `m_field_390` | W | `EGlobal` |
| 0x394 | `u32` | `m_field_394` | W | `EGlobal` |
| 0x398 | `u32` | `m_field_398` | W | `EGlobal` |
| 0x39C | `u32` | `m_field_39C` | W | `EGlobal` |
| 0x3A0 | `u32` | `m_field_3A0` | W | `EGlobal` |
| 0x3A4 | `u32` | `m_field_3A4` | W | `EGlobal` |
| 0x3A8 | `u32` | `m_field_3A8` | W | `EGlobal` |
| 0x3AC | `f32` | `m_field_3AC` | W | `EGlobal` |
| 0x3B0 | `f32` | `m_field_3B0` | W | `EGlobal` |
| 0x3B4 | `u32` | `m_field_3B4` | W | `EGlobal` |
| 0x3B8 | `u32` | `m_field_3B8` | W | `EGlobal` |
| 0x3BC | `u32` | `m_field_3BC` | W | `EGlobal` |
| 0x3C0 | `u32` | `m_field_3C0` | W | `EGlobal` |
| 0x3C4 | `u32` | `m_field_3C4` | W | `EGlobal` |
| 0x3C8 | `u32` | `m_field_3C8` | W | `EGlobal` |
| 0x3CC | `u32` | `m_field_3CC` | W | `EGlobal` |
| 0x3D0 | `u32` | `m_field_3D0` | W | `EGlobal` |
| 0x3D4 | `u32` | `m_field_3D4` | W | `EGlobal` |
| 0x3D8 | `u32` | `m_field_3D8` | W | `EGlobal` |
| 0x3DC | `u32` | `m_field_3DC` | W | `EGlobal` |
| 0x3E0 | `u32` | `m_field_3E0` | W | `EGlobal` |
| 0x3E4 | `u32` | `m_field_3E4` | W | `EGlobal` |
| 0x3E8 | `u32` | `m_field_3E8` | W | `EGlobal` |
| 0x3EC | `u32` | `m_field_3EC` | W | `EGlobal` |
| 0x3F0 | `u32` | `m_field_3F0` | W | `EGlobal` |
| 0x3F4 | `u32` | `m_field_3F4` | W | `EGlobal` |
| 0x3F8 | `u32` | `m_field_3F8` | W | `EGlobal` |
| 0x3FC | `u32` | `m_field_3FC` | W | `EGlobal` |
| 0x400 | `u32` | `m_field_400` | W | `EGlobal` |
| 0x404 | `u32` | `m_field_404` | W | `EGlobal` |
| 0x408 | `u32` | `m_field_408` | W | `EGlobal` |
| 0x40C | `u32` | `m_field_40C` | W | `EGlobal` |
| 0x418 | `u32` | **`m_defaults_418`** | R/W | `EGlobal`, `SetDefaults` |
| 0x41C | `u32` | `m_field_41C` | W | `EGlobal` |
| 0x420 | `u32` | `m_field_420` | W | `EGlobal` |
| 0x424 | `u32` | `m_field_424` | W | `EGlobal` |
| 0x428 | `u32` | `m_field_428` | W | `EGlobal` |
| 0x42C | `u32` | `m_field_42C` | W | `EGlobal` |
| 0x430 | `u32` | `m_field_430` | W | `EGlobal` |
| 0x434 | `u32` | `m_field_434` | W | `EGlobal` |
| 0x438 | `u32` | `m_field_438` | W | `EGlobal` |
| 0x43C | `u32` | `m_field_43C` | W | `EGlobal` |
| 0x440 | `u32` | `m_field_440` | W | `EGlobal` |
| 0x448 | `u32` | `m_field_448` | W | `EGlobal` |
| 0x44C | `u32` | `m_field_44C` | W | `EGlobal` |
| 0x450 | `u32` | **`m_defaults_450`** | W | `EGlobal`, `Reset`, `SetDefaults` |
| 0x454 | `u32` | **`m_defaults_454`** | W | `EGlobal`, `Reset`, `SetDefaults` |
| 0x45C | `u32` | `m_field_45C` | W | `EGlobal` |
| 0x460 | `u32` | `m_field_460` | W | `EGlobal` |
| 0x464 | `u32` | `m_field_464` | W | `EGlobal` |
| 0x468 | `u32` | `m_field_468` | W | `EGlobal` |
| 0x46C | `u32` | `m_field_46C` | W | `EGlobal` |
| 0x470 | `u32` | `m_field_470` | W | `EGlobal` |
| 0x474 | `u32` | `m_field_474` | W | `EGlobal` |
| 0x478 | `u32` | `m_field_478` | W | `EGlobal` |
| 0x480 | `u32` | `m_field_480` | W | `EGlobal` |
| 0x484 | `u32` | `m_field_484` | W | `EGlobal` |
| 0x48C | `u32` | `m_field_48C` | W | `EGlobal` |
| 0x490 | `u32` | `m_field_490` | R/W | `EGlobal`, `LoadIntroRequirements`, `Reset` |
| 0x494 | `u8[0x1BC]` | _(gap)_ | - | - |
| 0x650 | `u32` | **`m_defaults_650`** | W | `SetDefaults` |

### `cXObjectImpl`

**Size:** >= 0x5C70 (23664 bytes) | **Fields:** 146 (22 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `f32` | **`m_prevObjectSibling`** | R/W | `AllowIdleOptimization`, `CalcDistance`, `CalcDistanceWithPentalties`, ... |
| 0x001 | `u8` | `m_field_001` | R | `TrySetMotiveDelta` |
| 0x002 | `s16` | `m_field_002` | R/W | `PostLoad`, `TryCheckObject`, `TrySetMotiveDelta`, ... |
| 0x003 | `u8` | `m_field_003` | R | `TrySetMotiveDelta` |
| 0x004 | `f32` | **`m_bIsVehicle`** | R/W | `AllowIdleOptimization`, `CalcDistance`, `CalcDistanceWithPentalties`, ... |
| 0x006 | `s16` | `m_field_006` | R/W | `InterpValue`, `PostLoad`, `TryRelationship2`, ... |
| 0x007 | `u8` | `m_field_007` | R | `InterpValue`, `TryIdle` |
| 0x008 | `f32` | `m_field_008` | R/W | `Initialize`, `InterpValue`, `ParseUIString`, ... |
| 0x00C | `u32` | `m_field_00C` | R/W | `HierGetObject`, `Initialize`, `InterpValue`, ... |
| 0x00E | `s16` | `m_field_00E` | R | `ReconStream` |
| 0x010 | `f32` | **`m_interactionLeader`** | R/W | `GetInteractionLeader`, `HierGetObject`, `Initialize`, ... |
| 0x012 | `s16` | **`m_bIsRoof`** | R | `IsRoof` |
| 0x014 | `f32` | **`m_bIsSpriteVisible`** | R/W | `HierGetObject`, `Initialize`, `InterpValue`, ... |
| 0x016 | `s16` | `m_field_016` | R/W | `InterpValue`, `TryCameraControl`, `TryCheckObject`, ... |
| 0x018 | `f32` | `m_field_018` | R/W | `ExtractContainedSims`, `Initialize`, `InterpValue`, ... |
| 0x01A | `s16` | `m_field_01A` | R | `TryGenericSimCall` |
| 0x01C | `f32` | **`m_slotHeight`** | R/W | `GetSlotHeight`, `Initialize`, `ReconSlots`, ... |
| 0x020 | `f32` | `m_field_020` | R | `TrySnap` |
| 0x024 | `f32` | `m_field_024` | R/W | `DayPassed`, `ParseUIString`, `TrySnap`, ... |
| 0x028 | `f32` | `m_field_028` | R | `Initialize`, `InterpValue`, `ParseUIString`, ... |
| 0x02C | `u32` | `m_field_02C` | R | `ParseUIString` |
| 0x030 | `f32` | `m_field_030` | R/W | `ParseUIString`, `TrySnap` |
| 0x034 | `f32` | `m_field_034` | R/W | `InterpValue`, `ParseUIString`, `TryCameraControl`, ... |
| 0x038 | `f32` | **`m_frontFaceDirection`** | R | `DayPassed`, `GetFrontFaceDirection`, `ParseUIString`, ... |
| 0x03C | `u32` | `m_field_03C` | R | `ParseUIString`, `TryGenericSimCall` |
| 0x044 | `u32` | `m_field_044` | R | `TryGenericSimCall` |
| 0x046 | `u16` | `m_field_046` | R | `DayPassed` |
| 0x048 | `s16` | `m_field_048` | R | `DayPassed`, `InterpValue` |
| 0x04A | `s16` | `m_field_04A` | R | `DayPassed` |
| 0x04C | `f32` | `m_field_04C` | R | `DayPassed`, `InterpValue`, `TryCameraControl` |
| 0x04E | `s16` | **`m_bIsFromCatalog`** | R | `IsFromCatalog` |
| 0x050 | `f32` | **`m_bIsFromCatalog_050`** | R | `IsFromCatalog`, `TryCameraControl` |
| 0x058 | `s16` | **`m_firstImpl`** | R/W | `CalcDistance`, `Cleanup`, `EnableSim`, ... |
| 0x05C | `s16` | `m_field_05C` | R/W | `HideForCutaway`, `cXObjectImpl` |
| 0x060 | `s16` | `m_field_060` | R/W | `InterpValue`, `ReconStream`, `TryGenericSimCall`, ... |
| 0x062 | `s16` | `m_field_062` | R | `Reset` |
| 0x064 | `s16` | `m_field_064` | R/W | `Cleanup`, `EnableSim`, `HierSetSite`, ... |
| 0x068 | `u32` | **`m_placementSpec`** | R/W | `CalcDistanceWithPentalties`, `CalcShortDistance`, `CalcShortDistanceIn16thsOfTiles`, ... |
| 0x06C | `u32` | **`m_placementSpec_06C`** | R | `CalcDistanceWithPentalties`, `CalcShortDistance`, `CalcShortDistanceIn16thsOfTiles`, ... |
| 0x070 | `u32` | `m_field_070` | R/W | `TestIntersection`, `cXObjectImpl` |
| 0x07C | `f32` | `m_field_07C` | R | `InterpValue` |
| 0x080 | `u32` | **`m_placementSpec_080`** | R/W | `GetPlacementSpec`, `HierGetSite`, `Pickup`, ... |
| 0x084 | `u32` | **`m_hilite`** | R/W | `SetHilite`, `cXObjectImpl` |
| 0x088 | `u32` | **`m_debugName`** | R/W | `ComputeRect`, `DayPassed`, `GetDebugName`, ... |
| 0x08A | `s16` | **`m_bIsFromCatalog_08A`** | R | `IsFromCatalog` |
| 0x08C | `u32` | **`m_frontFaceDirection_08C`** | R/W | `DayPassed`, `GetDebugName`, `GetFrontFaceDirection`, ... |
| 0x090 | `s16` | **`m_objectSlot`** | R/W | `GetObjectSlot`, `HierGetChild`, `Initialize`, ... |
| 0x094 | `u32` | `m_field_094` | R | `ReconStream`, `TryGenericSimCall` |
| 0x098 | `s16` | `m_field_098` | R | `TryGenericSimCall` |
| 0x0A0 | `s16` | `m_field_0A0` | R/W | `TryCallNamedTree`, `TryFindFunctionalObject`, `TryGenericSimCall`, ... |
| 0x0A4 | `u32` | `m_field_0A4` | R | `TryGenericSimCall`, `TrySnap` |
| 0x0A8 | `s16` | `m_field_0A8` | R | `TryGenericSimCall` |
| 0x0B0 | `u32` | `m_field_0B0` | R/W | `AllowIdleOptimization`, `Simulate`, `TrySetBalloon`, ... |
| 0x0B4 | `u32` | `m_field_0B4` | R | `AllowIdleOptimization`, `TrySetBalloon` |
| 0x0B6 | `u16` | `m_field_0B6` | R | `TestAndPlace` |
| 0x0B8 | `s16` | `m_field_0B8` | R | `InterpValue`, `TryCheckObject`, `TryGenericSimCall`, ... |
| 0x0BC | `u32` | `m_field_0BC` | R | `TryGenericSimCall` |
| 0x0C0 | `u32` | `m_field_0C0` | R/W | `TryGenericSimCall`, `cXObjectImpl` |
| 0x0C4 | `u32` | `m_field_0C4` | R/W | `ChangeSelectedSimR`, `cXObjectImpl` |
| 0x0C8 | `u8` | `m_field_0C8` | W | `cXObjectImpl` |
| 0x0CC | `u32` | `m_field_0CC` | W | `cXObjectImpl` |
| 0x0D0 | `f32` | `m_field_0D0` | W | `cXObjectImpl` |
| 0x0D4 | `f32` | `m_field_0D4` | W | `cXObjectImpl` |
| 0x0D8 | `s16` | `m_field_0D8` | R/W | `InterpValue`, `TryGenericSimCall`, `cXObjectImpl` |
| 0x0DA | `u16` | `m_field_0DA` | W | `cXObjectImpl` |
| 0x0DC | `u32` | **`m_syncObject`** | R/W | `Initialize`, `Reset`, `SetSyncObject`, ... |
| 0x0E0 | `f32` | **`m_syncObject_0E0`** | R/W | `Initialize`, `Reset`, `SetSyncObject`, ... |
| 0x0E4 | `u32` | **`m_syncObject_0E4`** | W | `Initialize`, `Reset`, `SetSyncObject`, ... |
| 0x0E8 | `s16` | `m_field_0E8` | R | `TryCameraControl`, `TryGenericSimCall`, `TrySnap` |
| 0x0EA | `s16` | `m_field_0EA` | R | `TryGenericSimCall` |
| 0x0EC | `u32` | `m_field_0EC` | R/W | `Cleanup`, `HandleError`, `PostLoad`, ... |
| 0x0F0 | `s16` | `m_field_0F0` | R | `TryMakeActionString` |
| 0x0F8 | `s16` | `m_field_0F8` | R | `TestAndPlace`, `TryFindGoodLocation` |
| 0x100 | `s16` | `m_field_100` | R | `TestIntersection`, `TryGenericSimCall` |
| 0x10C | `u32` | `m_field_10C` | W | `cXObjectImpl` |
| 0x110 | `s16` | `m_field_110` | R | `TryGenericSimCall`, `TrySnap` |
| 0x114 | `u32` | `m_field_114` | R/W | `TryGenericSimCall`, `TrySnap`, `cXObjectImpl` |
| 0x120 | `s16` | `m_field_120` | R | `ReconStream`, `TryGenericSimCall` |
| 0x124 | `u32` | `m_field_124` | R | `TryGenericSimCall` |
| 0x128 | `s16` | `m_field_128` | R | `TryGenericSimCall` |
| 0x12C | `u32` | `m_field_12C` | R | `TryGenericSimCall` |
| 0x130 | `s16` | `m_field_130` | R/W | `TryBurn`, `TryFindGoodLocation`, `TryGenericSimCall` |
| 0x134 | `u32` | `m_field_134` | R | `TryGenericSimCall` |
| 0x138 | `s16` | `m_field_138` | R | `TryFindGoodLocation`, `TryGenericSimCall` |
| 0x13C | `u32` | `m_field_13C` | R | `TryGenericSimCall` |
| 0x140 | `s16` | `m_field_140` | R | `TestIntersection`, `TryGenericSimCall` |
| 0x144 | `u32` | `m_field_144` | R | `TryGenericSimCall` |
| 0x148 | `s16` | `m_field_148` | R | `TryGenericSimCall` |
| 0x14C | `u32` | `m_field_14C` | R | `TryGenericSimCall` |
| 0x150 | `s16` | `m_field_150` | R | `TryGenericSimCall`, `TrySnap` |
| 0x154 | `u32` | `m_field_154` | R | `TryGenericSimCall`, `TrySnap` |
| 0x158 | `s16` | `m_field_158` | R | `TryGenericSimCall`, `TrySnap` |
| 0x15C | `u32` | `m_field_15C` | R | `TryGenericSimCall`, `TrySnap` |
| 0x160 | `s16` | `m_field_160` | R | `TryCameraControl`, `TryGenericSimCall` |
| 0x164 | `u32` | `m_field_164` | R | `TryGenericSimCall` |
| 0x168 | `s16` | `m_field_168` | R | `TryGenericSimCall` |
| 0x16C | `u32` | `m_field_16C` | R | `TryGenericSimCall` |
| 0x170 | `s16` | `m_field_170` | R | `TryGenericSimCall` |
| 0x174 | `u32` | `m_field_174` | R | `TryGenericSimCall` |
| 0x188 | `s16` | `m_field_188` | R | `TryGenericSimCall` |
| 0x18C | `u32` | `m_field_18C` | R | `TryGenericSimCall` |
| 0x198 | `s16` | `m_field_198` | R | `TryPlaySound` |
| 0x1A8 | `s16` | `m_field_1A8` | R | `TryGenericSimCall`, `TryRelationship`, `TryRelationship2` |
| 0x1AC | `u32` | `m_field_1AC` | R | `TryGenericSimCall` |
| 0x1B0 | `s16` | `m_field_1B0` | R | `TryGenericSimCall` |
| 0x1B4 | `u32` | `m_field_1B4` | R | `TryGenericSimCall` |
| 0x1B8 | `s16` | `m_field_1B8` | R | `TryGenericSimCall`, `TrySnap` |
| 0x1BC | `u32` | `m_field_1BC` | R | `TryGenericSimCall` |
| 0x1C0 | `u8[0x28]` | _(gap)_ | - | - |
| 0x1E8 | `s16` | `m_field_1E8` | R | `TryGenericSimCall` |
| 0x1EC | `u32` | `m_field_1EC` | R | `TryGenericSimCall` |
| 0x1F0 | `u8[0x20]` | _(gap)_ | - | - |
| 0x210 | `s16` | `m_field_210` | R | `TryGenericSimCall` |
| 0x214 | `u32` | `m_field_214` | R | `TryGenericSimCall` |
| 0x218 | `s16` | `m_field_218` | R | `TryGenericSimCall` |
| 0x21C | `u32` | `m_field_21C` | R | `TryGenericSimCall` |
| 0x228 | `s16` | `m_field_228` | R | `Cleanup` |
| 0x22A | `u8[0x26]` | _(gap)_ | - | - |
| 0x250 | `s16` | `m_field_250` | R | `TryFindGoodLocation` |
| 0x260 | `s16` | `m_field_260` | R | `TryFindGoodLocation`, `TryGenericSimCall`, `TrySnap` |
| 0x264 | `u32` | `m_field_264` | R | `TryFindGoodLocation`, `TryGenericSimCall`, `TrySnap` |
| 0x268 | `u8[0x40]` | _(gap)_ | - | - |
| 0x2A8 | `u32` | `m_field_2A8` | R | `InterpValue` |
| 0x2AC | `u32` | `m_field_2AC` | R | `InterpValue` |
| 0x2B8 | `s16` | `m_field_2B8` | R | `TryGenericSimCall`, `TrySnap` |
| 0x2BC | `u32` | `m_field_2BC` | R | `TryGenericSimCall`, `TrySnap` |
| 0x2C0 | `u8[0x58]` | _(gap)_ | - | - |
| 0x318 | `s16` | `m_field_318` | R | `TrySnap` |
| 0x31C | `u32` | `m_field_31C` | R | `TrySnap` |
| 0x320 | `u32` | `m_field_320` | R | `TryCameraControl`, `TryUpdate` |
| 0x328 | `s16` | `m_field_328` | R | `TrySnap` |
| 0x32C | `u32` | `m_field_32C` | R | `TrySnap` |
| 0x338 | `s16` | `m_field_338` | R | `TrySnap` |
| 0x33C | `u32` | `m_field_33C` | R | `TrySnap` |
| 0x340 | `s16` | `m_field_340` | R | `TrySnap` |
| 0x344 | `u32` | `m_field_344` | R | `TrySnap` |
| 0x350 | `s16` | `m_field_350` | R | `TryFindGoodLocation`, `TrySnap` |
| 0x354 | `u32` | `m_field_354` | R | `TryFindGoodLocation`, `TrySnap` |
| 0x358 | `u8[0x20]` | _(gap)_ | - | - |
| 0x378 | `s16` | `m_field_378` | R | `Cleanup` |
| 0x37C | `u32` | `m_field_37C` | R | `Cleanup` |
| 0x380 | `u8[0x58]` | _(gap)_ | - | - |
| 0x3D8 | `s16` | `m_field_3D8` | R | `TryGenericSimCall` |
| 0x3DC | `u32` | `m_field_3DC` | R | `TryGenericSimCall` |
| 0x3E0 | `u8[0x14]` | _(gap)_ | - | - |
| 0x3F4 | `u32` | `m_field_3F4` | R | `TryParticleEffect`, `TrySnap` |
| 0x3F8 | `u8[0x90]` | _(gap)_ | - | - |
| 0x488 | `s16` | **`m_placementSpec_488`** | R | `GetContainer`, `GetPlacementSpec`, `InterpValue`, ... |
| 0x48C | `u32` | `m_field_48C` | R | `TryFindGoodLocation`, `TryGenericSimCall`, `TrySnap` |
| 0x490 | `u8[0x90]` | _(gap)_ | - | - |
| 0x520 | `s16` | `m_field_520` | R | `TryGenericSimCall`, `TrySnap` |
| 0x524 | `u32` | `m_field_524` | R | `TryGenericSimCall`, `TrySnap` |
| 0x528 | `u8[0x18]` | _(gap)_ | - | - |
| 0x540 | `u16` | `m_field_540` | W | `TryNotifyStackObject` |
| 0x542 | `u8[0xFA]` | _(gap)_ | - | - |
| 0x63C | `u32` | `m_field_63C` | R | `TryCameraControl` |
| 0x640 | `u8[0x558C]` | _(gap)_ | - | - |
| 0x5BCC | `u32` | `m_field_5BCC` | R | `TryGenericSimCall` |
| 0x5BD0 | `u8[0x9C]` | _(gap)_ | - | - |
| 0x5C6C | `u32` | `m_field_5C6C` | R | `TryGenericSimCall` |

### `ENgcRenderer`

**Size:** >= 0x4668 (18024 bytes) | **Fields:** 119 (33 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `void**` | **`_vtable` (vtable pointer)** | R/W | `CreateGXDisplayList`, `ENgcRenderer`, `GetCurrentRenderMode`, ... |
| 0x001 | `u8` | `m_field_001` | W | `InitData` |
| 0x002 | `u8` | `m_field_002` | W | `InitData` |
| 0x003 | `u8` | `m_field_003` | W | `InitData` |
| 0x004 | `f32` | **`m_currentRenderMode_004`** | R/W | `ENgcRenderer`, `GetCurrentRenderMode`, `InitData`, ... |
| 0x008 | `f32` | **`m_currentRenderMode_008`** | R/W | `ENgcRenderer`, `GetCurrentRenderMode`, `InitData`, ... |
| 0x00C | `f32` | **`m_currentRenderMode_00C`** | R/W | `ENgcRenderer`, `GetCurrentRenderMode`, `InitData`, ... |
| 0x010 | `u32` | **`m_currentRenderMode_010`** | R/W | `ENgcRenderer`, `GetCurrentRenderMode`, `UpdateLightingEquation` |
| 0x014 | `f32` | **`m_currentRenderMode_014`** | R/W | `ENgcRenderer`, `GetCurrentRenderMode`, `UpdateLightingEquation` |
| 0x018 | `f32` | `m_field_018` | W | `ENgcRenderer` |
| 0x01C | `u8` | `m_field_01C` | W | `ENgcRenderer` |
| 0x01D | `u8` | `m_field_01D` | W | `ENgcRenderer` |
| 0x01E | `u8` | `m_field_01E` | W | `ENgcRenderer` |
| 0x01F | `u8` | `m_field_01F` | W | `ENgcRenderer` |
| 0x020 | `u8` | `m_field_020` | W | `ENgcRenderer` |
| 0x021 | `u8` | `m_field_021` | W | `ENgcRenderer` |
| 0x022 | `u8` | `m_field_022` | W | `ENgcRenderer` |
| 0x023 | `u8` | `m_field_023` | W | `ENgcRenderer` |
| 0x024 | `u8` | `m_field_024` | R/W | `ENgcRenderer`, `MovieFrame` |
| 0x025 | `u8` | `m_field_025` | W | `ENgcRenderer` |
| 0x026 | `u16` | `m_field_026` | W | `ENgcRenderer` |
| 0x028 | `u32` | `m_field_028` | W | `ENgcRenderer`, `InitData` |
| 0x02C | `f32` | `m_field_02C` | R/W | `ENgcRenderer`, `InitData` |
| 0x030 | `u32` | `m_field_030` | W | `ENgcRenderer`, `InitData` |
| 0x034 | `u32` | `m_field_034` | W | `ENgcRenderer` |
| 0x038 | `u32` | `m_field_038` | W | `ENgcRenderer`, `InitData` |
| 0x03C | `u32` | `m_field_03C` | W | `ENgcRenderer`, `InitData` |
| 0x040 | `u32` | `m_field_040` | W | `InitData` |
| 0x044 | `u32` | `m_field_044` | W | `InitData` |
| 0x048 | `u32` | `m_field_048` | W | `InitData` |
| 0x04C | `u32` | `m_field_04C` | W | `InitData` |
| 0x050 | `u8[0x1C]` | _(gap)_ | - | - |
| 0x06C | `u8` | `m_field_06C` | W | `InitData` |
| 0x06D | `u8[0x2CB]` | _(gap)_ | - | - |
| 0x338 | `u32` | `m_field_338` | W | `ENgcRenderer` |
| 0x340 | `u32` | `m_field_340` | R/W | `CycleToNextFrameBuffer`, `EndFrame`, `InitVideo` |
| 0x34C | `u32` | `m_field_34C` | R/W | `CycleToNextFrameBuffer`, `ENgcRenderer`, `EndFrame`, ... |
| 0x350 | `u32` | `m_field_350` | R/W | `InitVideo` |
| 0x354 | `u32` | `m_field_354` | W | `InitVideo` |
| 0x358 | `u32` | `m_field_358` | R/W | `InitGX` |
| 0x35C | `u32` | `m_field_35C` | R/W | `Swap` |
| 0x360 | `u32` | **`m_clearColor`** | R/W | `ENgcRenderer`, `EndFrame`, `SetClearColor` |
| 0x364 | `u32` | `m_field_364` | R | `InitVideo` |
| 0x368 | `u16` | `m_field_368` | R | `EndFrame`, `InitGX`, `InitVideo`, ... |
| 0x36A | `u16` | `m_field_36A` | R | `EndFrame`, `InitGX`, `InitVideo`, ... |
| 0x36C | `u16` | `m_field_36C` | R | `InitVideo`, `ScrambleRect` |
| 0x372 | `u16` | `m_field_372` | R | `ClearRect`, `DirectRect`, `InitData`, ... |
| 0x374 | `u16` | `m_field_374` | R | `ClearRect`, `DirectRect`, `InitData`, ... |
| 0x37D | `u8` | `m_field_37D` | R | `EndFrame`, `RenderSurface` |
| 0x37E | `u8[0x18]` | _(gap)_ | - | - |
| 0x396 | `u32` | `m_field_396` | W | `InitVideo` |
| 0x3A0 | `u32` | **`m_shader`** | R/W | `ENgcRenderer`, `SetShader`, `UpdateTEVStages` |
| 0x3A3 | `u8` | **`m_tEVStages`** | R | `UpdateTEVStages` |
| 0x3A4 | `f32` | **`m_tEVStages_3A4`** | R/W | `InitData`, `UpdateTEVStages` |
| 0x3A8 | `u32` | `m_field_3A8` | W | `InitGX` |
| 0x3AC | `u8` | `m_field_3AC` | R/W | `EndFrame`, `InitData`, `InitVideo` |
| 0x3B0 | `u32` | **`m_clearColor_3B0`** | R/W | `EndFrame`, `InitData`, `InitVideo`, ... |
| 0x3B8 | `u32` | `m_field_3B8` | W | `InitData` |
| 0x3BC | `u8` | `m_field_3BC` | W | `InitData` |
| 0x3C0 | `u32` | `m_field_3C0` | W | `InitData` |
| 0x3C4 | `u32` | `m_field_3C4` | W | `InitData` |
| 0x3C8 | `u8` | `m_field_3C8` | W | `InitData` |
| 0x3D4 | `u8` | `m_field_3D4` | W | `InitData` |
| 0x3D5 | `u8[0xC3]` | _(gap)_ | - | - |
| 0x498 | `u32` | `m_field_498` | W | `WindowMatrix` |
| 0x49C | `u32` | `m_field_49C` | W | `WindowMatrix` |
| 0x4A0 | `u8[0x38]` | _(gap)_ | - | - |
| 0x4D8 | `u32` | **`m_geometryModes`** | R/W | `AlphaTest`, `ClearRect`, `DirectRect`, ... |
| 0x4DC | `u32` | `m_field_4DC` | R/W | `DirectRect`, `Execute`, `InitData`, ... |
| 0x4E0 | `u32` | `m_field_4E0` | R/W | `Execute` |
| 0x4E4 | `u8[0x2C]` | _(gap)_ | - | - |
| 0x510 | `u32` | **`m_geometryModes_510`** | R/W | `DirectRect`, `DisableGeometryModes`, `ENgcRenderer`, ... |
| 0x514 | `u32` | **`m_shader_514`** | R/W | `InitData`, `SetShader`, `UpdateTEVStages` |
| 0x518 | `f32` | **`m_shader_518`** | R/W | `ENgcRenderer`, `InitData`, `Material`, ... |
| 0x528 | `f32` | **`m_shader_528`** | R/W | `ENgcRenderer`, `InitData`, `Material`, ... |
| 0x538 | `f32` | **`m_shader_538`** | R/W | `ENgcRenderer`, `InitData`, `Material`, ... |
| 0x53C | `u8[0x28]` | _(gap)_ | - | - |
| 0x564 | `u8` | **`m_tEVStages_564`** | R | `UpdateTEVStages` |
| 0x565 | `u8` | **`m_tEVStages_565`** | R | `UpdateTEVStages` |
| 0x566 | `u8` | **`m_tEVStages_566`** | R | `UpdateTEVStages` |
| 0x567 | `u8` | **`m_tEVStages_567`** | R | `UpdateTEVStages` |
| 0x568 | `u8` | **`m_tEVStages_568`** | R | `UpdateTEVStages` |
| 0x569 | `u8[0x2B]` | _(gap)_ | - | - |
| 0x594 | `u32` | **`m_tEVStages_594`** | R | `UpdateTEVStages` |
| 0x5A4 | `u8` | **`m_tEVStages_5A4`** | R | `UpdateTEVStages` |
| 0x5A5 | `u8` | **`m_tEVStages_5A5`** | R | `UpdateTEVStages` |
| 0x5A6 | `u8` | **`m_tEVStages_5A6`** | R | `UpdateTEVStages` |
| 0x5A7 | `u8` | **`m_tEVStages_5A7`** | R | `UpdateTEVStages` |
| 0x5A8 | `u8` | **`m_tEVStages_5A8`** | R | `UpdateTEVStages` |
| 0x5A9 | `u8[0x1F]` | _(gap)_ | - | - |
| 0x5C8 | `u32` | `m_field_5C8` | R/W | `NgcGXDisplayList`, `NgcGXDisplayListInt`, `QuadList`, ... |
| 0x5CC | `u32` | `m_field_5CC` | R/W | `QuadList`, `SimpleSkinning`, `TriStripPacked`, ... |
| 0x5D0 | `u8[0x80]` | _(gap)_ | - | - |
| 0x650 | `f32` | **`m_lightingEquation`** | R/W | `InitData`, `Lights`, `UpdateLightingEquation` |
| 0x660 | `u32` | `m_field_660` | W | `InitData` |
| 0x66C | `u32` | `m_field_66C` | W | `InitData` |
| 0x678 | `u32` | `m_field_678` | W | `InitData` |
| 0x684 | `u32` | `m_field_684` | W | `InitData` |
| 0x690 | `u32` | `m_field_690` | W | `InitData` |
| 0x69C | `u32` | `m_field_69C` | W | `InitData` |
| 0x6A0 | `u8[0x2C]` | _(gap)_ | - | - |
| 0x6CC | `u32` | `m_field_6CC` | R/W | `InitData` |
| 0x6D0 | `u32` | `m_field_6D0` | R/W | `InitData` |
| 0x6D4 | `u32` | `m_field_6D4` | R/W | `InitData` |
| 0x6E8 | `u32` | `m_field_6E8` | W | `InitData` |
| 0x6F0 | `u8` | `m_field_6F0` | W | `InitData` |
| 0x6F1 | `u8[0x77]` | _(gap)_ | - | - |
| 0x768 | `u8` | **`m_lightingEquation_768`** | R/W | `InitData`, `Lights`, `UpdateLightingEquation` |
| 0x769 | `u8` | **`m_lightingEquation_769`** | R/W | `InitData`, `Lights`, `UpdateLightingEquation` |
| 0x76A | `u8[0x32]` | _(gap)_ | - | - |
| 0x79C | `u32` | `m_field_79C` | W | `InitData` |
| 0x7A0 | `u8[0x214]` | _(gap)_ | - | - |
| 0x9B4 | `f32` | `m_field_9B4` | W | `InitData` |
| 0x9B8 | `f32` | `m_field_9B8` | W | `InitData` |
| 0x9C0 | `f32` | `m_field_9C0` | W | `InitData` |
| 0x9C8 | `u32` | `m_field_9C8` | W | `InitData` |
| 0x9D0 | `u32` | `m_field_9D0` | W | `InitData` |
| 0x9D4 | `u8[0x1330]` | _(gap)_ | - | - |
| 0x1D04 | `f32` | `m_field_1D04` | R | `InitData` |
| 0x1D08 | `f64` | `m_field_1D08` | R | `InitData` |
| 0x1D10 | `u8[0xE30]` | _(gap)_ | - | - |
| 0x2B40 | `u32` | `m_field_2B40` | R | `InitData` |
| 0x2B44 | `u8[0x1A2C]` | _(gap)_ | - | - |
| 0x4570 | `u32` | `m_field_4570` | W | `ModelMatrices` |
| 0x4574 | `u8[0xC0]` | _(gap)_ | - | - |
| 0x4634 | `u8` | **`m_texture`** | R/W | `InitData`, `SetTexture` |
| 0x4638 | `u32` | `m_field_4638` | R | `DirectRect`, `MovieFrame`, `NgcScreenTriList`, ... |
| 0x463C | `u32` | **`m_tEVStages_463C`** | R | `UpdateTEVStages` |
| 0x4644 | `u8` | `m_field_4644` | W | `ZTest` |
| 0x4645 | `u8` | `m_field_4645` | W | `ZTest` |
| 0x4646 | `u8` | `m_field_4646` | W | `ZTest` |
| 0x4648 | `u32` | `m_field_4648` | W | `BeginFrame` |
| 0x464C | `u32` | `m_field_464C` | W | `InitVideo` |
| 0x4650 | `u32` | `m_field_4650` | R/W | `EndFrame`, `InitVideo` |
| 0x465C | `u32` | `m_field_465C` | R/W | `InitData`, `ParticleListBegin`, `ParticleListEnd` |
| 0x4660 | `u32` | `m_field_4660` | W | `ParticleListBegin` |
| 0x4664 | `u32` | `m_field_4664` | W | `ParticleListBegin` |

### `E3DWindow`

**Size:** >= 0x348 (840 bytes) | **Fields:** 118 (33 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `f32` | **`m_orthoProjectionForUIHD`** | R | `CalcViewport`, `CalcViewportInv`, `SetOrthoProjectionForUIHD`, ... |
| 0x004 | `f32` | **`m_orthoProjectionForUIHD_004`** | R/W | `MakeLineOnPlane`, `ProjectToZPlane`, `SetOrthoProjectionForUIHD`, ... |
| 0x008 | `f32` | **`m_orthoProjectionForUIHD_008`** | R/W | `CalcTextureProjection`, `MakeLineOnPlane`, `ProjectToZPlane`, ... |
| 0x00C | `f32` | **`m_orthoProjectionForUIHD_00C`** | R/W | `CalcTextureProjection`, `SetOrthoProjectionForUIHD` |
| 0x010 | `u32` | **`m_orthoProjectionForUIHD_010`** | R/W | `CalcTextureProjection`, `SetOrthoProjectionForUIHD` |
| 0x014 | `f32` | **`m_orthoProjectionForUIHD_014`** | R/W | `CalcTextureProjection`, `CalcViewport`, `CalcViewportInv`, ... |
| 0x018 | `u32` | **`m_orthoProjectionForUIHD_018`** | R/W | `CalcTextureProjection`, `SetOrthoProjectionForUIHD` |
| 0x01C | `u32` | **`m_orthoProjectionForUIHD_01C`** | R/W | `CalcTextureProjection`, `SetOrthoProjectionForUIHD` |
| 0x020 | `u32` | **`m_orthoProjectionForUIHD_020`** | R/W | `CalcTextureProjection`, `SetOrthoProjectionForUIHD` |
| 0x024 | `u32` | **`m_orthoProjectionForUIHD_024`** | R/W | `CalcTextureProjection`, `SetOrthoProjectionForUIHD` |
| 0x028 | `u32` | **`m_orthoProjectionForUIHD_028`** | R/W | `CalcTextureProjection`, `SetOrthoProjectionForUIHD` |
| 0x02C | `u32` | **`m_orthoProjectionForUIHD_02C`** | R/W | `CalcTextureProjection`, `SetOrthoProjectionForUIHD` |
| 0x030 | `f32` | **`m_orthoProjectionForUIHD_030`** | R/W | `CalcTextureProjection`, `CalcViewport`, `CalcViewportInv`, ... |
| 0x034 | `f32` | **`m_orthoProjectionForUIHD_034`** | R/W | `CalcTextureProjection`, `CalcViewport`, `CalcViewportInv`, ... |
| 0x038 | `u32` | **`m_orthoProjectionForUIHD_038`** | R/W | `CalcTextureProjection`, `SetOrthoProjectionForUIHD` |
| 0x03C | `u32` | **`m_orthoProjectionForUIHD_03C`** | R/W | `CalcTextureProjection`, `SetOrthoProjectionForUIHD` |
| 0x040 | `f32` | `m_field_040` | R | `E3DWindow` |
| 0x050 | `f32` | `m_field_050` | R | `E3DWindow`, `Select` |
| 0x060 | `f32` | `m_field_060` | R | `CalcViewportStructures` |
| 0x064 | `f32` | `m_field_064` | R | `CalcViewportStructures` |
| 0x068 | `f32` | `m_field_068` | R | `CalcViewportStructures` |
| 0x06C | `f32` | `m_field_06C` | R | `CalcViewportStructures` |
| 0x070 | `u8[0x2C]` | _(gap)_ | - | - |
| 0x09C | `u32` | `m_field_09C` | R/W | `E3DWindow`, `Select` |
| 0x0A0 | `u32` | **`m_lookAt`** | W | `SetLookAt` |
| 0x0A4 | `u32` | **`m_lookAt_0A4`** | W | `SetLookAt` |
| 0x0A8 | `u8[0x38]` | _(gap)_ | - | - |
| 0x0E0 | `f32` | **`m_3DQuadFromScreenTrapAtZ`** | R/W | `CalcViewportStructures`, `CornerToWorld`, `Get3DQuadFromScreenTrapAtZ`, ... |
| 0x0E4 | `u32` | **`m_lookAtPos`** | W | `SetLookAtPos` |
| 0x0F0 | `f32` | `m_field_0F0` | R | `TransformToWorld` |
| 0x100 | `f32` | `m_field_100` | R | `TransformToWorld` |
| 0x110 | `u32` | `m_field_110` | R | `LookAtMatrixChanged` |
| 0x120 | `u32` | `m_field_120` | R | `CalcTextureProjection` |
| 0x124 | `u32` | `m_field_124` | R | `CalcTextureProjection` |
| 0x128 | `u8[0x38]` | _(gap)_ | - | - |
| 0x160 | `u32` | **`m_orthoProjection`** | R/W | `CopyProjection`, `ProjectionMatrixChanged`, `SetOrthoProjection`, ... |
| 0x164 | `u32` | **`m_orthoProjection_164`** | R/W | `CopyProjection`, `ProjectionMatrixChanged`, `SetOrthoProjection`, ... |
| 0x168 | `u8[0x38]` | _(gap)_ | - | - |
| 0x1A0 | `u32` | `m_field_1A0` | W | `ProjectionMatrixChanged` |
| 0x1A4 | `u32` | `m_field_1A4` | W | `ProjectionMatrixChanged` |
| 0x1A8 | `u8[0x38]` | _(gap)_ | - | - |
| 0x1E0 | `f32` | **`m_orthoProjection_1E0`** | R/W | `SetOrthoProjection`, `SetOrthoProjectionForUIHD` |
| 0x1E4 | `u32` | **`m_orthoProjection_1E4`** | W | `SetOrthoProjection`, `SetOrthoProjectionForUIHD` |
| 0x1F0 | `f32` | **`m_orthoProjection_1F0`** | R/W | `SetOrthoProjection`, `SetOrthoProjectionForUIHD` |
| 0x1F4 | `u8[0x1C]` | _(gap)_ | - | - |
| 0x210 | `f32` | **`m_orthoProjection_210`** | R/W | `SetOrthoProjection`, `SetOrthoProjectionForUIHD` |
| 0x220 | `f32` | **`m_viewport`** | R/W | `CalcViewport`, `CalcViewportInv`, `E3DWindow`, ... |
| 0x224 | `f32` | `m_field_224` | R/W | `CalcViewport`, `CalcViewportInv` |
| 0x228 | `f32` | `m_field_228` | R/W | `CalcViewport`, `CalcViewportInv` |
| 0x22C | `f32` | `m_field_22C` | R/W | `CalcViewport`, `CalcViewportInv` |
| 0x230 | `f32` | `m_field_230` | R/W | `CalcViewport`, `CalcViewportInv`, `E3DWindow`, ... |
| 0x234 | `f32` | `m_field_234` | R/W | `CalcViewport`, `CalcViewportInv` |
| 0x238 | `f32` | `m_field_238` | R/W | `CalcViewport`, `CalcViewportInv` |
| 0x23C | `f32` | `m_field_23C` | R/W | `CalcViewport`, `CalcViewportInv` |
| 0x240 | `f32` | `m_field_240` | R | `BackCullTest`, `CalcViewportStructures`, `TransformToWorld` |
| 0x244 | `f32` | `m_field_244` | R | `BackCullTest`, `CalcViewportStructures`, `TransformToWorld` |
| 0x248 | `f32` | `m_field_248` | R | `CalcViewportStructures` |
| 0x250 | `f32` | `m_field_250` | R | `BackCullTest`, `CalcViewportStructures`, `TransformToWorld` |
| 0x254 | `f32` | `m_field_254` | R | `BackCullTest`, `CalcViewportStructures`, `TransformToWorld` |
| 0x258 | `f32` | `m_field_258` | R | `CalcViewportStructures` |
| 0x25C | `u8[0x24]` | _(gap)_ | - | - |
| 0x280 | `f32` | **`m_3DQuadFromScreenTrapAtZ_280`** | R/W | `CalcViewportStructures`, `CornerToWorld`, `Get3DQuadFromScreenTrapAtZ`, ... |
| 0x284 | `f32` | `m_field_284` | R | `CalcViewportStructures` |
| 0x288 | `f32` | `m_field_288` | R | `CalcViewportStructures`, `ProjectToZPlane` |
| 0x28C | `f32` | **`m_orthoProjection_28C`** | W | `CopyProjection`, `E3DWindow`, `SetOrthoProjection`, ... |
| 0x290 | `u32` | `m_field_290` | W | `LookAtMatrixChanged` |
| 0x29C | `f32` | **`m_orthoProjection_29C`** | W | `CopyProjection`, `E3DWindow`, `SetOrthoProjection`, ... |
| 0x2A0 | `f32` | `m_field_2A0` | R/W | `CalcViewportStructures`, `PinToFrustrum`, `Test`, ... |
| 0x2A4 | `f32` | `m_field_2A4` | R | `PinToFrustrum`, `Test`, `TestAsRect` |
| 0x2A8 | `f32` | `m_field_2A8` | R | `PinToFrustrum`, `Test` |
| 0x2AC | `f32` | `m_field_2AC` | R | `PinToFrustrum`, `Test`, `TestAsRect` |
| 0x2B0 | `f32` | `m_field_2B0` | R/W | `CalcViewportStructures`, `PinToFrustrum`, `Test`, ... |
| 0x2B4 | `f32` | `m_field_2B4` | R | `PinToFrustrum`, `Test`, `TestAsRect` |
| 0x2B8 | `f32` | `m_field_2B8` | R | `PinToFrustrum`, `Test` |
| 0x2BC | `f32` | `m_field_2BC` | R | `PinToFrustrum`, `Test`, `TestAsRect` |
| 0x2C0 | `f32` | `m_field_2C0` | R/W | `CalcViewportStructures`, `PinToFrustrum`, `Test`, ... |
| 0x2C4 | `f32` | `m_field_2C4` | R | `PinToFrustrum`, `Test`, `TestAsRect` |
| 0x2C8 | `f32` | `m_field_2C8` | R | `PinToFrustrum`, `Test` |
| 0x2CC | `f32` | `m_field_2CC` | R | `PinToFrustrum`, `Test`, `TestAsRect` |
| 0x2D0 | `f32` | `m_field_2D0` | R/W | `CalcViewportStructures`, `PinToFrustrum`, `Test`, ... |
| 0x2D4 | `f32` | `m_field_2D4` | R | `PinToFrustrum`, `Test`, `TestAsRect` |
| 0x2D8 | `f32` | `m_field_2D8` | R | `PinToFrustrum`, `Test` |
| 0x2DC | `f32` | `m_field_2DC` | R | `PinToFrustrum`, `Test`, `TestAsRect` |
| 0x2E0 | `f32` | `m_field_2E0` | R/W | `CalcViewportStructures`, `PinToFrustrum`, `Test` |
| 0x2E4 | `f32` | `m_field_2E4` | R | `PinToFrustrum`, `Test` |
| 0x2E8 | `f32` | `m_field_2E8` | R | `PinToFrustrum`, `Test` |
| 0x2EC | `f32` | `m_field_2EC` | R | `PinToFrustrum`, `Test` |
| 0x2F0 | `f32` | **`m_orthoProjection_2F0`** | R/W | `CopyProjection`, `PinToFrustrum`, `SetOrthoProjection`, ... |
| 0x2F4 | `f32` | **`m_orthoProjection_2F4`** | R/W | `CopyProjection`, `SetOrthoProjection`, `SetOrthoProjectionForUIHD`, ... |
| 0x2F8 | `f32` | **`m_orthoProjection_2F8`** | R/W | `CopyProjection`, `PinToFrustrum`, `SetOrthoProjection`, ... |
| 0x2FC | `u8` | `m_field_2FC` | R | `Test`, `TestAsRect` |
| 0x2FD | `u8` | `m_field_2FD` | R | `Test`, `TestAsRect` |
| 0x2FE | `u8` | `m_field_2FE` | R | `Test` |
| 0x2FF | `u8` | `m_field_2FF` | R | `Test`, `TestAsRect` |
| 0x300 | `u8` | `m_field_300` | R | `Test`, `TestAsRect` |
| 0x301 | `u8` | `m_field_301` | R | `Test` |
| 0x302 | `u8` | `m_field_302` | R | `Test`, `TestAsRect` |
| 0x303 | `u8` | `m_field_303` | R | `Test`, `TestAsRect` |
| 0x304 | `u8` | `m_field_304` | R | `Test` |
| 0x305 | `u8` | `m_field_305` | R | `Test`, `TestAsRect` |
| 0x306 | `u8` | `m_field_306` | R | `Test`, `TestAsRect` |
| 0x307 | `u8` | `m_field_307` | R | `Test` |
| 0x308 | `u8` | `m_field_308` | R | `Test` |
| 0x309 | `u8` | `m_field_309` | R | `Test` |
| 0x30A | `u8` | `m_field_30A` | R | `Test` |
| 0x30B | `u8` | `m_field_30B` | R | `Test`, `TestAsRect` |
| 0x30C | `u8` | `m_field_30C` | R | `Test`, `TestAsRect` |
| 0x30D | `u8` | `m_field_30D` | R | `Test` |
| 0x30E | `u8` | `m_field_30E` | R | `Test`, `TestAsRect` |
| 0x30F | `u8` | `m_field_30F` | R | `Test`, `TestAsRect` |
| 0x310 | `u8` | `m_field_310` | R | `Test` |
| 0x311 | `u8` | `m_field_311` | R | `Test`, `TestAsRect` |
| 0x312 | `u8` | `m_field_312` | R | `Test`, `TestAsRect` |
| 0x313 | `u8` | `m_field_313` | R | `Test` |
| 0x314 | `u8` | `m_field_314` | R | `Test`, `TestAsRect` |
| 0x315 | `u8` | `m_field_315` | R | `Test`, `TestAsRect` |
| 0x316 | `u8` | `m_field_316` | R | `Test` |
| 0x317 | `u8` | `m_field_317` | R | `Test` |
| 0x318 | `u8` | `m_field_318` | R | `Test` |
| 0x319 | `u8` | `m_field_319` | R | `Test` |
| 0x31C | `u32` | `m_field_31C` | R/W | `CalcViewportStructures`, `E3DWindow` |
| 0x320 | `f32` | `m_field_320` | R/W | `CalcViewportStructures` |
| 0x32C | `f32` | `m_field_32C` | R/W | `CalcViewportStructures` |
| 0x338 | `f32` | `m_field_338` | R/W | `CalcViewportStructures` |
| 0x344 | `f32` | `m_field_344` | R/W | `CalcViewportStructures` |

### `ACTTarget`

**Size:** >= 0x658 (1624 bytes) | **Fields:** 107 (15 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `u16` | **`m_localizable`** | R/W | `ACTTarget`, `AddAction`, `GetLocalizable`, ... |
| 0x004 | `u16` | **`m_variable`** | R/W | `ACTTarget`, `AddAction`, `CancelCurrentObject`, ... |
| 0x006 | `u8` | **`m_variable_006`** | W | `GetVariable` |
| 0x008 | `u32` | `m_field_008` | R/W | `ACTTarget`, `AddAction`, `Update`, ... |
| 0x00C | `u32` | `m_field_00C` | R/W | `ACTTarget`, `~ACTTarget` |
| 0x010 | `u32` | `m_field_010` | R/W | `ACTTarget`, `AddAction`, `Update`, ... |
| 0x014 | `u32` | `m_field_014` | R/W | `ACTTarget`, `AddAction`, `Update`, ... |
| 0x018 | `u32` | `m_field_018` | R/W | `ACTTarget`, `AddAction`, `Update`, ... |
| 0x01C | `u32` | `m_field_01C` | R/W | `ACTTarget`, `AddAction`, `PlaceItem`, ... |
| 0x020 | `u32` | `m_field_020` | R/W | `ACTTarget`, `~ACTTarget` |
| 0x024 | `u32` | `m_field_024` | R/W | `ACTTarget`, `~ACTTarget` |
| 0x028 | `u32` | `m_field_028` | W | `ACTTarget` |
| 0x038 | `u32` | **`m_interactionFromID`** | R/W | `ACTTarget`, `AddAction`, `GetInteractionFromID` |
| 0x03C | `u32` | **`m_bCancelCurrentObject`** | R | `CancelCurrentObject` |
| 0x044 | `u32` | `m_field_044` | R | `AddAction` |
| 0x048 | `u32` | `m_field_048` | W | `ACTTarget` |
| 0x058 | `u32` | `m_field_058` | R/W | `ACTTarget`, `~ACTTarget` |
| 0x068 | `u32` | `m_field_068` | R/W | `ACTTarget`, `~ACTTarget` |
| 0x078 | `u32` | `m_field_078` | W | `ACTTarget` |
| 0x07C | `u32` | `m_field_07C` | R/W | `ACTTarget`, `PlaceItem`, `~ACTTarget` |
| 0x080 | `u32` | `m_field_080` | W | `ACTTarget`, `~ACTTarget` |
| 0x084 | `u8[0x38]` | _(gap)_ | - | - |
| 0x0BC | `f32` | `m_field_0BC` | R/W | `ACTTarget` |
| 0x0C4 | `f32` | `m_field_0C4` | R/W | `ACTTarget` |
| 0x0CC | `u32` | **`m_variable_0CC`** | R/W | `ACTTarget`, `GetVariable`, `Update` |
| 0x0D0 | `u32` | **`m_variable_0D0`** | R/W | `ACTTarget`, `SetVariable`, `Update` |
| 0x0D4 | `u32` | **`m_variable_0D4`** | R/W | `ACTTarget`, `SetVariable`, `Update` |
| 0x0D8 | `u32` | **`m_bCancelModeEnabled`** | R/W | `ACTTarget`, `CancelModeEnabled`, `Update` |
| 0x0DC | `u32` | **`m_interactionFromID_0DC`** | R/W | `ACTTarget`, `AddAction`, `CancelModeEnabled`, ... |
| 0x0E0 | `u32` | `m_field_0E0` | R/W | `ACTTarget`, `Update` |
| 0x0E4 | `u32` | **`m_bCancelModeEnabled_0E4`** | R/W | `ACTTarget`, `AddAction`, `CancelModeEnabled`, ... |
| 0x0E8 | `u32` | **`m_bCancellingLastObject`** | R/W | `ACTTarget`, `CancellingLastObject`, `PlaceItem`, ... |
| 0x0EC | `u8[0x24]` | _(gap)_ | - | - |
| 0x110 | `u32` | `m_field_110` | W | `ACTTarget` |
| 0x114 | `u32` | `m_field_114` | W | `ACTTarget` |
| 0x118 | `u32` | `m_field_118` | W | `ACTTarget` |
| 0x11C | `u32` | `m_field_11C` | W | `ACTTarget` |
| 0x120 | `u8[0x3C]` | _(gap)_ | - | - |
| 0x15C | `u32` | `m_field_15C` | W | `ACTTarget` |
| 0x160 | `u32` | `m_field_160` | W | `ACTTarget` |
| 0x164 | `u32` | `m_field_164` | W | `ACTTarget` |
| 0x168 | `u32` | `m_field_168` | W | `ACTTarget` |
| 0x16C | `u8[0x3C]` | _(gap)_ | - | - |
| 0x1A8 | `u32` | `m_field_1A8` | W | `ACTTarget` |
| 0x1AC | `u32` | `m_field_1AC` | W | `ACTTarget` |
| 0x1B0 | `u32` | `m_field_1B0` | W | `ACTTarget` |
| 0x1B4 | `u32` | `m_field_1B4` | W | `ACTTarget` |
| 0x1B8 | `u8[0x3C]` | _(gap)_ | - | - |
| 0x1F4 | `u32` | `m_field_1F4` | W | `ACTTarget` |
| 0x1F8 | `u32` | `m_field_1F8` | W | `ACTTarget` |
| 0x1FC | `u32` | `m_field_1FC` | W | `ACTTarget` |
| 0x200 | `u32` | `m_field_200` | W | `ACTTarget` |
| 0x204 | `u8[0x3C]` | _(gap)_ | - | - |
| 0x240 | `u32` | `m_field_240` | W | `ACTTarget` |
| 0x244 | `u32` | `m_field_244` | W | `ACTTarget` |
| 0x248 | `u32` | `m_field_248` | W | `ACTTarget` |
| 0x24C | `u32` | `m_field_24C` | W | `ACTTarget` |
| 0x250 | `u8[0x3C]` | _(gap)_ | - | - |
| 0x28C | `u32` | `m_field_28C` | W | `ACTTarget` |
| 0x290 | `u32` | `m_field_290` | W | `ACTTarget` |
| 0x294 | `u32` | `m_field_294` | W | `ACTTarget` |
| 0x298 | `u32` | `m_field_298` | W | `ACTTarget` |
| 0x29C | `u8[0x3C]` | _(gap)_ | - | - |
| 0x2D8 | `u32` | `m_field_2D8` | W | `ACTTarget` |
| 0x2DC | `u32` | `m_field_2DC` | W | `ACTTarget` |
| 0x2E0 | `u32` | `m_field_2E0` | W | `ACTTarget` |
| 0x2E4 | `u32` | `m_field_2E4` | W | `ACTTarget` |
| 0x2E8 | `u8[0x3C]` | _(gap)_ | - | - |
| 0x324 | `u32` | `m_field_324` | W | `ACTTarget` |
| 0x328 | `u32` | `m_field_328` | W | `ACTTarget` |
| 0x32C | `u32` | `m_field_32C` | W | `ACTTarget` |
| 0x330 | `u32` | `m_field_330` | W | `ACTTarget` |
| 0x334 | `u8[0x3C]` | _(gap)_ | - | - |
| 0x370 | `u32` | `m_field_370` | W | `ACTTarget` |
| 0x374 | `u32` | `m_field_374` | W | `ACTTarget` |
| 0x378 | `u32` | `m_field_378` | W | `ACTTarget` |
| 0x37C | `u32` | `m_field_37C` | W | `ACTTarget` |
| 0x380 | `u8[0x3C]` | _(gap)_ | - | - |
| 0x3BC | `u32` | `m_field_3BC` | W | `ACTTarget` |
| 0x3C0 | `u32` | `m_field_3C0` | W | `ACTTarget` |
| 0x3C4 | `u32` | `m_field_3C4` | W | `ACTTarget` |
| 0x3C8 | `u32` | `m_field_3C8` | W | `ACTTarget` |
| 0x3CC | `u8[0x3C]` | _(gap)_ | - | - |
| 0x408 | `u32` | `m_field_408` | W | `ACTTarget` |
| 0x40C | `u32` | `m_field_40C` | W | `ACTTarget` |
| 0x410 | `u32` | `m_field_410` | W | `ACTTarget` |
| 0x414 | `u32` | `m_field_414` | W | `ACTTarget` |
| 0x418 | `u8[0x3C]` | _(gap)_ | - | - |
| 0x454 | `u32` | `m_field_454` | W | `ACTTarget` |
| 0x458 | `u32` | `m_field_458` | W | `ACTTarget` |
| 0x45C | `u32` | `m_field_45C` | W | `ACTTarget` |
| 0x460 | `u32` | `m_field_460` | W | `ACTTarget` |
| 0x464 | `u8[0x3C]` | _(gap)_ | - | - |
| 0x4A0 | `u32` | `m_field_4A0` | W | `ACTTarget` |
| 0x4A4 | `u32` | `m_field_4A4` | W | `ACTTarget` |
| 0x4A8 | `u32` | `m_field_4A8` | W | `ACTTarget` |
| 0x4AC | `u32` | `m_field_4AC` | W | `ACTTarget` |
| 0x4B0 | `u8[0x3C]` | _(gap)_ | - | - |
| 0x4EC | `u32` | `m_field_4EC` | W | `ACTTarget` |
| 0x4F0 | `u32` | `m_field_4F0` | W | `ACTTarget` |
| 0x4F4 | `u32` | `m_field_4F4` | W | `ACTTarget` |
| 0x4F8 | `u32` | `m_field_4F8` | W | `ACTTarget` |
| 0x4FC | `u8[0x3C]` | _(gap)_ | - | - |
| 0x538 | `u32` | `m_field_538` | W | `ACTTarget` |
| 0x53C | `u32` | `m_field_53C` | W | `ACTTarget` |
| 0x540 | `u32` | `m_field_540` | W | `ACTTarget` |
| 0x544 | `u32` | `m_field_544` | W | `ACTTarget` |
| 0x548 | `u8[0x3C]` | _(gap)_ | - | - |
| 0x584 | `u32` | `m_field_584` | W | `ACTTarget` |
| 0x588 | `u32` | `m_field_588` | W | `ACTTarget` |
| 0x58C | `u32` | `m_field_58C` | W | `ACTTarget` |
| 0x590 | `u32` | `m_field_590` | W | `ACTTarget` |
| 0x594 | `u8[0x3C]` | _(gap)_ | - | - |
| 0x5D0 | `u32` | `m_field_5D0` | W | `ACTTarget` |
| 0x5D4 | `u32` | `m_field_5D4` | W | `ACTTarget` |
| 0x5D8 | `u32` | `m_field_5D8` | W | `ACTTarget` |
| 0x5DC | `u32` | `m_field_5DC` | W | `ACTTarget` |
| 0x5E0 | `u8[0x3C]` | _(gap)_ | - | - |
| 0x61C | `u32` | `m_field_61C` | W | `ACTTarget` |
| 0x620 | `u32` | `m_field_620` | W | `ACTTarget` |
| 0x624 | `u32` | `m_field_624` | W | `ACTTarget` |
| 0x628 | `u32` | `m_field_628` | W | `ACTTarget` |
| 0x62C | `u8[0x18]` | _(gap)_ | - | - |
| 0x644 | `u32` | **`m_bCancelModeEnabled_644`** | R/W | `ACTTarget`, `CancelCurrentObject`, `CancelModeEnabled`, ... |
| 0x648 | `u32` | **`m_bCancelModeEnabled_648`** | R/W | `ACTTarget`, `CancelCurrentObject`, `CancelModeEnabled`, ... |
| 0x64C | `u32` | **`m_bCancelModeEnabled_64C`** | R/W | `ACTTarget`, `CancelCurrentObject`, `CancelModeEnabled`, ... |
| 0x654 | `u32` | `m_field_654` | R | `RemoveAction` |

### `cXPersonImpl`

**Size:** >= 0x66B0 (26288 bytes) | **Fields:** 106 (21 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `s16` | **`m_dominantMemory`** | R/W | `ActionSkipped`, `AskOthersToMove`, `CalcHappy`, ... |
| 0x004 | `f32` | **`m_aspirationScore`** | R/W | `ActionSkipped`, `AddAction`, `AskOthersToMove`, ... |
| 0x008 | `f32` | `m_field_008` | R/W | `AskOthersToMove`, `Cleanup`, `GosubObjectTree`, ... |
| 0x00A | `s16` | **`m_bIsCarryingDCObject`** | R/W | `IsCarryingDCObject`, `ReconStream`, `Simulate` |
| 0x00C | `f32` | `m_field_00C` | R/W | `Cleanup`, `InitRoute`, `Initialize`, ... |
| 0x00E | `u16` | `m_field_00E` | R | `InitRoute` |
| 0x010 | `s16` | `m_field_010` | R/W | `Cleanup`, `Initialize`, `MoveOutOfWay`, ... |
| 0x014 | `f32` | `m_field_014` | R/W | `Cleanup`, `Initialize`, `MoveOutOfWay`, ... |
| 0x016 | `s16` | `m_field_016` | R | `TryFindBestAction` |
| 0x018 | `f32` | `m_field_018` | R/W | `Cleanup`, `Initialize`, `ReconStream`, ... |
| 0x01C | `f32` | `m_field_01C` | R/W | `Cleanup`, `InitRoute`, `Initialize`, ... |
| 0x020 | `u32` | `m_field_020` | R/W | `Initialize`, `TryFindBestAction` |
| 0x024 | `u32` | `m_field_024` | W | `Initialize` |
| 0x028 | `f32` | `m_field_028` | R/W | `AddAction`, `Initialize`, `Simulate` |
| 0x02C | `u32` | `m_field_02C` | R/W | `Cleanup`, `Initialize`, `TrySocialMode` |
| 0x030 | `f32` | `m_field_030` | W | `Initialize`, `Turn`, `UserCanPickup` |
| 0x032 | `u16` | `m_field_032` | W | `ReconStream` |
| 0x034 | `u16` | `m_field_034` | R/W | `InitRoute`, `Initialize`, `ReconStream` |
| 0x036 | `u16` | `m_field_036` | W | `ReconStream` |
| 0x038 | `u16` | **`m_bCancelLastAction`** | R/W | `CancelAllActions`, `CancelAllButLastActions`, `CancelLastAction`, ... |
| 0x03A | `u16` | `m_field_03A` | W | `ReconStream` |
| 0x03C | `u16` | **`m_bCancelLastAction_03C`** | R/W | `AddAction`, `CancelLastAction`, `Cleanup`, ... |
| 0x03E | `s16` | `m_field_03E` | R/W | `Simulate`, `TrySocialMode` |
| 0x040 | `s16` | `m_field_040` | R/W | `InitRoute`, `Initialize`, `~cXPersonImpl` |
| 0x042 | `s16` | `m_field_042` | R | `SimMotives` |
| 0x044 | `u16` | `m_field_044` | R/W | `Cleanup`, `Initialize` |
| 0x046 | `s16` | `m_field_046` | R | `Initialize`, `~cXPersonImpl` |
| 0x048 | `s16` | `m_field_048` | R/W | `Initialize`, `Reset`, `TryElement`, ... |
| 0x04A | `s16` | `m_field_04A` | R/W | `Cleanup`, `MoveOutOfWay`, `RemoveAction`, ... |
| 0x04C | `f32` | `m_field_04C` | R/W | `Initialize`, `Reset`, `TryElement`, ... |
| 0x04E | `s16` | `m_field_04E` | R/W | `Reset` |
| 0x050 | `u32` | `m_field_050` | R | `TryGotoRoutingSlot` |
| 0x052 | `u16` | `m_field_052` | W | `InitRoute`, `TryGotoRoutingSlot` |
| 0x054 | `s16` | **`m_currentAction`** | R/W | `TryGotoRoutingSlot`, `UpdateCurrentAction` |
| 0x056 | `u16` | **`m_currentAction_056`** | W | `TryGotoRoutingSlot`, `UpdateCurrentAction` |
| 0x058 | `f32` | **`m_socialModeTarget`** | R/W | `Cleanup`, `GetSocialModeTarget`, `Initialize`, ... |
| 0x05C | `f32` | `m_field_05C` | R/W | `Initialize`, `MoveOutOfWay`, `TryGotoRoutingSlot` |
| 0x05E | `s16` | `m_field_05E` | R | `TryGotoRoutingSlot` |
| 0x060 | `u32` | `m_field_060` | R/W | `Initialize`, `TryGotoRoutingSlot` |
| 0x064 | `u16` | `m_field_064` | R/W | `Initialize`, `TryGotoRoutingSlot`, `TryIdleAnimate`, ... |
| 0x066 | `s16` | `m_field_066` | R | `LoadMotiveEffects` |
| 0x068 | `u32` | `m_field_068` | R/W | `InitRoute`, `Initialize`, `TryGotoRoutingSlot`, ... |
| 0x06C | `u32` | `m_field_06C` | R/W | `InitRoute`, `TryGotoRoutingSlot`, `TryLookTowards` |
| 0x078 | `u32` | `m_field_078` | R | `TryGotoRoutingSlot` |
| 0x07C | `s16` | `m_field_07C` | R/W | `Initialize`, `ReconStream`, `Reset`, ... |
| 0x07E | `u16` | `m_field_07E` | W | `Cleanup` |
| 0x080 | `u32` | `m_field_080` | R | `TryFindBestAction` |
| 0x084 | `s16` | **`m_bIsMale`** | R/W | `AskOthersToMove`, `IsMale`, `MoveOutOfWay`, ... |
| 0x088 | `s16` | `m_field_088` | R/W | `Cleanup`, `ForceLocation`, `TryGotoRoutingSlot` |
| 0x08A | `s16` | `m_field_08A` | R/W | `Initialize`, `ReconStream`, `Reset` |
| 0x08C | `u32` | `m_field_08C` | R/W | `TryGotoRoutingSlot` |
| 0x090 | `u16` | `m_field_090` | R | `TryGotoRoutingSlot` |
| 0x096 | `s16` | **`m_currentAction_096`** | R/W | `Cleanup`, `ShouldInterrupt`, `UpdateCurrentAction` |
| 0x098 | `u16` | **`m_currentAction_098`** | R/W | `Cleanup`, `TryGotoRoutingSlot`, `UpdateCurrentAction` |
| 0x09A | `s16` | **`m_currentAction_09A`** | R/W | `TryGotoRoutingSlot`, `UpdateCurrentAction` |
| 0x09C | `u16` | **`m_bIsPersonDying`** | R/W | `IsPersonDying`, `TryGotoRoutingSlot` |
| 0x0A0 | `s16` | `m_field_0A0` | R | `MoveOutOfWay`, `TryFindBestAction`, `TrySocialMode` |
| 0x0A2 | `u8[0x12]` | _(gap)_ | - | - |
| 0x0B4 | `f32` | `m_field_0B4` | W | `CalcHappy` |
| 0x0BC | `f32` | `m_field_0BC` | R | `ShouldInterrupt` |
| 0x0C4 | `f32` | `m_field_0C4` | R | `ShouldInterrupt` |
| 0x0CC | `f32` | `m_field_0CC` | R | `ShouldInterrupt` |
| 0x0DC | `f32` | `m_field_0DC` | W | `Simulate` |
| 0x0EC | `u32` | `m_field_0EC` | R | `Cleanup` |
| 0x0F0 | `u8[0x38]` | _(gap)_ | - | - |
| 0x128 | `u32` | `m_field_128` | W | `cXPersonImpl` |
| 0x12C | `u32` | `m_field_12C` | R/W | `Simulate`, `cXPersonImpl` |
| 0x130 | `u8[0x150]` | _(gap)_ | - | - |
| 0x280 | `s16` | `m_field_280` | R | `MoveOutOfWay` |
| 0x284 | `u32` | `m_field_284` | R | `MoveOutOfWay` |
| 0x288 | `u8[0x20]` | _(gap)_ | - | - |
| 0x2A8 | `u32` | **`m_currentInteractionStackObject`** | R | `ActionSkipped`, `AddAction`, `Cleanup`, ... |
| 0x2AC | `u32` | **`m_bHasQueuedActionOfPri`** | R | `ActionSkipped`, `AddAction`, `Cleanup`, ... |
| 0x2B0 | `u8[0x134]` | _(gap)_ | - | - |
| 0x3E4 | `u32` | `m_field_3E4` | R/W | `ReconStream`, `Simulate`, `TrySetMotiveDelta`, ... |
| 0x3F4 | `u32` | `m_field_3F4` | R/W | `CheckFirstPlayerForFailedSocialModeEntry`, `CheckSecondPlayerForFailedSocialModeEntry`, `Cleanup`, ... |
| 0x3F8 | `u32` | `m_field_3F8` | R/W | `DumpDestList`, `InitRoute`, `TryGotoRoutingSlot`, ... |
| 0x3FC | `u32` | `m_field_3FC` | R | `InitRoute`, `TryGotoRoutingSlot` |
| 0x408 | `u32` | `m_field_408` | R/W | `Initialize`, `LoadMotiveEffects`, `TryFindBestAction`, ... |
| 0x40C | `u32` | `m_field_40C` | R/W | `AskOthersToMove`, `Cleanup`, `ReconStream`, ... |
| 0x410 | `u32` | `m_field_410` | R | `AskOthersToMove` |
| 0x41C | `u16` | **`m_currentRoom`** | R/W | `Simulate`, `UpdateCurrentRoom`, `cXPersonImpl` |
| 0x420 | `u32` | **`m_controllingObject`** | R/W | `Cleanup`, `GetControllingObject`, `GosubObjectTree`, ... |
| 0x424 | `u32` | **`m_controllingObject_424`** | R | `Cleanup`, `GetControllingObject` |
| 0x430 | `u32` | `m_field_430` | W | `cXPersonImpl` |
| 0x434 | `u32` | `m_field_434` | W | `cXPersonImpl` |
| 0x438 | `u32` | `m_field_438` | W | `cXPersonImpl` |
| 0x43C | `u32` | `m_field_43C` | W | `cXPersonImpl` |
| 0x440 | `u32` | `m_field_440` | W | `cXPersonImpl` |
| 0x444 | `u32` | `m_field_444` | W | `cXPersonImpl` |
| 0x448 | `u32` | `m_field_448` | W | `cXPersonImpl` |
| 0x44C | `u32` | `m_field_44C` | W | `cXPersonImpl` |
| 0x450 | `u16` | `m_field_450` | W | `cXPersonImpl` |
| 0x452 | `u16` | `m_field_452` | W | `cXPersonImpl` |
| 0x454 | `u8[0xD8]` | _(gap)_ | - | - |
| 0x52C | `u16` | `m_field_52C` | W | `cXPersonImpl` |
| 0x530 | `u32` | `m_field_530` | R/W | `Simulate`, `cXPersonImpl` |
| 0x534 | `u32` | **`m_currentAction_534`** | R/W | `AddAction`, `Cleanup`, `CompleteCurrentAction`, ... |
| 0x538 | `u32` | `m_field_538` | W | `cXPersonImpl` |
| 0x53C | `u32` | `m_field_53C` | W | `cXPersonImpl` |
| 0x540 | `s16` | `m_field_540` | R/W | `Initialize`, `Reset`, `TryIdleAnimate` |
| 0x544 | `u32` | `m_field_544` | W | `Initialize`, `Reset` |
| 0x548 | `u32` | **`m_secondPlayerInSocialMode`** | W | `Initialize`, `Reset`, `SetSecondPlayerInSocialMode` |
| 0x54C | `u32` | `m_field_54C` | W | `Initialize`, `Reset` |
| 0x550 | `u32` | `m_field_550` | W | `cXPersonImpl`, `~cXPersonImpl` |
| 0x554 | `u8[0x1C]` | _(gap)_ | - | - |
| 0x570 | `u32` | `m_field_570` | W | `cXPersonImpl` |
| 0x578 | `u32` | `m_field_578` | W | `cXPersonImpl` |
| 0x580 | `u32` | `m_field_580` | W | `cXPersonImpl` |
| 0x584 | `u8[0x40]` | _(gap)_ | - | - |
| 0x5C4 | `u32` | `m_field_5C4` | R/W | `cXPersonImpl` |
| 0x5C8 | `u32` | `m_field_5C8` | R/W | `cXPersonImpl` |
| 0x5CC | `u8[0x38]` | _(gap)_ | - | - |
| 0x604 | `u32` | **`m_normalSimDescription`** | R | `GetNormalSimDescription` |
| 0x608 | `u8[0x60A4]` | _(gap)_ | - | - |
| 0x66AC | `u32` | `m_field_66AC` | R | `AskOthersToMove` |

### `SAnimator2`

**Size:** >= 0x46F4 (18164 bytes) | **Fields:** 106 (22 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `f32` | **`m_engineFormatPos`** | R/W | `AddProp`, `DrawProps`, `Dress`, ... |
| 0x004 | `f32` | **`m_engineFormatPos_004`** | R/W | `AddProp`, `AttachParticleEffect`, `BeginFollow`, ... |
| 0x006 | `u8` | `m_field_006` | R | `TryAnimate` |
| 0x007 | `u8` | `m_field_007` | R | `TryAnimate` |
| 0x008 | `f32` | **`m_carryHandPosAndDir`** | R/W | `AddProp`, `BeginFollow`, `DetachMonitoredTrack`, ... |
| 0x00A | `s16` | `m_field_00A` | R | `updateCarryAnimation` |
| 0x00C | `u32` | `m_field_00C` | R/W | `BeginFollow`, `EnableWalkFade`, `FollowOneStep`, ... |
| 0x00D | `u8` | `m_field_00D` | W | `StartDefaultIdle`, `TryAnimate`, `endFollowDone`, ... |
| 0x010 | `f32` | **`m_bIsSimulatorControlled`** | R/W | `DrawCensor`, `EndFollow`, `FollowOneStep`, ... |
| 0x014 | `f32` | `m_field_014` | R/W | `BeginFollow`, `DrawCensor`, `EnableWalkFade`, ... |
| 0x018 | `f32` | **`m_turnRate`** | R/W | `BeginFollow`, `DrawCensor`, `EndFollow`, ... |
| 0x01C | `f32` | `m_field_01C` | R/W | `BeginFollow`, `FollowOneStep`, `SAnimator2`, ... |
| 0x020 | `f32` | `m_field_020` | R/W | `BeginFollow`, `DrawCensor`, `FollowOneStep`, ... |
| 0x024 | `f32` | `m_field_024` | R/W | `BeginFollow`, `DrawCensor`, `Initialize`, ... |
| 0x028 | `f32` | `m_field_028` | R/W | `BeginFollow`, `DrawCensor`, `Initialize`, ... |
| 0x02C | `u32` | **`m_turnRate_02C`** | R/W | `CheckOptionalMotionAnimStatusOnStateChange`, `GetTurnRate`, `SetNextStateFromCompletedTurn`, ... |
| 0x030 | `f32` | `m_field_030` | R/W | `BeginFollow`, `DrawCensor`, `FollowOneStep`, ... |
| 0x034 | `f32` | `m_field_034` | R/W | `DrawCensor`, `SAnimator2`, `positionCharacter`, ... |
| 0x038 | `f32` | `m_field_038` | R/W | `DrawCensor`, `SAnimator2`, `positionCharacter`, ... |
| 0x03C | `u32` | `m_field_03C` | R/W | `SAnimator2`, `UpdateNPCAutoRun`, `handleFreeMoveWalkRunAnimation`, ... |
| 0x048 | `u32` | `m_field_048` | W | `procBoneParticleEvt` |
| 0x04C | `u8[0x20]` | _(gap)_ | - | - |
| 0x06C | `u32` | `m_field_06C` | W | `startCarry`, `stopCarry`, `updateCarryAnimation` |
| 0x070 | `u8[0x1C]` | _(gap)_ | - | - |
| 0x08C | `u8` | `m_field_08C` | R | `setNewModel` |
| 0x098 | `f32` | **`m_turnRate_098`** | R/W | `GetTurnRate`, `SAnimator2`, `handleTurnAnimation`, ... |
| 0x09C | `f32` | **`m_movementVelocityFromStyle`** | R/W | `GetMovementVelocityFromStyle`, `SAnimator2`, `handleFreeMoveWalkRunAnimation`, ... |
| 0x0A0 | `f32` | **`m_movementVelocityFromStyle_0A0`** | R/W | `GetMovementVelocityFromStyle`, `SAnimator2`, `handleFreeMoveWalkRunAnimation`, ... |
| 0x0A4 | `f32` | `m_field_0A4` | R/W | `SAnimator2`, `handleSidestepAnimation`, `initSidestep`, ... |
| 0x0A8 | `f32` | **`m_movementVelocityFromStyle_0A8`** | R/W | `GetMovementVelocityFromStyle`, `SAnimator2`, `handleFreeMoveWalkRunAnimation`, ... |
| 0x0AC | `f32` | **`m_movementVelocityFromStyle_0AC`** | R/W | `GetMovementVelocityFromStyle`, `SAnimator2`, `handleFreeMoveWalkRunAnimation`, ... |
| 0x0B0 | `u32` | **`m_nextStateFromCompletedTurn`** | R/W | `SAnimator2`, `SetNextStateFromCompletedTurn`, `setAnimationState`, ... |
| 0x0B4 | `f32` | **`m_desiredFacing`** | R/W | `SAnimator2`, `SetDesiredFacing`, `awarenessMove`, ... |
| 0x0B8 | `f32` | `m_field_0B8` | R/W | `Reset`, `SAnimator2`, `handleFreeMoveWalkRunAnimation` |
| 0x0C8 | `u32` | `m_field_0C8` | R/W | `ReconStream`, `Reset`, `SAnimator2`, ... |
| 0x0CC | `u32` | `m_field_0CC` | R/W | `Reset`, `SAnimator2`, `TryAnimate`, ... |
| 0x0D0 | `f32` | `m_field_0D0` | R/W | `ReconStream`, `SAnimator2`, `StartDefaultIdle`, ... |
| 0x0D4 | `u32` | `m_field_0D4` | R/W | `Reset`, `SAnimator2`, `StartDefaultIdle`, ... |
| 0x0D8 | `u32` | `m_field_0D8` | R/W | `Reset`, `SAnimator2`, `TryAnimate`, ... |
| 0x0DC | `u32` | `m_field_0DC` | R/W | `DequeueAnimEvent`, `Reset`, `SAnimator2`, ... |
| 0x0E0 | `u32` | `m_field_0E0` | R/W | `Reset`, `SAnimator2`, `isAnimationDone` |
| 0x0EC | `u32` | `m_field_0EC` | R/W | `Reset`, `SAnimator2`, `TryAnimate` |
| 0x0F0 | `u32` | `m_field_0F0` | R/W | `ReconStream`, `SAnimator2`, `TryAnimate`, ... |
| 0x0F4 | `f32` | `m_field_0F4` | W | `SAnimator2` |
| 0x0F8 | `f32` | `m_field_0F8` | W | `SAnimator2` |
| 0x0FC | `f32` | **`m_idleAnimPlaybackParameters`** | R/W | `Initialize`, `SAnimator2`, `SetIdleAnimPlaybackParameters`, ... |
| 0x100 | `f32` | `m_field_100` | W | `SAnimator2`, `Update` |
| 0x104 | `f32` | `m_field_104` | R/W | `Initialize`, `SAnimator2`, `Update`, ... |
| 0x108 | `u32` | `m_field_108` | R/W | `BeginFollow`, `SAnimator2`, `UpdateNPCAutoRun`, ... |
| 0x10C | `u32` | `m_field_10C` | R/W | `BeginFollow`, `SAnimator2`, `determineWalkRunStyle`, ... |
| 0x110 | `f32` | `m_field_110` | R/W | `Initialize`, `SAnimator2`, `Update`, ... |
| 0x114 | `f32` | `m_field_114` | R/W | `Initialize`, `SAnimator2`, `exitAwarenessFollow`, ... |
| 0x118 | `u32` | `m_field_118` | R/W | `Initialize`, `SAnimator2`, `handleFreeMoveWalkRunAnimation`, ... |
| 0x11C | `u32` | `m_field_11C` | R/W | `Initialize`, `SAnimator2`, `UnloadPendingLongIdleAnim`, ... |
| 0x120 | `u32` | `m_field_120` | R/W | `SAnimator2`, `handleIdleAnimation` |
| 0x124 | `u32` | `m_field_124` | R/W | `SAnimator2`, `SelectAlgorithmicIdle`, `handleIdleAnimation` |
| 0x128 | `f32` | `m_field_128` | R/W | `SAnimator2`, `SelectAlgorithmicIdle`, `handleIdleAnimation` |
| 0x12C | `u32` | `m_field_12C` | W | `SAnimator2` |
| 0x130 | `u32` | `m_field_130` | R/W | `Reset`, `SAnimator2`, `TryChangeSuit`, ... |
| 0x134 | `f32` | **`m_bonePos`** | R/W | `GetBonePos`, `GetCarryHandPosAndDir`, `SAnimator2`, ... |
| 0x138 | `f32` | `m_field_138` | W | `SAnimator2` |
| 0x13C | `f32` | `m_field_13C` | W | `SAnimator2` |
| 0x140 | `f32` | **`m_carryHandPosAndDir_140`** | R/W | `GetCarryHandPosAndDir`, `SAnimator2`, `positionCharacter` |
| 0x144 | `f32` | `m_field_144` | W | `SAnimator2`, `positionCharacter` |
| 0x148 | `f32` | `m_field_148` | W | `SAnimator2`, `positionCharacter` |
| 0x14C | `f32` | **`m_bonePos_14C`** | R/W | `GetBonePos`, `SAnimator2`, `positionCharacter` |
| 0x150 | `f32` | `m_field_150` | R/W | `SAnimator2`, `wearNormal` |
| 0x154 | `f32` | `m_field_154` | R/W | `SAnimator2`, `wearNormal` |
| 0x158 | `f32` | **`m_bonePos_158`** | R/W | `GetBonePos`, `SAnimator2`, `positionCharacter` |
| 0x15C | `f32` | `m_field_15C` | W | `SAnimator2` |
| 0x160 | `f32` | `m_field_160` | W | `SAnimator2` |
| 0x164 | `s16` | `m_field_164` | R/W | `Initialize`, `SAnimator2`, `startCarry`, ... |
| 0x168 | `u32` | `m_field_168` | R/W | `AddProp`, `DrawProps`, `DrawPropsShadow`, ... |
| 0x16C | `u32` | `m_field_16C` | R/W | `PropsHaveAlpha`, `ReconStream`, `Undress`, ... |
| 0x178 | `u32` | `m_field_178` | R/W | `Initialize`, `SAnimator2`, `handleMoodAnimations` |
| 0x17C | `u32` | `m_field_17C` | R/W | `DrawCensor`, `SAnimator2`, `updateCensor` |
| 0x180 | `u8[0x30]` | _(gap)_ | - | - |
| 0x1B0 | `u32` | `m_field_1B0` | R | `positionCharacter` |
| 0x1C0 | `f32` | `m_field_1C0` | W | `SAnimator2`, `handleWalkRunAnimation` |
| 0x1C4 | `u32` | `m_field_1C4` | W | `SAnimator2`, `handleWalkRunAnimation` |
| 0x1C8 | `u32` | `m_field_1C8` | R/W | `BeginFollow`, `SAnimator2`, `followMiddleUpdate`, ... |
| 0x1CC | `u32` | `m_field_1CC` | W | `EndFollow`, `SAnimator2`, `TryAnimate` |
| 0x1D0 | `u8[0x118]` | _(gap)_ | - | - |
| 0x2E8 | `s16` | `m_field_2E8` | R | `resolveSkillForPrimitive` |
| 0x2EC | `u32` | `m_field_2EC` | R | `resolveSkillForPrimitive` |
| 0x2F0 | `u8[0x88]` | _(gap)_ | - | - |
| 0x378 | `u32` | `m_field_378` | R | `TryAnimate` |
| 0x37C | `u8[0x24]` | _(gap)_ | - | - |
| 0x3A0 | `u32` | `m_field_3A0` | R | `TryAnimate` |
| 0x3A4 | `u32` | `m_field_3A4` | R | `TryAnimate` |
| 0x3A8 | `u8[0xE0]` | _(gap)_ | - | - |
| 0x488 | `s16` | `m_field_488` | R | `resolveSkillForPrimitive` |
| 0x48C | `u32` | `m_field_48C` | R | `resolveSkillForPrimitive` |
| 0x490 | `u8[0x140]` | _(gap)_ | - | - |
| 0x5D0 | `u32` | `m_field_5D0` | R | `updateParticles` |
| 0x5DC | `u32` | `m_field_5DC` | R | `updateParticles` |
| 0x5E8 | `u32` | `m_field_5E8` | W | `Initialize`, `SAnimator2`, `isAnimationDone`, ... |
| 0x5EC | `u32` | `m_field_5EC` | R/W | `Initialize`, `ReconStream`, `SAnimator2`, ... |
| 0x5F0 | `u32` | `m_field_5F0` | R/W | `Initialize`, `ReconStream`, `SAnimator2`, ... |
| 0x5F4 | `u32` | `m_field_5F4` | R/W | `ReconStream`, `SAnimator2`, `Update` |
| 0x5F8 | `u8` | **`m_turnRate_5F8`** | R/W | `BeginFollow`, `EnableWalkFade`, `GetTurnRate`, ... |
| 0x5F9 | `u8` | `m_field_5F9` | R/W | `BeginFollow`, `Initialize`, `LoadDCOptionalMotionAnims`, ... |
| 0x5FA | `u8` | `m_field_5FA` | R/W | `Initialize`, `LoadOptionalIdleAnim`, `SAnimator2`, ... |
| 0x5FB | `u8` | `m_field_5FB` | R/W | `SAnimator2`, `StartDefaultIdle`, `UnloadPendingLongIdleAnim`, ... |
| 0x5FC | `u32` | `m_field_5FC` | R/W | `EndFollow`, `SAnimator2`, `UpdatePortalMode`, ... |
| 0x600 | `u32` | `m_field_600` | R/W | `EndAutoRun`, `EndFollow`, `StartAutoRun`, ... |
| 0x604 | `u32` | `m_field_604` | R/W | `ReconStream`, `SAnimator2`, `setNewModel`, ... |
| 0x608 | `f32` | **`m_desiredFacing_608`** | R/W | `Initialize`, `SAnimator2`, `SetDesiredFacing`, ... |
| 0x60C | `u32` | **`m_carryHandPosAndDir_60C`** | R/W | `GetCarryHandPosAndDir`, `Initialize`, `positionCharacter` |
| 0x61C | `u32` | **`m_bIsSimulatorControlled_61C`** | R/W | `Initialize`, `IsSimulatorControlled`, `LoadDCOptionalMotionAnims`, ... |
| 0x620 | `u32` | `m_field_620` | R | `awarenessMove`, `handleIdleAnimation`, `handleSkillIdleAnimation`, ... |
| 0x630 | `u32` | `m_field_630` | R | `updateRenderModels` |
| 0x634 | `u8[0x34]` | _(gap)_ | - | - |
| 0x668 | `u32` | `m_field_668` | R/W | `DetachMonitoredTrack`, `EndFollow`, `SAnimator2`, ... |
| 0x66C | `u8[0x4084]` | _(gap)_ | - | - |
| 0x46F0 | `f32` | `m_field_46F0` | R | `TryAnimate` |

### `InteractorModule`

**Size:** >= 0x60C (1548 bytes) | **Fields:** 98 (7 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `f32` | **`m_visibleSideOfWall`** | R/W | `CanObjectBeDestroyed`, `ClampPosToWorld`, `ConvertVertsToTiles`, ... |
| 0x002 | `u32` | `m_field_002` | R/W | `PlacementObject::CreateGridTile` |
| 0x004 | `f32` | **`m_bIsLegalToPlaceMultiTileAtLocation`** | R/W | `CanObjectBeDestroyed`, `CheckNewSimInSocialMode`, `ClampPosToWorld`, ... |
| 0x007 | `u8` | `m_field_007` | R | `PlacementObject::Rotate` |
| 0x008 | `f32` | **`m_objectPosition`** | R/W | `ConvertVertsToTiles`, `DirectInteractor::ExecuteActionMenu`, `DirectInteractor::InitPlayerPos`, ... |
| 0x00C | `f32` | **`m_cursorIntersectionObjects`** | R/W | `DirectInteractor::OnCommandPressed`, `DirectInteractor::UpdateObjectHighlights`, `FloorPainter::CancelSession`, ... |
| 0x010 | `f32` | `m_field_010` | R/W | `DirectInteractor::CancelQueuedActions`, `DirectInteractor::InitPlayerPos`, `DirectInteractor::OnCommandPressed`, ... |
| 0x014 | `f32` | `m_field_014` | R/W | `FloorPainter::OnStart`, `Interactor::Moved`, `InteractorInputManager::InstanceData::CloseSession`, ... |
| 0x016 | `s16` | `m_field_016` | R | `ObjectManipulator::Update` |
| 0x017 | `u8` | `m_field_017` | R | `ObjectManipulator::Update` |
| 0x018 | `f32` | **`m_objectInstancesList`** | R/W | `GetObjectInstancesList`, `InteractorInputManager::InstanceData::CloseSession`, `InteractorInputManager::InstanceData::OpenSession`, ... |
| 0x01C | `u32` | `m_field_01C` | R/W | `InteractorInputManager::InstanceData::CloseSession`, `InteractorInputManager::InstanceData::OpenSession`, `InteractorInputManager::InstanceData::Update`, ... |
| 0x020 | `f32` | `m_field_020` | R/W | `DirectInteractor::Update`, `FloorPainter::CurrentSelectionIsValid`, `FloorPainter::GetSelectedRectPoints`, ... |
| 0x024 | `f32` | `m_field_024` | R/W | `FloorPainter::CurrentSelectionIsValid`, `FloorPainter::GetSelectedRectPoints`, `FloorPainter::PaintRoom`, ... |
| 0x028 | `u32` | `m_field_028` | R/W | `InteractorResourceSet::AddTexture`, `InteractorResourceSet::ClearSet`, `InteractorResourceSet::GetTexture`, ... |
| 0x02C | `f32` | `m_field_02C` | R/W | `DirectInteractor::InitPlayerPos`, `DirectInteractor::OnCommandPressed`, `DirectInteractor::ResetIdleTime`, ... |
| 0x030 | `f32` | `m_field_030` | R/W | `DirectInteractor::ExecuteActionMenu`, `DirectInteractor::OnCommandPressed`, `DirectInteractor::OnCommandReleased`, ... |
| 0x034 | `f32` | `m_field_034` | R/W | `DirectInteractor::InterpretFreeMoveInput`, `DirectInteractor::OnCommandReleased`, `DirectInteractor::ParseControls`, ... |
| 0x038 | `f32` | `m_field_038` | R/W | `DirectInteractor::OnCommandReleased`, `DirectInteractor::ParseControls`, `FloorPainter::OnCommandReleased`, ... |
| 0x03C | `f32` | `m_field_03C` | R/W | `DirectInteractor::OnCommandPressed`, `DirectInteractor::OnCommandReleased`, `DirectInteractor::ParseControls`, ... |
| 0x040 | `f32` | `m_field_040` | R/W | `DirectInteractor::OnCommandReleased`, `DirectInteractor::ParseControls`, `FloorPainter::OnCommandReleased`, ... |
| 0x044 | `u32` | `m_field_044` | R/W | `DirectInteractor::InterpretFreeMoveInput`, `DirectInteractor::ParseControls`, `Interactor::ResetInputState`, ... |
| 0x048 | `f32` | `m_field_048` | R/W | `DirectInteractor::ParseControls`, `DirectInteractor::ShouldHighlightObject`, `Interactor::ResetInputState`, ... |
| 0x04C | `f32` | `m_field_04C` | R/W | `DirectInteractor::ShouldHighlightObject`, `InteractorResourceSet::AddShader`, `InteractorResourceSet::ClearSet`, ... |
| 0x050 | `f32` | `m_field_050` | W | `FloorPainter::OnCreate`, `InteractorVisualizer::DrawPreviewOnAffectedWalls`, `InteractorVisualizer::DrawWallpaperRectPreview`, ... |
| 0x054 | `f32` | `m_field_054` | W | `FloorPainter::OnCreate`, `ObjectManipulator::OnStart`, `WallManipulator::OnCreate`, ... |
| 0x058 | `f32` | `m_field_058` | R/W | `DirectInteractor::ResetIdleTime`, `DirectInteractor::Update` |
| 0x05C | `u32` | `m_field_05C` | R/W | `DirectInteractor::DirectInteractor`, `DirectInteractor::ExecuteActionMenu`, `DirectInteractor::ExecuteObjectActionMenu`, ... |
| 0x060 | `f32` | `m_field_060` | R/W | `FloorPainter::CurrentSelectionIsValid`, `FloorPainter::HandleActionCmdInPlaceMode`, `FloorPainter::HandleActionCmdInRemoveMode`, ... |
| 0x064 | `f32` | `m_field_064` | R/W | `DirectInteractor::DirectInteractor`, `DirectInteractor::Update`, `DirectInteractor::UpdateControlStatus`, ... |
| 0x068 | `f32` | `m_field_068` | R/W | `DirectInteractor::InitPlayerPos`, `DirectInteractor::OnStart`, `DirectInteractor::Update`, ... |
| 0x06C | `u32` | `m_field_06C` | R/W | `DirectInteractor::OnCommandPressed`, `DirectInteractor::OnStart`, `DirectInteractor::Update`, ... |
| 0x070 | `f32` | `m_field_070` | R/W | `DirectInteractor::CancelQueuedActions`, `DirectInteractor::DirectInteractor`, `DirectInteractor::ExecuteActionMenu`, ... |
| 0x074 | `f32` | `m_field_074` | R/W | `DirectInteractor::DirectInteractor`, `DirectInteractor::ShouldHighlightObject`, `InteractorVisualizer::Draw`, ... |
| 0x078 | `u32` | `m_field_078` | R/W | `DirectInteractor::DirectInteractor`, `DirectInteractor::InitPlayerPos`, `DirectInteractor::OnStart`, ... |
| 0x07C | `u32` | `m_field_07C` | R/W | `DirectInteractor::DirectInteractor`, `DirectInteractor::InitPlayerPos`, `FloorPainter::CurrentSelectionIsValid`, ... |
| 0x080 | `u32` | `m_field_080` | R/W | `DirectInteractor::DirectInteractor`, `DirectInteractor::ExecuteObjectActionMenu`, `DirectInteractor::ResetIdleTime`, ... |
| 0x084 | `f32` | `m_field_084` | R/W | `FloorPainter::OnStart`, `WallPainter::AdjustCursorPosition`, `WallPainter::OnStart`, ... |
| 0x088 | `u32` | `m_field_088` | R/W | `WallManipulator::CommittTransaction`, `WallManipulator::WallManipulator`, `WallManipulator::~WallManipulator`, ... |
| 0x090 | `u32` | `m_field_090` | R/W | `FloorPainter::OnStart`, `FloorPainter::~FloorPainter`, `WallPainter::CountWallsInRoomSelection`, ... |
| 0x094 | `u32` | `m_field_094` | R/W | `FloorPainter::OnStart`, `FloorPainter::OnStop`, `WallPainter::CommittTransaction`, ... |
| 0x098 | `f32` | `m_field_098` | R/W | `FloorPainter::CurrentSelectionIsValid`, `FloorPainter::OnCommandPressed`, `FloorPainter::PaintFloor`, ... |
| 0x09C | `u32` | `m_field_09C` | R/W | `FloorPainter::OnCommandPressed`, `FloorPainter::OnStart`, `WallPainter::CommittTransaction`, ... |
| 0x0A0 | `f32` | `m_field_0A0` | R/W | `FloorPainter::CancelSession`, `FloorPainter::HandleActionCmdInRemoveMode`, `FloorPainter::OnCommandPressed`, ... |
| 0x0A4 | `f32` | `m_field_0A4` | R/W | `FloorPainter::CancelSession`, `FloorPainter::CurrentSelectionIsValid`, `FloorPainter::OnCommandPressed`, ... |
| 0x0A8 | `u32` | `m_field_0A8` | R/W | `FloorPainter::FloorPainter`, `FloorPainter::Update`, `FloorPainter::~FloorPainter`, ... |
| 0x0AC | `u32` | `m_field_0AC` | W | `GrabManipulator::GrabManipulator`, `InteractorManager::CreatePlayerInteractorSets`, `InteractorVisualizer::InteractorOrderTableCallback`, ... |
| 0x0B0 | `u32` | `m_field_0B0` | W | `DirectInteractor::InterpretFreeMoveInput`, `DirectInteractor::OnCommandPressed`, `DirectInteractor::ResetIdleTime`, ... |
| 0x0B4 | `f32` | `m_field_0B4` | R/W | `DirectInteractor::InterpretFreeMoveInput`, `DirectInteractor::SendNeutralFreeMoveInput`, `InteractorVisualizer::InteractorOrderTableCallback` |
| 0x0B8 | `f32` | `m_field_0B8` | R/W | `DirectInteractor::SetVelocityModifiers`, `FloorPainter::FloorPainter`, `FloorPainter::HandleActionCmdInPlaceMode`, ... |
| 0x0BC | `u32` | `m_field_0BC` | R/W | `GrabManipulator::OnStart`, `PlaceManipulator::StartPlacement`, `WallPainter::OnStart`, ... |
| 0x0C0 | `f32` | `m_field_0C0` | R/W | `GrabManipulator::OnStart`, `InteractorVisualizer::Draw`, `InteractorVisualizer::DrawPreviewOnAffectedWalls`, ... |
| 0x0C4 | `f32` | `m_field_0C4` | R/W | `GrabManipulator::OnStart`, `InteractorVisualizer::Draw`, `InteractorVisualizer::DrawPreviewOnAffectedWalls`, ... |
| 0x0C8 | `f32` | `m_field_0C8` | R/W | `DirectInteractor::ExecuteActionMenu`, `GrabManipulator::GrabManipulator`, `GrabManipulator::OnStart`, ... |
| 0x0CC | `s16` | `m_field_0CC` | R/W | `PlaceManipulator::StartPlacement`, `PlaceManipulator::TryPlacingCurrentObject`, `WallManipulator::ValidateWallSegment`, ... |
| 0x0D0 | `u32` | `m_field_0D0` | R/W | `PlaceManipulator::OnCommandPressed`, `WallManipulator::CheckForAffectedWalls`, `WallManipulator::CommittTransaction`, ... |
| 0x0D4 | `u32` | `m_field_0D4` | R/W | `WallManipulator::AddWallAtTile`, `WallManipulator::CanChangeTileAdd`, `WallManipulator::HandleDeleteLine`, ... |
| 0x0D8 | `u32` | `m_field_0D8` | W | `WallManipulator::OnStart` |
| 0x0DC | `u32` | `m_field_0DC` | W | `WallManipulator::OnStart` |
| 0x0E0 | `u32` | `m_field_0E0` | W | `WallManipulator::WallManipulator` |
| 0x0F0 | `f32` | `m_field_0F0` | R/W | `InteractorVisualizer::DrawPreviewOnAffectedWalls`, `InteractorVisualizer::DrawVerticalRect`, `InteractorVisualizer::DrawWallpaperPreviewOnAffectedWalls`, ... |
| 0x0F4 | `u32` | `m_field_0F4` | R | `WallManipulator::OnStart`, `WallManipulator::OnStop` |
| 0x0F8 | `u32` | `m_field_0F8` | R | `WallManipulator::OnStart` |
| 0x0FC | `u32` | `m_field_0FC` | R | `WallManipulator::OnStart` |
| 0x100 | `u32` | `m_field_100` | R | `WallManipulator::CommittTransaction`, `WallManipulator::OnStart` |
| 0x104 | `u32` | `m_field_104` | R/W | `WallManipulator::CommittTransaction`, `WallManipulator::OnStart` |
| 0x10C | `u32` | `m_field_10C` | W | `InteractorVisualizer::Draw`, `InteractorVisualizer::DrawResource`, `InteractorVisualizer::DrawSimpleResourceSet`, ... |
| 0x110 | `f32` | `m_field_110` | W | `InteractorVisualizer::Draw`, `InteractorVisualizer::DrawPreviewOnAffectedWalls`, `InteractorVisualizer::DrawResource`, ... |
| 0x114 | `f32` | `m_field_114` | W | `InteractorVisualizer::DrawPreviewOnAffectedWalls`, `InteractorVisualizer::DrawWallpaperRectPreview` |
| 0x120 | `u32` | `m_field_120` | R | `InteractorVisualizer::Draw` |
| 0x124 | `u8[0x3C]` | _(gap)_ | - | - |
| 0x160 | `u32` | `m_field_160` | R | `DirectInteractor::OnCommandPressed`, `SimInteractor::OnCommandPressed` |
| 0x164 | `u8[0x18]` | _(gap)_ | - | - |
| 0x17C | `u32` | `m_field_17C` | R/W | `SimInteractor::OnStart`, `SimInteractor::SimInteractor`, `SimInteractor::Update` |
| 0x180 | `f32` | `m_field_180` | R/W | `SimInteractor::GetBeamScale`, `SimInteractor::OnStart`, `SimInteractor::SimInteractor`, ... |
| 0x184 | `f32` | `m_field_184` | W | `SimInteractor::SimInteractor`, `SimInteractor::Update` |
| 0x188 | `u32` | `m_field_188` | R/W | `SimInteractor::OnCommandPressed`, `SimInteractor::OnCommandReleased`, `SimInteractor::OnStart`, ... |
| 0x18C | `u32` | `m_field_18C` | W | `SimInteractor::ImmediatelyCutCursorAndCameraToPos`, `SimInteractor::SimInteractor` |
| 0x190 | `u32` | `m_field_190` | R/W | `SimInteractor::ReturnPlumbBobToOwner`, `SimInteractor::SimInteractor` |
| 0x194 | `u32` | `m_field_194` | R/W | `SimInteractor::OnStart`, `SimInteractor::Update` |
| 0x198 | `u32` | `m_field_198` | W | `SimInteractor::OnStart` |
| 0x19C | `u32` | `m_field_19C` | R/W | `SimInteractor::OnStart`, `SimInteractor::OnStop`, `SimInteractor::ReturnPlumbBobToOwner`, ... |
| 0x1A0 | `u8[0x30]` | _(gap)_ | - | - |
| 0x1D0 | `f32` | `m_field_1D0` | R/W | `SimInteractor::SimInteractor`, `SimInteractor::UpdateOverlapIntersection` |
| 0x1D8 | `f32` | `m_field_1D8` | R/W | `SimInteractor::Update`, `SimInteractor::UpdateOverlapIntersection` |
| 0x1DC | `f32` | `m_field_1DC` | R/W | `SimInteractor::SimInteractor`, `SimInteractor::UpdateOverlapIntersection` |
| 0x1E0 | `f32` | `m_field_1E0` | W | `SimInteractor::SimInteractor`, `SimInteractor::UpdateOverlapIntersection` |
| 0x1EC | `f32` | `m_field_1EC` | R/W | `SimInteractor::SimInteractor`, `SimInteractor::UpdateOverlapIntersection` |
| 0x1F8 | `f32` | `m_field_1F8` | W | `SimInteractor::SimInteractor`, `SimInteractor::UpdateOverlapIntersection` |
| 0x204 | `f32` | `m_field_204` | W | `SimInteractor::SimInteractor` |
| 0x214 | `u32` | `m_field_214` | R/W | `SimInteractor::OnCommandReleased`, `SimInteractor::OnStart`, `SimInteractor::Update` |
| 0x218 | `u32` | `m_field_218` | W | `SimInteractor::OnStart` |
| 0x224 | `u32` | `m_field_224` | W | `SimInteractor::OnStart`, `SimInteractor::SimInteractor`, `SimInteractor::UpdateOverlapIntersection` |
| 0x228 | `u32` | `m_field_228` | W | `SimInteractor::OnStart`, `SimInteractor::SimInteractor` |
| 0x238 | `u32` | `m_field_238` | R | `DirectInteractor::OnCommandPressed`, `SimInteractor::OnCommandPressed` |
| 0x23C | `u8[0xE4]` | _(gap)_ | - | - |
| 0x320 | `u32` | `m_field_320` | R | `InteractorVisualizer::Draw` |
| 0x324 | `u8[0x8C]` | _(gap)_ | - | - |
| 0x3B0 | `u32` | `m_field_3B0` | W | `WallManipulator::CheckForAffectedWalls` |
| 0x3BC | `u32` | `m_field_3BC` | R | `WallManipulator::FinalizePlacement`, `WallManipulator::FinalizeRoom`, `WallPainter::FinalizePaperForRoom`, ... |
| 0x3C0 | `u8[0x58]` | _(gap)_ | - | - |
| 0x418 | `f32` | **`m_visibleSideOfWall_418`** | R | `GetCameraRelativeStickAngle`, `GetVisibleSideOfWall`, `InteractorVisualizer::DrawResource` |
| 0x41C | `u8[0x20]` | _(gap)_ | - | - |
| 0x43C | `f32` | **`m_visibleSideOfWall_43C`** | R | `FloorPainter::OnStart`, `GetCameraRelativeStickAngle`, `GetVisibleSideOfWall`, ... |
| 0x440 | `u8[0x1C8]` | _(gap)_ | - | - |
| 0x608 | `f32` | `m_field_608` | W | `DirectInteractor::InterpretFreeMoveInput`, `DirectInteractor::SendNeutralFreeMoveInput` |

### `ESim`

**Size:** >= 0x648 (1608 bytes) | **Fields:** 97 (21 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `f32` | **`m_obCenter`** | R/W | `CensorOrderTableCallback`, `DeletePlayerCachedModel`, `Draw`, ... |
| 0x004 | `f32` | **`m_obCenter_004`** | R/W | `Draw`, `DrawSim`, `ESim`, ... |
| 0x008 | `f32` | **`m_obCenter_008`** | R/W | `ESim`, `GetObCenter`, `initModel` |
| 0x00C | `u32` | `m_field_00C` | W | `ESim` |
| 0x010 | `u32` | `m_field_010` | W | `ESim` |
| 0x014 | `u32` | **`m_ghostParticleEffect`** | R/W | `ESim`, `UpdateGhostParticleEffect` |
| 0x018 | `u32` | **`m_ghostParticleEffect_018`** | R/W | `ESim`, `UpdateGhostParticleEffect` |
| 0x01C | `u32` | `m_field_01C` | W | `ESim` |
| 0x020 | `u32` | `m_field_020` | W | `ESim` |
| 0x024 | `u32` | `m_field_024` | W | `ESim` |
| 0x034 | `u32` | `m_field_034` | W | `ESim` |
| 0x038 | `u8[0x1C]` | _(gap)_ | - | - |
| 0x054 | `f32` | `m_field_054` | W | `initModel` |
| 0x05C | `u32` | `m_field_05C` | R/W | `ESim`, `Update` |
| 0x060 | `f32` | `m_field_060` | W | `Update` |
| 0x064 | `f32` | `m_field_064` | W | `Update` |
| 0x068 | `u32` | `m_field_068` | R/W | `Draw`, `ESim` |
| 0x06C | `u32` | `m_field_06C` | W | `ESim` |
| 0x070 | `u32` | `m_field_070` | R | `Draw` |
| 0x074 | `u8[0x15]` | _(gap)_ | - | - |
| 0x089 | `u8` | `m_field_089` | R | `CompositeSkin` |
| 0x098 | `u32` | `m_field_098` | R | `CensorOrderTableCallback`, `PropOrderTableCallback`, `ServiceNpcOrderTableCallback`, ... |
| 0x0A8 | `u32` | `m_field_0A8` | W | `CensorOrderTableCallback`, `PropOrderTableCallback`, `ServiceNpcOrderTableCallback`, ... |
| 0x0AC | `u32` | `m_field_0AC` | W | `CensorOrderTableCallback`, `PropOrderTableCallback`, `ServiceNpcOrderTableCallback`, ... |
| 0x0B0 | `u32` | `m_field_0B0` | W | `SkillMeterOrderTableCallback` |
| 0x0B4 | `u32` | `m_field_0B4` | W | `CensorOrderTableCallback`, `PropOrderTableCallback`, `ServiceNpcOrderTableCallback`, ... |
| 0x0B8 | `u32` | `m_field_0B8` | W | `PropOrderTableCallback`, `SimOrderTableCallback`, `SkillMeterOrderTableCallback` |
| 0x0BC | `u8[0x5C]` | _(gap)_ | - | - |
| 0x118 | `u32` | `m_field_118` | R | `initModel` |
| 0x120 | `u32` | **`m_shadow`** | R/W | `UpdateShadow`, `initModel` |
| 0x124 | `u8[0x1FC]` | _(gap)_ | - | - |
| 0x320 | `u32` | `m_field_320` | W | `ESim`, `~ESim` |
| 0x328 | `u32` | `m_field_328` | W | `ESim` |
| 0x32C | `u32` | **`m_simAndNpcCommonItems`** | R | `DrawSimAndNpcCommonItems` |
| 0x330 | `u8[0xA0]` | _(gap)_ | - | - |
| 0x3D0 | `u32` | `m_field_3D0` | R/W | `CompositeSkin`, `CreateThumbnail`, `Draw`, ... |
| 0x3D4 | `u32` | `m_field_3D4` | W | `initModel` |
| 0x3D8 | `u32` | `m_field_3D8` | R/W | `CreateSkinAsync`, `ESim`, `RefreshSkin`, ... |
| 0x3E0 | `u32` | `m_field_3E0` | R/W | `ESim`, `Update`, `UpdateShadow`, ... |
| 0x3E4 | `u32` | `m_field_3E4` | W | `ESim` |
| 0x3E8 | `u32` | **`m_plumbBobState`** | R/W | `DrawPlumbBob`, `DrawSkillMeter`, `ESim`, ... |
| 0x3EC | `u32` | **`m_plumbBobState_3EC`** | R/W | `DrawPlumbBob`, `DrawSkillMeter`, `SetPlumbBobState`, ... |
| 0x3F0 | `f32` | **`m_skillMeter`** | R/W | `DrawSkillMeter`, `initModel` |
| 0x3F4 | `f32` | **`m_plumbBobState_3F4`** | R/W | `DrawPlumbBob`, `SetPlumbBobState`, `UpdateSkillMeter` |
| 0x404 | `u32` | **`m_ghostParticleEffect_404`** | R/W | `ESim`, `UpdateGhostParticleEffect` |
| 0x408 | `u32` | `m_field_408` | R/W | `DrawCursorHighLight`, `ESim`, `initModel`, ... |
| 0x40C | `u32` | `m_field_40C` | R/W | `DrawCursorHighLight`, `ESim`, `initModel`, ... |
| 0x410 | `u32` | `m_field_410` | R/W | `ESim`, `initModel`, `~ESim` |
| 0x414 | `u32` | `m_field_414` | W | `ESim` |
| 0x418 | `f32` | `m_field_418` | R/W | `DrawCursorHighLight`, `DrawSkillMeter`, `ESim` |
| 0x41C | `u32` | **`m_cursorHighLight`** | R/W | `DrawCursorHighLight`, `ESim` |
| 0x420 | `u32` | **`m_cursorHighLight_420`** | R/W | `DrawCursorHighLight`, `ESim` |
| 0x424 | `u32` | **`m_skinChange`** | R/W | `ESim`, `UpdateSkinChange` |
| 0x428 | `u32` | **`m_shadow_428`** | R/W | `Draw`, `DrawSim`, `UpdateShadow` |
| 0x42C | `u32` | `m_field_42C` | R/W | `DrawSimAndNpcCommonItems`, `ESim`, `initModel`, ... |
| 0x430 | `u32` | `m_field_430` | R/W | `DrawSimAndNpcCommonItems`, `ESim`, `UpdateShowerCurtain`, ... |
| 0x434 | `u32` | **`m_showerCurtain`** | R/W | `ESim`, `UpdateShowerCurtain`, `UpdateSkinChange` |
| 0x438 | `f32` | `m_field_438` | R/W | `DrawSimAndNpcCommonItems`, `ESim`, `UpdateShowerCurtain`, ... |
| 0x43C | `f32` | **`m_queuedOperation`** | R/W | `DrawSkillMeter`, `ESim`, `UpdateQueuedOperation` |
| 0x440 | `u32` | `m_field_440` | W | `ESim`, `initModel` |
| 0x444 | `u32` | `m_field_444` | W | `ESim`, `initModel` |
| 0x448 | `u32` | `m_field_448` | W | `ESim`, `initModel` |
| 0x44C | `u32` | `m_field_44C` | W | `ESim`, `initModel` |
| 0x450 | `u32` | `m_field_450` | R/W | `Draw` |
| 0x454 | `u32` | `m_field_454` | R/W | `Draw`, `ESim`, `Update`, ... |
| 0x458 | `u32` | `m_field_458` | W | `ESim`, `initModel` |
| 0x464 | `u32` | `m_field_464` | W | `ESim`, `initModel` |
| 0x478 | `u32` | `m_field_478` | W | `ESim`, `initModel` |
| 0x47C | `u32` | `m_field_47C` | W | `ESim`, `initModel` |
| 0x480 | `u32` | `m_field_480` | W | `ESim`, `initModel` |
| 0x484 | `u32` | `m_field_484` | W | `ESim`, `initModel` |
| 0x488 | `u32` | `m_field_488` | W | `Draw` |
| 0x48C | `u32` | `m_field_48C` | W | `ESim`, `initModel` |
| 0x490 | `u32` | `m_field_490` | W | `ESim`, `initModel` |
| 0x49C | `u32` | `m_field_49C` | W | `ESim`, `initModel` |
| 0x4B0 | `u32` | `m_field_4B0` | W | `ESim` |
| 0x4B4 | `u32` | `m_field_4B4` | W | `ESim` |
| 0x4B8 | `u32` | `m_field_4B8` | W | `ESim` |
| 0x4BC | `u32` | `m_field_4BC` | W | `ESim` |
| 0x4C0 | `u32` | `m_field_4C0` | W | `ESim` |
| 0x4C4 | `u32` | `m_field_4C4` | W | `ESim` |
| 0x4D4 | `u32` | `m_field_4D4` | W | `ESim` |
| 0x4E8 | `u32` | `m_field_4E8` | W | `ESim` |
| 0x4EC | `u32` | `m_field_4EC` | W | `ESim` |
| 0x4F0 | `u32` | `m_field_4F0` | W | `ESim` |
| 0x4F4 | `u32` | `m_field_4F4` | W | `ESim` |
| 0x4F8 | `u32` | `m_field_4F8` | R/W | `Draw` |
| 0x4FC | `u32` | `m_field_4FC` | R/W | `Draw`, `ESim` |
| 0x500 | `u32` | `m_field_500` | W | `ESim` |
| 0x50C | `u32` | `m_field_50C` | W | `ESim` |
| 0x520 | `u32` | **`m_skinChange_520`** | R/W | `ESim`, `UpdateQueuedOperation`, `UpdateSkinChange` |
| 0x524 | `u32` | `m_field_524` | W | `ESim`, `initModel` |
| 0x528 | `u32` | `m_field_528` | W | `Draw` |
| 0x52C | `u32` | `m_field_52C` | W | `ESim`, `initModel` |
| 0x530 | `u8[0xF8]` | _(gap)_ | - | - |
| 0x628 | `u32` | `m_field_628` | R/W | `ESim`, `~ESim` |
| 0x62C | `u32` | `m_field_62C` | W | `initModel` |
| 0x630 | `u32` | `m_field_630` | R/W | `CreateSkinAsync`, `ESim`, `RefreshSkin`, ... |
| 0x634 | `u32` | **`m_shadow_634`** | R/W | `Draw`, `UpdateShadow`, `initModel` |
| 0x638 | `u32` | `m_field_638` | R/W | `Draw`, `ESim`, `Update`, ... |
| 0x63C | `u32` | **`m_scaler`** | R/W | `ChangeCostume`, `CompositeSkin`, `CreateThumbnail`, ... |
| 0x640 | `u32` | `m_field_640` | R/W | `ESim`, `Update` |
| 0x644 | `u32` | `m_field_644` | R/W | `ESim`, `ReadModelFromCache`, `TransferModelToCache` |

### `CameraDirector`

**Size:** >= 0x44C (1100 bytes) | **Fields:** 90 (35 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `u32` | `m_field_000` | R | `CalcCancelCam`, `CalcSimsCam`, `InterpToGameCamera`, ... |
| 0x004 | `u32` | `m_field_004` | R | `CalcCancelCam`, `CalcSimsCam` |
| 0x008 | `u32` | `m_field_008` | R | `CalcCancelCam`, `CalcSimsCam` |
| 0x00C | `u32` | `m_field_00C` | R | `CalcCancelCam`, `CalcSimsCam` |
| 0x010 | `u32` | `m_field_010` | R | `CalcCancelCam`, `CalcSimsCam` |
| 0x014 | `u32` | `m_field_014` | R | `CalcCancelCam`, `CalcSimsCam` |
| 0x018 | `u32` | `m_field_018` | R | `CalcCancelCam`, `CalcSimsCam` |
| 0x01C | `u32` | `m_field_01C` | R | `CalcCancelCam`, `CalcSimsCam` |
| 0x020 | `u32` | `m_field_020` | R | `CalcCancelCam`, `CalcSimsCam` |
| 0x024 | `u32` | `m_field_024` | R | `CalcCancelCam`, `CalcSimsCam` |
| 0x028 | `u32` | `m_field_028` | R | `CalcCancelCam`, `CalcSimsCam` |
| 0x02C | `u32` | `m_field_02C` | R | `CalcCancelCam`, `CalcSimsCam` |
| 0x030 | `u32` | `m_field_030` | R | `CalcCancelCam`, `CalcSimsCam` |
| 0x034 | `u32` | `m_field_034` | R | `CalcCancelCam`, `CalcSimsCam` |
| 0x038 | `u32` | `m_field_038` | R | `CalcCancelCam`, `CalcSimsCam` |
| 0x03C | `u32` | `m_field_03C` | R | `CalcCancelCam`, `CalcSimsCam` |
| 0x040 | `f32` | **`m_cameraPosAndFOV`** | R | `UpdateCameraPosAndFOV` |
| 0x044 | `u8[0x1C]` | _(gap)_ | - | - |
| 0x060 | `f32` | `m_field_060` | R | `Interp` |
| 0x070 | `f32` | **`m_upInterpCamera`** | R | `Interp`, `SetUpInterpCamera` |
| 0x080 | `f32` | **`m_cameraInterp`** | R/W | `CalcCancelCam`, `CalcSimsCam`, `Interp`, ... |
| 0x084 | `u32` | **`m_cameraInterp_084`** | R/W | `CalcCancelCam`, `CalcSimsCam`, `SetCameraCut`, ... |
| 0x090 | `f32` | **`m_cameraCutAnim`** | R/W | `Interp`, `SetCameraCutAnim` |
| 0x0A0 | `f32` | **`m_cameraCutAnim_0A0`** | R/W | `Interp`, `SetCameraCutAnim` |
| 0x0B0 | `f32` | **`m_cameraCutAnim_0B0`** | R/W | `Interp`, `SetCameraCutAnim` |
| 0x0B4 | `f32` | **`m_cameraCutAnim_0B4`** | W | `SetCameraCutAnim` |
| 0x0B8 | `f32` | **`m_cameraCutAnim_0B8`** | W | `SetCameraCutAnim` |
| 0x0BC | `u8[0x44]` | _(gap)_ | - | - |
| 0x100 | `u32` | `m_field_100` | W | `InitSimsCamera` |
| 0x10C | `u32` | `m_field_10C` | W | `InitSimsCamera` |
| 0x118 | `u32` | **`m_cameraInterp_118`** | R/W | `AttachDummy`, `InitCurrentCamera`, `ReleaseCurrentCamera`, ... |
| 0x11C | `u32` | **`m_cameraInterp_11C`** | R/W | `AttachDummy`, `InitCurrentCamera`, `ReleaseCurrentCamera`, ... |
| 0x120 | `u8[0x40]` | _(gap)_ | - | - |
| 0x160 | `u32` | **`m_cameraInterp_160`** | R/W | `CalcCancelCam`, `CalcSimsCam`, `Draw`, ... |
| 0x164 | `u32` | `m_field_164` | R/W | `ReleaseCurrentCamera`, `Reset`, `StartAnim`, ... |
| 0x168 | `f32` | `m_field_168` | R/W | `StartAnim`, `Update` |
| 0x170 | `u32` | **`m_upInterpCamera_170`** | R/W | `AnimEventHandler`, `CalcCancelCam`, `CalcSimsCam`, ... |
| 0x174 | `f32` | `m_field_174` | R/W | `CalcCancelCam`, `CalcSimsCam`, `InitSimsCamera` |
| 0x178 | `f32` | `m_field_178` | R/W | `CalcCancelCam`, `CalcSimsCam`, `InitSimsCamera`, ... |
| 0x17C | `f32` | `m_field_17C` | R/W | `CalcCancelCam`, `CalcSimsCam`, `InitSimsCamera`, ... |
| 0x180 | `f32` | `m_field_180` | R/W | `CalcCancelCam`, `CalcSimsCam`, `InitSimsCamera`, ... |
| 0x184 | `f32` | `m_field_184` | R/W | `CalcCancelCam`, `CalcSimsCam`, `InitSimsCamera`, ... |
| 0x188 | `f32` | `m_field_188` | W | `InitSimsCamera` |
| 0x18C | `f32` | `m_field_18C` | R/W | `InitSimsCamera`, `Interp` |
| 0x190 | `f32` | **`m_upInterpCamera_190`** | R/W | `Interp`, `ReleaseCurrentCamera`, `Reset`, ... |
| 0x194 | `f32` | **`m_upInterpCamera_194`** | R/W | `Interp`, `ReleaseCurrentCamera`, `Reset`, ... |
| 0x198 | `u32` | **`m_upInterpCamera_198`** | R/W | `ReleaseCurrentCamera`, `Reset`, `SetUpInterpCamera`, ... |
| 0x19C | `f32` | **`m_upInterpCamera_19C`** | R/W | `Interp`, `SetUpInterpCamera` |
| 0x1A0 | `f32` | **`m_cameraInterp_1A0`** | R/W | `CalcCancelCam`, `CalcSimsCam`, `InitCurrentCamera`, ... |
| 0x1A4 | `u32` | `m_field_1A4` | W | `Reset`, `StartAnim` |
| 0x1A8 | `u8[0x24]` | _(gap)_ | - | - |
| 0x1CC | `u32` | **`m_cameraCutAnim_1CC`** | R | `SetCameraCutAnim`, `SetCameraInterpAnim`, `StartAnim` |
| 0x1D0 | `u8[0x50]` | _(gap)_ | - | - |
| 0x220 | `u32` | **`m_cameraInterp_220`** | R/W | `AttachDummy`, `InitCurrentCamera`, `ProcessPropertyEventTags`, ... |
| 0x224 | `f32` | `m_field_224` | R/W | `InitCurrentCamera`, `ProcessPropertyEventTags`, `ReleaseCurrentCamera`, ... |
| 0x228 | `f32` | `m_field_228` | R/W | `InitCurrentCamera`, `ProcessPropertyEventTags`, `ReleaseCurrentCamera`, ... |
| 0x22C | `f32` | **`m_cameraInterp_22C`** | R/W | `AttachDummy`, `InitCurrentCamera`, `InterpToCancelCamera`, ... |
| 0x230 | `u32` | **`m_cameraInterp_230`** | R/W | `AttachDummy`, `InitCurrentCamera`, `ReleaseCurrentCamera`, ... |
| 0x234 | `u32` | `m_field_234` | R/W | `Draw`, `Reset` |
| 0x238 | `u32` | **`m_cameraInterp_238`** | R/W | `AttachDummy`, `CheckCancelled`, `InterpToGameCamera`, ... |
| 0x23C | `u32` | `m_field_23C` | R/W | `InterpToCancelCamera`, `Reset`, `Update` |
| 0x240 | `u32` | **`m_cameraInterp_240`** | R/W | `AttachDummy`, `CheckCancelled`, `InterpToCancelCamera`, ... |
| 0x244 | `u32` | `m_field_244` | R/W | `CameraDirector`, `CheckCancelled`, `DisableControls`, ... |
| 0x248 | `u32` | `m_field_248` | R/W | `DisableControls`, `EnableControls`, `ReleaseCurrentCamera` |
| 0x24C | `u32` | **`m_cameraCutAnim_24C`** | R/W | `CalcCancelCam`, `ReleaseCurrentCamera`, `Reset`, ... |
| 0x250 | `f32` | **`m_cameraCutAnim_250`** | R | `SetCameraCutAnim` |
| 0x260 | `f32` | **`m_cameraCutAnim_260`** | R | `SetCameraCutAnim` |
| 0x270 | `f32` | **`m_cameraCutAnim_270`** | R | `SetCameraCutAnim` |
| 0x280 | `f32` | **`m_cameraCutAnim_280`** | R | `SetCameraCutAnim` |
| 0x290 | `f32` | **`m_cameraCutAnim_290`** | R/W | `SetCameraCutAnim` |
| 0x294 | `u32` | **`m_cameraCutAnim_294`** | W | `SetCameraCutAnim` |
| 0x298 | `u8[0x38]` | _(gap)_ | - | - |
| 0x2D0 | `u32` | `m_field_2D0` | R/W | `CameraDirector`, `~CameraDirector` |
| 0x2D4 | `f32` | `m_field_2D4` | R/W | `BeginCameraBloomInterp`, `BloomInterp`, `Reset`, ... |
| 0x2D8 | `f32` | **`m_animNoteTrack`** | R/W | `BlurInterp`, `Reset`, `UpdateAnimNoteTrack` |
| 0x2DC | `f32` | `m_field_2DC` | R | `BloomInterp` |
| 0x2E0 | `f32` | `m_field_2E0` | R | `BloomInterp` |
| 0x2E4 | `f32` | `m_field_2E4` | R | `BloomInterp` |
| 0x2E8 | `f32` | `m_field_2E8` | R | `BloomInterp` |
| 0x2EC | `f32` | `m_field_2EC` | R/W | `BeginCameraBloomInterp`, `BloomInterp` |
| 0x2F0 | `f32` | `m_field_2F0` | R | `BloomInterp` |
| 0x2F4 | `f32` | `m_field_2F4` | R | `BloomInterp` |
| 0x2F8 | `f32` | `m_field_2F8` | R | `BloomInterp` |
| 0x2FC | `f32` | `m_field_2FC` | R | `BlurInterp` |
| 0x300 | `f32` | `m_field_300` | R | `BlurInterp` |
| 0x304 | `f32` | `m_field_304` | R | `BlurInterp` |
| 0x308 | `f32` | `m_field_308` | R | `BlurInterp` |
| 0x30C | `f32` | `m_field_30C` | R | `BlurInterp` |
| 0x310 | `f32` | `m_field_310` | R | `BlurInterp` |
| 0x314 | `f32` | `m_field_314` | R | `BlurInterp` |
| 0x318 | `f32` | `m_field_318` | R | `BlurInterp` |
| 0x31C | `u32` | `m_field_31C` | R/W | `BeginCameraBloomInterp`, `BloomInterp`, `BlurInterp`, ... |
| 0x320 | `u32` | `m_field_320` | R/W | `InterpToGameCamera`, `ReleaseToGameCamera` |
| 0x324 | `f32` | **`m_cameraInterpAnim`** | R/W | `CameraDirector`, `InterpToGameCamera`, `ReleaseToGameCamera`, ... |
| 0x328 | `f32` | **`m_cameraInterpAnim_328`** | R/W | `CameraDirector`, `InterpToGameCamera`, `ReleaseToGameCamera`, ... |
| 0x32C | `u8[0x11C]` | _(gap)_ | - | - |
| 0x448 | `f32` | **`m_cameraInterpAnim_448`** | R | `InterpToGameCamera`, `SetCameraInterpAnim` |

### `ISimsObjectModel`

**Size:** >= 0x323C (12860 bytes) | **Fields:** 88 (28 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `f32` | **`m_heightOffset`** | R/W | `ApplyMatrix`, `BlendHighlights`, `CalcDynamicOrient`, ... |
| 0x004 | `f32` | **`m_adjacentRoom`** | R/W | `ApplyMatrix`, `BlendHighlights`, `CreateShadow`, ... |
| 0x008 | `f32` | `m_field_008` | R/W | `ApplyMatrix`, `BlendHighlights`, `DoLightingCalculation`, ... |
| 0x00C | `u32` | **`m_initalObjectState`** | R/W | `BlendHighlights`, `DoLightingCalculation`, `SetInitalObjectState`, ... |
| 0x00E | `u8` | **`m_tracks`** | R | `UpdateTracks` |
| 0x010 | `u32` | **`m_initalObjectState_010`** | R/W | `BlendHighlights`, `DoLightingCalculation`, `Draw`, ... |
| 0x012 | `s16` | **`m_animController`** | R | `CreateShadow`, `UpdateAnimController` |
| 0x014 | `f32` | `m_field_014` | R/W | `ApplyMatrix`, `BlendHighlights`, `DoLightingCalculation`, ... |
| 0x018 | `f32` | `m_field_018` | R | `ApplyMatrix`, `Update` |
| 0x01C | `f32` | `m_field_01C` | R/W | `ApplyMatrix`, `Update` |
| 0x020 | `u32` | `m_field_020` | R/W | `ApplyMatrix`, `Update` |
| 0x024 | `u32` | `m_field_024` | R/W | `ApplyMatrix`, `Update` |
| 0x028 | `u32` | `m_field_028` | R/W | `ApplyMatrix`, `Update` |
| 0x02C | `u32` | `m_field_02C` | R | `Update`, `VisibilityTest` |
| 0x030 | `u32` | `m_field_030` | R | `Update`, `VisibilityTest` |
| 0x034 | `u32` | `m_field_034` | R | `Update` |
| 0x038 | `u32` | `m_field_038` | R | `Update` |
| 0x03C | `u32` | `m_field_03C` | R | `Update` |
| 0x050 | `f32` | `m_field_050` | R | `Update` |
| 0x05C | `u32` | `m_field_05C` | R/W | `CreateShadow`, `ISimsObjectModel` |
| 0x070 | `u32` | `m_field_070` | R | `Draw` |
| 0x07C | `u32` | `m_field_07C` | W | `CreateShadow`, `InitBulb` |
| 0x080 | `u8[0x2C]` | _(gap)_ | - | - |
| 0x0AC | `f32` | **`m_upCharacter`** | R/W | `ApplyMatrix`, `InitBulb`, `SetupCharacter` |
| 0x0B8 | `f32` | `m_field_0B8` | R/W | `ApplyMatrix`, `InitBulb` |
| 0x0C0 | `f32` | **`m_animDef`** | R | `ApplyMatrix`, `CalcLightsFromPos`, `CreateShadow`, ... |
| 0x0C4 | `f32` | **`m_upCharacter_0C4`** | W | `InitBulb`, `SetupCharacter` |
| 0x0C8 | `f32` | **`m_upCharacter_0C8`** | W | `InitBulb`, `SetupCharacter` |
| 0x0CC | `f32` | **`m_upCharacter_0CC`** | W | `InitBulb`, `SetupCharacter` |
| 0x0D0 | `f32` | `m_field_0D0` | W | `InitBulb` |
| 0x0D4 | `u32` | `m_field_0D4` | W | `InitBulb` |
| 0x0D8 | `u8[0x18]` | _(gap)_ | - | - |
| 0x0F0 | `u32` | `m_field_0F0` | R | `Draw` |
| 0x0F4 | `u8[0x1C]` | _(gap)_ | - | - |
| 0x110 | `u32` | **`m_sOMModel`** | R | `SetSOMModel` |
| 0x118 | `u32` | `m_field_118` | R | `CreateShadow`, `DoAnimation`, `DoLightingCalculation`, ... |
| 0x11C | `u32` | `m_field_11C` | R | `CreateShadow`, `DoAnimation`, `Draw` |
| 0x120 | `u32` | **`m_bIsVisible`** | R | `AnimateLights`, `ApplyMatrix`, `CalcLightsFromPos`, ... |
| 0x124 | `u32` | `m_field_124` | R | `Draw` |
| 0x128 | `u8[0x1F0]` | _(gap)_ | - | - |
| 0x318 | `u32` | `m_field_318` | R | `Draw` |
| 0x320 | `u32` | `m_field_320` | R/W | `ApplyMatrix`, `Create`, `ISimsObjectModel`, ... |
| 0x328 | `u32` | **`m_adjacentRoom_328`** | R/W | `ApplyMatrix`, `Create`, `CreateShadow`, ... |
| 0x32C | `u32` | `m_field_32C` | R/W | `DoLightingCalculation`, `ISimsObjectModel`, `PropigateFlagsToSubModels`, ... |
| 0x340 | `u32` | `m_field_340` | R | `AnimateLights` |
| 0x344 | `u8[0x14]` | _(gap)_ | - | - |
| 0x358 | `u32` | `m_field_358` | R | `DoAnimation`, `Draw` |
| 0x35C | `u8[0x1C]` | _(gap)_ | - | - |
| 0x378 | `u32` | **`m_animTrack`** | R | `StartNewAnimTrack`, `UpdateAnimTrack` |
| 0x37C | `u8[0x40]` | _(gap)_ | - | - |
| 0x3BC | `u32` | `m_field_3BC` | R/W | `CleanupStuff` |
| 0x3C0 | `u32` | `m_field_3C0` | R/W | `CleanupStuff` |
| 0x3C8 | `u32` | **`m_objOrient`** | R/W | `Create`, `ISimsObjectModel`, `InitBulb`, ... |
| 0x3CC | `u32` | **`m_heightOffset_3CC`** | R/W | `ApplyMatrix`, `GetHeightOffset`, `ISimsObjectModel`, ... |
| 0x3D0 | `u32` | **`m_heightOffset_3D0`** | R/W | `GetHeightOffset`, `ISimsObjectModel` |
| 0x3D4 | `u32` | `m_field_3D4` | W | `ISimsObjectModel` |
| 0x3D8 | `u32` | `m_field_3D8` | W | `ISimsObjectModel` |
| 0x3DC | `u32` | `m_field_3DC` | W | `ISimsObjectModel` |
| 0x3E0 | `u32` | `m_field_3E0` | W | `ISimsObjectModel` |
| 0x3E4 | `u32` | **`m_initalObjectState_3E4`** | R/W | `ISimsObjectModel`, `SetInitalObjectState`, `Update` |
| 0x3E8 | `u32` | **`m_sOMModel_3E8`** | R/W | `AnimStartBlendIn`, `AnimStartImmediate`, `Draw`, ... |
| 0x3EC | `f32` | `m_field_3EC` | R/W | `ISimsObjectModel`, `StartNewAnimTrack`, `UpdateAnimTrack`, ... |
| 0x3F0 | `f32` | **`m_objOrient_3F0`** | R/W | `CalcOrient`, `SetObjOrient`, `Update` |
| 0x3F4 | `f32` | `m_field_3F4` | W | `ISimsObjectModel` |
| 0x3F8 | `f32` | **`m_highlightAnim`** | R/W | `ISimsObjectModel`, `UpdateHighlightAnim` |
| 0x3FC | `f32` | **`m_highlightAnim_3FC`** | R/W | `ISimsObjectModel`, `UpdateHighlightAnim` |
| 0x400 | `u32` | `m_field_400` | W | `ISimsObjectModel`, `Update` |
| 0x404 | `f32` | `m_field_404` | W | `ApplyMatrix`, `Update` |
| 0x408 | `u8[0x14]` | _(gap)_ | - | - |
| 0x41C | `u32` | `m_field_41C` | R/W | `ChageShader`, `ISimsObjectModel`, `~ISimsObjectModel` |
| 0x420 | `u32` | **`m_initalObjectState_420`** | R/W | `ISimsObjectModel`, `SetInitalObjectState` |
| 0x428 | `u32` | `m_field_428` | R | `StartNewAnimTrack` |
| 0x42C | `u8[0x14]` | _(gap)_ | - | - |
| 0x440 | `u32` | `m_field_440` | R/W | `Draw`, `ISimsObjectModel`, `Update`, ... |
| 0x44C | `u32` | `m_field_44C` | R/W | `ApplyMatrix`, `CalcDynamicOrient`, `CalcOrient`, ... |
| 0x450 | `u32` | `m_field_450` | R/W | `ISimsObjectModel`, `InsertSubModelsInHouse`, `OrientSubObjects`, ... |
| 0x45C | `u32` | **`m_adjacentRoom_45C`** | R/W | `GetAdjacentRoom`, `ISimsObjectModel`, `SetWallForPortal` |
| 0x460 | `u32` | **`m_initalObjectState_460`** | R/W | `ApplyMatrix`, `CleanupStuff`, `ISimsObjectModel`, ... |
| 0x464 | `u32` | `m_field_464` | R | `AnimateLights`, `CleanupStuff` |
| 0x468 | `u32` | `m_field_468` | R | `AnimateLights` |
| 0x470 | `f32` | `m_field_470` | W | `ApplyMatrix` |
| 0x474 | `f32` | `m_field_474` | W | `ISimsObjectModel` |
| 0x478 | `f32` | `m_field_478` | W | `ISimsObjectModel` |
| 0x47C | `f32` | `m_field_47C` | W | `ISimsObjectModel` |
| 0x480 | `u32` | `m_field_480` | W | `ApplyMatrix` |
| 0x48C | `f32` | `m_field_48C` | R/W | `ISimsObjectModel`, `ProcessPropertyEventTags`, `StartNewAnimTrack`, ... |
| 0x490 | `u32` | `m_field_490` | R/W | `ISimsObjectModel`, `ProcessPropertyEventTags`, `StartNewAnimTrack`, ... |
| 0x494 | `u32` | `m_field_494` | R/W | `ISimsObjectModel`, `TryAnimateObject` |
| 0x498 | `u32` | `m_field_498` | R/W | `ISimsObjectModel`, `ProcessPropertyEventTags`, `StartNewAnimTrack`, ... |
| 0x49C | `u32` | `m_field_49C` | R/W | `ISimsObjectModel`, `ProcessPropertyEventTags`, `StartNewAnimTrack`, ... |
| 0x4A0 | `u32` | **`m_initalObjectState_4A0`** | R/W | `SetInitalObjectState`, `TryAnimateObject`, `Update`, ... |
| 0x4A4 | `u32` | `m_field_4A4` | R/W | `ISimsObjectModel`, `ProcessPropertyEventTags`, `StartNewAnimTrack`, ... |
| 0x4A8 | `u32` | **`m_animTrack_4A8`** | W | `StartNewAnimTrack`, `UpdateAnimTrack` |
| 0x4B4 | `u32` | `m_field_4B4` | R/W | `CleanupStuff`, `ISimsObjectModel`, `KillAllAnimTracks`, ... |
| 0x4B8 | `u32` | `m_field_4B8` | W | `ISimsObjectModel` |
| 0x4BC | `u8[0x2D78]` | _(gap)_ | - | - |
| 0x3234 | `f32` | `m_field_3234` | R | `Draw` |
| 0x3238 | `f32` | `m_field_3238` | R | `Draw` |

### `INVTarget`

**Size:** >= 0x5EAC (24236 bytes) | **Fields:** 82 (31 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `u8` | **`m_onMsgInvShpCanColor`** | R/W | `AddFloorTileToShopItemsDB`, `AddObjSelectorToShopItemsDB`, `AddWallPaperToShopItemsDB`, ... |
| 0x004 | `u32` | **`m_onMsgInvShpCanColor_004`** | R/W | `AddFloorTileToShopItemsDB`, `AddObjSelectorToShopItemsDB`, `AddWallPaperToShopItemsDB`, ... |
| 0x008 | `u32` | `m_field_008` | R/W | `EnterFloorTilingMode`, `EnterGrabModeNewInteractorApi`, `EnterPlaceAnyObjectModeUsingNewInteractorApi`, ... |
| 0x00C | `u32` | `m_field_00C` | R/W | `AddObjSelectorToShopItemsDB`, `EnterFloorTilingMode`, `EnterGrabModeNewInteractorApi`, ... |
| 0x010 | `u32` | `m_field_010` | R/W | `EnterFloorTilingMode`, `EnterGrabModeNewInteractorApi`, `EnterPlaceAnyObjectModeUsingNewInteractorApi`, ... |
| 0x014 | `s16` | **`m_allObjectRelatedCheatStrings`** | R/W | `BuildLotShopDB`, `Cheat_BuildCatalogDB`, `EnterFloorTilingMode`, ... |
| 0x016 | `s16` | `m_field_016` | R | `BuildLotShopDB`, `Cheat_BuildCatalogDB` |
| 0x018 | `u8` | `m_field_018` | R/W | `EnterGrabModeNewInteractorApi`, `EnterPlaceAnyObjectModeUsingNewInteractorApi`, `EnterPlaceModeUsingNewInteractorApi`, ... |
| 0x01C | `f32` | `m_field_01C` | R/W | `BuildLotShopDB`, `Cheat_InstallSelectedCategoryObjectShaders`, `Cheat_OnSetCurrentTabMode`, ... |
| 0x020 | `u16` | **`m_onMsgInvShpCanColor_020`** | R/W | `ClearAllObjectInfoData`, `EnterFloorTilingMode`, `EnterPlaceAnyObjectModeUsingNewInteractorApi`, ... |
| 0x024 | `u32` | `m_field_024` | R/W | `EnterPlaceAnyObjectModeUsingNewInteractorApi`, `EnterPlaceModeUsingNewInteractorApi`, `EnterWallBuildMode`, ... |
| 0x028 | `u32` | `m_field_028` | W | `INVTarget` |
| 0x02C | `u32` | `m_field_02C` | R | `EnterFloorTilingMode`, `EnterGrabModeNewInteractorApi`, `EnterPlaceAnyObjectModeUsingNewInteractorApi`, ... |
| 0x038 | `u32` | **`m_onMsgInvShpColorN`** | R/W | `AddObjSelectorToShopItemsDB`, `BuildLotShopDB`, `Cheat_BuildCatalogDB`, ... |
| 0x03C | `u8` | **`m_onMsgInvShpCanColor_03C`** | R/W | `EnterFloorTilingMode`, `EnterGrabModeNewInteractorApi`, `EnterPlaceAnyObjectModeUsingNewInteractorApi`, ... |
| 0x048 | `u32` | `m_field_048` | W | `INVTarget` |
| 0x058 | `u32` | `m_field_058` | R/W | `INVTarget`, `~INVTarget` |
| 0x068 | `u32` | `m_field_068` | R/W | `INVTarget`, `~INVTarget` |
| 0x070 | `s16` | `m_field_070` | R | `BuildLotShopDB`, `Cheat_BuildCatalogDB` |
| 0x074 | `u32` | `m_field_074` | R | `BuildLotShopDB`, `Cheat_BuildCatalogDB` |
| 0x078 | `s16` | `m_field_078` | R/W | `FireCodeDialogSelectionCallback`, `INVTarget` |
| 0x07C | `u32` | **`m_onMsgInvShpCanColor_07C`** | R/W | `Cheat_InstallSelectedCategoryObjectShaders`, `Cheat_OnSetCurrentTabMode`, `EnterFloorTilingMode`, ... |
| 0x080 | `u32` | **`m_onMsgInvItemSelected`** | R/W | `INVTarget`, `SetOnMsgInvItemSelected`, `~INVTarget` |
| 0x084 | `u32` | **`m_bCannotGrabToInventoryDialogSelectionCallback`** | R/W | `BuildLotShopDB`, `CannotGrabToInventoryDialogSelectionCallback`, `Cheat_HandleCellChange`, ... |
| 0x088 | `u32` | **`m_onMsgInvObjectInfoReady`** | R/W | `GetOnMsgInvObjectInfoReady`, `GetOnMsgInvShpObjectInfoReady`, `INVTarget`, ... |
| 0x08C | `u32` | **`m_inputState`** | W | `INVTarget`, `UpdateInputState` |
| 0x090 | `u32` | **`m_onMsgInvShpCanPurchase`** | R/W | `CommittChangesToInventory`, `EnterFloorTilingMode`, `EnterWallBuildMode`, ... |
| 0x094 | `u32` | **`m_onMsgInvPrepareObjectInfo`** | W | `INVTarget`, `SetOnMsgInvPrepareObjectInfo` |
| 0x098 | `u32` | **`m_onMsgInvItemSelected_098`** | R/W | `SetOnMsgInvItemSelected` |
| 0x0A4 | `u32` | **`m_onMsgInvItemSelected_0A4`** | R/W | `SetOnMsgInvItemSelected`, `~INVTarget` |
| 0x0A8 | `f32` | `m_field_0A8` | R/W | `INVTarget`, `~INVTarget` |
| 0x0AC | `u32` | `m_field_0AC` | R/W | `ExitFloorTilingMode`, `INVTarget`, `~INVTarget` |
| 0x0BC | `u32` | `m_field_0BC` | R/W | `INVTarget`, `OnSetCurrentTab` |
| 0x0C0 | `u32` | `m_field_0C0` | W | `INVTarget` |
| 0x0C4 | `u32` | `m_field_0C4` | W | `INVTarget` |
| 0x0C8 | `u32` | `m_field_0C8` | R/W | `EnterPlaceAnyObjectModeUsingNewInteractorApi`, `EnterPlaceModeUsingNewInteractorApi`, `INVTarget`, ... |
| 0x0CC | `u8` | `m_field_0CC` | R/W | `EnterPlaceAnyObjectModeUsingNewInteractorApi`, `EnterPlaceModeUsingNewInteractorApi`, `INVTarget`, ... |
| 0x0D0 | `u32` | `m_field_0D0` | R/W | `INVTarget`, `PopCurrentFilter`, `PushGrabFilter`, ... |
| 0x0D4 | `u32` | `m_field_0D4` | R/W | `Cheat_InstallSelectedCategoryObjectShaders`, `Cheat_OnSetCurrentTabMode`, `INVTarget`, ... |
| 0x0D8 | `u8[0x60]` | _(gap)_ | - | - |
| 0x138 | `u8` | `m_field_138` | R/W | `Cheat_HandleCellChange`, `Cheat_HandleProgressDownHierarchy`, `Cheat_HandleReturnUpHierarchy`, ... |
| 0x13C | `u32` | `m_field_13C` | W | `INVTarget` |
| 0x140 | `u32` | `m_field_140` | R/W | `AddObjSelectorToShopItemsDB`, `BuildLotShopDB`, `Cheat_BuildCatalogDB`, ... |
| 0x144 | `u32` | `m_field_144` | R/W | `AddObjSelectorToShopItemsDB`, `BuildLotShopDB`, `Cheat_BuildCatalogDB`, ... |
| 0x148 | `u32` | `m_field_148` | R/W | `AddObjSelectorToShopItemsDB`, `BuildLotShopDB`, `Cheat_BuildCatalogDB`, ... |
| 0x14C | `u32` | `m_field_14C` | R/W | `AddObjSelectorToShopItemsDB`, `BuildLotShopDB`, `Cheat_BuildCatalogDB`, ... |
| 0x150 | `u32` | `m_field_150` | R/W | `AddObjSelectorToShopItemsDB`, `BuildLotShopDB`, `Cheat_BuildCatalogDB`, ... |
| 0x154 | `u32` | `m_field_154` | R/W | `AddObjSelectorToShopItemsDB`, `BuildLotShopDB`, `Cheat_BuildCatalogDB`, ... |
| 0x158 | `u32` | `m_field_158` | R/W | `AddObjSelectorToShopItemsDB`, `BuildLotShopDB`, `Cheat_BuildCatalogDB`, ... |
| 0x15C | `u32` | `m_field_15C` | R/W | `AddObjSelectorToShopItemsDB`, `BuildLotShopDB`, `Cheat_BuildCatalogDB`, ... |
| 0x160 | `u32` | `m_field_160` | R/W | `AddObjSelectorToShopItemsDB`, `BuildLotShopDB`, `Cheat_BuildCatalogDB`, ... |
| 0x164 | `u32` | **`m_onMsgInvShpItemCount`** | R/W | `AddWallToShopItemsDB`, `BuildLotShopDB`, `Cheat_BuildCatalogDB`, ... |
| 0x168 | `u32` | **`m_onMsgInvShpItemCount_168`** | R/W | `AddWallPaperToShopItemsDB`, `BuildLotShopDB`, `Cheat_BuildCatalogDB`, ... |
| 0x16C | `u32` | **`m_onMsgInvShpItemCount_16C`** | R/W | `AddFloorTileToShopItemsDB`, `BuildLotShopDB`, `Cheat_BuildCatalogDB`, ... |
| 0x170 | `u32` | `m_field_170` | R/W | `AddObjSelectorToShopItemsDB`, `BuildLotShopDB`, `Cheat_BuildCatalogDB`, ... |
| 0x174 | `u32` | `m_field_174` | R/W | `AddObjSelectorToShopItemsDB`, `BuildLotShopDB`, `Cheat_BuildCatalogDB`, ... |
| 0x178 | `u32` | **`m_onMsgInvShpItemCount_178`** | R/W | `BuildLotShopDB`, `GetOnMsgInvShpCategoryCount`, `GetOnMsgInvShpCategoryN`, ... |
| 0x17C | `u32` | **`m_onMsgInvShpCategoryN`** | R | `GetOnMsgInvShpCategoryCount`, `GetOnMsgInvShpCategoryN` |
| 0x188 | `u8` | `m_field_188` | R/W | `Cheat_OnSetCurrentTabMode`, `INVTarget` |
| 0x189 | `u8` | **`m_pageIdxCheatString`** | R/W | `Cheat_HandleCellChange`, `Cheat_HandleProgressDownHierarchy`, `Cheat_HandleReturnUpHierarchy`, ... |
| 0x18A | `u8` | **`m_pageIdxCheatString_18A`** | R/W | `Cheat_HandleReturnUpHierarchy`, `Cheat_InstallSelectedCategoryObjectShaders`, `INVTarget`, ... |
| 0x18B | `u8[0x25D]` | _(gap)_ | - | - |
| 0x3E8 | `u32` | `m_field_3E8` | R | `BuildLotShopDB` |
| 0x3EC | `u8[0x2DA0]` | _(gap)_ | - | - |
| 0x318C | `u32` | **`m_onMsgInvShpCanPurchase_318C`** | R/W | `GetOnMsgInvShpCanPurchase`, `INVTarget`, `SetOnMsgInvSellAllItems`, ... |
| 0x3190 | `u32` | `m_field_3190` | W | `INVTarget` |
| 0x3194 | `u32` | `m_field_3194` | W | `INVTarget` |
| 0x3198 | `u32` | `m_field_3198` | W | `INVTarget` |
| 0x319C | `u8[0xB4]` | _(gap)_ | - | - |
| 0x3250 | `u8` | **`m_onMsgInvShpPrevTab`** | R/W | `BuildLotShopDB`, `INVTarget`, `SetOnMsgInvShpCurrentCategory`, ... |
| 0x3251 | `u8` | **`m_onLocMsgInvShpObjectName`** | R/W | `Cheat_HandleCellChange`, `Cheat_HandleReturnUpHierarchy`, `Cheat_InstallSelectedCategoryObjectShaders`, ... |
| 0x3252 | `u8` | **`m_onMsgInvShpCanPurchase_3252`** | R/W | `GetOnMsgInvShpCanColor`, `GetOnMsgInvShpCanPurchase`, `INVTarget`, ... |
| 0x3253 | `u8` | **`m_onMsgInvShpCanPurchase_3253`** | R/W | `GetOnMsgInvShpCanPurchase`, `INVTarget`, `SetOnMsgInvSellAllItems`, ... |
| 0x3254 | `u32` | `m_field_3254` | R/W | `BuildLotShopDB`, `INVTarget`, `~INVTarget` |
| 0x3258 | `u32` | **`m_onMsgInvShpCanColor_3258`** | R/W | `ClearAllObjectInfoData`, `GetOnMsgInvShpCanColor`, `INVTarget`, ... |
| 0x325C | `u32` | `m_field_325C` | W | `INVTarget` |
| 0x3260 | `u8[0x38]` | _(gap)_ | - | - |
| 0x3298 | `u32` | **`m_onMsgInvShpCanPurchase_3298`** | R/W | `GetOnMsgInvShpCanPurchase`, `GrabModeCallbackImpl`, `SetOnMsgInvItemSelected` |
| 0x32AC | `u32` | `m_field_32AC` | W | `INVTarget` |
| 0x32BC | `u32` | `m_field_32BC` | W | `INVTarget` |
| 0x32CC | `u32` | `m_field_32CC` | W | `INVTarget` |
| 0x32D0 | `u8[0x14]` | _(gap)_ | - | - |
| 0x32E4 | `u32` | **`m_onMsgInvBldDisplayInfo`** | R/W | `EnterFloorTilingMode`, `EnterWallBuildMode`, `EnterWallPaperingMode`, ... |
| 0x32E8 | `u32` | `m_field_32E8` | W | `EnterFloorTilingMode`, `EnterWallBuildMode`, `EnterWallPaperingMode`, ... |
| 0x32EC | `u32` | **`m_variable`** | R/W | `ExitFloorTilingMode`, `GetVariable`, `GrabModeCallbackImpl`, ... |
| 0x32F0 | `u8[0x296C]` | _(gap)_ | - | - |
| 0x5C5C | `u32` | `m_field_5C5C` | R | `INVTarget` |
| 0x5C60 | `u8[0x244]` | _(gap)_ | - | - |
| 0x5EA4 | `u32` | `m_field_5EA4` | R | `BuildLotShopDB`, `Cheat_BuildCatalogDB` |
| 0x5EA8 | `u32` | `m_field_5EA8` | R | `BuildLotShopDB`, `Cheat_BuildCatalogDB` |

### `SimsCameraParameters`

**Size:** >= 0x1C8 (456 bytes) | **Fields:** 80 (1 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `void**` | **`_vtable` (vtable pointer)** | W | `SimsCameraParameters` |
| 0x004 | `f32` | `m_field_004` | W | `SimsCameraParameters` |
| 0x008 | `f32` | `m_field_008` | W | `SimsCameraParameters` |
| 0x00C | `f32` | `m_field_00C` | W | `SimsCameraParameters` |
| 0x010 | `f32` | `m_field_010` | W | `SimsCameraParameters` |
| 0x014 | `f32` | `m_field_014` | W | `SimsCameraParameters` |
| 0x018 | `f32` | `m_field_018` | W | `SimsCameraParameters` |
| 0x01C | `f32` | `m_field_01C` | W | `SimsCameraParameters` |
| 0x020 | `f32` | `m_field_020` | W | `SimsCameraParameters` |
| 0x024 | `f32` | `m_field_024` | W | `SimsCameraParameters` |
| 0x028 | `f32` | `m_field_028` | R/W | `SimsCameraParameters` |
| 0x02C | `f32` | `m_field_02C` | W | `SimsCameraParameters` |
| 0x030 | `f32` | `m_field_030` | W | `SimsCameraParameters` |
| 0x034 | `f32` | `m_field_034` | W | `SimsCameraParameters` |
| 0x038 | `f32` | `m_field_038` | R/W | `SimsCameraParameters` |
| 0x03C | `f32` | `m_field_03C` | W | `SimsCameraParameters` |
| 0x040 | `f32` | `m_field_040` | W | `SimsCameraParameters` |
| 0x04C | `f32` | `m_field_04C` | W | `SimsCameraParameters` |
| 0x050 | `f32` | `m_field_050` | W | `SimsCameraParameters` |
| 0x054 | `f32` | `m_field_054` | W | `SimsCameraParameters` |
| 0x058 | `f32` | `m_field_058` | W | `SimsCameraParameters` |
| 0x05C | `f32` | `m_field_05C` | W | `SimsCameraParameters` |
| 0x060 | `f32` | `m_field_060` | W | `SimsCameraParameters` |
| 0x064 | `f32` | `m_field_064` | W | `SimsCameraParameters` |
| 0x068 | `f32` | `m_field_068` | W | `SimsCameraParameters` |
| 0x06C | `f32` | `m_field_06C` | W | `SimsCameraParameters` |
| 0x070 | `f32` | `m_field_070` | W | `SimsCameraParameters` |
| 0x074 | `f32` | `m_field_074` | W | `SimsCameraParameters` |
| 0x078 | `f32` | `m_field_078` | W | `SimsCameraParameters` |
| 0x07C | `f32` | `m_field_07C` | W | `SimsCameraParameters` |
| 0x080 | `f32` | `m_field_080` | W | `SimsCameraParameters` |
| 0x084 | `f32` | `m_field_084` | W | `SimsCameraParameters` |
| 0x088 | `f32` | `m_field_088` | W | `SimsCameraParameters` |
| 0x08C | `f32` | `m_field_08C` | W | `SimsCameraParameters` |
| 0x090 | `f32` | `m_field_090` | W | `SimsCameraParameters` |
| 0x094 | `f32` | `m_field_094` | W | `SimsCameraParameters` |
| 0x098 | `f32` | `m_field_098` | W | `SimsCameraParameters` |
| 0x09C | `f32` | `m_field_09C` | W | `SimsCameraParameters` |
| 0x0A0 | `f32` | `m_field_0A0` | W | `SimsCameraParameters` |
| 0x0A4 | `f32` | `m_field_0A4` | W | `SimsCameraParameters` |
| 0x0A8 | `f32` | `m_field_0A8` | W | `SimsCameraParameters` |
| 0x0AC | `f32` | `m_field_0AC` | W | `SimsCameraParameters` |
| 0x0B0 | `f32` | `m_field_0B0` | W | `SimsCameraParameters` |
| 0x0B4 | `f32` | `m_field_0B4` | W | `SimsCameraParameters` |
| 0x0B8 | `f32` | `m_field_0B8` | W | `SimsCameraParameters` |
| 0x0BC | `f32` | `m_field_0BC` | W | `SimsCameraParameters` |
| 0x0C8 | `f32` | `m_field_0C8` | W | `SimsCameraParameters` |
| 0x0D4 | `f32` | `m_field_0D4` | W | `SimsCameraParameters` |
| 0x0E0 | `u32` | `m_field_0E0` | W | `SimsCameraParameters` |
| 0x0E4 | `u32` | `m_field_0E4` | W | `SimsCameraParameters` |
| 0x0E8 | `u32` | `m_field_0E8` | W | `SimsCameraParameters` |
| 0x0F0 | `u32` | `m_field_0F0` | W | `SimsCameraParameters` |
| 0x0F4 | `u32` | `m_field_0F4` | W | `SimsCameraParameters` |
| 0x0F8 | `u32` | `m_field_0F8` | W | `SimsCameraParameters` |
| 0x0FC | `f32` | `m_field_0FC` | W | `SimsCameraParameters` |
| 0x10C | `f32` | `m_field_10C` | W | `SimsCameraParameters` |
| 0x11C | `f32` | `m_field_11C` | W | `SimsCameraParameters` |
| 0x120 | `u8[0x1C]` | _(gap)_ | - | - |
| 0x13C | `f32` | `m_field_13C` | W | `SimsCameraParameters` |
| 0x14C | `f32` | `m_field_14C` | W | `SimsCameraParameters` |
| 0x15C | `f32` | `m_field_15C` | W | `SimsCameraParameters` |
| 0x16C | `f32` | `m_field_16C` | W | `SimsCameraParameters` |
| 0x170 | `f32` | `m_field_170` | W | `SimsCameraParameters` |
| 0x174 | `f32` | `m_field_174` | W | `SimsCameraParameters` |
| 0x17C | `f32` | `m_field_17C` | W | `SimsCameraParameters` |
| 0x180 | `f32` | `m_field_180` | W | `SimsCameraParameters` |
| 0x184 | `f32` | `m_field_184` | W | `SimsCameraParameters` |
| 0x188 | `u32` | `m_field_188` | W | `SimsCameraParameters` |
| 0x18C | `u32` | `m_field_18C` | W | `SimsCameraParameters` |
| 0x190 | `u32` | `m_field_190` | W | `SimsCameraParameters` |
| 0x198 | `u32` | `m_field_198` | W | `SimsCameraParameters` |
| 0x19C | `u32` | `m_field_19C` | W | `SimsCameraParameters` |
| 0x1A0 | `u32` | `m_field_1A0` | W | `SimsCameraParameters` |
| 0x1A4 | `u32` | `m_field_1A4` | W | `SimsCameraParameters` |
| 0x1A8 | `u32` | `m_field_1A8` | W | `SimsCameraParameters` |
| 0x1AC | `u32` | `m_field_1AC` | W | `SimsCameraParameters` |
| 0x1B4 | `u32` | `m_field_1B4` | W | `SimsCameraParameters` |
| 0x1B8 | `u32` | `m_field_1B8` | W | `SimsCameraParameters` |
| 0x1BC | `u32` | `m_field_1BC` | W | `SimsCameraParameters` |
| 0x1C0 | `u32` | `m_field_1C0` | W | `SimsCameraParameters` |
| 0x1C4 | `u32` | `m_field_1C4` | W | `SimsCameraParameters` |

### `CasSimDescriptionS2C`

**Size:** >= 0x122 (290 bytes) | **Fields:** 74 (38 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `s16` | **`m_bodyPartParam`** | R/W | `ClearSim`, `DoStream`, `GetBodyPartParam`, ... |
| 0x002 | `u8` | `m_field_002` | R/W | `ClearSim`, `DoStream` |
| 0x004 | `u16` | **`m_bodyPartParam_004`** | W | `GetBodyPartParam`, `ReadOldDescription` |
| 0x008 | `u32` | **`m_bodyPartParam_008`** | W | `GetBodyPartParam` |
| 0x00C | `u32` | **`m_bodyPartParam_00C`** | W | `GetBodyPartParam` |
| 0x010 | `u8[0x32]` | _(gap)_ | - | - |
| 0x042 | `u16` | `m_field_042` | W | `ClearSim`, `Verify` |
| 0x044 | `u8[0x3E]` | _(gap)_ | - | - |
| 0x082 | `u16` | `m_field_082` | W | `ClearSim`, `Verify` |
| 0x084 | `u32` | **`m_bodyTypeMorphValues`** | R/W | `CasSimDescriptionS2C`, `ClearSim`, `InitializeToDefaultCostume`, ... |
| 0x088 | `u8` | **`m_bodyTypeMorphValues_088`** | R/W | `ClearSim`, `SetBodyTypeMorphValues`, `Verify` |
| 0x089 | `u8` | `m_field_089` | R/W | `ClearSim`, `Verify` |
| 0x08A | `u8` | **`m_bodyPartIndex`** | R/W | `ClearSim`, `GetBodyPartIndex`, `SetBodyPartIndex` |
| 0x08B | `u8` | **`m_bodyPartTextureIndex`** | R/W | `ClearSim`, `GetBodyPartTextureIndex`, `SetBodyPartTextureIndex` |
| 0x08C | `u8` | **`m_bodyPartIndex_08C`** | R/W | `ClearSim`, `GetBodyPartIndex`, `SetBodyPartIndex` |
| 0x08D | `u8` | **`m_bodyPartIndex_08D`** | R/W | `ClearSim`, `GetBodyPartIndex`, `SetBodyPartIndex` |
| 0x08E | `u8` | **`m_bodyPartTextureIndex_08E`** | R/W | `ClearSim`, `GetBodyPartTextureIndex`, `SetBodyPartTextureIndex` |
| 0x090 | `u32` | **`m_hairBodyPart`** | R/W | `ClearSim`, `DoStream`, `GetHairBodyPart` |
| 0x093 | `u8` | `m_field_093` | R | `DoStream` |
| 0x094 | `u32` | **`m_hairBodyPart_094`** | R/W | `ClearSim`, `GetHairBodyPart`, `Verify` |
| 0x098 | `u8` | **`m_bodyPartIndex_098`** | R/W | `ClearSim`, `GetBodyPartIndex`, `InitializeToDefaultCostume`, ... |
| 0x099 | `u8` | **`m_bodyPartTextureIndex_099`** | R/W | `ClearSim`, `GetBodyPartTextureIndex`, `SetBodyPartTextureIndex`, ... |
| 0x09C | `u32` | **`m_innerLayerTorsoStyle`** | R/W | `ClearSim`, `DoStream`, `SetInnerLayerTorsoStyle`, ... |
| 0x09F | `u8` | `m_field_09F` | R | `DoStream` |
| 0x0A0 | `u32` | `m_field_0A0` | R/W | `ClearSim`, `DoStream`, `SwitchInnerLayerSleeveToFirstAvailableStyle`, ... |
| 0x0A3 | `u8` | `m_field_0A3` | R | `DoStream` |
| 0x0A4 | `u8` | **`m_bodyPartIndex_0A4`** | R/W | `ClearSim`, `GetBodyPartIndex`, `SetBodyPartIndex`, ... |
| 0x0A5 | `u8` | **`m_bodyPartTextureIndex_0A5`** | R/W | `ClearSim`, `GetBodyPartTextureIndex`, `SetBodyPartTextureIndex`, ... |
| 0x0A8 | `u32` | `m_field_0A8` | R/W | `ClearSim`, `DoStream`, `SwitchMidLayerTorso`, ... |
| 0x0AB | `u8` | `m_field_0AB` | R | `DoStream` |
| 0x0AC | `u32` | `m_field_0AC` | R/W | `ClearSim`, `DoStream`, `SwitchMidLayerCollarToFirstAvailableStyle`, ... |
| 0x0AF | `u8` | `m_field_0AF` | R | `DoStream` |
| 0x0B0 | `u32` | `m_field_0B0` | R/W | `ClearSim`, `DoStream`, `SwitchMidLayerSleeveToFirstAvailableStyle`, ... |
| 0x0B3 | `u8` | `m_field_0B3` | R | `DoStream` |
| 0x0B4 | `u8` | **`m_bodyPartIndex_0B4`** | R/W | `ClearSim`, `GetBodyPartIndex`, `InnerLayerHalfTorsoRequired`, ... |
| 0x0B5 | `u8` | **`m_bodyPartTextureIndex_0B5`** | R/W | `ClearSim`, `GetBodyPartTextureIndex`, `SetBodyPartTextureIndex`, ... |
| 0x0B8 | `u32` | `m_field_0B8` | R/W | `ClearSim`, `DoStream`, `SwitchOuterLayerTorsoToFirstAvailableStyle`, ... |
| 0x0BB | `u8` | `m_field_0BB` | R | `DoStream` |
| 0x0BC | `u32` | `m_field_0BC` | R/W | `ClearSim`, `DoStream`, `SwitchOuterLayerCollarToFirstAvailableStyle`, ... |
| 0x0BF | `u8` | `m_field_0BF` | R | `DoStream` |
| 0x0C0 | `u32` | `m_field_0C0` | R/W | `ClearSim`, `DoStream`, `SwitchOuterLayerSleeveToFirstAvailableStyle`, ... |
| 0x0C3 | `u8` | `m_field_0C3` | R | `DoStream` |
| 0x0C4 | `u8` | **`m_bodyPartIndex_0C4`** | R/W | `ClearSim`, `GetBodyPartIndex`, `InitializeToDefaultCostume`, ... |
| 0x0C5 | `u8` | **`m_bodyPartTextureIndex_0C5`** | R/W | `ClearSim`, `GetBodyPartTextureIndex`, `SetBodyPartTextureIndex` |
| 0x0C8 | `u32` | `m_field_0C8` | R/W | `ClearSim`, `DoStream`, `ShouldBootTopBeDisplayed`, ... |
| 0x0CB | `u8` | `m_field_0CB` | R | `DoStream` |
| 0x0CC | `u8` | **`m_bodyPartIndex_0CC`** | R/W | `ClearSim`, `GetBodyPartIndex`, `InitializeToDefaultCostume`, ... |
| 0x0CD | `u8` | **`m_bodyPartTextureIndex_0CD`** | R/W | `ClearSim`, `GetBodyPartTextureIndex`, `SetBodyPartTextureIndex` |
| 0x0D0 | `u32` | `m_field_0D0` | R/W | `ClearSim`, `ShouldBootTopBeDisplayed`, `Verify` |
| 0x0D4 | `u8` | **`m_bodyPartIndex_0D4`** | R/W | `ClearSim`, `GetBodyPartIndex`, `SetBodyPartIndex` |
| 0x0D5 | `u8` | **`m_bodyPartIndex_0D5`** | R/W | `ClearSim`, `GetBodyPartIndex`, `SetBodyPartIndex`, ... |
| 0x0D6 | `u8` | **`m_bodyPartTextureIndex_0D6`** | R/W | `ClearSim`, `GetBodyPartTextureIndex`, `SetBodyPartTextureIndex` |
| 0x0D8 | `u32` | `m_field_0D8` | W | `ClearSim`, `DoStream`, `SwitchHatToFirstAvailableStyle` |
| 0x0DB | `u8` | `m_field_0DB` | R | `DoStream` |
| 0x0DC | `u8` | **`m_bodyPartIndex_0DC`** | R/W | `ClearSim`, `GetBodyPartIndex`, `SetBodyPartIndex` |
| 0x0DD | `u8` | **`m_bodyPartTextureIndex_0DD`** | R/W | `ClearSim`, `GetBodyPartTextureIndex`, `SetBodyPartTextureIndex` |
| 0x0E0 | `u32` | `m_field_0E0` | W | `ClearSim` |
| 0x0E4 | `u32` | `m_field_0E4` | W | `ClearSim` |
| 0x0E8 | `u8` | **`m_bodyPartIndex_0E8`** | R/W | `ClearSim`, `GetBodyPartIndex`, `SetBodyPartIndex` |
| 0x0E9 | `u8` | **`m_bodyPartTextureIndex_0E9`** | R/W | `ClearSim`, `GetBodyPartTextureIndex`, `SetBodyPartTextureIndex` |
| 0x0EA | `u8` | **`m_bodyPartIndex_0EA`** | R/W | `ClearSim`, `GetBodyPartIndex`, `SetBodyPartIndex` |
| 0x0EB | `u8` | **`m_bodyPartTextureIndex_0EB`** | R/W | `ClearSim`, `GetBodyPartTextureIndex`, `SetBodyPartTextureIndex` |
| 0x0EC | `u32` | `m_field_0EC` | W | `ClearSim`, `DoStream` |
| 0x0EF | `u8` | `m_field_0EF` | R | `DoStream` |
| 0x0F0 | `u8` | **`m_bodyPartIndex_0F0`** | R/W | `ClearSim`, `GetBodyPartIndex`, `SetBodyPartIndex` |
| 0x0F1 | `u8` | **`m_bodyPartTextureIndex_0F1`** | R/W | `ClearSim`, `GetBodyPartTextureIndex`, `SetBodyPartTextureIndex` |
| 0x0F8 | `f32` | **`m_bodyTypeMorphValues_0F8`** | R/W | `CasSimDescriptionS2C`, `ClearSim`, `SetBodyTypeMorphValues`, ... |
| 0x0FC | `f32` | **`m_bodyTypeMorphValues_0FC`** | R/W | `CasSimDescriptionS2C`, `ClearSim`, `SetBodyTypeMorphValues`, ... |
| 0x100 | `f32` | **`m_bodyTypeMorphValues_100`** | R/W | `CasSimDescriptionS2C`, `ClearSim`, `SetBodyTypeMorphValues`, ... |
| 0x104 | `f32` | `m_field_104` | R/W | `CasSimDescriptionS2C`, `ClearSim`, `Verify` |
| 0x108 | `f32` | `m_field_108` | R/W | `CasSimDescriptionS2C`, `ClearSim`, `Verify` |
| 0x10C | `f32` | `m_field_10C` | R/W | `CasSimDescriptionS2C`, `ClearSim`, `Verify` |
| 0x110 | `f32` | `m_field_110` | R/W | `CasSimDescriptionS2C`, `ClearSim`, `Verify` |
| 0x114 | `f32` | `m_field_114` | R/W | `CasSimDescriptionS2C`, `ClearSim`, `Verify` |
| 0x118 | `u32` | `m_field_118` | W | `ClearSim` |
| 0x121 | `u8` | `m_field_121` | R/W | `ClearSim`, `Verify` |

### `CasSimState`

**Size:** >= 0x120 (288 bytes) | **Fields:** 72 (47 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `void**` | **`_vtable` (vtable pointer)** | R/W | `CasSimState`, `HandleEventChangeSim`, `HandleEventInitSim`, ... |
| 0x004 | `u32` | `m_field_004` | W | `CasSimState`, `HandleEventInitSim`, `HandleEventStoreSim` |
| 0x008 | `u32` | `m_field_008` | W | `HandleEventInitSim`, `HandleEventStoreSim` |
| 0x00C | `u32` | `m_field_00C` | W | `HandleEventInitSim`, `HandleEventStoreSim` |
| 0x010 | `u32` | `m_field_010` | W | `HandleEventInitSim`, `HandleEventStoreSim` |
| 0x014 | `u32` | `m_field_014` | W | `HandleEventInitSim`, `HandleEventStoreSim` |
| 0x018 | `u8[0x32]` | _(gap)_ | - | - |
| 0x04A | `u16` | **`m_simName`** | W | `SetSimName` |
| 0x04C | `u8[0x40]` | _(gap)_ | - | - |
| 0x08C | `u32` | **`m_moreThanOneOption`** | R | `GetAdjacentIndex`, `GetMoreThanOneOption`, `HandleEventChangeSim`, ... |
| 0x090 | `u8` | **`m_adjacentIndex`** | R/W | `GetAdjacentIndex`, `HandleEventChangeSim` |
| 0x091 | `u8` | **`m_adjacentIndex_091`** | R/W | `GetAdjacentIndex`, `HandleEventChangeSim` |
| 0x092 | `u8` | **`m_moreThanOneOption_092`** | R/W | `GetAdjacentIndex`, `GetMoreThanOneOption`, `HandleEventChangeSim` |
| 0x093 | `u8` | **`m_adjacentIndex_093`** | R/W | `GetAdjacentIndex`, `HandleEventChangeSim` |
| 0x094 | `u8` | **`m_adjacentIndex_094`** | R/W | `GetAdjacentIndex`, `HandleEventChangeSim` |
| 0x095 | `u8` | **`m_moreThanOneOption_095`** | R/W | `GetAdjacentIndex`, `GetMoreThanOneOption`, `HandleEventChangeSim` |
| 0x096 | `u8` | **`m_adjacentIndex_096`** | R/W | `GetAdjacentIndex`, `HandleEventChangeSim` |
| 0x098 | `u32` | **`m_moreThanOneOption_098`** | R/W | `GetMoreThanOneOption`, `HandleEventChangeSim` |
| 0x09B | `u8` | `m_field_09B` | R | `HandleEventChangeSim` |
| 0x09C | `u32` | `m_field_09C` | W | `HandleEventChangeSim` |
| 0x0A0 | `u8` | **`m_moreThanOneOption_0A0`** | R/W | `GetAdjacentIndex`, `GetMoreThanOneOption`, `HandleEventChangeSim` |
| 0x0A1 | `u8` | **`m_adjacentIndex_0A1`** | R/W | `GetAdjacentIndex`, `HandleEventChangeSim` |
| 0x0A8 | `u32` | **`m_moreThanOneOption_0A8`** | R/W | `GetMoreThanOneOption`, `HandleEventChangeSim` |
| 0x0AB | `u8` | `m_field_0AB` | R | `HandleEventChangeSim` |
| 0x0AC | `u8` | **`m_moreThanOneOption_0AC`** | R/W | `GetAdjacentIndex`, `GetMoreThanOneOption`, `HandleEventChangeSim` |
| 0x0AD | `u8` | **`m_adjacentIndex_0AD`** | R/W | `GetAdjacentIndex`, `HandleEventChangeSim` |
| 0x0B0 | `u32` | **`m_moreThanOneOption_0B0`** | R/W | `GetMoreThanOneOption`, `HandleEventChangeSim` |
| 0x0B3 | `u8` | `m_field_0B3` | R | `HandleEventChangeSim` |
| 0x0B4 | `u32` | **`m_moreThanOneOption_0B4`** | R/W | `GetMoreThanOneOption`, `HandleEventChangeSim` |
| 0x0B7 | `u8` | `m_field_0B7` | R | `HandleEventChangeSim` |
| 0x0B8 | `u32` | **`m_moreThanOneOption_0B8`** | R/W | `GetMoreThanOneOption`, `HandleEventChangeSim` |
| 0x0BB | `u8` | `m_field_0BB` | R | `HandleEventChangeSim` |
| 0x0BC | `u8` | **`m_moreThanOneOption_0BC`** | R/W | `GetAdjacentIndex`, `GetMoreThanOneOption`, `HandleEventChangeSim` |
| 0x0BD | `u8` | **`m_adjacentIndex_0BD`** | R/W | `GetAdjacentIndex`, `HandleEventChangeSim` |
| 0x0C0 | `u32` | **`m_moreThanOneOption_0C0`** | R/W | `GetMoreThanOneOption`, `HandleEventChangeSim` |
| 0x0C3 | `u8` | `m_field_0C3` | R | `HandleEventChangeSim` |
| 0x0C4 | `u32` | **`m_moreThanOneOption_0C4`** | R/W | `GetMoreThanOneOption`, `HandleEventChangeSim` |
| 0x0C7 | `u8` | `m_field_0C7` | R | `HandleEventChangeSim` |
| 0x0C8 | `u32` | **`m_moreThanOneOption_0C8`** | R/W | `GetMoreThanOneOption`, `HandleEventChangeSim` |
| 0x0CB | `u8` | `m_field_0CB` | R | `HandleEventChangeSim` |
| 0x0CC | `u8` | **`m_moreThanOneOption_0CC`** | R/W | `GetAdjacentIndex`, `GetMoreThanOneOption`, `HandleEventChangeSim` |
| 0x0CD | `u8` | **`m_adjacentIndex_0CD`** | R/W | `GetAdjacentIndex`, `HandleEventChangeSim` |
| 0x0D0 | `u32` | **`m_moreThanOneOption_0D0`** | R/W | `GetMoreThanOneOption`, `HandleEventChangeSim` |
| 0x0D3 | `u8` | `m_field_0D3` | R | `HandleEventChangeSim` |
| 0x0D4 | `u8` | **`m_moreThanOneOption_0D4`** | R/W | `GetAdjacentIndex`, `GetMoreThanOneOption`, `HandleEventChangeSim` |
| 0x0D5 | `u8` | **`m_adjacentIndex_0D5`** | R/W | `GetAdjacentIndex`, `HandleEventChangeSim` |
| 0x0DC | `u8` | **`m_adjacentIndex_0DC`** | R/W | `GetAdjacentIndex`, `HandleEventChangeSim` |
| 0x0DD | `u8` | **`m_moreThanOneOption_0DD`** | R/W | `GetAdjacentIndex`, `GetMoreThanOneOption`, `HandleEventChangeSim` |
| 0x0DE | `u8` | **`m_adjacentIndex_0DE`** | R/W | `GetAdjacentIndex`, `HandleEventChangeSim` |
| 0x0E0 | `u32` | **`m_moreThanOneOption_0E0`** | R/W | `GetMoreThanOneOption`, `HandleEventChangeSim` |
| 0x0E3 | `u8` | `m_field_0E3` | R | `HandleEventChangeSim` |
| 0x0E4 | `u8` | **`m_moreThanOneOption_0E4`** | R/W | `GetAdjacentIndex`, `GetMoreThanOneOption`, `HandleEventChangeSim` |
| 0x0E5 | `u8` | **`m_adjacentIndex_0E5`** | R/W | `GetAdjacentIndex`, `HandleEventChangeSim` |
| 0x0E8 | `u32` | **`m_adjacentIndex_0E8`** | R/W | `GetAdjacentIndex`, `HandleEventChangeSim` |
| 0x0EC | `u32` | **`m_adjacentIndex_0EC`** | R/W | `GetAdjacentIndex`, `HandleEventChangeSim` |
| 0x0F0 | `u8` | **`m_moreThanOneOption_0F0`** | R/W | `GetAdjacentIndex`, `GetMoreThanOneOption`, `HandleEventChangeSim` |
| 0x0F1 | `u8` | **`m_adjacentIndex_0F1`** | R/W | `GetAdjacentIndex`, `HandleEventChangeSim` |
| 0x0F2 | `u8` | **`m_moreThanOneOption_0F2`** | R/W | `GetAdjacentIndex`, `GetMoreThanOneOption`, `HandleEventChangeSim` |
| 0x0F3 | `u8` | **`m_adjacentIndex_0F3`** | R/W | `GetAdjacentIndex`, `HandleEventChangeSim` |
| 0x0F4 | `u32` | **`m_moreThanOneOption_0F4`** | R/W | `GetMoreThanOneOption`, `HandleEventChangeSim` |
| 0x0F7 | `u8` | `m_field_0F7` | R | `HandleEventChangeSim` |
| 0x0F8 | `u8` | **`m_moreThanOneOption_0F8`** | R/W | `GetAdjacentIndex`, `GetMoreThanOneOption`, `HandleEventChangeSim` |
| 0x0F9 | `u8` | **`m_adjacentIndex_0F9`** | R/W | `GetAdjacentIndex`, `HandleEventChangeSim` |
| 0x0FA | `u8` | **`m_adjacentIndex_0FA`** | R/W | `GetAdjacentIndex`, `HandleEventChangeSim` |
| 0x0FB | `u8` | **`m_adjacentIndex_0FB`** | R/W | `GetAdjacentIndex`, `HandleEventChangeSim` |
| 0x0FC | `u8` | **`m_adjacentIndex_0FC`** | R/W | `GetAdjacentIndex`, `HandleEventChangeSim` |
| 0x100 | `f32` | `m_field_100` | W | `HandleEventMorphSim` |
| 0x104 | `f32` | `m_field_104` | W | `HandleEventMorphSim` |
| 0x108 | `f32` | `m_field_108` | W | `HandleEventMorphSim` |
| 0x10C | `f32` | `m_field_10C` | W | `HandleEventMorphSim` |
| 0x110 | `f32` | `m_field_110` | W | `HandleEventMorphSim` |
| 0x114 | `f32` | `m_field_114` | W | `HandleEventMorphSim` |
| 0x118 | `f32` | `m_field_118` | W | `HandleEventMorphSim` |
| 0x11C | `f32` | `m_field_11C` | W | `HandleEventMorphSim` |

### `G2DTarget`

**Size:** >= 0xDE0 (3552 bytes) | **Fields:** 72 (40 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `u16` | **`m_localizable`** | R/W | `CalculateBackgroundSize`, `G2DTarget`, `GetLocalizable`, ... |
| 0x004 | `u16` | **`m_variable`** | R/W | `G2DTarget`, `GetVariable`, `~G2DTarget` |
| 0x006 | `u8` | **`m_variable_006`** | W | `GetVariable` |
| 0x008 | `u32` | `m_field_008` | R/W | `G2DTarget`, `~G2DTarget` |
| 0x00C | `u32` | `m_field_00C` | R/W | `CalculateBackgroundSize`, `G2DTarget`, `~G2DTarget` |
| 0x010 | `u32` | `m_field_010` | R/W | `G2DTarget`, `SpawnDialog`, `UnloadDialog`, ... |
| 0x014 | `u32` | `m_field_014` | R/W | `G2DTarget`, `~G2DTarget` |
| 0x018 | `u32` | `m_field_018` | R/W | `G2DTarget`, `~G2DTarget` |
| 0x01C | `u32` | **`m_icon`** | R/W | `G2DTarget`, `SetIcon`, `SetupDialogData`, ... |
| 0x020 | `u32` | `m_field_020` | R/W | `G2DTarget`, `~G2DTarget` |
| 0x024 | `u32` | `m_field_024` | R/W | `G2DTarget`, `~G2DTarget` |
| 0x028 | `u32` | `m_field_028` | W | `G2DTarget` |
| 0x038 | `u32` | `m_field_038` | W | `G2DTarget` |
| 0x048 | `u32` | `m_field_048` | W | `G2DTarget` |
| 0x058 | `u32` | `m_field_058` | R/W | `G2DTarget`, `SpawnDialog`, `UnloadDialog`, ... |
| 0x068 | `u32` | `m_field_068` | R/W | `G2DTarget`, `~G2DTarget` |
| 0x078 | `u32` | `m_field_078` | W | `G2DTarget` |
| 0x07C | `u32` | **`m_icon_07C`** | R/W | `G2DTarget`, `PushAptButtonFiltersForPlayer`, `SetIcon`, ... |
| 0x080 | `u32` | `m_field_080` | W | `G2DTarget`, `~G2DTarget` |
| 0x084 | `u32` | `m_field_084` | W | `G2DTarget`, `SpawnDialog`, `UnloadDialog` |
| 0x088 | `u32` | **`m_variable_088`** | R/W | `G2DTarget`, `GetVariable`, `UnloadDialog`, ... |
| 0x08C | `u32` | **`m_variable_08C`** | W | `G2DTarget`, `GetVariable`, `SetVariable`, ... |
| 0x090 | `u32` | `m_field_090` | R/W | `G2DTarget`, `Update` |
| 0x094 | `u32` | `m_field_094` | R/W | `G2DTarget`, `Update` |
| 0x098 | `u32` | `m_field_098` | R/W | `G2DTarget`, `ServiceG2DShutdown`, `SpawnDialog`, ... |
| 0x09C | `u32` | **`m_upDialogData`** | R/W | `CheckPlayerInput`, `SetupDialogData` |
| 0x0A0 | `u32` | **`m_upDialogData_0A0`** | W | `G2DTarget`, `SetupDialogData` |
| 0x0A4 | `u32` | **`m_variable_0A4`** | R/W | `CalculateBackgroundSize`, `ChangeContinueType`, `CheckPlayerInput`, ... |
| 0x0A8 | `u32` | **`m_upDialogData_0A8`** | R/W | `SetupDialogData`, `SpawnDialog` |
| 0x0AC | `u32` | **`m_upDialogData_0AC`** | R/W | `ChangeContinueType`, `G2DTarget`, `SetupDialogData` |
| 0x0B0 | `u32` | **`m_upWidgets`** | R/W | `G2DTarget`, `ReflowButtonSelection`, `SetVariable`, ... |
| 0x0B4 | `u32` | **`m_upDialogData_0B4`** | W | `G2DTarget`, `SetupDialogData` |
| 0x0B8 | `u32` | **`m_upDialogData_0B8`** | R/W | `G2DTarget`, `SetupDialogData`, `Update` |
| 0x0BC | `u32` | **`m_upDialogData_0BC`** | R/W | `G2DTarget`, `SetupDialogData`, `Update` |
| 0x0C0 | `u32` | **`m_variable_0C0`** | R/W | `G2DTarget`, `SetVariable`, `SetupDialogData` |
| 0x0C4 | `u32` | **`m_upDialogData_0C4`** | R/W | `ExecuteDialogClosedCallback`, `G2DTarget`, `HideDialog`, ... |
| 0x0C8 | `u32` | **`m_upDialogData_0C8`** | R/W | `G2DTarget`, `ReflowButtonSelection`, `SetVariable`, ... |
| 0x0CC | `u32` | **`m_upDialogData_0CC`** | R/W | `CalculateBackgroundSize`, `G2DTarget`, `SetupDialogData`, ... |
| 0x0D0 | `s16` | **`m_upDialogData_0D0`** | R/W | `CalculateBackgroundSize`, `G2DTarget`, `SetIcon`, ... |
| 0x0D2 | `s16` | **`m_upDialogData_0D2`** | R/W | `CalculateBackgroundSize`, `G2DTarget`, `SetIcon`, ... |
| 0x0D4 | `u32` | **`m_variable_0D4`** | R/W | `CalculateBackgroundSize`, `G2DTarget`, `GetVariable`, ... |
| 0x0D8 | `u32` | **`m_variable_0D8`** | R/W | `CalculateBackgroundSize`, `G2DTarget`, `GetVariable` |
| 0x0DC | `f32` | **`m_upWidgets_0DC`** | R/W | `CalculateBackgroundSize`, `SetupWidgets` |
| 0x0E0 | `f32` | `m_field_0E0` | R/W | `CalculateBackgroundSize` |
| 0x0E4 | `f32` | **`m_upWidgets_0E4`** | R/W | `CalculateBackgroundSize`, `SetupWidgets` |
| 0x0E8 | `f32` | **`m_upWidgets_0E8`** | R/W | `CalculateBackgroundSize`, `SetupWidgets` |
| 0x0EC | `f32` | **`m_upWidgets_0EC`** | R/W | `CalculateBackgroundSize`, `SetupWidgets` |
| 0x0F0 | `f32` | **`m_upWidgets_0F0`** | R/W | `CalculateBackgroundSize`, `SetupWidgets` |
| 0x0F4 | `f32` | **`m_upWidgets_0F4`** | R/W | `CalculateBackgroundSize`, `SetupWidgets` |
| 0x0F8 | `f32` | **`m_upWidgets_0F8`** | R/W | `CalculateBackgroundSize`, `SetupWidgets` |
| 0x0FC | `u8[0x14]` | _(gap)_ | - | - |
| 0x110 | `u32` | **`m_upDialogData_110`** | R/W | `ExecuteSelectionCallback`, `HideDialog`, `SetupDialogData`, ... |
| 0x114 | `u32` | **`m_upDialogData_114`** | R/W | `ExecuteZeroInputCallback`, `HideDialog`, `SetupDialogData`, ... |
| 0x118 | `u32` | **`m_upDialogData_118`** | R/W | `ExecuteDialogClosedCallback`, `HideDialog`, `SetupDialogData`, ... |
| 0x11C | `u32` | **`m_upDialogData_11C`** | R/W | `G2DTarget`, `SetupDialogData` |
| 0x120 | `u32` | `m_field_120` | W | `G2DTarget` |
| 0x124 | `u32` | `m_field_124` | W | `G2DTarget` |
| 0x128 | `f32` | **`m_variable_128`** | R/W | `SetVariable`, `SpawnDialog` |
| 0x12C | `f32` | **`m_variable_12C`** | R/W | `G2DTarget`, `SetVariable`, `SpawnDialog`, ... |
| 0x130 | `u32` | **`m_upDialogData_130`** | R/W | `G2DTarget`, `SetupDialogData`, `Update` |
| 0x134 | `u32` | **`m_variable_134`** | R/W | `G2DTarget`, `GetVariable`, `HideDialog`, ... |
| 0x138 | `u8[0x14]` | _(gap)_ | - | - |
| 0x14C | `u32` | **`m_variable_14C`** | R/W | `GetVariable`, `UnloadDialog` |
| 0x150 | `u32` | `m_field_150` | R/W | `ReflowButtonSelection` |
| 0x154 | `u32` | `m_field_154` | R/W | `ReflowButtonSelection` |
| 0x158 | `u32` | `m_field_158` | R/W | `ReflowButtonSelection` |
| 0x15C | `u32` | `m_field_15C` | R/W | `ReflowButtonSelection` |
| 0x160 | `u32` | `m_field_160` | R/W | `ReflowButtonSelection` |
| 0x164 | `u32` | `m_field_164` | R/W | `ReflowButtonSelection` |
| 0x168 | `u32` | `m_field_168` | R/W | `ReflowButtonSelection` |
| 0x16C | `u32` | `m_field_16C` | R/W | `ReflowButtonSelection` |
| 0x170 | `u32` | `m_field_170` | R/W | `ReflowButtonSelection` |
| 0x174 | `u8[0xC58]` | _(gap)_ | - | - |
| 0xDCC | `f32` | `m_field_DCC` | R | `CalculateBackgroundSize` |
| 0xDD8 | `f64` | `m_field_DD8` | R | `CalculateBackgroundSize` |

### `PCTTarget`

**Size:** >= 0x47F4 (18420 bytes) | **Fields:** 70 (27 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `u16` | **`m_localizable`** | R/W | `GetLocalizable`, `PCTTarget`, `SetVariable`, ... |
| 0x002 | `u16` | `m_field_002` | W | `PlaceModeCallback` |
| 0x004 | `f32` | **`m_localizable_004`** | R/W | `GetLocalizable`, `PCTTarget`, `PlaceModeCallback`, ... |
| 0x008 | `f32` | `m_field_008` | R/W | `PCTTarget`, `cCellInfo::GetName`, `cCellInfo::Init`, ... |
| 0x00C | `s16` | **`m_localizable_00C`** | R/W | `GetLocalizable`, `GetVariable`, `PCTTarget`, ... |
| 0x010 | `u32` | `m_field_010` | R/W | `PCTTarget`, `cCellInfo::Init`, `calc_motive_ratings`, ... |
| 0x014 | `u16` | **`m_localizable_014`** | R/W | `GetLocalizable`, `PCTTarget`, `cCellInfo::GetDesc`, ... |
| 0x018 | `u8` | `m_field_018` | R/W | `PCTTarget`, `enter_place_mode`, `enter_place_tombstone_mode`, ... |
| 0x01C | `f32` | **`m_variable`** | R/W | `PCTTarget`, `SetVariable`, `cCellInfo::Init`, ... |
| 0x020 | `u16` | `m_field_020` | R/W | `PCTTarget`, `enter_floor_mode`, `enter_place_mode`, ... |
| 0x024 | `s16` | `m_field_024` | R/W | `PCTTarget`, `PlaceModeCallback`, `cCellInfo::GetPrice`, ... |
| 0x028 | `u32` | `m_field_028` | W | `PCTTarget` |
| 0x02C | `u32` | `m_field_02C` | R | `enter_floor_mode`, `enter_place_mode`, `enter_place_tombstone_mode`, ... |
| 0x038 | `u32` | **`m_localizable_038`** | R/W | `GetLocalizable`, `PCTTarget`, `PlaceModeCallback`, ... |
| 0x03C | `u8` | `m_field_03C` | R/W | `enter_floor_mode`, `enter_place_mode`, `enter_place_tombstone_mode`, ... |
| 0x048 | `u32` | `m_field_048` | W | `PCTTarget` |
| 0x058 | `u32` | `m_field_058` | R/W | `PCTTarget`, `~PCTTarget` |
| 0x068 | `u32` | `m_field_068` | R/W | `PCTTarget`, `~PCTTarget` |
| 0x074 | `u32` | **`m_variable_074`** | R/W | `SetVariable` |
| 0x078 | `u32` | `m_field_078` | W | `PCTTarget` |
| 0x07C | `u32` | **`m_variable_07C`** | R/W | `PCTTarget`, `SetVariable`, `on_selection_changed`, ... |
| 0x080 | `u32` | **`m_variable_080`** | R/W | `PCTTarget`, `SetVariable`, `~PCTTarget` |
| 0x084 | `u32` | `m_field_084` | R/W | `FloorPainterCallback`, `GrabManipulatorCallback`, `PCTTarget`, ... |
| 0x088 | `u32` | `m_field_088` | R/W | `PCTTarget`, `~PCTTarget` |
| 0x08C | `u32` | `m_field_08C` | R/W | `PCTTarget`, `~PCTTarget` |
| 0x090 | `u32` | **`m_variable_090`** | R/W | `GetVariable`, `PCTTarget`, `PlaceModeCallback`, ... |
| 0x094 | `u32` | **`m_variable_094`** | R/W | `PCTTarget`, `SetVariable` |
| 0x098 | `u32` | **`m_variable_098`** | R/W | `GetVariable`, `PCTTarget`, `SetVariable` |
| 0x09C | `u32` | `m_field_09C` | R/W | `PCTTarget`, `on_tab_changed_floor`, `on_tab_changed_objects`, ... |
| 0x0A0 | `u32` | `m_field_0A0` | R/W | `PCTTarget`, `on_tab_changed_objects` |
| 0x0A4 | `u32` | `m_field_0A4` | R/W | `PCTTarget`, `on_tab_changed_objects`, `~PCTTarget` |
| 0x0A8 | `u32` | **`m_localizable_0A8`** | R/W | `GetLocalizable`, `GetVariable`, `PCTTarget`, ... |
| 0x0AC | `u32` | **`m_variable_0AC`** | R/W | `GetVariable`, `PCTTarget`, `SetVariable`, ... |
| 0x0B0 | `u32` | **`m_localizable_0B0`** | R/W | `GetLocalizable`, `GetVariable`, `PCTTarget`, ... |
| 0x0B4 | `u32` | **`m_variable_0B4`** | R/W | `GetVariable`, `PCTTarget`, `on_PCT_Scroll`, ... |
| 0x0B8 | `u32` | **`m_localizable_0B8`** | R/W | `GetLocalizable`, `GetVariable`, `PCTTarget`, ... |
| 0x0BC | `u32` | `m_field_0BC` | R/W | `PCTTarget`, `calc_motive_ratings`, `get_cell_info_at_gridindex`, ... |
| 0x0C0 | `u32` | **`m_variable_0C0`** | R/W | `GetVariable`, `PCTTarget`, `calc_motive_ratings`, ... |
| 0x0C4 | `u32` | **`m_variable_0C4`** | R/W | `GetVariable`, `PCTTarget`, `on_selection_changed` |
| 0x0C8 | `u32` | **`m_variable_0C8`** | R/W | `GetVariable`, `PCTTarget`, `on_selection_changed` |
| 0x0CC | `u32` | `m_field_0CC` | R | `on_selection_changed` |
| 0x0D0 | `u32` | `m_field_0D0` | R | `on_selection_changed` |
| 0x0D4 | `u32` | `m_field_0D4` | R | `on_selection_changed` |
| 0x0D8 | `u32` | `m_field_0D8` | R | `on_selection_changed` |
| 0x0DC | `u32` | `m_field_0DC` | R | `on_selection_changed` |
| 0x0E0 | `u32` | `m_field_0E0` | R | `on_selection_changed` |
| 0x0E4 | `u32` | `m_field_0E4` | R/W | `CreateGrabObjectMenu`, `PCTTarget`, `Update`, ... |
| 0x0E8 | `u32` | `m_field_0E8` | R/W | `PCTTarget`, `WallManipulatorCallback`, `WallPainterCallback`, ... |
| 0x0EC | `u32` | `m_field_0EC` | R/W | `PCTTarget`, `on_PCT_SetVisible`, `on_PCT_ShowHelp` |
| 0x0F0 | `u32` | **`m_variable_0F0`** | R/W | `GetVariable`, `GrabManipulatorCallback`, `PCTTarget`, ... |
| 0x0F4 | `u32` | `m_field_0F4` | W | `GrabManipulatorCallback`, `PCTTarget`, `Update`, ... |
| 0x0F8 | `u32` | `m_field_0F8` | W | `GrabManipulatorCallback`, `Update`, `on_PCT_EnterPlaceMode` |
| 0x100 | `u32` | `m_field_100` | W | `GrabManipulatorCallback` |
| 0x108 | `u32` | `m_field_108` | W | `GrabManipulatorCallback`, `on_PCT_EnterPlaceMode` |
| 0x10C | `u8[0x38]` | _(gap)_ | - | - |
| 0x144 | `u32` | `m_field_144` | W | `GrabManipulatorCallback`, `PCTTarget`, `Update`, ... |
| 0x154 | `u32` | `m_field_154` | W | `GrabManipulatorCallback`, `PCTTarget`, `Update`, ... |
| 0x164 | `u32` | `m_field_164` | W | `GrabManipulatorCallback`, `PCTTarget`, `Update`, ... |
| 0x168 | `u8[0x9C]` | _(gap)_ | - | - |
| 0x204 | `u32` | **`m_variable_204`** | R | `GetVariable`, `SetVariable` |
| 0x20C | `u32` | **`m_variable_20C`** | R/W | `FloorPainterCallback`, `GetVariable`, `PCTTarget`, ... |
| 0x210 | `u32` | `m_field_210` | R/W | `PCTTarget`, `calc_floor_tile_value`, `calc_wall_value`, ... |
| 0x214 | `u32` | **`m_localizable_214`** | R/W | `FloorPainterCallback`, `GetLocalizable`, `GrabManipulatorCallback`, ... |
| 0x218 | `u32` | `m_field_218` | R/W | `PCTTarget`, `on_selection_changed`, `on_tab_changed_objects`, ... |
| 0x21C | `u32` | `m_field_21C` | R/W | `PCTTarget`, `on_selection_changed`, `~PCTTarget` |
| 0x22C | `u32` | `m_field_22C` | R/W | `PCTTarget`, `PlaceModeCallback` |
| 0x230 | `u32` | `m_field_230` | R/W | `PCTTarget`, `PlaceModeCallback` |
| 0x234 | `u32` | **`m_variable_234`** | R/W | `GetVariable`, `PCTTarget`, `PlaceModeCallback`, ... |
| 0x238 | `u32` | **`m_variable_238`** | R/W | `GetVariable`, `PCTTarget`, `PlaceModeCallback`, ... |
| 0x23C | `u32` | **`m_variable_23C`** | R/W | `GetVariable`, `PCTTarget`, `PlaceModeCallback`, ... |
| 0x240 | `u32` | `m_field_240` | R/W | `PCTTarget`, `PlaceModeCallback`, `~PCTTarget` |
| 0x244 | `u8[0x45AC]` | _(gap)_ | - | - |
| 0x47F0 | `f32` | `m_field_47F0` | R | `enter_tool_mode` |

### `M2MTarget`

**Size:** >= 0x23E8 (9192 bytes) | **Fields:** 69 (26 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `u16` | **`m_localizable`** | R/W | `GetLocalizable`, `GetVariable`, `M2MTarget`, ... |
| 0x004 | `u16` | **`m_variable`** | R/W | `GetVariable`, `M2MTarget`, `~M2MTarget` |
| 0x006 | `u8` | **`m_variable_006`** | W | `GetVariable` |
| 0x008 | `u32` | `m_field_008` | R/W | `M2MTarget`, `~M2MTarget` |
| 0x00C | `u32` | **`m_upWidgetLayout`** | R/W | `M2MTarget`, `SetupWidgetLayout`, `~M2MTarget` |
| 0x010 | `u32` | `m_field_010` | R/W | `M2MTarget`, `~M2MTarget` |
| 0x014 | `u32` | `m_field_014` | R/W | `M2MTarget`, `~M2MTarget` |
| 0x018 | `u32` | `m_field_018` | R/W | `M2MTarget`, `~M2MTarget` |
| 0x01C | `u32` | `m_field_01C` | R/W | `M2MTarget`, `~M2MTarget` |
| 0x020 | `u32` | `m_field_020` | R/W | `M2MTarget`, `~M2MTarget` |
| 0x024 | `u32` | `m_field_024` | R/W | `M2MTarget`, `~M2MTarget` |
| 0x028 | `u32` | `m_field_028` | W | `M2MTarget` |
| 0x038 | `u32` | `m_field_038` | W | `M2MTarget` |
| 0x03C | `u32` | `m_field_03C` | W | `M2MTarget` |
| 0x040 | `u32` | `m_field_040` | W | `M2MTarget` |
| 0x044 | `u32` | `m_field_044` | W | `M2MTarget` |
| 0x048 | `u16` | `m_field_048` | W | `M2MTarget` |
| 0x04A | `u16` | `m_field_04A` | W | `M2MTarget` |
| 0x04C | `u32` | `m_field_04C` | W | `M2MTarget` |
| 0x058 | `u32` | `m_field_058` | R/W | `M2MTarget`, `~M2MTarget` |
| 0x068 | `u32` | `m_field_068` | R/W | `M2MTarget`, `~M2MTarget` |
| 0x078 | `u32` | `m_field_078` | W | `M2MTarget` |
| 0x07C | `u32` | `m_field_07C` | R/W | `M2MTarget`, `PushButtonFilters`, `~M2MTarget` |
| 0x080 | `u32` | **`m_upWidgetLayout_080`** | R/W | `M2MTarget`, `SetupWidgetLayout`, `~M2MTarget` |
| 0x084 | `u32` | `m_field_084` | W | `M2MTarget`, `SpawnConfirmStartNewGameDialog`, `SpawnContinueNoMemCardDialog`, ... |
| 0x088 | `u32` | `m_field_088` | W | `SpawnConfirmStartNewGameDialog`, `SpawnContinueNoMemCardDialog`, `SpawnNoSaveBeforeQuitDialog`, ... |
| 0x08C | `u32` | `m_field_08C` | W | `SpawnConfirmStartNewGameDialog`, `SpawnContinueNoMemCardDialog`, `SpawnNoSaveBeforeQuitDialog`, ... |
| 0x090 | `u32` | `m_field_090` | W | `SpawnConfirmStartNewGameDialog`, `SpawnContinueNoMemCardDialog`, `SpawnNoSaveBeforeQuitDialog`, ... |
| 0x094 | `u32` | `m_field_094` | W | `SpawnConfirmStartNewGameDialog`, `SpawnContinueNoMemCardDialog`, `SpawnNoSaveBeforeQuitDialog`, ... |
| 0x098 | `u32` | `m_field_098` | W | `SpawnConfirmStartNewGameDialog`, `SpawnContinueNoMemCardDialog`, `SpawnNoSaveBeforeQuitDialog`, ... |
| 0x0A0 | `u32` | `m_field_0A0` | W | `SpawnConfirmStartNewGameDialog`, `SpawnContinueNoMemCardDialog`, `SpawnNoSaveBeforeQuitDialog`, ... |
| 0x0A4 | `u32` | `m_field_0A4` | W | `SpawnConfirmStartNewGameDialog`, `SpawnContinueNoMemCardDialog`, `SpawnNoSaveBeforeQuitDialog`, ... |
| 0x0A8 | `u8[0x18]` | _(gap)_ | - | - |
| 0x0C0 | `u32` | `m_field_0C0` | W | `SpawnConfirmStartNewGameDialog`, `SpawnContinueNoMemCardDialog`, `SpawnNoSaveBeforeQuitDialog`, ... |
| 0x0CC | `u16` | `m_field_0CC` | W | `SpawnConfirmStartNewGameDialog`, `SpawnContinueNoMemCardDialog`, `SpawnNoSaveBeforeQuitDialog`, ... |
| 0x0CE | `u16` | `m_field_0CE` | W | `SpawnConfirmStartNewGameDialog`, `SpawnContinueNoMemCardDialog`, `SpawnNoSaveBeforeQuitDialog`, ... |
| 0x0D0 | `u32` | `m_field_0D0` | W | `SpawnConfirmStartNewGameDialog`, `SpawnContinueNoMemCardDialog`, `SpawnNoSaveBeforeQuitDialog`, ... |
| 0x0D4 | `u32` | `m_field_0D4` | W | `M2MTarget` |
| 0x0E4 | `u32` | `m_field_0E4` | W | `M2MTarget` |
| 0x0F4 | `u32` | `m_field_0F4` | W | `M2MTarget` |
| 0x104 | `u32` | `m_field_104` | W | `M2MTarget` |
| 0x108 | `u32` | `m_field_108` | W | `M2MTarget`, `~M2MTarget` |
| 0x10C | `u32` | **`m_localizable_10C`** | R/W | `GetLocalizable`, `IsItemEnabled`, `M2MTarget`, ... |
| 0x110 | `u32` | **`m_localizable_110`** | R/W | `GetLocalizable`, `IsItemEnabled`, `OnCancel`, ... |
| 0x114 | `u32` | `m_field_114` | R | `StartLoadedGame` |
| 0x118 | `u32` | **`m_currState`** | R/W | `M2MTarget`, `OnSaveLoadFailed`, `OnSaveLoadSucceed`, ... |
| 0x11C | `u32` | **`m_localizable_11C`** | R/W | `DialogClosedCallback`, `GetLocalizable`, `M2MTarget`, ... |
| 0x120 | `u8[0x38]` | _(gap)_ | - | - |
| 0x158 | `u32` | `m_field_158` | R/W | `OnSaveLoadFailed`, `StartNGCMemoryCardBootChecks` |
| 0x15C | `u32` | `m_field_15C` | R/W | `OnSaveLoadFailed`, `StartNGCMemoryCardBootChecks` |
| 0x160 | `u32` | **`m_variable_160`** | R/W | `GetVariable`, `M2MTarget`, `SetupWidgetLayout` |
| 0x164 | `u32` | **`m_variable_164`** | R/W | `GetVariable`, `M2MTarget`, `SetupWidgetLayout` |
| 0x168 | `u32` | **`m_localizable_168`** | R/W | `CalcNumItems`, `DialogClosedCallback`, `GetLocalizable`, ... |
| 0x16C | `u32` | **`m_widgetState`** | R/W | `M2MTarget`, `Update`, `UpdateWidgetState` |
| 0x170 | `u32` | `m_field_170` | R/W | `PopButtonFilters`, `PushButtonFilters` |
| 0x174 | `u32` | `m_field_174` | R/W | `PopButtonFilters`, `PushButtonFilters` |
| 0x178 | `u32` | **`m_bIsItemEnabledMemCardSelect`** | R/W | `IsItemEnabledMemCardSelect`, `M2MTarget`, `Update` |
| 0x17C | `u32` | **`m_bIsItemEnabledMemCardSelect_17C`** | R/W | `IsItemEnabledMemCardSelect`, `M2MTarget`, `Update` |
| 0x180 | `u32` | `m_field_180` | R/W | `M2MTarget`, `OnCancel`, `OnSaveLoadFailed`, ... |
| 0x184 | `u32` | **`m_variable_184`** | R/W | `M2MTarget`, `SetCurrState`, `SetVariable`, ... |
| 0x188 | `u32` | **`m_upWidgetLayout_188`** | R/W | `CalcNumItems`, `FillWidget`, `M2MTarget`, ... |
| 0x18C | `u32` | **`m_variable_18C`** | R/W | `FillWidget`, `M2MTarget`, `ReflowButtonSelection`, ... |
| 0x190 | `u32` | `m_field_190` | R/W | `M2MTarget`, `PushButtonFilters`, `SpawnConfirmStartNewGameDialog`, ... |
| 0x194 | `u32` | **`m_currState_194`** | R/W | `M2MTarget`, `SetCurrState` |
| 0x198 | `u8[0x220C]` | _(gap)_ | - | - |
| 0x23A4 | `f32` | **`m_upWidgetLayout_23A4`** | R | `SetupWidgetLayout` |
| 0x23A8 | `f32` | **`m_upWidgetLayout_23A8`** | R | `SetupWidgetLayout` |
| 0x23AC | `f32` | **`m_upWidgetLayout_23AC`** | R | `SetupWidgetLayout` |
| 0x23B0 | `u8[0x18]` | _(gap)_ | - | - |
| 0x23C8 | `f64` | **`m_upWidgetLayout_23C8`** | R | `SetupWidgetLayout` |
| 0x23D0 | `f64` | **`m_upWidgetLayout_23D0`** | R | `SetupWidgetLayout` |
| 0x23DC | `f32` | **`m_upWidgetLayout_23DC`** | R | `SetupWidgetLayout` |
| 0x23E4 | `f32` | **`m_upWidgetLayout_23E4`** | R | `SetupWidgetLayout` |

### `ESimsCam`

**Size:** >= 0x570 (1392 bytes) | **Fields:** 66 (32 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `f32` | **`m_fov`** | R/W | `ApplyNoise`, `ApplyZoom`, `CalRoomId`, ... |
| 0x002 | `u16` | **`m_win`** | R | `UpdateWin` |
| 0x004 | `f32` | **`m_containingRoomId`** | R/W | `ApplyNoise`, `CalcPitch`, `CalcZAxisTheta`, ... |
| 0x008 | `f32` | **`m_cursorPos`** | R/W | `ApplyNoise`, `CalcPitch`, `CalcZAxisTheta`, ... |
| 0x010 | `u32` | `m_field_010` | R | `Update` |
| 0x018 | `u32` | **`m_objectPosition`** | R | `GetObjectOrientation`, `GetObjectPosition` |
| 0x01C | `u8[0x14]` | _(gap)_ | - | - |
| 0x030 | `u32` | `m_field_030` | R | `ApplyNoise` |
| 0x044 | `u32` | `m_field_044` | R | `CursorNotActive` |
| 0x048 | `u32` | `m_field_048` | R | `CursorNotActive` |
| 0x04C | `u8[0x64]` | _(gap)_ | - | - |
| 0x0B0 | `f32` | **`m_nearPlane`** | R | `GetNearPlane` |
| 0x0B4 | `u8[0x34]` | _(gap)_ | - | - |
| 0x0E8 | `s16` | **`m_containingRoomId_0E8`** | R | `GetContainingRoomId` |
| 0x0EA | `u8[0x276]` | _(gap)_ | - | - |
| 0x360 | `f32` | `m_field_360` | R/W | `ValidateCursorPosition` |
| 0x36C | `f32` | `m_field_36C` | R/W | `ValidateCursorPosition` |
| 0x378 | `f32` | `m_field_378` | R | `ValidateCursorPosition` |
| 0x384 | `f32` | `m_field_384` | R | `ValidateCursorPosition` |
| 0x390 | `f32` | **`m_win_390`** | R/W | `UpdateWin` |
| 0x39C | `f32` | **`m_win_39C`** | R/W | `UpdateWin` |
| 0x3A8 | `f32` | **`m_win_3A8`** | R/W | `UpdateWin` |
| 0x3B4 | `f32` | **`m_win_3B4`** | R/W | `UpdateWin` |
| 0x3B8 | `u8[0x14]` | _(gap)_ | - | - |
| 0x3CC | `u32` | **`m_mode`** | R/W | `CenterOnSelectedSim`, `SetMode`, `Update` |
| 0x3D0 | `u32` | **`m_mode_3D0`** | R/W | `CenterOnSelectedSim`, `SetMode` |
| 0x3D4 | `u8[0x44]` | _(gap)_ | - | - |
| 0x418 | `f32` | **`m_pos`** | R/W | `DrawCameraInfo`, `FollowSimStiff`, `ForcePosition`, ... |
| 0x41C | `f32` | **`m_win_41C`** | R | `DrawCameraInfo`, `UpdateWin` |
| 0x420 | `f32` | `m_field_420` | R | `DrawCameraInfo`, `HandleRotation`, `HandleZoom` |
| 0x424 | `f32` | **`m_pos_424`** | R/W | `ForcePosition`, `ResetPos`, `SetPos`, ... |
| 0x430 | `u32` | `m_field_430` | W | `CenterOnSelectedSim`, `FollowPlayerInteractor` |
| 0x43C | `f32` | **`m_pos_43C`** | R/W | `CenterOnSelectedSim`, `DrawCameraInfo`, `FollowPlayerInteractor`, ... |
| 0x440 | `f32` | `m_field_440` | R/W | `CenterOnSelectedSim`, `DrawCameraInfo`, `FollowSimStiff` |
| 0x444 | `f32` | **`m_winPos`** | R/W | `CenterOnSelectedSim`, `DrawCameraInfo`, `SetWinPos` |
| 0x448 | `f32` | **`m_curZoomRatio`** | R/W | `ApplyZoom`, `FollowSimStiff`, `ForcePosition`, ... |
| 0x44C | `f32` | **`m_pos_44C`** | R/W | `ApplyPan`, `FollowSimStiff`, `ForcePosition`, ... |
| 0x450 | `f32` | **`m_pos_450`** | R/W | `ApplyZoom`, `ForcePosition`, `InterpolateActualCameraParamsToTarget`, ... |
| 0x454 | `f32` | **`m_winPos_454`** | R/W | `FollowPlayerInteractor`, `InterpolateActualCameraParamsToTarget`, `SetWinPos` |
| 0x458 | `f32` | `m_field_458` | R | `InterpolateActualCameraParamsToTarget` |
| 0x460 | `f32` | `m_field_460` | R | `InterpolateActualCameraParamsToTarget` |
| 0x464 | `f32` | `m_field_464` | R/W | `InterpolateActualCameraParamsToTarget` |
| 0x468 | `f32` | `m_field_468` | R/W | `InterpolateActualCameraParamsToTarget` |
| 0x46C | `u32` | `m_field_46C` | R/W | `ESimsCam`, `InterpolateActualCameraParamsToTarget` |
| 0x470 | `f32` | `m_field_470` | R/W | `ESimsCam`, `FollowSimStiff`, `InterpolateActualCameraParamsToTarget` |
| 0x474 | `u32` | `m_field_474` | R/W | `ESimsCam`, `FollowSimStiff`, `HandleRotation` |
| 0x478 | `u32` | **`m_winPos_478`** | R/W | `CenterOnSelectedSim`, `ForcePosition`, `ResetPos`, ... |
| 0x47C | `u32` | `m_field_47C` | W | `ESimsCam` |
| 0x488 | `u32` | `m_field_488` | W | `ESimsCam` |
| 0x494 | `u32` | `m_field_494` | W | `ESimsCam` |
| 0x4A0 | `f32` | `m_field_4A0` | W | `ESimsCam` |
| 0x4A4 | `f32` | `m_field_4A4` | W | `ESimsCam` |
| 0x4A8 | `u32` | **`m_activeNoiseSetting`** | R/W | `ESimsCam`, `SetActiveNoiseSetting`, `Update` |
| 0x4AC | `u32` | `m_field_4AC` | W | `ESimsCam` |
| 0x4B0 | `u32` | `m_field_4B0` | W | `ESimsCam` |
| 0x4B4 | `u32` | `m_field_4B4` | W | `ESimsCam` |
| 0x4B8 | `u32` | `m_field_4B8` | W | `ESimsCam` |
| 0x4BC | `u32` | `m_field_4BC` | W | `ESimsCam` |
| 0x4C0 | `u32` | `m_field_4C0` | W | `ESimsCam` |
| 0x4C4 | `u32` | `m_field_4C4` | W | `ESimsCam` |
| 0x4C8 | `u8[0x78]` | _(gap)_ | - | - |
| 0x540 | `u32` | `m_field_540` | R/W | `CenterOnSelectedSim`, `ESimsCam` |
| 0x544 | `u16` | **`m_win_544`** | R/W | `ESimsCam`, `UpdateWin` |
| 0x548 | `u32` | **`m_win_548`** | W | `ESimsCam`, `UpdateWin` |
| 0x54C | `u32` | `m_field_54C` | W | `Reset` |
| 0x550 | `u32` | **`m_winPos_550`** | R/W | `ESimsCam`, `HandleRotation`, `HandleZoom`, ... |
| 0x554 | `u32` | **`m_winPos_554`** | R | `SetWinPos` |
| 0x558 | `u32` | **`m_winPos_558`** | R | `SetWinPos` |
| 0x55C | `u32` | **`m_winPos_55C`** | R | `SetWinPos` |
| 0x560 | `u32` | `m_field_560` | R/W | `ESimsCam`, `ReadControllerRotation`, `ReadControllerZoom` |
| 0x564 | `u32` | **`m_nearPlane_564`** | R/W | `ESimsCam`, `GetNearPlane`, `InterpolateActualCameraParamsToTarget`, ... |
| 0x568 | `u32` | **`m_nearPlane_568`** | R/W | `ESimsCam`, `GetNearPlane`, `InterpolateActualCameraParamsToTarget`, ... |
| 0x56C | `u32` | `m_field_56C` | W | `ESimsCam`, `~ESimsCam` |

### `Effects`

**Size:** >= 0x1A8 (424 bytes) | **Fields:** 65 (0 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `f32` | `m_field_000` | R/W | `Effect::DefaultInit`, `Effect::Effect`, `EffectsManager::AddEffect`, ... |
| 0x004 | `f32` | `m_field_004` | R/W | `Effect::DefaultInit`, `Effect::Effect`, `EffectsManager::AddEffect`, ... |
| 0x008 | `f32` | `m_field_008` | R/W | `Effect::DefaultInit`, `Effect::Effect`, `EffectsManager::AddEffect`, ... |
| 0x00C | `f32` | `m_field_00C` | R/W | `Effect::DefaultInit`, `Effect::Effect`, `FastParticleEmitter::AddBurst`, ... |
| 0x010 | `f32` | `m_field_010` | R/W | `Effect::DefaultInit`, `Effect::Effect`, `EffectsManager::Update`, ... |
| 0x014 | `f32` | `m_field_014` | R/W | `Effect::DefaultInit`, `Effect::Effect`, `FastParticleEmitter::RotateEmitter`, ... |
| 0x018 | `f32` | `m_field_018` | R/W | `Effect::DefaultInit`, `Effect::Effect`, `FastParticleEmitter::RotateEmitter`, ... |
| 0x01C | `f32` | `m_field_01C` | R/W | `Effect::DefaultInit`, `Effect::Effect`, `FastParticleEmitter::RotateEmitter`, ... |
| 0x020 | `f32` | `m_field_020` | R/W | `Effect::DefaultInit`, `Effect::Effect`, `FastParticleEmitter::RotateEmitter`, ... |
| 0x024 | `f32` | `m_field_024` | R/W | `Effect::DefaultInit`, `Effect::Effect`, `FastParticleEmitter::RotateEmitter`, ... |
| 0x028 | `f32` | `m_field_028` | R/W | `Effect::DefaultInit`, `Effect::Effect`, `FastParticleEmitter::RotateEmitter`, ... |
| 0x02C | `f32` | `m_field_02C` | R/W | `Effect::DefaultInit`, `Effect::Effect`, `FastParticleEmitter::RotateEmitter`, ... |
| 0x030 | `u32` | `m_field_030` | R/W | `Effect::DefaultInit`, `Effect::Effect` |
| 0x034 | `u32` | `m_field_034` | R/W | `Effect::DefaultInit`, `Effect::Effect` |
| 0x038 | `u32` | `m_field_038` | R/W | `Effect::DefaultInit`, `Effect::Effect` |
| 0x03C | `u32` | `m_field_03C` | R/W | `Effect::DefaultInit`, `Effect::Effect` |
| 0x040 | `u16` | `m_field_040` | W | `Effect::Effect` |
| 0x044 | `u32` | `m_field_044` | W | `Effect::Effect` |
| 0x048 | `u32` | `m_field_048` | W | `Effect::Effect` |
| 0x04C | `u32` | `m_field_04C` | W | `Effect::Effect` |
| 0x050 | `f32` | `m_field_050` | W | `FastParticleEmitter::RotateEmitter` |
| 0x054 | `u8[0x2C]` | _(gap)_ | - | - |
| 0x080 | `f32` | `m_field_080` | R/W | `FastParticleEmitter::SharedInitPart2` |
| 0x090 | `f32` | `m_field_090` | R | `FastParticleEmitter::RenderQuad` |
| 0x094 | `u8[0x2C]` | _(gap)_ | - | - |
| 0x0C0 | `f32` | `m_field_0C0` | R | `FastParticleEmitter::ComputeDispersionPositionAndVelocity`, `FastParticleEmitter::SharedInitPart2`, `FastParticleEmitter::Update` |
| 0x0D0 | `f32` | `m_field_0D0` | R/W | `FastParticleEmitter::AddBurst`, `FastParticleEmitter::SharedInitPart2`, `FastParticleEmitter::Update` |
| 0x0E0 | `f32` | `m_field_0E0` | R/W | `FastParticleEmitter::Update` |
| 0x0EC | `f32` | `m_field_0EC` | R/W | `FastParticleEmitter::SharedInitPart2`, `FastParticleEmitter::Update` |
| 0x0F0 | `f32` | `m_field_0F0` | R/W | `FastParticleEmitter::ComputeDispersionPositionAndVelocity`, `FastParticleEmitter::SharedInitPart2`, `FastParticleEmitter::Update` |
| 0x100 | `f32` | `m_field_100` | W | `Effect::DefaultInit`, `Effect::SetParentTransform` |
| 0x104 | `f32` | `m_field_104` | W | `Effect::DefaultInit`, `Effect::SetParentTransform` |
| 0x108 | `f32` | `m_field_108` | W | `Effect::SetParentTransform` |
| 0x110 | `f32` | `m_field_110` | W | `Effect::SetParentTransform` |
| 0x114 | `f32` | `m_field_114` | W | `Effect::SetParentTransform` |
| 0x118 | `f32` | `m_field_118` | W | `Effect::SetParentTransform` |
| 0x120 | `f32` | `m_field_120` | W | `Effect::SetParentTransform` |
| 0x124 | `f32` | `m_field_124` | W | `Effect::SetParentTransform` |
| 0x128 | `f32` | `m_field_128` | W | `Effect::SetParentTransform` |
| 0x12C | `u8[0x14]` | _(gap)_ | - | - |
| 0x140 | `u32` | `m_field_140` | R/W | `Effect::DefaultInit`, `Effect::SetParentTransform`, `FastParticleEmitter::ComputeCombinedMatrix`, ... |
| 0x144 | `u32` | `m_field_144` | R/W | `Effect::Effect`, `EffectsManager::CreateEffect`, `FastParticleEmitter::FastParticleEmitter`, ... |
| 0x148 | `u32` | `m_field_148` | R/W | `FastParticleEmitter::AddBurst`, `FastParticleEmitter::SharedInitPart1`, `FastParticleEmitter::SharedInitPart2`, ... |
| 0x14C | `f32` | `m_field_14C` | R/W | `FastParticleEmitter::DoSimulationAndRender`, `FastParticleEmitter::SharedInitPart1` |
| 0x150 | `f32` | `m_field_150` | R/W | `FastParticleEmitter::ComputeDispersionPositionAndVelocity`, `FastParticleEmitter::ComputeMaxParticles`, `FastParticleEmitter::PreRollParticles`, ... |
| 0x154 | `f32` | `m_field_154` | R/W | `FastParticleEmitter::ComputeMaxParticles`, `FastParticleEmitter::PreRollParticles`, `FastParticleEmitter::ReallocateParticles`, ... |
| 0x158 | `f32` | `m_field_158` | R/W | `FastParticleEmitter::SharedInitPart2`, `FastParticleEmitter::Update` |
| 0x15C | `u32` | `m_field_15C` | R/W | `FastParticleEmitter::AddBurst`, `FastParticleEmitter::SharedInitPart2`, `FastParticleEmitter::Stop`, ... |
| 0x160 | `u32` | `m_field_160` | R/W | `FastParticleEmitter::SharedInitPart2`, `FastParticleEmitter::Update` |
| 0x164 | `s16` | `m_field_164` | R/W | `FastParticleEmitter::AllocateParticlePackets`, `FastParticleEmitter::FastParticleEmitter`, `FastParticleEmitter::FreeParticlePackets`, ... |
| 0x166 | `u8` | `m_field_166` | W | `FastParticleEmitter::Init` |
| 0x168 | `s16` | `m_field_168` | R/W | `FastParticleEmitter::AddBurst`, `FastParticleEmitter::AllocateParticlePackets`, `FastParticleEmitter::DoSimulationAndRender`, ... |
| 0x16C | `f32` | `m_field_16C` | W | `FastParticleEmitter::SharedInitPart2` |
| 0x170 | `f32` | `m_field_170` | W | `FastParticleEmitter::SharedInitPart2` |
| 0x174 | `f32` | `m_field_174` | R/W | `FastParticleEmitter::RotateEmitter`, `FastParticleEmitter::SharedInitPart2` |
| 0x178 | `f32` | `m_field_178` | R/W | `FastParticleEmitter::RotateEmitter`, `FastParticleEmitter::SharedInitPart2` |
| 0x17C | `f32` | `m_field_17C` | R/W | `FastParticleEmitter::ComputeMaxParticles`, `FastParticleEmitter::PreRollParticles`, `FastParticleEmitter::ReallocateParticles`, ... |
| 0x180 | `f32` | `m_field_180` | R/W | `FastParticleEmitter::ComputeMaxParticles`, `FastParticleEmitter::PreRollParticles`, `FastParticleEmitter::ReallocateParticles`, ... |
| 0x184 | `f32` | `m_field_184` | R/W | `FastParticleEmitter::ComputeDispersionPositionAndVelocity`, `FastParticleEmitter::SharedInitPart2`, `FastParticleEmitter::Update` |
| 0x188 | `f32` | `m_field_188` | R/W | `FastParticleEmitter::SharedInitPart2`, `FastParticleEmitter::Update` |
| 0x18C | `u32` | `m_field_18C` | R/W | `FastParticleEmitter::AddBurst`, `FastParticleEmitter::AllocateParticlePackets`, `FastParticleEmitter::ComputeDispersionPositionAndVelocity`, ... |
| 0x190 | `u32` | `m_field_190` | R/W | `FastParticleEmitter::AddBurst`, `FastParticleEmitter::DoSimulationAndRender`, `FastParticleEmitter::FastParticleEmitter`, ... |
| 0x194 | `u32` | `m_field_194` | R/W | `FastParticleEmitter::FastParticleEmitter`, `FastParticleEmitter::Init`, `FastParticleEmitter::InitResourceData`, ... |
| 0x198 | `u16` | `m_field_198` | R/W | `FastParticleEmitter::AddBurst`, `FastParticleEmitter::ComputeMaxParticles`, `FastParticleEmitter::DoSimulationAndRender`, ... |
| 0x19A | `u16` | `m_field_19A` | R/W | `FastParticleEmitter::AddBurst`, `FastParticleEmitter::ComputeMaxParticles`, `FastParticleEmitter::DoSimulationAndRender`, ... |
| 0x19C | `u32` | `m_field_19C` | R/W | `FastParticleEmitter::AddBurst`, `FastParticleEmitter::AllocateParticlePackets`, `FastParticleEmitter::DoSimulationAndRender`, ... |
| 0x1A0 | `u32` | `m_field_1A0` | R/W | `FastParticleEmitter::FastParticleEmitter`, `FastParticleEmitter::Init`, `FastParticleEmitter::~FastParticleEmitter` |
| 0x1A4 | `u32` | `m_field_1A4` | R/W | `FastParticleEmitter::DoSimulationAndRender`, `FastParticleEmitter::FastParticleEmitter`, `FastParticleEmitter::SharedInitPart2`, ... |

### `cSimulatorImpl`

**Size:** >= 0x180 (384 bytes) | **Fields:** 59 (16 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `void**` | **`_vtable` (vtable pointer)** | R/W | `DoCommand`, `DoStream`, `GetTodaysExpenses`, ... |
| 0x004 | `u32` | **`m_todaysExpenses_004`** | R | `GetTodaysExpenses`, `SimulateOneTick` |
| 0x008 | `u32` | **`m_todaysExpenses_008`** | R | `GetTodaysExpenses`, `SimulateOneTick` |
| 0x00C | `u32` | **`m_todaysExpenses_00C`** | R | `GetTodaysExpenses`, `SimulateOneTick` |
| 0x010 | `u32` | **`m_todaysExpenses_010`** | R/W | `GetTodaysExpenses`, `SimulateOneTick`, `cSimulatorImpl`, ... |
| 0x014 | `s16` | **`m_todaysExpenses_014`** | R/W | `ComputeTimeOfDay`, `GetTodaysExpenses`, `Init`, ... |
| 0x016 | `s16` | `m_field_016` | R/W | `Init`, `SimulateOneTick` |
| 0x018 | `u16` | `m_field_018` | R/W | `DoCommand`, `TickAllObjects` |
| 0x01A | `u16` | `m_field_01A` | W | `DoCommand` |
| 0x01C | `s16` | **`m_currentHour`** | R/W | `HourTimeOfDayLastChanged`, `HourTimeOfDayNextChanges`, `Init`, ... |
| 0x01E | `u16` | **`m_currentHour_01E`** | R/W | `Init`, `SetCurrentHour`, `SimulateOneTick` |
| 0x020 | `u16` | `m_field_020` | R/W | `SimulateOneTick` |
| 0x022 | `s16` | `m_field_022` | R/W | `DoStream`, `Init`, `SimulateOneTick` |
| 0x024 | `s16` | `m_field_024` | R/W | `DoStream`, `Init`, `SimulateOneTick` |
| 0x028 | `s16` | `m_field_028` | R | `TickAllObjects` |
| 0x02A | `s16` | `m_field_02A` | R/W | `Simulate` |
| 0x02C | `u16` | `m_field_02C` | W | `DoStream`, `Init` |
| 0x02E | `u16` | **`m_funds`** | W | `SetFunds` |
| 0x030 | `u16` | **`m_funds_030`** | W | `SetFunds` |
| 0x032 | `u16` | `m_field_032` | W | `DoStream`, `Init` |
| 0x034 | `s16` | **`m_speed`** | R/W | `DoStream`, `Init`, `SetSpeed`, ... |
| 0x036 | `s16` | `m_field_036` | R/W | `DoStream`, `Init`, `Pause`, ... |
| 0x038 | `s16` | `m_field_038` | R/W | `DoStream`, `Init` |
| 0x03A | `u16` | `m_field_03A` | W | `cSimulatorImpl` |
| 0x03C | `u16` | `m_field_03C` | W | `Init` |
| 0x046 | `s16` | `m_field_046` | R/W | `DoStream` |
| 0x04C | `u16` | `m_field_04C` | R/W | `ClearHistory`, `SimulateOneTick` |
| 0x04E | `u16` | `m_field_04E` | W | `DoStream`, `SimulateOneTick` |
| 0x050 | `u16` | `m_field_050` | W | `DoStream` |
| 0x054 | `u16` | `m_field_054` | W | `DoCommand` |
| 0x056 | `u16` | `m_field_056` | W | `DoStream` |
| 0x058 | `u16` | `m_field_058` | W | `DoStream` |
| 0x05A | `u16` | `m_field_05A` | W | `DoStream` |
| 0x05C | `u16` | `m_field_05C` | W | `DoStream` |
| 0x05E | `s16` | `m_field_05E` | R/W | `Simulate` |
| 0x062 | `s16` | `m_field_062` | R/W | `DoStream`, `Init` |
| 0x068 | `u16` | `m_field_068` | W | `DoStream`, `Init` |
| 0x070 | `u16` | **`m_global`** | W | `GetGlobal` |
| 0x072 | `u16` | **`m_global_072`** | W | `GetGlobal` |
| 0x074 | `u32` | **`m_funds_074`** | R/W | `DoStream`, `Init`, `SetFunds`, ... |
| 0x078 | `u32` | **`m_funds_078`** | R/W | `Init`, `SetFunds`, `Spend` |
| 0x07C | `u32` | `m_field_07C` | R/W | `DoStream`, `Init`, `SimulateOneTick`, ... |
| 0x080 | `u32` | `m_field_080` | R/W | `SimulateOneTick`, `cSimulatorImpl` |
| 0x084 | `u32` | `m_field_084` | W | `Init`, `cSimulatorImpl` |
| 0x088 | `u32` | `m_field_088` | R/W | `DoStream`, `Init`, `cSimulatorImpl` |
| 0x08C | `u32` | `m_field_08C` | R/W | `DoStream`, `Init`, `cSimulatorImpl` |
| 0x090 | `u32` | `m_field_090` | R/W | `Init`, `SimulateOneTick` |
| 0x094 | `u32` | `m_field_094` | W | `cSimulatorImpl` |
| 0x098 | `u32` | `m_field_098` | W | `DoStream`, `cSimulatorImpl` |
| 0x09C | `u32` | `m_field_09C` | W | `Init`, `Simulate` |
| 0x0A0 | `f32` | **`m_speed_0A0`** | R/W | `Resume`, `SetSpeed`, `Simulate`, ... |
| 0x0A4 | `f32` | `m_field_0A4` | W | `Simulate`, `cSimulatorImpl` |
| 0x0A8 | `f32` | `m_field_0A8` | W | `DoStream`, `Pause`, `TickAllObjects`, ... |
| 0x0AC | `f32` | `m_field_0AC` | R/W | `DoStream`, `Simulate`, `cSimulatorImpl` |
| 0x0B0 | `f32` | `m_field_0B0` | R/W | `DoStream`, `Simulate`, `cSimulatorImpl` |
| 0x0B4 | `u8[0xC0]` | _(gap)_ | - | - |
| 0x174 | `u32` | `m_field_174` | R/W | `DoStream`, `Init`, `cSimulatorImpl`, ... |
| 0x178 | `u32` | `m_field_178` | R/W | `DoCommand`, `DoStream`, `Init`, ... |
| 0x17A | `s16` | `m_field_17A` | R | `DoStream` |
| 0x17C | `u32` | `m_field_17C` | W | `Simulate`, `cSimulatorImpl` |

### `EIWallPart`

**Size:** >= 0xDBC (3516 bytes) | **Fields:** 59 (40 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `f32` | **`m_wallModelId`** | R/W | `DrawOutsideShadows`, `DrawShadow`, `EIWallPart`, ... |
| 0x004 | `f32` | **`m_wallModelId_004`** | R/W | `Draw`, `DrawOutsideShadows`, `GetWallModelId`, ... |
| 0x008 | `f32` | **`m_wallpaperShader`** | R/W | `Draw`, `DrawOutsideShadows`, `GetWallpaperShader`, ... |
| 0x00C | `f32` | `m_field_00C` | R/W | `Draw`, `WallOrderTableCallback` |
| 0x010 | `u32` | `m_field_010` | W | `EIWallPart` |
| 0x014 | `u32` | **`m_wallModelId_014`** | R/W | `Draw`, `GetWallModelId` |
| 0x018 | `u32` | `m_field_018` | R | `Draw` |
| 0x01C | `u32` | **`m_shadowModel`** | R/W | `Draw`, `EIWallPart`, `GetShadowModel` |
| 0x028 | `u32` | **`m_shadowModel_028`** | R/W | `Draw`, `EIWallPart`, `GetShadowModel` |
| 0x03C | `f32` | **`m_wallpaperShader_03C`** | R | `DrawOutsideShadows`, `GetWallpaperShader` |
| 0x040 | `u32` | **`m_wallpaperShader_040`** | R | `GetWallpaperShader` |
| 0x044 | `u8[0x18]` | _(gap)_ | - | - |
| 0x05C | `u32` | **`m_visible`** | R/W | `SetVisible` |
| 0x068 | `u32` | `m_field_068` | W | `EIWallPart` |
| 0x070 | `u32` | `m_field_070` | R | `Draw`, `DrawOutsideShadows`, `DrawShadow`, ... |
| 0x074 | `u8[0x24]` | _(gap)_ | - | - |
| 0x098 | `u32` | `m_field_098` | R | `WallOrderTableCallback` |
| 0x0A2 | `s16` | **`m_wallModelId_0A2`** | R | `GetWallModelId` |
| 0x0A8 | `u32` | `m_field_0A8` | R/W | `WallOrderTableCallback` |
| 0x0B8 | `u32` | `m_field_0B8` | R/W | `WallOrderTableCallback` |
| 0x0BC | `u8[0x34]` | _(gap)_ | - | - |
| 0x0F0 | `u32` | `m_field_0F0` | R | `DrawOutsideShadows`, `DrawShadow`, `WallOrderTableCallback` |
| 0x0F4 | `u8[0x1C]` | _(gap)_ | - | - |
| 0x110 | `u32` | **`m_shadowModel_110`** | R | `GetShadowModel` |
| 0x118 | `u32` | `m_field_118` | R | `Draw`, `DrawOutsideShadows`, `DrawShadow` |
| 0x11C | `u32` | **`m_outsideShadows`** | R | `DrawOutsideShadows` |
| 0x120 | `u32` | **`m_wallpaperShader_120`** | R | `Draw`, `DrawShadow`, `GetWallpaperShader`, ... |
| 0x128 | `u32` | `m_field_128` | W | `Draw` |
| 0x138 | `u32` | `m_field_138` | W | `Draw` |
| 0x13C | `u8[0xDC]` | _(gap)_ | - | - |
| 0x218 | `u32` | `m_field_218` | W | `Draw` |
| 0x21C | `u8[0x64]` | _(gap)_ | - | - |
| 0x280 | `f32` | `m_field_280` | R | `VisibilityTest` |
| 0x284 | `f32` | `m_field_284` | R | `VisibilityTest` |
| 0x288 | `u8[0x98]` | _(gap)_ | - | - |
| 0x320 | `u32` | **`m_points`** | R/W | `EIWallPart`, `GetPoint`, `GetPoints` |
| 0x324 | `u32` | **`m_points_324`** | R/W | `EIWallPart`, `GetPoint`, `GetPoints` |
| 0x32C | `u32` | `m_field_32C` | W | `EIWallPart` |
| 0x330 | `u32` | `m_field_330` | W | `EIWallPart` |
| 0x334 | `u8[0x15]` | _(gap)_ | - | - |
| 0x349 | `u8` | **`m_shadow`** | R | `Draw`, `DrawShadow` |
| 0x350 | `u32` | `m_field_350` | W | `EIWallPart` |
| 0x354 | `u32` | **`m_wallModelId_354`** | R/W | `EIWallPart`, `GetWallModelId` |
| 0x358 | `s16` | **`m_shadowModel_358`** | R/W | `DrawOutsideShadows`, `DrawShadow`, `EIWallPart`, ... |
| 0x35A | `s16` | **`m_shadowModel_35A`** | R/W | `DrawOutsideShadows`, `DrawShadow`, `EIWallPart`, ... |
| 0x35C | `f32` | **`m_orient`** | R/W | `EIWallPart`, `SetOrient` |
| 0x360 | `f32` | **`m_orient_360`** | R/W | `EIWallPart`, `SetOrient` |
| 0x364 | `f32` | **`m_orient_364`** | R/W | `EIWallPart`, `SetOrient` |
| 0x368 | `f32` | **`m_orient_368`** | R/W | `EIWallPart`, `SetOrient` |
| 0x36C | `f32` | **`m_orient_36C`** | R/W | `EIWallPart`, `SetOrient` |
| 0x370 | `f32` | **`m_orient_370`** | R/W | `EIWallPart`, `SetOrient` |
| 0x374 | `f32` | **`m_orient_374`** | R/W | `EIWallPart`, `SetOrient` |
| 0x378 | `f32` | **`m_orient_378`** | R/W | `EIWallPart`, `SetOrient` |
| 0x37C | `f32` | **`m_orient_37C`** | R/W | `DrawOutsideShadows`, `DrawShadow`, `SetOrient`, ... |
| 0x380 | `f32` | **`m_orient_380`** | R/W | `DrawOutsideShadows`, `DrawShadow`, `SetOrient`, ... |
| 0x384 | `f32` | **`m_orient_384`** | R/W | `SetOrient`, `VisibilityTest` |
| 0x388 | `f32` | **`m_orient_388`** | W | `SetOrient` |
| 0x38C | `f32` | **`m_orient_38C`** | W | `SetOrient` |
| 0x390 | `f32` | **`m_orient_390`** | W | `SetOrient` |
| 0x394 | `f32` | **`m_orient_394`** | W | `SetOrient` |
| 0x398 | `f32` | **`m_orient_398`** | W | `SetOrient` |
| 0x39C | `f32` | **`m_orient_39C`** | W | `SetOrient` |
| 0x3A0 | `u32` | **`m_wallpaperShader_3A0`** | R/W | `ChangeWallpaper`, `EIWallPart`, `GetWallpaperShader`, ... |
| 0x3AC | `u32` | **`m_shadowModel_3AC`** | R/W | `DrawOutsideShadows`, `DrawShadow`, `EIWallPart`, ... |
| 0x3B0 | `u8[0x9F8]` | _(gap)_ | - | - |
| 0xDA8 | `f32` | `m_field_DA8` | R | `WallOrderTableCallback` |
| 0xDB4 | `f32` | **`m_outsideShadows_DB4`** | R | `DrawOutsideShadows` |
| 0xDB8 | `f32` | **`m_outsideShadows_DB8`** | R | `DrawOutsideShadows` |

### `WAFTarget`

**Size:** >= 0x288 (648 bytes) | **Fields:** 59 (14 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `u16` | **`m_localizable`** | R/W | `GetLocalizable`, `GetVariable`, `NewWantsAndFearsIcon`, ... |
| 0x004 | `u16` | **`m_variable`** | R/W | `GetVariable`, `WAFTarget`, `~WAFTarget` |
| 0x006 | `u8` | **`m_variable_006`** | W | `GetVariable` |
| 0x008 | `u32` | `m_field_008` | R/W | `WAFTarget`, `~WAFTarget` |
| 0x00C | `u32` | `m_field_00C` | R/W | `WAFTarget`, `~WAFTarget` |
| 0x010 | `u32` | `m_field_010` | R/W | `WAFTarget`, `~WAFTarget` |
| 0x014 | `u32` | `m_field_014` | R/W | `WAFTarget`, `~WAFTarget` |
| 0x018 | `u32` | `m_field_018` | R/W | `WAFTarget`, `~WAFTarget` |
| 0x01C | `u32` | `m_field_01C` | R/W | `NewWantsAndFearsIcon`, `StartAnimation`, `UpdateWantsAndFears`, ... |
| 0x020 | `u32` | `m_field_020` | R/W | `WAFTarget`, `~WAFTarget` |
| 0x024 | `u32` | `m_field_024` | R/W | `WAFTarget`, `~WAFTarget` |
| 0x028 | `u32` | `m_field_028` | W | `WAFTarget` |
| 0x038 | `u32` | `m_field_038` | W | `WAFTarget` |
| 0x048 | `u32` | `m_field_048` | W | `WAFTarget` |
| 0x058 | `u32` | `m_field_058` | R/W | `WAFTarget`, `~WAFTarget` |
| 0x068 | `u32` | `m_field_068` | R/W | `WAFTarget`, `~WAFTarget` |
| 0x078 | `u32` | `m_field_078` | W | `WAFTarget` |
| 0x07C | `u32` | `m_field_07C` | R/W | `NewWantsAndFearsIcon`, `StartAnimation`, `UpdateWantsAndFears`, ... |
| 0x080 | `u32` | `m_field_080` | W | `WAFTarget`, `~WAFTarget` |
| 0x084 | `u32` | **`m_variable_084`** | R/W | `GetVariable`, `Update`, `UpdateWantsAndFears`, ... |
| 0x088 | `u32` | **`m_variable_088`** | R/W | `SetVariable`, `Update`, `UpdateWantsAndFears`, ... |
| 0x08C | `u32` | **`m_variable_08C`** | R/W | `SetVariable`, `Update`, `WAFTarget` |
| 0x090 | `u32` | `m_field_090` | R/W | `NewWantsAndFearsIcon`, `Update`, `WAFTarget` |
| 0x094 | `u32` | **`m_topBarColorAtTier`** | R/W | `BeginBottomBarTween`, `BeginTopBarTween`, `FinishSettingIcon`, ... |
| 0x098 | `u32` | **`m_variable_098`** | R/W | `SetVariable`, `Update`, `WAFTarget` |
| 0x09C | `u32` | `m_field_09C` | R/W | `Update`, `WAFTarget` |
| 0x0A0 | `u32` | **`m_variable_0A0`** | R/W | `SetVariable`, `Update`, `WAFTarget` |
| 0x0A4 | `u8[0x20]` | _(gap)_ | - | - |
| 0x0C4 | `u32` | `m_field_0C4` | W | `WAFTarget` |
| 0x0C8 | `u32` | `m_field_0C8` | W | `WAFTarget` |
| 0x0CC | `u32` | `m_field_0CC` | W | `WAFTarget` |
| 0x0D0 | `u8[0x30]` | _(gap)_ | - | - |
| 0x100 | `u32` | `m_field_100` | W | `WAFTarget` |
| 0x104 | `u32` | `m_field_104` | W | `WAFTarget` |
| 0x108 | `u32` | `m_field_108` | W | `WAFTarget` |
| 0x10C | `u8[0x30]` | _(gap)_ | - | - |
| 0x13C | `u32` | `m_field_13C` | W | `WAFTarget` |
| 0x140 | `u32` | `m_field_140` | W | `WAFTarget` |
| 0x144 | `u32` | `m_field_144` | W | `WAFTarget` |
| 0x148 | `u8[0x30]` | _(gap)_ | - | - |
| 0x178 | `u32` | `m_field_178` | W | `WAFTarget` |
| 0x17C | `u32` | `m_field_17C` | W | `WAFTarget` |
| 0x180 | `u32` | `m_field_180` | W | `WAFTarget` |
| 0x184 | `u8[0x30]` | _(gap)_ | - | - |
| 0x1B4 | `u32` | `m_field_1B4` | W | `WAFTarget` |
| 0x1B8 | `u32` | `m_field_1B8` | W | `WAFTarget` |
| 0x1BC | `u32` | `m_field_1BC` | W | `WAFTarget` |
| 0x1C0 | `u8[0x30]` | _(gap)_ | - | - |
| 0x1F0 | `u32` | `m_field_1F0` | W | `WAFTarget` |
| 0x1F4 | `u32` | `m_field_1F4` | W | `WAFTarget` |
| 0x1F8 | `u32` | `m_field_1F8` | W | `WAFTarget` |
| 0x1FC | `u8[0x30]` | _(gap)_ | - | - |
| 0x22C | `u32` | `m_field_22C` | W | `WAFTarget` |
| 0x230 | `u32` | `m_field_230` | W | `WAFTarget` |
| 0x234 | `u32` | `m_field_234` | W | `WAFTarget` |
| 0x248 | `f32` | `m_field_248` | R/W | `Update`, `WAFTarget` |
| 0x24C | `u32` | `m_field_24C` | R/W | `NewWantsAndFearsIcon`, `Update`, `WAFTarget` |
| 0x250 | `u8[0x14]` | _(gap)_ | - | - |
| 0x264 | `u32` | `m_field_264` | R/W | `BeginBottomBarTween`, `BeginTopBarTween`, `OnBottomBarTweenComplete`, ... |
| 0x268 | `u32` | `m_field_268` | R/W | `BeginBottomBarTween`, `BeginMeterTween`, `BeginTopBarTween`, ... |
| 0x26C | `u32` | **`m_aspirationMeterHeight`** | R/W | `GlowEffectAwayStart`, `GlowEffectStart`, `OnTopBarTweenComplete`, ... |
| 0x270 | `u32` | `m_field_270` | R/W | `GlowEffectAwayStart`, `GlowEffectStart`, `UpdateWantsAndFears`, ... |
| 0x274 | `f32` | **`m_topBarTweenColor`** | R/W | `BeginBottomBarTween`, `BeginMeterTween`, `CalculateTweenTargetPosition`, ... |
| 0x278 | `f32` | **`m_topBarColorAtTier_278`** | R/W | `BeginBottomBarTween`, `BeginMeterTween`, `BeginTopBarTween`, ... |
| 0x27C | `f32` | `m_field_27C` | R/W | `BeginBottomBarTween`, `BeginTopBarTween`, `OnBottomBarTweenComplete`, ... |
| 0x280 | `u32` | **`m_variable_280`** | R/W | `SetVariable`, `Update`, `WAFTarget` |
| 0x284 | `u32` | **`m_wantsAndFears`** | R/W | `UpdateWantsAndFears`, `WAFTarget` |

### `E2ETarget`

**Size:** >= 0x288 (648 bytes) | **Fields:** 56 (15 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `u16` | **`m_localizable`** | R/W | `E2ETarget`, `GetLocalizable`, `GetVariable`, ... |
| 0x004 | `u16` | **`m_variable`** | R/W | `E2ETarget`, `GetVariable`, `~E2ETarget` |
| 0x006 | `u8` | **`m_variable_006`** | W | `GetVariable` |
| 0x008 | `u32` | `m_field_008` | R/W | `E2ETarget`, `~E2ETarget` |
| 0x00C | `u32` | `m_field_00C` | R/W | `E2ETarget`, `~E2ETarget` |
| 0x010 | `u16` | `m_field_010` | R/W | `E2ETarget`, `~E2ETarget` |
| 0x012 | `u16` | `m_field_012` | R | `E2ETarget` |
| 0x014 | `u32` | `m_field_014` | R/W | `E2ETarget`, `~E2ETarget` |
| 0x018 | `u32` | `m_field_018` | R/W | `E2ETarget`, `~E2ETarget` |
| 0x01C | `u32` | **`m_shaders`** | R/W | `E2ETarget`, `UpdateShaders`, `~E2ETarget` |
| 0x020 | `u32` | `m_field_020` | R/W | `E2ETarget`, `~E2ETarget` |
| 0x024 | `u32` | `m_field_024` | R/W | `E2ETarget`, `~E2ETarget` |
| 0x028 | `u32` | `m_field_028` | W | `E2ETarget` |
| 0x038 | `u32` | `m_field_038` | W | `E2ETarget` |
| 0x048 | `u32` | `m_field_048` | W | `E2ETarget` |
| 0x058 | `u32` | `m_field_058` | R/W | `E2ETarget`, `~E2ETarget` |
| 0x068 | `u32` | `m_field_068` | R/W | `E2ETarget`, `~E2ETarget` |
| 0x078 | `u32` | `m_field_078` | R/W | `E2ETarget` |
| 0x07C | `u32` | **`m_shaders_07C`** | R/W | `E2ETarget`, `UpdateShaders`, `~E2ETarget` |
| 0x080 | `u32` | `m_field_080` | R/W | `CaptureFrame`, `E2ETarget`, `OnCircleKeyPressed`, ... |
| 0x084 | `u32` | **`m_variable_084`** | W | `E2ETarget`, `GetVariable` |
| 0x088 | `u32` | `m_field_088` | R/W | `E2ERenderCallback`, `E2ETarget`, `Update` |
| 0x08C | `u32` | `m_field_08C` | R/W | `E2ETarget`, `InitializeEyeToy`, `ReintializeEyeToy` |
| 0x090 | `u32` | `m_field_090` | R/W | `E2ETarget`, `~E2ETarget` |
| 0x094 | `u32` | `m_field_094` | W | `E2ETarget` |
| 0x098 | `u32` | `m_field_098` | R/W | `E2ETarget` |
| 0x09C | `u32` | `m_field_09C` | R/W | `E2ETarget`, `~E2ETarget` |
| 0x0A0 | `u32` | `m_field_0A0` | R/W | `E2ETarget`, `~E2ETarget` |
| 0x0A8 | `u32` | `m_field_0A8` | R/W | `E2ETarget`, `OnLeftKeyPressed`, `OnRightKeyPressed`, ... |
| 0x0AC | `u32` | `m_field_0AC` | W | `E2ETarget` |
| 0x0B0 | `u32` | **`m_variable_0B0`** | R/W | `E2ETarget`, `GetVariable` |
| 0x0B4 | `u32` | **`m_variable_0B4`** | R/W | `ChangeSelectedSlot`, `E2ETarget`, `GetVariable` |
| 0x0B8 | `u32` | **`m_variable_0B8`** | R/W | `E2ETarget`, `GetVariable` |
| 0x0BC | `u32` | **`m_variable_0BC`** | R/W | `CaptureFrame`, `ChangeFunFrame`, `E2ETarget`, ... |
| 0x0C0 | `u32` | `m_field_0C0` | R/W | `ChangeSelectedSlot`, `E2ETarget`, `OnLeftKeyPressed`, ... |
| 0x0C4 | `u32` | **`m_variable_0C4`** | R/W | `ChangeFilter`, `E2ETarget`, `OnLeftKeyPressed`, ... |
| 0x0C8 | `f32` | `m_field_0C8` | R/W | `E2ETarget`, `OnExitSettings`, `OnSaveDialogDoneCB` |
| 0x0CC | `f32` | `m_field_0CC` | R/W | `E2ETarget`, `OnExitSettings`, `OnSaveDialogDoneCB` |
| 0x0D0 | `f32` | `m_field_0D0` | R/W | `E2ETarget`, `OnExitSettings`, `OnSaveDialogDoneCB` |
| 0x0D4 | `f32` | `m_field_0D4` | R/W | `E2ETarget`, `OnExitSettings`, `OnSaveDialogDoneCB` |
| 0x0D8 | `u32` | **`m_localizable_0D8`** | R/W | `CaptureFrame`, `E2ETarget`, `GetLocalizable`, ... |
| 0x0DC | `u32` | **`m_topLevelState`** | W | `E2ETarget`, `SetTopLevelState` |
| 0x0E0 | `u32` | **`m_variable_0E0`** | R/W | `E2ETarget`, `GetVariable`, `OnSaveGameComplete`, ... |
| 0x0E4 | `u32` | `m_field_0E4` | W | `E2ETarget`, `LaunchSaveSettingsDialog`, `SpawnNoEyeToyDialogBox` |
| 0x0F0 | `u32` | `m_field_0F0` | W | `LaunchSaveSettingsDialog`, `SpawnNoEyeToyDialogBox` |
| 0x0F8 | `u32` | `m_field_0F8` | W | `LaunchSaveSettingsDialog`, `SpawnNoEyeToyDialogBox` |
| 0x104 | `u32` | `m_field_104` | W | `LaunchSaveSettingsDialog`, `SpawnNoEyeToyDialogBox` |
| 0x108 | `u8[0x2C]` | _(gap)_ | - | - |
| 0x134 | `u32` | `m_field_134` | W | `E2ETarget`, `LaunchSaveSettingsDialog`, `SpawnNoEyeToyDialogBox` |
| 0x144 | `u32` | `m_field_144` | W | `E2ETarget`, `LaunchSaveSettingsDialog`, `SpawnNoEyeToyDialogBox` |
| 0x154 | `u32` | `m_field_154` | W | `E2ETarget`, `LaunchSaveSettingsDialog`, `SpawnNoEyeToyDialogBox` |
| 0x158 | `u8[0x14]` | _(gap)_ | - | - |
| 0x16C | `u32` | `m_field_16C` | W | `E2ETarget`, `SpawnSaveGameDialog` |
| 0x180 | `u32` | `m_field_180` | W | `SpawnSaveGameDialog` |
| 0x184 | `u8[0x38]` | _(gap)_ | - | - |
| 0x1BC | `u32` | `m_field_1BC` | W | `E2ETarget`, `SpawnSaveGameDialog` |
| 0x1CC | `u32` | `m_field_1CC` | W | `E2ETarget`, `SpawnSaveGameDialog` |
| 0x1DC | `u32` | `m_field_1DC` | W | `E2ETarget`, `SpawnSaveGameDialog` |
| 0x1E0 | `u8[0xA4]` | _(gap)_ | - | - |
| 0x284 | `u32` | **`m_variable_284`** | R/W | `CaptureFrame`, `E2ETarget`, `OnSaveGameComplete`, ... |

### `O2TTarget`

**Size:** >= 0x25C (604 bytes) | **Fields:** 56 (19 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `u16` | **`m_localizable`** | R/W | `ExitScreenWizard`, `GetLocalizable`, `GetVariable`, ... |
| 0x004 | `u16` | **`m_variable`** | R/W | `GetVariable`, `O2TTarget`, `~O2TTarget` |
| 0x006 | `u8` | **`m_variable_006`** | W | `GetVariable` |
| 0x008 | `u32` | `m_field_008` | R/W | `O2TTarget`, `~O2TTarget` |
| 0x00C | `u32` | `m_field_00C` | R/W | `O2TTarget`, `~O2TTarget` |
| 0x010 | `u32` | `m_field_010` | R/W | `O2TTarget`, `~O2TTarget` |
| 0x014 | `u32` | `m_field_014` | R/W | `O2TTarget`, `~O2TTarget` |
| 0x018 | `u32` | `m_field_018` | R/W | `O2TTarget`, `~O2TTarget` |
| 0x01C | `u32` | `m_field_01C` | R/W | `ExitScreenWizard`, `O2TTarget`, `StartScreenWizard`, ... |
| 0x020 | `u32` | `m_field_020` | R/W | `O2TTarget`, `~O2TTarget` |
| 0x024 | `u32` | `m_field_024` | R/W | `O2TTarget`, `~O2TTarget` |
| 0x028 | `u32` | `m_field_028` | W | `O2TTarget` |
| 0x038 | `u32` | `m_field_038` | W | `O2TTarget` |
| 0x048 | `u32` | `m_field_048` | W | `O2TTarget` |
| 0x058 | `u32` | `m_field_058` | R/W | `O2TTarget`, `~O2TTarget` |
| 0x068 | `u32` | `m_field_068` | R/W | `O2TTarget`, `~O2TTarget` |
| 0x078 | `u32` | `m_field_078` | W | `O2TTarget` |
| 0x07C | `u32` | `m_field_07C` | R/W | `ExitScreenWizard`, `O2TTarget`, `StartScreenWizard`, ... |
| 0x080 | `u32` | `m_field_080` | R/W | `O2TTarget`, `OnCircleKeyPressed`, `~O2TTarget` |
| 0x084 | `u32` | **`m_variable_084`** | W | `GetVariable`, `O2TTarget` |
| 0x088 | `u32` | **`m_localizable_088`** | R/W | `GetLocalizable`, `O2TTarget`, `OnCircleKeyPressed`, ... |
| 0x08C | `u32` | **`m_variable_08C`** | W | `O2TTarget`, `SetTopLevelState`, `SetVariable` |
| 0x090 | `u32` | **`m_variable_090`** | R/W | `GetVariable`, `O2TTarget`, `OnSaveGameComplete`, ... |
| 0x094 | `u32` | `m_field_094` | W | `O2TTarget` |
| 0x098 | `u32` | `m_field_098` | W | `O2TTarget` |
| 0x09C | `u32` | `m_field_09C` | R/W | `O2TTarget`, `OnDownKeyPressed`, `OnUpKeyPressed`, ... |
| 0x0A0 | `u32` | `m_field_0A0` | R/W | `O2TTarget`, `OnDownKeyPressed`, `OnLeftKeyPressed`, ... |
| 0x0A4 | `u32` | `m_field_0A4` | W | `O2TTarget`, `SpawnQuitDialogBox` |
| 0x0B0 | `u32` | `m_field_0B0` | W | `SpawnQuitDialogBox` |
| 0x0B8 | `u32` | `m_field_0B8` | W | `SpawnQuitDialogBox` |
| 0x0C4 | `u32` | `m_field_0C4` | W | `SpawnQuitDialogBox` |
| 0x0C8 | `u8[0x2C]` | _(gap)_ | - | - |
| 0x0F4 | `u32` | `m_field_0F4` | W | `O2TTarget`, `SpawnQuitDialogBox` |
| 0x104 | `u32` | `m_field_104` | W | `O2TTarget`, `SpawnQuitDialogBox` |
| 0x114 | `u32` | `m_field_114` | W | `O2TTarget`, `SpawnQuitDialogBox` |
| 0x118 | `u8[0x14]` | _(gap)_ | - | - |
| 0x12C | `u32` | `m_field_12C` | W | `O2TTarget`, `SpawnSaveSettingsDialog` |
| 0x138 | `u32` | `m_field_138` | W | `SpawnSaveSettingsDialog` |
| 0x140 | `u32` | `m_field_140` | W | `SpawnSaveSettingsDialog` |
| 0x14C | `u32` | `m_field_14C` | W | `SpawnSaveSettingsDialog` |
| 0x150 | `u8[0x2C]` | _(gap)_ | - | - |
| 0x17C | `u32` | `m_field_17C` | W | `O2TTarget`, `SpawnSaveSettingsDialog` |
| 0x18C | `u32` | `m_field_18C` | W | `O2TTarget`, `SpawnSaveSettingsDialog` |
| 0x19C | `u32` | `m_field_19C` | W | `O2TTarget`, `SpawnSaveSettingsDialog` |
| 0x1A0 | `u8[0x14]` | _(gap)_ | - | - |
| 0x1B4 | `u32` | **`m_variable_1B4`** | R/W | `O2TTarget`, `SetVariable`, `ShowHelp` |
| 0x1B8 | `u32` | `m_field_1B8` | R/W | `O2TTarget`, `~O2TTarget` |
| 0x1BC | `u32` | `m_field_1BC` | R/W | `O2TTarget`, `~O2TTarget` |
| 0x1C0 | `u32` | **`m_variable_1C0`** | W | `SetVariable` |
| 0x1CC | `u32` | **`m_variable_1CC`** | W | `SetVariable` |
| 0x1D4 | `u32` | **`m_variable_1D4`** | W | `SetVariable` |
| 0x1E0 | `u32` | **`m_variable_1E0`** | W | `SetVariable` |
| 0x1E4 | `u32` | **`m_variable_1E4`** | W | `SetVariable` |
| 0x1E8 | `u8[0x28]` | _(gap)_ | - | - |
| 0x210 | `u32` | **`m_variable_210`** | W | `SetVariable` |
| 0x220 | `u32` | **`m_variable_220`** | W | `SetVariable` |
| 0x230 | `u32` | **`m_variable_230`** | W | `SetVariable` |
| 0x234 | `u8[0x14]` | _(gap)_ | - | - |
| 0x248 | `u32` | **`m_variable_248`** | R | `GetVariable`, `SetVariable`, `ShowHelp`, ... |
| 0x250 | `u32` | `m_field_250` | W | `O2TTarget`, `OnQuitGameDialogClose` |
| 0x254 | `u32` | **`m_variable_254`** | R/W | `O2TTarget`, `SetVariable`, `ShowHelp`, ... |
| 0x258 | `u32` | **`m_variable_258`** | R/W | `O2TTarget`, `OnSaveSettingsDialogClose`, `OnStateChange`, ... |

### `SaveGameTarget`

**Size:** >= 0x168 (360 bytes) | **Fields:** 55 (1 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `void**` | **`_vtable` (vtable pointer)** | R/W | `PerformSaveGame`, `SaveGameTarget`, `~SaveGameTarget` |
| 0x004 | `f32` | `m_field_004` | R/W | `SaveGameTarget`, `Update`, `~SaveGameTarget` |
| 0x008 | `u32` | `m_field_008` | R/W | `SaveGameTarget`, `~SaveGameTarget` |
| 0x00C | `u32` | `m_field_00C` | R/W | `SaveGameTarget`, `~SaveGameTarget` |
| 0x010 | `u32` | `m_field_010` | R/W | `SaveGameTarget`, `~SaveGameTarget` |
| 0x014 | `u32` | `m_field_014` | R/W | `SaveGameTarget`, `~SaveGameTarget` |
| 0x018 | `u32` | `m_field_018` | R/W | `SaveGameTarget`, `~SaveGameTarget` |
| 0x01C | `u32` | `m_field_01C` | R/W | `SaveGameTarget`, `~SaveGameTarget` |
| 0x020 | `u32` | `m_field_020` | R/W | `SaveGameTarget`, `~SaveGameTarget` |
| 0x024 | `u32` | `m_field_024` | R/W | `SaveGameTarget`, `~SaveGameTarget` |
| 0x028 | `u32` | `m_field_028` | W | `SaveGameTarget` |
| 0x038 | `u32` | `m_field_038` | W | `SaveGameTarget` |
| 0x048 | `u32` | `m_field_048` | W | `SaveGameTarget` |
| 0x058 | `u32` | `m_field_058` | R/W | `SaveGameTarget`, `~SaveGameTarget` |
| 0x068 | `u32` | `m_field_068` | R/W | `SaveGameTarget`, `~SaveGameTarget` |
| 0x078 | `u32` | `m_field_078` | W | `SaveGameTarget` |
| 0x07C | `u32` | `m_field_07C` | R/W | `SaveGameTarget`, `~SaveGameTarget` |
| 0x080 | `u32` | `m_field_080` | W | `SaveGameTarget`, `~SaveGameTarget` |
| 0x084 | `u32` | `m_field_084` | W | `SaveGameTarget`, `SpawnCardCorruptDialog`, `SpawnCardDamagedDialog`, ... |
| 0x088 | `u32` | `m_field_088` | W | `SpawnCardCorruptDialog`, `SpawnCardDamagedDialog`, `SpawnCheckingDialog`, ... |
| 0x08C | `u32` | `m_field_08C` | W | `SpawnCardCorruptDialog`, `SpawnCardDamagedDialog`, `SpawnCheckingDialog`, ... |
| 0x090 | `u32` | `m_field_090` | W | `SpawnCardCorruptDialog`, `SpawnCardDamagedDialog`, `SpawnCheckingDialog`, ... |
| 0x094 | `u32` | `m_field_094` | W | `SpawnCardCorruptDialog`, `SpawnCardDamagedDialog`, `SpawnCheckingDialog`, ... |
| 0x098 | `u32` | `m_field_098` | W | `SpawnCardCorruptDialog`, `SpawnCardDamagedDialog`, `SpawnCheckingDialog`, ... |
| 0x0A0 | `u32` | `m_field_0A0` | W | `SpawnCardCorruptDialog`, `SpawnCardDamagedDialog`, `SpawnCheckingDialog`, ... |
| 0x0A4 | `u8[0x1C]` | _(gap)_ | - | - |
| 0x0C0 | `u32` | `m_field_0C0` | W | `SpawnCardCorruptDialog`, `SpawnCardDamagedDialog`, `SpawnCheckingDialog`, ... |
| 0x0CC | `u16` | `m_field_0CC` | W | `SpawnCardCorruptDialog`, `SpawnCardDamagedDialog`, `SpawnCheckingDialog`, ... |
| 0x0CE | `u16` | `m_field_0CE` | W | `SpawnCardCorruptDialog`, `SpawnCardDamagedDialog`, `SpawnCheckingDialog`, ... |
| 0x0D0 | `u32` | `m_field_0D0` | W | `SpawnCardCorruptDialog`, `SpawnCardDamagedDialog`, `SpawnFormatCancelDialog`, ... |
| 0x0D4 | `u32` | `m_field_0D4` | W | `SaveGameTarget` |
| 0x0E4 | `u32` | `m_field_0E4` | W | `SaveGameTarget` |
| 0x0F4 | `u32` | `m_field_0F4` | W | `SaveGameTarget` |
| 0x104 | `u32` | `m_field_104` | W | `SaveGameTarget` |
| 0x108 | `u32` | `m_field_108` | W | `SaveGameTarget`, `~SaveGameTarget` |
| 0x110 | `u32` | `m_field_110` | R/W | `PerformMemoryCardChecks`, `PerformSaveGame`, `SaveGameTarget`, ... |
| 0x114 | `u32` | `m_field_114` | W | `SaveGameTarget`, `~SaveGameTarget` |
| 0x118 | `u32` | `m_field_118` | R/W | `PerformSaveGame`, `SaveGameTarget`, `SpawnCardCorruptDialog`, ... |
| 0x11C | `u32` | `m_field_11C` | R/W | `SaveGameTarget`, `SelectionCallback`, `Update` |
| 0x120 | `u32` | `m_field_120` | R/W | `SaveGameTarget`, `Update` |
| 0x128 | `u32` | `m_field_128` | R/W | `PerformMemoryCardChecks`, `PerformSaveGame`, `SaveGameTarget`, ... |
| 0x12C | `u32` | `m_field_12C` | R/W | `PerformMemoryCardChecks`, `PerformSaveGame`, `SaveGameTarget`, ... |
| 0x130 | `u32` | `m_field_130` | R/W | `PerformMemoryCardChecks`, `PerformSaveGame`, `SaveGameTarget`, ... |
| 0x134 | `u32` | `m_field_134` | R/W | `PerformSaveGame`, `SaveGameTarget`, `Update` |
| 0x138 | `u32` | `m_field_138` | R/W | `PerformMemoryCardChecks`, `PerformSaveGame`, `SaveGameTarget`, ... |
| 0x13C | `u32` | `m_field_13C` | R/W | `PerformSaveGame`, `SaveGameTarget` |
| 0x140 | `u32` | `m_field_140` | R/W | `PerformSaveGame`, `SaveGameTarget`, `Update` |
| 0x144 | `u32` | `m_field_144` | R/W | `PerformSaveGame`, `SaveGameTarget` |
| 0x148 | `u32` | `m_field_148` | R/W | `PerformSaveGame`, `SaveGameTarget` |
| 0x14C | `u32` | `m_field_14C` | W | `SaveGameTarget`, `Update`, `ZeroInputCallback` |
| 0x150 | `u32` | `m_field_150` | W | `SaveGameTarget`, `Update` |
| 0x154 | `u32` | `m_field_154` | R/W | `PerformSaveGame`, `SaveGameTarget`, `Update` |
| 0x158 | `u32` | `m_field_158` | R/W | `PerformSaveGame` |
| 0x15C | `u32` | `m_field_15C` | R/W | `PerformSaveGame` |
| 0x160 | `f32` | `m_field_160` | W | `SaveGameTarget` |
| 0x164 | `f32` | `m_field_164` | W | `SaveGameTarget` |

### `ESpriteRender`

**Size:** >= 0x5E98 (24216 bytes) | **Fields:** 53 (49 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `f32` | **`m_upDoubleRect`** | R/W | `DrawDirectly`, `DrawIntoOrderTable`, `SetSprite`, ... |
| 0x001 | `u8` | **`m_upDoubleRect_001`** | W | `SetUpDoubleRect`, `SetUpRect` |
| 0x002 | `u8` | **`m_upDoubleRect_002`** | W | `SetUpDoubleRect`, `SetUpRect` |
| 0x003 | `u8` | **`m_upDoubleRect_003`** | W | `SetUpDoubleRect`, `SetUpRect` |
| 0x004 | `f32` | **`m_upDoubleRect_004`** | R/W | `DrawDirectly`, `DrawIntoOrderTable`, `SetSprite`, ... |
| 0x005 | `u8` | **`m_upDoubleRect_005`** | W | `SetUpDoubleRect`, `SetUpRect` |
| 0x006 | `u8` | **`m_upDoubleRect_006`** | W | `SetUpDoubleRect`, `SetUpRect` |
| 0x007 | `u8` | **`m_upDoubleRect_007`** | W | `SetUpDoubleRect`, `SetUpRect` |
| 0x008 | `f32` | **`m_upDoubleRect_008`** | R/W | `DrawDirectly`, `DrawIntoOrderTable`, `SetSprite`, ... |
| 0x00C | `f32` | **`m_upDoubleRect_00C`** | R/W | `DeleteShaders`, `DrawDirectly`, `DrawIntoOrderTable`, ... |
| 0x010 | `f32` | **`m_upDoubleRect_010`** | R/W | `DeleteShaders`, `DrawDirectly`, `DrawIntoOrderTable`, ... |
| 0x014 | `f32` | **`m_upDoubleRect_014`** | R/W | `DeleteShaders`, `SetSprite`, `SetUpDoubleRect`, ... |
| 0x018 | `f32` | **`m_upDoubleRect_018`** | R/W | `DeleteShaders`, `DrawDirectly`, `SetSprite`, ... |
| 0x01C | `f32` | **`m_upDoubleRect_01C`** | R/W | `DeleteShaders`, `SetSprite`, `SetUpDoubleRect`, ... |
| 0x020 | `u32` | **`m_sprite`** | R/W | `DeleteShaders`, `DrawDirectly`, `SetSprite`, ... |
| 0x024 | `u32` | **`m_sprite_024`** | R/W | `DeleteShaders`, `DrawDirectly`, `SetSprite`, ... |
| 0x028 | `u32` | **`m_sprite_028`** | R/W | `DeleteShaders`, `SetSprite`, `Update` |
| 0x02C | `u32` | **`m_sprite_02C`** | R/W | `DeleteShaders`, `DrawDirectly`, `SetSprite`, ... |
| 0x030 | `u32` | **`m_sprite_030`** | R/W | `DeleteShaders`, `SetSprite`, `Update` |
| 0x038 | `f32` | **`m_upDoubleRect_038`** | R/W | `DrawDirectly`, `SetSprite`, `SetUpDoubleRect` |
| 0x03C | `f32` | **`m_sprite_03C`** | R/W | `DrawDirectly`, `SetSprite` |
| 0x040 | `f32` | **`m_sprite_040`** | R/W | `DrawDirectly`, `SetSprite` |
| 0x048 | `u32` | **`m_sprite_048`** | R | `SetSprite` |
| 0x04C | `f32` | **`m_sprite_04C`** | W | `SetSprite` |
| 0x050 | `f32` | **`m_directly`** | R | `DrawDirectly` |
| 0x054 | `f32` | **`m_directly_054`** | R | `DrawDirectly` |
| 0x058 | `f32` | **`m_directly_058`** | R/W | `DrawDirectly` |
| 0x05C | `f32` | **`m_sprite_05C`** | R/W | `DrawDirectly`, `SetSprite` |
| 0x060 | `f32` | **`m_sprite_060`** | R/W | `DrawDirectly`, `SetSprite` |
| 0x064 | `f32` | **`m_sprite_064`** | R/W | `DrawDirectly`, `SetSprite` |
| 0x070 | `f32` | **`m_sprite_070`** | W | `SetSprite` |
| 0x07C | `f32` | **`m_directly_07C`** | W | `DrawDirectly` |
| 0x080 | `f32` | **`m_sprite_080`** | R/W | `DrawDirectly`, `SetSprite` |
| 0x084 | `f32` | **`m_sprite_084`** | R/W | `DrawDirectly`, `SetSprite` |
| 0x088 | `f32` | **`m_sprite_088`** | R/W | `DrawDirectly`, `SetSprite` |
| 0x094 | `u32` | **`m_sprite_094`** | W | `SetSprite` |
| 0x098 | `s16` | `m_field_098` | R | `DrawDirectly`, `DrawIntoOrderTable`, `SpriteRenderOrderTableCallback` |
| 0x09C | `u32` | **`m_intoOrderTable`** | R | `DrawDirectly`, `DrawIntoOrderTable` |
| 0x0A8 | `u32` | `m_field_0A8` | W | `SpriteRenderOrderTableCallback` |
| 0x0AC | `u32` | **`m_intoOrderTable_0AC`** | W | `DrawIntoOrderTable`, `SpriteRenderOrderTableCallback` |
| 0x0B0 | `s16` | **`m_upDoubleRect_0B0`** | R/W | `SetUpDoubleRect`, `SpriteRenderOrderTableCallback` |
| 0x0B4 | `u32` | **`m_upDoubleRect_0B4`** | R/W | `SetUpDoubleRect`, `SpriteRenderOrderTableCallback` |
| 0x0C8 | `u32` | **`m_intoOrderTable_0C8`** | R | `DrawIntoOrderTable` |
| 0x0DC | `u32` | **`m_intoOrderTable_0DC`** | W | `DrawIntoOrderTable` |
| 0x0E0 | `f32` | **`m_upDoubleRect_0E0`** | R | `SetUpDoubleRect` |
| 0x0E8 | `u32` | `m_field_0E8` | W | `~ESpriteRender` |
| 0x0F0 | `f32` | **`m_upDoubleRect_0F0`** | R | `DrawDirectly`, `SetUpDoubleRect` |
| 0x0F4 | `u8[0x2DC]` | _(gap)_ | - | - |
| 0x3D0 | `u32` | **`m_intoOrderTable_3D0`** | R | `DrawIntoOrderTable` |
| 0x3D4 | `u8[0x18]` | _(gap)_ | - | - |
| 0x3EC | `u32` | `m_field_3EC` | R | `Update` |
| 0x3F0 | `u8[0x1110]` | _(gap)_ | - | - |
| 0x1500 | `f32` | **`m_intoOrderTable_1500`** | R | `DrawIntoOrderTable` |
| 0x1508 | `f32` | **`m_directly_1508`** | R | `DrawDirectly` |
| 0x150C | `u8[0x48]` | _(gap)_ | - | - |
| 0x1554 | `f32` | **`m_upDoubleRect_1554`** | R | `SetUpDoubleRect` |
| 0x1558 | `u8[0x493C]` | _(gap)_ | - | - |
| 0x5E94 | `u32` | **`m_intoOrderTable_5E94`** | R | `DrawIntoOrderTable` |

### `GameData`

**Size:** >= 0x1E34 (7732 bytes) | **Fields:** 53 (3 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `void**` | **`_vtable` (vtable pointer)** | R/W | `CreateAFamilyAddFamilyMember`, `GameData`, `LoadDefaultNeighborhood`, ... |
| 0x004 | `s16` | `m_field_004` | R/W | `PlayerEnterHouse`, `PrepCreateAFamilyData`, `PrepareSimData` |
| 0x006 | `u8[0x1E]` | _(gap)_ | - | - |
| 0x024 | `u32` | `m_field_024` | R | `StoreCreateAFamilyData` |
| 0x02C | `u32` | `m_field_02C` | W | `GameData`, `SystemPreUpdate` |
| 0x030 | `u32` | **`m_bIsPlayerConnected`** | R/W | `GameData`, `IsPlayerConnected`, `SystemPreUpdate` |
| 0x034 | `u32` | **`m_bIsPlayerConnected_034`** | R/W | `GameData`, `IsPlayerConnected`, `PlayerEnterHouse`, ... |
| 0x038 | `u32` | `m_field_038` | R/W | `PrepCreateAFamilyData`, `StoreCreateAFamilyData` |
| 0x03C | `u32` | `m_field_03C` | W | `GameData` |
| 0x040 | `u32` | `m_field_040` | W | `GameData` |
| 0x044 | `u32` | `m_field_044` | W | `GameData` |
| 0x048 | `u32` | `m_field_048` | W | `GameData` |
| 0x04C | `u32` | `m_field_04C` | W | `GameData` |
| 0x050 | `u32` | `m_field_050` | W | `GameData` |
| 0x054 | `u32` | `m_field_054` | R | `~GameData` |
| 0x058 | `u8[0x14]` | _(gap)_ | - | - |
| 0x06C | `u32` | `m_field_06C` | R/W | `GameData`, `~GameData` |
| 0x070 | `u32` | `m_field_070` | R/W | `GameData`, `~GameData` |
| 0x074 | `u32` | `m_field_074` | R/W | `GameData`, `~GameData` |
| 0x078 | `u32` | `m_field_078` | R/W | `GameData`, `PrepCreateAFamilyData`, `PrepareSimData`, ... |
| 0x080 | `u32` | `m_field_080` | W | `GameData` |
| 0x084 | `u32` | `m_field_084` | W | `GameData`, `GamePlayReset` |
| 0x086 | `u16` | `m_field_086` | W | `LoadDefaultNeighborhood`, `LoadSavedNeighborhood` |
| 0x088 | `u16` | `m_field_088` | W | `LoadDefaultNeighborhood`, `PlayerEnterHouse` |
| 0x08C | `u32` | `m_field_08C` | R/W | `GameData`, `PrepCreateAFamilyData`, `StoreCreateAFamilyData` |
| 0x090 | `u32` | `m_field_090` | W | `GameData` |
| 0x094 | `u32` | `m_field_094` | W | `GameData` |
| 0x098 | `u32` | `m_field_098` | W | `GameData` |
| 0x09C | `u32` | `m_field_09C` | W | `GameData` |
| 0x0A0 | `u32` | `m_field_0A0` | W | `GameData` |
| 0x0A4 | `u16` | `m_field_0A4` | W | `GameData`, `ReplaceSimData` |
| 0x0A8 | `u32` | `m_field_0A8` | W | `GameData` |
| 0x0B0 | `u32` | `m_field_0B0` | W | `GameData` |
| 0x0B4 | `u32` | `m_field_0B4` | W | `GameData` |
| 0x0B8 | `u32` | `m_field_0B8` | W | `GameData` |
| 0x0BC | `u32` | `m_field_0BC` | W | `GameData` |
| 0x0C0 | `u32` | `m_field_0C0` | W | `GameData` |
| 0x0C4 | `u32` | `m_field_0C4` | W | `GameData` |
| 0x0C8 | `u32` | `m_field_0C8` | W | `GameData` |
| 0x0CC | `u32` | `m_field_0CC` | W | `GameData` |
| 0x0D8 | `u32` | `m_field_0D8` | W | `GameData` |
| 0x0DC | `f32` | `m_field_0DC` | W | `GameData` |
| 0x0E0 | `f32` | `m_field_0E0` | W | `GameData` |
| 0x0E4 | `u32` | `m_field_0E4` | W | `GameData`, `GamePlayReset` |
| 0x0E8 | `u32` | `m_field_0E8` | W | `GameData`, `GamePlayReset` |
| 0x0EC | `u32` | `m_field_0EC` | W | `GameData` |
| 0x0F0 | `u32` | `m_field_0F0` | R/W | `GameData`, `GamePlayReset`, `SystemPostDraw` |
| 0x0F4 | `u8[0x20]` | _(gap)_ | - | - |
| 0x114 | `u32` | `m_field_114` | R/W | `CopyrightUpdate`, `GameData` |
| 0x118 | `f32` | `m_field_118` | R/W | `CopyrightDraw`, `CopyrightUpdate`, `GameData` |
| 0x11C | `f32` | `m_field_11C` | W | `CopyrightUpdate`, `GameData` |
| 0x120 | `f32` | `m_field_120` | W | `GameData` |
| 0x124 | `u32` | `m_field_124` | W | `GameData` |
| 0x128 | `u32` | `m_field_128` | W | `GameData` |
| 0x12C | `u8[0xDC]` | _(gap)_ | - | - |
| 0x208 | `u32` | `m_field_208` | R | `SystemPreUpdate` |
| 0x20C | `u8[0x1C24]` | _(gap)_ | - | - |
| 0x1E30 | `f32` | `m_field_1E30` | R | `SystemPostDraw` |

### `INGTarget`

**Size:** >= 0x468 (1128 bytes) | **Fields:** 53 (29 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `u8` | **`m_localizable`** | R/W | `GetLocalizable`, `GetVariable`, `INGTarget`, ... |
| 0x002 | `s16` | **`m_localizable_002`** | R | `GetLocalizable` |
| 0x004 | `u16` | **`m_localizable_004`** | R/W | `GetLocalizable`, `GetVariable`, `INGTarget`, ... |
| 0x006 | `u8` | **`m_variable`** | W | `GetVariable` |
| 0x008 | `u32` | **`m_variable_008`** | R/W | `INGTarget`, `SetVariable`, `install_current_item_shaders`, ... |
| 0x00C | `u32` | **`m_variable_00C`** | R/W | `INGTarget`, `SetVariable`, `~INGTarget` |
| 0x010 | `u32` | **`m_localizable_010`** | R/W | `GetLocalizable`, `INGTarget`, `~INGTarget` |
| 0x014 | `u32` | **`m_localizable_014`** | R/W | `GetLocalizable`, `INGTarget`, `~INGTarget` |
| 0x018 | `u32` | **`m_localizable_018`** | R/W | `GetLocalizable`, `INGTarget`, `~INGTarget` |
| 0x01C | `u32` | **`m_localizable_01C`** | R/W | `GetLocalizable`, `INGTarget`, `SetVariable`, ... |
| 0x020 | `u32` | `m_field_020` | R/W | `INGTarget`, `~INGTarget` |
| 0x024 | `u32` | **`m_localizable_024`** | R/W | `GetLocalizable`, `INGTarget`, `~INGTarget` |
| 0x028 | `u32` | `m_field_028` | W | `INGTarget` |
| 0x038 | `u32` | `m_field_038` | W | `INGTarget` |
| 0x048 | `u32` | `m_field_048` | W | `INGTarget` |
| 0x058 | `u32` | `m_field_058` | R/W | `INGTarget`, `~INGTarget` |
| 0x068 | `u32` | `m_field_068` | R/W | `INGTarget`, `~INGTarget` |
| 0x078 | `u32` | `m_field_078` | W | `INGTarget` |
| 0x07C | `u32` | **`m_variable_07C`** | R/W | `INGTarget`, `SetVariable`, `install_current_item_shaders`, ... |
| 0x080 | `u32` | `m_field_080` | R/W | `INGTarget`, `onHelpDialogSelection`, `~INGTarget` |
| 0x084 | `u32` | `m_field_084` | W | `INGTarget`, `~INGTarget` |
| 0x088 | `u32` | `m_field_088` | W | `INGTarget`, `~INGTarget` |
| 0x08C | `u32` | `m_field_08C` | W | `INGTarget` |
| 0x090 | `u32` | `m_field_090` | W | `INGTarget` |
| 0x094 | `u32` | **`m_variable_094`** | R/W | `INGTarget`, `SetVariable`, `Update` |
| 0x098 | `u32` | `m_field_098` | W | `INGTarget` |
| 0x09A | `s16` | `m_field_09A` | R | `end_dialog` |
| 0x09C | `u32` | `m_field_09C` | R/W | `INGTarget`, `~INGTarget` |
| 0x0A0 | `u32` | `m_field_0A0` | R/W | `INGTarget`, `~INGTarget` |
| 0x0A4 | `u32` | **`m_variable_0A4`** | W | `SetVariable` |
| 0x0A8 | `u32` | **`m_variable_0A8`** | W | `SetVariable` |
| 0x0B8 | `u32` | **`m_variable_0B8`** | W | `SetVariable` |
| 0x0C8 | `u32` | **`m_variable_0C8`** | W | `SetVariable` |
| 0x0CC | `u8[0x28]` | _(gap)_ | - | - |
| 0x0F4 | `u32` | **`m_variable_0F4`** | W | `SetVariable` |
| 0x104 | `u32` | **`m_variable_104`** | W | `SetVariable` |
| 0x114 | `u32` | **`m_variable_114`** | W | `SetVariable` |
| 0x118 | `u8[0x18]` | _(gap)_ | - | - |
| 0x130 | `u32` | **`m_variable_130`** | W | `SetVariable` |
| 0x134 | `u32` | **`m_variable_134`** | R/W | `INGTarget`, `SetVariable`, `onHelpDialogSelection` |
| 0x138 | `u8[0xA8]` | _(gap)_ | - | - |
| 0x1E0 | `u32` | `m_field_1E0` | R | `end_dialog` |
| 0x1E8 | `u32` | `m_field_1E8` | R | `end_dialog` |
| 0x1F0 | `u32` | `m_field_1F0` | R | `end_dialog` |
| 0x1F8 | `u32` | `m_field_1F8` | R | `end_dialog` |
| 0x200 | `u32` | `m_field_200` | R/W | `INGTarget`, `create_edit_buffer`, `end_dialog` |
| 0x204 | `u32` | `m_field_204` | R | `end_dialog` |
| 0x208 | `u8[0x23C]` | _(gap)_ | - | - |
| 0x444 | `u32` | **`m_localizable_444`** | R/W | `GetLocalizable`, `INGTarget`, `SetVariable`, ... |
| 0x448 | `u32` | **`m_localizable_448`** | R/W | `GetLocalizable`, `INGTarget`, `SetVariable` |
| 0x44C | `u32` | **`m_variable_44C`** | R/W | `INGTarget`, `SetVariable`, `get_current_inginfo` |
| 0x450 | `u32` | **`m_variable_450`** | R/W | `INGTarget`, `SetVariable`, `get_current_mix_inginfo` |
| 0x454 | `u32` | **`m_localizable_454`** | R/W | `GetLocalizable`, `INGTarget`, `SetVariable`, ... |
| 0x458 | `u32` | **`m_variable_458`** | R/W | `INGTarget`, `SetVariable`, `Update` |
| 0x45C | `u32` | `m_field_45C` | R/W | `INGTarget`, `Update` |
| 0x460 | `f32` | **`m_variable_460`** | R/W | `INGTarget`, `SetVariable`, `Update` |
| 0x464 | `u32` | `m_field_464` | R/W | `INGTarget`, `Update` |

### `MUWrapper`

**Size:** >= 0x118 (280 bytes) | **Fields:** 53 (20 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `void**` | **`_vtable` (vtable pointer)** | R/W | `GetVariable`, `Startup` |
| 0x004 | `u32` | **`m_variable_004`** | R/W | `Draw`, `GetVariable`, `Reset`, ... |
| 0x008 | `u32` | `m_field_008` | R/W | `ResetSlotSelection`, `Startup` |
| 0x00C | `f32` | `m_field_00C` | W | `Startup` |
| 0x010 | `f32` | `m_field_010` | W | `Startup` |
| 0x014 | `f32` | `m_field_014` | W | `Startup` |
| 0x018 | `f32` | `m_field_018` | W | `Startup` |
| 0x01C | `f32` | **`m_variable_01C`** | R/W | `GetVariable`, `Reset`, `ResetSlotSelection`, ... |
| 0x020 | `f32` | `m_field_020` | W | `Startup` |
| 0x024 | `f32` | `m_field_024` | W | `Startup` |
| 0x028 | `f32` | `m_field_028` | W | `Startup` |
| 0x02C | `f32` | `m_field_02C` | W | `Startup` |
| 0x030 | `f32` | `m_field_030` | W | `Startup` |
| 0x034 | `u32` | `m_field_034` | W | `Startup` |
| 0x038 | `u32` | `m_field_038` | W | `Startup` |
| 0x03C | `u32` | `m_field_03C` | W | `Startup` |
| 0x03F | `u8` | **`m_variable_03F`** | W | `GetVariable` |
| 0x040 | `u8[0x1C]` | _(gap)_ | - | - |
| 0x05C | `u32` | `m_field_05C` | W | `Startup` |
| 0x060 | `u32` | `m_field_060` | W | `Startup` |
| 0x064 | `u32` | `m_field_064` | W | `Startup` |
| 0x068 | `f32` | `m_field_068` | W | `Startup` |
| 0x06C | `u32` | `m_field_06C` | W | `Startup` |
| 0x080 | `u32` | `m_field_080` | W | `~MUWrapper` |
| 0x08C | `u32` | `m_field_08C` | R | `~MUWrapper` |
| 0x090 | `u8[0x14]` | _(gap)_ | - | - |
| 0x0A4 | `u32` | `m_field_0A4` | R/W | `Reset`, `ResetSlotSelection`, `Shutdown`, ... |
| 0x0A8 | `u32` | **`m_variable_0A8`** | R/W | `Draw`, `GetVariable`, `HideDialog`, ... |
| 0x0AC | `u32` | **`m_variable_0AC`** | R/W | `GetVariable`, `Reset`, `ResetSlotSelection`, ... |
| 0x0B0 | `u32` | **`m_variable_0B0`** | R/W | `GetVariable`, `Reset`, `ResetSlotSelection`, ... |
| 0x0B4 | `u32` | **`m_upDisplayOkType`** | R | `Draw`, `Reset`, `SetupDisplayOkType`, ... |
| 0x0B8 | `u32` | **`m_upQueryType`** | R | `SetupQueryType` |
| 0x0BC | `u32` | **`m_upInfoType`** | R | `SetupInfoType` |
| 0x0C0 | `u32` | `m_field_0C0` | R/W | `HideDialog`, `ShowDialog` |
| 0x0C4 | `u32` | `m_field_0C4` | R/W | `HideMenu`, `ShowMenu` |
| 0x0C8 | `u32` | `m_field_0C8` | R/W | `Draw`, `Startup` |
| 0x0CC | `u32` | **`m_variable_0CC`** | R/W | `ResetSlotSelection`, `SetVariable`, `Startup` |
| 0x0D0 | `u32` | **`m_variable_0D0`** | R/W | `SetVariable`, `Startup` |
| 0x0D4 | `f32` | **`m_variable_0D4`** | R/W | `ResetSlotSelection`, `SetVariable`, `Startup` |
| 0x0D8 | `f32` | **`m_variable_0D8`** | W | `SetVariable` |
| 0x0DC | `f32` | **`m_variable_0DC`** | R/W | `ResetSlotSelection`, `SetVariable`, `Startup` |
| 0x0E0 | `f32` | **`m_variable_0E0`** | R/W | `ResetSlotSelection`, `SetVariable` |
| 0x0E4 | `f32` | **`m_variable_0E4`** | R/W | `GetVariable`, `Reset`, `Startup` |
| 0x0E8 | `f32` | **`m_variable_0E8`** | R | `GetVariable`, `Reset` |
| 0x0EC | `f32` | **`m_variable_0EC`** | R/W | `GetVariable`, `Reset`, `Startup` |
| 0x0F0 | `f32` | **`m_variable_0F0`** | R/W | `GetVariable`, `Reset` |
| 0x0F4 | `u32` | `m_field_0F4` | R/W | `Reset` |
| 0x0F8 | `u32` | `m_field_0F8` | R/W | `Reset` |
| 0x0FC | `u32` | `m_field_0FC` | R/W | `Reset` |
| 0x100 | `u32` | `m_field_100` | R/W | `Reset` |
| 0x104 | `u32` | `m_field_104` | W | `Reset` |
| 0x108 | `u32` | `m_field_108` | R/W | `Draw`, `HideDialog`, `Reset`, ... |
| 0x10C | `u32` | `m_field_10C` | R/W | `Draw`, `HideDialog`, `Reset`, ... |
| 0x110 | `u32` | `m_field_110` | R/W | `Draw`, `HideDialog`, `Reset`, ... |
| 0x114 | `u32` | `m_field_114` | R/W | `Draw`, `HideDialog`, `Reset`, ... |

### `MMUTarget`

**Size:** >= 0x360 (864 bytes) | **Fields:** 52 (15 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `u16` | **`m_localizable`** | R/W | `GetLocalizable`, `GetVariable`, `MMUTarget`, ... |
| 0x004 | `u16` | **`m_variable`** | R/W | `Draw`, `GetVariable`, `MMUTarget`, ... |
| 0x006 | `u8` | **`m_variable_006`** | W | `GetVariable` |
| 0x008 | `u32` | `m_field_008` | R/W | `Draw`, `GoUpMenuTree`, `MMUTarget`, ... |
| 0x00C | `u32` | `m_field_00C` | R/W | `Draw`, `GoUpMenuTree`, `MMUTarget`, ... |
| 0x010 | `u8` | `m_field_010` | R/W | `Draw`, `GoUpMenuTree`, `MMUTarget`, ... |
| 0x014 | `u32` | `m_field_014` | R/W | `GoUpMenuTree`, `MMUTarget`, `~MMUTarget` |
| 0x018 | `u32` | **`m_menuState`** | R/W | `MMUTarget`, `UpdateMenuState`, `~MMUTarget` |
| 0x01C | `u32` | `m_field_01C` | R/W | `MMUTarget`, `~MMUTarget` |
| 0x020 | `u32` | `m_field_020` | R/W | `MMUTarget`, `~MMUTarget` |
| 0x024 | `u32` | `m_field_024` | R/W | `MMUTarget`, `~MMUTarget` |
| 0x028 | `u32` | `m_field_028` | W | `MMUTarget` |
| 0x038 | `u32` | `m_field_038` | W | `MMUTarget` |
| 0x048 | `u32` | `m_field_048` | W | `MMUTarget` |
| 0x058 | `u32` | `m_field_058` | R/W | `MMUTarget`, `~MMUTarget` |
| 0x068 | `u32` | `m_field_068` | R/W | `MMUTarget`, `~MMUTarget` |
| 0x078 | `u32` | `m_field_078` | W | `MMUTarget` |
| 0x07C | `u32` | `m_field_07C` | R/W | `MMUTarget`, `~MMUTarget` |
| 0x080 | `u32` | **`m_currentChoice`** | R/W | `DecrementChoice`, `GoUpMenuTree`, `IncrementChoice`, ... |
| 0x084 | `u32` | **`m_variable_084`** | W | `GetVariable`, `MMUTarget` |
| 0x088 | `u32` | `m_field_088` | W | `MMUTarget` |
| 0x08C | `u32` | **`m_listItemName`** | R/W | `ChangeScreenMode`, `DecrementChoice`, `Draw`, ... |
| 0x090 | `u32` | `m_field_090` | W | `ChangeScreenMode`, `MMUTarget`, `OnNGHSelect` |
| 0x094 | `u32` | `m_field_094` | W | `MMUTarget` |
| 0x098 | `u32` | `m_field_098` | R/W | `LaunchLot`, `MMUTarget`, `OnDownKeyPressed`, ... |
| 0x09C | `u32` | `m_field_09C` | R/W | `ChangeScreenMode`, `MMUTarget`, `OnDownKeyPressed`, ... |
| 0x0A0 | `u32` | `m_field_0A0` | R/W | `MMUTarget`, `OnDownKeyPressed`, `OnUpKeyPressed`, ... |
| 0x0A4 | `u32` | `m_field_0A4` | R/W | `DecrementChoice`, `EndPlayerNumberChooser`, `IncrementChoice`, ... |
| 0x0A8 | `u32` | **`m_topLevelChoice`** | W | `MMUTarget`, `UpdateTopLevelChoice` |
| 0x0AC | `u32` | `m_field_0AC` | R/W | `MMUTarget`, `OnXKeyPressed`, `Update`, ... |
| 0x0B0 | `u32` | **`m_numberOfChoicesInState`** | R/W | `DecrementChoice`, `GetNumberOfChoicesInState`, `GetVariable`, ... |
| 0x0B4 | `u32` | **`m_menuState_0B4`** | W | `MMUTarget`, `UpdateMenuState` |
| 0x0B8 | `u32` | **`m_localizable_0B8`** | R/W | `DecrementChoice`, `GetLocalizable`, `IncrementChoice`, ... |
| 0x0BC | `u32` | **`m_gameplayChoice`** | W | `MMUTarget`, `UpdateGameplayChoice` |
| 0x0C0 | `u32` | `m_field_0C0` | R/W | `DecrementChoice`, `IncrementChoice`, `MMUTarget`, ... |
| 0x0C4 | `u32` | **`m_numberOfPlayersChoice`** | W | `MMUTarget`, `UpdateNumberOfPlayersChoice` |
| 0x0C8 | `u32` | `m_field_0C8` | R/W | `GoUpMenuTree`, `MMUTarget` |
| 0x0D8 | `u32` | `m_field_0D8` | R/W | `GoUpMenuTree`, `MMUTarget` |
| 0x0DC | `u8[0x1C]` | _(gap)_ | - | - |
| 0x0F8 | `u32` | **`m_menuState_0F8`** | R/W | `GoUpMenuTree`, `MMUTarget`, `UpdateMenuState` |
| 0x0FC | `u32` | `m_field_0FC` | R/W | `MMUTarget`, `Update` |
| 0x100 | `u32` | `m_field_100` | R/W | `MMUTarget`, `OnStartGameComplete`, `OnXKeyPressed`, ... |
| 0x104 | `u32` | `m_field_104` | W | `MMUTarget`, `OnXKeyPressed` |
| 0x110 | `u32` | `m_field_110` | W | `OnXKeyPressed` |
| 0x118 | `u32` | `m_field_118` | W | `OnXKeyPressed` |
| 0x120 | `u32` | `m_field_120` | W | `OnXKeyPressed` |
| 0x124 | `u32` | `m_field_124` | W | `OnXKeyPressed` |
| 0x128 | `u8[0x2C]` | _(gap)_ | - | - |
| 0x154 | `u32` | `m_field_154` | W | `MMUTarget`, `OnXKeyPressed` |
| 0x164 | `u32` | `m_field_164` | W | `MMUTarget`, `OnXKeyPressed` |
| 0x174 | `u32` | `m_field_174` | W | `MMUTarget`, `OnXKeyPressed` |
| 0x178 | `u8[0x14]` | _(gap)_ | - | - |
| 0x18C | `u32` | `m_field_18C` | R/W | `Draw`, `MMUTarget` |
| 0x190 | `u32` | `m_field_190` | R/W | `Dialog2ClosedCallback`, `OnStartGameComplete`, `OnXKeyPressed`, ... |
| 0x194 | `u8[0x1C8]` | _(gap)_ | - | - |
| 0x35C | `u32` | **`m_localizable_35C`** | R | `GetLocalizable` |

### `PDATarget`

**Size:** >= 0x178 (376 bytes) | **Fields:** 52 (13 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `u16` | **`m_variable`** | R/W | `GetVariable`, `HandleButtonHelpMessage`, `PDATarget`, ... |
| 0x004 | `u16` | **`m_variable_004`** | R/W | `GetVariable`, `PDATarget`, `~PDATarget` |
| 0x006 | `u8` | **`m_variable_006`** | W | `GetVariable` |
| 0x008 | `u32` | `m_field_008` | R/W | `PDATarget`, `~PDATarget` |
| 0x00C | `u32` | `m_field_00C` | R/W | `PDATarget`, `~PDATarget` |
| 0x010 | `u32` | `m_field_010` | R/W | `PDATarget`, `~PDATarget` |
| 0x014 | `u32` | `m_field_014` | R/W | `PDATarget`, `~PDATarget` |
| 0x018 | `u32` | `m_field_018` | R/W | `PDATarget`, `~PDATarget` |
| 0x01C | `u32` | **`m_upSkinShaders`** | R/W | `PDATarget`, `SetupSkinShaders`, `~PDATarget` |
| 0x020 | `u32` | `m_field_020` | R/W | `PDATarget`, `~PDATarget` |
| 0x024 | `u32` | `m_field_024` | R/W | `PDATarget`, `~PDATarget` |
| 0x028 | `u32` | `m_field_028` | W | `PDATarget` |
| 0x02C | `u32` | `m_field_02C` | R | `~PDATarget` |
| 0x038 | `u32` | `m_field_038` | W | `PDATarget` |
| 0x03C | `u8` | `m_field_03C` | R/W | `PDATarget`, `~PDATarget` |
| 0x040 | `u32` | `m_field_040` | W | `PDATarget` |
| 0x044 | `u32` | `m_field_044` | W | `PDATarget` |
| 0x048 | `u16` | `m_field_048` | W | `PDATarget` |
| 0x04A | `u16` | `m_field_04A` | W | `PDATarget` |
| 0x04C | `u32` | `m_field_04C` | W | `PDATarget` |
| 0x058 | `u32` | `m_field_058` | R/W | `PDATarget`, `~PDATarget` |
| 0x068 | `u32` | `m_field_068` | R/W | `PDATarget`, `~PDATarget` |
| 0x078 | `u32` | `m_field_078` | W | `PDATarget` |
| 0x07C | `u32` | **`m_upSkinShaders_07C`** | R/W | `PDATarget`, `SetupSkinShaders`, `~PDATarget` |
| 0x080 | `u32` | `m_field_080` | W | `PDATarget`, `~PDATarget` |
| 0x084 | `u32` | `m_field_084` | W | `HandleButtonHelpMessage`, `HandleFirstOpenMessage`, `PDATarget` |
| 0x088 | `u32` | `m_field_088` | W | `HandleButtonHelpMessage`, `HandleFirstOpenMessage` |
| 0x08C | `u32` | `m_field_08C` | W | `HandleButtonHelpMessage`, `HandleFirstOpenMessage` |
| 0x090 | `u32` | `m_field_090` | W | `HandleButtonHelpMessage`, `HandleFirstOpenMessage` |
| 0x094 | `u32` | `m_field_094` | W | `HandleButtonHelpMessage`, `HandleFirstOpenMessage` |
| 0x098 | `u32` | `m_field_098` | W | `HandleButtonHelpMessage`, `HandleFirstOpenMessage` |
| 0x0A8 | `u32` | `m_field_0A8` | W | `HandleButtonHelpMessage`, `HandleFirstOpenMessage` |
| 0x0AC | `u8[0x24]` | _(gap)_ | - | - |
| 0x0D0 | `u32` | `m_field_0D0` | W | `HandleButtonHelpMessage`, `HandleFirstOpenMessage` |
| 0x0D4 | `u32` | `m_field_0D4` | W | `PDATarget` |
| 0x0E4 | `u32` | `m_field_0E4` | W | `PDATarget` |
| 0x0F4 | `u32` | `m_field_0F4` | W | `PDATarget` |
| 0x104 | `u32` | `m_field_104` | W | `PDATarget` |
| 0x108 | `u32` | `m_field_108` | W | `PDATarget`, `~PDATarget` |
| 0x10C | `u8[0x28]` | _(gap)_ | - | - |
| 0x134 | `u32` | `m_field_134` | R | `HandleSubTargetStateChange` |
| 0x13C | `u32` | **`m_variable_13C`** | R | `GetVariable`, `HandleSubTargetStateChange` |
| 0x140 | `u32` | **`m_variable_140`** | R | `GetVariable`, `HandleSubTargetStateChange` |
| 0x144 | `u32` | `m_field_144` | R | `HandleSubTargetStateChange` |
| 0x148 | `u32` | `m_field_148` | R | `HandleSubTargetStateChange` |
| 0x14C | `u32` | **`m_variable_14C`** | W | `SetVariable` |
| 0x150 | `u32` | **`m_variable_150`** | W | `SetVariable` |
| 0x154 | `u32` | **`m_variable_154`** | W | `SetVariable` |
| 0x158 | `u32` | **`m_variable_158`** | W | `SetVariable` |
| 0x15C | `u32` | `m_field_15C` | R/W | `PDATarget`, `~PDATarget` |
| 0x168 | `u32` | `m_field_168` | W | `HandleButtonHelpMessage`, `HandleFirstOpenMessage`, `PDATarget` |
| 0x16C | `u32` | `m_field_16C` | R/W | `PDATarget`, `~PDATarget` |
| 0x170 | `u32` | **`m_variable_170`** | R/W | `PDATarget`, `SelectionCallback`, `SetVariable` |
| 0x174 | `u32` | **`m_variable_174`** | R/W | `SelectionCallback`, `SetVariable` |

### `ERLevel`

**Size:** >= 0x60A4 (24740 bytes) | **Fields:** 51 (9 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `f32` | **`m_lightsAtLocation`** | R/W | `AllocAndCopyOTD`, `CalcBounds`, `Deallocate`, ... |
| 0x004 | `f32` | **`m_roomCount`** | R/W | `AllocAndCopyOTD`, `CalcBounds`, `Draw`, ... |
| 0x008 | `f32` | **`m_roomCount_008`** | R/W | `AddWallInstanceToLevel`, `AllocAndCopyOTD`, `CalcBounds`, ... |
| 0x00C | `f32` | `m_field_00C` | R/W | `AllocAndCopyOTD`, `CalcBounds`, `ERLevel`, ... |
| 0x010 | `u32` | `m_field_010` | W | `AllocAndCopyOTD`, `ERLevel`, `InsertInDOFForegroundObjectList` |
| 0x014 | `f32` | `m_field_014` | R/W | `AllocAndCopyOTD`, `Draw`, `ERLevel`, ... |
| 0x018 | `s16` | `m_field_018` | R/W | `Draw`, `InsertLight`, `RemoveLight` |
| 0x01C | `u32` | `m_field_01C` | R | `Draw` |
| 0x024 | `u32` | `m_field_024` | R | `RegisterFloor` |
| 0x028 | `u32` | `m_field_028` | R/W | `AllocAndLoadLevel`, `Draw`, `InsertInDOFForegroundObjectList`, ... |
| 0x02C | `f32` | `m_field_02C` | W | `InsertInOrderTable` |
| 0x030 | `f32` | `m_field_030` | R/W | `Draw`, `InsertInOrderTable` |
| 0x034 | `f32` | `m_field_034` | R | `Draw` |
| 0x03C | `f32` | `m_field_03C` | R | `Draw` |
| 0x048 | `f32` | `m_field_048` | R | `Draw` |
| 0x04C | `u32` | **`m_lightsIntensityScale`** | R | `UpdateLightsIntensityScale` |
| 0x050 | `u32` | **`m_lightsIntensityScale_050`** | R | `UpdateLightsIntensityScale` |
| 0x060 | `f32` | `m_field_060` | R/W | `Draw` |
| 0x064 | `f32` | `m_field_064` | R/W | `Draw` |
| 0x068 | `f32` | `m_field_068` | R/W | `Draw` |
| 0x06C | `u32` | `m_field_06C` | R | `Draw` |
| 0x070 | `s16` | `m_field_070` | R | `Draw`, `DrawObjectShadowsInside`, `DrawObjectShadowsOutside`, ... |
| 0x074 | `u32` | `m_field_074` | R | `Draw` |
| 0x078 | `s16` | `m_field_078` | R | `Draw` |
| 0x07C | `u32` | `m_field_07C` | R | `Draw` |
| 0x080 | `s16` | `m_field_080` | R | `Draw` |
| 0x084 | `u32` | `m_field_084` | R | `Draw` |
| 0x08C | `f32` | `m_field_08C` | R | `Draw` |
| 0x090 | `f32` | `m_field_090` | R | `Draw` |
| 0x094 | `f32` | `m_field_094` | R/W | `Draw` |
| 0x098 | `u32` | `m_field_098` | W | `Draw` |
| 0x09C | `u32` | `m_field_09C` | W | `Draw` |
| 0x0A8 | `u32` | `m_field_0A8` | W | `Draw` |
| 0x0AC | `u32` | `m_field_0AC` | W | `Draw` |
| 0x0B0 | `u32` | `m_field_0B0` | W | `Draw` |
| 0x0B4 | `u32` | `m_field_0B4` | W | `Draw` |
| 0x0B8 | `u32` | `m_field_0B8` | W | `Draw` |
| 0x0BC | `u8[0x34]` | _(gap)_ | - | - |
| 0x0F0 | `u32` | `m_field_0F0` | R | `Draw`, `DrawObjectShadowsInside`, `DrawSimShadow` |
| 0x0F8 | `s16` | `m_field_0F8` | R | `Draw` |
| 0x0FC | `u32` | `m_field_0FC` | R | `Draw` |
| 0x100 | `u8[0x28]` | _(gap)_ | - | - |
| 0x128 | `f32` | `m_field_128` | R | `Draw`, `ObjectShouldBeOccluded` |
| 0x12C | `u32` | `m_field_12C` | R | `Draw` |
| 0x130 | `s16` | `m_field_130` | R | `Draw` |
| 0x134 | `u32` | `m_field_134` | R | `Draw` |
| 0x138 | `u8[0xA0]` | _(gap)_ | - | - |
| 0x1D8 | `s16` | `m_field_1D8` | R | `Draw` |
| 0x1DC | `u32` | `m_field_1DC` | R | `Draw` |
| 0x1E0 | `u8[0x5CCC]` | _(gap)_ | - | - |
| 0x5EAC | `u32` | `m_field_5EAC` | R | `Draw` |
| 0x5EB0 | `u8[0x19C]` | _(gap)_ | - | - |
| 0x604C | `u32` | **`m_sunLight`** | R | `GetSunLight` |
| 0x605C | `f32` | **`m_sunLight_605C`** | R | `Draw`, `DrawObjectShadowsOutside`, `GetSunLight` |
| 0x606C | `u32` | **`m_sunLight_606C`** | R | `GetSunLight` |
| 0x6070 | `u8[0x30]` | _(gap)_ | - | - |
| 0x60A0 | `u32` | **`m_objectShadowsInside`** | R | `DrawObjectShadowsInside` |

### `CRDTarget`

**Size:** >= 0xF8 (248 bytes) | **Fields:** 50 (20 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `u16` | **`m_localizable`** | R/W | `CRDTarget`, `EndCredits`, `GetLocalizable`, ... |
| 0x001 | `u8` | **`m_upForCreditsRender`** | W | `SetupForCreditsRender` |
| 0x002 | `u16` | **`m_upForCreditsRender_002`** | R/W | `ScrollingCallback`, `SetupForCreditsRender` |
| 0x004 | `f32` | **`m_variable`** | R/W | `CRDTarget`, `GetVariable`, `ScrollingCallback`, ... |
| 0x006 | `u8` | **`m_variable_006`** | W | `GetVariable` |
| 0x008 | `f32` | **`m_upForCreditsRender_008`** | R/W | `CRDTarget`, `ScrollingCallback`, `SetupForCreditsRender`, ... |
| 0x00C | `f32` | `m_field_00C` | R/W | `CRDTarget`, `ScrollingCallback`, `~CRDTarget` |
| 0x010 | `u32` | `m_field_010` | R/W | `CRDTarget`, `~CRDTarget` |
| 0x014 | `u32` | `m_field_014` | R/W | `CRDTarget`, `~CRDTarget` |
| 0x018 | `u32` | **`m_upForCreditsRender_018`** | R/W | `CRDTarget`, `SetupForCreditsRender`, `~CRDTarget` |
| 0x01C | `u32` | **`m_upForCreditsRender_01C`** | R/W | `CRDTarget`, `SetupForCreditsRender`, `~CRDTarget` |
| 0x020 | `u32` | `m_field_020` | R/W | `CRDTarget`, `~CRDTarget` |
| 0x024 | `f32` | **`m_upForCreditsRender_024`** | R/W | `CRDTarget`, `ScrollingCallback`, `SetupForCreditsRender`, ... |
| 0x028 | `u32` | `m_field_028` | W | `CRDTarget` |
| 0x02C | `u32` | `m_field_02C` | W | `ScrollingCallback` |
| 0x030 | `u32` | `m_field_030` | W | `ScrollingCallback` |
| 0x034 | `u32` | `m_field_034` | W | `ScrollingCallback` |
| 0x038 | `u32` | `m_field_038` | W | `CRDTarget` |
| 0x048 | `u32` | `m_field_048` | W | `CRDTarget` |
| 0x058 | `u32` | `m_field_058` | R/W | `CRDTarget`, `~CRDTarget` |
| 0x068 | `u32` | `m_field_068` | R/W | `CRDTarget`, `~CRDTarget` |
| 0x078 | `u32` | `m_field_078` | R/W | `CRDTarget` |
| 0x07C | `u32` | `m_field_07C` | R/W | `CRDTarget`, `~CRDTarget` |
| 0x080 | `u32` | `m_field_080` | W | `CRDTarget`, `~CRDTarget` |
| 0x084 | `u32` | **`m_variable_084`** | R/W | `CRDTarget`, `GetVariable`, `Update` |
| 0x088 | `u32` | `m_field_088` | R/W | `CRDTarget`, `HideCredits`, `ShowCredits`, ... |
| 0x08C | `u32` | **`m_variable_08C`** | R/W | `CRDTarget`, `HideCredits`, `SetVariable`, ... |
| 0x090 | `u32` | `m_field_090` | R/W | `CRDTarget`, `ShowCredits`, `Update` |
| 0x094 | `u32` | `m_field_094` | R/W | `ShowPhoto`, `Update` |
| 0x098 | `u32` | `m_field_098` | R/W | `ShowCredits`, `Update`, `~CRDTarget` |
| 0x09C | `u32` | **`m_variable_09C`** | R/W | `CRDTarget`, `EndCredits`, `GetVariable`, ... |
| 0x0A0 | `u32` | `m_field_0A0` | R/W | `CRDTarget`, `EndCredits`, `ScrollingCallback`, ... |
| 0x0A4 | `f32` | `m_field_0A4` | W | `CRDTarget`, `StartCredits` |
| 0x0A8 | `f32` | **`m_upForCreditsRender_0A8`** | R/W | `CRDTarget`, `ScrollingCallback`, `SetupForCreditsRender` |
| 0x0AC | `f32` | `m_field_0AC` | R/W | `CRDTarget`, `ScrollingCallback` |
| 0x0B0 | `u32` | `m_field_0B0` | R/W | `CRDTarget`, `InitCreditsTextFetch`, `ScrollingCallback` |
| 0x0B3 | `u8` | `m_field_0B3` | R | `ScrollingCallback` |
| 0x0B4 | `f32` | `m_field_0B4` | R/W | `CRDTarget`, `ScrollingCallback` |
| 0x0B8 | `u32` | `m_field_0B8` | R/W | `CRDTarget`, `EndCredits`, `InitCreditsTextFetch`, ... |
| 0x0BC | `u32` | `m_field_0BC` | R/W | `InitCreditsTextFetch`, `ScrollingCallback` |
| 0x0C0 | `u32` | `m_field_0C0` | R/W | `CRDTarget`, `ShowCredits`, `Update` |
| 0x0C4 | `u32` | **`m_upForCreditsRender_0C4`** | R/W | `CRDTarget`, `EndCredits`, `SetupForCreditsRender` |
| 0x0C8 | `u32` | **`m_upForCreditsRender_0C8`** | R/W | `CRDTarget`, `SetupForCreditsRender`, `~CRDTarget` |
| 0x0CC | `u32` | `m_field_0CC` | W | `CRDTarget` |
| 0x0D0 | `u32` | `m_field_0D0` | W | `CRDTarget` |
| 0x0E0 | `u16` | **`m_upForCreditsRender_0E0`** | W | `SetupForCreditsRender` |
| 0x0E2 | `u16` | **`m_upForCreditsRender_0E2`** | W | `SetupForCreditsRender` |
| 0x0EA | `u8` | **`m_upForCreditsRender_0EA`** | W | `SetupForCreditsRender` |
| 0x0F0 | `u32` | **`m_upForCreditsRender_0F0`** | R/W | `CRDTarget`, `EndCredits`, `SetupForCreditsRender` |
| 0x0F4 | `u32` | **`m_upForCreditsRender_0F4`** | R/W | `CRDTarget`, `EndCredits`, `SetupForCreditsRender` |

### `ENgcRenderStateCache`

**Size:** >= 0x9DC (2524 bytes) | **Fields:** 50 (0 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `f32` | `m_field_000` | R/W | `Apply`, `operator=` |
| 0x004 | `f32` | `m_field_004` | R/W | `Apply`, `operator=` |
| 0x008 | `f32` | `m_field_008` | R/W | `Apply`, `operator=` |
| 0x00C | `f32` | `m_field_00C` | R | `Apply` |
| 0x010 | `f32` | `m_field_010` | R | `Apply` |
| 0x014 | `f32` | `m_field_014` | R | `Apply` |
| 0x018 | `f32` | `m_field_018` | R | `Apply` |
| 0x01C | `f32` | `m_field_01C` | R | `Apply` |
| 0x020 | `f32` | `m_field_020` | R | `Apply` |
| 0x024 | `f32` | `m_field_024` | R | `Apply` |
| 0x028 | `f32` | `m_field_028` | R | `Apply` |
| 0x02C | `f32` | `m_field_02C` | R | `Apply` |
| 0x030 | `u32` | `m_field_030` | R | `Apply` |
| 0x038 | `f32` | `m_field_038` | R | `Apply` |
| 0x03C | `u32` | `m_field_03C` | R | `Apply` |
| 0x040 | `u32` | `m_field_040` | R | `Apply` |
| 0x044 | `u32` | `m_field_044` | R | `Apply` |
| 0x048 | `u32` | `m_field_048` | R | `Apply` |
| 0x04C | `u32` | `m_field_04C` | R | `Apply` |
| 0x050 | `u8[0x1C]` | _(gap)_ | - | - |
| 0x06C | `u8` | `m_field_06C` | R | `Apply` |
| 0x06D | `u8[0x33F]` | _(gap)_ | - | - |
| 0x3AC | `u8` | `m_field_3AC` | R/W | `Apply`, `RestoreState`, `SaveState`, ... |
| 0x3B0 | `u32` | `m_field_3B0` | R | `Apply` |
| 0x3B4 | `u8` | `m_field_3B4` | R | `Apply` |
| 0x3B8 | `u32` | `m_field_3B8` | R/W | `Apply`, `RestoreState`, `SaveState`, ... |
| 0x3BC | `u8` | `m_field_3BC` | R | `Apply` |
| 0x3C0 | `u32` | `m_field_3C0` | R | `Apply` |
| 0x3C4 | `u32` | `m_field_3C4` | R | `Apply` |
| 0x3C8 | `u8` | `m_field_3C8` | R | `Apply` |
| 0x3C9 | `u8` | `m_field_3C9` | R | `Apply` |
| 0x3CC | `u8` | `m_field_3CC` | R | `Apply` |
| 0x3D0 | `u8` | `m_field_3D0` | R | `Apply` |
| 0x3D1 | `u8[0x2F7]` | _(gap)_ | - | - |
| 0x6C8 | `u32` | `m_field_6C8` | R/W | `Apply`, `operator=` |
| 0x6CC | `u32` | `m_field_6CC` | R/W | `Apply`, `RestoreState`, `RestoreViewportState`, ... |
| 0x6D0 | `u32` | `m_field_6D0` | R/W | `Apply`, `operator=` |
| 0x6D2 | `u16` | `m_field_6D2` | R | `Apply` |
| 0x6D4 | `u32` | `m_field_6D4` | R/W | `Apply`, `operator=` |
| 0x6D8 | `u32` | `m_field_6D8` | R/W | `Apply`, `operator=` |
| 0x6DC | `u32` | `m_field_6DC` | R | `Apply` |
| 0x6E0 | `u32` | `m_field_6E0` | R | `Apply` |
| 0x6E4 | `u32` | `m_field_6E4` | R | `Apply` |
| 0x6E8 | `u32` | `m_field_6E8` | R/W | `Apply`, `RestoreState`, `SaveState`, ... |
| 0x6EC | `u32` | `m_field_6EC` | R/W | `Apply`, `RestoreState`, `SaveState`, ... |
| 0x6F0 | `u8` | `m_field_6F0` | R/W | `Apply`, `operator=` |
| 0x6F1 | `u8[0xAB]` | _(gap)_ | - | - |
| 0x79C | `u32` | `m_field_79C` | R | `Apply` |
| 0x7A0 | `u8[0x210]` | _(gap)_ | - | - |
| 0x9B0 | `f32` | `m_field_9B0` | R/W | `Apply`, `RestoreViewportState`, `SaveViewportState`, ... |
| 0x9B4 | `u8[0x14]` | _(gap)_ | - | - |
| 0x9C8 | `u32` | `m_field_9C8` | R/W | `Apply`, `RestoreViewportState`, `SaveViewportState`, ... |
| 0x9CC | `u32` | `m_field_9CC` | R | `Apply` |
| 0x9D0 | `u32` | `m_field_9D0` | R | `Apply` |
| 0x9D4 | `u32` | `m_field_9D4` | R | `Apply` |
| 0x9D8 | `u32` | `m_field_9D8` | R/W | `Apply`, `operator=` |

### `LoadGameTarget`

**Size:** >= 0x14C (332 bytes) | **Fields:** 50 (1 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `void**` | **`_vtable` (vtable pointer)** | R/W | `LoadGameTarget`, `~LoadGameTarget` |
| 0x004 | `u32` | `m_field_004` | R/W | `LoadGameTarget`, `~LoadGameTarget` |
| 0x008 | `u32` | `m_field_008` | R/W | `LoadGameTarget`, `~LoadGameTarget` |
| 0x00C | `u32` | `m_field_00C` | R/W | `LoadGameTarget`, `~LoadGameTarget` |
| 0x010 | `u32` | `m_field_010` | R/W | `LoadGameTarget`, `~LoadGameTarget` |
| 0x014 | `u32` | `m_field_014` | R/W | `LoadGameTarget`, `~LoadGameTarget` |
| 0x018 | `u32` | `m_field_018` | R/W | `LoadGameTarget`, `~LoadGameTarget` |
| 0x01C | `u32` | `m_field_01C` | R/W | `LoadGameTarget`, `~LoadGameTarget` |
| 0x020 | `u32` | `m_field_020` | R/W | `LoadGameTarget`, `~LoadGameTarget` |
| 0x024 | `u32` | `m_field_024` | R/W | `LoadGameTarget`, `~LoadGameTarget` |
| 0x028 | `u32` | `m_field_028` | W | `LoadGameTarget` |
| 0x038 | `u32` | `m_field_038` | W | `LoadGameTarget` |
| 0x048 | `u32` | `m_field_048` | W | `LoadGameTarget` |
| 0x058 | `u32` | `m_field_058` | R/W | `LoadGameTarget`, `~LoadGameTarget` |
| 0x068 | `u32` | `m_field_068` | R/W | `LoadGameTarget`, `~LoadGameTarget` |
| 0x078 | `u32` | `m_field_078` | W | `LoadGameTarget` |
| 0x07C | `u32` | `m_field_07C` | R/W | `LoadGameTarget`, `~LoadGameTarget` |
| 0x080 | `u32` | `m_field_080` | W | `LoadGameTarget`, `~LoadGameTarget` |
| 0x084 | `u32` | `m_field_084` | W | `LoadGameTarget`, `SpawnCardCorruptDialog`, `SpawnCardDamagedDialog`, ... |
| 0x088 | `u32` | `m_field_088` | W | `SpawnCardCorruptDialog`, `SpawnCardDamagedDialog`, `SpawnCheckingDialog`, ... |
| 0x08C | `u32` | `m_field_08C` | W | `SpawnCardCorruptDialog`, `SpawnCardDamagedDialog`, `SpawnCheckingDialog`, ... |
| 0x090 | `u32` | `m_field_090` | W | `SpawnCardCorruptDialog`, `SpawnCardDamagedDialog`, `SpawnCheckingDialog`, ... |
| 0x094 | `u32` | `m_field_094` | W | `SpawnCardCorruptDialog`, `SpawnCardDamagedDialog`, `SpawnCheckingDialog`, ... |
| 0x098 | `u32` | `m_field_098` | W | `SpawnCardCorruptDialog`, `SpawnCardDamagedDialog`, `SpawnCheckingDialog`, ... |
| 0x0A0 | `u32` | `m_field_0A0` | W | `SpawnCardCorruptDialog`, `SpawnCardDamagedDialog`, `SpawnCheckingDialog`, ... |
| 0x0A4 | `u8[0x1C]` | _(gap)_ | - | - |
| 0x0C0 | `u32` | `m_field_0C0` | W | `SpawnCardCorruptDialog`, `SpawnCardDamagedDialog`, `SpawnCheckingDialog`, ... |
| 0x0CC | `u16` | `m_field_0CC` | W | `SpawnCardCorruptDialog`, `SpawnCardDamagedDialog`, `SpawnCheckingDialog`, ... |
| 0x0CE | `u16` | `m_field_0CE` | W | `SpawnCardCorruptDialog`, `SpawnCardDamagedDialog`, `SpawnCheckingDialog`, ... |
| 0x0D0 | `u32` | `m_field_0D0` | W | `SpawnCardCorruptDialog`, `SpawnCardDamagedDialog`, `SpawnFormatCancelDialog`, ... |
| 0x0D4 | `u32` | `m_field_0D4` | W | `LoadGameTarget` |
| 0x0E4 | `u32` | `m_field_0E4` | W | `LoadGameTarget` |
| 0x0F4 | `u32` | `m_field_0F4` | W | `LoadGameTarget` |
| 0x104 | `u32` | `m_field_104` | W | `LoadGameTarget` |
| 0x108 | `u32` | `m_field_108` | W | `LoadGameTarget`, `~LoadGameTarget` |
| 0x10C | `u32` | `m_field_10C` | R/W | `BackgroundPerformLoad`, `LoadGameTarget`, `PerformMemoryCardChecks`, ... |
| 0x114 | `u32` | `m_field_114` | W | `LoadGameTarget`, `~LoadGameTarget` |
| 0x118 | `u32` | `m_field_118` | R/W | `BackgroundPerformLoad`, `LoadGameTarget`, `SpawnCardCorruptDialog`, ... |
| 0x11C | `u32` | `m_field_11C` | R/W | `LoadGameTarget`, `SelectionCallback`, `Update` |
| 0x120 | `u32` | `m_field_120` | R/W | `LoadGameTarget`, `Update` |
| 0x124 | `u32` | `m_field_124` | R/W | `LoadGameTarget`, `Update` |
| 0x128 | `u32` | `m_field_128` | R/W | `LoadGameTarget`, `PerformLoad`, `PerformMemoryCardChecks`, ... |
| 0x12B | `u8` | `m_field_12B` | R | `PerformLoad` |
| 0x12C | `u32` | `m_field_12C` | R/W | `BackgroundPerformLoad`, `LoadGameTarget`, `PerformMemoryCardChecks`, ... |
| 0x130 | `u32` | `m_field_130` | R/W | `BackgroundPerformLoad`, `LoadGameTarget`, `SelectionCallback`, ... |
| 0x134 | `u32` | `m_field_134` | R/W | `BackgroundPerformLoad`, `LoadGameTarget`, `Update` |
| 0x138 | `u32` | `m_field_138` | R/W | `LoadGameTarget`, `PerformLoad`, `PerformMemoryCardChecks`, ... |
| 0x13C | `u32` | `m_field_13C` | W | `LoadGameTarget` |
| 0x140 | `u32` | `m_field_140` | R/W | `LoadGameTarget`, `SelectionCallback`, `Update` |
| 0x144 | `u32` | `m_field_144` | R/W | `BackgroundPerformLoad`, `LoadGameTarget`, `PerformLoad` |
| 0x148 | `u32` | `m_field_148` | R/W | `BackgroundPerformLoad` |

### `NewControlParms`

**Size:** >= 0xC4 (196 bytes) | **Fields:** 49 (1 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `void**` | **`_vtable` (vtable pointer)** | W | `NewControlParms` |
| 0x004 | `f32` | `m_field_004` | W | `NewControlParms` |
| 0x008 | `f32` | `m_field_008` | W | `NewControlParms` |
| 0x00C | `f32` | `m_field_00C` | W | `NewControlParms` |
| 0x010 | `f32` | `m_field_010` | W | `NewControlParms` |
| 0x014 | `f32` | `m_field_014` | W | `NewControlParms` |
| 0x018 | `f32` | `m_field_018` | W | `NewControlParms` |
| 0x01C | `f32` | `m_field_01C` | W | `NewControlParms` |
| 0x020 | `f32` | `m_field_020` | W | `NewControlParms` |
| 0x024 | `f32` | `m_field_024` | W | `NewControlParms` |
| 0x028 | `u32` | `m_field_028` | W | `NewControlParms` |
| 0x02C | `u32` | `m_field_02C` | W | `NewControlParms` |
| 0x030 | `u32` | `m_field_030` | W | `NewControlParms` |
| 0x034 | `f32` | `m_field_034` | W | `NewControlParms` |
| 0x038 | `f32` | `m_field_038` | W | `NewControlParms` |
| 0x03C | `f32` | `m_field_03C` | W | `NewControlParms` |
| 0x040 | `u32` | `m_field_040` | W | `NewControlParms` |
| 0x044 | `f32` | `m_field_044` | W | `NewControlParms` |
| 0x048 | `f32` | `m_field_048` | W | `NewControlParms` |
| 0x04C | `f32` | `m_field_04C` | W | `NewControlParms` |
| 0x050 | `u32` | `m_field_050` | W | `NewControlParms` |
| 0x054 | `f32` | `m_field_054` | W | `NewControlParms` |
| 0x058 | `u32` | `m_field_058` | W | `NewControlParms` |
| 0x05C | `u32` | `m_field_05C` | W | `NewControlParms` |
| 0x060 | `f32` | `m_field_060` | W | `NewControlParms` |
| 0x064 | `f32` | `m_field_064` | W | `NewControlParms` |
| 0x068 | `u32` | `m_field_068` | W | `NewControlParms` |
| 0x06C | `f32` | `m_field_06C` | W | `NewControlParms` |
| 0x070 | `f32` | `m_field_070` | W | `NewControlParms` |
| 0x074 | `f32` | `m_field_074` | W | `NewControlParms` |
| 0x078 | `u32` | `m_field_078` | W | `NewControlParms` |
| 0x07C | `f32` | `m_field_07C` | W | `NewControlParms` |
| 0x080 | `f32` | `m_field_080` | W | `NewControlParms` |
| 0x084 | `f32` | `m_field_084` | W | `NewControlParms` |
| 0x088 | `f32` | `m_field_088` | W | `NewControlParms` |
| 0x08C | `f32` | `m_field_08C` | W | `NewControlParms` |
| 0x090 | `f32` | `m_field_090` | W | `NewControlParms` |
| 0x094 | `f32` | `m_field_094` | W | `NewControlParms` |
| 0x098 | `f32` | `m_field_098` | W | `NewControlParms` |
| 0x09C | `f32` | `m_field_09C` | W | `NewControlParms` |
| 0x0A0 | `u32` | `m_field_0A0` | W | `NewControlParms` |
| 0x0A4 | `u32` | `m_field_0A4` | W | `NewControlParms` |
| 0x0A8 | `f32` | `m_field_0A8` | W | `NewControlParms` |
| 0x0AC | `f32` | `m_field_0AC` | W | `NewControlParms` |
| 0x0B0 | `f32` | `m_field_0B0` | W | `NewControlParms` |
| 0x0B4 | `f32` | `m_field_0B4` | W | `NewControlParms` |
| 0x0B8 | `f32` | `m_field_0B8` | W | `NewControlParms` |
| 0x0BC | `f32` | `m_field_0BC` | W | `NewControlParms` |
| 0x0C0 | `u32` | `m_field_0C0` | W | `NewControlParms` |

### `CASSelectionTarget`

**Size:** >= 0x5DB (1499 bytes) | **Fields:** 48 (10 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `u8` | **`m_variable`** | R/W | `CASSelectionTarget`, `ClearRecentlyUnlockedBitFlag`, `GetVariable`, ... |
| 0x002 | `u8` | **`m_variable_002`** | W | `GetVariable` |
| 0x004 | `u32` | `m_field_004` | R/W | `CASSelectionTarget`, `LoadGridTextures`, `~CASSelectionTarget` |
| 0x007 | `u8` | **`m_localizable`** | W | `GetLocalizable` |
| 0x008 | `u32` | `m_field_008` | R/W | `CASSelectionTarget`, `~CASSelectionTarget` |
| 0x00C | `u32` | `m_field_00C` | R/W | `CASSelectionTarget`, `~CASSelectionTarget` |
| 0x010 | `u32` | `m_field_010` | R/W | `CASSelectionTarget`, `~CASSelectionTarget` |
| 0x014 | `u32` | `m_field_014` | R/W | `CASSelectionTarget`, `~CASSelectionTarget` |
| 0x018 | `u32` | `m_field_018` | R/W | `CASSelectionTarget`, `~CASSelectionTarget` |
| 0x01C | `u32` | **`m_titleShaderAccordingToCurUIFocus`** | R/W | `CASSelectionTarget`, `InitScreen`, `SetTitleShaderAccordingToCurUIFocus`, ... |
| 0x020 | `u32` | `m_field_020` | R/W | `CASSelectionTarget`, `~CASSelectionTarget` |
| 0x024 | `u32` | `m_field_024` | R/W | `CASSelectionTarget`, `~CASSelectionTarget` |
| 0x028 | `u32` | `m_field_028` | W | `CASSelectionTarget` |
| 0x038 | `u32` | `m_field_038` | W | `CASSelectionTarget` |
| 0x048 | `u32` | `m_field_048` | W | `CASSelectionTarget` |
| 0x058 | `u32` | `m_field_058` | R/W | `CASSelectionTarget`, `~CASSelectionTarget` |
| 0x068 | `u32` | `m_field_068` | R/W | `CASSelectionTarget`, `~CASSelectionTarget` |
| 0x078 | `u32` | `m_field_078` | W | `CASSelectionTarget` |
| 0x07C | `u32` | **`m_titleShaderAccordingToCurUIFocus_07C`** | R/W | `CASSelectionTarget`, `SetTitleShaderAccordingToCurUIFocus`, `~CASSelectionTarget` |
| 0x080 | `u32` | `m_field_080` | W | `CASSelectionTarget`, `~CASSelectionTarget` |
| 0x084 | `u32` | **`m_variable_084`** | R/W | `CASSelectionTarget`, `ClearRecentlyUnlockedBitFlag`, `InitScreen`, ... |
| 0x088 | `u32` | `m_field_088` | W | `CASSelectionTarget`, `~CASSelectionTarget` |
| 0x08C | `u32` | **`m_lockStateString`** | R/W | `CASSelectionTarget`, `ClearRecentlyUnlockedBitFlag`, `GetLocalizable`, ... |
| 0x090 | `u32` | **`m_localizable_090`** | R/W | `CASSelectionTarget`, `GetLocalizable`, `SetVariable` |
| 0x094 | `u8[0x5C]` | _(gap)_ | - | - |
| 0x0F0 | `u32` | `m_field_0F0` | R | `ClearTextures`, `LoadGridTextures`, `ShiftShaderTexturesLeft`, ... |
| 0x0F4 | `u8[0x450]` | _(gap)_ | - | - |
| 0x544 | `u32` | `m_field_544` | R/W | `CASSelectionTarget`, `InitScreen`, `ScrollPageRight`, ... |
| 0x548 | `u32` | **`m_upInitialSelectionPage`** | R/W | `CASSelectionTarget`, `InitScreen`, `ScrollPageLeft`, ... |
| 0x54C | `u32` | `m_field_54C` | R/W | `CASSelectionTarget`, `ClearRecentlyUnlockedBitFlag`, `ConvertCurUIFocusToChangeEvent`, ... |
| 0x550 | `u32` | `m_field_550` | W | `CASSelectionTarget`, `InitScreen` |
| 0x554 | `u8[0x40]` | _(gap)_ | - | - |
| 0x594 | `u32` | `m_field_594` | W | `CreateSelectionShaders` |
| 0x598 | `u32` | `m_field_598` | W | `CreateSelectionShaders` |
| 0x59C | `u32` | `m_field_59C` | W | `CreateSelectionShaders` |
| 0x5A0 | `u32` | `m_field_5A0` | W | `CreateSelectionShaders` |
| 0x5A4 | `u32` | `m_field_5A4` | W | `CreateSelectionShaders` |
| 0x5A8 | `u32` | `m_field_5A8` | W | `CreateSelectionShaders` |
| 0x5AC | `u32` | `m_field_5AC` | W | `CreateSelectionShaders` |
| 0x5B0 | `u32` | `m_field_5B0` | W | `CreateSelectionShaders` |
| 0x5B4 | `u32` | `m_field_5B4` | W | `CreateSelectionShaders` |
| 0x5B8 | `u32` | `m_field_5B8` | W | `CreateSelectionShaders` |
| 0x5BC | `u32` | `m_field_5BC` | W | `CreateSelectionShaders` |
| 0x5C0 | `u32` | `m_field_5C0` | W | `CreateSelectionShaders` |
| 0x5C4 | `u32` | `m_field_5C4` | W | `CreateSelectionShaders` |
| 0x5C8 | `u32` | `m_field_5C8` | W | `CreateSelectionShaders` |
| 0x5CC | `u32` | `m_field_5CC` | W | `CreateSelectionShaders` |
| 0x5D0 | `u32` | `m_field_5D0` | W | `CreateSelectionShaders` |
| 0x5D4 | `u32` | `m_field_5D4` | R/W | `CASSelectionTarget`, `ClearTextures`, `CreateSelectionShaders`, ... |
| 0x5D8 | `u16` | `m_field_5D8` | W | `InitScreen` |
| 0x5DA | `u8` | **`m_variable_5DA`** | W | `InitScreen`, `SetVariable` |

### `HUDTarget`

**Size:** >= 0x8B8 (2232 bytes) | **Fields:** 48 (23 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `u16` | **`m_playerLocalizable`** | R/W | `ApplyMotiveCurveArray`, `GetNextRepUnlockValue`, `GetPlayerLocalizable`, ... |
| 0x004 | `u16` | **`m_playerVariable`** | R/W | `ApplyMotiveCurveArray`, `GetPlayerVariable`, `HUDTarget`, ... |
| 0x006 | `u8` | **`m_playerVariable_006`** | W | `GetPlayerVariable` |
| 0x008 | `u16` | **`m_playerVariable_008`** | R/W | `GetPlayerVariable`, `HUDTarget`, `~HUDTarget` |
| 0x00C | `u32` | `m_field_00C` | R/W | `HUDTarget`, `~HUDTarget` |
| 0x010 | `u32` | `m_field_010` | R/W | `HUDTarget`, `~HUDTarget` |
| 0x014 | `u32` | `m_field_014` | R/W | `HUDTarget`, `~HUDTarget` |
| 0x018 | `u32` | `m_field_018` | R/W | `HUDTarget`, `~HUDTarget` |
| 0x01C | `u32` | `m_field_01C` | R/W | `HUDTarget`, `InstallHUDIcons`, `~HUDTarget` |
| 0x020 | `u32` | `m_field_020` | R/W | `HUDTarget`, `~HUDTarget` |
| 0x024 | `u32` | `m_field_024` | R/W | `HUDTarget`, `~HUDTarget` |
| 0x028 | `u32` | `m_field_028` | W | `HUDTarget` |
| 0x038 | `u32` | `m_field_038` | W | `HUDTarget` |
| 0x048 | `u32` | `m_field_048` | W | `HUDTarget` |
| 0x058 | `u32` | `m_field_058` | R/W | `HUDTarget`, `~HUDTarget` |
| 0x068 | `u32` | `m_field_068` | R/W | `HUDTarget`, `~HUDTarget` |
| 0x078 | `u32` | `m_field_078` | W | `HUDTarget` |
| 0x07C | `u32` | `m_field_07C` | R/W | `HUDTarget`, `InstallHUDIcons`, `~HUDTarget` |
| 0x080 | `u32` | `m_field_080` | W | `HUDTarget`, `~HUDTarget` |
| 0x084 | `u8` | `m_field_084` | R/W | `HUDTarget`, `Update` |
| 0x085 | `u8[0x15]` | _(gap)_ | - | - |
| 0x09A | `u16` | `m_field_09A` | R/W | `CalculateJobScore`, `ResetJobHudProperties` |
| 0x09C | `u16` | `m_field_09C` | R/W | `CalculateJobScore`, `ResetJobHudProperties` |
| 0x0A0 | `u32` | **`m_hUDData`** | R/W | `ApplyMotiveCurveArray`, `CalculateJobScore`, `GetHUDData`, ... |
| 0x0A4 | `u8[0x24]` | _(gap)_ | - | - |
| 0x0C8 | `u16` | **`m_playerLocalizable_0C8`** | R/W | `GetPlayerLocalizable`, `GetPlayerVariable`, `HUDTarget`, ... |
| 0x0CA | `u16` | **`m_playerVariable_0CA`** | R/W | `ApplyMotiveCurveArray`, `GetPlayerVariable`, `HUDTarget`, ... |
| 0x0CC | `f32` | **`m_playerVariable_0CC`** | W | `HUDTarget`, `SetPlayerVariable` |
| 0x0D0 | `u32` | **`m_playerVariable_0D0`** | R/W | `GetPlayerLocalizable`, `GetPlayerVariable`, `HUDTarget` |
| 0x0D4 | `u32` | `m_field_0D4` | W | `HUDTarget` |
| 0x0D8 | `u8` | `m_field_0D8` | W | `HUDTarget` |
| 0x0DC | `u32` | **`m_playerVariable_0DC`** | W | `HUDTarget`, `SetPlayerVariable` |
| 0x0E0 | `u32` | `m_field_0E0` | W | `HUDTarget` |
| 0x0E4 | `u32` | **`m_playerVariable_0E4`** | R/W | `HUDTarget`, `HideHUD`, `SetPlayerVariable`, ... |
| 0x0E8 | `u8` | **`m_playerVariable_0E8`** | R/W | `GotoCAS`, `HUDTarget`, `HideHUD`, ... |
| 0x0E9 | `u8` | **`m_playerVariable_0E9`** | W | `HUDTarget`, `SetPlayerVariable` |
| 0x0EA | `u8` | **`m_playerVariable_0EA`** | W | `HUDTarget`, `SetPlayerVariable` |
| 0x0EC | `u32` | `m_field_0EC` | R/W | `HUDTarget`, `HideHUD`, `ShowHUD`, ... |
| 0x0F0 | `u32` | **`m_tutorialLocks`** | W | `HUDTarget`, `UpdateTutorialLocks` |
| 0x0F4 | `u8` | **`m_speedControls`** | R/W | `HUDTarget`, `Update`, `UpdateSpeedControls` |
| 0x0F5 | `u8` | **`m_speedControls_0F5`** | R/W | `HUDTarget`, `Update`, `UpdateSpeedControls` |
| 0x0F6 | `u8` | **`m_speedControls_0F6`** | R/W | `HUDTarget`, `Update`, `UpdateSpeedControls` |
| 0x0F7 | `u8` | **`m_speedControls_0F7`** | R/W | `HUDTarget`, `Update`, `UpdateSpeedControls` |
| 0x0F8 | `u32` | `m_field_0F8` | R/W | `AttachControllers`, `HUDTarget`, `ReleaseControllers`, ... |
| 0x0FC | `u32` | `m_field_0FC` | R/W | `AttachControllers`, `HUDTarget`, `ReleaseControllers`, ... |
| 0x100 | `u8` | **`m_playerVariable_100`** | R/W | `GetPlayerVariable`, `GotoCAS`, `HUDTarget`, ... |
| 0x104 | `u32` | **`m_hUDData_104`** | R/W | `CalculateJobScore`, `GetHUDData`, `GetPlayerVariable`, ... |
| 0x108 | `u8[0x50]` | _(gap)_ | - | - |
| 0x158 | `u32` | **`m_playerLocalizable_158`** | R | `GetPlayerLocalizable` |
| 0x15C | `u8[0x308]` | _(gap)_ | - | - |
| 0x464 | `u32` | **`m_playerLocalizable_464`** | R | `GetPlayerLocalizable` |
| 0x468 | `u8[0x44C]` | _(gap)_ | - | - |
| 0x8B4 | `u32` | `m_field_8B4` | R/W | `HUDTarget`, `~HUDTarget` |

### `FAMTarget`

**Size:** >= 0x450 (1104 bytes) | **Fields:** 47 (24 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `u16` | **`m_nameForFamilyInLotSelect`** | R/W | `FAMTarget`, `GetLocalizable`, `GetMoneyForFamily`, ... |
| 0x004 | `u16` | **`m_variable`** | R/W | `FAMTarget`, `GetVariable`, `OnXKeyPressed`, ... |
| 0x006 | `u8` | **`m_variable_006`** | W | `GetVariable` |
| 0x008 | `u32` | `m_field_008` | R/W | `FAMTarget`, `GoUpMenuTree`, `OnXKeyPressed`, ... |
| 0x00C | `u32` | **`m_nameForFamilyInLotSelect_00C`** | R/W | `FAMTarget`, `GetNameForFamily`, `GetNameForFamilyInLotSelect`, ... |
| 0x010 | `u32` | `m_field_010` | R/W | `FAMTarget`, `GoUpMenuTree`, `UpdateMenuState`, ... |
| 0x014 | `u32` | `m_field_014` | R/W | `FAMTarget`, `GoUpMenuTree`, `~FAMTarget` |
| 0x018 | `u32` | **`m_menuState`** | R/W | `FAMTarget`, `UpdateMenuState`, `~FAMTarget` |
| 0x01C | `u32` | `m_field_01C` | R/W | `FAMTarget`, `UpdateFamilySelectShaders`, `UpdateLotSelectShaders`, ... |
| 0x020 | `u32` | `m_field_020` | R/W | `FAMTarget`, `~FAMTarget` |
| 0x024 | `u32` | `m_field_024` | R/W | `FAMTarget`, `~FAMTarget` |
| 0x028 | `u32` | `m_field_028` | W | `FAMTarget` |
| 0x038 | `u32` | `m_field_038` | W | `FAMTarget` |
| 0x048 | `u32` | `m_field_048` | W | `FAMTarget` |
| 0x058 | `u32` | `m_field_058` | R/W | `FAMTarget`, `~FAMTarget` |
| 0x068 | `u32` | `m_field_068` | R/W | `FAMTarget`, `~FAMTarget` |
| 0x070 | `u32` | **`m_moneyForLot`** | W | `GetMoneyForLot` |
| 0x078 | `u32` | `m_field_078` | W | `FAMTarget` |
| 0x07C | `u32` | `m_field_07C` | R/W | `FAMTarget`, `UpdateFamilySelectShaders`, `UpdateLotSelectShaders`, ... |
| 0x080 | `u32` | `m_field_080` | W | `FAMTarget`, `~FAMTarget` |
| 0x084 | `u32` | **`m_variable_084`** | W | `FAMTarget`, `GetVariable` |
| 0x088 | `u32` | **`m_variable_088`** | R/W | `FAMTarget`, `GetVariable`, `OnCancelKeyPressed`, ... |
| 0x08C | `u32` | **`m_menuState_08C`** | R/W | `FAMTarget`, `UpdateMenuState` |
| 0x090 | `u32` | **`m_menuState_090`** | R/W | `FAMTarget`, `GoUpMenuTree`, `UpdateMenuState` |
| 0x0A0 | `u32` | **`m_menuState_0A0`** | R/W | `FAMTarget`, `GoUpMenuTree`, `UpdateMenuState` |
| 0x0A4 | `u8[0x1C]` | _(gap)_ | - | - |
| 0x0C0 | `u32` | **`m_menuState_0C0`** | R/W | `FAMTarget`, `GoUpMenuTree`, `UpdateMenuState` |
| 0x0C4 | `u32` | `m_field_0C4` | W | `FAMTarget`, `OnCancelKeyPressed`, `OnXKeyPressed` |
| 0x0D0 | `u32` | `m_field_0D0` | W | `OnCancelKeyPressed`, `OnXKeyPressed` |
| 0x0D8 | `u32` | `m_field_0D8` | W | `OnCancelKeyPressed`, `OnXKeyPressed` |
| 0x0E4 | `u32` | `m_field_0E4` | W | `OnCancelKeyPressed`, `OnXKeyPressed` |
| 0x0E8 | `u8[0x2C]` | _(gap)_ | - | - |
| 0x114 | `u32` | `m_field_114` | W | `FAMTarget`, `OnCancelKeyPressed`, `OnXKeyPressed` |
| 0x124 | `u32` | `m_field_124` | W | `FAMTarget`, `OnCancelKeyPressed`, `OnXKeyPressed` |
| 0x134 | `u32` | `m_field_134` | W | `FAMTarget`, `OnCancelKeyPressed`, `OnXKeyPressed` |
| 0x138 | `s16` | `m_field_138` | R | `OnXKeyPressed` |
| 0x13A | `u8[0x12]` | _(gap)_ | - | - |
| 0x14C | `u32` | **`m_nameForFamilyInLotSelect_14C`** | R/W | `EvictFamily`, `FAMTarget`, `GetLocalizable`, ... |
| 0x150 | `u32` | **`m_currentChoice`** | R/W | `FAMTarget`, `OnDialogSelection`, `OnDownKeyPressed`, ... |
| 0x154 | `u32` | **`m_numberOfChoicesInState`** | R/W | `FAMTarget`, `GetNumberOfChoicesInState` |
| 0x158 | `u32` | **`m_numberOfChoicesInState_158`** | R/W | `FAMTarget`, `GetNumberOfChoicesInState`, `OnDownKeyPressed`, ... |
| 0x15C | `u32` | **`m_currentChoice_15C`** | R/W | `FAMTarget`, `OnDialogSelection`, `OnDownKeyPressed`, ... |
| 0x160 | `u32` | **`m_currentChoice_160`** | R/W | `FAMTarget`, `OnDialogSelection`, `OnDownKeyPressed`, ... |
| 0x164 | `u32` | **`m_currentChoice_164`** | R/W | `FAMTarget`, `OnDialogSelection`, `OnDownKeyPressed`, ... |
| 0x168 | `u32` | `m_field_168` | R/W | `FAMTarget`, `OnDownKeyPressed`, `OnUpKeyPressed` |
| 0x16C | `u32` | **`m_localizable`** | R/W | `FAMTarget`, `GetLocalizable`, `OnReturnFromCreateAFamily`, ... |
| 0x170 | `u8[0x20]` | _(gap)_ | - | - |
| 0x190 | `s16` | **`m_moneyForLot_190`** | R | `GetMoneyForLot` |
| 0x194 | `u32` | **`m_moneyForLot_194`** | R | `GetMoneyForLot` |
| 0x198 | `u8[0x2B0]` | _(gap)_ | - | - |
| 0x448 | `u32` | **`m_menuState_448`** | W | `UpdateMenuState` |
| 0x44C | `u32` | **`m_menuState_44C`** | W | `UpdateMenuState` |

### `Neighbor`

**Size:** >= 0x1B8 (440 bytes) | **Fields:** 47 (5 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `void**` | **`_vtable` (vtable pointer)** | R/W | `AdjustRelationship`, `CalculateRelationshipLevel`, `CopyRelationships`, ... |
| 0x002 | `u8` | `m_field_002` | R | `ForceNewTree` |
| 0x004 | `s16` | `m_field_004` | R/W | `CopyRelationships`, `FindDuplicateBookmark`, `ForceNewTree`, ... |
| 0x008 | `u16` | **`m_family`** | R/W | `DoStream`, `ForceNewTree`, `GetFamily`, ... |
| 0x00B | `u8` | `m_field_00B` | R | `ForceNewTree` |
| 0x00C | `f32` | **`m_bIsCharacter`** | R/W | `CalculateWantFearAd`, `DoStream`, `IsCharacter`, ... |
| 0x010 | `u32` | **`m_relationshipById_010`** | R/W | `AdjustRelationship`, `DoStream`, `GetRelationshipById`, ... |
| 0x014 | `u32` | `m_field_014` | W | `operator=` |
| 0x018 | `u32` | **`m_uIifNeeded`** | R | `CalculateWantFearAd`, `SpawnWantFearDialog`, `UpdateUIifNeeded` |
| 0x01C | `u16` | `m_field_01C` | R/W | `Neighbor`, `RecalculateRelationshipData` |
| 0x01E | `u16` | `m_field_01E` | W | `Neighbor`, `RecalculateRelationshipData` |
| 0x020 | `u16` | `m_field_020` | R/W | `Neighbor`, `RecalculateRelationshipData` |
| 0x022 | `u16` | `m_field_022` | W | `Neighbor`, `RecalculateRelationshipData` |
| 0x024 | `u32` | `m_field_024` | R/W | `Neighbor`, `RecalculateRelationshipData`, `operator=` |
| 0x028 | `u8[0x30]` | _(gap)_ | - | - |
| 0x058 | `s16` | `m_field_058` | R | `RecalculateRelationshipData` |
| 0x05A | `u8[0x1A]` | _(gap)_ | - | - |
| 0x074 | `u16` | `m_field_074` | R/W | `LoadFromCharacter`, `SaveToCharacter` |
| 0x076 | `u16` | `m_field_076` | R/W | `LoadFromCharacter`, `SaveToCharacter` |
| 0x078 | `u16` | `m_field_078` | R/W | `LoadFromCharacter`, `SaveToCharacter` |
| 0x07A | `u16` | `m_field_07A` | R/W | `LoadFromCharacter`, `SaveToCharacter` |
| 0x07C | `u16` | `m_field_07C` | R/W | `LoadFromCharacter`, `SaveToCharacter` |
| 0x07E | `u16` | `m_field_07E` | R/W | `LoadFromCharacter`, `SaveToCharacter` |
| 0x082 | `s16` | `m_field_082` | R/W | `InitDefaultValues`, `LoadFromCharacter`, `SaveToCharacter` |
| 0x084 | `s16` | `m_field_084` | R/W | `InitDefaultValues`, `LoadFromCharacter`, `SaveToCharacter` |
| 0x086 | `s16` | `m_field_086` | R/W | `InitDefaultValues`, `LoadFromCharacter`, `SaveToCharacter` |
| 0x088 | `s16` | `m_field_088` | R/W | `InitDefaultValues`, `LoadFromCharacter`, `SaveToCharacter` |
| 0x08A | `s16` | `m_field_08A` | R/W | `InitDefaultValues`, `LoadFromCharacter`, `SaveToCharacter` |
| 0x08C | `s16` | `m_field_08C` | R/W | `InitDefaultValues`, `LoadFromCharacter`, `SaveToCharacter` |
| 0x08E | `s16` | `m_field_08E` | R/W | `InitDefaultValues`, `LoadFromCharacter`, `SaveToCharacter` |
| 0x090 | `s16` | `m_field_090` | R/W | `InitDefaultValues`, `LoadFromCharacter`, `SaveToCharacter` |
| 0x092 | `s16` | `m_field_092` | R/W | `InitDefaultValues`, `LoadFromCharacter`, `SaveToCharacter` |
| 0x094 | `s16` | `m_field_094` | R/W | `InitDefaultValues`, `LoadFromCharacter`, `SaveToCharacter` |
| 0x098 | `u16` | `m_field_098` | W | `LoadFromCharacter` |
| 0x099 | `u8` | `m_field_099` | R | `SaveToCharacter` |
| 0x0A0 | `s16` | `m_field_0A0` | R/W | `InitDefaultValues`, `LoadFromCharacter`, `SaveToCharacter` |
| 0x0A2 | `u8[0x1A]` | _(gap)_ | - | - |
| 0x0BC | `u32` | `m_field_0BC` | R | `RecalculateRelationshipData` |
| 0x0C0 | `u32` | `m_field_0C0` | R | `RecalculateRelationshipData` |
| 0x0C4 | `u8[0x1C]` | _(gap)_ | - | - |
| 0x0E0 | `s16` | `m_field_0E0` | R/W | `InitDefaultValues`, `LoadFromCharacter`, `SaveToCharacter` |
| 0x0E2 | `s16` | `m_field_0E2` | R/W | `InitDefaultValues`, `LoadFromCharacter`, `SaveToCharacter` |
| 0x0E4 | `s16` | `m_field_0E4` | R/W | `LoadFromCharacter`, `SaveToCharacter` |
| 0x0EE | `s16` | `m_field_0EE` | R/W | `InitDefaultValues`, `LoadFromCharacter`, `SaveToCharacter` |
| 0x0FC | `u16` | `m_field_0FC` | W | `LoadFromCharacter` |
| 0x104 | `u16` | `m_field_104` | R/W | `InitDefaultValues` |
| 0x110 | `f32` | `m_field_110` | W | `InitDefaultValues` |
| 0x11C | `f32` | `m_field_11C` | R | `CalculateWantFearAd` |
| 0x120 | `u8[0x30]` | _(gap)_ | - | - |
| 0x150 | `f32` | `m_field_150` | W | `InitDefaultValues` |
| 0x154 | `u8[0x40]` | _(gap)_ | - | - |
| 0x194 | `u32` | `m_field_194` | R/W | `AdvanceBookmark`, `DoStream`, `FindBookmarkToReplace`, ... |
| 0x198 | `u8[0x1C]` | _(gap)_ | - | - |
| 0x1B4 | `u32` | `m_field_1B4` | W | `DoStream`, `Neighbor`, `ResetAllWantsAndFears`, ... |

### `XRoute`

**Size:** >= 0x4A8 (1192 bytes) | **Fields:** 47 (4 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `void**` | **`_vtable` (vtable pointer)** | R/W | `AddGoal`, `BuildGoalList`, `ClearCurrentGoal`, ... |
| 0x004 | `u32` | **`m_maxScore_004`** | R/W | `AddGoal`, `BuildGoalList`, `ClearCurrentGoal`, ... |
| 0x008 | `u32` | `m_field_008` | R/W | `AddGoal`, `ConstructGoals`, `FindPath`, ... |
| 0x00C | `s16` | `m_field_00C` | R/W | `AddGoal`, `ConstructGoals`, `FindPath`, ... |
| 0x010 | `u32` | `m_field_010` | R/W | `Construct`, `ConstructGoals`, `FindPath`, ... |
| 0x014 | `u32` | `m_field_014` | W | `ConstructGoals` |
| 0x018 | `s16` | `m_field_018` | R/W | `ConstructGoals`, `FindPath` |
| 0x01C | `u32` | `m_field_01C` | R | `EvalTileForGoal`, `FindPath` |
| 0x020 | `u8[0x14]` | _(gap)_ | - | - |
| 0x034 | `u32` | `m_field_034` | R | `FindPath` |
| 0x038 | `u8[0x14]` | _(gap)_ | - | - |
| 0x04C | `u32` | **`m_bIsPersonSittingOnChairGoal`** | R/W | `ChooseStartingPoint`, `Construct`, `ConstructGoals`, ... |
| 0x050 | `u32` | `m_field_050` | R/W | `BuildGoalList`, `ChooseStartingPoint`, `Construct`, ... |
| 0x054 | `u32` | `m_field_054` | R/W | `ClearCurrentGoal`, `Construct`, `XRoute` |
| 0x058 | `u32` | **`m_maxScore_058`** | R/W | `AddGoal`, `ClearCurrentGoal`, `Construct`, ... |
| 0x05C | `u32` | `m_field_05C` | W | `Construct`, `XRoute` |
| 0x060 | `u32` | `m_field_060` | W | `Construct`, `XRoute` |
| 0x064 | `u32` | `m_field_064` | W | `XRoute` |
| 0x068 | `u32` | `m_field_068` | W | `XRoute` |
| 0x06C | `u32` | `m_field_06C` | W | `Construct`, `XRoute` |
| 0x070 | `u32` | `m_field_070` | R/W | `ChooseStartingPoint`, `ConstructGoals`, `FindPath`, ... |
| 0x074 | `u32` | `m_field_074` | R/W | `ChooseStartingPoint`, `ConstructGoals`, `FindPath`, ... |
| 0x078 | `u32` | `m_field_078` | W | `ChooseStartingPoint`, `XRoute` |
| 0x07C | `u32` | `m_field_07C` | W | `Construct`, `XRoute` |
| 0x080 | `u32` | `m_field_080` | R/W | `Construct`, `EvalTileForGoal`, `ShouldIgnore`, ... |
| 0x084 | `s16` | `m_field_084` | R/W | `ChooseStartingPoint`, `Construct`, `ConstructGoals`, ... |
| 0x088 | `u32` | `m_field_088` | W | `Construct`, `XRoute` |
| 0x08C | `u32` | `m_field_08C` | R/W | `Construct`, `ConstructGoals`, `FindPath`, ... |
| 0x090 | `u16` | `m_field_090` | W | `Construct`, `ConstructGoals`, `EvalTileForGoal`, ... |
| 0x094 | `u32` | `m_field_094` | R/W | `Construct`, `ShouldIgnore`, `XRoute` |
| 0x098 | `s16` | `m_field_098` | R/W | `FindPath`, `XRoute` |
| 0x09C | `s16` | `m_field_09C` | R/W | `BuildGoalList`, `Construct`, `FindPath`, ... |
| 0x0A0 | `u32` | `m_field_0A0` | R/W | `BuildGoalList`, `Construct`, `ConstructGoals`, ... |
| 0x0A4 | `u8[0x174]` | _(gap)_ | - | - |
| 0x218 | `s16` | `m_field_218` | R | `FindPath` |
| 0x21C | `u32` | `m_field_21C` | R | `FindPath` |
| 0x220 | `u8[0x38]` | _(gap)_ | - | - |
| 0x258 | `s16` | `m_field_258` | R | `FindPath` |
| 0x25C | `u32` | `m_field_25C` | R | `FindPath` |
| 0x260 | `s16` | `m_field_260` | R | `FindPath` |
| 0x264 | `u32` | `m_field_264` | R | `FindPath` |
| 0x268 | `u8[0xA0]` | _(gap)_ | - | - |
| 0x308 | `s16` | `m_field_308` | R | `FindPath` |
| 0x30C | `u32` | `m_field_30C` | R | `FindPath` |
| 0x318 | `s16` | `m_field_318` | R | `FindPath` |
| 0x31C | `u32` | `m_field_31C` | R | `FindPath` |
| 0x320 | `s16` | `m_field_320` | R | `FindPath` |
| 0x324 | `u32` | `m_field_324` | R | `FindPath` |
| 0x328 | `u8[0x168]` | _(gap)_ | - | - |
| 0x490 | `s16` | `m_field_490` | R | `FindPath` |
| 0x494 | `u32` | `m_field_494` | R | `FindPath` |
| 0x4A0 | `s16` | `m_field_4A0` | R | `FindPath` |
| 0x4A4 | `u32` | `m_field_4A4` | R | `FindPath` |

### `CASGeneticsTarget`

**Size:** >= 0x41C (1052 bytes) | **Fields:** 46 (13 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `u8` | **`m_variable`** | R/W | `CASGeneticsTarget`, `GetVariable`, `HandleGenerateStageBG`, ... |
| 0x004 | `f32` | **`m_variable_004`** | R/W | `CASGeneticsTarget`, `GetVariable`, `HandleGenerateStageBG`, ... |
| 0x006 | `u8` | **`m_variable_006`** | W | `GetVariable` |
| 0x008 | `f32` | `m_field_008` | R/W | `CASGeneticsTarget`, `HandleGenerateStageBG`, `~CASGeneticsTarget` |
| 0x00C | `f32` | `m_field_00C` | R/W | `CASGeneticsTarget`, `HandleGenerateStageBG`, `~CASGeneticsTarget` |
| 0x010 | `u32` | `m_field_010` | R/W | `CASGeneticsTarget`, `HandleGenerateStageBG`, `~CASGeneticsTarget` |
| 0x014 | `u32` | `m_field_014` | R/W | `CASGeneticsTarget`, `HandleGenerateStageBG`, `~CASGeneticsTarget` |
| 0x018 | `u32` | `m_field_018` | R/W | `CASGeneticsTarget`, `~CASGeneticsTarget` |
| 0x01C | `u32` | `m_field_01C` | R/W | `CASGeneticsTarget`, `~CASGeneticsTarget` |
| 0x020 | `u32` | `m_field_020` | R/W | `CASGeneticsTarget`, `~CASGeneticsTarget` |
| 0x024 | `u32` | `m_field_024` | R/W | `CASGeneticsTarget`, `~CASGeneticsTarget` |
| 0x028 | `u32` | `m_field_028` | W | `CASGeneticsTarget` |
| 0x038 | `u32` | `m_field_038` | W | `CASGeneticsTarget` |
| 0x048 | `u32` | `m_field_048` | W | `CASGeneticsTarget` |
| 0x058 | `u32` | `m_field_058` | R/W | `CASGeneticsTarget`, `~CASGeneticsTarget` |
| 0x068 | `u32` | `m_field_068` | R/W | `CASGeneticsTarget`, `~CASGeneticsTarget` |
| 0x078 | `u32` | `m_field_078` | W | `CASGeneticsTarget` |
| 0x07C | `u32` | `m_field_07C` | R/W | `CASGeneticsTarget`, `~CASGeneticsTarget` |
| 0x080 | `u32` | `m_field_080` | W | `CASGeneticsTarget`, `~CASGeneticsTarget` |
| 0x084 | `u32` | **`m_variable_084`** | R/W | `CASGeneticsTarget`, `HandleGenerateStageBG`, `SetVariable`, ... |
| 0x088 | `u32` | `m_field_088` | W | `CASGeneticsTarget`, `~CASGeneticsTarget` |
| 0x08C | `u32` | `m_field_08C` | W | `CASGeneticsTarget` |
| 0x090 | `u32` | `m_field_090` | W | `CASGeneticsTarget` |
| 0x094 | `u32` | **`m_defaultSim`** | R/W | `CASGeneticsTarget`, `CreateParentTexture`, `GetDefaultSim`, ... |
| 0x098 | `u32` | `m_field_098` | W | `CASGeneticsTarget` |
| 0x09C | `u32` | `m_field_09C` | R/W | `BeginGenerate`, `CASGeneticsTarget`, `Update` |
| 0x0A0 | `u32` | `m_field_0A0` | R/W | `BeginGenerate`, `CASGeneticsTarget`, `Update` |
| 0x0A4 | `u32` | `m_field_0A4` | R/W | `BeginGenerate`, `CASGeneticsTarget`, `Update` |
| 0x0A8 | `u32` | `m_field_0A8` | R/W | `BeginGenerate`, `CASGeneticsTarget`, `Update` |
| 0x0AC | `u8[0x248]` | _(gap)_ | - | - |
| 0x2F4 | `u32` | **`m_variable_2F4`** | R/W | `CASGeneticsTarget`, `HandleGenerateStageBG`, `SetVariable`, ... |
| 0x2F8 | `u32` | **`m_variable_2F8`** | R/W | `CASGeneticsTarget`, `Draw`, `SetVariable`, ... |
| 0x2FC | `u32` | `m_field_2FC` | R/W | `CASGeneticsTarget`, `CreateParentTexture`, `HandleGenerateStageBG`, ... |
| 0x300 | `u32` | **`m_grandparentIndex`** | R/W | `BeginGenerate`, `CASGeneticsTarget`, `SetGrandparentIndex`, ... |
| 0x304 | `u32` | `m_field_304` | W | `CASGeneticsTarget` |
| 0x308 | `u32` | `m_field_308` | W | `CASGeneticsTarget` |
| 0x30C | `u32` | `m_field_30C` | W | `CASGeneticsTarget` |
| 0x310 | `u32` | `m_field_310` | W | `CASGeneticsTarget` |
| 0x314 | `u32` | `m_field_314` | W | `CASGeneticsTarget` |
| 0x318 | `u32` | `m_field_318` | W | `CASGeneticsTarget` |
| 0x31C | `u32` | **`m_variable_31C`** | W | `SetVariable` |
| 0x32C | `f32` | **`m_variable_32C`** | R/W | `SetVariable` |
| 0x338 | `u32` | **`m_variable_338`** | W | `SetVariable` |
| 0x33C | `u8[0xD0]` | _(gap)_ | - | - |
| 0x40C | `u32` | **`m_variable_40C`** | W | `SetVariable` |
| 0x410 | `u32` | **`m_variable_410`** | W | `SetVariable` |
| 0x414 | `u32` | `m_field_414` | R/W | `BeginGenerate`, `CASGeneticsTarget`, `Update`, ... |
| 0x418 | `u32` | `m_field_418` | R/W | `BeginGenerate`, `CASGeneticsTarget`, `Update`, ... |

### `EGraphics`

**Size:** >= 0x33C (828 bytes) | **Fields:** 46 (24 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `void**` | **`_vtable` (vtable pointer)** | R/W | `Close`, `ComputeViewport`, `CreateRenderSurface`, ... |
| 0x004 | `u32` | `m_field_004` | R/W | `BeginFrame`, `EGraphics`, `EndFrame` |
| 0x008 | `u32` | `m_field_008` | W | `EGraphics`, `Init` |
| 0x00C | `u32` | `m_field_00C` | W | `EGraphics` |
| 0x010 | `u32` | `m_field_010` | W | `EGraphics` |
| 0x014 | `u32` | `m_field_014` | R/W | `DisplayTiming`, `DrawTiming`, `EGraphics` |
| 0x018 | `u32` | **`m_outputRect`** | R/W | `EGraphics`, `GetOutputRect` |
| 0x01C | `u32` | **`m_outputRect_01C`** | R/W | `EGraphics`, `GetOutputRect` |
| 0x020 | `u32` | `m_field_020` | W | `EGraphics` |
| 0x024 | `u32` | `m_field_024` | W | `EGraphics` |
| 0x028 | `u32` | `m_field_028` | W | `EGraphics` |
| 0x02C | `u32` | `m_field_02C` | W | `EGraphics` |
| 0x030 | `s16` | `m_field_030` | R/W | `CreateRenderSurface`, `Destroy`, `EGraphics`, ... |
| 0x034 | `u32` | `m_field_034` | R/W | `CreateTexture`, `Destroy`, `EGraphics` |
| 0x038 | `u32` | `m_field_038` | R/W | `CreateShader`, `Destroy`, `EGraphics` |
| 0x03C | `u32` | `m_field_03C` | W | `EGraphics` |
| 0x040 | `u8[0x30]` | _(gap)_ | - | - |
| 0x070 | `u32` | `m_field_070` | R | `DeselectTextures` |
| 0x080 | `u32` | `m_field_080` | W | `EGraphics` |
| 0x08C | `u32` | `m_field_08C` | W | `EGraphics` |
| 0x090 | `u32` | `m_field_090` | R/W | `DrawTiming`, `EGraphics`, `LoadSystemFont` |
| 0x098 | `u32` | `m_field_098` | W | `EGraphics` |
| 0x09C | `f32` | **`m_timing`** | R/W | `DisplayTiming`, `DrawTiming` |
| 0x0A0 | `f32` | **`m_timing_0A0`** | R/W | `DisplayTiming`, `DrawTiming` |
| 0x0A4 | `u8[0x200]` | _(gap)_ | - | - |
| 0x2A4 | `u32` | **`m_censorRect`** | R/W | `SetCensorRect` |
| 0x2A8 | `u32` | **`m_bloom`** | R/W | `SetBloom`, `SetCameraBloom` |
| 0x2AC | `f32` | **`m_bloom_2AC`** | R/W | `SetBloom`, `SetCameraBloom` |
| 0x2B0 | `f32` | **`m_bloom_2B0`** | R/W | `SetBloom`, `SetCameraBloom` |
| 0x2B4 | `f32` | **`m_bloom_2B4`** | R/W | `SetBloom`, `SetCameraBloom` |
| 0x2B8 | `f32` | **`m_bloom_2B8`** | R/W | `SetBloom`, `SetCameraBloom` |
| 0x2BC | `f32` | **`m_worldBloom`** | R/W | `SetBloom`, `SetWorldBloom` |
| 0x2C0 | `f32` | **`m_worldBloom_2C0`** | R/W | `SetBloom`, `SetWorldBloom` |
| 0x2C4 | `f32` | **`m_worldBloom_2C4`** | R/W | `SetBloom`, `SetWorldBloom` |
| 0x2C8 | `f32` | **`m_worldBloom_2C8`** | R/W | `SetBloom`, `SetWorldBloom` |
| 0x2CC | `u32` | **`m_bloom_2CC`** | R/W | `EGraphics`, `SetBloom` |
| 0x2D0 | `f32` | **`m_bloom_2D0`** | R | `SetBloom` |
| 0x2D4 | `f32` | **`m_bloom_2D4`** | R | `SetBloom` |
| 0x2D8 | `f32` | **`m_bloom_2D8`** | R | `SetBloom` |
| 0x2DC | `f32` | **`m_bloom_2DC`** | R | `SetBloom` |
| 0x2E0 | `f32` | **`m_bloom_2E0`** | W | `SetBloom` |
| 0x2E4 | `f32` | **`m_bloom_2E4`** | W | `SetBloom` |
| 0x2E8 | `f32` | **`m_bloom_2E8`** | W | `SetBloom` |
| 0x2EC | `f32` | **`m_bloom_2EC`** | W | `SetBloom` |
| 0x2F0 | `u8[0x2C]` | _(gap)_ | - | - |
| 0x31C | `u32` | `m_field_31C` | W | `EGraphics` |
| 0x320 | `u32` | `m_field_320` | W | `EGraphics` |
| 0x324 | `u32` | `m_field_324` | R/W | `Close`, `EGraphics`, `Flush`, ... |
| 0x338 | `u32` | `m_field_338` | R | `Destroy`, `Flush` |

### `R2LTarget`

**Size:** >= 0x1EC (492 bytes) | **Fields:** 46 (20 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `u16` | **`m_localizable`** | R/W | `ChangeSelection`, `GetLocalizable`, `GetVariable`, ... |
| 0x004 | `u16` | **`m_variable`** | R/W | `ChangeSelection`, `GetVariable`, `R2LTarget`, ... |
| 0x006 | `u8` | **`m_variable_006`** | W | `GetVariable` |
| 0x008 | `u32` | **`m_upPageShaders`** | R/W | `R2LTarget`, `SetupPageShaders`, `~R2LTarget` |
| 0x00C | `u16` | **`m_upPageShaders_00C`** | R/W | `R2LTarget`, `SetupPageShaders`, `~R2LTarget` |
| 0x010 | `u32` | `m_field_010` | R/W | `R2LTarget`, `~R2LTarget` |
| 0x014 | `u32` | `m_field_014` | R/W | `ChangeSelection`, `R2LTarget`, `~R2LTarget` |
| 0x018 | `u32` | **`m_upPageShaders_018`** | R/W | `ChangeSelection`, `R2LTarget`, `SetupPageShaders`, ... |
| 0x01C | `u32` | **`m_upPageShaders_01C`** | R/W | `ChangeSelection`, `R2LTarget`, `SetupPageShaders`, ... |
| 0x020 | `u32` | `m_field_020` | R/W | `R2LTarget`, `~R2LTarget` |
| 0x024 | `u32` | `m_field_024` | R/W | `R2LTarget`, `~R2LTarget` |
| 0x028 | `u32` | `m_field_028` | W | `R2LTarget` |
| 0x038 | `u32` | `m_field_038` | W | `R2LTarget` |
| 0x048 | `u32` | `m_field_048` | W | `R2LTarget` |
| 0x058 | `u32` | `m_field_058` | R/W | `R2LTarget`, `~R2LTarget` |
| 0x068 | `u32` | `m_field_068` | R/W | `R2LTarget`, `~R2LTarget` |
| 0x078 | `u32` | `m_field_078` | W | `R2LTarget` |
| 0x07C | `u32` | **`m_upPageShaders_07C`** | R/W | `ChangeSelection`, `R2LTarget`, `SetupPageShaders`, ... |
| 0x080 | `u32` | **`m_variable_080`** | R/W | `R2LTarget`, `SetVariable`, `~R2LTarget` |
| 0x084 | `u32` | `m_field_084` | W | `R2LTarget`, `~R2LTarget` |
| 0x088 | `u32` | **`m_variable_088`** | W | `GetVariable`, `R2LTarget` |
| 0x08C | `u32` | `m_field_08C` | R/W | `R2LTarget`, `~R2LTarget` |
| 0x090 | `u32` | `m_field_090` | R/W | `R2LTarget`, `~R2LTarget` |
| 0x094 | `u32` | **`m_upPageShaders_094`** | R/W | `ChangeSelection`, `R2LTarget`, `SetupPageShaders`, ... |
| 0x098 | `u32` | **`m_localizable_098`** | R/W | `ChangeSelection`, `GetLocalizable`, `SetupPageShaders`, ... |
| 0x09C | `u32` | **`m_localizable_09C`** | R/W | `ChangeSelection`, `GetLocalizable`, `GetVariable`, ... |
| 0x0A0 | `u32` | **`m_localizable_0A0`** | R/W | `ChangeSelection`, `GetLocalizable`, `GetVariable`, ... |
| 0x0A4 | `u32` | **`m_variable_0A4`** | R/W | `R2LTarget`, `SetVariable` |
| 0x0A8 | `u32` | **`m_variable_0A8`** | W | `R2LTarget`, `SetVariable` |
| 0x0B0 | `u32` | **`m_localizable_0B0`** | R/W | `ChangeSelection`, `GetLocalizable`, `R2LTarget` |
| 0x0B4 | `u32` | **`m_localizable_0B4`** | R/W | `ChangeSelection`, `GetLocalizable`, `R2LTarget` |
| 0x0B8 | `u32` | **`m_variable_0B8`** | R/W | `GetVariable`, `R2LTarget`, `SetVariable`, ... |
| 0x0BC | `u32` | `m_field_0BC` | W | `R2LTarget`, `SpawnSummaryDialog` |
| 0x0C0 | `u32` | `m_field_0C0` | W | `SpawnSummaryDialog` |
| 0x0C4 | `u32` | `m_field_0C4` | W | `SpawnSummaryDialog` |
| 0x0C8 | `u32` | `m_field_0C8` | W | `SpawnSummaryDialog` |
| 0x0CC | `u32` | `m_field_0CC` | W | `SpawnSummaryDialog` |
| 0x0D0 | `u32` | `m_field_0D0` | W | `SpawnSummaryDialog` |
| 0x0D8 | `u32` | `m_field_0D8` | W | `SpawnSummaryDialog` |
| 0x0E0 | `u32` | `m_field_0E0` | W | `SpawnSummaryDialog` |
| 0x0E4 | `u8[0x24]` | _(gap)_ | - | - |
| 0x108 | `u32` | `m_field_108` | W | `SpawnSummaryDialog` |
| 0x10C | `u32` | `m_field_10C` | W | `R2LTarget`, `SpawnSummaryDialog` |
| 0x11C | `u32` | `m_field_11C` | W | `R2LTarget`, `SpawnSummaryDialog` |
| 0x12C | `u32` | `m_field_12C` | W | `R2LTarget`, `SpawnSummaryDialog` |
| 0x130 | `u8[0x9C]` | _(gap)_ | - | - |
| 0x1CC | `u32` | **`m_variable_1CC`** | R | `GetVariable`, `SetVariable` |
| 0x1D0 | `u8[0x18]` | _(gap)_ | - | - |
| 0x1E8 | `u32` | `m_field_1E8` | R/W | `ChangeSelection`, `R2LTarget`, `~R2LTarget` |

### `MODTarget`

**Size:** >= 0x100 (256 bytes) | **Fields:** 45 (21 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `u16` | **`m_variable`** | R/W | `GetLocalizable`, `GetVariable`, `MODTarget`, ... |
| 0x004 | `u16` | **`m_variable_004`** | R/W | `GetVariable`, `MODTarget`, `~MODTarget` |
| 0x006 | `u8` | **`m_variable_006`** | W | `GetVariable` |
| 0x008 | `u32` | `m_field_008` | R/W | `MODTarget`, `~MODTarget` |
| 0x00C | `u32` | `m_field_00C` | R/W | `MODTarget`, `~MODTarget` |
| 0x010 | `u32` | `m_field_010` | R/W | `MODTarget`, `~MODTarget` |
| 0x014 | `u32` | `m_field_014` | R/W | `MODTarget`, `~MODTarget` |
| 0x018 | `u32` | `m_field_018` | R/W | `MODTarget`, `~MODTarget` |
| 0x01C | `u32` | `m_field_01C` | R/W | `MODTarget`, `~MODTarget` |
| 0x020 | `u32` | `m_field_020` | R/W | `MODTarget`, `~MODTarget` |
| 0x024 | `u32` | `m_field_024` | R/W | `MODTarget`, `~MODTarget` |
| 0x028 | `u32` | `m_field_028` | W | `MODTarget` |
| 0x038 | `u32` | `m_field_038` | W | `MODTarget` |
| 0x048 | `u32` | `m_field_048` | W | `MODTarget` |
| 0x058 | `u32` | `m_field_058` | R/W | `MODTarget`, `~MODTarget` |
| 0x068 | `u32` | `m_field_068` | R/W | `MODTarget`, `~MODTarget` |
| 0x078 | `u32` | `m_field_078` | R/W | `MODTarget` |
| 0x07C | `u32` | `m_field_07C` | R/W | `MODTarget`, `~MODTarget` |
| 0x080 | `u32` | `m_field_080` | W | `MODTarget`, `~MODTarget` |
| 0x084 | `u32` | **`m_variable_084`** | R/W | `GetVariable`, `MODTarget`, `SetDpadIcons`, ... |
| 0x088 | `u32` | **`m_variable_088`** | R/W | `MODTarget`, `SetVariable`, `TriggerAspirationChestDisplay`, ... |
| 0x08C | `u32` | **`m_variable_08C`** | R/W | `MODTarget`, `SetVariable`, `Update` |
| 0x090 | `u32` | `m_field_090` | R/W | `MODTarget`, `Update` |
| 0x094 | `u32` | **`m_variable_094`** | R/W | `DisplayFastForward`, `DisplayPaused`, `GetVariable`, ... |
| 0x098 | `u32` | `m_field_098` | W | `MODTarget` |
| 0x09C | `u32` | **`m_warning`** | R/W | `SetWarning`, `UpdateMood` |
| 0x0A0 | `u32` | **`m_mood`** | R/W | `MODTarget`, `UpdateMood` |
| 0x0A4 | `u32` | **`m_meterValue`** | R/W | `MODTarget`, `SetMeterValue`, `UpdateMood` |
| 0x0A8 | `u32` | **`m_dpadIcons`** | R/W | `MODTarget`, `SelectDpadArrow`, `SelectDpadButton`, ... |
| 0x0AC | `u32` | `m_field_0AC` | W | `SelectDpadArrow` |
| 0x0B0 | `u32` | `m_field_0B0` | W | `SelectDpadArrow` |
| 0x0B4 | `u32` | **`m_warning_0B4`** | R/W | `SelectDpadButton`, `SetWarning` |
| 0x0B8 | `u32` | **`m_dpadIcons_0B8`** | R/W | `SelectDpadButton`, `SetDpadIcons`, `SetWarning` |
| 0x0BC | `u32` | **`m_dpadIcons_0BC`** | R/W | `SelectDpadButton`, `SetDpadIcons`, `SetWarning`, ... |
| 0x0C0 | `u32` | **`m_dpadIcons_0C0`** | R/W | `MODTarget`, `SelectDpadButton`, `SetDpadIcons` |
| 0x0C4 | `u32` | **`m_dpadIcons_0C4`** | R/W | `MODTarget`, `SelectDpadButton`, `SetDpadIcons` |
| 0x0C8 | `u8[0x14]` | _(gap)_ | - | - |
| 0x0DC | `u32` | **`m_meterValue_0DC`** | R/W | `MODTarget`, `SetMeterValue` |
| 0x0E0 | `u32` | `m_field_0E0` | R/W | `DisplayPaused`, `MODTarget`, `Update` |
| 0x0E4 | `u32` | `m_field_0E4` | R/W | `DisplayFastForward`, `MODTarget`, `Update` |
| 0x0E8 | `u32` | `m_field_0E8` | R/W | `MODTarget`, `TriggerAspirationChestDisplay`, `Update` |
| 0x0EC | `u32` | **`m_localizable`** | R/W | `GetLocalizable`, `TriggerAspirationChestDisplay`, `Update` |
| 0x0F0 | `u32` | **`m_localizable_0F0`** | R/W | `GetLocalizable`, `TriggerAspirationChestDisplay`, `Update` |
| 0x0F4 | `u32` | **`m_variable_0F4`** | R/W | `MODTarget`, `SetVariable`, `Update` |
| 0x0F8 | `u32` | `m_field_0F8` | R/W | `MODTarget`, `Update` |
| 0x0FC | `u32` | **`m_variable_0FC`** | R/W | `MODTarget`, `SetVariable`, `Update` |

### `PlumbBob`

**Size:** >= 0x440 (1088 bytes) | **Fields:** 45 (16 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `f32` | **`m_state`** | R/W | `AddParticleSystem`, `Draw`, `DrawShadow`, ... |
| 0x004 | `f32` | **`m_state_004`** | R/W | `Draw`, `DrawShadow`, `SetState`, ... |
| 0x008 | `f32` | **`m_state_008`** | R/W | `Draw`, `DrawShadow`, `SetState`, ... |
| 0x00C | `f32` | **`m_state_00C`** | R/W | `ResetMomentum`, `SetState`, `Update` |
| 0x014 | `f32` | `m_field_014` | R | `AddParticleSystem`, `ResetMomentum` |
| 0x018 | `u32` | **`m_state_018`** | W | `ResetMomentum`, `SetState`, `Update` |
| 0x024 | `f32` | **`m_state_024`** | W | `SetState`, `Update` |
| 0x028 | `f32` | **`m_state_028`** | W | `SetState`, `Update` |
| 0x02C | `f32` | `m_field_02C` | R/W | `Update` |
| 0x030 | `u32` | **`m_color`** | W | `SetColor` |
| 0x040 | `u32` | **`m_color_040`** | W | `SetColor` |
| 0x04C | `f32` | `m_field_04C` | R/W | `Draw` |
| 0x050 | `f32` | `m_field_050` | R/W | `Draw` |
| 0x054 | `f32` | `m_field_054` | W | `Draw` |
| 0x058 | `u8[0x30]` | _(gap)_ | - | - |
| 0x088 | `u32` | **`m_particleSystem`** | R | `UpdateParticleSystem` |
| 0x098 | `u32` | `m_field_098` | R | `PlumbBobOrderTableCallback` |
| 0x0A8 | `u32` | `m_field_0A8` | W | `PlumbBobOrderTableCallback` |
| 0x0AC | `u32` | `m_field_0AC` | W | `PlumbBobOrderTableCallback` |
| 0x0B0 | `u32` | `m_field_0B0` | W | `PlumbBobOrderTableCallback` |
| 0x0B4 | `u32` | `m_field_0B4` | W | `PlumbBobOrderTableCallback` |
| 0x0B8 | `u32` | `m_field_0B8` | W | `PlumbBobOrderTableCallback` |
| 0x0BC | `u8[0x64]` | _(gap)_ | - | - |
| 0x120 | `u32` | `m_field_120` | W | `PlumbBob` |
| 0x124 | `u32` | `m_field_124` | W | `PlumbBob` |
| 0x128 | `f32` | **`m_state_128`** | R/W | `PlumbBob`, `SetState`, `Update` |
| 0x130 | `f32` | `m_field_130` | R | `Update` |
| 0x134 | `f32` | `m_field_134` | W | `PlumbBob`, `Update` |
| 0x140 | `f32` | `m_field_140` | R/W | `PlumbBob`, `Update` |
| 0x144 | `f32` | `m_field_144` | R/W | `PlumbBob`, `Update` |
| 0x148 | `u32` | `m_field_148` | R/W | `PlumbBob`, `Update` |
| 0x14C | `u32` | `m_field_14C` | R/W | `PlumbBob`, `Update` |
| 0x150 | `f32` | `m_field_150` | R/W | `PlumbBob`, `Update` |
| 0x154 | `u32` | **`m_particleVisibility`** | R/W | `Draw`, `EnableDraw`, `PlumbBob`, ... |
| 0x158 | `u32` | **`m_state_158`** | R/W | `PlumbBob`, `SetState`, `Update` |
| 0x15C | `u32` | `m_field_15C` | R/W | `PlumbBob`, `Update` |
| 0x160 | `u32` | `m_field_160` | R/W | `PlumbBob`, `Update` |
| 0x164 | `u32` | **`m_scaleFromTween`** | R/W | `Draw`, `DrawShadow`, `PlumbBob`, ... |
| 0x168 | `u32` | **`m_state_168`** | R/W | `PlumbBob`, `SetState`, `Update` |
| 0x16C | `u32` | `m_field_16C` | W | `PlumbBob`, `Shutdown` |
| 0x170 | `u32` | `m_field_170` | W | `PlumbBob` |
| 0x174 | `u8[0x40]` | _(gap)_ | - | - |
| 0x1B4 | `u32` | `m_field_1B4` | W | `PlumbBob` |
| 0x1C8 | `u32` | `m_field_1C8` | W | `PlumbBob` |
| 0x1CC | `u8[0x28]` | _(gap)_ | - | - |
| 0x1F4 | `u32` | **`m_particleVisibility_1F4`** | R/W | `AddParticleSystem`, `DestroyParticleSystems`, `PlumbBob`, ... |
| 0x1F8 | `u32` | `m_field_1F8` | R/W | `Update` |
| 0x1FC | `u8[0x21C]` | _(gap)_ | - | - |
| 0x418 | `f32` | `m_field_418` | R | `Draw` |
| 0x41C | `u8[0x20]` | _(gap)_ | - | - |
| 0x43C | `f32` | `m_field_43C` | R | `Draw` |

### `CSPTarget`

**Size:** >= 0x1A4 (420 bytes) | **Fields:** 44 (29 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `u16` | **`m_localizable`** | R/W | `CSPTarget`, `ChangeSelectedTab`, `GetLocalizable`, ... |
| 0x004 | `u16` | **`m_variable`** | R/W | `CSPTarget`, `GetVariable`, `SetupCareer`, ... |
| 0x006 | `u8` | **`m_variable_006`** | W | `GetVariable` |
| 0x008 | `u32` | **`m_upCareer`** | R/W | `CSPTarget`, `SetupCareer`, `~CSPTarget` |
| 0x00C | `u32` | `m_field_00C` | R/W | `CSPTarget`, `~CSPTarget` |
| 0x010 | `u32` | `m_field_010` | R/W | `CSPTarget`, `~CSPTarget` |
| 0x014 | `u32` | `m_field_014` | R/W | `CSPTarget`, `~CSPTarget` |
| 0x018 | `u32` | `m_field_018` | R/W | `CSPTarget`, `~CSPTarget` |
| 0x01C | `u32` | **`m_upCareer_01C`** | R/W | `CSPTarget`, `ChangeSelectedTab`, `InstallPromotionShaders`, ... |
| 0x020 | `s16` | **`m_upCareer_020`** | R/W | `CSPTarget`, `SetupCareer`, `~CSPTarget` |
| 0x024 | `u32` | `m_field_024` | R/W | `CSPTarget`, `~CSPTarget` |
| 0x028 | `u32` | `m_field_028` | W | `CSPTarget` |
| 0x038 | `u32` | `m_field_038` | W | `CSPTarget` |
| 0x048 | `u32` | `m_field_048` | W | `CSPTarget` |
| 0x058 | `u32` | `m_field_058` | R/W | `CSPTarget`, `~CSPTarget` |
| 0x068 | `u32` | `m_field_068` | R/W | `CSPTarget`, `~CSPTarget` |
| 0x078 | `u32` | `m_field_078` | W | `CSPTarget` |
| 0x07C | `u32` | **`m_upCareer_07C`** | R/W | `CSPTarget`, `ChangeSelectedTab`, `InstallPromotionShaders`, ... |
| 0x080 | `u32` | `m_field_080` | W | `CSPTarget`, `~CSPTarget` |
| 0x084 | `u32` | `m_field_084` | W | `CSPTarget`, `~CSPTarget` |
| 0x088 | `u32` | **`m_variable_088`** | W | `CSPTarget`, `GetVariable` |
| 0x08C | `u32` | **`m_localizable_08C`** | R/W | `CSPTarget`, `GetLocalizable`, `SetVariable` |
| 0x090 | `u32` | **`m_localizable_090`** | R/W | `CSPTarget`, `ChangeSelectedTab`, `GetLocalizable`, ... |
| 0x094 | `u32` | `m_field_094` | R/W | `CSPTarget`, `~CSPTarget` |
| 0x098 | `u32` | `m_field_098` | R/W | `CSPTarget`, `~CSPTarget` |
| 0x09C | `u8[0x14]` | _(gap)_ | - | - |
| 0x0B0 | `u32` | **`m_localizable_0B0`** | R/W | `GetLocalizable`, `SetupCareer` |
| 0x0B8 | `s16` | **`m_upCareer_0B8`** | R | `SetupCareer` |
| 0x0BA | `u8[0x1E]` | _(gap)_ | - | - |
| 0x0D8 | `u32` | **`m_localizable_0D8`** | R/W | `GetLocalizable`, `SetupCareer` |
| 0x0DC | `u32` | **`m_localizable_0DC`** | R/W | `GetLocalizable`, `SetupCareer` |
| 0x0E0 | `u32` | **`m_upSkills`** | R/W | `InstallPromotionShaders`, `SetupSkills` |
| 0x0E4 | `u32` | **`m_upSkills_0E4`** | R/W | `InstallPromotionShaders`, `SetupSkills` |
| 0x0E8 | `u32` | **`m_upSkills_0E8`** | R/W | `InstallPromotionShaders`, `SetupSkills` |
| 0x0EC | `u32` | **`m_upSkills_0EC`** | R/W | `InstallPromotionShaders`, `SetupSkills` |
| 0x0F0 | `u32` | **`m_upSkills_0F0`** | R/W | `InstallPromotionShaders`, `SetupSkills` |
| 0x0F4 | `u32` | **`m_upSkills_0F4`** | R/W | `InstallPromotionShaders`, `SetupSkills` |
| 0x0F8 | `u32` | **`m_upSkills_0F8`** | R/W | `InstallPromotionShaders`, `SetupSkills` |
| 0x0FC | `u32` | **`m_upPersonality`** | W | `SetupPersonality` |
| 0x100 | `u32` | **`m_upPersonality_100`** | W | `SetupPersonality` |
| 0x104 | `u32` | **`m_upPersonality_104`** | W | `SetupPersonality` |
| 0x108 | `u32` | **`m_upPersonality_108`** | W | `SetupPersonality` |
| 0x10C | `u32` | **`m_upPersonality_10C`** | W | `SetupPersonality` |
| 0x110 | `u32` | **`m_upPersonality_110`** | R/W | `SetupPersonality` |
| 0x112 | `s16` | **`m_upPersonality_112`** | R | `SetupPersonality` |
| 0x114 | `u8[0x8C]` | _(gap)_ | - | - |
| 0x1A0 | `u32` | **`m_variable_1A0`** | R | `GetVariable`, `SetVariable` |

### `DlgWrapper`

**Size:** >= 0x698C (27020 bytes) | **Fields:** 44 (11 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `f32` | **`m_variable`** | R/W | `DlgWrapper`, `GetVariable`, `Startup` |
| 0x001 | `u8` | **`m_variable_001`** | W | `GetVariable` |
| 0x004 | `u32` | `m_field_004` | R/W | `DlgWrapper`, `Startup` |
| 0x008 | `u32` | `m_field_008` | W | `DlgWrapper`, `Startup` |
| 0x00C | `f32` | `m_field_00C` | W | `DlgWrapper`, `Startup` |
| 0x010 | `f32` | `m_field_010` | W | `DlgWrapper`, `Startup` |
| 0x014 | `f32` | `m_field_014` | W | `DlgWrapper`, `Startup` |
| 0x018 | `f32` | `m_field_018` | W | `DlgWrapper`, `Startup` |
| 0x01C | `f32` | **`m_variable_01C`** | R/W | `SetVariable`, `Startup` |
| 0x020 | `u32` | `m_field_020` | W | `Startup` |
| 0x024 | `u32` | `m_field_024` | W | `Startup` |
| 0x028 | `u32` | `m_field_028` | W | `DlgWrapper` |
| 0x02C | `u32` | `m_field_02C` | W | `Startup` |
| 0x030 | `u32` | **`m_bodyFont`** | W | `SetAcceptFont`, `SetAlt1Font`, `SetBodyFont`, ... |
| 0x034 | `f32` | **`m_titleFontSize`** | R/W | `SetBodyFontSize`, `SetTitleFontSize`, `Startup`, ... |
| 0x038 | `u32` | `m_field_038` | W | `DlgWrapper`, `Startup` |
| 0x03C | `u32` | `m_field_03C` | W | `Startup` |
| 0x040 | `u32` | `m_field_040` | R | `Update` |
| 0x044 | `u32` | `m_field_044` | R | `Update` |
| 0x048 | `u32` | `m_field_048` | R/W | `DlgWrapper`, `Update` |
| 0x058 | `u32` | `m_field_058` | W | `DlgWrapper` |
| 0x05C | `u32` | `m_field_05C` | W | `Startup` |
| 0x060 | `u32` | `m_field_060` | R/W | `Startup` |
| 0x064 | `u32` | `m_field_064` | R/W | `Startup` |
| 0x068 | `u32` | `m_field_068` | W | `DlgWrapper` |
| 0x078 | `u32` | `m_field_078` | W | `DlgWrapper` |
| 0x080 | `u32` | `m_field_080` | W | `DlgWrapper`, `~DlgWrapper` |
| 0x084 | `u32` | `m_field_084` | W | `DlgWrapper` |
| 0x088 | `u32` | `m_field_088` | W | `DlgWrapper` |
| 0x08C | `u32` | `m_field_08C` | R/W | `DlgWrapper`, `~DlgWrapper` |
| 0x09C | `u32` | `m_field_09C` | W | `DlgWrapper` |
| 0x0A0 | `u32` | `m_field_0A0` | R/W | `DlgWrapper`, `Draw` |
| 0x0A4 | `u32` | `m_field_0A4` | R/W | `DlgWrapper`, `Startup` |
| 0x0A8 | `u32` | `m_field_0A8` | R/W | `DlgWrapper`, `Shutdown`, `Startup` |
| 0x0AC | `u32` | **`m_variable_0AC`** | R/W | `DialogPaneHide`, `DialogPaneShow`, `DlgWrapper`, ... |
| 0x0B0 | `u32` | `m_field_0B0` | R/W | `DlgWrapper`, `Shutdown`, `Startup` |
| 0x0B4 | `u32` | **`m_variable_0B4`** | R/W | `DialogPaneHide`, `DialogPaneShow`, `DlgWrapper`, ... |
| 0x0B8 | `u32` | `m_field_0B8` | R/W | `DialogPaneHide`, `DialogPaneShow`, `DlgWrapper`, ... |
| 0x0BC | `f32` | **`m_variable_0BC`** | R/W | `DlgWrapper`, `GetVariable`, `Startup` |
| 0x0C0 | `f32` | **`m_variable_0C0`** | R/W | `DlgWrapper`, `GetVariable` |
| 0x0C4 | `f32` | **`m_variable_0C4`** | R/W | `DlgWrapper`, `GetVariable`, `SetDialogSize`, ... |
| 0x0C8 | `f32` | **`m_variable_0C8`** | R/W | `DlgWrapper`, `GetVariable`, `SetDialogSize` |
| 0x0CC | `u32` | `m_field_0CC` | R/W | `DlgWrapper`, `Startup`, `Update` |
| 0x0D0 | `u8[0x68B8]` | _(gap)_ | - | - |
| 0x6988 | `f32` | `m_field_6988` | R | `Startup` |

### `EIStaticModel`

**Size:** >= 0x31C (796 bytes) | **Fields:** 44 (28 named)

| Offset | Type | Name | R/W | Accessed By |
|--------|------|------|-----|-------------|
| 0x000 | `u16` | `m_field_000` | R/W | `AnimOrderTableCallback`, `BuildDigests`, `Clone`, ... |
| 0x002 | `u16` | **`m_asShadow`** | R/W | `BuildDigests`, `DrawAsShadow` |
| 0x004 | `u32` | `m_field_004` | R/W | `BuildDigests`, `Clone`, `Draw`, ... |
| 0x008 | `u32` | **`m_orient`** | R | `BuildDigests`, `Clone`, `DrawAsShadow`, ... |
| 0x00C | `f32` | **`m_orient_00C`** | R/W | `BuildDigests`, `Clone`, `DrawAsShadow`, ... |
| 0x010 | `u32` | **`m_orient_010`** | R | `Clone`, `DrawAsShadow`, `DrawShadow`, ... |
| 0x014 | `u32` | **`m_orient_014`** | R/W | `Clone`, `Draw`, `DrawAsShadow`, ... |
| 0x018 | `u32` | **`m_orient_018`** | R/W | `Clone`, `Draw`, `DrawAsShadow`, ... |
| 0x01C | `u32` | **`m_anchorPos`** | R | `DrawShadow`, `GetAnchorPos`, `GetOrient` |
| 0x020 | `u32` | **`m_anchorPos_020`** | R | `GetAnchorPos`, `GetOrient` |
| 0x024 | `u32` | **`m_anchorPos_024`** | R | `DrawAsShadow`, `DrawShadow`, `GetAnchorPos`, ... |
| 0x028 | `u32` | **`m_anchorPos_028`** | R | `DrawShadow`, `GetAnchorPos`, `GetOrient` |
| 0x02C | `u32` | **`m_orient_02C`** | R | `DrawAsShadow`, `DrawImmediate`, `DrawImmediateGhosted`, ... |
| 0x030 | `u32` | **`m_orient_030`** | R | `DrawAsShadow`, `DrawImmediate`, `DrawImmediateGhosted`, ... |
| 0x034 | `u32` | **`m_anchorPos_034`** | R | `GetAnchorPos`, `GetOrient` |
| 0x038 | `u32` | **`m_anchorPos_038`** | R | `GetAnchorPos`, `GetOrient` |
| 0x03C | `u32` | **`m_anchorPos_03C`** | R | `GetAnchorPos`, `GetOrient` |
| 0x040 | `u8[0x1C]` | _(gap)_ | - | - |
| 0x05C | `u32` | `m_field_05C` | R/W | `BuildDigests`, `EIStaticModel` |
| 0x068 | `u32` | `m_field_068` | W | `BuildDigests` |
| 0x06C | `u32` | `m_field_06C` | W | `BuildDigests` |
| 0x070 | `u32` | `m_field_070` | R/W | `AnimOrderTableCallback`, `BuildDigests`, `Draw`, ... |
| 0x074 | `u32` | **`m_immediateGhosted`** | R | `DrawImmediateGhosted` |
| 0x07C | `u32` | **`m_upModel`** | R/W | `Clone`, `Draw`, `DrawAsShadow`, ... |
| 0x080 | `u32` | **`m_anchorPos_080`** | R/W | `Clone`, `GetAnchorPos`, `SetOrient`, ... |
| 0x084 | `u32` | **`m_anchorPos_084`** | R/W | `Clone`, `GetAnchorPos`, `SetOrient`, ... |
| 0x098 | `u32` | `m_field_098` | R | `AnimOrderTableCallback` |
| 0x0A8 | `u32` | `m_field_0A8` | R/W | `AnimOrderTableCallback` |
| 0x0B4 | `u32` | **`m_immediateGhosted_0B4`** | R | `DrawImmediateGhosted` |
| 0x0C0 | `f32` | **`m_orient_0C0`** | R/W | `GetOrient`, `SetOrient`, `Setup`, ... |
| 0x0C4 | `u32` | **`m_orient_0C4`** | R/W | `GetOrient`, `SetOrient`, `Setup`, ... |
| 0x0CC | `f32` | **`m_up`** | W | `Setup` |
| 0x0D0 | `f32` | **`m_up_0D0`** | R | `Setup` |
| 0x0E0 | `f32` | **`m_up_0E0`** | R | `Setup` |
| 0x0F0 | `u32` | `m_field_0F0` | R | `AnimOrderTableCallback`, `Draw`, `DrawAsShadow`, ... |
| 0x100 | `u32` | `m_field_100` | R/W | `Clone`, `EIStaticModel` |
| 0x110 | `u32` | **`m_upModel_110`** | R/W | `Clone`, `EIStaticModel`, `SetupModel`, ... |
| 0x114 | `u32` | **`m_upModel_114`** | R/W | `Clone`, `DeallocateModel`, `EIStaticModel`, ... |
| 0x118 | `u32` | `m_field_118` | R/W | `BuildDigests`, `ChangeShader`, `ChangeShaderState`, ... |
| 0x11C | `u32` | `m_field_11C` | R/W | `BuildDigests`, `Clone`, `DeallocateModel`, ... |
| 0x120 | `u32` | **`m_upBounds`** | R/W | `BuildDigests`, `ChangeShader`, `ChangeShaderState`, ... |
| 0x124 | `u32` | `m_field_124` | R/W | `Clone`, `Draw`, `EIStaticModel` |
| 0x128 | `u8[0x38]` | _(gap)_ | - | - |
| 0x160 | `s16` | `m_field_160` | R | `Draw` |
| 0x164 | `u32` | `m_field_164` | R | `Draw` |
| 0x168 | `u8[0x1B0]` | _(gap)_ | - | - |
| 0x318 | `u32` | `m_field_318` | R/W | `BuildDigests`, `Clone`, `Draw`, ... |

## Static Members (from Map File)

**`AmbientScorePlayer`:** `s_ambientDatabase`

**`AptDisplayList`:** `BASE_MOVIE_DEPTH`

**`AptFormat`:** `s_nPSystemUID`

**`AptMath`:** `m_nMinimumAlignment`

**`AptNativeHash`:** `NUM_PROBES`

**`AptValue`:** `MAX_REFCOUNT`, `MAX_GCROOT`

**`EAHeap`:** `EA_HEAP_NUM_SMALL_COUNTERS`

**`EGlobal`:** `kFirstPlayerCheat`

**`EIWallPart`:** `kMaxWallShaders`

**`ENDummy`:** `MAX_NAME_SIZE`

**`ENgcRenderer`:** `kFrameEffectsBufferFormat`

**`ESim`:** `m_pMemoryForHeap`

**`ESimsCam`:** `m_degRotAngDef`, `m_degTiltAngDef`, `m_zoomDef`, `m_vEyeDef`, `m_vTargetDef`, `m_vUpDef`

**`FastAllocPool`:** `ALIGNMENT`

**`GoalUnlock`:** `kNumGoalAndUnlockVariables`

**`ISimsMultiTileObjectModel`:** `_MtuliTileTweekLookupArr`, `vOffSets`

**`SimsMemCardWrap`:** `saveFileName`

**`SkinCompositor`:** `s_fullAlphaValue`

**`cXObject`:** `kNumTemp`, `kNumDataDeleted`, `kNumData`, `s_OriginalFDataCount`
