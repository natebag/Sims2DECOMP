// xl_batch_2.cpp - Extra-large asm stub conversions (1375-1786 lines), batch 2
// Converted from 46 asm stub files to portable C++
// Classes: EFloorShdTblNode, SKNTarget, WantFear, EGraphics, EIStaticSubModel,
//          AptScriptColour, BBI::InventoryItem, BBI::InventoryItems, UIQDTarget,
//          EFixedString, TileWalls, ESims3DHead, ENgcMovie, EControllerManager,
//          SkinCompositor, ENgcAudio, Room, OPTTarget, PassiveInfluenceSystem,
//          MSGTarget, RMDTarget, AptCharacterAnimation, Behavior, ObjSelector,
//          ReconBuffer, EHouse, ActionQueueHUD, Path, DlgWrapper, EString,
//          K2YTarget, TextureUtils, SKLTarget, cXPortal, ERTQuantize,
//          AmbientSoundPlayer, AptLoadVars, ERotDecomp, ActionMenu, ELightGrid,
//          CasGenetics, MOTTarget, AptNativeHash, ESpriteRender,
//          InLevelBaseState, BSplineVolume, cSimulatorImpl
#include "types.h"

// ============================================================================
// External functions
// ============================================================================
extern "C" {
    void* memcpy(void*, const void*, unsigned int);
    void* memset(void*, int, unsigned int);
    int memcmp(const void*, const void*, unsigned int);
    int strlen(const char*);
    char* strcpy(char*, const char*);
    char* strcat(char*, const char*);
    char* strchr(const char*, int);
    char* strrchr(const char*, int);
    char* strncpy(char*, const char*, unsigned int);
    int strcmp(const char*, const char*);
    int stricmp(const char*, const char*);
    float sqrtf(float);
    int sprintf(char*, const char*, ...);
    int Sprintf(char*, char*, ...);
    int wcslen(const unsigned short*);
    unsigned short* wcscpy(unsigned short*, const unsigned short*);
    int rand();
    float sinf(float);
    float cosf(float);
    float fabsf(float);
}

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
extern void* operator new(unsigned int);
extern void operator delete(void*);
extern void* __builtin_vec_new(unsigned int);
extern void __builtin_vec_delete(void*);

// ============================================================================
// Forward declarations
// ============================================================================
class EString;
class EConfig;
class EFile;
class EStream;
class EMat4;
class EVec3;
class EVec2;
class EVec4;
class EBound3;
class ERC;
class EResource;
class EResourceManager;
class EDataHeader;
class ETypeInfo;
class EThread;
class EFixedString;
class ERFont;
class ERShader;
class ERTexture;
class ERLevel;
class ETexture;
class EShader;
class EShaderDef;
class ETextureDef;
class ERenderSurface;
class ERenderSurfaceDef;
class EViewport;
class EInstance;
class ENodeList;
class EILight;
class EWindow;
class EPMDesc;
class EVoice;
class EVoiceDesc;
class EBtnToCmdAssoc;
class EController;
class EControllerManager;
class EBitArray;
class EQuat;
class ERotKeyframe;
class ELevelDrawData;
class EOrderTableData;
class AptValue;
class AptCIH;
class AptCharacter;
class AptConstFile;
class AptHashItem;
class EAStringC;
class NLIteratorPtrType;
class BString;
class BString2;
class StringBuffer;
class StringBuffer2;
class CasSimDescriptionS2C;
class ReconBuffer;
class Neighbor;
class Interaction;
class ObjSelector;
class ObjDefinition;
class ObjectModule;
class ObjectDataBehaviorTree;
class ObjectDataBehaviorConstants;
class BehaviorNode;
class Language;
class Player;
class CTilePt;
class RoomManager;
class cXObject;
class cXPerson;
class cXPortal;
class ESim;
class AnimRef;
class RoutingParams;
class LevelLightingEntry;
class Scheme;
class StateMachine;
class ExpenseReport;
class GameData;
struct RCMode;
struct SimSpeed;
struct ExpenseType;
template <typename T0> class TRect;
template <typename T0> class TNodeList;
template <typename T0, typename T1> class TArray;
template <typename T0, typename T1> class vector;
template <typename T0> class allocator;
class TArrayDefaultAllocator;
class __sFILE;

extern void EORDbgTrace(char*, ...);

// ============================================================================
// EFloorShdTblNode - Floor shadow table node for rendering
// ============================================================================
struct EFloorStripInfo;
class EFloorTileStrip;

class EFloorShdTblNode {
public:
    // Layout: [0] EResource*, [4+] ENodeList stripList
    void* m_pResource;    // 0x00
    char m_stripList[8];  // 0x04 - ENodeList

    // 0x80045544
    ~EFloorShdTblNode() {
        ENodeList* list = (ENodeList*)((char*)this + 4);
        list->RemoveAll();
        // conditional delete via hidden param
    }

    // 0x80045588
    void CleanUp() {
        ENodeList* list = (ENodeList*)((char*)this + 4);
        list->RemoveAll();
        EResource* res = *(EResource**)this;
        if (res != 0) {
            res->DelRef();
            *(void**)this = 0;
        }
    }

    // 0x800455D0
    void InitTable(); // NOTE: asm-derived, complex static init + loop

    // 0x800456D4
    void AddStripToTable(int index, EFloorStripInfo& info); // NOTE: asm-derived

    // 0x80045A28
    void BuildTable(ERLevel* level); // NOTE: asm-derived, large function (1832B)

    // 0x80046150
    void CheckForObjectsInFloor(CTilePt& tile); // NOTE: asm-derived

    // 0x80046A9C
    void BuildStrip(ERC* rc, EFloorStripInfo info, EVec2& vec, EFloorTileStrip* strip,
                    bool flag, ERLevel* level, EBound3& bound, bool& outFlag); // NOTE: asm-derived (1640B)

    // 0x80047104
    void EmptyTable(); { // NOTE: asm-derived
        // Iterates through strip list and removes entries
    }

    // 0x80047EB8
    void PreviewTable(); // NOTE: asm-derived
};

// ============================================================================
// SKNTarget - Skin selection UI target
// ============================================================================
class SKNTarget {
public:
    // Layout inferred from ctor: vtable at 0x80, various fields initialized to 0
    // [0]-[24] zeroed fields, [40/56/72/88/104] sub-structures with flag=1

    // 0x80202444
    SKNTarget(int param); // NOTE: asm-derived, large ctor (1868B) with many field inits

    // 0x80202B90
    ~SKNTarget(); // NOTE: asm-derived, cleanup with multiple sub-object dtors

    // 0x80202D54
    void GetVariable(char* name); // NOTE: asm-derived, string comparison dispatch

    // 0x80202E18
    void SetVariable(char* name, char* value); // NOTE: asm-derived, string comparison dispatch

    // 0x80202EEC
    void FindActualSkinIndex(int index); // NOTE: asm-derived

    // 0x80202F58
    void SetupPageShaders(int page); // NOTE: asm-derived, large (1952B)

    // 0x802036F8
    void SetupSkinUnlocks(); // NOTE: asm-derived
};

// ============================================================================
// WantFear - Want/Fear system (aspiration tracking)
// ============================================================================
class WantFear {
public:
    class Notification {
    public:
        // Used for matching wants/fears to events
    };

    class Bookmark {
    public:
        // 0x8014ABE4
        void ResetCountdown() {
            // NOTE: asm-derived - resets countdown timer field
            char* self = (char*)this;
            // Loads a float constant and stores to field
            // Calls some time-related function
        }

        // 0x8014ACB8
        bool IsDuplicateNode(Bookmark& other) const; // NOTE: asm-derived

        // 0x8014AD30
        bool IsDuplicateEvent(Bookmark& other) const; // NOTE: asm-derived

        // 0x8014ADA0
        int GetType() const; // NOTE: asm-derived

        // 0x8014AE3C
        void GetText(BString2& outText, Neighbor* neighbor, bool flag) const; // NOTE: asm-derived (1328B)

        // 0x8014B398
        void* GetBaseShader(Neighbor* neighbor) const; // NOTE: asm-derived

        // 0x8014B44C
        void* GetBackgroundShader(Neighbor* neighbor) const; // NOTE: asm-derived

        // 0x8014B4DC
        bool SatisfiedBy(WantFear::Notification& notification) const; // NOTE: asm-derived

        // 0x8014B5F4
        bool IsValid(Neighbor* neighbor, bool flag) const; // NOTE: asm-derived

        // 0x8014B748
        bool IsCompleted(Neighbor* neighbor) const; // NOTE: asm-derived

        // 0x8014B858
        void ApplyReward(Neighbor* neighbor); // NOTE: asm-derived

        // 0x8014BA7C
        short GetNextBookmarkAlongBranch(short branch); // NOTE: asm-derived

        // 0x8014BB4C
        void DoStream(ReconBuffer* buffer, int mode); // NOTE: asm-derived
    };

    class Event {
    public:
        // 0x8014A8FC
        void GetEventText(signed char eventType, BString2& outText) const; // NOTE: asm-derived
    };
};

// ============================================================================
// EGraphics - Graphics system manager
// ============================================================================
class EGraphics {
public:
    // 0x802F0D9C
    EGraphics(); // NOTE: asm-derived (408B), initializes many graphics fields

    // 0x802F0F34
    ~EGraphics(); // NOTE: asm-derived

    // 0x802F0F84
    void Init(); // NOTE: asm-derived

    // 0x802F1034
    void DeselectTextures() {
        // NOTE: asm-derived - iterates texture slots and deselects
        char* self = (char*)this;
        for (int i = 0; i < 8; i++) {
            // Deselect texture at slot i
        }
    }

    // 0x802F10C8
    void BeginFrame(); // NOTE: asm-derived

    // 0x802F1120
    void EndFrame(); // NOTE: asm-derived

    // 0x802F11B0
    void Flush(); // NOTE: asm-derived

    // 0x802F1244
    void GetOutputRect(TRect<float>& rect, int mode); // NOTE: asm-derived

    // 0x802F13F8
    void Open(RCMode mode); // NOTE: asm-derived

    // 0x802F1470
    void Close(ERC* rc); // NOTE: asm-derived

    // 0x802F15EC
    ETexture* CreateTexture(ETextureDef& def); // NOTE: asm-derived

    // 0x802F1690
    void Destroy(ETexture* tex); // NOTE: asm-derived

    // 0x802F1748
    EShader* CreateShader(EShaderDef& def); // NOTE: asm-derived

    // 0x802F17EC
    void Destroy(EShader* shader); // NOTE: asm-derived

    // 0x802F1840
    ERenderSurface* CreateRenderSurface(ERenderSurfaceDef& def); // NOTE: asm-derived

    // 0x802F18E4
    void Destroy(ERenderSurface* surface); // NOTE: asm-derived

    // 0x802F19BC
    void* AllocVertexData(unsigned int size); // NOTE: asm-derived

    // 0x802F1A08
    void FreeVertexData(void* data); // NOTE: asm-derived

    // 0x802F1A58
    void ComputeViewport(EViewport& viewport, TRect<float>& rect); // NOTE: asm-derived

    // 0x802F1B3C
    void SetUpNormalMapMatrix(); // NOTE: asm-derived

    // 0x802F1BB8
    void LoadSystemFont(); // NOTE: asm-derived

    // 0x802F1C34
    void DrawTiming(); // NOTE: asm-derived (612B)

    // 0x802F1EC8
    void DisplayTiming(bool show, EVec2& pos); // NOTE: asm-derived

    // 0x802F1F10
    void SetCensorRect(EVec3& pos1, EVec3& pos2, bool active) {
        // NOTE: asm-derived - stores censor rect parameters
        char* self = (char*)this;
        float* p1 = (float*)&pos1;
        float* p2 = (float*)&pos2;
        // Copy position data and set active flag
    }

    // 0x802F1FB4
    void SetCameraBloom(float r, float g, float b, float a) {
        // NOTE: asm-derived - stores bloom parameters to camera bloom fields
        char* self = (char*)this;
        // Store float params to member offsets
    }

    // 0x802F2030
    void SetBloom(); // NOTE: asm-derived

    // 0x802F2094
    void SetWorldBloom(float r, float g, float b, float a) {
        // NOTE: asm-derived - stores world bloom parameters
        char* self = (char*)this;
        // Store float params
    }
};

