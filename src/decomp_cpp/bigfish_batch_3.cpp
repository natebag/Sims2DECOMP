// bigfish_batch_3.cpp - Big fish asm stub conversions (6936-11687 lines), batch 3
// Converted from 8 asm stub files to portable C++
// Classes: ERLevel (63 funcs), PCTTarget (51 funcs), AptCharacterInst (32 funcs),
//          ObjectModuleImpl (64 funcs), EdithVariableSet (16 funcs),
//          static_init (146 funcs), EAnimController (93 funcs), INVTarget (108 funcs)
#include "types.h"

// ============================================================================
// External functions
// ============================================================================
extern "C" {
    void* memcpy(void*, const void*, unsigned int);
    void* memset(void*, int, unsigned int);
    void* memmove(void*, const void*, unsigned int);
    int memcmp(const void*, const void*, unsigned int);
    int strlen(const char*);
    char* strcpy(char*, const char*);
    char* strcat(char*, const char*);
    char* strchr(const char*, int);
    char* strrchr(const char*, int);
    char* strncpy(char*, const char*, unsigned int);
    int strcmp(const char*, const char*);
    int stricmp(const char*, const char*);
    int strncmp(const char*, const char*, unsigned int);
    float sqrtf(float);
    int Sprintf(char*, char*, ...);
    int wcslen(const unsigned short*);
    unsigned short* wcscpy(unsigned short*, const unsigned short*);
    int wcscmp(const unsigned short*, const unsigned short*);
    float sinf(float);
    float cosf(float);
    float fabsf(float);
    int rand();
    void srand(unsigned int);
    float fmodf(float, float);
    double fmod(double, double);
    int puts(const char*);
    void abort();
    int atoi(const char*);
    int swprintf(unsigned short*, const unsigned short*, ...);
}

extern int MLtraceNull(...);

// Memory
class EAHeap;
extern EAHeap* MainHeap();
extern EAHeap* RootHeap();
extern EAHeap* VMHeap();
extern EAHeap* ResourceHeap();
extern EAHeap* AudioHeap();
extern EAHeap* ShaderHeap();
extern EAHeap* TextureHeap();
extern EAHeap* AnimationHeap();
extern EAHeap* ModelHeap();
extern EAHeap* FlashesHeap();
extern EAHeap* AptHeap();
extern EAHeap* DebugHeap();
extern EAHeap* CUIHeap();
class EAHeap {
public:
    void* Malloc(unsigned int, int);
    void* MallocAligned(unsigned int, unsigned int, unsigned int, int);
    void Free(void*);
    void Compact();
    void SetNextCheckPoint();
};

// Operator new/delete
extern void* operator new(std::size_t);
extern void operator delete(void*);
extern void* __builtin_vec_new(std::size_t);
extern void __builtin_vec_delete(void*);

// ============================================================================
// STL / Allocator helpers
// ============================================================================
template <bool B, int I>
class __node_alloc {
public:
    static void* _M_allocate(unsigned int);
    static void _M_deallocate(void*, unsigned int);
};

// ============================================================================
// Forward declarations
// ============================================================================
template <typename T> class TNodeList;
template <typename T> class allocator;
template <typename T0, typename T1> class vector;
template <typename T0, typename T1> class pair;
template <int N, typename T0, typename T1> class byte_key_map;

class NLIteratorPtrType;
class EString;
class EConfig;
class EStringTableNoCase;
class EFile;
class EStream;
class EMat4;
struct EVec3;
class EVec2;
class EVec4;
class EBound3;
class EBoundSphere;
class ERC;
class EResource;
class EResourceManager;
class EDataHeader;
class ETypeInfo;
class EThread;
class EFixedString;
class ERFont;
class ERMovie;
class EPMDesc;
class EWindow;
class EInstance;
class EAnimController;
class EACTrack;
class EACTrackStreams;
class EACNodeState;
class EACEventRange;
class EAnimNodeDataPos;
class ECharacterNode;
class ERCharacter;
class ERAnim;
class ERModel;
class EStorable;
class EOrderTableData;
class EDirLight;
class EILight;
class ELights;
class EIDirLight;
class EIPointLight;
class ELightGrid;
class EHashTable;
class ERedBlackTree;
class ENodeList;
class LevelLightingEntry;
class AptValue;
class AptCIH;
class AptMovie;
class EAStringC;
class AptNativeHash;
class AptString;
class AptActionInterpreter;
class AptFormat;
class FenceData;
class FloorTile;
class IGoalUnlock;
class ISimInstance;
class ObjSelector;
class WallTile;
class cXObject;
class cXMTObject;
class cXObjectImpl;
class cXPerson;
class cXPersonImpl;
class CTilePt;
class HouseStats;
class Neighbor;
class RoomManager;
class ReconBuffer;
class iResFile;
class Commander;
class HelpDialog;
class ActionMenu;
class UIObjectBase;
class UIDialog;
class UIUpdateTable;
class UIDrawTable;
class UIUserDrawCBTable;
class UI2D;
class UI3D;
class UIAUDIO;
class GetVariableCommandTable;
class SetVariableCommandTable;
class GetLocalizableCommandTable;
class CBFunctor0;
class _Nonconst_traits;
class StringBuffer;
class EMemoryMeterWin;
class ESimsApp;
class ESimsDataManager;
class NewControlParms;
class SimsCameraParameters;

struct eAnimatedObjectType;
struct eTrackFlags;

namespace BBI {
    class InventoryItem {
    public:
        struct eItemSubcategory;
    };
}

namespace InteractorModule {
    class Interactor {
    public:
        struct CallbackData;
    };
    class PlaceManipulator {
    public:
        struct CallbackData;
    };
    class WallManipulator {
    public:
        struct CallbackData;
    };
    class WallPainter {
    public:
        struct CallbackData;
    };
    class FloorPainter {
    public:
        struct CallbackData;
    };
    class GrabManipulator {
    public:
        struct CallbackData;
    };
    class ShoppingItem;
    class WallData;
    class WallPaperData;
    class FloorData;
}

// ============================================================================
// BString2
// ============================================================================
class BString2 {
public:
    BString2();
    ~BString2();
    BString2& operator=(unsigned short*);
};

// ============================================================================
// Base class definitions needed before ERLevel and ObjectModuleImpl
// ============================================================================
class EResource {
public:
    EResource();
    ~EResource();
    void DelRef();
    void SetName(char*);
};

class Commander {
public:
    Commander();
    ~Commander();
};

// ============================================================================
// ERLevel
// ============================================================================
// 63 functions, 23568 bytes

class ERLevel : public EResource {
public:
    // 0x80231348 (952 bytes)
    ERLevel() {
        // NOTE: asm-derived - complex constructor
        // Initializes EResource base, ELightGrid, EOrderTableEntry, EMat4s,
        // EHashTable, ERedBlackTree, EIDirLight, EILight, and many member fields
        // Sets up vtable, zeroes out numerous member variables,
        // calls EResourceManager::AddRef for resources, creates child RC,
        // inserts default lights
    }

    // 0x80231700 (404 bytes)
    ~ERLevel() {
        // NOTE: asm-derived - complex destructor
        // Sets vtable, removes lights, releases resources via DelRef,
        // calls EEngine::ClearCurrentLevel, destroys room node lists,
        // destroys EInstance children, removes from ENodeList, ERedBlackTree,
        // EHashTable, then calls EResource::~EResource base dtor
    }

    // 0x80231894 (92 bytes)
    // Copies sun light direction and color data from member offsets into output refs
    void GetSunLight(EVec3& outDir, EDirLight& outLight);

    // 0x802318F0 (672 bytes)
    void Write(EStream& stream);

    // 0x80231BD0 (172 bytes)
    void AddInstancesFromBoundTree(EStorable* storable);

    // 0x80231C7C (1720 bytes)
    void Read(EStream& stream);

    // 0x80232334 (2172 bytes)
    void Load(EFile& file);

    // 0x80232BB0 (464 bytes)
    void Refresh(EFile* file);

    // 0x80232D80 (120 bytes)
    void AllocAndLoadLevel(EFile& file);

    // 0x80232DF8 (68 bytes)
    void ClearJustReadByLevelFlags();

    // 0x80232E3C (328 bytes)
    void DestroyInstancesWithoutJustReadByLevelFlags();

    // 0x80232F84 (124 bytes)
    void DestroyInstancesOriginallyReadByLevel();

    // 0x80233000 (148 bytes)
    void Deallocate();

    // 0x80233094 (296 bytes)
    void DeallocateSub();

    // 0x80233210 (92 bytes)
    void InsertWall(EInstance* inst, bool flag);

    // 0x8023326C (88 bytes)
    void RemoveWall(EInstance* inst);

    // 0x802332C4 (68 bytes)
    void InsertLight(EILight* light);

    // 0x80233308 (92 bytes)
    void RemoveLight(EILight* light);

    // 0x80233368 (236 bytes)
    void InsertSkydomeInstance(EInstance* inst);

    // 0x80233454 (232 bytes)
    void AddInstanceToLevel(EInstance* inst);

