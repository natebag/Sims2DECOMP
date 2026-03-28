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
struct CTilePt { short x; short y; };
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
// InteractorModule is declared as a namespace below
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
struct PersDataPair { int a; int b; };
struct PrimitiveSample;
struct ReconBuffer;
struct RelArray;
struct RelInt;
struct ResFile;
struct Room;
struct RouteGoal;
struct RoutingSlot;
struct ScoredInteraction { int a; int b; int c; int d; };
struct SimTickSample;
struct SlotDescriptor;
struct SlotLoader;
struct SndInstruction;
struct SoundEventInfo { int a; int b; int c; };
struct SpriteSlot;
struct StackElem { void* data; };
struct StackString;
struct StateMachineStatus;
struct TreeTableAdQuickData;
struct TreeTableEntryQuickData;
struct XObjLang;
struct XRoute { int a; int b; };
struct cBoxX;
struct cHitControlGroup;
struct cTrack;
struct cXObject;
struct cXObjectImpl;
struct iResFile;
struct lua_State;
struct model_dat { int a; int b; int c; int d; int e; };
struct FileRec { int a; int b; int c; };
struct NamespaceSelector { int a; int b; int c; struct DataCache { int field8; void* field12; int field16; }; };
struct DiagonalNode { int a; int b; };
struct ObjectDataID { unsigned int a; unsigned int b; };

// Nested type forward declarations
namespace AutomationNS { struct LuaTable; }
struct ERDataset { struct ResourceInfo; };
struct EResourceManager { struct ResourceIndexRecord; static void* Alloc(unsigned long size, unsigned int align); static void Free(void* ptr); };
struct CasGenetics { struct Grandparent; };
struct ISmartDataFactory { struct tDataProvider { int a; int b; int c; }; };

namespace InteractorModule {
    struct FloorData;
    struct WallData;
    struct WallPaperData;
    struct Interactor;
    struct InteractorInfo;
    struct InteractorType;
    struct InteractorResourceSet;
    struct InvStock { int a; int b; };
    struct PatternSellCount;
    struct FenceSellCount;
    struct PlacementObject { struct ContainerInfo; };
    struct InteractorManager { struct ActiveInteractor; };
    struct InteractorInputManager { struct InteractorCommand; };
}

struct FAMTarget { struct FAM_STATE; };
struct MMUTarget { struct MMU_MENU_STATE; };
struct ACTTarget { struct iqRecord { int a; int b; int c; }; };

// STL-like types (SN Systems / Metrowerks STL)
template <typename T> struct allocator {};
template <typename T> struct char_traits {};
template <typename T> struct less {};
template <typename T> struct greater {};
template <typename T> struct equal_to {};
template <typename T> struct _Identity {};
template <typename T> struct _Select1st {};
template <typename T, typename U> struct _Nonconst_traits {};

struct _Rb_tree_node_base {
    int _M_color;
    _Rb_tree_node_base* _M_parent;
    _Rb_tree_node_base* _M_left;
    _Rb_tree_node_base* _M_right;
};
template <typename T>
struct _Rb_tree_node : _Rb_tree_node_base {
    T _M_value_field;
};
template <typename T, typename Traits> struct _Rb_tree_iterator;

template <typename T1, typename T2> struct pair { T1 first; T2 second; };

template <bool b, int n> struct __node_alloc;
template <unsigned int N> struct _Base_bitset;

template <typename T, typename Alloc>
struct vector {
    T* _M_start;
    T* _M_finish;
    T* _M_end_of_storage;
    void reserve(unsigned int n);
    void _M_fill_insert(T* pos, unsigned int n, const T& val);
    vector<T, Alloc>& operator=(const vector<T, Alloc>& rhs);
};

template <typename T, typename Alloc> struct list;
template <typename T, typename Alloc> struct deque;
template <typename T, typename Container> struct stack;

template <typename Key, typename Value, typename KeyOfValue,
          typename Compare, typename Alloc>
struct _Rb_tree {
    void _M_erase(_Rb_tree_node<Value>* x);
    void* _M_insert(void* x, void* y, const Value& v);
    void* insert_unique(const Value& v);
    void* insert_equal(const Value& v);
    void* insert_unique(void* hint, const Value& v);
};

template <bool b> struct _Rb_global;

template <typename T, typename Alloc>
struct _Deque_base {
    void _M_create_nodes(T** nstart, T** nfinish);
    void _M_destroy_nodes(T** nstart, T** nfinish);
    void _M_initialize_map(unsigned int num);
    ~_Deque_base(void);
};

template <typename T, typename Alloc>
struct _List_base {
    void clear(void);
};
template <typename T, typename Alloc> struct _String_base;

template <typename T, typename Alloc>
struct deque : _Deque_base<T, Alloc> {
    void _M_pop_back_aux(void);
    void _M_reallocate_map(unsigned int n, bool add_at_front);
    void _M_push_back_aux_v(const T& t);
};

template <typename Char, typename Traits, typename Alloc>
struct basic_string {
    Char* _M_start;
    Char* _M_finish;
    basic_string(void);
    basic_string(const Char* s);
    basic_string(const basic_string& other);
    ~basic_string(void);
    void reserve(unsigned int n);
};

template <unsigned int N, typename T, typename Alloc> struct byte_key_map;

struct basic_string_ref {
    char* m_ptr;
    unsigned int m_length;
    unsigned int m_capacity;
    int m_refCount;
    void delete_ptr(void);
    basic_string_ref(unsigned int size, int mode);
    basic_string_ref(void* src, unsigned int offset, unsigned int len);
    basic_string_ref(char* src, unsigned int len, unsigned int cap);
};
struct basic_string_ref2;

namespace EA { namespace UnitTest { struct Test; } }

#endif // STL_TYPES_H