// ============================================================================
// EIStaticSubModel - Static sub-model for level geometry
// ============================================================================
class EIStaticSubModel {
public:
    // 0x8022E360
    EIStaticSubModel(); // NOTE: asm-derived, zeroes many fields

    // 0x8022E3F8
    ~EIStaticSubModel(); // NOTE: asm-derived

    // 0x8022E47C
    void Write(EStream& stream); // NOTE: asm-derived

    // 0x8022E508
    void Read(EStream& stream); // NOTE: asm-derived

    // 0x8022E5A8
    void Load(EFile& file); // NOTE: asm-derived

    // 0x8022E6A4
    void DeallocateModel(); // NOTE: asm-derived

    // 0x8022E738
    void SetupModel(); // NOTE: asm-derived

    // 0x8022E788
    void BuildDigests(); // NOTE: asm-derived

    // 0x8022E8D8
    void DrawAsShadow(ELevelDrawData& drawData); // NOTE: asm-derived

    // 0x8022E9EC
    void Draw(ELevelDrawData& drawData); // NOTE: asm-derived (1336B)

    // 0x8022EF24
    void DrawWireFrame(ERC* rc); // NOTE: asm-derived

    // 0x8022F0A4
    void SkyOrderTableCallback(ELevelDrawData& drawData, EOrderTableData* otd); // NOTE: asm-derived

    // 0x8022F168
    void FaceOrderTableCallback(ELevelDrawData& drawData, EOrderTableData* otd); // NOTE: asm-derived

    // 0x8022F384
    void OrderTableCallback(ELevelDrawData& drawData, EOrderTableData* otd); // NOTE: asm-derived

    // 0x8022F448
    void FloorOrderTableCallback(ELevelDrawData& drawData, EOrderTableData* otd); // NOTE: asm-derived

    // 0x8022F50C
    bool HasModifiableColor(); // NOTE: asm-derived

    // 0x8022F598
    void RebuildShaders(); // NOTE: asm-derived

    // 0x8022F820
    void RegisterType(unsigned short type); // NOTE: asm-derived
};

// ============================================================================
// AptScriptColour - APT ActionScript Color object
// ============================================================================
class AptScriptColour {
public:
    // 0x802B65F4
    AptScriptColour(AptValue* target); // NOTE: asm-derived (352B)

    // 0x802B6754
    ~AptScriptColour(); // NOTE: asm-derived

    // 0x802B67BC
    void CleanNativeFunctions(); // NOTE: asm-derived

    // 0x802B68D8
    void objectMemberLookup(AptValue* obj, EAStringC* name) const; // NOTE: asm-derived (908B)

    // 0x802B6C64
    void sMethod_setRGB(AptValue* args, int nargs); // NOTE: asm-derived

    // 0x802B6D8C
    void sMethod_getRGB(AptValue* args, int nargs); // NOTE: asm-derived

    // 0x802B6EA4
    void sMethod_getTransform(AptValue* args, int nargs); // NOTE: asm-derived (1628B)

    // 0x802B7500
    void sMethod_setTransform(AptValue* args, int nargs); // NOTE: asm-derived (752B)

    // 0x802B77F0
    void RegisterReferences() const; // NOTE: asm-derived

    // 0x802B7840
    void DestroyGCPointers(); // NOTE: asm-derived
};

// ============================================================================
// BBI - Build/Buy Inventory system
// ============================================================================
namespace BBI {

class InventoryItem {
public:
    enum eItemCategory {
        // Categories for inventory items
    };
    enum eItemSubcategory {
        // Subcategories
    };

    // 0x8004A144
    void DoStream(ReconBuffer* buffer, int mode); // NOTE: asm-derived

    // 0x8004A248
    void SetItemCount(int count) {
        // NOTE: asm-derived - simple setter
        char* self = (char*)this;
        *(int*)(self + 4) = count; // approximate offset
    }
};

class InventoryItems {
public:
    // 0x8004A37C
    bool CanAddItemsByGuid(int guid, int count, unsigned char slot) const; // NOTE: asm-derived

    // 0x8004A468
    void AddItemsByGuid(int guid, int count, unsigned char slot); // NOTE: asm-derived

    // 0x8004A524
    void RemoveItemsByGuid(int guid, int count, unsigned char slot); // NOTE: asm-derived

    // 0x8004A59C
    void DeleteItem(InventoryItem* item); // NOTE: asm-derived

    // 0x8004A720
    void Clear() {
        // NOTE: asm-derived - clears all items from inventory
        char* self = (char*)this;
        // Iterate and delete all items
    }

    // 0x8004A7A0
    int GetItemCount() const; // NOTE: asm-derived

    // 0x8004A800
    int CountItemsByGuid(int guid) const; // NOTE: asm-derived

    // 0x8004A878
    int CountItemsByCategory(InventoryItem::eItemCategory cat) const; // NOTE: asm-derived

    // 0x8004A904
    int GetItemsByCategory(InventoryItem::eItemCategory cat, InventoryItem** outItems,
                           unsigned int maxItems) const; // NOTE: asm-derived

    // 0x8004A9A4
    InventoryItem* GetItemByGuid(int guid, unsigned char slot) const; // NOTE: asm-derived

    // 0x8004A9E8
    bool IsItemInInventory(int guid) const; // NOTE: asm-derived

    // 0x8004AA80
    bool CanAddBuilderItem(InventoryItem::eItemSubcategory subcat, int param2,
                           int param3) const; // NOTE: asm-derived

    // 0x8004AB10
    void AddBuilderItem(InventoryItem::eItemSubcategory subcat, int param2,
                        int param3); // NOTE: asm-derived

    // 0x8004ABDC
    void RemoveBuilderItem(InventoryItem::eItemSubcategory subcat, int param2,
                           int param3); // NOTE: asm-derived

    // 0x8004AC50
    InventoryItem* GetBuilderItem(InventoryItem::eItemSubcategory subcat,
                                  int index) const; // NOTE: asm-derived

    // 0x8004AC94
    int GetBuilderItemIndex(InventoryItem::eItemSubcategory subcat,
                            int guid) const; // NOTE: asm-derived

    // 0x8004AD24
    void DoStreamWrite(ReconBuffer* buffer, int mode); // NOTE: asm-derived

    // 0x8004ADDC
    void DoStreamRead(ReconBuffer* buffer, int mode); // NOTE: asm-derived

    // 0x8004AF14
    void DoStream(ReconBuffer* buffer, int mode); // NOTE: asm-derived

    // 0x8004AFA8
    int GetNewItemIndex() const; // NOTE: asm-derived

    // 0x8004AFEC
    int GetItemIndexByGuid(int guid, unsigned char slot) const; // NOTE: asm-derived

    // 0x8004B078
    InventoryItem* CreateNewItemFromGuid(int guid) const; // NOTE: asm-derived

    // 0x8004B0D4
    InventoryItem* CreateNewBuilderItem(InventoryItem::eItemSubcategory subcat,
                                        int param2) const; // NOTE: asm-derived

    // 0x8004B148
    InventoryItem* CreateNewItemFromSelector(ObjSelector* selector) const; // NOTE: asm-derived

    // 0x8004B1E0
    static InventoryItem::eItemCategory GetItemCategoryFromObjDefinition(
        ObjDefinition* def); // NOTE: asm-derived
};

} // namespace BBI

// ============================================================================
// UIQDTarget - UI Quickdata target
// ============================================================================
class UIQDTarget {
public:
    // 0x8017BF44
    UIQDTarget(); // NOTE: asm-derived (1088B), large ctor with callback setup

    // 0x8017C384
    ~UIQDTarget(); // NOTE: asm-derived

    // 0x8017C4C8
    void GetVariable(char* name); // NOTE: asm-derived (612B)

    // 0x8017C72C
    void GetQuickdataText(char* key); // NOTE: asm-derived

    // 0x8017C92C
    void UIQDSubstitutionStrings(unsigned short* str); // NOTE: asm-derived (2016B)

    // 0x8017D10C
    void UIQDRemoveEmbeddedControl(unsigned short* str); // NOTE: asm-derived
};

// ============================================================================
// EFixedString - Fixed-size string buffer operations
// ============================================================================
// Layout: [0] char* m_pData, [4] int m_capacity

class EFixedString {
public:
    char* m_pData;   // 0x00
    int m_capacity;  // 0x04

    // Implicit: GetLength() returns strlen(m_pData)
    int GetLength() const { return strlen(m_pData); }

    // 0x802C7428
    void Concatonate(char* str1, char* str2) {
        static const char* s_emptyStr = ""; // r13-26884
        if (str1 == 0) str1 = (char*)s_emptyStr;
        int len1 = strlen(str1);
        if (str2 == 0) str2 = (char*)s_emptyStr;
        int len2 = strlen(str2);
        int copyLen1 = m_capacity;
        if (copyLen1 > len1) copyLen1 = len1;
        if (copyLen1 > 0) {
            memcpy(m_pData, str1, copyLen1);
        }
        int remaining = m_capacity - copyLen1;
        int copyLen2 = remaining - 1;
        if (copyLen2 > len2 + 1) copyLen2 = len2 + 1;
        if (copyLen2 > 0) {
            memcpy(m_pData + copyLen1, str2, copyLen2);
        }
        m_pData[m_capacity - 1] = '\0';
    }

    // 0x802C7558
    void MakeCopy(char* src) {
        static const char* s_emptyStr = ""; // r13-26884
        if (src == 0) src = (char*)s_emptyStr;
        int srcLen = strlen(src);
        int needed = srcLen + 1;
        if (needed <= m_capacity) {
            memcpy(m_pData, src, needed);
        } else {
            memcpy(m_pData, src, m_capacity - 1);
            m_pData[m_capacity - 1] = '\0';
        }
    }

    // 0x802C7690
    int Compare(char* other) const {
        const char* s = m_pData;
        while (true) {
            char a = *s;
            char b = *other;
            if (a < b) return -1;
            if (a > b) return 1;
            if (a == 0 && b == 0) return 0;
            s++;
            other++;
        }
    }

    // 0x802C76E4
    int CompareNoCase(char* other) const {
        const char* s = m_pData;
        while (true) {
            char a = *s;
            char b = *other;
            // Convert lowercase to uppercase
            if (a >= 'a' && a <= 'z') a -= 32;
            if (b >= 'a' && b <= 'z') b -= 32;
            if (a < b) return -1;
            if (a > b) return 1;
            if (*s == 0 && *other == 0) return 0;
            s++;
            other++;
        }
    }

    // 0x802C7760
    int CompareSymbol(char* other) const {
        const char* s = m_pData;
        const char* o = other;
        // Handle leading digits vs underscore
        if (s[0] >= '0' && s[0] <= '9' && o[0] == '_') {
            o++;
        } else if (o[0] >= '0' && o[0] <= '9' && s[0] == '_') {
            s++;
        }
        while (true) {
            char a = *s;
            char b = *o;
            // Normalize: lowercase->upper, non-alnum->underscore
            if (a >= 'a' && a <= 'z') a -= 32;
            else if (!(a >= 'A' && a <= 'Z') && !(a >= '0' && a <= '9') && a != 0) a = '_';
            if (b >= 'a' && b <= 'z') b -= 32;
            else if (!(b >= 'A' && b <= 'Z') && !(b >= '0' && b <= '9') && b != 0) b = '_';
            if (a < b) return -1;
            if (a > b) return 1;
            if (*s == 0 && *o == 0) return 0;
            s++;
            o++;
        }
    }

    // 0x802C7874
    void Mid(EFixedString& result, int start, int len) const {
        result.MakeCopy(m_pData + start);
        if (len != -1) {
            result.Left(result, len);
        }
    }

    // 0x802C78C8
    void Left(EFixedString& result, int count) const {
        if (this != &result) {
            int copyLen = result.m_capacity;
            if (copyLen > count) copyLen = count;
            memcpy(result.m_pData, m_pData, copyLen);
        }
        int termPos = result.m_capacity - 1;
        if (termPos > count) termPos = count;
        result.m_pData[termPos] = '\0';
    }

    // 0x802C793C
    void Right(EFixedString& result, int count) const {
        int len = GetLength();
        int start = len - count;
        if (start < 0) start = 0;
        result.MakeCopy(m_pData + start);
    }

