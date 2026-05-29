# VTABLE MAPS - TOP CLASSES FOR BLRL DECOMP

## Overview
This document maps virtual table layouts for the most important classes in The Sims 2.
The blrl virtual dispatch technique requires methods declared in vtable order.

## TOP 5 CLASSES BY VTABLE SIZE (Most Virtual Methods)

### 1. cXMTObject::cXObject virtual table
- **Address:** 0x805db110
- **Size:** 0x00000530 bytes
- **Entries:** 332 virtual methods

### 2. cXMTObjectImpl::cXObject virtual table
- **Address:** 0x805daac8
- **Size:** 0x00000530 bytes
- **Entries:** 332 virtual methods

### 3. cXObject virtual table
- **Address:** 0x805e2e80
- **Size:** 0x00000530 bytes
- **Entries:** 332 virtual methods

### 4. cXObjectImpl::cXObject virtual table
- **Address:** 0x805e28a0
- **Size:** 0x00000530 bytes
- **Entries:** 332 virtual methods

### 5. cXPersonImpl::cXObject virtual table
- **Address:** 0x805f1fd8
- **Size:** 0x00000530 bytes
- **Entries:** 332 virtual methods

## PRIORITY CLASSES FOR BLRL UNLOCKING

### ESim (32 blrl functions in esim TU)
- **ESim virtual table**: 0x8058f158, 126 entries
- **ESimsApp virtual table**: 0x80579870, 56 entries
- **cXMTObject::TreeSim virtual table**: 0x805db640, 44 entries
- **cXMTObjectImpl::TreeSim virtual table**: 0x805daff8, 44 entries
- **cXObject::TreeSim virtual table**: 0x805e33b0, 44 entries
- **cXObjectImpl::TreeSim virtual table**: 0x805e2dd0, 44 entries
- **cXPerson::TreeSim virtual table**: 0x805f2de8, 44 entries
- **cXPersonImpl::TreeSim virtual table**: 0x805f2950, 44 entries
- **cXPortal::TreeSim virtual table**: 0x805f4c60, 44 entries
- **cXPortalImpl::TreeSim virtual table**: 0x805f45e8, 44 entries
- **TreeSim virtual table**: 0x805faf48, 44 entries
- **TreeSimImpl::TreeSim virtual table**: 0x805fae98, 44 entries
- **ESimsDataManager virtual table**: 0x80589c00, 22 entries
- **TheSimsStartScreenStateMachine virtual table**: 0x805c9148, 18 entries
- **TheSimsNGCLicenseState virtual table**: 0x805cb8e8, 18 entries
- **TheSimsMemCardCheckState virtual table**: 0x805cb8a0, 18 entries
- **TheSimsEAMovieState virtual table**: 0x805cb858, 18 entries
- **TheSimsMaxisLogoState virtual table**: 0x805cb810, 18 entries
- **TheSimsSimsIntroMovieState virtual table**: 0x805cb7c8, 18 entries
- **TheSimsEnterMainMenuState virtual table**: 0x805cb780, 18 entries
- **TheSimsMainMenuState virtual table**: 0x805cb738, 18 entries
- **TheSimsStateMachine virtual table**: 0x805cb930, 18 entries
- **ESim::IBaseSimInstance virtual table**: 0x8058f120, 14 entries
- **ISimsObjectModel::IBaseSimInstance virtual table**: 0x8059fdb0, 14 entries
- **ISimsWallObjectModel::IBaseSimInstance virtual table**: 0x8059fb80, 14 entries
- **ISimsMultiTileObjectModel::IBaseSimInstance virtual table**: 0x8059f950, 14 entries
- **ISimsCounterTopObject::IBaseSimInstance virtual table**: 0x8059f720, 14 entries
- **IShrubObject::IBaseSimInstance virtual table**: 0x8059f4f0, 14 entries
- **IBaseSimInstance virtual table**: 0x805a2a50, 14 entries
- **ISimInstance::IBaseSimInstance virtual table**: 0x805a2828, 14 entries
- **cXMTObjectImpl::TreeSimImpl virtual table**: 0x805da9e8, 12 entries
- **cXObjectImpl::TreeSimImpl virtual table**: 0x805e2870, 12 entries
- **cXPersonImpl::TreeSimImpl virtual table**: 0x805f2508, 12 entries
- **TreeSimImpl virtual table**: 0x805fae68, 12 entries
- **ESims3DHead virtual table**: 0x805ae990, 10 entries
- **ESimsCam virtual table**: 0x805855d0, 8 entries
- **CasEventChangeSimS2C virtual table**: 0x80602158, 8 entries
- **CasEventChangeSimS2C virtual table**: 0x806039f0, 8 entries
- **CasEventChangeSimS2C virtual table**: 0x8060a200, 8 entries
- **CasEventStoreSim virtual table**: 0x8060a1e0, 8 entries
- **CasEventChangeSimS2C virtual table**: 0x80615430, 8 entries
- **CasEventChangeSimS2C virtual table**: 0x80616518, 8 entries
- **CasEventStoreSim virtual table**: 0x80637630, 8 entries
- **CasEventChangeSimS2C virtual table**: 0x80637730, 8 entries
- **CasEventChangeSimS2C virtual table**: 0x806708d0, 8 entries