    // 0x8023353C (240 bytes)
    void AddInstanceToLevelHead(EInstance* inst);

    // 0x8023362C (420 bytes)
    void AddWallInstanceToLevel(EInstance* inst);

    // 0x802337D4 (80 bytes)
    void PrepareInstance(EInstance* inst);

    // 0x80233824 (164 bytes)
    void AddInstanceToRoom(EInstance* inst);

    // 0x802338C8 (156 bytes)
    void RemoveInstanceFromRoom(EInstance* inst);

    // 0x80233964 (120 bytes)
    void GetRoomIndex(EInstance* inst) const;

    // 0x802339DC (92 bytes)
    void NotifyInstanceMoved(EInstance* inst);

    // 0x80233A38 (268 bytes)
    void FixInstances();

    // 0x80233B44 (88 bytes)
    void FixInstanceList(TNodeList<EInstance*>& list);

    // 0x80233BD8 (120 bytes)
    void RemoveInstanceFromIdMap(EInstance* inst);

    // 0x80233D1C (192 bytes)
    void Init();

    // 0x80233EA4 (108 bytes)
    void UnregisterFloorOTDs(EInstance* inst);

    // 0x80233F10 (384 bytes)
    void RemoveInstance(EInstance* inst);

    // 0x80234090 (288 bytes)
    void SetBounds(EInstance* inst, EBound3& bounds);

    // 0x802341B0 (176 bytes)
    void AddBounds(EBound3& a, EBound3& b, bool& flag);

    // 0x80234260 (264 bytes)
    void CalcBounds();

    // 0x802343A0 (152 bytes)
    void Update();

    // 0x80234438 (120 bytes)
    void CalcRadiusFromViewParams(float fov, float aspect, float dist);

    // 0x80234508 (568 bytes)
    void DrawObjectShadowsOutside(TNodeList<EInstance*>& list);

    // 0x80234740 (816 bytes)
    void DrawObjectShadowsInside(TNodeList<EInstance*>& list);

    // 0x80234A70 (116 bytes)
    void DrawOrderTableSlot(EOrderTableData* otd);

    // 0x80234AE4 (192 bytes)
    void DrawOrderTableSlotFast(EOrderTableData* otd);

    // 0x80234BA4 (244 bytes)
    void DrawSortedOrderTable(EOrderTableData* otd);

    // 0x80234C98 (4364 bytes)
    void Draw(ERC* rc);

    // 0x80235DA4 (368 bytes)
    void ObjectShouldBeOccluded(EInstance* inst);

    // 0x80235F14 (68 bytes)
    void ObjectShouldBeOccluded(short id, float dist);

    // 0x80235F58 (784 bytes)
    void DrawSimShadow(int simIndex);

    // 0x80236288 (152 bytes)
    void AllocAndCopyOTD(EOrderTableData& otd);

    // 0x8023637C (100 bytes)
    void RegisterFloor(EOrderTableData& otd);

    // 0x802363E0 (168 bytes)
    void InsertInOrderTable(EOrderTableData& otd);

    // 0x80236488 (232 bytes)
    void InsertInDOFForegroundObjectList(EOrderTableData& otd);

    // 0x80236598 (544 bytes)
    void DrawOrderTableEntry(EOrderTableData* otd, ERC* rc);

    // 0x802367B8 (376 bytes)
    void DrawOrderTable();

    // 0x80236930 (700 bytes)
    void IntersectBoundBox(EBound3& bound, EVec3& rayOrig, EVec3& rayDir);

    // 0x80236BEC (188 bytes)
    void DrawWireFrame(ERC* rc);

    // 0x80236CA8 (480 bytes)
    void SetRoomCount(int count);

    // 0x80236E88 (132 bytes)
    void UpdateLightsIntensityScale(int roomIndex, EVec3 pos);

    // 0x80236F0C (68 bytes)
    void IsRoomAt(EVec3& pos, int roomIndex);

    // 0x80236F74 (152 bytes)
    void ResetLightLocations();

    // 0x802377AC (364 bytes)
    void OutsideLightsUpdate(float timeOfDay, LevelLightingEntry& entry);

    // 0x80237918 (136 bytes)
    void UpdateFloorLighting();

    // 0x802379B4 (200 bytes)
    void GetLightsAtLocation(EVec3& pos, int roomIndex, ELights& outLights);

    // 0x8023813C (84 bytes)
    void RegisterType(unsigned short typeId);
};

// ============================================================================
// PCTTarget
// ============================================================================
// 51 functions, 26192 bytes

class PCTTarget {
public:
    enum ePCTMode {};
    enum ePCTType {};

    class cCellInfo {
    public:
        // 0x801D1F54 (288 bytes)
        void Init(ObjSelector* sel, IGoalUnlock* unlock);

        // 0x801D2074 (68 bytes)
        void Init(int index, FenceData* fence);

        // 0x801D20B8 (68 bytes)
        void Init(int index, WallTile* wall);

        // 0x801D20FC (68 bytes)
        void Init(int index, FloorTile* floor);

        // 0x801D2140 (180 bytes)
        void GetPrice() const;

        // 0x801D21F4 (264 bytes)
        void GetName(unsigned short* outName) const;

        // 0x801D22FC (140 bytes)
        void GetDesc(unsigned short* outDesc) const;
    };

    // 0x801D2388 (4012 bytes)
    PCTTarget(ePCTMode mode, int param) {
        // NOTE: asm-derived - complex constructor
        // Sets vtable, zeroes many member fields at offsets 0-240,
        // constructs 5 BString2 members, initializes HelpDialog,
        // creates GetVariableCommandTable, SetVariableCommandTable,
        // GetLocalizableCommandTable, UIUpdateTable, UIDrawTable,
        // UIUserDrawCBTable, UI2D, UI3D, UIAUDIO singletons if needed,
        // installs UI update entries and callbacks
    }

    // 0x801D3334 (740 bytes)
    ~PCTTarget() {
        // NOTE: asm-derived - complex destructor
        // Destroys HelpDialog, BString2 members, uninstalls UI entries,
        // cleans up allocated resources
    }

    // 0x801D3618 (1872 bytes)
    void SetVariable(char* name, char* value);

    // 0x801D3D68 (1032 bytes)
    void GetVariable(char* name);

    // 0x801D4170 (1244 bytes)
    void GetLocalizable(char* name);

    // 0x801D464C (856 bytes)
    void Update();

    // 0x801D49E0 (76 bytes)
    void get_cell_info_at_gridindex(unsigned int index) const;

    // 0x801D4A2C (368 bytes)
    void on_tab_changed();

    // 0x801D4C54 (392 bytes)
    void on_tab_changed_objects();

    // 0x801D4DDC (428 bytes)
    void on_tab_changed_wall();

    // 0x801D4FC8 (388 bytes)
    void on_tab_changed_wallpaper();

    // 0x801D51A0 (464 bytes)
    void on_tab_changed_floor();

    // 0x801D5370 (1196 bytes)
    void on_selection_changed();

    // 0x801D581C (244 bytes)
    void on_PCT_Scroll(int delta);

    // 0x801D5910 (108 bytes)
    void on_PCT_EnterToolMode();

    // 0x801D597C (772 bytes)
    void on_PCT_EnterPlaceMode();

    // 0x801D5C80 (168 bytes)
    void on_PCT_SetVisible(bool visible);

    // 0x801D5D28 (272 bytes)
    void update_grid_shaders();

    // 0x801D5E38 (288 bytes)
    void update_object_shader();

    // 0x801D5F58 (484 bytes)
    void calc_motive_ratings();

    // 0x801D6144 (104 bytes)
    void get_motive_rating_value(unsigned int index, unsigned short* outStr) const;

    // 0x801D61BC (92 bytes)
    void set_dialog_visible(bool visible);

    // 0x801D6218 (124 bytes)
    void can_afford_selection() const;

    // 0x801D6294 (220 bytes)
    void on_PCT_ShowHelp(int helpId);

    // 0x801D6370 (72 bytes)
    void start_action_menu();

    // 0x801D63B8 (240 bytes)
    void CreateGrabObjectMenu(TNodeList<ISimInstance*>& simList);

    // 0x801D64A8 (184 bytes)
    void setup_interactor_camera(bool flag);

    // 0x801D6560 (708 bytes)
    void enter_tool_mode(ePCTType type, bool flag);

    // 0x801D6824 (1468 bytes)
    void GrabManipulatorCallback(InteractorModule::Interactor::CallbackData* data);

    // 0x801D6DEC (124 bytes)
    void delete_dialog_selection_callback(int selection);

    // 0x801D6E68 (288 bytes)
    void sell_dialog_selection_callback(int selection);

    // 0x801D6F88 (456 bytes)
    void enter_place_tombstone_mode();

    // 0x801D7150 (620 bytes)
    void enter_place_mode(cCellInfo* cellInfo);

    // 0x801D73BC (160 bytes)
    void PickedUpObject(cXObject* obj);

    // 0x801D745C (880 bytes)
    void PlaceModeCallback(InteractorModule::Interactor::CallbackData* data);