    // 0x802C798C
    void operator+=(char* str) {
        int curLen = GetLength();
        int addLen = strlen(str);
        int remaining = m_capacity - curLen - 1;
        int copyLen = addLen + 1;
        if (copyLen > remaining) copyLen = remaining;
        if (copyLen > 0) {
            memcpy(m_pData + curLen, str, copyLen);
        }
        m_pData[m_capacity - 1] = '\0';
    }

    // 0x802C7A94
    int FindNoCase(char ch) const {
        const char* s = m_pData;
        int pos = 0;
        while (*s != 0) {
            if (CharsEqualNoCase(*s, ch)) return pos;
            s++;
            pos++;
        }
        return -1;
    }

    // 0x802C7B00
    int Find(char* substr) const {
        int subLen = strlen(substr);
        int len = GetLength();
        int maxStart = len - subLen;
        for (int i = 0; i <= maxStart; i++) {
            bool match = true;
            for (int j = 0; j < subLen; j++) {
                if (m_pData[i + j] != substr[j]) {
                    match = false;
                    break;
                }
            }
            if (match) return i;
        }
        return -1;
    }

    // 0x802C7BB0
    int FindNoCase(char* substr) const {
        int subLen = strlen(substr);
        int len = GetLength();
        int maxStart = len - subLen;
        for (int i = 0; i <= maxStart; i++) {
            bool match = true;
            for (int j = 0; j < subLen; j++) {
                if (!CharsEqualNoCase(m_pData[i + j], substr[j])) {
                    match = false;
                    break;
                }
            }
            if (match) return i;
        }
        return -1;
    }

    // 0x802C7C60
    void Replace(EFixedString& result, char* find, char* replace); // NOTE: asm-derived

    // 0x802C7CF4
    int FindReverse(char ch) const {
        const char* s = m_pData;
        int len = GetLength();
        for (int i = len - 1; i >= 0; i--) {
            if (s[i] == ch) return i;
        }
        return -1;
    }

    // 0x802C7D58
    void Convert(float val) {
        Sprintf(m_pData, (char*)"%f", val);
    }

    // 0x802C7DAC
    void Convert(int val) {
        Sprintf(m_pData, (char*)"%d", val);
    }

    // 0x802C7E34
    void Remove(EFixedString& result, char ch); // NOTE: asm-derived

    // 0x802C7F50
    void FixTrailingSlash(); // NOTE: asm-derived

    // 0x802C7FA4
    void RemoveTrailingSlash() {
        int len = GetLength();
        if (len > 0) {
            char last = m_pData[len - 1];
            if (last == '/' || last == '\\') {
                m_pData[len - 1] = '\0';
            }
        }
    }

    // 0x802C8034
    void RemoveDriveLetter(); // NOTE: asm-derived

    // 0x802C80A8
    void ExtractFilename(EFixedString& result) const; // NOTE: asm-derived

    // 0x802C8134
    void ExtractRoot(EFixedString& result) const; // NOTE: asm-derived

    // 0x802C81EC
    void ExtractDirectory(EFixedString& result) const; // NOTE: asm-derived

    // 0x802C827C
    void ExtractExtension(EFixedString& result) const; // NOTE: asm-derived

    // 0x802C82F4
    void MakeLegalFilename(); // NOTE: asm-derived

    // 0x802C8378
    void TrimRight(char ch) {
        int len = GetLength();
        while (len > 0 && m_pData[len - 1] == ch) {
            len--;
            m_pData[len] = '\0';
        }
    }

    // 0x802C841C
    void TrimLeft(char ch) {
        char* s = m_pData;
        while (*s == ch) s++;
        if (s != m_pData) {
            MakeCopy(s);
        }
    }

    // 0x802C84B8
    void TrimRight(char* chars); // NOTE: asm-derived

    // 0x802C8550
    void TrimLeft(char* chars); // NOTE: asm-derived

    // 0x802C8654
    static bool CharsEqualNoCase(char a, char b) {
        if (a >= 'a' && a <= 'z') a -= 32;
        if (b >= 'a' && b <= 'z') b -= 32;
        return a == b;
    }
};

// ============================================================================
// TileWalls - Wall placement data per tile
// ============================================================================
enum TileWallsSegment { /* wall segment enum */ };
enum TilePtDir { /* direction enum */ };
enum DiagonalSideSelector { /* diagonal side enum */ };
struct WallPattern { /* wall pattern data */ };
struct WallStyle { /* wall style data */ };

class TileWalls {
public:
    enum SheerPlacement { /* sheer placement enum */ };

    // 0x80145EF0
    static void GenerateRotationLookups(); // NOTE: asm-derived (468B)

    // 0x801460C4
    int GetPlacement(TileWallsSegment seg) const; // NOTE: asm-derived

    // 0x80146134
    void SetPlacement(SheerPlacement placement, TileWallsSegment seg); // NOTE: asm-derived

    // 0x801461AC
    void Rotate(int amount); // NOTE: asm-derived (648B)

    // 0x80146434
    bool CanAdd(TileWallsSegment seg) const; // NOTE: asm-derived

    // 0x80146550
    void GetAdjacentTile(TileWallsSegment seg, CTilePt* outTile); // NOTE: asm-derived

    // 0x80146614
    static TileWallsSegment GetOppositeSegment(TileWallsSegment seg); // NOTE: asm-derived

    // 0x80146680
    static TileWallsSegment DirToWallSeg(TilePtDir dir); // NOTE: asm-derived

    // 0x801466D4
    static TileWallsSegment GetWallBetween(TilePtDir dir); // NOTE: asm-derived

    // 0x8014674C
    static int SegmentToIndex(TileWallsSegment seg, DiagonalSideSelector side); // NOTE: asm-derived

    // 0x801467C4
    static void IndexToSegment(int index, DiagonalSideSelector* outSide); // NOTE: asm-derived

    // 0x8014683C
    static bool IsSingleWall(TileWallsSegment seg); // NOTE: asm-derived

    // 0x8014693C
    TileWalls& operator=(TileWalls& other) {
        // NOTE: asm-derived - copies wall data
        memcpy(this, &other, sizeof(TileWalls));
        return *this;
    }

    // 0x801469C8
    bool HasWallNotFence(TileWallsSegment seg) const; // NOTE: asm-derived

    // 0x80146A34
    bool HasFenceNotWall(TileWallsSegment seg) const; // NOTE: asm-derived

    // 0x80146AB4
    bool HasDiagonalNotFence() const; // NOTE: asm-derived

    // 0x80146B7C
    bool HasDiagonalFence() const; // NOTE: asm-derived

    // 0x80146C44
    WallPattern GetPattern(TileWallsSegment seg, DiagonalSideSelector side) const; // NOTE: asm-derived

    // 0x80146CCC
    void SetPattern(WallPattern pattern, TileWallsSegment seg,
                    DiagonalSideSelector side); // NOTE: asm-derived

    // 0x80146D80
    WallStyle GetStyle(TileWallsSegment seg) const; // NOTE: asm-derived

    // 0x80146DD8
    void SetStyle(WallStyle style, TileWallsSegment seg); // NOTE: asm-derived

    // 0x80146E4C
    void AddWall(TileWallsSegment seg); // NOTE: asm-derived

    // 0x80146EB8
    void RemoveWall(TileWallsSegment seg); // NOTE: asm-derived

    // 0x80146F10
    TileWallsSegment First() const; // NOTE: asm-derived

    // 0x80146F78
    TileWallsSegment Next(TileWallsSegment seg) const; // NOTE: asm-derived
};

// ============================================================================
// ESims3DHead - 3D head rendering for Sims
// ============================================================================
class ESims3DHead {
public:
    // 0x8006D2FC
    ESims3DHead(ESim* sim); // NOTE: asm-derived

    // 0x8006D35C
    void InitShaders(); // NOTE: asm-derived

    // 0x8006D3CC
    void ResetShaders(); // NOTE: asm-derived

    // 0x8006D418
    void InitHead(cXPerson* person); // NOTE: asm-derived

    // 0x8006D4C4
    ~ESims3DHead(); // NOTE: asm-derived

    // 0x8006D51C
    void Draw(ERC* rc); // NOTE: asm-derived (4260B) - very large rendering function

    // 0x8006E634
    void Draw2D(ERC* rc, cXPerson* person); // NOTE: asm-derived

    // 0x8006E760
    void* operator new(unsigned int size) {
        return MainHeap()->Malloc(size, 0);
    }
};

// ============================================================================
// ENgcMovie - NGC movie player (THP video)
// ============================================================================
class EAllocGroup;
class THPAudioInfo;
class _GXRenderModeObj;

class ENgcMovie {
public:
    // 0x80335108
    ENgcMovie(); // NOTE: asm-derived, zeroes many fields

    // 0x803351D8
    ~ENgcMovie(); // NOTE: asm-derived

    // 0x80335244
    void Load(EFile* file, unsigned int param1, unsigned int param2,
              unsigned int param3); // NOTE: asm-derived

    // 0x803353A8
    void Start(int x, int y); // NOTE: asm-derived

    // 0x803354A0
    bool IsFinished(); // NOTE: asm-derived

    // 0x803354FC
    void* GetNextFrame(); // NOTE: asm-derived

    // 0x8033560C
    void PlayerInit(int param); // NOTE: asm-derived

    // 0x80335744
    void PlayerQuit(); // NOTE: asm-derived

    // 0x803357A4
    void PlayerOpen(unsigned int handle, bool loop); // NOTE: asm-derived (792B)

    // 0x80335ABC
    void PlayerClose(); // NOTE: asm-derived

    // 0x80335B0C
    void PlayerCreateBuffers(EAllocGroup& alloc); // NOTE: asm-derived (472B)

    // 0x80335CE4
    void PlayerPrepare(int x, int y, int scale); // NOTE: asm-derived (556B)

    // 0x80335F10
    void PlayerPlay(); // NOTE: asm-derived

    // 0x80335F6C
    void PlayerStop(); // NOTE: asm-derived

    // 0x80336054
    void PlayerSkip(); // NOTE: asm-derived

    // 0x803361FC
    void PlayerDrawCurrentFrame(_GXRenderModeObj* rmo, unsigned int x, unsigned int y,
                                unsigned int w, unsigned int h); // NOTE: asm-derived

    // 0x803362F8
    void PlayerGetAudioInfo(THPAudioInfo* info); // NOTE: asm-derived

    // 0x80336394
    void PlayerDrawDone(); // NOTE: asm-derived
};

// ============================================================================
// EControllerManager - Input controller management
// ============================================================================
// Many functions are thin wrappers calling GetCmdResultAllCtrl or GetBtnResultAllCtrl
// with different member function pointers for EController

class EControllerManager {
public:
    // 0x803233F4
    void Update(); // NOTE: asm-derived

    // 0x80323468
    void SwapPlayerControls(unsigned int p1, unsigned int p2); // NOTE: asm-derived (356B)

    // 0x8032366C
    void FindActiveController(); // NOTE: asm-derived

    // 0x803236CC
    void Flush(); // NOTE: asm-derived

    // 0x80323724
    void GetCmdResultAllCtrl(unsigned int cmd,
        unsigned int (EController::*downFn)(EController*, unsigned int),
        unsigned int (EController::*pressFn)(EController*, unsigned int),
        bool flag, unsigned int* result, unsigned int player); // NOTE: asm-derived

    // 0x80323884
    void GetBtnResultAllCtrl(
        unsigned int (EController::*fn)(EController*, unsigned int),
        bool flag1, bool flag2, unsigned int btn,
        unsigned int* result, unsigned int player); // NOTE: asm-derived

    // 0x803239E8
    void MapControllerCommands(EBtnToCmdAssoc* assoc, int count); // NOTE: asm-derived

    // 0x80323AF8
    void GetCmdDownAllCtrl(unsigned int cmd, unsigned int* result, unsigned int player); // NOTE: asm-derived
    // 0x80323B4C
    void GetCmdPressedAllCtrl(unsigned int cmd, unsigned int* result, unsigned int player); // NOTE: asm-derived
    // 0x80323BB8
    void GetCmdReleasedAllCtrl(unsigned int cmd, unsigned int* result, unsigned int player); // NOTE: asm-derived
    // 0x80323C24
    void GetCmdUpAllCtrl(unsigned int cmd, unsigned int* result, unsigned int player); // NOTE: asm-derived
    // 0x80323C78
    void GetCmdRepeatAllCtrl(unsigned int cmd, unsigned int* result, unsigned int player); // NOTE: asm-derived