### GoalUnlock / GoalBase
- **GoalUnlock virtual table**: 0x805d6230, 26 entries
- **CUnlockDisplayObject virtual table**: 0x805b5930, 12 entries
- **CUnlockDisplayObjectSim virtual table**: 0x805b6800, 12 entries
- **CUnlockDisplay virtual table**: 0x805b49e0, 6 entries

### CardSys / MemoryCard
- **ENgcMemoryCard virtual table**: 0x806a0de0, 78 entries
- **EMemoryCard virtual table**: 0x806a0f18, 54 entries
- **MemoryCardUsage virtual table**: 0x80633398, 32 entries
- **TheSimsMemCardCheckState virtual table**: 0x805cb8a0, 18 entries
- **LoadGameTarget::MemCardSaveLoad virtual table**: 0x806301f8, 8 entries
- **MemCardSaveLoad virtual table**: 0x80630288, 8 entries
- **SaveGameTarget::MemCardSaveLoad virtual table**: 0x80631818, 8 entries
- **MemCardSaveLoad virtual table**: 0x806318b0, 8 entries

### ActionQueue
- **Interaction virtual table**: 0x805d9730, 10 entries
- **AutomationNS::LuaInteractionTable virtual table**: 0x80672300, 8 entries

### APT Classes (Top 20)
- **CDirtyXml::IAptXml virtual table**: 0x8066c920, 80 entries
- **AptScriptFunctionBase virtual table**: 0x80689bc8, 54 entries
- **AptScriptFunction1 virtual table**: 0x80689af0, 54 entries
- **AptScriptFunction2 virtual table**: 0x80689a18, 54 entries
- **AptScriptFunctionByteCodeBlock virtual table**: 0x80689940, 54 entries
- **IAptXmlNode virtual table**: 0x8066cbf8, 48 entries
- **{anonymous}::CompactMapTest virtual table**: 0x80606cf8, 38 entries
- **AptExtObject virtual table**: 0x8068e1c8, 38 entries
- **AptLookup virtual table**: 0x806751b0, 34 entries
- **AptRegister virtual table**: 0x80675238, 34 entries
- **AptStringObject virtual table**: 0x80675128, 34 entries
- **AptMovieClip virtual table**: 0x806750a0, 34 entries
- **AptArray virtual table**: 0x80676e38, 34 entries
- **AptNativeFunction virtual table**: 0x80676ec0, 34 entries
- **AptNativeFunction virtual table**: 0x80677d78, 34 entries
- **AptCIH virtual table**: 0x80678a68, 34 entries
- **AptNativeFunction virtual table**: 0x806798c8, 34 entries
- **AptDate virtual table**: 0x80679840, 34 entries
- **AptNativeFunction virtual table**: 0x8067e088, 34 entries
- **AptError virtual table**: 0x8067de68, 34 entries

## ALL VTABLES SORTED BY SIZE (Top 50)