    // 0x801D77CC (644 bytes)
    void enter_wall_mode(cCellInfo* cellInfo, bool flag);

    // 0x801D7A50 (604 bytes)
    void WallManipulatorCallback(InteractorModule::Interactor::CallbackData* data);

    // 0x801D7CAC (244 bytes)
    void calc_wall_value(InteractorModule::Interactor::CallbackData* data);

    // 0x801D7DA0 (568 bytes)
    void enter_wallpaper_mode(cCellInfo* cellInfo, bool flag);

    // 0x801D7FD8 (176 bytes)
    void calc_wallpaper_value(InteractorModule::Interactor::CallbackData* data);

    // 0x801D8088 (532 bytes)
    void WallPainterCallback(InteractorModule::Interactor::CallbackData* data);

    // 0x801D829C (560 bytes)
    void enter_floor_mode(cCellInfo* cellInfo, bool flag);

    // 0x801D84CC (400 bytes)
    void FloorPainterCallback(InteractorModule::Interactor::CallbackData* data);

    // 0x801D865C (244 bytes)
    void calc_floor_tile_value(InteractorModule::Interactor::CallbackData* data);
};

// ============================================================================
// AptCharacterInst
// ============================================================================
// 32 functions, 28384 bytes

class AptCharacterInst {
public:
    // 0x80288B98 (292 bytes)
    void _gotoAndX(AptValue* frameArg, int numArgs, int playFlag);

    // 0x80288CBC (1756 bytes)
    void CleanNativeFunctions();

    // 0x802893E0 (720 bytes)
    void sMethod_attachMovie(AptValue* args, int numArgs);

    // 0x802896B0 (488 bytes)
    void sMethod_loadMovie(AptValue* args, int numArgs);

    // 0x80289898 (220 bytes)
    void sMethod_unloadMovie(AptValue* args, int numArgs);

    // 0x80289974 (156 bytes)
    void sMethod_duplicateMovieClip(AptValue* args, int numArgs);

    // 0x80289A10 (120 bytes)
    void sMethod_removeMovieClip(AptValue* args, int numArgs);

    // 0x80289A88 (120 bytes)
    void sMethod_removeTextField(AptValue* args, int numArgs);

    // 0x80289B00 (820 bytes)
    void sMethod_createTextField(AptValue* args, int numArgs);

    // 0x80289E34 (228 bytes)
    void sMethod_getDepth(AptValue* args, int numArgs);

    // 0x80289F18 (812 bytes)
    void sMethod_swapDepths(AptValue* args, int numArgs);

    // 0x8028A244 (212 bytes)
    void sMethod_setMask(AptValue* args, int numArgs);

    // 0x8028A318 (916 bytes)
    void sMethod_getBounds(AptValue* args, int numArgs);

    // 0x8028A6AC (516 bytes)
    void sMethod_startDrag(AptValue* args, int numArgs);

    // 0x8028A8B0 (844 bytes)
    void sMethod_hitTest(AptValue* args, int numArgs);

    // 0x8028ABFC (440 bytes)
    void sMethod_createEmptyMovieClip(AptValue* args, int numArgs);

    // 0x8028ADB4 (180 bytes)
    void sMethod_loadVariables(AptValue* args, int numArgs);

    // 0x8028AE68 (160 bytes)
    void sMethod_stop(AptValue* args, int numArgs);

    // 0x8028AF08 (160 bytes)
    void sMethod_play(AptValue* args, int numArgs);

    // 0x8028AFA8 (76 bytes)
    void sMethod_nextFrame(AptValue* args, int numArgs);

    // 0x8028AFF4 (76 bytes)
    void sMethod_prevFrame(AptValue* args, int numArgs);

    // 0x8028B040 (556 bytes)
    void sMethod_getBytesTotal(AptValue* args, int numArgs);

    // 0x8028B26C (480 bytes)
    void sMethod_getBytesLoaded(AptValue* args, int numArgs);

    // 0x8028B44C (4312 bytes)
    void objectMemberSet(AptValue* obj, EAStringC* name, AptValue* value);

    // 0x8028C524 (9576 bytes)
    void objectMemberLookup(AptValue* obj, EAStringC* name);

    // 0x8028EA8C (712 bytes)
    void sMethod_setTextFormat(AptValue* args, int numArgs);

    // 0x8028ED54 (1060 bytes)
    void sMethod_getNewTextFormat(AptValue* args, int numArgs);

    // 0x8028F178 (1476 bytes)
    void sMethod_getTextFormat(AptValue* args, int numArgs);

    // 0x8028F73C (624 bytes)
    void sMethod_localToGlobal(AptValue* args, int numArgs);

    // 0x8028FAE8 (92 bytes)
    // Destructor variant 1
    ~AptCharacterInst();

    // 0x8029C5F4 (92 bytes)
    // Destructor variant 2 (thunk/duplicate at different address)

    // 0x802C4C68 (92 bytes)
    // Destructor variant 3 (thunk/duplicate at different address)
};

// ============================================================================
// ObjectModuleImpl
// ============================================================================
// 64 functions, 27940 bytes

class ObjectModuleImpl : public Commander {
public:
    // 0x800F2CBC (272 bytes)
    ObjectModuleImpl() {
        // NOTE: asm-derived - constructor
        // Sets vtable, constructs Commander base,
        // initializes many vector-like member fields at offsets 28-8352 to zero,
        // calls memset to zero a large block
    }

    // 0x800F2DCC (520 bytes)
    ~ObjectModuleImpl() {
        // NOTE: asm-derived - destructor
        // Sets vtable, destroys vector members (deallocating their buffers),
        // destroys Commander base, frees allocated memory via operator delete
        // or __node_alloc::_M_deallocate
    }

    // 0x800F2FD4 (228 bytes)
    void Save(iResFile* file);

    // 0x800F30BC (1576 bytes)
    void Load(iResFile* file);

    // 0x800F36E4 (760 bytes)
    void killDemolishedObjects(iResFile* file);

    // 0x800F39DC (128 bytes)
    void PostLoad(iResFile* file, int param, bool flag);

    // 0x800F3A5C (192 bytes)
    void SelectPlayerSims();

    // 0x800F3B1C (212 bytes)
    void DoReconObject(ReconBuffer* buf, cXObjectImpl** objOut);

    // 0x800F3BF0 (160 bytes)
    void DoReconPerson(ReconBuffer* buf, cXPersonImpl** personOut);

    // 0x800F3C94 (2324 bytes)
    void DoStream(ReconBuffer* buf, int mode);

    // 0x800F45A8 (116 bytes)
    void Init();

    // 0x800F461C (164 bytes)
    void LoadGlobalRoutingSlots();

    // 0x800F46C0 (568 bytes)
    void Destroy();

    // 0x800F48F8 (284 bytes)
    void GetObjectByGUID(int guid);

    // 0x800F4A14 (156 bytes)
    void GetPersonByGUID(int guid);

    // 0x800F4AB0 (288 bytes)
    void ConstructObject(ObjSelector* sel, cXMTObject* mtObj);

    // 0x800F4BD0 (1324 bytes)
    void MakeNewOutOfWorldObject(ObjSelector* sel, short* outId);

    // 0x800F50FC (1388 bytes)
    void KillOutOfWorldObject(short objId, bool flag);

    // 0x800F5668 (532 bytes)
    void KillObject(short objId);

    // 0x800F587C (312 bytes)
    void KillQueueFlush();

    // 0x800F59B4 (228 bytes)
    void PostSim(bool flag);

    // 0x800F5A98 (120 bytes)
    void DayChanged();

    // 0x800F5B10 (704 bytes)
    void UpdateRooms(int roomCount);

    // 0x800F5DD0 (168 bytes)
    void UpdateInteractionInfluences();

    // 0x800F5E78 (596 bytes)
    void KillAllObjects();

    // 0x800F60CC (528 bytes)
    void KillObjectsOutsideBounds(int x1, int y1, int x2, int y2);

    // 0x800F62DC (948 bytes)
    void UpdateSimObjects();

    // 0x800F6690 (800 bytes)
    void AddToKillQueue(short objId, bool immediate);

    // 0x800F69BC (248 bytes)
    void IsFamilyMemberAwakeAndVisible();

    // 0x800F6AB4 (404 bytes)
    void DoCommand(short objId, int command);

    // 0x800F6C48 (404 bytes)
    void PreviewAnimation(short objId, short animId, short blendId, bool flag);

    // 0x800F6DDC (116 bytes)
    void ForceAllLocations();

    // 0x800F6E50 (844 bytes)
    void GetAnObjectID(short startId);

    // 0x800F719C (2048 bytes)
    void AddObject(cXObject* obj, short id, bool flag);

    // 0x800F799C (720 bytes)
    void RemoveObject(cXObject* obj);

    // 0x800F7C6C (456 bytes)
    void DisableBuyAndBuild(cXObject* obj);

    // 0x800F7E34 (244 bytes)
    void EnableBuyAndBuild(cXObject* obj);

    // 0x800F7F28 (592 bytes)
    void CheckIntegrity();

    // 0x800F8178 (156 bytes)
    void ClearAwarenessOfObject(cXObject* obj);