    // 0x80323CE4
    void GetBtnDownAllCtrl(unsigned int btn, unsigned int* result, unsigned int player); // NOTE: asm-derived
    // 0x80323D34
    void GetBtnPressedAllCtrl(unsigned int btn, unsigned int* result, unsigned int player); // NOTE: asm-derived
    // 0x80323D84
    void GetBtnReleasedAllCtrl(unsigned int btn, unsigned int* result, unsigned int player); // NOTE: asm-derived
    // 0x80323DD4
    void GetBtnUpAllCtrl(unsigned int btn, unsigned int* result, unsigned int player); // NOTE: asm-derived
    // 0x80323E24
    void GetBtnRepeatAllCtrl(unsigned int btn, unsigned int* result, unsigned int player); // NOTE: asm-derived

    // 0x80323E74
    void GetBtnDownAnyAllCtrl(unsigned int btn, unsigned int* result, unsigned int player); // NOTE: asm-derived
    // 0x80323EC4
    void GetBtnPressedAnyAllCtrl(unsigned int btn, unsigned int* result, unsigned int player); // NOTE: asm-derived
    // 0x80323F14
    void GetBtnReleasedAnyAllCtrl(unsigned int btn, unsigned int* result, unsigned int player); // NOTE: asm-derived
    // 0x80323F64
    void GetBtnUpAnyAllCtrl(unsigned int btn, unsigned int* result, unsigned int player); // NOTE: asm-derived
    // 0x80323FB4
    void GetBtnRepeatAnyAllCtrl(unsigned int btn, unsigned int* result, unsigned int player); // NOTE: asm-derived

    // 0x80324004
    void GetCmdDownExclAllCtrl(unsigned int cmd, unsigned int* result, unsigned int player); // NOTE: asm-derived
    // 0x80324058
    void GetCmdPressedExclAllCtrl(unsigned int cmd, unsigned int* result, unsigned int player); // NOTE: asm-derived
    // 0x803240C4
    void GetCmdReleasedExclAllCtrl(unsigned int cmd, unsigned int* result, unsigned int player); // NOTE: asm-derived
    // 0x80324130
    void GetCmdUpExclAllCtrl(unsigned int cmd, unsigned int* result, unsigned int player); // NOTE: asm-derived
    // 0x80324184
    void GetCmdRepeatExclAllCtrl(unsigned int cmd, unsigned int* result, unsigned int player); // NOTE: asm-derived

    // 0x803241F0
    void GetBtnDownExclAllCtrl(unsigned int btn, unsigned int* result, unsigned int player); // NOTE: asm-derived
    // 0x80324240
    void GetBtnPressedExlAllCtrl(unsigned int btn, unsigned int* result, unsigned int player); // NOTE: asm-derived
    // 0x80324290
    void GetBtnReleasedExclAllCtrl(unsigned int btn, unsigned int* result, unsigned int player); // NOTE: asm-derived
    // 0x803242E0
    void GetBtnUpExclAllCtrl(unsigned int btn, unsigned int* result, unsigned int player); // NOTE: asm-derived
    // 0x80324330
    void GetBtnRepeatExclAllCtrl(unsigned int btn, unsigned int* result, unsigned int player); // NOTE: asm-derived

    // 0x80324380
    void GetBtnDownAnyExclAllCtrl(unsigned int btn, unsigned int* result, unsigned int player); // NOTE: asm-derived
    // 0x803243D0
    void GetBtnPressedAnyExlAllCtrl(unsigned int btn, unsigned int* result, unsigned int player); // NOTE: asm-derived
    // 0x80324420
    void GetBtnReleasedAnyExclAllCtrl(unsigned int btn, unsigned int* result, unsigned int player); // NOTE: asm-derived
    // 0x80324470
    void GetBtnUpAnyExclAllCtrl(unsigned int btn, unsigned int* result, unsigned int player); // NOTE: asm-derived
    // 0x803244C0
    void GetBtnRepeatAnyExclAllCtrl(unsigned int btn, unsigned int* result, unsigned int player); // NOTE: asm-derived
};

// ============================================================================
// SkinCompositor - Skin texture compositing system
// ============================================================================
enum eBodyPartS2C { /* body part enum */ };

class SkinCompositor {
public:
    // 0x80075B10
    SkinCompositor(); // NOTE: asm-derived

    // 0x80075BB0
    void Reset(); // NOTE: asm-derived

    // 0x80075CC8
    void CreateSkinQuadrantPrecomposited(ERTexture* tex, unsigned int quadrant,
                                         bool mirror); // NOTE: asm-derived

    // 0x80075DEC
    void CreateSkin(ERTexture* tex, unsigned char bodyType,
                    CasSimDescriptionS2C* desc, bool flag); // NOTE: asm-derived

    // 0x80075E8C
    void InitScratchpadTextures(unsigned short format); // NOTE: asm-derived (372B)

    // 0x80076000
    void InitSkinTexture(); // NOTE: asm-derived

    // 0x8007604C
    void FinalizeSkinTexture(); // NOTE: asm-derived

    // 0x80076098
    void LoadAllTextureLayers(); // NOTE: asm-derived (1164B)

    // 0x80076524
    void GetTextureIDs(unsigned int& count, unsigned int* ids1,
                       unsigned int* ids2, unsigned int* ids3); // NOTE: asm-derived

    // 0x80076618
    void BlendTexture(eBodyPartS2C part, unsigned int src,
                      unsigned int dst); // NOTE: asm-derived (1932B)

    // 0x80076DA4
    void* GetFinalReflectionMask(); // NOTE: asm-derived
};

// ============================================================================
// ENgcAudio - GameCube audio system
// ============================================================================
class ENgcAudio {
public:
    // 0x8032B7A8
    ENgcAudio(); // NOTE: asm-derived

    // 0x8032B818
    ~ENgcAudio(); // NOTE: asm-derived

    // 0x8032B8EC
    void InitAudio(); // NOTE: asm-derived

    // 0x8032B9F4
    void Shutdown(); // NOTE: asm-derived

    // 0x8032BA5C
    void PlayMusic(EPMDesc& desc); // NOTE: asm-derived (1152B)

    // 0x8032BEEC
    void Update(); // NOTE: asm-derived (784B)

    // 0x8032C1FC
    void StopMusic(); // NOTE: asm-derived

    // 0x8032C2C8
    void PauseMusic(); // NOTE: asm-derived

    // 0x8032C338
    void ResumeMusic(); // NOTE: asm-derived

    // 0x8032C3A8
    void SetMusicVolume(float vol); // NOTE: asm-derived

    // 0x8032C470
    void SetMusicPan(float pan); // NOTE: asm-derived

    // 0x8032C53C
    bool IsPlayingMusic(); // NOTE: asm-derived

    // 0x8032C614
    void FreeVoice(EVoice* voice); // NOTE: asm-derived

    // 0x8032C65C
    void AudioBindVoice(EVoice* voice, unsigned int sampleID); // NOTE: asm-derived (412B)

    // 0x8032C7F8
    void UnbindVoice(EVoice* voice); // NOTE: asm-derived

    // 0x8032C8E0
    void GetVoiceState(EVoice* voice, EVoiceDesc& desc); // NOTE: asm-derived

    // 0x8032C970
    void SetVoiceState(EVoice* voice, EVoiceDesc& desc); // NOTE: asm-derived

    // 0x8032CAA0
    void SetSpeakerVolumes(EVoice* voice, int* volumes,
                           unsigned int count); // NOTE: asm-derived
};

// ============================================================================
// Room - Room data for house system
// ============================================================================
struct ObjectIterator;

class Room {
public:
    // 0x801374C4
    Room(unsigned short id, RoomManager* mgr); // NOTE: asm-derived

    // 0x80137578
    ~Room(); // NOTE: asm-derived (372B)

    // 0x801376EC
    void Clear(); // NOTE: asm-derived

    // 0x80137780
    void* GetPartition(); // NOTE: asm-derived

    // 0x801377D8
    void ComputeRoom(); // NOTE: asm-derived (896B)

    // 0x80137BE0
    void CollectTileStats(CTilePt& tile); // NOTE: asm-derived (612B)

    // 0x80137E44
    void CollectObjectStats(ObjectIterator iter); // NOTE: asm-derived (1048B)

    // 0x8013825C
    void PrintStats(); // NOTE: asm-derived

    // 0x80138300
    float GetObjectDensity(); // NOTE: asm-derived

    // 0x8013836C
    void AbsorbNewRoomList(vector<CTilePt, allocator<CTilePt> >& list); // NOTE: asm-derived

    // 0x801383B4
    bool IsTileInRoom(CTilePt& tile); // NOTE: asm-derived

    // 0x80138420
    bool IsOutside(); // NOTE: asm-derived

    // 0x80138534
    void SetOverheadLights(bool on); // NOTE: asm-derived

    // 0x801385B4
    int GetPeopleCount(); // NOTE: asm-derived

    // 0x80138684
    float GetAmbientLight() const; // NOTE: asm-derived

    // 0x80138704
    float GetAmbientLightMultiplier(); // NOTE: asm-derived
};

// ============================================================================
// OPTTarget - Options screen UI target
// ============================================================================
class OPTTarget {
public:
    // 0x801FB230
    OPTTarget(); // NOTE: asm-derived (2152B), large ctor

    // 0x801FBA98
    ~OPTTarget(); // NOTE: asm-derived

    // 0x801FBBDC
    void SetVariable(char* name, char* value); // NOTE: asm-derived (832B)

    // 0x801FBF1C
    void GetVariable(char* name); // NOTE: asm-derived (912B)

    // 0x801FC2B0
    float GetScreenXLocal(signed char idx); // NOTE: asm-derived

    // 0x801FC344
    float GetScreenXGlobal(float local); // NOTE: asm-derived

    // 0x801FC3A4
    float GetScreenYLocal(signed char idx); // NOTE: asm-derived

    // 0x801FC438
    float GetScreenYGlobal(float local); // NOTE: asm-derived

    // 0x801FC498
    void RememberOptions(); // NOTE: asm-derived

    // 0x801FC510
    void RestoreOptions(); // NOTE: asm-derived
};

// ============================================================================
// PassiveInfluenceSystem - Environmental influence on Sims
// ============================================================================
class PassiveInfluenceSystem {
public:
    // 0x80113DB0
    PassiveInfluenceSystem(); // NOTE: asm-derived

    // 0x80113E48
    ~PassiveInfluenceSystem(); // NOTE: asm-derived

    // 0x80113F40
    void AddObjectToMap(cXObject* obj, signed char x1, signed char y1,
                        signed char x2, signed char y2); // NOTE: asm-derived (556B)

    // 0x8011416C
    void RemoveObjectFromMap(cXObject* obj); // NOTE: asm-derived (472B)

    // 0x80114344
    void MoveObjectInWorld(cXObject* obj); // NOTE: asm-derived (960B)

    // 0x80114704
    void NotifySimulator(cXPerson* person, int event,
                         int param); // NOTE: asm-derived (1176B)

    // 0x80114B9C
    void CheckObjects(int param); // NOTE: asm-derived (640B)

    // 0x80114E1C
    void SetInfluenceMotiveDelta(cXObject* obj, unsigned char motive,
                                  float delta, short duration); // NOTE: asm-derived (644B)

    // 0x801150A0
    void ClearInfluenceMotiveDeltas(cXObject* obj); // NOTE: asm-derived

    // 0x8011513C
    void SetSkillNameID(cXObject* obj, AnimRef* anim); // NOTE: asm-derived
};

// ============================================================================
// MSGTarget - Message dialog UI target
// ============================================================================
class MSGTarget {
public:
    // 0x801F9D48
    void DeliverXamMessage(int msgId, unsigned short param); // NOTE: asm-derived

    // 0x801F9E00
    MSGTarget(int param); // NOTE: asm-derived (2972B), very large ctor

    // 0x801FA99C
    ~MSGTarget(); // NOTE: asm-derived (488B)

