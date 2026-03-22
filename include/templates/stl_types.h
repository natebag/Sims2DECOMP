#ifndef STL_TYPES_H
#define STL_TYPES_H

// Forward declarations for all types used in STL template instantiations
// Auto-generated from symbol map

#include "types.h"

// Forward class/struct declarations
struct ACTTarget;
struct AmbientScorePlayer;
struct AptAuxIDToChar;
struct AttachmentNode;
struct AttachmentNodeV1;
struct BString;
struct BString2;
struct CTilePt;
struct CasGenetics;
struct CasListener;
struct CasSimDescriptionS2C;
struct ChainResFile;
struct ConsoleAutoRefCount;
struct DiagonalNode;
struct ECTRL_CMD;
struct EOrderTableData;
struct ERAmbientSound;
struct ERDataset;
struct ERModel;
struct ERShader;
struct ERSoundEvent;
struct ERTexture;
struct EResourceManager;
struct EResourceMap;
struct EString;
struct EdithVariableSet;
struct FAMTarget;
struct FamilyMember;
struct FileRec;
struct IFFResList;
struct IFFResNode;
struct INVTarget;
struct IPoint;
struct IRect;
struct ISmartDataFactory;
struct InteractorModule;
struct LogInteractionSample;
struct MMUTarget;
struct MotiveInc;
struct NamespaceSelector;
struct Neighbor;
struct ObjSelector;
struct ObjectDataID;
struct ObjectRecord;
struct ObjectSlot;
struct PassiveInfluenceObject;
struct PassiveInfluencePerson;
struct PassiveInfluenceTarget;
struct PenaltyRect;
struct PersDataPair;
struct PrimitiveSample;
struct ReconBuffer;
struct RelArray;
struct RelInt;
struct ResFile;
struct Room;
struct RouteGoal;
struct RoutingSlot;
struct ScoredInteraction;
struct SimTickSample;
struct SlotDescriptor;
struct SlotLoader;
struct SndInstruction;
struct SoundEventInfo;
struct SpriteSlot;
struct StackElem;
struct StackString;
struct StateMachineStatus;
struct TreeTableAdQuickData;
struct TreeTableEntryQuickData;
struct XObjLang;
struct XRoute;
struct cBoxX;
struct cHitControlGroup;
struct cTrack;
struct cXObject;
struct cXObjectImpl;
struct iResFile;
struct lua_State;
struct model_dat;

// Nested type forward declarations
namespace AutomationNS { struct LuaTable; }
struct ERDataset { struct ResourceInfo; };
struct EResourceManager { struct ResourceIndexRecord; };
struct CasGenetics { struct Grandparent; };
struct ISmartDataFactory { struct tDataProvider; };

namespace InteractorModule {
    struct FloorData;
    struct WallData;
    struct WallPaperData;
    struct Interactor;
    struct InteractorInfo;
    struct InteractorType;
    struct InteractorResourceSet;
    struct InvStock;
    struct PatternSellCount;
    struct FenceSellCount;
    struct PlacementObject { struct ContainerInfo; };
    struct InteractorManager { struct ActiveInteractor; };
    struct InteractorInputManager { struct InteractorCommand; };
}

struct FAMTarget { struct FAM_STATE; };
struct MMUTarget { struct MMU_MENU_STATE; };
struct ACTTarget { struct iqRecord; };

// STL-like types (SN Systems / Metrowerks STL)
template <typename T> struct allocator {};
template <typename T> struct char_traits {};
template <typename T> struct less {};
template <typename T> struct greater {};
template <typename T> struct equal_to {};
template <typename T> struct _Identity {};
template <typename T> struct _Select1st {};
template <typename T, typename U> struct _Nonconst_traits {};

struct _Rb_tree_node_base;
template <typename T> struct _Rb_tree_node;
template <typename T, typename Traits> struct _Rb_tree_iterator;

template <typename T1, typename T2> struct pair { T1 first; T2 second; };

template <bool b, int n> struct __node_alloc;
template <unsigned int N> struct _Base_bitset;

template <typename T, typename Alloc> struct vector;
template <typename T, typename Alloc> struct list;
template <typename T, typename Alloc> struct deque;
template <typename T, typename Container> struct stack;

template <typename Key, typename Value, typename KeyOfValue,
          typename Compare, typename Alloc>
struct _Rb_tree;

template <bool b> struct _Rb_global;

template <typename T, typename Alloc> struct _Deque_base;
template <typename T, typename Alloc> struct _List_base;
template <typename T, typename Alloc> struct _String_base;

template <typename Char, typename Traits, typename Alloc>
struct basic_string;

template <unsigned int N, typename T, typename Alloc> struct byte_key_map;

struct basic_string_ref;
struct basic_string_ref2;

namespace EA { namespace UnitTest { struct Test; } }

#endif // STL_TYPES_H