    // 0x800F8214 (172 bytes)
    void CleanupPeople(cXObject* obj);

    // 0x800F82C8 (180 bytes)
    void BroadcastMessage(char* msg, int param);

    // 0x800F837C (200 bytes)
    void SendMessage(cXObject* target, char* msg, int param);

    // 0x800F8444 (148 bytes)
    void UpdateWallAdjacencies();

    // 0x800F84D8 (120 bytes)
    void InvalidateAllRoutes();

    // 0x800F8560 (120 bytes)
    void RelationshipAccessed(Neighbor* a, Neighbor* b, int type, bool flag);

    // 0x800F85D8 (288 bytes)
    void OffsetObjectMap(CTilePt& offset);

    // 0x800F86F8 (1372 bytes)
    void OffsetWorld(CTilePt& offset);

    // 0x800F8C6C (140 bytes)
    void SetTutorialObject(cXObject* obj);

    // 0x800F8CF8 (76 bytes)
    void ShowTutorialInfo();

    // 0x800F8D44 (932 bytes)
    void ComputeStats(int* a, int* b, bool* c, bool* d, bool* e);

    // 0x800F90E8 (424 bytes)
    void FillInObjectStats(RoomManager* roomMgr, HouseStats& stats);

    // 0x800F9290 (128 bytes)
    void IsSelectionSwitchingAllowed();

    // 0x800F9310 (116 bytes)
    void IsValidObject(cXObject* obj);

    // 0x800F9384 (176 bytes)
    void IsValidPerson(cXPerson* person);

    // 0x800F9480 (248 bytes)
    void ClearIdleStatus(int param);

    // 0x800F9620 (72 bytes)
    void GetObjectFromID(int id);

    // 0x800F9668 (124 bytes)
    void GetTileObjectID(CTilePt& tile);

    // 0x800F96E4 (104 bytes)
    void SetTileObjectID(CTilePt& tile, short id);

    // 0x800F974C (128 bytes)
    void CreateNeighbor(Neighbor* neighbor);

    // 0x800F97CC (84 bytes)
    void GetObject(int index);

    // 0x800F9860 (200 bytes)
    void GetNextPerson(unsigned short startIndex);

    // 0x8013FFB4 (116 bytes)
    void GetSimMemory(int simId, int category, int index);

    // 0x80140028 (284 bytes)
    void SetSimMemory(int simId, int category, int index, int value);

    // 0x80140144 (160 bytes)
    void GetDominantMemory(int simId, int category, int index);
};

// ============================================================================
// EdithVariableSet
// ============================================================================
// 16 functions, 29744 bytes

class EdithVariableSet {
public:
    // 0x800E3280 (108 bytes)
    EdithVariableSet() {
        // NOTE: asm-derived - constructor
        // Calls memset to zero first 12 bytes, then zeroes offsets 12, 16,
        // sub-struct at offset 20 (pointer + end ptr),
        // and 8 short members at offsets 30-44
    }

    // 0x800E32EC (264 bytes)
    EdithVariableSet(EdithVariableSet& other) {
        // NOTE: asm-derived - copy constructor
        // Copies first 12 bytes directly, allocates new buffer for vector at
        // offset 12 (using __builtin_new or __node_alloc::_M_allocate),
        // copies vector contents via memmove, copies 8 short members via loop
    }

    // 0x800E33F4 (3040 bytes)
    void Initialize(cXObjectImpl* obj);

    // 0x800E3FD4 (108 bytes)
    ~EdithVariableSet() {
        // NOTE: asm-derived - destructor
        // Frees vector buffer at offset 12 if non-null,
        // frees sub-struct at offset 20 if non-null,
        // uses __builtin_delete or __node_alloc::_M_deallocate based on size
    }

    // 0x800E4040 (1304 bytes)
    void operator[](int index);

    // 0x800E4558 (4836 bytes)
    void WriteVar(int varIndex, short value);

    // 0x800E583C (1408 bytes)
    void ReconStream(ReconBuffer* buf, int mode);

    // 0x800E5DBC (6588 bytes)
    void Insert(pair<unsigned int, short>& kvp);

    // 0x800E7778 (740 bytes)
    void RemoveInstanceVariable(unsigned char varId);

    // 0x800E7A5C (440 bytes)
    void ShrinkToExactSize(byte_key_map<72, short, allocator<short>>& map);

    // 0x800E7C14 (284 bytes)
    void ReconKeyBitSet(ReconBuffer* buf, void* iter);

    // 0x800E7D30 (564 bytes)
    void ReconOldFdata(ReconBuffer* buf, unsigned int param);

    // 0x800E7F64 (264 bytes)
    void Reset();

    // 0x800E806C (1168 bytes)
    void Contains(int varIndex);

    // 0x800E84FC (664 bytes)
    void GetCategoryVariableMap(unsigned short category);

    // 0x800E8794 (7964 bytes)
    void CreateCategoryVariableMap(unsigned short category);
};

// ============================================================================
// __static_initialization_and_destruction_0 functions
// ============================================================================
// 146 functions, 34428 bytes
// These are compiler-generated static init/destroy functions for global objects.
// Each one constructs or destructs specific global objects based on the
// (int initialize, int priority) parameters passed by the CRT.

// 0x800062FC (132 bytes) - ESimsApp global
void __static_init_800062FC(int mode, int priority);

// 0x8000AE30 (256 bytes) - Array of 48 structs (32 bytes each), loop init/destroy
void __static_init_8000AE30(int mode, int priority);

// 0x8001E87C (200 bytes) - NewControlParms + 2 SimsCameraParameters globals
void __static_init_8001E87C(int mode, int priority);

// 0x800235E8 (136 bytes) - ESimsDataManager + EFile globals
void __static_init_800235E8(int mode, int priority);

// 0x800254D0 (7772 bytes) - Large block of camera/game tuning constants
void __static_init_800254D0(int mode, int priority);

// 0x8003038C (284 bytes)
void __static_init_8003038C(int mode, int priority);

// 0x80034E40 (312 bytes)
void __static_init_80034E40(int mode, int priority);

// 0x800372D8 (208 bytes)
void __static_init_800372D8(int mode, int priority);

// 0x80039514 (92 bytes)
void __static_init_80039514(int mode, int priority);

// 0x8003DE10 (108 bytes)
void __static_init_8003DE10(int mode, int priority);

// 0x8003E0EC (84 bytes)
void __static_init_8003E0EC(int mode, int priority);

// 0x80042928 (708 bytes)
void __static_init_80042928(int mode, int priority);

// 0x80048198 (428 bytes)
void __static_init_80048198(int mode, int priority);

// 0x80053A70 (408 bytes)
void __static_init_80053A70(int mode, int priority);

// 0x8005675C (136 bytes)
void __static_init_8005675C(int mode, int priority);

// 0x80057738 (248 bytes)
void __static_init_80057738(int mode, int priority);

// 0x8005B1E4 (84 bytes)
void __static_init_8005B1E4(int mode, int priority);

// 0x8006E708 (88 bytes)
void __static_init_8006E708(int mode, int priority);

// 0x800703EC (360 bytes)
void __static_init_800703EC(int mode, int priority);

// 0x80074524 (1504 bytes)
void __static_init_80074524(int mode, int priority);

// 0x800770E4 (1136 bytes)
void __static_init_800770E4(int mode, int priority);

// 0x8007D53C (84 bytes)
void __static_init_8007D53C(int mode, int priority);

// 0x80086D40 (692 bytes)
void __static_init_80086D40(int mode, int priority);

// 0x8009591C (84 bytes)
void __static_init_8009591C(int mode, int priority);

// 0x8009A338 (2444 bytes)
void __static_init_8009A338(int mode, int priority);

// 0x8009FFE0 (84 bytes)
void __static_init_8009FFE0(int mode, int priority);

// 0x800A48F0 (112 bytes)
void __static_init_800A48F0(int mode, int priority);

// 0x800A533C (76 bytes)
void __static_init_800A533C(int mode, int priority);

// 0x800AD090 (136 bytes)
void __static_init_800AD090(int mode, int priority);

// 0x800B131C (120 bytes)
void __static_init_800B131C(int mode, int priority);

// 0x800B505C (312 bytes)
void __static_init_800B505C(int mode, int priority);

// 0x800B838C (84 bytes)
void __static_init_800B838C(int mode, int priority);

// 0x800C2CD0 (76 bytes)
void __static_init_800C2CD0(int mode, int priority);

// 0x800CC5D4 (164 bytes)
void __static_init_800CC5D4(int mode, int priority);

// 0x800D16BC (456 bytes)
void __static_init_800D16BC(int mode, int priority);

// 0x800D9264 (348 bytes)
void __static_init_800D9264(int mode, int priority);

// 0x800EA814 (128 bytes)
void __static_init_800EA814(int mode, int priority);

// 0x8010FB78 (432 bytes)
void __static_init_8010FB78(int mode, int priority);

// 0x8011333C (84 bytes)
void __static_init_8011333C(int mode, int priority);