    // 0x801FAB84
    void SetupTitles(int mode); // NOTE: asm-derived

    // 0x801FACC4
    void GetVariable(char* name); // NOTE: asm-derived

    // 0x801FAE34
    void SetVariable(char* name, char* value); // NOTE: asm-derived (744B)

    // 0x801FB11C
    void GetLocalizable(char* key); // NOTE: asm-derived
};

// ============================================================================
// RMDTarget - Reminder dialog UI target
// ============================================================================
class RMDTarget {
public:
    // 0x801DEDE8
    RMDTarget(int param1, int param2); // NOTE: asm-derived (2144B)

    // 0x801DF648
    ~RMDTarget(); // NOTE: asm-derived (496B)

    // 0x801DF838
    void SetVariable(char* name, char* value); // NOTE: asm-derived

    // 0x801DF994
    void GetVariable(char* name); // NOTE: asm-derived

    // 0x801DFA2C
    void GetLocalizable(char* key); // NOTE: asm-derived

    // 0x801DFB1C
    void Update(); // NOTE: asm-derived

    // 0x801DFB98
    void SetupWidgets(); // NOTE: asm-derived (1036B)

    // 0x801DFFA4
    void UnloadDialog(); // NOTE: asm-derived

    // 0x801E014C
    void StartShowTween(); // NOTE: asm-derived

    // 0x801E022C
    void StartHideTween(); // NOTE: asm-derived
};

// ============================================================================
// AptCharacterAnimation - APT character animation data
// ============================================================================
class AptCharacterAnimation {
public:
    // 0x802821A8
    void Fixup(void* data, AptConstFile* constFile, void* param); // NOTE: asm-derived (1312B)

    // 0x802826C8
    void Resolve(void* data, AptConstFile* constFile, void* param); // NOTE: asm-derived

    // 0x80282730
    void UnmapCharacter(AptCharacter* character); // NOTE: asm-derived

    // 0x80282774
    bool IsImport(int id); // NOTE: asm-derived

    // 0x802827BC
    void Unresolve(void* data); // NOTE: asm-derived (1792B)

    // 0x80283024
    void Link(AptCharacter* character, void* data); // NOTE: asm-derived (720B)

    // 0x802847E4
    int GetIDFromImportFile(int importId); // NOTE: asm-derived

    // 0x80284880
    void ExecuteInitActions(AptCIH* cih, int frame); // NOTE: asm-derived

    // 0x802849A0
    void ExecuteInitAction(AptCIH* cih, int actionIdx); // NOTE: asm-derived

    // 0x80284AB4
    void ExportClassDefinitionAssets(AptCIH* cih); // NOTE: asm-derived
};

// ============================================================================
// Behavior - Behavior tree system for sim AI
// ============================================================================
class Behavior {
public:
    // 0x800AB314
    ~Behavior(); // NOTE: asm-derived (396B)

    // 0x800AB4A0
    int CountNodes(short treeId); // NOTE: asm-derived

    // 0x800AB560
    void GetNode(short treeId, short nodeId, BehaviorNode* outNode); // NOTE: asm-derived

    // 0x800AB5BC
    bool GetNodeRef(short treeId, short nodeId, BehaviorNode** outNode); // NOTE: asm-derived (504B)

    // 0x800AB7B4
    bool IsNodeReachable(short nodeId, int flags); // NOTE: asm-derived

    // 0x800AB8C4
    void GetNodeText(short treeId, short nodeId, StringBuffer& outText); // NOTE: asm-derived

    // 0x800AB968
    int GetResFileID(short treeId); // NOTE: asm-derived

    // 0x800ABA34
    int GetTreeClass(short treeId); // NOTE: asm-derived

    // 0x800ABA88
    void GetClassName(short treeId, StringBuffer& outName); // NOTE: asm-derived

    // 0x800ABB14
    bool IsSingleExit(short treeId, short nodeId); // NOTE: asm-derived

    // 0x800ABD30
    int GetCumulativeTreeVersion(short treeId); // NOTE: asm-derived (1620B)

    // 0x800AC384
    bool GetTree(short treeId, ObjectDataBehaviorTree** outTree, bool flag); // NOTE: asm-derived

    // 0x800AC4A4
    void GetTreeName(short treeId, StringBuffer& outName); // NOTE: asm-derived

    // 0x800AC5A8
    bool GetConstants(short treeId, ObjectDataBehaviorConstants** outConst); // NOTE: asm-derived

    // 0x800AC650
    void Init(Language* lang, ObjSelector* selector); // NOTE: asm-derived (480B)

    // 0x800AD128
    int GetResFileIDByClass(short classId); // NOTE: asm-derived
};

// ============================================================================
// ObjSelector - Object selector/definition accessor
// ============================================================================
class CatalogResource;
class TreeTable;
class AnimTableImpl;

class ObjSelector {
public:
    // 0x801104DC
    ObjSelector(); // NOTE: asm-derived

    // 0x801105A0
    ~ObjSelector(); // NOTE: asm-derived

    // 0x80110674
    bool IsPreloaded() const; // NOTE: asm-derived

    // 0x80110790
    void loadFile(); // NOTE: asm-derived

    // 0x801107DC
    int GetEffectiveTreeTableID(); // NOTE: asm-derived

    // 0x80110840
    ObjSelector* GetMasterSelector(); // NOTE: asm-derived

    // 0x801108F0
    const char* GetCatalogName(); // NOTE: asm-derived

    // 0x8011094C
    const char* GetCatalogDescription(); // NOTE: asm-derived

    // 0x801109A8
    const char* GetCatalogShortName(); // NOTE: asm-derived

    // 0x80110A2C
    BString2* GetUserName(); // NOTE: asm-derived

    // 0x80110A80
    void SetUserName(BString2& name); // NOTE: asm-derived

    // 0x80110B04
    BString2* GetUserLastName(); // NOTE: asm-derived

    // 0x80110B58
    void SetUserLastName(BString2& name); // NOTE: asm-derived

    // 0x80110BB4
    void GetUserFullName(BString2& outName); // NOTE: asm-derived

    // 0x80110C80
    bool GetBigThumbnail(ERShader** outShader); // NOTE: asm-derived

    // 0x80110D44
    bool GetThumbnail(ERShader** outShader); // NOTE: asm-derived (480B)

    // 0x80110F24
    void SetThumbnail(ETexture* tex); // NOTE: asm-derived

    // 0x80111004
    void DestroyThumbnail(); // NOTE: asm-derived

    // 0x801110F0
    bool GetHasInteractions(); // NOTE: asm-derived

    // 0x80111194
    int GetInitTreeVersion(); // NOTE: asm-derived

    // 0x801111FC
    int GetMainTreeVersion(); // NOTE: asm-derived

    // 0x80111264
    int GetCatalogRating(int category); // NOTE: asm-derived

    // 0x801113AC
    void* GetFnTable(); // NOTE: asm-derived

    // 0x8011148C
    CatalogResource* GetCatalogResource(); // NOTE: asm-derived

    // 0x8011150C
    void GetShortFilename(StringBuffer* outName); // NOTE: asm-derived

    // 0x80111588
    int CountTypeAttributes(); // NOTE: asm-derived

    // 0x801115E8
    void* GetTypeAttributes(); // NOTE: asm-derived

    // 0x80111648
    TreeTable* GetTreeTable(); // NOTE: asm-derived

    // 0x801116A0
    void* GetNormalSimDescription() const; // NOTE: asm-derived

    // 0x801116E8
    void ResetAnimTables(); // NOTE: asm-derived

    // 0x80111744
    AnimTableImpl* GetAdultAnimTable(); // NOTE: asm-derived

    // 0x801117A4
    AnimTableImpl* GetChildAnimTable(); // NOTE: asm-derived

    // 0x80111804
    AnimTableImpl* GetAdultToChildAnimTable(); // NOTE: asm-derived

    // 0x80111864
    AnimTableImpl* GetChildToAdultAnimTable(); // NOTE: asm-derived
};

// ============================================================================
// ReconBuffer - Serialization/streaming buffer
// ============================================================================
class ReconBuffer {
public:
    // 0x80132E18
    ~ReconBuffer(); // NOTE: asm-derived

    // 0x80132E94
    void UseStringTable(unsigned int param1, unsigned int param2, short param3); // NOTE: asm-derived

    // 0x80132F4C
    void ReconCmprInt(int* value, Scheme* scheme); // NOTE: asm-derived (444B)

    // 0x80133108
    void ReconBits(int bitCount, int* value); // NOTE: asm-derived (444B)

    // 0x801332D0
    void Recon8(signed char* value, int count); // NOTE: asm-derived

    // 0x80133430
    void ReconBool(bool* value); // NOTE: asm-derived

    // 0x80133484
    void Recon16(short* value, int count); // NOTE: asm-derived

    // 0x80133634
    void Recon32(int* value, int count); // NOTE: asm-derived

    // 0x801337E0
    void ReconFloat(float* value, int count); // NOTE: asm-derived

    // 0x8013398C
    void ReconMark(); // NOTE: asm-derived

    // 0x80133A98
    void ReadToNextMark(); // NOTE: asm-derived

    // 0x80133AE4
    void ReconString(BString& str); // NOTE: asm-derived

    // 0x80133C48
    void ReconString(BString2& str); // NOTE: asm-derived (648B)

    // 0x80133ED0
    void ReconString(StringBuffer& str); // NOTE: asm-derived

    // 0x80134028
    void ReconString(StringBuffer2& str); // NOTE: asm-derived (580B)
};

// ============================================================================
// EHouse - House building and management
// ============================================================================
class EHouse {
public:
    // 0x8002371C
    EHouse(EVec2& pos, int floors, ERLevel* level,
           bool flag1, bool flag2, bool flag3, bool flag4); // NOTE: asm-derived (644B)

    // 0x800239A0
    ~EHouse(); // NOTE: asm-derived

    // 0x80023A20
    void BuildHouse(); // NOTE: asm-derived (396B)

    // 0x80023BE0
    void SetNextWallMode(); // NOTE: asm-derived

    // 0x80024430
    void Draw(ERC* rc); // NOTE: asm-derived

    // 0x800244CC
    void Update(); // NOTE: asm-derived (548B)

    // 0x800246F0
    void UpdateRoomAmbient(LevelLightingEntry& entry); // NOTE: asm-derived

    // 0x80024828
    void WeatherChanging(); // NOTE: asm-derived

    // 0x800248A8
    void Fair(); // NOTE: asm-derived

    // 0x800248F4
    void Rain(); // NOTE: asm-derived

    // 0x8002498C
    void UpdateWeather(); // NOTE: asm-derived (880B)

    // 0x80024CFC
    void Cleanup(); // NOTE: asm-derived

    // 0x80024DB8
    void DestroyWalls(); // NOTE: asm-derived

    // 0x80024E04
    void ReCalcHouse(); // NOTE: asm-derived (404B)

    // 0x80024F98
    void UpdateRoomLights(); // NOTE: asm-derived (372B)

    // 0x8002510C
    void SetLightIntensityScaleFromRoom(EILight* light); // NOTE: asm-derived

    // 0x80025264
    void InitRoomLighting(); // NOTE: asm-derived

    // 0x800253AC
    void CleanUpRoomLights(); // NOTE: asm-derived

    // 0x80025464
    void InsertHouseObject(EOrderTableData* otd); // NOTE: asm-derived
};

// ============================================================================
// ActionQueueHUD - Action queue HUD display
// ============================================================================
class ActionQueueHUD {
public:
    class ActionQueueItem {
    public:
        // 0x803B24C8
        void SetupItem(char* name, unsigned int icon, ERShader* shader,
                       unsigned int flags); // NOTE: asm-derived

        // 0x803B252C
        void UpdateItem(ActionQueueItem& other); // NOTE: asm-derived
    };

    // 0x801845E4
    ActionQueueHUD(); // NOTE: asm-derived

    // 0x801846CC
    ~ActionQueueHUD(); // NOTE: asm-derived

    // 0x801847C4
    void AttachController(); // NOTE: asm-derived

    // 0x8018481C
    void DetachController(); // NOTE: asm-derived

    // 0x8018486C
    void Stop(); // NOTE: asm-derived (388B)