| Rank | Class | Address | Size | Entries |
|------|-------|---------|------|----------|
| 1 | cXMTObject::cXObject virtual table | 0x805db110 | 0x00000530 | 332 |
| 2 | cXMTObjectImpl::cXObject virtual table | 0x805daac8 | 0x00000530 | 332 |
| 3 | cXObject virtual table | 0x805e2e80 | 0x00000530 | 332 |
| 4 | cXObjectImpl::cXObject virtual table | 0x805e28a0 | 0x00000530 | 332 |
| 5 | cXPersonImpl::cXObject virtual table | 0x805f1fd8 | 0x00000530 | 332 |
| 6 | cXPortal::cXObject virtual table | 0x805f4730 | 0x00000530 | 332 |
| 7 | cXPortalImpl::cXObject virtual table | 0x805f40b8 | 0x00000530 | 332 |
| 8 | cXPerson virtual table | 0x805f2a18 | 0x000003d0 | 244 |
| 9 | cXPersonImpl::cXPerson virtual table | 0x805f2580 | 0x000003d0 | 244 |
| 10 | ENgcRC virtual table | 0x806a1420 | 0x00000350 | 212 |
| 11 | ERC virtual table | 0x80696408 | 0x000002d8 | 182 |
| 12 | ObjectModule virtual table | 0x805e84a8 | 0x000002a0 | 168 |
| 13 | ObjectModuleImpl virtual table | 0x805e8208 | 0x000002a0 | 168 |
| 14 | EGraphics virtual table | 0x80695ec8 | 0x00000240 | 144 |
| 15 | ENgcGraphics virtual table | 0x806a0b08 | 0x00000240 | 144 |
| 16 | ObjectFolderImpl virtual table | 0x805e5950 | 0x00000218 | 134 |
| 17 | ObjectFolder virtual table | 0x805e5ba8 | 0x00000208 | 130 |
| 18 | ESim virtual table | 0x8058f158 | 0x000001f8 | 126 |
| 19 | ISimsObjectModel virtual table | 0x8059fde8 | 0x000001f8 | 126 |
| 20 | ISimsWallObjectModel virtual table | 0x8059fbb8 | 0x000001f8 | 126 |
| 21 | ISimsMultiTileObjectModel virtual table | 0x8059f988 | 0x000001f8 | 126 |
| 22 | ISimsCounterTopObject virtual table | 0x8059f758 | 0x000001f8 | 126 |
| 23 | IShrubObject virtual table | 0x8059f528 | 0x000001f8 | 126 |
| 24 | TTabScratchEntry virtual table | 0x805fb298 | 0x000001f8 | 126 |
| 25 | TreeTableEntryQuickData virtual table | 0x806005d8 | 0x000001f8 | 126 |
| 26 | ISimInstance virtual table | 0x805a2860 | 0x000001f0 | 124 |
| 27 | NeighborhoodImpl virtual table | 0x805de4f0 | 0x000001c0 | 112 |
| 28 | Neighborhood virtual table | 0x805de6b0 | 0x000001c0 | 112 |
| 29 | cSimulator virtual table | 0x805f8610 | 0x000001a8 | 106 |
| 30 | cSimulatorImpl virtual table | 0x805f8468 | 0x000001a8 | 106 |
| 31 | EIAmbLight virtual table | 0x80661e40 | 0x00000198 | 102 |
| 32 | EIPortalPointLight virtual table | 0x80665c58 | 0x00000198 | 102 |
| 33 | EIDirLight virtual table | 0x80662310 | 0x00000190 | 100 |
| 34 | EILight virtual table | 0x806632e8 | 0x00000190 | 100 |
| 35 | EIPointAmbLight virtual table | 0x806647f8 | 0x00000190 | 100 |
| 36 | EIPointLight virtual table | 0x80665220 | 0x00000190 | 100 |
| 37 | EISpotLight virtual table | 0x80666150 | 0x00000190 | 100 |
| 38 | PlayerFamilyImpl virtual table | 0x805f38e0 | 0x00000180 | 96 |
| 39 | EIFenceWall virtual table | 0x8058d640 | 0x00000178 | 94 |
| 40 | EIWallPart virtual table | 0x8058d7b8 | 0x00000178 | 94 |
| 41 | ESimShadow virtual table | 0x8058f350 | 0x00000170 | 92 |
| 42 | EIStaticModel virtual table | 0x80666cb0 | 0x00000170 | 92 |
| 43 | Family virtual table | 0x805d44b8 | 0x00000168 | 90 |
| 44 | FamilyImpl virtual table | 0x805d4350 | 0x00000168 | 90 |
| 45 | SAnimator2 virtual table | 0x805ac748 | 0x00000160 | 88 |
| 46 | EIStaticSubModel virtual table | 0x80667730 | 0x00000160 | 88 |
| 47 | EmitterSpr3d virtual table | 0x8057d9d0 | 0x00000158 | 86 |
| 48 | EmitterSpr3d virtual table | 0x80582958 | 0x00000158 | 86 |
| 49 | EIFloor virtual table | 0x8059ce18 | 0x00000158 | 86 |
| 50 | EmitterGeom3dTab virtual table | 0x8059ffe0 | 0x00000158 | 86 |

## STATISTICS
- Total vtables found: 888
- Largest vtable: cXMTObject::cXObject virtual table with 332 entries
- Smallest vtable: EDL virtual table with 6 entries