// 0x8012C36C (356 bytes)
void __static_init_8012C36C(int mode, int priority);

// 0x80134778 (700 bytes)
void __static_init_80134778(int mode, int priority);

// 0x801388B4 (76 bytes)
void __static_init_801388B4(int mode, int priority);

// 0x8013D824 (84 bytes)
void __static_init_8013D824(int mode, int priority);

// 0x8013FC1C (84 bytes)
void __static_init_8013FC1C(int mode, int priority);

// 0x8015A684 (112 bytes)
void __static_init_8015A684(int mode, int priority);

// 0x8015B8F8 (112 bytes)
void __static_init_8015B8F8(int mode, int priority);

// 0x80166F84 (692 bytes)
void __static_init_80166F84(int mode, int priority);

// 0x8016FB00 (84 bytes)
void __static_init_8016FB00(int mode, int priority);

// 0x80175428 (84 bytes)
void __static_init_80175428(int mode, int priority);

// 0x801755C4 (164 bytes)
void __static_init_801755C4(int mode, int priority);

// 0x8017578C (132 bytes)
void __static_init_8017578C(int mode, int priority);

// 0x80175934 (132 bytes)
void __static_init_80175934(int mode, int priority);

// 0x801A07A4 (84 bytes)
void __static_init_801A07A4(int mode, int priority);

// 0x802060C8 (80 bytes)
void __static_init_802060C8(int mode, int priority);

// 0x80218E84 (140 bytes)
void __static_init_80218E84(int mode, int priority);

// 0x80226DCC (112 bytes)
void __static_init_80226DCC(int mode, int priority);

// 0x802272FC (112 bytes)
void __static_init_802272FC(int mode, int priority);

// 0x802276E0 (112 bytes)
void __static_init_802276E0(int mode, int priority);

// 0x80227EEC (112 bytes)
void __static_init_80227EEC(int mode, int priority);

// 0x80229284 (112 bytes)
void __static_init_80229284(int mode, int priority);

// 0x80229B28 (112 bytes)
void __static_init_80229B28(int mode, int priority);

// 0x8022A444 (112 bytes)
void __static_init_8022A444(int mode, int priority);

// 0x8022AF1C (112 bytes)
void __static_init_8022AF1C(int mode, int priority);

// 0x8022B6FC (112 bytes)
void __static_init_8022B6FC(int mode, int priority);

// 0x8022DF48 (112 bytes)
void __static_init_8022DF48(int mode, int priority);

// 0x8022F694 (140 bytes)
void __static_init_8022F694(int mode, int priority);

// 0x8022F968 (108 bytes)
void __static_init_8022F968(int mode, int priority);

// 0x80237F70 (196 bytes)
void __static_init_80237F70(int mode, int priority);

// 0x8026BE5C (248 bytes)
void __static_init_8026BE5C(int mode, int priority);

// 0x80281C8C (144 bytes)
void __static_init_80281C8C(int mode, int priority);

// 0x80287D54 (124 bytes)
void __static_init_80287D54(int mode, int priority);

// 0x802C4950 (196 bytes)
void __static_init_802C4950(int mode, int priority);

// 0x802C5C2C (112 bytes)
void __static_init_802C5C2C(int mode, int priority);

// 0x802C7268 (84 bytes)
void __static_init_802C7268(int mode, int priority);

// 0x802D158C (108 bytes)
void __static_init_802D158C(int mode, int priority);

// 0x802D5C50 (104 bytes)
void __static_init_802D5C50(int mode, int priority);

// 0x802D6EB4 (112 bytes)
void __static_init_802D6EB4(int mode, int priority);

// 0x802E20B0 (84 bytes)
void __static_init_802E20B0(int mode, int priority);

// 0x802E3A44 (84 bytes)
void __static_init_802E3A44(int mode, int priority);

// 0x802F0D1C (84 bytes)
void __static_init_802F0D1C(int mode, int priority);

// 0x802F9A10 (112 bytes)
void __static_init_802F9A10(int mode, int priority);

// 0x802FA9E8 (100 bytes)
void __static_init_802FA9E8(int mode, int priority);

// 0x803007D8 (84 bytes)
void __static_init_803007D8(int mode, int priority);

// 0x80303DAC (84 bytes)
void __static_init_80303DAC(int mode, int priority);

// 0x80306554 (136 bytes)
void __static_init_80306554(int mode, int priority);

// 0x8030671C (168 bytes)
void __static_init_8030671C(int mode, int priority);

// 0x80307B20 (84 bytes)
void __static_init_80307B20(int mode, int priority);

// 0x8030A100 (364 bytes)
void __static_init_8030A100(int mode, int priority);

// 0x8030FA7C (112 bytes)
void __static_init_8030FA7C(int mode, int priority);

// 0x80311C34 (84 bytes)
void __static_init_80311C34(int mode, int priority);

// 0x80312070 (112 bytes)
void __static_init_80312070(int mode, int priority);

// 0x80312E14 (84 bytes)
void __static_init_80312E14(int mode, int priority);

// 0x80313BF4 (112 bytes)
void __static_init_80313BF4(int mode, int priority);

// 0x8031770C (132 bytes)
void __static_init_8031770C(int mode, int priority);

// 0x8031B164 (136 bytes)
void __static_init_8031B164(int mode, int priority);

// 0x803203DC (160 bytes)
void __static_init_803203DC(int mode, int priority);

// 0x80321180 (112 bytes)
void __static_init_80321180(int mode, int priority);

// 0x803222B4 (84 bytes)
void __static_init_803222B4(int mode, int priority);

// 0x80322994 (112 bytes)
void __static_init_80322994(int mode, int priority);

// 0x80322C18 (108 bytes)
void __static_init_80322C18(int mode, int priority);

// 0x80322D9C (108 bytes)
void __static_init_80322D9C(int mode, int priority);

// 0x80322F54 (116 bytes)
void __static_init_80322F54(int mode, int priority);

// 0x80323120 (108 bytes)
void __static_init_80323120(int mode, int priority);

// 0x80323290 (108 bytes)
void __static_init_80323290(int mode, int priority);

// 0x80323A4C (112 bytes)
void __static_init_80323A4C(int mode, int priority);

// 0x8032488C (120 bytes)
void __static_init_8032488C(int mode, int priority);

// 0x80324AC8 (108 bytes)
void __static_init_80324AC8(int mode, int priority);

// 0x80324C54 (108 bytes)
void __static_init_80324C54(int mode, int priority);

// 0x80324DD0 (108 bytes)
void __static_init_80324DD0(int mode, int priority);

// 0x80324F4C (108 bytes)
void __static_init_80324F4C(int mode, int priority);

// 0x80325114 (116 bytes)
void __static_init_80325114(int mode, int priority);

// 0x80325480 (120 bytes)
void __static_init_80325480(int mode, int priority);

// 0x80328130 (84 bytes)
void __static_init_80328130(int mode, int priority);

// 0x80328268 (108 bytes)
void __static_init_80328268(int mode, int priority);

// 0x803283EC (108 bytes)
void __static_init_803283EC(int mode, int priority);

// 0x8032854C (108 bytes)
void __static_init_8032854C(int mode, int priority);

// 0x803286E4 (108 bytes)
void __static_init_803286E4(int mode, int priority);

// 0x8032884C (108 bytes)
void __static_init_8032884C(int mode, int priority);

// 0x803289AC (108 bytes)
void __static_init_803289AC(int mode, int priority);

// 0x80328B04 (108 bytes)
void __static_init_80328B04(int mode, int priority);

// 0x8032B668 (108 bytes)
void __static_init_8032B668(int mode, int priority);

// 0x8032CB1C (84 bytes)
void __static_init_8032CB1C(int mode, int priority);

// 0x8032D8A8 (164 bytes)
void __static_init_8032D8A8(int mode, int priority);

// 0x8032DB6C (76 bytes)
void __static_init_8032DB6C(int mode, int priority);

// 0x8032DF94 (84 bytes)
void __static_init_8032DF94(int mode, int priority);

// 0x8032F260 (116 bytes)
void __static_init_8032F260(int mode, int priority);

// 0x8032FDD0 (84 bytes)
void __static_init_8032FDD0(int mode, int priority);

// 0x80335064 (76 bytes)
void __static_init_80335064(int mode, int priority);

// 0x8034A488 (148 bytes)
void __static_init_8034A488(int mode, int priority);

// 0x8034DB54 (84 bytes)
void __static_init_8034DB54(int mode, int priority);

// 0x80356584 (84 bytes)
void __static_init_80356584(int mode, int priority);

// 0x80362008 (180 bytes)
void __static_init_80362008(int mode, int priority);

// 0x80363308 (112 bytes)
void __static_init_80363308(int mode, int priority);

// 0x80364564 (288 bytes)
void __static_init_80364564(int mode, int priority);

// 0x80367100 (112 bytes)
void __static_init_80367100(int mode, int priority);

// 0x80367F64 (112 bytes)
void __static_init_80367F64(int mode, int priority);

// 0x8036842C (112 bytes)
void __static_init_8036842C(int mode, int priority);