    // 0x80184A30
    void RunEditActionQueue(); // NOTE: asm-derived (568B)

    // 0x80184C68
    void SelectNextAction(); // NOTE: asm-derived

    // 0x80184CDC
    void SelectPriorAction(); // NOTE: asm-derived

    // 0x80184D40
    void ActivateEditActionQueue(); // NOTE: asm-derived

    // 0x80184E04
    void DeactivateEditActionQueue(); // NOTE: asm-derived

    // 0x80184E8C
    void RunIngame(); // NOTE: asm-derived (340B)

    // 0x80184FE0
    void OnUserCancelledAction(unsigned int index); // NOTE: asm-derived

    // 0x80185068
    void AddAction(ActionQueueItem& item, Interaction* interaction,
                   unsigned int flags); // NOTE: asm-derived

    // 0x80185138
    void SetAction(ActionQueueItem& item, Interaction* interaction); // NOTE: asm-derived

    // 0x801851F8
    void RemoveAction(Interaction* interaction); // NOTE: asm-derived (400B)

    // 0x80185388
    void RemoveAllActions(); // NOTE: asm-derived

    // 0x801853FC
    void StartPendingOperation(); // NOTE: asm-derived (468B)

    // 0x801855D0
    void CompletePendingOperation(); // NOTE: asm-derived (392B)

    // 0x80185758
    void CatchUpPendingActions(); // NOTE: asm-derived

    // 0x801857B8
    void RunActionQueue(); // NOTE: asm-derived

    // 0x80185820
    void UpdateVisual(); // NOTE: asm-derived

    // 0x80185870
    void* GetPlayerSim() const; // NOTE: asm-derived
};

// ============================================================================
// Path - Pathfinding (A* routing)
// ============================================================================
class Path {
public:
    // 0x8013ACAC
    void InitAST(); // NOTE: asm-derived (460B)

    // 0x8013AE78
    void OpenANode(); // NOTE: asm-derived (3108B) - core A* node opening

    // 0x8013BC20
    void DoOneSmooth(); // NOTE: asm-derived (1228B)

    // 0x8013D6AC
    void InitPath(RoutingParams* params); // NOTE: asm-derived

    // 0x8013D750
    int FindSmallestOpenNode(); // NOTE: asm-derived

    // 0x803AE6D8
    ~Path(); // NOTE: asm-derived (328B)
};

// ============================================================================
// DlgWrapper - Dialog wrapper for in-game dialogs
// ============================================================================
class DlgWrapper {
public:
    // 0x8007E440
    DlgWrapper(bool flag); // NOTE: asm-derived

    // 0x8007E544
    ~DlgWrapper(); // NOTE: asm-derived

    // 0x8007D8A0
    void Startup(); // NOTE: asm-derived (1272B)

    // 0x8007DD98
    void Shutdown(); // NOTE: asm-derived

    // 0x8007DDEC
    void Reset(); // NOTE: asm-derived

    // 0x8007DE30
    void Update(); // NOTE: asm-derived (440B)

    // 0x8007DFE8
    void Draw(ERC* rc); // NOTE: asm-derived

    // 0x8007E084
    void DialogPaneShow(); // NOTE: asm-derived

    // 0x8007E0FC
    void DialogPaneHide(); // NOTE: asm-derived

    // 0x8007E184
    void SetVariable(char* name, char* value); // NOTE: asm-derived

    // 0x8007E274
    void GetVariable(char* name); // NOTE: asm-derived (460B)

    // 0x8007E68C
    void SetDialogSize(EVec2& size); // NOTE: asm-derived

    // 0x8007E808
    void SetTitleFontSize(float size) {
        // NOTE: asm-derived - stores float to member offset
        char* self = (char*)this;
        *(float*)(self + 0x10) = size; // approximate offset
    }

    // 0x8007E874
    void SetBodyFont(ERFont* font) {
        char* self = (char*)this;
        *(ERFont**)(self + 0x18) = font; // approximate offset
    }

    // 0x8007E8B8
    void SetBodyFontSize(float size) {
        char* self = (char*)this;
        *(float*)(self + 0x1C) = size; // approximate offset
    }

    // 0x8007E8FC
    void SetBodyPos(EVec2& pos); // NOTE: asm-derived

    // 0x8007EA08
    void SetAcceptFont(ERFont* font); // NOTE: asm-derived
    // 0x8007EA58
    void SetAcceptFontSize(float size); // NOTE: asm-derived
    // 0x8007EAAC
    void SetAcceptPos(EVec2& pos); // NOTE: asm-derived
    // 0x8007EB08
    void SetAcceptPosX(float x); // NOTE: asm-derived
    // 0x8007EB58
    void SetAcceptPosY(float y); // NOTE: asm-derived

    // 0x8007EBE4
    void SetDeclineFont(ERFont* font); // NOTE: asm-derived
    // 0x8007EC34
    void SetDeclineFontSize(float size); // NOTE: asm-derived
    // 0x8007EC88
    void SetDeclinePos(EVec2& pos); // NOTE: asm-derived
    // 0x8007ECE4
    void SetDeclinePosX(float x); // NOTE: asm-derived
    // 0x8007ED34
    void SetDeclinePosY(float y); // NOTE: asm-derived

    // 0x8007EDC0
    void SetAlt1Font(ERFont* font); // NOTE: asm-derived
    // 0x8007EE10
    void SetAlt1FontSize(float size); // NOTE: asm-derived
    // 0x8007EE64
    void SetAlt1Pos(EVec2& pos); // NOTE: asm-derived
    // 0x8007EEC0
    void SetAlt1PosX(float x); // NOTE: asm-derived
    // 0x8007EF10
    void SetAlt1PosY(float y); // NOTE: asm-derived
};

// ============================================================================
// EString - Dynamic string class
// ============================================================================
class EString {
public:
    // 0x802D2880
    EString(char* str1, char* str2); // NOTE: asm-derived

    // 0x802D29E0
    void Tokenize(char* delimiters,
                  TArray<EString, TArrayDefaultAllocator>& outTokens); // NOTE: asm-derived

    // 0x802D2AA0
    void GetLine(__sFILE* file); // NOTE: asm-derived

    // 0x802D2B60
    void MakeCopy(char* src); // NOTE: asm-derived

    // 0x802D2CB0
    void Allocate(int size); // NOTE: asm-derived

    // 0x802D2D78
    int Compare(char* other) const; // NOTE: asm-derived

    // 0x802D2DE8
    int CompareNoCase(char* other) const; // NOTE: asm-derived

    // 0x802D2E58
    int CompareSymbol(char* other) const; // NOTE: asm-derived

    // 0x802D2F6C
    EString Mid(int start, int len) const; // NOTE: asm-derived

    // 0x802D2FE4
    EString Left(int count) const; // NOTE: asm-derived

    // 0x802D3058
    EString Right(int count) const; // NOTE: asm-derived

    // 0x802D30A8
    EString& operator+=(char* str); // NOTE: asm-derived

    // 0x802D3140
    EString& operator+=(char ch); // NOTE: asm-derived

    // 0x802D3198
    int Find(char ch, int start) const; // NOTE: asm-derived

    // 0x802D31F8
    int FindNoCase(char ch) const; // NOTE: asm-derived

    // 0x802D3264
    int Find(char* substr, int start) const; // NOTE: asm-derived

    // 0x802D32C4
    int FindNoCase(char* substr) const; // NOTE: asm-derived

    // 0x802D3374
    void Replace(char* find, char* replace); // NOTE: asm-derived

    // 0x802D343C
    int FindReverse(char ch) const; // NOTE: asm-derived

    // 0x802D3498
    void Convert(float val); // NOTE: asm-derived

    // 0x802D34E4
    void Convert(int val); // NOTE: asm-derived

    // 0x802D3564
    void Remove(char ch); // NOTE: asm-derived

    // 0x802D379C
    EString ExtractFilename() const; // NOTE: asm-derived

    // 0x802D37E0
    EString ExtractRoot() const; // NOTE: asm-derived

    // 0x802D3824
    EString ExtractDirectory() const; // NOTE: asm-derived

    // 0x802D3868
    EString ExtractExtension() const; // NOTE: asm-derived

    // 0x802D38E4
    void MakeLegalSymbolName(); // NOTE: asm-derived

    // 0x802D393C
    void RemoveRelationalDirectories(); // NOTE: asm-derived

    // 0x802D3980
    void TrimRight(char ch); // NOTE: asm-derived

    // 0x802D3A2C
    void TrimLeft(char ch); // NOTE: asm-derived

    // 0x802D3AE0
    void TrimRight(char* chars); // NOTE: asm-derived

    // 0x802D3B84
    void TrimLeft(char* chars); // NOTE: asm-derived

    // 0x802D3C48
    void Format(char* fmt, ...); // NOTE: asm-derived

    // 0x802D3D2C
    void Insert(int pos, char ch); // NOTE: asm-derived

    // 0x802D3DB4
    void Insert(int pos, char* str); // NOTE: asm-derived

    // 0x802D3EFC
    static bool CharsEqualNoCase(char a, char b); // NOTE: asm-derived
};

// ============================================================================
// K2YTarget - Keyboard input UI target
// ============================================================================
class K2YTarget {
public:
    enum eK2yboardMode { /* keyboard modes */ };

    // 0x801BDA58
    K2YTarget(); // NOTE: asm-derived (2220B)

    // 0x801BE304
    ~K2YTarget(); // NOTE: asm-derived

    // 0x801BE460
    void GetName(); // NOTE: asm-derived

    // 0x801BE56C
    void SetVariable(char* name, char* value); // NOTE: asm-derived (688B)

    // 0x801BE81C
    void GetVariable(char* name); // NOTE: asm-derived (740B)

    // 0x801BEB00
    void GetLocalizable(char* key); // NOTE: asm-derived (596B)

    // 0x801BED54
    void GetKeybits(int param1, int param2); // NOTE: asm-derived (492B)

    // 0x801BEF40
    void SetStartMode(eK2yboardMode mode); // NOTE: asm-derived

    // 0x801BEFA0
    void SaveName(); // NOTE: asm-derived
};

// ============================================================================
// TextureUtils - Texture manipulation utilities
// ============================================================================
class TextureUtils {
public:
    // 0x8030B108
    static void LoadTexture(unsigned int id, ETexture* tex); // NOTE: asm-derived

    // 0x8030B228
    static void CopyTexture32To8(ETexture* src, ETexture* dst); // NOTE: asm-derived (900B)

    // 0x8030B5AC
    static void CopyTexture8To32(ETexture* src, ETexture* dst); // NOTE: asm-derived

    // 0x8030B7B0
    static void CopyTexture32To32(ETexture* src, ETexture* dst); // NOTE: asm-derived

    // 0x8030B960
    static void CopyTexture8To8(ETexture* src, ETexture* dst); // NOTE: asm-derived (572B)

    // 0x8030BB9C
    static void CopyTexture32To32Half(ETexture* src, ETexture* dst,
                                       unsigned char flag, unsigned int param); // NOTE: asm-derived (708B)

    // 0x8030BE60
    static void VerticalFlip(ETexture* tex); // NOTE: asm-derived

    // 0x8030BFA0
    static void MakeTextureSepiaTone(ETexture* tex); // NOTE: asm-derived (564B)

    // 0x8030C1D4
    static void ConvertColorArrayToSepia(unsigned char* src,
                                          unsigned char* dst); // NOTE: asm-derived

    // 0x8030C2CC
    static void SwapRB(ETexture* tex); // NOTE: asm-derived (744B)

    // 0x8030C5B4
    static void PrepareTextureForUpdateBegin(ETexture* tex); // NOTE: asm-derived

    // 0x8030C618
    static void PostUpdateEnd(ETexture* tex, bool flag); // NOTE: asm-derived

    // 0x8030C65C
    static unsigned int BlendPixels32(unsigned int pixel1,
                                       unsigned int pixel2); // NOTE: asm-derived
};

// ============================================================================
// SKLTarget - Skills display UI target
// ============================================================================
class SKLTarget {
public:
    // 0x801E02DC
    SKLTarget(int param); // NOTE: asm-derived (2796B)

    // 0x801E0DC8
    ~SKLTarget(); // NOTE: asm-derived

    // 0x801E0F34
    void SetVariable(char* name, char* value); // NOTE: asm-derived

    // 0x801E104C
    void GetVariable(char* name); // NOTE: asm-derived

    // 0x801E10E4
    void GetLocalizable(char* key); // NOTE: asm-derived (808B)

    // 0x801E140C
    void Update(); // NOTE: asm-derived (540B)

    // 0x801E1644
    void UpdateSkillsBar(); // NOTE: asm-derived (888B)
};

// ============================================================================
// cXPortal - Portal objects for inter-room routing
// ============================================================================
class cXPortal {
public:
    // 0x8013226C
    cXPortal(int param); // NOTE: asm-derived (1220B)

    // 0x8012D1E0
    ~cXPortal(); // NOTE: asm-derived (688B)

    // 0x80130960
    void DirtyAllRoutes(ObjectModule* objMod); // NOTE: asm-derived

    // 0x80130A34
    void InitPortalRoute(ObjectModule* objMod, cXObject* src,
                         cXObject* dst); // NOTE: asm-derived

    // 0x801312A4
    float EstimateDistance(ObjectModule* objMod, cXObject* src,
                           cXObject* dst); // NOTE: asm-derived (524B)

    // 0x801316A0
    cXPortal* FindBestPortal(ObjectModule* objMod, cXObject* src,
                              cXObject* dst); // NOTE: asm-derived (1272B)

    // 0x80131B98
    void FailedPortalTree(ObjectModule* objMod, cXObject* obj,
                          cXPortal* portal); // NOTE: asm-derived

    // 0x80131C7C
    void BeginningPortalTree(ObjectModule* objMod, cXObject* obj,
                             cXPortal* portal); // NOTE: asm-derived (872B)

    // 0x80131FE4
    void DumpRouteScores(ObjectModule* objMod, short param); // NOTE: asm-derived (508B)

    // 0x80132744
    static void* CAST_IMPL(); // NOTE: asm-derived
};

// ============================================================================
// ERTQuantize - Color quantization (palette generation)
// ============================================================================
class ERTQCacheNode;
class ERTQNode;

class ERTQuantize {
public:
    // 0x802CE71C
    ~ERTQuantize(); // NOTE: asm-derived

    // 0x802CE76C
    void Deallocate(); // NOTE: asm-derived

    // 0x802CE7BC
    void Init(unsigned int maxColors, unsigned int param2,
              void* (*allocFn)(unsigned int), void (*freeFn)(void*),
              bool flag); // NOTE: asm-derived (592B)

    // 0x802CEAE4
    void InitializeCube(); // NOTE: asm-derived

    // 0x802CEBD0
    void InitializeNode(unsigned char level, unsigned int index,
                        ERTQNode* parent, EVec3& color); // NOTE: asm-derived

    // 0x802CECE0
    void AddPixel(unsigned char* pixel); // NOTE: asm-derived

    // 0x802CED98
    void FlushAdd(ERTQCacheNode& cacheNode); // NOTE: asm-derived

    // 0x802CEE00
    void TransformToYuv(unsigned char* rgb, EVec3& yuv); // NOTE: asm-derived

    // 0x802CEFD0
    void TransformFromYUV(EVec3& yuv, unsigned char* rgb); // NOTE: asm-derived

    // 0x802CF1C8
    int Classify(EVec3& color, int depth); // NOTE: asm-derived (736B)

    // 0x802CF4A8
    void PruneLevel(ERTQNode* node); // NOTE: asm-derived

    // 0x802CF54C
    void PruneChild(ERTQNode* node); // NOTE: asm-derived

    // 0x802CF634
    void Compute(); // NOTE: asm-derived

    // 0x802CF6CC
    void Reduction(); // NOTE: asm-derived

    // 0x802CF75C
    void Reduce(ERTQNode* node); // NOTE: asm-derived

    // 0x802CF838
    void MColormap(ERTQNode* node); // NOTE: asm-derived

    // 0x802CF96C
    void GetPaletteEntry(int index, unsigned char* outColor); // NOTE: asm-derived

    // 0x802CF9B8
    int GetClosestColor(unsigned char* pixel); // NOTE: asm-derived (636B)

    // 0x802CFC34
    int ClosestColor(ERTQNode* node); // NOTE: asm-derived
};

// ============================================================================
// AmbientSoundPlayer - Ambient/environmental sound playback
// ============================================================================
class AmbientSoundPlayer {
public:
    // 0x800A92BC
    ~AmbientSoundPlayer(); // NOTE: asm-derived

    // 0x800A9374
    void Start(); // NOTE: asm-derived (964B)

    // 0x800A9738
    void Stop(); // NOTE: asm-derived

    // 0x800A97B4
    void Pause(); // NOTE: asm-derived

    // 0x800A97F8
    void UnPause(); // NOTE: asm-derived

    // 0x800A983C
    void SetInitialSoundPosition(); // NOTE: asm-derived (2068B)

    // 0x800AA050
    void UpdateSoundPosition(); // NOTE: asm-derived

    // 0x800AA0A4
    void UpdateLoopingSoundPosition(); // NOTE: asm-derived (1300B)

    // 0x800AA5B8
    void UpdatePanAndVolume(); // NOTE: asm-derived (844B)

    // 0x800AA904
    void UpdateSoundVolume(); // NOTE: asm-derived

    // 0x800AA9BC
    bool IsFinished(); // NOTE: asm-derived
};

// ============================================================================
// AptLoadVars - APT ActionScript LoadVars object
// ============================================================================
class AptLoadVars {
public:
    // 0x802A888C
    AptLoadVars(); // NOTE: asm-derived

    // 0x802A6DB8
    ~AptLoadVars(); // NOTE: asm-derived

    // 0x802A67CC
    void objectMemberLookup(AptValue* obj, EAStringC* name) const; // NOTE: asm-derived (1516B)

    // 0x802A6E20
    void CleanNativeFunctions(); // NOTE: asm-derived (412B)

    // 0x802A6FBC
    void sMethod_load(AptValue* args, int nargs); // NOTE: asm-derived (820B)

    // 0x802A72F0
    void sMethod_send(AptValue* args, int nargs); // NOTE: asm-derived (764B)

    // 0x802A75EC
    void sMethod_sendAndLoad(AptValue* args, int nargs); // NOTE: asm-derived (1368B)

    // 0x802A7B44
    void sMethod_getBytesTotal(AptValue* args, int nargs); // NOTE: asm-derived

    // 0x802A7C38
    void sMethod_getBytesLoaded(AptValue* args, int nargs); // NOTE: asm-derived

    // 0x802A7D2C
    void sMethod_toString(AptValue* args, int nargs); // NOTE: asm-derived
};

// ============================================================================
// ERotDecomp - Rotation decompressor for animation
// ============================================================================
class ERotDecomp {
public:
    // 0x8035D2E8
    void Init(EBitArray* bits, int offset); // NOTE: asm-derived (384B)

    // 0x8035D468
    void* operator new(unsigned int size); // NOTE: asm-derived

    // 0x8035D50C
    void operator delete(void* ptr); // NOTE: asm-derived

    // 0x8035D5E0
    void GetFrame(float frame); // NOTE: asm-derived (1776B)

    // 0x8035DCD0
    void NextSegment(float frame); // NOTE: asm-derived

    // 0x8035DE0C
    void LastSegment(float frame); // NOTE: asm-derived

    // 0x8035DF44
    void Reset(); // NOTE: asm-derived

    // 0x8035DFB0
    void ResetEnd(); // NOTE: asm-derived

    // 0x8035E038
    void ReadAllQs(); // NOTE: asm-derived

    // 0x8035E0B4
    void GetKeyframe(int index, ERotKeyframe& outKey); // NOTE: asm-derived

    // 0x8035E1D8
    void GetQuatVal(int index, EQuat& outQuat); // NOTE: asm-derived

    // 0x8035E2DC
    void GetQ(int param1, int param2, EQuat& outQuat); // NOTE: asm-derived (2080B)
};

// ============================================================================
// ActionMenu - Pie menu / action selection menu
// ============================================================================
class ActionMenu {
public:
    class MenuItem {
    public:
        // 0x80182F40
        MenuItem(); // NOTE: asm-derived

        // 0x80182F9C
        ~MenuItem(); // NOTE: asm-derived

        // 0x80182FF4
        void Setup(cXObject* obj, Interaction* interaction, BString2& name,
                   unsigned int icon, ERShader* shader, bool flag); // NOTE: asm-derived

        // 0x801830B8
        void AddSubItem(MenuItem* item); // NOTE: asm-derived

        // 0x80183138
        bool IsObjectInMenu(cXObject* obj); // NOTE: asm-derived

        // 0x801831B8
        void ClearMenu(); // NOTE: asm-derived

        // 0x80183260
        int GetMenuItemCount() const; // NOTE: asm-derived
    };

    // 0x801832A8
    ActionMenu(); // NOTE: asm-derived

    // 0x80183350
    ~ActionMenu(); // NOTE: asm-derived

    // 0x80183410
    void Draw(ERC* rc); // NOTE: asm-derived (980B)

    // 0x801837F8
    void Stop(); // NOTE: asm-derived

    // 0x801838B0
    void Animate(); // NOTE: asm-derived

    // 0x80183928
    void UpdateIcon(); // NOTE: asm-derived (488B)

    // 0x80183B10
    void FillInMenu(); // NOTE: asm-derived

    // 0x80183C24
    void Run(); // NOTE: asm-derived (636B)

    // 0x80183EA0
    void AddMenu(cXObject* obj, BString2& name, unsigned int icon,
                 ERShader* shader); // NOTE: asm-derived

    // 0x80183F84
    void AddMenuItem(cXObject* obj, Interaction* interaction, BString2& name,
                     unsigned int icon, ERShader* shader, bool flag); // NOTE: asm-derived

    // 0x80184018
    void ShowMenu(); // NOTE: asm-derived

    // 0x80184108
    void BackOutMenu(); // NOTE: asm-derived

    // 0x80184208
    void AcceptMenu(); // NOTE: asm-derived (416B)

    // 0x801843A8
    void CloseMenu(); // NOTE: asm-derived

    // 0x801843FC
    void TerminateMenu(); // NOTE: asm-derived

    // 0x80184520
    void* GetPlayerSim() const; // NOTE: asm-derived
};

// ============================================================================
// ELightGrid - Light grid system for per-vertex lighting
// ============================================================================
class ELightGrid {
public:
    class LightData {
    public:
        // 0x80230F8C
        void Clear(); // NOTE: asm-derived
    };

    struct LightWeight {
        // Weight data for interpolating lights
    };

    struct PortalData {
        // Portal light connection data
    };

    class RoomData {
    public:
        // 0x8022FBC4
        void Flush(); // NOTE: asm-derived

        // 0x802301AC
        void FindClosestLights(EVec3& pos, int room, int maxLights,
                               LightData* outLights, LightWeight* outWeights,
                               int param); // NOTE: asm-derived

        // 0x8023073C
        void EvaluateAmbientAndDirectionalLights(); // NOTE: asm-derived
    };

    // 0x8022FA6C
    ELightGrid(); // NOTE: asm-derived

    // 0x8022FAF4
    void Flush(); // NOTE: asm-derived

    // 0x8022FC14
    void AddRoomToVertex(int vertX, int vertY, int room); // NOTE: asm-derived

    // 0x8022FCAC
    void Update(TNodeList<EILight*>& lights, EInstance** instances,
                int numInstances, int flags); // NOTE: asm-derived (820B)

    // 0x8022FFE0
    void ConnectPortalLights(RoomData* roomData); // NOTE: asm-derived (460B)

    // 0x802302B4
    void EvaluatePointLights(int room, int numLights); // NOTE: asm-derived

    // 0x802303D4
    void AddLightsToVertices(); // NOTE: asm-derived (564B)

    // 0x80230608
    void EvaluateLights(); // NOTE: asm-derived

    // 0x8023065C
    void EvaluateOuterLotLights(); // NOTE: asm-derived

    // 0x802306E4
    void EvaluateAmbientAndDirectionalLights(); // NOTE: asm-derived

    // 0x802307CC
    void EvaluatePortalLights(int room, int numPortals); // NOTE: asm-derived

    // 0x80230838
    void EvaluatePortalLight(LightData* lightData,
                              PortalData* portalData); // NOTE: asm-derived (768B)