// 0x80368B1C (112 bytes)
void __static_init_80368B1C(int mode, int priority);

// 0x80369710 (112 bytes)
void __static_init_80369710(int mode, int priority);

// 0x80369E08 (112 bytes)
void __static_init_80369E08(int mode, int priority);

// 0x8036A4E4 (112 bytes)
void __static_init_8036A4E4(int mode, int priority);

// 0x8036AB0C (112 bytes)
void __static_init_8036AB0C(int mode, int priority);

// 0x8036B03C (112 bytes)
void __static_init_8036B03C(int mode, int priority);

// 0x8036C0C0 (112 bytes)
void __static_init_8036C0C0(int mode, int priority);

// 0x8036C8D0 (84 bytes)
void __static_init_8036C8D0(int mode, int priority);

// 0x8036CCBC (112 bytes)
void __static_init_8036CCBC(int mode, int priority);

// ============================================================================
// EAnimController
// ============================================================================
// 93 functions, 38092 bytes

class EAnimController {
public:
    // 0x802E77A4 (224 bytes)
    EAnimController() {
        // NOTE: asm-derived - constructor
        // Sets m_type = 2, m_animId = -1
        // Zeroes track list at offset 72, sets active flag = 1
        // Releases any existing resource at offset 36 via DelRef
        // Zeroes matrices/node pointers at offsets 12-32, 56-68, 108, 112
        // Sets default blend values (-1 at offsets 40, 44, 48, 52)
        // Loads float defaults for offsets 84, 88
    }

    // 0x802E7884 (96 bytes)
    ~EAnimController() {
        // NOTE: asm-derived - destructor
        // Calls Deallocate(), removes track node list,
        // releases EResource at offset 36 via DelRef,
        // conditionally frees this via operator delete
    }

    // 0x802E78E4 (272 bytes)
    void Deallocate() {
        // NOTE: asm-derived
        // Calls StopAllTracks(), DeallocateNodes()
        // Frees matrix buffer at offset 12 via MainHeap()->Free()
        // Destroys track array at offset 68 (each track has ERedBlackTree + resource)
        // Frees node state buffer at offset 112 via MainHeap()->Free()
        // Resets m_animId = -1, zeroes node/matrix pointers, releases resource
    }

    // 0x802E79F4 (212 bytes)
    void DeallocateNodes() {
        // NOTE: asm-derived
        // Frees node data at offset 24 via MainHeap()->Free()
        // Frees node arrays at offsets 28, 32 via MainHeap()->Free()
        // Sets m_nodeCount = -1 at offset 44, zeroes offset 16
    }

    // 0x802E7AC8 (1068 bytes)
    void Init(unsigned int animId, eAnimatedObjectType objType, unsigned int flags);

    // 0x802E7EF4 (76 bytes)
    void Init(char* animName, eAnimatedObjectType objType, unsigned int flags);

    // 0x802E7F60 (320 bytes)
    void IsTrackValid(eTrackFlags trackFlag);

    // 0x802E80C4 (328 bytes)
    void SuspendTrack(eTrackFlags trackFlag);

    // 0x802E820C (332 bytes)
    void ResumeTrack(eTrackFlags trackFlag);

    // 0x802E8358 (148 bytes)
    void CalcOrientMatrix(EVec3& fwd, EVec3& up, EVec3& right, EMat4& outMat);

    // 0x802E83EC (1144 bytes)
    void Update(EVec3* pos, EVec3* orient, EVec3 velocity);

    // 0x802E8864 (392 bytes)
    void ProcessEvents(TNodeList<EACEventRange*>& eventList, bool flag);

    // 0x802E89EC (108 bytes)
    void AddEventRange(TNodeList<EACEventRange*>& eventList, EACTrack* track, float start, float end);

    // 0x802E8A58 (2488 bytes)
    void UpdateTrack(EACTrack* track, EVec3& pos, EVec3& orient, TNodeList<EACEventRange*>& events);

    // 0x802E9410 (152 bytes)
    void GetSlavePos(EACTrack* master, EACTrack* slave);

    // 0x802E94D8 (464 bytes)
    void GetAnimTrans(eTrackFlags trackFlag, EVec3& outTrans);

    // 0x802E96A8 (696 bytes)
    void GetAnimTranslate(eTrackFlags trackFlag, EVec3& outStart, EVec3& outEnd);

    // 0x802E9960 (420 bytes)
    void GetAnimTime(eTrackFlags trackFlag);

    // 0x802E9B04 (100 bytes)
    void GetAnimVelocity(eTrackFlags trackFlag, EVec3& outVel);

    // 0x802E9B68 (164 bytes)
    void GetFirstRelevantTrack();

    // 0x802E9C24 (184 bytes)
    void AnimateTrack(EACTrack* track, EACNodeState* nodeState, EMat4* mat);

    // 0x802E9CDC (1100 bytes)
    void Compute(EMat4& mat, int index);

    // 0x802EA128 (180 bytes)
    void AllocMatrices();

    // 0x802EA1DC (176 bytes)
    void ComputeInverse(EMat4& mat, int index);

    // 0x802EA2CC (312 bytes)
    void PostMultNodeAndDescendents(int nodeIndex, EMat4& mat);

    // 0x802EA404 (312 bytes)
    void PreMultNodeAndDescendents(int nodeIndex, EMat4& mat);

    // 0x802EA53C (348 bytes)
    void CalcTightBoundBox(EMat4& mat, EBound3& outBound, bool* valid);

    // 0x802EA698 (68 bytes)
    void FixAccumulationForRootNode(EACTrack* track, EACNodeState& nodeState);

    // 0x802EA6DC (772 bytes)
    void AnimateSpecial(ERAnim* anim, float time, EACTrackStreams* streams,
                        EACNodeState* state, EAnimNodeDataPos* dataPos, EACNodeState& outState);

    // 0x802EA9E0 (824 bytes)
    void BlendNodeArrays(EACTrack* track, EACNodeState* stateA, EACNodeState* stateB);

    // 0x802EAD18 (1176 bytes)
    void Animate(EACTrack* track, EACNodeState* outState);

    // 0x802EB1B0 (400 bytes)
    void Blend(float factor, EACNodeState& stateA, EACNodeState& stateB);

    // 0x802EB340 (508 bytes)
    void Layer(float factor, EACNodeState& stateA, EACNodeState& stateB);

    // 0x802EB570 (1624 bytes)
    void ComputeMatrices(EMat4& rootMat);

    // 0x802EBBC8 (1040 bytes)
    void CalcMatrix(EMat4& parentMat, ECharacterNode& node, EACNodeState& state, EMat4& outMat);

    // 0x802EBFD8 (96 bytes)
    void StopAllTracks();

    // 0x802EC038 (352 bytes)
    void DeactivateTrack(EACTrack* track);

    // 0x802EC198 (796 bytes)
    void CreateStreams(EACTrack* track);

    // 0x802EC4B4 (236 bytes)
    void DestroyStreams(EACTrack* track);

    // 0x802EC5A0 (328 bytes)
    void StopTrack(eTrackFlags trackFlag);

    // 0x802EC6E8 (680 bytes)
    void TransferTrack(eTrackFlags srcFlag, eTrackFlags dstFlag);

    // 0x802EC990 (360 bytes)
    void GetTrackAnimId(eTrackFlags trackFlag);

    // 0x802ECAF8 (1044 bytes)
    void SetStaticBlendTrackAnim(eTrackFlags trackFlag, unsigned int animId,
                                  float blend, int mode, float speed, EACTrack* srcTrack);

    // 0x802ECF0C (2272 bytes)
    void SetTrackAnim(eTrackFlags trackFlag, unsigned int animId,
                       int mode, float speed, EACTrack** outTrack);

    // 0x802ED7EC (84 bytes)
    void SetTrackAnim(eTrackFlags trackFlag, char* animName);

    // 0x802ED840 (364 bytes)
    void GetTrackAnimName(eTrackFlags trackFlag);

    // 0x802ED9AC (408 bytes)
    void SetTrackIntensity(eTrackFlags trackFlag, float intensity);

    // 0x802EDB44 (172 bytes)
    void SetTrackIntensity(EACTrack* track, float intensity, bool immediate);

    // 0x802EDBF0 (128 bytes)
    void SetAllTrackIntensities(float intensity);

    // 0x802EDC70 (348 bytes)
    void GetTrackBlendTarget(eTrackFlags trackFlag);

    // 0x802EDDCC (336 bytes)
    void GetTrackIntensity(eTrackFlags trackFlag);

    // 0x802EDF1C (336 bytes)
    void GetTrackSpeed(eTrackFlags trackFlag);

    // 0x802EE06C (272 bytes)
    void BlendAllOutgoingTracks(float target, float rate, bool flag);

    // 0x802EE17C (96 bytes)
    void SetTrackBlend(EACTrack* track, float blend);

    // 0x802EE1DC (328 bytes)
    void SetTrackBlend(eTrackFlags trackFlag, float blend);

    // 0x802EE324 (108 bytes)
    void SetTrackBlendSmooth(EACTrack* track, float target, float rate, float accel);

    // 0x802EE390 (328 bytes)
    void SetTrackBlendSmooth(eTrackFlags trackFlag, float target, float rate, float accel);

    // 0x802EE4F8 (328 bytes)
    void SetTrackBlendHermiteSafe(eTrackFlags trackFlag, float p0, float p1, float t0, float t1);

    // 0x802EE640 (184 bytes)
    void SetTrackBlendHermite(EACTrack* track, float p0, float p1, float t0, float t1);

    // 0x802EE6F8 (348 bytes)
    void SetTrackBlendHermite(eTrackFlags trackFlag, float p0, float p1, float t0, float t1);

    // 0x802EE854 (524 bytes)
    void BlendTrackIntensity(EACTrack* track);

    // 0x802EEA60 (156 bytes)
    void SetTrackPhaseLock(EACTrack* master, EACTrack* slave, float phase);

    // 0x802EEAFC (536 bytes)
    void SetProceduralTrack(eTrackFlags trackFlag,
                             void (*updateCB)(unsigned int, EACTrack*, ERCharacter*, EVec3&, EVec3&),
                             void (*animCB)(unsigned int, EACTrack*, EMat4&, ERCharacter*, EACNodeState*),
                             unsigned int userData);

    // 0x802EED14 (428 bytes)
    void RestartTrack(eTrackFlags trackFlag);

    // 0x802EEEC0 (384 bytes)
    void SetTrackPhase(eTrackFlags trackFlag, float phase);

    // 0x802EF040 (468 bytes)
    void SetTrackFrame(eTrackFlags trackFlag, float frame, bool clamp);

    // 0x802EF230 (324 bytes)
    void SetTrackBlendFactors(eTrackFlags trackFlag, float* factors);

    // 0x802EF374 (360 bytes)
    void GetTrackFrameCount(eTrackFlags trackFlag);

    // 0x802EF4DC (336 bytes)
    void GetTrackFrame(eTrackFlags trackFlag);

    // 0x802EF62C (396 bytes)
    void GetTrackPos(eTrackFlags trackFlag);

    // 0x802EF7B8 (104 bytes)
    void SetTrackPos(EACTrack* track, float pos, bool wrap);

    // 0x802EF820 (328 bytes)
    void SetTrackPos(eTrackFlags trackFlag, float pos, bool wrap);

    // 0x802EF968 (344 bytes)
    void IsTrackAnimComplete(eTrackFlags trackFlag);

    // 0x802EFAC0 (328 bytes)
    void ClearTrackAnimComplete(eTrackFlags trackFlag);

    // 0x802EFC08 (316 bytes)
    void GetTrackAnimDef(eTrackFlags trackFlag);

    // 0x802EFD44 (68 bytes)
    void SetTrackSpeed(EACTrack* track, float speed);

    // 0x802EFD88 (328 bytes)
    void SetTrackSpeed(eTrackFlags trackFlag, float speed);

    // 0x802EFED0 (104 bytes)
    void SetAllTrackSpeed(float speed);

    // 0x802EFF38 (148 bytes)
    void VisibilityTest(EMat4& viewMat);

    // 0x802EFFCC (820 bytes)
    void CalcVisibilitySphere(EMat4& mat, EBoundSphere& outSphere);

    // 0x802F0300 (180 bytes)
    void GetAnimRootNodeTrans(EACTrack* track);

    // 0x802F03B4 (116 bytes)
    void Draw(ERC* rc, ERModel* model, EMat4& mat);

    // 0x802F0428 (308 bytes)
    void CalcNodePos(int nodeIndex);

    // 0x802F055C (284 bytes)
    void CalcNodeMatrix(int nodeIndex, EMat4& outMat);

    // 0x802F0678 (136 bytes)
    void GetNodeMatrix(int nodeIndex);

    // 0x802F0700 (348 bytes)
    void CalcNodeOrientWithoutLocalRot(int nodeIndex, EMat4& outMat);

    // 0x802F085C (468 bytes)
    void CalcNodeOrient(int nodeIndex, EMat4& outMat);

    // 0x802F0A30 (92 bytes)
    void SetNodeIgnoreAnimatedVisibility(int nodeIndex, bool ignore);

    // 0x802F0A8C (92 bytes)
    void SetNodeVisible(int nodeIndex, bool visible);

    // 0x802F0AE8 (276 bytes)
    void SetTrackActive(EACTrack* track, bool active);

    // 0x802F0BFC (208 bytes)
    void Enable(bool enable, EMat4& mat);

    // 0x802F0CCC (80 bytes)
    void CalcBillinearCoeff(float u, float v, float w,
                             float& c0, float& c1, float& c2, float& c3);

    // 0x803C357C (144 bytes)
    void GetNonMainTrackFlagFromIndex(int index);
};

// ============================================================================
// INVTarget
// ============================================================================
// 108 functions, 43760 bytes

class INVTarget {
public:
    enum eInteractorMode {};

    // 0x801ECDF0 (3284 bytes)
    INVTarget(int param) {
        // NOTE: asm-derived - complex constructor
        // Sets vtable, zeroes many fields at offsets 0-13036,
        // constructs ActionMenu at offset 12700,
        // constructs 5 BString2 members,
        // creates singleton UI tables (GetVariableCommandTable, etc.) if needed,
        // installs UI update/draw entries,
        // calls EAHeap::Compact() on all 14 heaps,
        // calls EAHeap::SetNextCheckPoint(),
        // polls EMemoryMeterWin, installs callback functors
    }

    // 0x801EDAC4 (1760 bytes)
    ~INVTarget() {
        // NOTE: asm-derived - complex destructor
        // Uninstalls UI entries, destroys BString2 members, ActionMenu,
        // frees allocated vector buffers, calls EAHeap::Compact() on all heaps
    }

    // 0x801EE1A4 (92 bytes)
    void GetPlayerFunds() const;

    // 0x801EE200 (100 bytes)
    void SetPlayerFunds(int amount);

    // 0x801EE264 (176 bytes)
    void FormatMoneyString(int amount, bool showSign, unsigned short* outStr);

    // 0x801EE314 (888 bytes)
    void SetVariable(char* name, char* value);

    // 0x801EE68C (2344 bytes)
    void GetVariable(char* name);

    // 0x801EEFB4 (408 bytes)
    void GetLocalizable(char* name);

    // 0x801EF14C (536 bytes)
    void GetOnLocMsgInvObjectName(unsigned short* outStr);

    // 0x801EF364 (340 bytes)
    void GetOnLocMsgInvObjectDescription(unsigned short* outStr);

    // 0x801EF500 (624 bytes)
    void Cheat_OnSetCurrentTabMode(int mode);

    // 0x801EF770 (656 bytes)
    void OnItemSelectedCheatMode();

    // 0x801EFA1C (1588 bytes)
    void Cheat_InstallSelectedCategoryObjectShaders(int category);

    // 0x801F0050 (164 bytes)
    void OnSetCurrentTab(int tab);

    // 0x801F00F4 (780 bytes)
    void InstallInventoryPanelShaders(int panel);

    // 0x801F0400 (184 bytes)
    void UninstallInventoryPanelInfo();

    // 0x801F04FC (204 bytes)
    void SetupInteractorCamera(bool flag);

    // 0x801F05C8 (88 bytes)
    void UpdateInputState();

    // 0x801F0620 (204 bytes)
    void CreateObjectMenuForBuyBuild(TNodeList<ISimInstance*>& simList);

    // 0x801F06EC (148 bytes)
    void PushPlaceFilter();

    // 0x801F0780 (232 bytes)
    void PushGrabFilter();

    // 0x801F0868 (84 bytes)
    void PopCurrentFilter();

    // 0x801F08BC (72 bytes)
    void Cheat_HandleProgressDownHierarchy(char* param);

    // 0x801F0904 (132 bytes)
    void Cheat_HandleReturnUpHierarchy(char* param);

    // 0x801F0988 (888 bytes)
    void Cheat_HandleCellChange();

    // 0x801F0D00 (72 bytes)
    void ClearAllCheatStrings();

    // 0x801F0D48 (112 bytes)
    void SetCategoryCheatString(char* str, int index, char* value);

    // 0x801F0DB8 (68 bytes)
    void SetPageIdxCheatString(char* str, int index);

    // 0x801F0DFC (104 bytes)
    void SetFileNameCheatString(char* str, int index, char* value);

    // 0x801F0E64 (100 bytes)
    void SetCatalogNameCheatString(char* str, int index, unsigned short* name);

    // 0x801F0EFC (152 bytes)
    void SetAllObjectRelatedCheatStrings(ObjSelector* sel);

    // 0x801F0F94 (256 bytes)
    void SetAllObjectRelatedCheatStrings(InteractorModule::WallData* data);

    // 0x801F1094 (132 bytes)
    void SetAllObjectRelatedCheatStrings(InteractorModule::WallPaperData* data);

    // 0x801F1118 (132 bytes)
    void SetAllObjectRelatedCheatStrings(InteractorModule::FloorData* data);

    // 0x801F119C (88 bytes)
    void ClearAllObjRelatedCheatStrings();