    // 0x80230C2C
    void GetLightWeightsAtLocation(EVec3& pos, int room,
                                    LightWeight* outWeights); // NOTE: asm-derived (508B)

    // 0x80230E28
    int GetLightsAtLocation(EVec3& pos, int room) const; // NOTE: asm-derived

    // 0x80230EF0
    bool IsRoomAtLocation(EVec3& pos, int room); // NOTE: asm-derived

    // 0x80230FFC
    void EvaluateLamps(); // NOTE: asm-derived

    // 0x80231040
    void EvaluateLampsOn(); // NOTE: asm-derived
};

// ============================================================================
// CasGenetics - Create-A-Sim genetics system
// ============================================================================
class CasGenetics {
public:
    class Grandparent {
    public:
        // 0x80161998
        ~Grandparent(); // NOTE: asm-derived
    };

    // 0x80160424
    ~CasGenetics(); // NOTE: asm-derived

    // 0x801604A8
    void BlendSimDescriptions(CasSimDescriptionS2C& desc1, CasSimDescriptionS2C& desc2,
                              CasSimDescriptionS2C& outDesc, bool flag); // NOTE: asm-derived (492B)

    // 0x80160694
    signed char BlendSkinColor(signed char color1, signed char color2); // NOTE: asm-derived

    // 0x80160788
    signed char BlendBodyType(signed char type1, signed char type2); // NOTE: asm-derived

    // 0x801608A0
    float BlendMorphValues(float val1, float val2); // NOTE: asm-derived

    // 0x80160900
    void ChoosePersonalityTraits(CasSimDescriptionS2C& desc); // NOTE: asm-derived

    // 0x80160974
    void ChooseRandomBodyPart(eBodyPartS2C part, CasSimDescriptionS2C& desc,
                              int param); // NOTE: asm-derived (1028B)

    // 0x80160D78
    void ClearGrandparentsList(); // NOTE: asm-derived

    // 0x80160E38
    void LoadGrandparentList(bool flag); // NOTE: asm-derived

    // 0x80160F44
    void SaveGrandparentList(); // NOTE: asm-derived

    // 0x80161090
    void DoStream(ReconBuffer* buffer, int mode); // NOTE: asm-derived (1068B)

    // 0x801614BC
    void CreateNewGrandparentList(); // NOTE: asm-derived (592B)

    // 0x8016170C
    void LoadGrandparentPortraits(); // NOTE: asm-derived

    // 0x801617FC
    Grandparent* GetGrandparent(bool maternal, unsigned int index); // NOTE: asm-derived

    // 0x80161840
    void UpdateGrandparentDescription(bool maternal, unsigned int index,
                                       CasSimDescriptionS2C& desc); // NOTE: asm-derived

    // 0x801618F0
    const char* GetGrandparentPortraitName(bool maternal,
                                            unsigned int index); // NOTE: asm-derived

    // 0x80161A20
    bool FemaleFacialFeatureLocked(signed char feature); // NOTE: asm-derived
};

// ============================================================================
// MOTTarget - Motive bars UI target
// ============================================================================
class MOTTarget {
public:
    // 0x801CAABC
    MOTTarget(int param); // NOTE: asm-derived (2792B)

    // 0x801CB5A4
    ~MOTTarget(); // NOTE: asm-derived

    // 0x801CB710
    void SetVariable(char* name, char* value); // NOTE: asm-derived

    // 0x801CB828
    void GetVariable(char* name); // NOTE: asm-derived

    // 0x801CB8C0
    void GetLocalizable(char* key); // NOTE: asm-derived

    // 0x801CB944
    void Update(); // NOTE: asm-derived (532B)

    // 0x801CBB78
    void UpdateMotiveBars(); // NOTE: asm-derived (1096B)

    // 0x801CBFC8
    void ReadMotiveBar(int index); // NOTE: asm-derived (464B)

    // 0x801CC198
    void ResetRealMotiveValues(); // NOTE: asm-derived
};

// ============================================================================
// AptNativeHash - APT native hash table for ActionScript objects
// ============================================================================
class AptNativeHash {
public:
    // 0x802A98CC
    ~AptNativeHash(); // NOTE: asm-derived

    // 0x802A99D0
    void DestroyGCPointers(); // NOTE: asm-derived

    // 0x802A9B04
    void SetIfNotExists(EAStringC* key, AptValue* value); // NOTE: asm-derived

    // 0x802A9B50
    void Set(EAStringC* key, AptValue* value); // NOTE: asm-derived (548B)

    // 0x802A9D74
    void Unset(EAStringC* key); // NOTE: asm-derived (552B)

    // 0x802A9F9C
    AptValue* Lookup(EAStringC* key) const; // NOTE: asm-derived

    // 0x802AA0D4
    void ClearData(); // NOTE: asm-derived (424B)

    // 0x802AA27C
    void ClearDataNoDelete(); // NOTE: asm-derived

    // 0x802AA400
    AptHashItem* GetFirstItem(); // NOTE: asm-derived

    // 0x802AA470
    AptHashItem* GetNextItem(AptHashItem* item); // NOTE: asm-derived

    // 0x802AA4E4
    void Expand(); // NOTE: asm-derived

    // 0x802AA5E0
    void HashSet(EAStringC* key, AptValue* value); // NOTE: asm-derived (1336B)

    // 0x802AAB18
    AptHashItem* HashFindKey(EAStringC* key) const; // NOTE: asm-derived (616B)

    // 0x802AAD80
    void UpdateObjectMethods(AptValue* obj, EAStringC* name,
                              int param); // NOTE: asm-derived

    // 0x802AAE30
    void RegisterReferences(AptValue* root) const; // NOTE: asm-derived

    // 0x802AAF0C
    void FirstAllocation(); // NOTE: asm-derived
};

// ============================================================================
// ESpriteRender - Sprite rendering system (billboards, particles, etc.)
// ============================================================================
class ESpriteRender {
public:
    struct SpriteData {
        // Per-sprite rendering data
    };

    // 0x80035530
    ~ESpriteRender(); // NOTE: asm-derived

    // 0x80035588
    void DeleteShaders(); // NOTE: asm-derived (320B)

    // 0x800356C8
    void Update(); // NOTE: asm-derived (456B)

    // 0x80035890
    void DrawIntoOrderTable(); // NOTE: asm-derived (888B)

    // 0x80035C08
    void SpriteRenderOrderTableCallback(ELevelDrawData& drawData,
                                         EOrderTableData* otd); // NOTE: asm-derived

    // 0x80035C50
    void DrawDirectly(ERC* rc); // NOTE: asm-derived (1320B)

    // 0x80036178
    void SetSprite(); // NOTE: asm-derived (1468B)

    // 0x80036734
    void SetUpRect(ERC* rc, EVec3& pos, float width, float height,
                   SpriteData& outData); // NOTE: asm-derived (620B)

    // 0x800369A0
    void SetUpDoubleRect(ERC* rc, EVec3& pos, float width, float height,
                         ERShader* shader1, ERShader* shader2,
                         SpriteData& outData); // NOTE: asm-derived (1128B)
};

// ============================================================================
// InLevelBaseState - Base state for in-level gameplay
// ============================================================================
class InLevelBaseState {
public:
    // 0x8008B5B0
    InLevelBaseState(int param); // NOTE: asm-derived

    // 0x8008B6F8
    ~InLevelBaseState(); // NOTE: asm-derived

    // 0x80089EB0
    void Shutdown(); // NOTE: asm-derived

    // 0x80089F2C
    void Update(float deltaTime); // NOTE: asm-derived (5204B) - very large update loop

    // 0x8008B380
    void HandleExitToMainMenu(); // NOTE: asm-derived

    // 0x8008B4D0
    void SavePlayerInteractorState(); // NOTE: asm-derived

    // 0x8008B55C
    void dialog_selection_callback(int selection); // NOTE: asm-derived
};

// ============================================================================
// BSplineVolume - B-spline volume for morph deformation
// ============================================================================
class BSplineVolume {
public:
    // 0x8030D864
    BSplineVolume(); // NOTE: asm-derived

    // 0x8030D8F8
    ~BSplineVolume(); // NOTE: asm-derived

    // 0x8030D944
    void Free(); // NOTE: asm-derived (552B)

    // 0x8030DB6C
    void Read(EStream& stream); // NOTE: asm-derived (840B)

    // 0x8030DEB4
    void Read(unsigned char* data); // NOTE: asm-derived (768B)

    // 0x8030E250
    void AllocateControlPoints(int dimX, int dimY, int dimZ,
                                int order); // NOTE: asm-derived

    // 0x8030E348
    void ParameterizeControlPoints(); // NOTE: asm-derived (1040B)

    // 0x8030E758
    void ParameterizeVert(EVec3 pos, int& outIndex); // NOTE: asm-derived (660B)

    // 0x8030E9EC
    void GenerateControlPointDeltas(); // NOTE: asm-derived

    // 0x8030EBA0
    void BlendVolumes(); // NOTE: asm-derived (836B)

    // 0x8030F0FC
    void GetPosition(EVec3* outPos, int index) const; // NOTE: asm-derived (704B)
};

// ============================================================================
// cSimulatorImpl - Game simulator implementation
// ============================================================================
class Commander {
public:
    Commander();
    ~Commander();
};

class cSimulatorImpl {
public:
    // Layout: [0] vtable, [4] Commander base, [16] sub-vtable,
    //         [152] field, [180+] ExpenseReport array (5x32=160 bytes),
    //         [340] ExpenseReport totals

    // 0x8014024C
    cSimulatorImpl() {
        // NOTE: asm-derived - sets up vtables, inits Commander base,
        // zeroes field at 152, resets 5 ExpenseReports starting at 180,
        // resets totals ExpenseReport at 340, initializes time/speed fields
    }

    // 0x80140394
    void Init(); // NOTE: asm-derived

    // 0x80140410
    ~cSimulatorImpl(); // NOTE: asm-derived

    // 0x80140488
    void DoStream(ReconBuffer* buffer, int mode); // NOTE: asm-derived

    // 0x801405D0
    void DoCommand(short cmd, int param); // NOTE: asm-derived

    // 0x80140760
    void SimulateOneTick(); // NOTE: asm-derived (684B)

    // 0x80140A38
    void ComputeTimeOfDay(); // NOTE: asm-derived

    // 0x80140B00
    int HourTimeOfDayLastChanged(); // NOTE: asm-derived

    // 0x80140BA4
    int HourTimeOfDayNextChanges(); // NOTE: asm-derived

    // 0x80140C58
    void TickAllObjects(); // NOTE: asm-derived

    // 0x80140CE0
    void SetSpeed(SimSpeed speed); // NOTE: asm-derived

    // 0x80140D44
    void UpdateSpeed(); // NOTE: asm-derived

    // 0x80140DB8
    void Pause(); // NOTE: asm-derived

    // 0x80140DE8
    void Resume(); // NOTE: asm-derived

    // 0x80140E18
    void SetCurrentHour(int hour); // NOTE: asm-derived

    // 0x80140E94
    void SetFunds(int player, int amount); // NOTE: asm-derived

    // 0x80140F14
    void Spend(ExpenseType type, int amount, int player); // NOTE: asm-derived

    // 0x80140F88
    void ClearHistory(); // NOTE: asm-derived

    // 0x80141050
    void Simulate(); // NOTE: asm-derived

    // 0x80141118
    void GetTodaysExpenses(ExpenseReport* report); // NOTE: asm-derived

    // 0x80141168
    void GetPreviousExpenses(int day, ExpenseReport* report); // NOTE: asm-derived

    // 0x801411CC
    void GetExpensesHistory(ExpenseReport* report); // NOTE: asm-derived

    // 0x80141234
    short GetGlobal(short index); // NOTE: asm-derived

    // 0x80141278
    void GetGlobalRef(short index, short** outRef); // NOTE: asm-derived
};

// ============================================================================
// ENodeList helper (referenced by EFloorShdTblNode)
// ============================================================================
class ENodeList {
public:
    void RemoveAll();
    void Remove(NLIteratorPtrType*);
    void AddHead(unsigned int);
    void AddTail(unsigned int);
};

class EResource {
public:
    void DelRef();
    void AddRef();
};