    // 0x801F1254 (536 bytes)
    void FireCodeDialogSelectionCallback(int selection);

    // 0x801F1470 (76 bytes)
    void CannotGrabToInventoryDialogSelectionCallback(int selection);

    // 0x801F14EC (272 bytes)
    void PlaceModeCallbackImpl(InteractorModule::PlaceManipulator::CallbackData* data);

    // 0x801F1624 (592 bytes)
    void CommittChangesToInventory(InteractorModule::WallManipulator::CallbackData* data);

    // 0x801F1874 (256 bytes)
    void WallManipulatorCallbackImpl(InteractorModule::WallManipulator::CallbackData* data);

    // 0x801F199C (208 bytes)
    void CommittChangesToInventory(InteractorModule::WallPainter::CallbackData* data);

    // 0x801F1A6C (256 bytes)
    void WallPainterCallbackImpl(InteractorModule::WallPainter::CallbackData* data);

    // 0x801F1BBC (144 bytes)
    void FloorModeCallbackImpl(InteractorModule::FloorPainter::CallbackData* data);

    // 0x801F1C4C (400 bytes)
    void GrabModeCallbackImpl(InteractorModule::GrabManipulator::CallbackData* data);

    // 0x801F1E04 (444 bytes)
    void EnterPlaceAnyObjectModeUsingNewInteractorApi(ObjSelector* sel);

    // 0x801F1FC0 (440 bytes)
    void EnterGrabModeNewInteractorApi();

    // 0x801F2178 (504 bytes)
    void EnterPlaceModeUsingNewInteractorApi(ObjSelector* sel, unsigned char flags);

    // 0x801F23B0 (1848 bytes)
    void InstallInvVariables();

    // 0x801F2AE8 (2200 bytes)
    void InstallShpVariables();

    // 0x801F3380 (592 bytes)
    void AddObjSelectorToShopItemsDB(ObjSelector* sel);

    // 0x801F35D0 (440 bytes)
    void AddFloorTileToShopItemsDB(FloorTile* tile, int index);

    // 0x801F3788 (440 bytes)
    void AddWallPaperToShopItemsDB(WallTile* tile, int index);

    // 0x801F3940 (440 bytes)
    void AddWallToShopItemsDB(FenceData* fence, int index);

    // 0x801F3AF8 (840 bytes)
    void Cheat_BuildCatalogDB();

    // 0x801F3E40 (1580 bytes)
    void BuildLotShopDB();

    // 0x801F446C (88 bytes)
    void SetOnMsgInvCurrentTab(char* msg);

    // 0x801F44C4 (88 bytes)
    void SetOnMsgInvCurrentCell(char* msg);

    // 0x801F4584 (512 bytes)
    void SetOnMsgInvPrepareObjectInfo(char* msg);

    // 0x801F4798 (424 bytes)
    void SetOnMsgInvItemSelected(char* msg);

    // 0x801F4940 (96 bytes)
    void SetOnMsgInvGrabMode(char* msg);

    // 0x801F4AB8 (652 bytes)
    void SetOnMsgInvSellAllItems(char* msg);

    // 0x801F4D44 (648 bytes)
    void SetOnMsgInvSellOneItem(char* msg);

    // 0x801F5010 (228 bytes)
    void SetOnMsgInvShpPrepareObjectInfo(char* msg);

    // 0x801F50F4 (576 bytes)
    void PrepareObjectInfo(ObjSelector* sel, int index, bool flag, unsigned char param);

    // 0x801F5334 (184 bytes)
    void PrepareObjectInfo(InteractorModule::WallPaperData* data, int index, bool flag);

    // 0x801F53EC (184 bytes)
    void PrepareObjectInfo(InteractorModule::FloorData* data, int index, bool flag);

    // 0x801F54A4 (204 bytes)
    void PrepareObjectInfo(InteractorModule::WallData* data, int index, bool flag);

    // 0x801F5570 (260 bytes)
    void ClearAllObjectInfoData();

    // 0x801F5674 (152 bytes)
    void GetObjectRating(ObjSelector* sel, int& outRating1, int& outRating2);

    // 0x801F570C (404 bytes)
    void GetMotiveText(ObjSelector* sel, unsigned short* outStr);

    // 0x801F58A0 (104 bytes)
    void GetMotiveText(int index, unsigned short* outStr);

    // 0x801F5908 (396 bytes)
    void GetMotiveText(BBI::InventoryItem* item, unsigned short* outStr);

    // 0x801F5A94 (256 bytes)
    void GetMotiveText(int index, InteractorModule::ShoppingItem* item, unsigned short* outStr);

    // 0x801F5BA0 (136 bytes)
    void GetNumberOfBuildItemsToBuy(BBI::InventoryItem::eItemSubcategory subcat, int maxCount);

    // 0x801F5C28 (560 bytes)
    void SetOnMsgInvShpItemSelected(char* msg);

    // 0x801F5E58 (104 bytes)
    void SetOnMsgInvShpNextTab(char* msg);

    // 0x801F5EC0 (108 bytes)
    void SetOnMsgInvShpPrevTab(char* msg);

    // 0x801F5F2C (148 bytes)
    void SetOnMsgInvShpCurrentCategory(char* msg);

    // 0x801F5FC0 (212 bytes)
    void SetOnMsgInvShpSelectColor(char* msg);

    // 0x801F60D8 (144 bytes)
    void InstallShoppingObjectShaders(int count);

    // 0x801F6168 (236 bytes)
    void InstallWallPaperShaders(
        vector<InteractorModule::WallPaperData, allocator<InteractorModule::WallPaperData>>* data,
        int count);

    // 0x801F6254 (324 bytes)
    void InstallWallShaders(
        vector<InteractorModule::WallData, allocator<InteractorModule::WallData>>* data,
        int count);

    // 0x801F6398 (236 bytes)
    void InstallFloorTileShaders(
        vector<InteractorModule::FloorData, allocator<InteractorModule::FloorData>>* data,
        int count);

    // 0x801F6484 (236 bytes)
    void InstallObjListShaders(
        vector<ObjSelector*, allocator<ObjSelector*>>* data,
        int count);

    // 0x801F65C8 (240 bytes)
    void GetOnMsgInvSelectExitReset(char* msg);

    // 0x801F66F8 (68 bytes)
    void GetOnMsgInvObjectInfoReady(char* msg);

    // 0x801F6858 (248 bytes)
    void GetOnMsgInvShpItemCount(char* msg);

    // 0x801F6988 (256 bytes)
    void GetOnLocMsgInvShpObjectName(unsigned short* outStr);

    // 0x801F6A88 (128 bytes)
    void GetOnLocMsgInvShpObjectDescription(unsigned short* outStr);

    // 0x801F6B08 (152 bytes)
    void GetOnLocMsgInvShpBudget(unsigned short* outStr);

    // 0x801F6BA0 (84 bytes)
    void GetOnLocMsgInvMotiveText(unsigned short* outStr);

    // 0x801F6BF4 (104 bytes)
    void GetOnLocMsgInvShpMotiveText(unsigned short* outStr);

    // 0x801F6C5C (68 bytes)
    void GetOnMsgInvShpObjectInfoReady(char* msg);

    // 0x801F6CA0 (488 bytes)
    void GetSelectedShoppingItem(int index, InteractorModule::ShoppingItem& outItem, int& outIdx);

    // 0x801F6E88 (708 bytes)
    void GetOnMsgInvShpCanPurchase(char* msg);

    // 0x801F7150 (104 bytes)
    void GetOnMsgInvShpShpTabToInvTab(char* msg);

    // 0x801F71B8 (516 bytes)
    void GetOnMsgInvShpCanColor(char* msg);

    // 0x801F73BC (180 bytes)
    void GetOnMsgInvShpColorN(char* msg, int n);

    // 0x801F74A4 (68 bytes)
    void GetOnMsgInvShpCategoryCount(char* msg);

    // 0x801F74E8 (104 bytes)
    void GetOnMsgInvShpCategoryN(char* msg, int n);

    // 0x801F7550 (272 bytes)
    void ExitFloorTilingMode(bool commit);

    // 0x801F76A8 (636 bytes)
    void EnterWallBuildMode(InteractorModule::WallData* data, eInteractorMode mode);

    // 0x801F7924 (632 bytes)
    void EnterWallPaperingMode(InteractorModule::WallPaperData* data, eInteractorMode mode);

    // 0x801F7B9C (688 bytes)
    void EnterFloorTilingMode(InteractorModule::FloorData* data, eInteractorMode mode);

    // 0x801F7E4C (100 bytes)
    void IsPackagedItem(BBI::InventoryItem* item);

    // 0x801F7EB0 (108 bytes)
    void GetOnMsgInvShpIsPack(char* msg);

    // 0x801F7F1C (140 bytes)
    void GetOnMsgInvHelpMode(char* msg);

    // 0x801F7FE0 (68 bytes)
    void GetOnMsgInvBldDisplayInfo(char* msg);
};


class ActionMenu {
public:
    ActionMenu();
    void BackOutMenu();
};

extern ActionMenu* GetActionMenu(unsigned int);
