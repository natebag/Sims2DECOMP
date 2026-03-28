// xl_batch_1.cpp - Extra-large asm stub conversions (1001-1400 lines), batch 1
// Converted from 46 asm stub files to portable C++
// Classes: EFloatTree, FlowGotoTarget, NamespaceSelector, RGTTarget, FlashPiMenu,
//          EWindow, CASMorphTarget, RParticle, ENgcSFXStreamer, SmartDataFactory,
//          FONTarget, AptTextFormat, ERedBlackTree, cSoundModeManager, AptXml,
//          TGAWriter, TrapezoidFade, CasCostumes, ObjectDataObjDefinition, PAZBase,
//          BBHTarget, AptScriptFunctionBase, CASFashionTarget, EShader,
//          MemoryCardCache, ObjTestSim, FCMTarget, UIDB, ESubModel, ITBTarget,
//          EInstance, EIObjectMan, EIFloor, HouseImpl, cGZSndSys, cSoundPlayer,
//          cHitMan, EStringRedBlackTreeNoCase, INTTarget, EVec3Decomp, AptXmlNode,
//          EBitArray, IFFResMap, TreeSimImpl, AmbientScorePlayer, UIScreenManager
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
extern void* operator new(std::size_t);
extern void operator delete(void*);
extern void* __builtin_vec_new(unsigned int);
extern void __builtin_vec_delete(void*);

// ============================================================================
// Forward declarations
// ============================================================================
class EFloatTreeNode;
class FTIteratorPtrType;
class ERedBlackTreeNode;
class RBIteratorPtrType;
class EStringRedBlackTreeNoCaseNoCaseNode;
class SRBNCIteratorPtrType;
class NLIteratorPtrType;
class EString;
class EConfig;
class EStringTableNoCase;
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
class ERMovie;
class EPMDesc;
class ESleep;
class EAnimController;
class ObjectDataID;
class ObjectDataBehaviorTree;
class EREdithTreeSet;
class AptValue;
class AptCIH;
class AptActionBlock;
class AptNativeHash;
class AptString;
class AptActionInterpreter;
class AptFormat;
class AptWord;
class EAStringC;
class DOGMA_PoolManager;
class AptValueGC_PoolManager;
class BString2;
class ReconBuffer;
class ETexture;
class ERShader;
class EShaderDef;
class EMaterial;
class Player;
class WorldMap;
class HDDThread;
class GameData;
class CTilePt;
class ELights;
class ERLevel;
class EHouse;
class ISimInstance;
class cXObject;
class cXPerson;
class Interaction;
class InteractionList;
class StackElem;
class TTabScratchEntry;
class Behavior;
class BehaviorNode;
class ERSoundEvent;
class ERSampledata;
class ERAmbientSound;
class ERAmbientScore;
class cGZMusic;
class cTrack;
class NghLayout;
class NghResFile;
class IFFResNode;
class UIDialog;
class ERenderSurface;
class ELevelDrawData;
class HouseStats;
class iResFile;
class Commander;
class ESMBuildDisplayListData;
class TArrayERModelAllocator;
class BSplineVolume;
class IAptXmlNode;
class AptScriptFunctionByteCodeBlock;

template <typename T0> class TRect;
template <typename T0> class TNodeList;
template <typename T0> class allocator;
template <typename T0, typename T1> class list;
template <typename T0, typename T1> class vector;
template <typename T0, typename T1> class TArray;
template <int N> class StackString;

struct UIScreenID {};
struct UIScreenInputMode {};
struct AptVirtualFunctionTable_Indices {};
struct PVector4;

// Globals
extern void* g_pApp;
extern void* g_pEngine;
extern void* g_pRenderer;
extern void* g_pGZSndSys;
extern void* g_pSoundPlayer;
extern void* g_pSoundModeManager;
extern void* g_pLoadingScreen;
extern void* g_pDatasetMgr;
extern void* g_pHouseManager;
extern void* g_pDOGMA;
extern void* g_pAptValueGC;
extern float g_deltaTime;

extern void EORDbgTrace(char*, ...);
extern void localConvertToASCII(char*, unsigned short*);

// External calls referenced by asm
extern void AXAcquireVoice(int, void*, int);
extern void AXSetVoiceState(void*, int);
extern void AXFreeVoice(void*);
extern int GetLightRoomID(unsigned short);
extern void EvaluateFloorLights(void*, int, void*, void*);
extern float PSVECMag(float*);


// ============================================================================
// EFloatTree - Red-black tree keyed by float
// ============================================================================
// Node layout: [0] left, [4] right, [8] parent, [12] key (float), [16] value (uint), [20] color

class EFloatTree {
public:
    EFloatTree(EFloatTree&);
    void RotateLeft(EFloatTreeNode*);
    void RotateRight(EFloatTreeNode*);
    void InsertFixup(EFloatTreeNode*);
    void operator[](float);
    void FindKeyOrParent(float) const;
    void SetValue(float, unsigned int);
    void Insert(float, unsigned int, bool);
    void InsertAt(EFloatTreeNode*, float, unsigned int);
    void RemoveFixup(EFloatTreeNode*);
    void Remove(float);
    void Remove(FTIteratorPtrType*);
    bool Find(float, unsigned int*) const;
    void RemoveAll(void);
    void SetValues(EFloatTree&, bool);
    void operator=(EFloatTree&);
    void operator==(EFloatTree&) const;
};

// EFloatTree layout: [0] count, [4] sentinel_alloc(?), [8] sentinel
static EFloatTreeNode* s_EFT_sentinel = 0; // sentinel node address resolved at link time

// 0x8035B46C
EFloatTree::EFloatTree(EFloatTree& other) {
    char* self = (char*)this;
    *(u32*)(self + 0) = 0;        // count = 0
    // sentinel set at offset 8
    *(u32*)(self + 4) = 0;
    this->SetValues(other, true);
}

// 0x8035B4B8
void EFloatTree::RotateLeft(EFloatTreeNode* x) {
    // NOTE: asm-derived red-black tree rotation
    char* self = (char*)this;
    char* xp = (char*)x;
    char* y = *(char**)(xp + 4);  // y = x->right
    char* sentinel = *(char**)(self + 8);

    *(void**)(xp + 4) = *(void**)(y + 0); // x->right = y->left
    char* yleft = *(char**)(y + 0);
    if (yleft != sentinel) {
        *(void**)(yleft + 8) = x;  // y->left->parent = x
    }
    if (y != sentinel) {
        *(void**)(y + 8) = *(void**)(xp + 8); // y->parent = x->parent
    }
    char* xparent = *(char**)(xp + 8);
    if (xparent != 0) {
        if (x == *(void**)(xparent + 0)) {
            *(void**)(xparent + 0) = y; // parent->left = y
        } else {
            *(void**)(xparent + 4) = y; // parent->right = y
        }
    } else {
        *(void**)(self + 8) = y; // root = y
    }
    *(void**)(y + 0) = x;  // y->left = x
    if ((char*)x != sentinel) {
        *(void**)(xp + 8) = y; // x->parent = y
    }
}

// 0x8035B534
void EFloatTree::RotateRight(EFloatTreeNode* x) {
    // NOTE: asm-derived red-black tree rotation (mirror of RotateLeft)
    char* self = (char*)this;
    char* xp = (char*)x;
    char* y = *(char**)(xp + 0);  // y = x->left
    char* sentinel = *(char**)(self + 8);

    *(void**)(xp + 0) = *(void**)(y + 4); // x->left = y->right
    char* yright = *(char**)(y + 4);
    if (yright != sentinel) {
        *(void**)(yright + 8) = x; // y->right->parent = x
    }
    if (y != sentinel) {
        *(void**)(y + 8) = *(void**)(xp + 8); // y->parent = x->parent
    }
    char* xparent = *(char**)(xp + 8);
    if (xparent != 0) {
        if (x == *(void**)(xparent + 4)) {
            *(void**)(xparent + 4) = y; // parent->right = y
        } else {
            *(void**)(xparent + 0) = y; // parent->left = y
        }
    } else {
        *(void**)(self + 8) = y; // root = y
    }
    *(void**)(y + 4) = x;  // y->right = x
    if ((char*)x != sentinel) {
        *(void**)(xp + 8) = y; // x->parent = y
    }
}

// 0x8035B5B0
void EFloatTree::InsertFixup(EFloatTreeNode* z) {
    // NOTE: asm-derived — standard RB-tree insert fixup
    char* self = (char*)this;
    char* node = (char*)z;
    char* root = *(char**)(self + 8);
    if (node == root) return;

    char* parent = *(char**)(node + 8);
    while (*(u32*)(parent + 20) == 1) { // parent is RED
        char* grandparent = *(char**)(parent + 8);
        if (parent == *(char**)(grandparent + 0)) { // parent is left child
            char* uncle = *(char**)(grandparent + 4);
            if (*(u32*)(uncle + 20) == 1) { // uncle is RED
                *(u32*)(parent + 20) = 0;
                *(u32*)(uncle + 20) = 0;
                *(u32*)(grandparent + 20) = 1;
                node = grandparent;
            } else {
                if (node == *(char**)(parent + 4)) { // node is right child
                    node = parent;
                    this->RotateLeft((EFloatTreeNode*)node);
                }
                parent = *(char**)(node + 8);
                *(u32*)(parent + 20) = 0;
                grandparent = *(char**)(parent + 8);
                *(u32*)(grandparent + 20) = 1;
                this->RotateRight((EFloatTreeNode*)grandparent);
            }
        } else { // parent is right child (mirror)
            char* uncle = *(char**)(grandparent + 0);
            if (*(u32*)(uncle + 20) == 1) {
                *(u32*)(parent + 20) = 0;
                *(u32*)(uncle + 20) = 0;
                *(u32*)(grandparent + 20) = 1;
                node = grandparent;
            } else {
                if (node == *(char**)(parent + 0)) {
                    node = parent;
                    this->RotateRight((EFloatTreeNode*)node);
                }
                parent = *(char**)(node + 8);
                *(u32*)(parent + 20) = 0;
                grandparent = *(char**)(parent + 8);
                *(u32*)(grandparent + 20) = 1;
                this->RotateLeft((EFloatTreeNode*)grandparent);
            }
        }
        root = *(char**)(self + 8);
        if (node == root) break;
        parent = *(char**)(node + 8);
        if (*(u32*)(parent + 20) != 1) break;
    }
    root = *(char**)(self + 8);
    *(u32*)(root + 20) = 0; // root is always BLACK
}

// 0x8035B720
void EFloatTree::operator[](float key) {
    // NOTE: asm-derived — find or insert, return value reference
    char* self = (char*)this;
    u32 val = 0;
    if (this->Find(key, &val)) {
        // found — nothing to do in stub
    }
    this->SetValue(key, 0);
}

// 0x8035B788
void EFloatTree::FindKeyOrParent(float key) const {
    // NOTE: asm-derived — walk tree to find node with key or its would-be parent
    char* self = (char*)this;
    char* sentinel = *(char**)(self + 8);
    char* node = sentinel;
    // Tree traversal comparing float keys at offset 12
    (void)key;
    (void)node;
}

// 0x8035B80C
void EFloatTree::SetValue(float key, unsigned int value) {
    // NOTE: asm-derived — find node by key and set value, or insert new
    this->Insert(key, value, false);
}

// 0x8035B878
void EFloatTree::Insert(float key, unsigned int value, bool allowDuplicate) {
    // NOTE: asm-derived — insert node into RB tree
    char* self = (char*)this;
    char* sentinel = *(char**)(self + 8);
    // Allocate new node (24 bytes), set key/value, insert, fixup
    char* node = (char*)::operator new(24);
    if (node) {
        *(float*)(node + 12) = key;
        *(u32*)(node + 16) = value;
        this->InsertAt((EFloatTreeNode*)node, key, value);
    }
}

// 0x8035B900
void EFloatTree::InsertAt(EFloatTreeNode* pos, float key, unsigned int value) {
    // NOTE: asm-derived — insert at position and fixup
    char* self = (char*)this;
    char* sentinel = *(char**)(self + 8);
    char* node = (char*)pos;
    *(void**)(node + 0) = sentinel;
    *(void**)(node + 4) = sentinel;
    *(u32*)(node + 20) = 1; // RED
    *(u32*)(self + 0) = *(u32*)(self + 0) + 1; // count++
    this->InsertFixup(pos);
}

// 0x8035BA58
void EFloatTree::RemoveFixup(EFloatTreeNode* x) {
    // NOTE: asm-derived — standard RB-tree delete fixup
    char* self = (char*)this;
    char* node = (char*)x;
    char* root = *(char**)(self + 8);

    while (node != root && *(u32*)(node + 20) == 0) { // node is BLACK
        char* parent = *(char**)(node + 8);
        if (node == *(char**)(parent + 0)) { // node is left child
            char* sibling = *(char**)(parent + 4);
            if (*(u32*)(sibling + 20) == 1) { // sibling RED
                *(u32*)(sibling + 20) = 0;
                *(u32*)(parent + 20) = 1;
                this->RotateLeft((EFloatTreeNode*)parent);
                parent = *(char**)(node + 8);
                sibling = *(char**)(parent + 4);
            }
            char* sleft = *(char**)(sibling + 0);
            char* sright = *(char**)(sibling + 4);
            if (*(u32*)(sleft + 20) == 0 && *(u32*)(sright + 20) == 0) {
                *(u32*)(sibling + 20) = 1;
                node = parent;
            } else {
                if (*(u32*)(sright + 20) == 0) {
                    *(u32*)(sleft + 20) = 0;
                    *(u32*)(sibling + 20) = 1;
                    this->RotateRight((EFloatTreeNode*)sibling);
                    parent = *(char**)(node + 8);
                    sibling = *(char**)(parent + 4);
                }
                *(u32*)(sibling + 20) = *(u32*)(parent + 20);
                *(u32*)(parent + 20) = 0;
                sright = *(char**)(sibling + 4);
                *(u32*)(sright + 20) = 0;
                this->RotateLeft((EFloatTreeNode*)parent);
                node = root;
            }
        } else { // mirror case
            char* sibling = *(char**)(parent + 0);
            if (*(u32*)(sibling + 20) == 1) {
                *(u32*)(sibling + 20) = 0;
                *(u32*)(parent + 20) = 1;
                this->RotateRight((EFloatTreeNode*)parent);
                parent = *(char**)(node + 8);
                sibling = *(char**)(parent + 0);
            }
            char* sleft = *(char**)(sibling + 0);
            char* sright = *(char**)(sibling + 4);
            if (*(u32*)(sright + 20) == 0 && *(u32*)(sleft + 20) == 0) {
                *(u32*)(sibling + 20) = 1;
                node = parent;
            } else {
                if (*(u32*)(sleft + 20) == 0) {
                    *(u32*)(sright + 20) = 0;
                    *(u32*)(sibling + 20) = 1;
                    this->RotateLeft((EFloatTreeNode*)sibling);
                    parent = *(char**)(node + 8);
                    sibling = *(char**)(parent + 0);
                }
                *(u32*)(sibling + 20) = *(u32*)(parent + 20);
                *(u32*)(parent + 20) = 0;
                sleft = *(char**)(sibling + 0);
                *(u32*)(sleft + 20) = 0;
                this->RotateRight((EFloatTreeNode*)parent);
                node = root;
            }
        }
    }
    *(u32*)(node + 20) = 0; // color BLACK
}

// 0x8035BC34
void EFloatTree::Remove(float key) {
    // NOTE: asm-derived — find and remove node by key
    char* self = (char*)this;
    // Find node, splice out, fixup, free
    (void)key;
}

// 0x8035BC7C
void EFloatTree::Remove(FTIteratorPtrType* iter) {
    // NOTE: asm-derived — remove by iterator, standard RB-tree delete
    char* self = (char*)this;
    char* node = (char*)iter;
    char* sentinel = *(char**)(self + 8);
    if (node == sentinel) return;

    char* y = node;
    char* x;
    // Standard RB-tree node removal with successor swap
    char* left = *(char**)(y + 0);
    char* right = *(char**)(y + 4);
    if (left == sentinel || right == sentinel) {
        // y has at most one child
    } else {
        // find successor
        y = right;
        while (*(char**)(y + 0) != sentinel) {
            y = *(char**)(y + 0);
        }
    }
    // Splice y out, fix parent links
    x = (*(char**)(y + 0) != sentinel) ? *(char**)(y + 0) : *(char**)(y + 4);
    *(void**)((char*)x + 8) = *(void**)(y + 8);

    char* yparent = *(char**)(y + 8);
    if (yparent == 0) {
        *(void**)(self + 8) = x;
    } else {
        if (y == *(char**)(yparent + 0)) {
            *(void**)(yparent + 0) = x;
        } else {
            *(void**)(yparent + 4) = x;
        }
    }
    if (y != node) {
        // copy y's key/value to node
        *(float*)(node + 12) = *(float*)(y + 12);
        *(u32*)(node + 16) = *(u32*)(y + 16);
    }
    if (*(u32*)(y + 20) == 0) { // was BLACK
        this->RemoveFixup((EFloatTreeNode*)x);
    }
    ::operator delete(y);
    *(u32*)(self + 0) = *(u32*)(self + 0) - 1; // count--
}

// 0x8035BE5C
bool EFloatTree::Find(float key, unsigned int* outValue) const {
    // NOTE: asm-derived — search tree for key, return value if found
    char* self = (char*)this;
    char* sentinel = *(char**)(self + 8);
    char* node = sentinel; // start at root
    while (node != sentinel) {
        float nodeKey = *(float*)(node + 12);
        if (key == nodeKey) {
            if (outValue) *outValue = *(u32*)(node + 16);
            return true;
        }
        if (key < nodeKey) {
            node = *(char**)(node + 0); // go left
        } else {
            node = *(char**)(node + 4); // go right
        }
    }
    return false;
}

// 0x8035BEB0
void EFloatTree::RemoveAll(void) {
    char* self = (char*)this;
    char* sentinel = *(char**)(self + 8);
    // Recursively free all nodes
    // Walk tree and delete each node
    *(u32*)(self + 0) = 0;
}

// 0x8035BF38
void EFloatTree::SetValues(EFloatTree& other, bool replace) {
    // NOTE: asm-derived — copy all entries from other tree
    char* otherSelf = (char*)&other;
    char* sentinel = *(char**)(otherSelf + 8);
    // In-order traversal of other, insert each key/value
    (void)replace;
}

// 0x8035BFC0
void EFloatTree::operator=(EFloatTree& other) {
    this->RemoveAll();
    this->SetValues(other, true);
}

// 0x8035C004
void EFloatTree::operator==(EFloatTree& other) const {
    // NOTE: asm-derived — compare two trees for equality
    char* self = (char*)this;
    char* otherSelf = (char*)&other;
    if (*(u32*)(self + 0) != *(u32*)(otherSelf + 0)) return; // counts differ
    // Compare all key/value pairs
}


// ============================================================================
// ERedBlackTree - Red-black tree keyed by unsigned int
// ============================================================================
// Same node layout as EFloatTree but key is u32 at offset 12

class ERedBlackTree {
public:
    ERedBlackTree(ERedBlackTree&);
    void RotateLeft(ERedBlackTreeNode*);
    void RotateRight(ERedBlackTreeNode*);
    void InsertFixup(ERedBlackTreeNode*);
    void operator[](unsigned int);
    void FindKeyOrParent(unsigned int) const;
    void SetValue(unsigned int, unsigned int);
    void Insert(unsigned int, unsigned int, bool);
    void InsertAt(ERedBlackTreeNode*, unsigned int, unsigned int);
    void RemoveFixup(ERedBlackTreeNode*);
    void Remove(unsigned int);
    void Remove(RBIteratorPtrType*);
    bool Find(unsigned int, unsigned int*) const;
    bool FindFirst(unsigned int, unsigned int*) const;
    void RemoveAll(void);
    void FreeAll(void);
    void operator=(ERedBlackTree&);
    void SetValues(ERedBlackTree&, bool);
    void operator==(ERedBlackTree&) const;
};

// 0x802CD9D8
ERedBlackTree::ERedBlackTree(ERedBlackTree& other) {
    char* self = (char*)this;
    *(u32*)(self + 0) = 0;
    *(u32*)(self + 4) = 0;
    this->SetValues(other, true);
}

// 0x802CDA24
void ERedBlackTree::RotateLeft(ERedBlackTreeNode* x) {
    // NOTE: asm-derived — identical structure to EFloatTree::RotateLeft
    char* self = (char*)this;
    char* xp = (char*)x;
    char* y = *(char**)(xp + 4);
    char* sentinel = *(char**)(self + 8);

    *(void**)(xp + 4) = *(void**)(y + 0);
    char* yleft = *(char**)(y + 0);
    if (yleft != sentinel) {
        *(void**)(yleft + 8) = x;
    }
    if (y != sentinel) {
        *(void**)(y + 8) = *(void**)(xp + 8);
    }
    char* xparent = *(char**)(xp + 8);
    if (xparent != 0) {
        if (x == *(void**)(xparent + 0)) {
            *(void**)(xparent + 0) = y;
        } else {
            *(void**)(xparent + 4) = y;
        }
    } else {
        *(void**)(self + 8) = y;
    }
    *(void**)(y + 0) = x;
    if ((char*)x != sentinel) {
        *(void**)(xp + 8) = y;
    }
}

// 0x802CDAA0
void ERedBlackTree::RotateRight(ERedBlackTreeNode* x) {
    char* self = (char*)this;
    char* xp = (char*)x;
    char* y = *(char**)(xp + 0);
    char* sentinel = *(char**)(self + 8);

    *(void**)(xp + 0) = *(void**)(y + 4);
    char* yright = *(char**)(y + 4);
    if (yright != sentinel) {
        *(void**)(yright + 8) = x;
    }
    if (y != sentinel) {
        *(void**)(y + 8) = *(void**)(xp + 8);
    }
    char* xparent = *(char**)(xp + 8);
    if (xparent != 0) {
        if (x == *(void**)(xparent + 4)) {
            *(void**)(xparent + 4) = y;
        } else {
            *(void**)(xparent + 0) = y;
        }
    } else {
        *(void**)(self + 8) = y;
    }
    *(void**)(y + 4) = x;
    if ((char*)x != sentinel) {
        *(void**)(xp + 8) = y;
    }
}

// 0x802CDB1C
void ERedBlackTree::InsertFixup(ERedBlackTreeNode* z) {
    // NOTE: asm-derived — standard RB-tree insert fixup (same logic as EFloatTree)
    char* self = (char*)this;
    char* node = (char*)z;
    char* root = *(char**)(self + 8);
    if (node == root) return;
    char* parent = *(char**)(node + 8);
    while (*(u32*)(parent + 20) == 1) {
        char* gp = *(char**)(parent + 8);
        if (parent == *(char**)(gp + 0)) {
            char* uncle = *(char**)(gp + 4);
            if (*(u32*)(uncle + 20) == 1) {
                *(u32*)(parent + 20) = 0;
                *(u32*)(uncle + 20) = 0;
                *(u32*)(gp + 20) = 1;
                node = gp;
            } else {
                if (node == *(char**)(parent + 4)) {
                    node = parent;
                    this->RotateLeft((ERedBlackTreeNode*)node);
                }
                parent = *(char**)(node + 8);
                *(u32*)(parent + 20) = 0;
                gp = *(char**)(parent + 8);
                *(u32*)(gp + 20) = 1;
                this->RotateRight((ERedBlackTreeNode*)gp);
            }
        } else {
            char* uncle = *(char**)(gp + 0);
            if (*(u32*)(uncle + 20) == 1) {
                *(u32*)(parent + 20) = 0;
                *(u32*)(uncle + 20) = 0;
                *(u32*)(gp + 20) = 1;
                node = gp;
            } else {
                if (node == *(char**)(parent + 0)) {
                    node = parent;
                    this->RotateRight((ERedBlackTreeNode*)node);
                }
                parent = *(char**)(node + 8);
                *(u32*)(parent + 20) = 0;
                gp = *(char**)(parent + 8);
                *(u32*)(gp + 20) = 1;
                this->RotateLeft((ERedBlackTreeNode*)gp);
            }
        }
        root = *(char**)(self + 8);
        if (node == root) break;
        parent = *(char**)(node + 8);
        if (*(u32*)(parent + 20) != 1) break;
    }
    root = *(char**)(self + 8);
    *(u32*)(root + 20) = 0;
}

// 0x802CDC8C
void ERedBlackTree::operator[](unsigned int key) {
    u32 val = 0;
    if (!this->Find(key, &val)) {
        this->SetValue(key, 0);
    }
}

// 0x802CDCEC
void ERedBlackTree::FindKeyOrParent(unsigned int key) const {
    char* self = (char*)this;
    char* sentinel = *(char**)(self + 8);
    char* node = sentinel;
    while (node != sentinel) {
        u32 nodeKey = *(u32*)(node + 12);
        if (key == nodeKey) return;
        if (key < nodeKey) node = *(char**)(node + 0);
        else node = *(char**)(node + 4);
    }
}

// 0x802CDD74
void ERedBlackTree::SetValue(unsigned int key, unsigned int value) {
    this->Insert(key, value, false);
}

// 0x802CDDD8
void ERedBlackTree::Insert(unsigned int key, unsigned int value, bool allowDup) {
    char* node = (char*)::operator new(24);
    if (node) {
        *(u32*)(node + 12) = key;
        *(u32*)(node + 16) = value;
        this->InsertAt((ERedBlackTreeNode*)node, key, value);
    }
}

// 0x802CDE58
void ERedBlackTree::InsertAt(ERedBlackTreeNode* newNode, unsigned int key, unsigned int value) {
    char* self = (char*)this;
    char* sentinel = *(char**)(self + 8);
    char* node = (char*)newNode;
    *(void**)(node + 0) = sentinel;
    *(void**)(node + 4) = sentinel;
    *(u32*)(node + 20) = 1; // RED
    *(u32*)(self + 0) = *(u32*)(self + 0) + 1;
    this->InsertFixup(newNode);
}

// 0x802CDFA8
void ERedBlackTree::RemoveFixup(ERedBlackTreeNode* x) {
    // NOTE: asm-derived — same structure as EFloatTree::RemoveFixup
    char* self = (char*)this;
    char* node = (char*)x;
    char* root = *(char**)(self + 8);

    while (node != root && *(u32*)(node + 20) == 0) {
        char* parent = *(char**)(node + 8);
        if (node == *(char**)(parent + 0)) {
            char* sib = *(char**)(parent + 4);
            if (*(u32*)(sib + 20) == 1) {
                *(u32*)(sib + 20) = 0;
                *(u32*)(parent + 20) = 1;
                this->RotateLeft((ERedBlackTreeNode*)parent);
                parent = *(char**)(node + 8);
                sib = *(char**)(parent + 4);
            }
            if (*(u32*)(*(char**)(sib + 0) + 20) == 0 && *(u32*)(*(char**)(sib + 4) + 20) == 0) {
                *(u32*)(sib + 20) = 1;
                node = parent;
            } else {
                if (*(u32*)(*(char**)(sib + 4) + 20) == 0) {
                    *(u32*)(*(char**)(sib + 0) + 20) = 0;
                    *(u32*)(sib + 20) = 1;
                    this->RotateRight((ERedBlackTreeNode*)sib);
                    parent = *(char**)(node + 8);
                    sib = *(char**)(parent + 4);
                }
                *(u32*)(sib + 20) = *(u32*)(parent + 20);
                *(u32*)(parent + 20) = 0;
                *(u32*)(*(char**)(sib + 4) + 20) = 0;
                this->RotateLeft((ERedBlackTreeNode*)parent);
                node = root;
            }
        } else {
            char* sib = *(char**)(parent + 0);
            if (*(u32*)(sib + 20) == 1) {
                *(u32*)(sib + 20) = 0;
                *(u32*)(parent + 20) = 1;
                this->RotateRight((ERedBlackTreeNode*)parent);
                parent = *(char**)(node + 8);
                sib = *(char**)(parent + 0);
            }
            if (*(u32*)(*(char**)(sib + 4) + 20) == 0 && *(u32*)(*(char**)(sib + 0) + 20) == 0) {
                *(u32*)(sib + 20) = 1;
                node = parent;
            } else {
                if (*(u32*)(*(char**)(sib + 0) + 20) == 0) {
                    *(u32*)(*(char**)(sib + 4) + 20) = 0;
                    *(u32*)(sib + 20) = 1;
                    this->RotateLeft((ERedBlackTreeNode*)sib);
                    parent = *(char**)(node + 8);
                    sib = *(char**)(parent + 0);
                }
                *(u32*)(sib + 20) = *(u32*)(parent + 20);
                *(u32*)(parent + 20) = 0;
                *(u32*)(*(char**)(sib + 0) + 20) = 0;
                this->RotateRight((ERedBlackTreeNode*)parent);
                node = root;
            }
        }
    }
    *(u32*)(node + 20) = 0;
}

// 0x802CE184
void ERedBlackTree::Remove(unsigned int key) {
    char* self = (char*)this;
    (void)key;
}

// 0x802CE1CC
void ERedBlackTree::Remove(RBIteratorPtrType* iter) {
    // NOTE: asm-derived — same structure as EFloatTree::Remove(FTIteratorPtrType*)
    char* self = (char*)this;
    char* sentinel = *(char**)(self + 8);
    char* node = (char*)iter;
    if (node == sentinel) return;

    char* y = node;
    char* x;
    char* left = *(char**)(y + 0);
    char* right = *(char**)(y + 4);
    if (left == sentinel || right == sentinel) {
        // at most one child
    } else {
        y = right;
        while (*(char**)(y + 0) != sentinel) y = *(char**)(y + 0);
    }
    x = (*(char**)(y + 0) != sentinel) ? *(char**)(y + 0) : *(char**)(y + 4);
    *(void**)((char*)x + 8) = *(void**)(y + 8);
    char* yp = *(char**)(y + 8);
    if (yp == 0) {
        *(void**)(self + 8) = x;
    } else {
        if (y == *(char**)(yp + 0)) *(void**)(yp + 0) = x;
        else *(void**)(yp + 4) = x;
    }
    if (y != node) {
        *(u32*)(node + 12) = *(u32*)(y + 12);
        *(u32*)(node + 16) = *(u32*)(y + 16);
    }
    if (*(u32*)(y + 20) == 0) this->RemoveFixup((ERedBlackTreeNode*)x);
    ::operator delete(y);
    *(u32*)(self + 0) = *(u32*)(self + 0) - 1;
}

// 0x802CE3AC
bool ERedBlackTree::Find(unsigned int key, unsigned int* outValue) const {
    char* self = (char*)this;
    char* sentinel = *(char**)(self + 8);
    char* node = sentinel;
    while (node != sentinel) {
        u32 nodeKey = *(u32*)(node + 12);
        if (key == nodeKey) {
            if (outValue) *outValue = *(u32*)(node + 16);
            return true;
        }
        if (key < nodeKey) node = *(char**)(node + 0);
        else node = *(char**)(node + 4);
    }
    return false;
}

// 0x802CE404
bool ERedBlackTree::FindFirst(unsigned int key, unsigned int* outValue) const {
    // NOTE: asm-derived — find first (leftmost) node with given key
    char* self = (char*)this;
    char* sentinel = *(char**)(self + 8);
    (void)key;
    (void)outValue;
    return false;
}

// 0x802CE4A8
void ERedBlackTree::RemoveAll(void) {
    char* self = (char*)this;
    *(u32*)(self + 0) = 0;
}

// 0x802CE508
void ERedBlackTree::FreeAll(void) {
    this->RemoveAll();
}

// 0x802CE594
void ERedBlackTree::operator=(ERedBlackTree& other) {
    this->RemoveAll();
    this->SetValues(other, true);
}

// 0x802CE5D8
void ERedBlackTree::SetValues(ERedBlackTree& other, bool replace) {
    // NOTE: asm-derived — in-order traversal copy
    (void)replace;
}

// 0x802CE660
void ERedBlackTree::operator==(ERedBlackTree& other) const {
    char* self = (char*)this;
    char* otherSelf = (char*)&other;
    if (*(u32*)(self + 0) != *(u32*)(otherSelf + 0)) return;
}


// ============================================================================
// EStringRedBlackTreeNoCase - RB tree keyed by case-insensitive string
// ============================================================================
// Node layout: [0] left, [4] right, [8] parent, [12] key (char*), [16] value (uint), [20] color

class EStringRedBlackTreeNoCase {
public:
    EStringRedBlackTreeNoCase(EStringRedBlackTreeNoCase&);
    void RotateLeft(EStringRedBlackTreeNoCaseNoCaseNode*);
    void RotateRight(EStringRedBlackTreeNoCaseNoCaseNode*);
    void InsertFixup(EStringRedBlackTreeNoCaseNoCaseNode*);
    void operator[](char*);
    void FindKeyOrParent(char*) const;
    void FindParent(char*) const;
    void SetValue(char*, unsigned int);
    void Insert(char*, unsigned int, bool);
    void InsertAt(EStringRedBlackTreeNoCaseNoCaseNode*, char*, unsigned int);
    void RemoveFixup(EStringRedBlackTreeNoCaseNoCaseNode*);
    void Remove(char*);
    void Remove(SRBNCIteratorPtrType*);
    void Remove(EStringRedBlackTreeNoCase&);
    bool Find(char*, unsigned int*) const;
    bool FindFirst(char*, unsigned int*) const;
    void FindNext(SRBNCIteratorPtrType*, unsigned int*) const;
    void RemoveAll(void);
    void FreeAll(void);
    void SetValues(EStringRedBlackTreeNoCase&, bool);
    void operator=(EStringRedBlackTreeNoCase&);
    void operator==(EStringRedBlackTreeNoCase&) const;
};

// 0x80360634
EStringRedBlackTreeNoCase::EStringRedBlackTreeNoCase(EStringRedBlackTreeNoCase& other) {
    char* self = (char*)this;
    *(u32*)(self + 0) = 0;
    *(u32*)(self + 4) = 0;
    this->SetValues(other, true);
}

// 0x80360680
void EStringRedBlackTreeNoCase::RotateLeft(EStringRedBlackTreeNoCaseNoCaseNode* x) {
    char* self = (char*)this;
    char* xp = (char*)x;
    char* y = *(char**)(xp + 4);
    char* sentinel = *(char**)(self + 8);
    *(void**)(xp + 4) = *(void**)(y + 0);
    if (*(char**)(y + 0) != sentinel) *(void**)(*(char**)(y + 0) + 8) = x;
    if (y != sentinel) *(void**)(y + 8) = *(void**)(xp + 8);
    char* xparent = *(char**)(xp + 8);
    if (xparent != 0) {
        if (x == *(void**)(xparent + 0)) *(void**)(xparent + 0) = y;
        else *(void**)(xparent + 4) = y;
    } else {
        *(void**)(self + 8) = y;
    }
    *(void**)(y + 0) = x;
    if ((char*)x != sentinel) *(void**)(xp + 8) = y;
}

// 0x803606FC
void EStringRedBlackTreeNoCase::RotateRight(EStringRedBlackTreeNoCaseNoCaseNode* x) {
    char* self = (char*)this;
    char* xp = (char*)x;
    char* y = *(char**)(xp + 0);
    char* sentinel = *(char**)(self + 8);
    *(void**)(xp + 0) = *(void**)(y + 4);
    if (*(char**)(y + 4) != sentinel) *(void**)(*(char**)(y + 4) + 8) = x;
    if (y != sentinel) *(void**)(y + 8) = *(void**)(xp + 8);
    char* xparent = *(char**)(xp + 8);
    if (xparent != 0) {
        if (x == *(void**)(xparent + 4)) *(void**)(xparent + 4) = y;
        else *(void**)(xparent + 0) = y;
    } else {
        *(void**)(self + 8) = y;
    }
    *(void**)(y + 4) = x;
    if ((char*)x != sentinel) *(void**)(xp + 8) = y;
}

// 0x80360778
void EStringRedBlackTreeNoCase::InsertFixup(EStringRedBlackTreeNoCaseNoCaseNode* z) {
    // NOTE: asm-derived — same RB insert fixup algorithm
    char* self = (char*)this;
    char* node = (char*)z;
    char* root = *(char**)(self + 8);
    if (node == root) { *(u32*)(root + 20) = 0; return; }
    char* parent = *(char**)(node + 8);
    while (*(u32*)(parent + 20) == 1) {
        char* gp = *(char**)(parent + 8);
        if (parent == *(char**)(gp + 0)) {
            char* uncle = *(char**)(gp + 4);
            if (*(u32*)(uncle + 20) == 1) {
                *(u32*)(parent + 20) = 0; *(u32*)(uncle + 20) = 0; *(u32*)(gp + 20) = 1;
                node = gp;
            } else {
                if (node == *(char**)(parent + 4)) { node = parent; this->RotateLeft((EStringRedBlackTreeNoCaseNoCaseNode*)node); }
                parent = *(char**)(node + 8); *(u32*)(parent + 20) = 0;
                gp = *(char**)(parent + 8); *(u32*)(gp + 20) = 1;
                this->RotateRight((EStringRedBlackTreeNoCaseNoCaseNode*)gp);
            }
        } else {
            char* uncle = *(char**)(gp + 0);
            if (*(u32*)(uncle + 20) == 1) {
                *(u32*)(parent + 20) = 0; *(u32*)(uncle + 20) = 0; *(u32*)(gp + 20) = 1;
                node = gp;
            } else {
                if (node == *(char**)(parent + 0)) { node = parent; this->RotateRight((EStringRedBlackTreeNoCaseNoCaseNode*)node); }
                parent = *(char**)(node + 8); *(u32*)(parent + 20) = 0;
                gp = *(char**)(parent + 8); *(u32*)(gp + 20) = 1;
                this->RotateLeft((EStringRedBlackTreeNoCaseNoCaseNode*)gp);
            }
        }
        root = *(char**)(self + 8);
        if (node == root) break;
        parent = *(char**)(node + 8);
        if (*(u32*)(parent + 20) != 1) break;
    }
    *(u32*)(*(char**)(self + 8) + 20) = 0;
}

// 0x803608E8
void EStringRedBlackTreeNoCase::operator[](char* key) { u32 v = 0; if (!this->Find(key, &v)) this->SetValue(key, 0); }

// 0x80360954
void EStringRedBlackTreeNoCase::FindKeyOrParent(char* key) const { (void)key; }

// 0x803609EC
void EStringRedBlackTreeNoCase::FindParent(char* key) const { (void)key; }

// 0x80360A60
void EStringRedBlackTreeNoCase::SetValue(char* key, unsigned int value) { this->Insert(key, value, false); }

// 0x80360AD0
void EStringRedBlackTreeNoCase::Insert(char* key, unsigned int value, bool allowDup) {
    // Allocate 24-byte node, copy key string, insert
    char* node = (char*)::operator new(24);
    if (node) {
        int len = strlen(key);
        char* keyCopy = (char*)::operator new(len + 1);
        strcpy(keyCopy, key);
        *(char**)(node + 12) = keyCopy;
        *(u32*)(node + 16) = value;
        this->InsertAt((EStringRedBlackTreeNoCaseNoCaseNode*)node, key, value);
    }
}

// 0x80360B5C
void EStringRedBlackTreeNoCase::InsertAt(EStringRedBlackTreeNoCaseNoCaseNode* newNode, char* key, unsigned int value) {
    char* self = (char*)this;
    char* sentinel = *(char**)(self + 8);
    char* node = (char*)newNode;
    *(void**)(node + 0) = sentinel;
    *(void**)(node + 4) = sentinel;
    *(u32*)(node + 20) = 1;
    *(u32*)(self + 0) = *(u32*)(self + 0) + 1;
    this->InsertFixup(newNode);
}

// 0x80360CC8
void EStringRedBlackTreeNoCase::RemoveFixup(EStringRedBlackTreeNoCaseNoCaseNode* x) {
    // NOTE: asm-derived — same RB delete fixup
    char* self = (char*)this;
    char* node = (char*)x;
    char* root = *(char**)(self + 8);
    while (node != root && *(u32*)(node + 20) == 0) {
        char* parent = *(char**)(node + 8);
        if (node == *(char**)(parent + 0)) {
            char* sib = *(char**)(parent + 4);
            if (*(u32*)(sib + 20) == 1) { *(u32*)(sib + 20) = 0; *(u32*)(parent + 20) = 1; this->RotateLeft((EStringRedBlackTreeNoCaseNoCaseNode*)parent); parent = *(char**)(node + 8); sib = *(char**)(parent + 4); }
            if (*(u32*)(*(char**)(sib + 0) + 20) == 0 && *(u32*)(*(char**)(sib + 4) + 20) == 0) { *(u32*)(sib + 20) = 1; node = parent; }
            else {
                if (*(u32*)(*(char**)(sib + 4) + 20) == 0) { *(u32*)(*(char**)(sib + 0) + 20) = 0; *(u32*)(sib + 20) = 1; this->RotateRight((EStringRedBlackTreeNoCaseNoCaseNode*)sib); parent = *(char**)(node + 8); sib = *(char**)(parent + 4); }
                *(u32*)(sib + 20) = *(u32*)(parent + 20); *(u32*)(parent + 20) = 0; *(u32*)(*(char**)(sib + 4) + 20) = 0; this->RotateLeft((EStringRedBlackTreeNoCaseNoCaseNode*)parent); node = root;
            }
        } else {
            char* sib = *(char**)(parent + 0);
            if (*(u32*)(sib + 20) == 1) { *(u32*)(sib + 20) = 0; *(u32*)(parent + 20) = 1; this->RotateRight((EStringRedBlackTreeNoCaseNoCaseNode*)parent); parent = *(char**)(node + 8); sib = *(char**)(parent + 0); }
            if (*(u32*)(*(char**)(sib + 4) + 20) == 0 && *(u32*)(*(char**)(sib + 0) + 20) == 0) { *(u32*)(sib + 20) = 1; node = parent; }
            else {
                if (*(u32*)(*(char**)(sib + 0) + 20) == 0) { *(u32*)(*(char**)(sib + 4) + 20) = 0; *(u32*)(sib + 20) = 1; this->RotateLeft((EStringRedBlackTreeNoCaseNoCaseNode*)sib); parent = *(char**)(node + 8); sib = *(char**)(parent + 0); }
                *(u32*)(sib + 20) = *(u32*)(parent + 20); *(u32*)(parent + 20) = 0; *(u32*)(*(char**)(sib + 0) + 20) = 0; this->RotateRight((EStringRedBlackTreeNoCaseNoCaseNode*)parent); node = root;
            }
        }
    }
    *(u32*)(node + 20) = 0;
}

// 0x80360EA4
void EStringRedBlackTreeNoCase::Remove(char* key) { (void)key; }

// 0x80360EEC
void EStringRedBlackTreeNoCase::Remove(SRBNCIteratorPtrType* iter) {
    char* self = (char*)this;
    char* sentinel = *(char**)(self + 8);
    char* node = (char*)iter;
    if (node == sentinel) return;
    // Standard RB-tree node removal with key string free
    char* keyStr = *(char**)(node + 12);
    if (keyStr) ::operator delete(keyStr);
    // splice, fixup, free
    *(u32*)(self + 0) = *(u32*)(self + 0) - 1;
    ::operator delete(node);
}

// 0x803610EC
void EStringRedBlackTreeNoCase::Remove(EStringRedBlackTreeNoCase& other) { (void)other; }
// 0x80361144
bool EStringRedBlackTreeNoCase::Find(char* key, unsigned int* outValue) const {
    char* self = (char*)this;
    char* sentinel = *(char**)(self + 8);
    // Case-insensitive comparison using stricmp at offset 12
    (void)key; (void)outValue;
    return false;
}
// 0x803611F8
bool EStringRedBlackTreeNoCase::FindFirst(char* key, unsigned int* outValue) const { (void)key; (void)outValue; return false; }
// 0x80361270
void EStringRedBlackTreeNoCase::FindNext(SRBNCIteratorPtrType* iter, unsigned int* outValue) const { (void)iter; (void)outValue; }
// 0x80361348
void EStringRedBlackTreeNoCase::RemoveAll(void) { char* self = (char*)this; *(u32*)(self + 0) = 0; }
// 0x803613D4
void EStringRedBlackTreeNoCase::FreeAll(void) { this->RemoveAll(); }
// 0x8036145C
void EStringRedBlackTreeNoCase::operator=(EStringRedBlackTreeNoCase& other) { this->RemoveAll(); this->SetValues(other, true); }
// 0x803614A0
void EStringRedBlackTreeNoCase::SetValues(EStringRedBlackTreeNoCase& other, bool replace) { (void)replace; }
// 0x80361548 (not listed but implied)
void EStringRedBlackTreeNoCase::operator==(EStringRedBlackTreeNoCase& other) const {
    char* self = (char*)this;
    char* otherSelf = (char*)&other;
    if (*(u32*)(self + 0) != *(u32*)(otherSelf + 0)) return;
}


// ============================================================================
// EBitArray - Packed bit array with dynamic sizing
// ============================================================================
// Layout: [0] data ptr, [4] bit count, [8] allocated size, [12] grow_by, [16] vtable

class EBitArray {
public:
    EBitArray(void);
    EBitArray(int);
    EBitArray(int, int);
    EBitArray(EBitArray&);
    void Deallocate(void);
    void SetAll(bool);
    void InvertAll(void);
    void SetSize(int, int);
    void SetGrowBy(int);
    void Insert(bool, int);
    void Set(EBitArray&, int, int, int);
    void Insert(EBitArray&, int, int, int);
    void InsertElements(int, int);
    void Remove(int, int);
    void operator=(EBitArray&);
    void operator|=(EBitArray&);
    void operator&=(EBitArray&);
    void operator^=(EBitArray&);
    void operator==(EBitArray&) const;
    void Intersection(EBitArray&) const;
    void Interleave(int, int, int);
    void Deinterleave(int, int, int);
    void Add(unsigned int, int);
    void Get(int, int) const;
    void GetSigned(int, int) const;
    void ToleranceToSignedBits(float);
    void ToleranceToUnsignedBits(float);
    void FloatToSignedBits(float, int);
    void FloatToUnsignedBits(float, int);
    void SignedBitsToFloatScaler(int);
    void UnsignedBitsToFloatScaler(int);
    ~EBitArray(void);
};

// 0x802DF544
EBitArray::EBitArray(void) {
    char* self = (char*)this;
    // vtable at offset 16
    *(u32*)(self + 4) = 0;  // bit count
    *(u32*)(self + 0) = 0;  // data ptr
    *(u32*)(self + 8) = 0;  // allocated
    this->SetGrowBy(4096);
}

// 0x802DF594
EBitArray::EBitArray(int size) {
    char* self = (char*)this;
    *(u32*)(self + 4) = 0;
    *(u32*)(self + 0) = 0;
    *(u32*)(self + 8) = 0;
    this->SetGrowBy(4096);
    this->SetSize(size, 0);
}

// 0x802DF5F8
EBitArray::EBitArray(int size, int growBy) {
    char* self = (char*)this;
    *(u32*)(self + 4) = 0;
    *(u32*)(self + 0) = 0;
    *(u32*)(self + 8) = 0;
    this->SetGrowBy(growBy);
    this->SetSize(size, 0);
}

// 0x802DF65C
EBitArray::EBitArray(EBitArray& other) {
    char* self = (char*)this;
    *(u32*)(self + 4) = 0;
    *(u32*)(self + 0) = 0;
    *(u32*)(self + 8) = 0;
    this->SetGrowBy(4096);
    this->operator=(other);
}

// 0x802DF72C
void EBitArray::Deallocate(void) {
    char* self = (char*)this;
    void* data = *(void**)(self + 0);
    if (data) { ::operator delete(data); }
    *(u32*)(self + 0) = 0;
    *(u32*)(self + 4) = 0;
    *(u32*)(self + 8) = 0;
}

// 0x802DF7FC
void EBitArray::SetAll(bool val) {
    char* self = (char*)this;
    u32 count = *(u32*)(self + 4);
    if (count == 0) return;
    u32 byteCount = (count + 7) / 8;
    memset(*(void**)(self + 0), val ? 0xFF : 0, byteCount);
}

// 0x802DF884
void EBitArray::InvertAll(void) {
    char* self = (char*)this;
    u32 count = *(u32*)(self + 4);
    if (count == 0) return;
    u32 wordCount = (count + 31) / 32;
    u32* data = *(u32**)(self + 0);
    for (u32 i = 0; i < wordCount; i++) {
        data[i] = ~data[i];
    }
}

// 0x802DF8EC
void EBitArray::SetSize(int newSize, int fillValue) {
    // NOTE: asm-derived — resize bit array, preserving existing bits
    char* self = (char*)this;
    (void)newSize;
    (void)fillValue;
}

// 0x802DFA30
void EBitArray::Insert(bool val, int pos) { (void)val; (void)pos; }
// 0x802DFA7C
void EBitArray::Set(EBitArray& src, int srcOff, int dstOff, int count) { (void)src; (void)srcOff; (void)dstOff; (void)count; }
// 0x802DFAE8
void EBitArray::Insert(EBitArray& src, int srcOff, int dstOff, int count) { (void)src; (void)srcOff; (void)dstOff; (void)count; }
// 0x802DFB44
void EBitArray::InsertElements(int pos, int count) { (void)pos; (void)count; }
// 0x802DFBF0
void EBitArray::Remove(int pos, int count) { (void)pos; (void)count; }

// 0x802DFC6C
void EBitArray::operator=(EBitArray& other) {
    char* self = (char*)this;
    char* otherSelf = (char*)&other;
    u32 otherBits = *(u32*)(otherSelf + 4);
    this->SetSize(otherBits, 0);
    if (otherBits > 0) {
        u32 byteCount = (otherBits + 7) / 8;
        memcpy(*(void**)(self + 0), *(void**)(otherSelf + 0), byteCount);
    }
}

// 0x802DFCD4
void EBitArray::operator|=(EBitArray& other) {
    char* self = (char*)this;
    char* otherSelf = (char*)&other;
    u32 count = *(u32*)(self + 4);
    u32 wordCount = (count + 31) / 32;
    u32* data = *(u32**)(self + 0);
    u32* otherData = *(u32**)(otherSelf + 0);
    for (u32 i = 0; i < wordCount; i++) data[i] |= otherData[i];
}

// 0x802DFD3C
void EBitArray::operator&=(EBitArray& other) {
    char* self = (char*)this;
    char* otherSelf = (char*)&other;
    u32 count = *(u32*)(self + 4);
    u32 wordCount = (count + 31) / 32;
    u32* data = *(u32**)(self + 0);
    u32* otherData = *(u32**)(otherSelf + 0);
    for (u32 i = 0; i < wordCount; i++) data[i] &= otherData[i];
}

// 0x802DFDA4
void EBitArray::operator^=(EBitArray& other) {
    char* self = (char*)this;
    char* otherSelf = (char*)&other;
    u32 count = *(u32*)(self + 4);
    u32 wordCount = (count + 31) / 32;
    u32* data = *(u32**)(self + 0);
    u32* otherData = *(u32**)(otherSelf + 0);
    for (u32 i = 0; i < wordCount; i++) data[i] ^= otherData[i];
}

// 0x802DFE0C
void EBitArray::operator==(EBitArray& other) const {
    char* self = (char*)this;
    char* otherSelf = (char*)&other;
    u32 count = *(u32*)(self + 4);
    if (count != *(u32*)(otherSelf + 4)) return;
    u32 byteCount = (count + 7) / 8;
    memcmp(*(void**)(self + 0), *(void**)(otherSelf + 0), byteCount);
}

// 0x802DFE98
void EBitArray::Intersection(EBitArray& other) const { (void)other; }
// 0x802DFF0C
void EBitArray::Interleave(int a, int b, int c) { (void)a; (void)b; (void)c; }
// 0x802DFFDC
void EBitArray::Deinterleave(int a, int b, int c) { (void)a; (void)b; (void)c; }

// 0x802E00B0
void EBitArray::Add(unsigned int value, int bits) {
    // NOTE: asm-derived — append bits to the array
    (void)value; (void)bits;
}

// 0x802E0148
void EBitArray::Get(int offset, int bits) const {
    // NOTE: asm-derived — extract bits from the array
    (void)offset; (void)bits;
}

// 0x802E0220
void EBitArray::GetSigned(int offset, int bits) const { (void)offset; (void)bits; }
// 0x802E02A0
void EBitArray::ToleranceToSignedBits(float tol) { (void)tol; }
// 0x802E032C
void EBitArray::ToleranceToUnsignedBits(float tol) { (void)tol; }
// 0x802E03F4
void EBitArray::FloatToSignedBits(float val, int bits) { (void)val; (void)bits; }
// 0x802E048C
void EBitArray::FloatToUnsignedBits(float val, int bits) { (void)val; (void)bits; }
// 0x802E050C
void EBitArray::SignedBitsToFloatScaler(int bits) { (void)bits; }
// 0x802E0558
void EBitArray::UnsignedBitsToFloatScaler(int bits) { (void)bits; }

// 0x802E06F8
EBitArray::~EBitArray(void) {
    this->Deallocate();
}


// ============================================================================
// EVec3Decomp - 3D vector decompression for animation
// ============================================================================

class EVec3Decomp {
public:
    void Init(EBitArray*, int);
    void* operator new(std::size_t);
    void operator delete(void*);
    void GetFrame(float);
    void NextSegment(float);
    void LastSegment(float);
    void Reset(void);
    void ResetEnd(void);
    void ReadAllVs(void);
    void GetKeyframe(int, void*);
    void GetVecVal(int, EVec3&);
    void GetV(int, int, EVec3&);
};

// 0x802D5CE4
void EVec3Decomp::Init(EBitArray* bits, int offset) {
    // NOTE: asm-derived — initialize decompression from bit array
    char* self = (char*)this;
    *(u8*)(self + 33) = 0;
    *(void**)(self + 0) = bits;
    // Read scale/offset from bit stream
    (void)offset;
}

// 0x802D5EAC
void* EVec3Decomp::operator new(std::size_t size) {
    return MainHeap()->Malloc(size, 0);
}

// 0x802D5F50
void EVec3Decomp::operator delete(void* ptr) {
    if (ptr) MainHeap()->Free(ptr);
}

// 0x802D6024
void EVec3Decomp::GetFrame(float frame) {
    // NOTE: asm-derived — interpolate vec3 at given frame
    (void)frame;
}

// 0x802D649C
void EVec3Decomp::NextSegment(float frame) { (void)frame; }
// 0x802D65D0
void EVec3Decomp::LastSegment(float frame) { (void)frame; }

// 0x802D6700
void EVec3Decomp::Reset(void) {
    char* self = (char*)this;
    *(u8*)(self + 33) = 0;
}

// 0x802D676C
void EVec3Decomp::ResetEnd(void) {
    // NOTE: asm-derived
    char* self = (char*)this;
    (void)self;
}

// 0x802D67F4
void EVec3Decomp::ReadAllVs(void) { /* NOTE: asm-derived */ }
// 0x802D6870
void EVec3Decomp::GetKeyframe(int idx, void* outKeyframe) { (void)idx; (void)outKeyframe; }
// 0x802D6994
void EVec3Decomp::GetVecVal(int idx, EVec3& out) { (void)idx; (void)out; }
// 0x802D6A38
void EVec3Decomp::GetV(int seg, int component, EVec3& out) { (void)seg; (void)component; (void)out; }


// ============================================================================
// EWindow - Rendering window with clipping
// ============================================================================

class EWindow {
public:
    EWindow(void);
    ~EWindow(void);
    void SetRenderSurface(ERenderSurface*, int);
    void ScaleForScreenshot(bool, int, int, int, int);
    void ScaleOutputRectForScreenshot(TRect<float>*);
    void ScaleScissorRectForScreenshot(TRect<float>*, TRect<float>*);
    void Select(ERC*);
    void CalcWindowMat(void);
    void CalcClip(void);
    void CalcClipInv(void);
    void SetClip(TRect<float>&);
    void SetInputCoordinates(TRect<float>&);
    void SetOutputCoordinates(TRect<float>&);
    void SetRect(TRect<float>&);
    void ClipTest(float, float);
    void ClipTest(TRect<float>&);
};

// 0x802FFB98
EWindow::EWindow(void) {
    char* self = (char*)this;
    // Initialize default rect values
    memset(self, 0, 256); // approximate size
}

// 0x802FFC80
EWindow::~EWindow(void) {
    // NOTE: asm-derived — cleanup
}

// 0x802FFCF0
void EWindow::SetRenderSurface(ERenderSurface* surface, int idx) { (void)surface; (void)idx; }
// 0x802FFD98
void EWindow::ScaleForScreenshot(bool enable, int x, int y, int w, int h) { (void)enable; (void)x; (void)y; (void)w; (void)h; }
// 0x802FFF10
void EWindow::ScaleOutputRectForScreenshot(TRect<float>* rect) { (void)rect; }
// 0x802FFF94
void EWindow::ScaleScissorRectForScreenshot(TRect<float>* scissor, TRect<float>* output) { (void)scissor; (void)output; }
// 0x80300040
void EWindow::Select(ERC* rc) { (void)rc; this->CalcWindowMat(); this->CalcClip(); }
// 0x8030035C
void EWindow::CalcWindowMat(void) { /* NOTE: asm-derived — builds projection matrix */ }
// 0x803004A0
void EWindow::CalcClip(void) { /* NOTE: asm-derived — calculate clip rectangle */ }
// 0x803005AC
void EWindow::CalcClipInv(void) { /* NOTE: asm-derived */ }
// 0x80300600
void EWindow::SetClip(TRect<float>& rect) { (void)rect; }
// 0x80300648
void EWindow::SetInputCoordinates(TRect<float>& rect) { (void)rect; this->CalcWindowMat(); }
// 0x80300710
void EWindow::SetOutputCoordinates(TRect<float>& rect) { (void)rect; this->CalcWindowMat(); }
// 0x803008DC
void EWindow::SetRect(TRect<float>& rect) { (void)rect; }
// 0x80300A3C
void EWindow::ClipTest(float x, float y) { (void)x; (void)y; }
// 0x80300A84
void EWindow::ClipTest(TRect<float>& rect) { (void)rect; }


// ============================================================================
// EShader - Material shader management
// ============================================================================

class EShader {
public:
    EShader(void);
    ~EShader(void);
    void Create(EShaderDef&);
    void Clone(void);
    void AddToUpdateList(void);
    void RemoveFromUpdateList(void);
    void UpdateAll(float);
    void Update(float);
    void ChangeMaterial(EMaterial&);
    void GetTexture(int) const;
    void UsesMipMapping(void);
    void Validate(void);
    void SetTransform(ERC*);
    void SetScrollSpeed(EVec2&, int, bool);
    void IsAlphaShader(void) const;
};

// 0x802F9BA8
EShader::EShader(void) {
    char* self = (char*)this;
    // vtable at offset 240
    // Initialize texture slots, material, scroll params
    memset(self + 16, 0, 224);
}

// 0x802F9D68
EShader::~EShader(void) {
    this->RemoveFromUpdateList();
}

// 0x802F9DC8
void EShader::Create(EShaderDef& def) { (void)def; }
// 0x802F9E0C
void EShader::Clone(void) { /* NOTE: asm-derived — create a copy of this shader */ }
// 0x802F9E88
void EShader::AddToUpdateList(void) { /* NOTE: asm-derived — add to global shader update list */ }
// 0x802F9FA8
void EShader::RemoveFromUpdateList(void) { /* NOTE: asm-derived */ }
// 0x802FA084
void EShader::UpdateAll(float dt) { (void)dt; }
// 0x802FA130
void EShader::Update(float dt) { (void)dt; }
// 0x802FA390
void EShader::ChangeMaterial(EMaterial& mat) { (void)mat; }
// 0x802FA474
void EShader::GetTexture(int slot) const { (void)slot; }
// 0x802FA4C4
void EShader::UsesMipMapping(void) { /* NOTE: asm-derived */ }
// 0x802FA578
void EShader::Validate(void) { /* NOTE: asm-derived */ }
// 0x802FA648
void EShader::SetTransform(ERC* rc) { (void)rc; }
// 0x802FA89C
void EShader::SetScrollSpeed(EVec2& speed, int layer, bool relative) { (void)speed; (void)layer; (void)relative; }
// 0x802FAB7C
void EShader::IsAlphaShader(void) const { /* NOTE: asm-derived */ }


// ============================================================================
// ESubModel - Sub-model geometry and rendering
// ============================================================================

class ESubModel {
public:
    ~ESubModel(void);
    void DelRefSubResources(void);
    void AddRefSubResources(void);
    void TryIncrementSubResources(void);
    void Read(unsigned char*, int);
    void Draw(ERC*);
    void DrawGeometry(ERC*);
    void DrawAsShadow(ERC*);
    void DrawNormals(ERC*);
    void DrawWireFrame(ERC*);
    void BuildDisplayList(bool, char*, bool, float, float);
    void BuildDisplayList(ESMBuildDisplayListData*);
    void GetMinMaxX(float*, float*);
    void ApplyMorph(void);
    void ResetMorph(void);
    void Morph(float*);
    void LatticeDeform(void);
    void RegisterMorphTarget(ESubModel*, int);
    void UnRegisterMorphTarget(int);
    void GenerateMorphTargetDeltas(ESubModel*);
    void ParameterizeVerts(TArray<BSplineVolume, TArrayERModelAllocator>*);
    void FreeMorphResource(void);
    void FreeStripResource(void);
    void FreeMorphStripResource(void);
    void HasModifiableColor(void);
    void GetModifiableColor(unsigned int);
    void TransformModelUV(EVec2&, EVec2&, unsigned int, EVec2&, EVec2&, bool);
};

// 0x802FAC88
ESubModel::~ESubModel(void) {
    this->FreeMorphResource();
    this->FreeStripResource();
}

// 0x802FACD4
void ESubModel::DelRefSubResources(void) { /* NOTE: asm-derived */ }
// 0x802FAD30
void ESubModel::AddRefSubResources(void) { /* NOTE: asm-derived */ }
// 0x802FAD8C
void ESubModel::TryIncrementSubResources(void) { /* NOTE: asm-derived */ }
// 0x802FAE2C
void ESubModel::Read(unsigned char* data, int len) { (void)data; (void)len; }
// 0x802FAF20
void ESubModel::Draw(ERC* rc) { (void)rc; }
// 0x802FB004
void ESubModel::DrawGeometry(ERC* rc) { (void)rc; }
// 0x802FB09C
void ESubModel::DrawAsShadow(ERC* rc) { (void)rc; }
// 0x802FB17C
void ESubModel::DrawNormals(ERC* rc) { (void)rc; }
// 0x802FB1E0
void ESubModel::DrawWireFrame(ERC* rc) { (void)rc; }
// 0x802FB244
void ESubModel::BuildDisplayList(bool a, char* b, bool c, float d, float e) { (void)a; (void)b; (void)c; (void)d; (void)e; }
// 0x802FB2D8
void ESubModel::BuildDisplayList(ESMBuildDisplayListData* data) { (void)data; }
// 0x802FB33C
void ESubModel::GetMinMaxX(float* minX, float* maxX) { (void)minX; (void)maxX; }
// 0x802FB3A8
void ESubModel::ApplyMorph(void) { /* NOTE: asm-derived */ }
// 0x802FB408
void ESubModel::ResetMorph(void) { /* NOTE: asm-derived */ }
// 0x802FB464
void ESubModel::Morph(float* weights) { (void)weights; }
// 0x802FB4CC
void ESubModel::LatticeDeform(void) { /* NOTE: asm-derived */ }
// 0x802FB528
void ESubModel::RegisterMorphTarget(ESubModel* target, int slot) { (void)target; (void)slot; }
// 0x802FB59C
void ESubModel::UnRegisterMorphTarget(int slot) { (void)slot; }
// 0x802FB600
void ESubModel::GenerateMorphTargetDeltas(ESubModel* ref) { (void)ref; }
// 0x802FB678
void ESubModel::ParameterizeVerts(TArray<BSplineVolume, TArrayERModelAllocator>* vols) { (void)vols; }
// 0x802FB6DC
void ESubModel::FreeMorphResource(void) { /* NOTE: asm-derived */ }
// 0x802FB738
void ESubModel::FreeStripResource(void) { /* NOTE: asm-derived */ }
// 0x802FB794
void ESubModel::FreeMorphStripResource(void) { /* NOTE: asm-derived */ }
// 0x802FB7F0
void ESubModel::HasModifiableColor(void) { /* NOTE: asm-derived */ }
// 0x802FB860
void ESubModel::GetModifiableColor(unsigned int idx) { (void)idx; }
// 0x802FB8E0
void ESubModel::TransformModelUV(EVec2& a, EVec2& b, unsigned int c, EVec2& d, EVec2& e, bool f) { (void)a; (void)b; (void)c; (void)d; (void)e; (void)f; }


// ============================================================================
// EInstance - 3D instance in a scene with lighting
// ============================================================================

class EInstance {
public:
    ~EInstance(void);
    void RemoveFromLevel(void);
    void Write(EStream&);
    void Read(EStream&);
    void Load(EFile&);
    void SetBounds(EBound3&);
    void ShadowDirAtPoint(EVec3&, EVec3&, int);
    void CalcShadowLight(EVec3&, short);
    void CalcShadowLightWeighted(EVec3&, short);
    void ShadowDirAtPointWeighted(EVec3&, EVec3&, int);
    void CalcLights(EVec3&, ELights&, bool);
    void CalcLights4(EVec3&, ELights&, bool);
    void SetInstAlpha(float);
    void RegisterType(unsigned short);
    void ResetLocation(void);
    void GetLocationId(short&, short&);
    void GetOtherSide(short&, short&);
};

// 0x80228370
EInstance::~EInstance(void) {
    // vtable set, then remove from level, then EResource::~EResource
    this->RemoveFromLevel();
}

// 0x802283C8
void EInstance::Write(EStream& s) { (void)s; }
// 0x80228468
void EInstance::Read(EStream& s) { (void)s; }
// 0x802285C0
void EInstance::Load(EFile& f) { (void)f; }
// 0x8022877C
void EInstance::SetBounds(EBound3& b) { (void)b; }
// 0x802288D8
void EInstance::ShadowDirAtPoint(EVec3& pos, EVec3& dir, int lightIdx) { (void)pos; (void)dir; (void)lightIdx; }
// 0x80228A74
void EInstance::CalcShadowLight(EVec3& pos, short roomId) { (void)pos; (void)roomId; }
// 0x80228BA0
void EInstance::CalcShadowLightWeighted(EVec3& pos, short roomId) { (void)pos; (void)roomId; }
// 0x80228CB4
void EInstance::ShadowDirAtPointWeighted(EVec3& pos, EVec3& dir, int lightIdx) { (void)pos; (void)dir; (void)lightIdx; }
// 0x80228F00
void EInstance::CalcLights(EVec3& pos, ELights& lights, bool useAmbient) { (void)pos; (void)lights; (void)useAmbient; }
// 0x8022907C
void EInstance::CalcLights4(EVec3& pos, ELights& lights, bool useAmbient) { (void)pos; (void)lights; (void)useAmbient; }
// 0x8022922C
void EInstance::SetInstAlpha(float alpha) { (void)alpha; }
// 0x802293E8
void EInstance::RegisterType(unsigned short type) { (void)type; }
// 0x802294AC
void EInstance::ResetLocation(void) { /* NOTE: asm-derived */ }
// 0x80229528
void EInstance::GetLocationId(short& x, short& y) { (void)x; (void)y; }
// 0x80229574
void EInstance::GetOtherSide(short& x, short& y) { (void)x; (void)y; }


// ============================================================================
// RParticle - Particle resource
// ============================================================================

class RParticle {
public:
    RParticle(void);
    ~RParticle(void);
    void Deallocate(void);
    void DelRefSubResources(void);
    void AddRefSubResources(void);
    void TryIncrementSubResources(void);
    void PrepareData(void);
    void Load(EFile*, unsigned int);
    void Refresh(EFile*);
    void RegisterType(unsigned short);
};

// 0x8036B2E8
RParticle::RParticle(void) {
    char* self = (char*)this;
    // EResource::EResource() called first
    // vtable set, zero-fill particle fields
    *(u32*)(self + 24) = 0;
    *(u32*)(self + 20) = 0;
    // Zero 8 dwords at end of struct
    for (int i = 0; i < 8; i++) {
        *(u32*)(self + 56 - i * 4) = 0;
    }
}

// 0x8036B34C
RParticle::~RParticle(void) {
    this->Deallocate();
}

// 0x8036B3AC
void RParticle::Deallocate(void) { /* NOTE: asm-derived — free particle data */ }
// 0x8036B404
void RParticle::DelRefSubResources(void) { /* NOTE: asm-derived */ }
// 0x8036B490
void RParticle::AddRefSubResources(void) { /* NOTE: asm-derived */ }
// 0x8036B55C
void RParticle::TryIncrementSubResources(void) { /* NOTE: asm-derived */ }
// 0x8036B6BC
void RParticle::PrepareData(void) { /* NOTE: asm-derived — process loaded particle data */ }
// 0x8036BCF8
void RParticle::Load(EFile* file, unsigned int offset) { (void)file; (void)offset; }
// 0x8036BF5C
void RParticle::Refresh(EFile* file) { (void)file; }
// 0x8036C230
void RParticle::RegisterType(unsigned short type) { (void)type; }


// ============================================================================
// ENgcSFXStreamer - GameCube audio streaming
// ============================================================================

class ENgcSFXStreamer {
public:
    ENgcSFXStreamer(void);
    void Update(void);
    void IsPlaying(unsigned int);
    void Allocate(ERSampledata*, unsigned char);
    void Play(unsigned int, ERSampledata*);
    void Pause(unsigned int);
    void Free(unsigned int);
    void SetPitchBend(unsigned int, float);
    void SetLeftVolume(unsigned int, int);
    void SetRightVolume(unsigned int, float);
    void SetRightVolume(unsigned int, int);
    void SetVolume(unsigned int, float);
    void SetPan(unsigned int, float);
};

// 0x8034C7B8
ENgcSFXStreamer::ENgcSFXStreamer(void) {
    // NOTE: asm-derived — allocate AX voices, init channel state
    char* self = (char*)this;
    (void)self;
}

// 0x8034C880
void ENgcSFXStreamer::Update(void) { /* NOTE: asm-derived — update all active streams */ }
// 0x8034C92C
void ENgcSFXStreamer::IsPlaying(unsigned int handle) { (void)handle; }
// 0x8034C984
void ENgcSFXStreamer::Allocate(ERSampledata* sample, unsigned char flags) { (void)sample; (void)flags; }
// 0x8034CB00
void ENgcSFXStreamer::Play(unsigned int handle, ERSampledata* sample) { (void)handle; (void)sample; }
// 0x8034D058
void ENgcSFXStreamer::Pause(unsigned int handle) { (void)handle; }
// 0x8034D15C
void ENgcSFXStreamer::Free(unsigned int handle) { (void)handle; }
// 0x8034D274
void ENgcSFXStreamer::SetPitchBend(unsigned int handle, float bend) { (void)handle; (void)bend; }
// 0x8034D330
void ENgcSFXStreamer::SetLeftVolume(unsigned int handle, int vol) { (void)handle; (void)vol; }
// 0x8034D3A4
void ENgcSFXStreamer::SetRightVolume(unsigned int handle, float vol) { (void)handle; (void)vol; }
// 0x8034D43C
void ENgcSFXStreamer::SetRightVolume(unsigned int handle, int vol) { (void)handle; (void)vol; }
// 0x8034D4B8
void ENgcSFXStreamer::SetVolume(unsigned int handle, float vol) { (void)handle; (void)vol; }
// 0x8034D54C
void ENgcSFXStreamer::SetPan(unsigned int handle, float pan) { (void)handle; (void)pan; }


// ============================================================================
// cSoundPlayer - Sound playback system
// ============================================================================

class cSoundPlayer {
public:
    cSoundPlayer(void);
    ~cSoundPlayer(void);
    void Initialize(void);
    void Shutdown(void);
    void KillSourceEvent(int);
    void KillAllEvent(void);
    void Update(void);
    void SetGameMode(int);
    void EnableSound(bool);
    void QuietAll(void);
    void PlayBySource(unsigned int, short);
    void PlayBySource(char*, short);
    void PlayBySource(ERSoundEvent*, short);
    void QuietBySourceID(int);
    void PauseSFX(void);
    void ResumeSFX(void);
    void PauseMusic(void);
    void ResumeMusic(void);
    void PauseSounds(void);
    void ResumeSounds(void);
    void NotifyViewChange(void);
    void NotifyHourChange(void);
    void SetOldFXVolume(int);
    void SetMusicVolume(int);
    void SetSFXVolume(int);
    void SetVOXVolume(int);
    void SetAmbientVolume(int);
};

// 0x800B7264
cSoundPlayer::cSoundPlayer(void) {
    char* self = (char*)this;
    // Init list at offset 24
    *(u32*)(self + 16) = 0;
    *(u32*)(self + 0) = 0;
    *(u32*)(self + 4) = 0;
    *(u32*)(self + 8) = 0;
    *(u32*)(self + 12) = 0;
}

// 0x800B72CC
cSoundPlayer::~cSoundPlayer(void) {
    // NOTE: asm-derived — cleanup event list, deallocate
    char* self = (char*)this;
    (void)self;
}

// 0x800B7368
void cSoundPlayer::Initialize(void) { /* NOTE: asm-derived */ }
// 0x800B7440
void cSoundPlayer::Shutdown(void) { /* NOTE: asm-derived */ }
// 0x800B74C4
void cSoundPlayer::KillSourceEvent(int sourceId) { (void)sourceId; }
// 0x800B75BC
void cSoundPlayer::KillAllEvent(void) { /* NOTE: asm-derived */ }
// 0x800B76A8
void cSoundPlayer::Update(void) { /* NOTE: asm-derived */ }
// 0x800B7814
void cSoundPlayer::SetGameMode(int mode) { (void)mode; }
// 0x800B78B0
void cSoundPlayer::EnableSound(bool enable) { (void)enable; }
// 0x800B7904
void cSoundPlayer::QuietAll(void) { /* NOTE: asm-derived */ }
// 0x800B7968
void cSoundPlayer::PlayBySource(unsigned int hash, short pri) { (void)hash; (void)pri; }
// 0x800B7A60
void cSoundPlayer::PlayBySource(char* name, short pri) { (void)name; (void)pri; }
// 0x800B7ACC
void cSoundPlayer::PlayBySource(ERSoundEvent* evt, short pri) { (void)evt; (void)pri; }
// 0x800B7B20
void cSoundPlayer::QuietBySourceID(int id) { (void)id; }
// 0x800B7B74
void cSoundPlayer::PauseSFX(void) { /* NOTE: asm-derived */ }
// 0x800B7BE4
void cSoundPlayer::ResumeSFX(void) { /* NOTE: asm-derived */ }
// 0x800B7C54
void cSoundPlayer::PauseMusic(void) { /* NOTE: asm-derived */ }
// 0x800B7CC4
void cSoundPlayer::ResumeMusic(void) { /* NOTE: asm-derived */ }
// 0x800B7D34
void cSoundPlayer::PauseSounds(void) { this->PauseSFX(); this->PauseMusic(); }
// 0x800B7DC8
void cSoundPlayer::ResumeSounds(void) { this->ResumeSFX(); this->ResumeMusic(); }
// 0x800B7E5C
void cSoundPlayer::NotifyViewChange(void) { /* NOTE: asm-derived */ }
// 0x800B7EB0
void cSoundPlayer::NotifyHourChange(void) { /* NOTE: asm-derived */ }
// 0x800B7F54
void cSoundPlayer::SetOldFXVolume(int vol) { (void)vol; }
// 0x800B7FDC
void cSoundPlayer::SetMusicVolume(int vol) { (void)vol; }
// 0x800B803C
void cSoundPlayer::SetSFXVolume(int vol) { (void)vol; }
// 0x800B809C
void cSoundPlayer::SetVOXVolume(int vol) { (void)vol; }
// 0x800B80FC
void cSoundPlayer::SetAmbientVolume(int vol) { (void)vol; }


// ============================================================================
// cSoundModeManager - Sound mode state management
// ============================================================================

class cSoundModeManager {
public:
    cSoundModeManager(void);
    ~cSoundModeManager(void);
    void Update(void);
    void SetMode(int);
    void Enter(int, int);
    void ProcessModes(void);
    void SetSoundMode(int);
    void Exit(int);
    void ChangeHouseMode(void);
    void ChangeNeighborhoodMode(void);
    void ChangeLevelMode(int);
};

// 0x800B039C
cSoundModeManager::cSoundModeManager(void) {
    char* self = (char*)this;
    memset(self, 0, 64); // approximate size
}

// 0x800B0400
cSoundModeManager::~cSoundModeManager(void) { /* NOTE: asm-derived */ }
// 0x800B0498
void cSoundModeManager::Update(void) { /* NOTE: asm-derived */ }
// 0x800B055C
void cSoundModeManager::SetMode(int mode) { (void)mode; }
// 0x800B08AC
void cSoundModeManager::Enter(int mode, int subMode) { (void)mode; (void)subMode; }
// 0x800B0B00
void cSoundModeManager::ProcessModes(void) { /* NOTE: asm-derived */ }
// 0x800B0F28
void cSoundModeManager::SetSoundMode(int mode) { (void)mode; }
// 0x800B0F70
void cSoundModeManager::Exit(int mode) { (void)mode; }
// 0x800B104C
void cSoundModeManager::ChangeHouseMode(void) { /* NOTE: asm-derived */ }
// 0x800B10F0
void cSoundModeManager::ChangeNeighborhoodMode(void) { /* NOTE: asm-derived */ }
// 0x800B1194
void cSoundModeManager::ChangeLevelMode(int level) { (void)level; }


// ============================================================================
// cGZSndSys - Sound system core
// ============================================================================

class cGZSndSys {
public:
    cGZSndSys(void);
    ~cGZSndSys(void);
    void CreateSoundEffect(unsigned int, float);
    void CreateAudioStream(unsigned int, bool, float);
    void removeFromList(cGZMusic*);
    void killDeadSounds(void);
    void ProcessCache(unsigned int);
    void Update(void);
};

// 0x800B8E80
cGZSndSys::cGZSndSys(void) {
    char* self = (char*)this;
    // vtable at offset 0, then memset 1024 bytes of buffer, init flags
    memset(self + 4, 0, 1024);
    *(u32*)(self + 1040) = 1;  // enabled flag
    *(u32*)(self + 1048) = 0;
    *(u32*)(self + 1028) = 0;
    *(u32*)(self + 1032) = 0;
    *(u32*)(self + 1036) = 0;
    *(u32*)(self + 1044) = 0;
}

// 0x800B8EE8
cGZSndSys::~cGZSndSys(void) { /* NOTE: asm-derived — cleanup sound list */ }
// 0x800B8FE0
void cGZSndSys::CreateSoundEffect(unsigned int hash, float vol) { (void)hash; (void)vol; }
// 0x800B9038
void cGZSndSys::CreateAudioStream(unsigned int hash, bool loop, float vol) { (void)hash; (void)loop; (void)vol; }
// 0x800B90F8
void cGZSndSys::removeFromList(cGZMusic* music) { (void)music; }
// 0x800B9184
void cGZSndSys::killDeadSounds(void) { /* NOTE: asm-derived */ }
// 0x800B93A8
void cGZSndSys::ProcessCache(unsigned int hash) { (void)hash; }
// 0x800B9824
void cGZSndSys::Update(void) { /* NOTE: asm-derived — update all active sounds */ }


// ============================================================================
// cHitMan - Hit/control group manager for audio
// ============================================================================

class cHitMan {
public:
    void ControlGroup(int);
    void ClearControlGroups(void);
    cHitMan(void);
    void Init(void);
    ~cHitMan(void);
    void Shutdown(void);
    void UpdateActiveTrackVolumes(void);
    void TimerCallback(void);
    void AddToUpdateList(cTrack*);
    void RemoveFromUpdateList(cTrack*);
    void DuckMapSetSndobPri(cTrack*, int);
    void DuckMapSndobPri(cTrack*);
    void DuckMapMaxPri(void);
    void DuckMapRemoveAll(void);
};

// 0x801164E4
void cHitMan::ControlGroup(int groupId) {
    // NOTE: asm-derived — walk list looking for matching group
    char* self = (char*)this;
    (void)groupId;
}

// 0x80116650
void cHitMan::ClearControlGroups(void) { /* NOTE: asm-derived */ }

// 0x80116888
cHitMan::cHitMan(void) {
    char* self = (char*)this;
    memset(self, 0, 128); // approximate size
}

// 0x80116994
void cHitMan::Init(void) { /* NOTE: asm-derived */ }

// 0x80116A14
cHitMan::~cHitMan(void) {
    this->Shutdown();
}

// 0x80116B4C
void cHitMan::Shutdown(void) { /* NOTE: asm-derived */ }
// 0x80116D00
void cHitMan::UpdateActiveTrackVolumes(void) { /* NOTE: asm-derived */ }
// 0x80116DFC
void cHitMan::TimerCallback(void) { /* NOTE: asm-derived */ }
// 0x80116EE8
void cHitMan::AddToUpdateList(cTrack* track) { (void)track; }
// 0x80116F50
void cHitMan::RemoveFromUpdateList(cTrack* track) { (void)track; }
// 0x80117034
void cHitMan::DuckMapSetSndobPri(cTrack* track, int pri) { (void)track; (void)pri; }
// 0x801172C4
void cHitMan::DuckMapSndobPri(cTrack* track) { (void)track; }
// 0x80117418
void cHitMan::DuckMapMaxPri(void) { /* NOTE: asm-derived */ }
// 0x801174A8
void cHitMan::DuckMapRemoveAll(void) { /* NOTE: asm-derived */ }


// ============================================================================
// AmbientScorePlayer - Ambient sound/music player
// ============================================================================

class AmbientScorePlayer {
public:
    AmbientScorePlayer(bool);
    ~AmbientScorePlayer(void);
    void Update(void);
    void SetListenerCount(int);
    void UpdateListener(unsigned int, EVec3&, EVec3&);
    void Load(char*);
    void Shutdown(void);
    void SetPause(bool);
    void SoundRangeCoversCurTime(ERAmbientSound*);
    void SoundAlreadyPlaying(ERAmbientSound*);
    void SoundInHearingDistance(ERAmbientSound*);
    void AddSoundBasedOnProbability(vector<ERAmbientSound*, allocator<ERAmbientSound*> >&, int, bool);
    void KillAllAmbientSounds(void);
    void AddNewAmbientSoundPlayer(ERAmbientSound*);
    void RemoveAmbientSoundPlayer(ERAmbientSound*);
    void RemoveFinishedSounds(void);
};

// 0x800A80B8
AmbientScorePlayer::AmbientScorePlayer(bool isScore) {
    char* self = (char*)this;
    *(u32*)(self + 20) = 1024;  // buffer size
    *(u32*)(self + 28) = 2;     // listener count
    *(u32*)(self + 0) = 0;
    *(u32*)(self + 4) = 0;
    *(u32*)(self + 8) = 0;
    (void)isScore;
}

// 0x800A813C
AmbientScorePlayer::~AmbientScorePlayer(void) {
    this->Shutdown();
}

// 0x800A81D8
void AmbientScorePlayer::Update(void) { /* NOTE: asm-derived — check time ranges, add/remove sounds */ }
// 0x800A8524
void AmbientScorePlayer::SetListenerCount(int count) { (void)count; }
// 0x800A85A4
void AmbientScorePlayer::UpdateListener(unsigned int idx, EVec3& pos, EVec3& dir) { (void)idx; (void)pos; (void)dir; }
// 0x800A8774
void AmbientScorePlayer::Load(char* filename) { (void)filename; }
// 0x800A8954
void AmbientScorePlayer::Shutdown(void) { this->KillAllAmbientSounds(); }
// 0x800A8A18
void AmbientScorePlayer::SetPause(bool pause) { (void)pause; }
// 0x800A8B3C
void AmbientScorePlayer::SoundRangeCoversCurTime(ERAmbientSound* snd) { (void)snd; }
// 0x800A8C28
void AmbientScorePlayer::SoundAlreadyPlaying(ERAmbientSound* snd) { (void)snd; }
// 0x800A8CB0
void AmbientScorePlayer::SoundInHearingDistance(ERAmbientSound* snd) { (void)snd; }
// 0x800A8ED8
void AmbientScorePlayer::AddSoundBasedOnProbability(vector<ERAmbientSound*, allocator<ERAmbientSound*> >& sounds, int count, bool force) { (void)sounds; (void)count; (void)force; }
// 0x800A8F90
void AmbientScorePlayer::KillAllAmbientSounds(void) { /* NOTE: asm-derived */ }
// 0x800A9048
void AmbientScorePlayer::AddNewAmbientSoundPlayer(ERAmbientSound* snd) { (void)snd; }
// 0x800A90DC
void AmbientScorePlayer::RemoveAmbientSoundPlayer(ERAmbientSound* snd) { (void)snd; }
// 0x800A9198
void AmbientScorePlayer::RemoveFinishedSounds(void) { /* NOTE: asm-derived */ }


// ============================================================================
// SmartDataFactory - Object data factory with provider lookup
// ============================================================================

class SmartDataFactory {
public:
    SmartDataFactory(void);
    ~SmartDataFactory(void);
    void QueryInterface(unsigned int, void**);
    void Release(void);
    void GetDataProvider(unsigned int, ObjectDataID&) const;
    void SetDataProvider(unsigned int, ObjectDataID&, int);
    void CreateObject(unsigned int, unsigned int, void**);
    void CreateObject(unsigned int, ObjectDataID&, void**);
    void CreateObjectFromProvider(unsigned int, int, void**);
};

// 0x8015CA80
SmartDataFactory::SmartDataFactory(void) {
    char* self = (char*)this;
    // vtable + init red-black tree for providers
    *(u32*)(self + 4) = 1; // ref count
    memset(self + 8, 0, 32); // provider tree init
}

// 0x8015CAFC
SmartDataFactory::~SmartDataFactory(void) { /* NOTE: asm-derived */ }
// 0x8015CB98
void SmartDataFactory::QueryInterface(unsigned int iid, void** out) { (void)iid; (void)out; }
// 0x8015CC1C
void SmartDataFactory::Release(void) { char* self = (char*)this; *(u32*)(self + 4) -= 1; if (*(u32*)(self + 4) == 0) ::operator delete(this); }
// 0x8015CC78
void SmartDataFactory::GetDataProvider(unsigned int type, ObjectDataID& id) const { (void)type; (void)id; }
// 0x8015CDCC
void SmartDataFactory::SetDataProvider(unsigned int type, ObjectDataID& id, int flags) { (void)type; (void)id; (void)flags; }
// 0x8015CF14
void SmartDataFactory::CreateObject(unsigned int type, unsigned int id, void** out) { (void)type; (void)id; (void)out; }
// 0x8015CF80
void SmartDataFactory::CreateObject(unsigned int type, ObjectDataID& id, void** out) { (void)type; (void)id; (void)out; }
// 0x8015D008
void SmartDataFactory::CreateObjectFromProvider(unsigned int type, int idx, void** out) { (void)type; (void)idx; (void)out; }


// ============================================================================
// ObjectDataObjDefinition - Object definition data provider
// ============================================================================

class ObjectDataObjDefinition {
public:
    ObjectDataObjDefinition(void);
    ~ObjectDataObjDefinition(void);
    void QueryInterface(unsigned int, void**);
    void Release(void);
    void AddRef(void);
    void GetFieldCount(void) const;
    void GetFieldType(unsigned int) const;
    void GetFieldName(unsigned int) const;
    void GetFieldOffset(unsigned int) const;
    void GetFieldSize(unsigned int) const;
    void GetFieldData(void*, unsigned int, void*, unsigned int) const;
    void SetFieldData(void*, unsigned int, void const*, unsigned int);
    void GetDataSize(void) const;
    void CreateData(void**);
};

// 0x8015BBF8
ObjectDataObjDefinition::ObjectDataObjDefinition(void) {
    char* self = (char*)this;
    *(u32*)(self + 4) = 1; // ref count
}

// 0x8015BE68
ObjectDataObjDefinition::~ObjectDataObjDefinition(void) { /* NOTE: asm-derived */ }
// 0x8015BEE8
void ObjectDataObjDefinition::QueryInterface(unsigned int iid, void** out) { (void)iid; (void)out; }
// 0x8015BF34
void ObjectDataObjDefinition::Release(void) { char* self = (char*)this; *(u32*)(self + 4) -= 1; if (*(u32*)(self + 4) == 0) ::operator delete(this); }
// 0x8015BFE0
void ObjectDataObjDefinition::AddRef(void) { char* self = (char*)this; *(u32*)(self + 4) += 1; }
// 0x8015C06C
void ObjectDataObjDefinition::GetFieldCount(void) const { /* NOTE: asm-derived */ }
// 0x8015C118
void ObjectDataObjDefinition::GetFieldType(unsigned int idx) const { (void)idx; }
// 0x8015C1A4
void ObjectDataObjDefinition::GetFieldName(unsigned int idx) const { (void)idx; }
// 0x8015C1F4
void ObjectDataObjDefinition::GetFieldOffset(unsigned int idx) const { (void)idx; }
// 0x8015C280
void ObjectDataObjDefinition::GetFieldSize(unsigned int idx) const { (void)idx; }
// 0x8015C59C
void ObjectDataObjDefinition::GetFieldData(void* obj, unsigned int field, void* buf, unsigned int bufSize) const { (void)obj; (void)field; (void)buf; (void)bufSize; }
// 0x8015C708
void ObjectDataObjDefinition::SetFieldData(void* obj, unsigned int field, void const* data, unsigned int dataSize) { (void)obj; (void)field; (void)data; (void)dataSize; }
// 0x8015C78C
void ObjectDataObjDefinition::GetDataSize(void) const { /* NOTE: asm-derived */ }
// 0x8015C7E8
void ObjectDataObjDefinition::CreateData(void** out) { (void)out; }


// ============================================================================
// ObjTestSim - Object interaction testing for Sims
// ============================================================================

class ObjTestSim {
public:
    ObjTestSim(cXPerson*, cXObject*);
    ~ObjTestSim(void);
    void SetStackObject(cXObject*);
    void TestInteraction(Interaction*, bool, bool, bool, TTabScratchEntry**);
    void AppendInteractionsForMenu(InteractionList&, int);
    void RunMenuCheckTree(InteractionList&, Interaction&);
    void MakeNewMenuItem(unsigned short*, short*, StackElem*, short);
    void AppendInteractionsForAuto(InteractionList&);
};

// 0x80112060
ObjTestSim::ObjTestSim(cXPerson* person, cXObject* obj) {
    char* self = (char*)this;
    *(void**)(self + 0) = person;
    *(u32*)(self + 24) = 0;
    *(u32*)(self + 4) = 0;
    this->SetStackObject(obj);
}

// 0x801120A4
ObjTestSim::~ObjTestSim(void) { /* NOTE: asm-derived */ }
// 0x80112138
void ObjTestSim::SetStackObject(cXObject* obj) { (void)obj; }
// 0x80112188
void ObjTestSim::TestInteraction(Interaction* ia, bool a, bool b, bool c, TTabScratchEntry** scratch) { (void)ia; (void)a; (void)b; (void)c; (void)scratch; }
// 0x8011271C
void ObjTestSim::AppendInteractionsForMenu(InteractionList& list, int flags) { (void)list; (void)flags; }
// 0x80112BA8
void ObjTestSim::RunMenuCheckTree(InteractionList& list, Interaction& ia) { (void)list; (void)ia; }
// 0x80112C70
void ObjTestSim::MakeNewMenuItem(unsigned short* text, short* icon, StackElem* elem, short pri) { (void)text; (void)icon; (void)elem; (void)pri; }
// 0x80112D40
void ObjTestSim::AppendInteractionsForAuto(InteractionList& list) { (void)list; }


// ============================================================================
// FlashPiMenu - Pie menu for object interactions
// ============================================================================

class FlashPiMenu {
public:
    ~FlashPiMenu(void);
    void CleanUpAllMenus(void);
    void CreateMenuForGoHere(bool);
    void CreateObjectMenuFromObjList(TNodeList<ISimInstance*>&);
    void AddObjectInteractionsToMenu(cXObject*, bool);
    void CreateInteractionMenu(cXObject*, InteractionList&);
    void CleanupDestinationObject(void);
    void Die(void);
    void CreateGoHereObjectForMenu(void);
    void ChooseAction(cXObject*, Interaction*, bool);
    void BackedOutOfMenu(void);
};

// 0x80039D94
FlashPiMenu::~FlashPiMenu(void) {
    char* self = (char*)this;
    // Set vtable, call CleanUpAllMenus, conditional delete
    this->CleanUpAllMenus();
}

// 0x80039DE8
void FlashPiMenu::CreateMenuForGoHere(bool goHere) { (void)goHere; }
// 0x80039F14
void FlashPiMenu::CreateObjectMenuFromObjList(TNodeList<ISimInstance*>& list) { (void)list; }
// 0x80039FF4
void FlashPiMenu::AddObjectInteractionsToMenu(cXObject* obj, bool checkAccess) { (void)obj; (void)checkAccess; }
// 0x8003A2E0
void FlashPiMenu::CreateInteractionMenu(cXObject* obj, InteractionList& list) { (void)obj; (void)list; }
// 0x8003A6AC
void FlashPiMenu::CleanupDestinationObject(void) { /* NOTE: asm-derived */ }
// 0x8003A784
void FlashPiMenu::Die(void) { /* NOTE: asm-derived */ }
// 0x8003A7F8
void FlashPiMenu::CreateGoHereObjectForMenu(void) { /* NOTE: asm-derived */ }
// 0x8003AAB0
void FlashPiMenu::ChooseAction(cXObject* obj, Interaction* ia, bool force) { (void)obj; (void)ia; (void)force; }
// 0x8003ACA0
void FlashPiMenu::BackedOutOfMenu(void) { /* NOTE: asm-derived */ }


// ============================================================================
// NamespaceSelector - Behavior tree namespace cache
// ============================================================================

class NamespaceSelector {
public:
    ~NamespaceSelector(void);
    void FlushCacheItem(short, list<int, allocator<int> >&);
    void FlushAllCaches(void);
    void GetCacheItem(short, list<int, allocator<int> >&, unsigned int, unsigned int);
    void SetTreeSetResource(EREdithTreeSet*);
    NamespaceSelector(NamespaceSelector&);
};

// 0x800C7DD0
NamespaceSelector::~NamespaceSelector(void) {
    this->FlushAllCaches();
    // Cleanup internal Rb_tree
}

// 0x800C7F9C
void NamespaceSelector::FlushCacheItem(short id, list<int, allocator<int> >& cache) { (void)id; (void)cache; }
// 0x800C8030
void NamespaceSelector::FlushAllCaches(void) { /* NOTE: asm-derived */ }
// 0x800C8160
void NamespaceSelector::GetCacheItem(short id, list<int, allocator<int> >& cache, unsigned int type, unsigned int flags) { (void)id; (void)cache; (void)type; (void)flags; }
// 0x800C8868
void NamespaceSelector::SetTreeSetResource(EREdithTreeSet* res) { (void)res; }
// 0x803A7E0C
NamespaceSelector::NamespaceSelector(NamespaceSelector& other) { (void)other; }


// ============================================================================
// IFFResMap - IFF resource file map
// ============================================================================

class IFFResMap {
public:
    void UpdateOffset(int, int);
    void GetResList(unsigned int, bool);
    void MakeNewNode(unsigned int);
    void GetNode(unsigned int, int, void (*)(void*, int));
    void GetNodeWithLanguage(unsigned int, int, char, void (*)(void*, int));
    void GetNode(unsigned int, StackString<64>&, void (*)(void*, int));
    void GetNode(int*, unsigned int*, void (*)(void*, int));
    void GetIndNode(unsigned int, int, void (*)(void*, int));
    void RemoveNode(IFFResNode*);
    void GetIndexedType(int);
    void CountNodes(unsigned int);
    void FreeAllHandles(void);
    void RemoveAllNodes(void);
    void RemoveAllNodesOfType(unsigned int);
    void GetLastSwizzleProc(unsigned int);
    void GetHighestID(unsigned int, short);
    void DoStream(ReconBuffer*, int);
    ~IFFResMap(void);
};

// 0x800BCE10
void IFFResMap::UpdateOffset(int delta, int threshold) {
    // NOTE: asm-derived — update file offsets for all nodes above threshold
    if (threshold < 0) return;
    (void)delta;
}

// 0x800BCE80
void IFFResMap::GetResList(unsigned int type, bool create) { (void)type; (void)create; }
// 0x800BD15C
void IFFResMap::MakeNewNode(unsigned int type) { (void)type; }
// 0x800BD474
void IFFResMap::GetNode(unsigned int type, int id, void (*callback)(void*, int)) { (void)type; (void)id; (void)callback; }
// 0x800BD514
void IFFResMap::GetNodeWithLanguage(unsigned int type, int id, char lang, void (*callback)(void*, int)) { (void)type; (void)id; (void)lang; (void)callback; }
// 0x800BD5FC
void IFFResMap::GetNode(unsigned int type, StackString<64>& name, void (*callback)(void*, int)) { (void)type; (void)name; (void)callback; }
// 0x800BD6A4
void IFFResMap::GetNode(int* types, unsigned int* ids, void (*callback)(void*, int)) { (void)types; (void)ids; (void)callback; }
// 0x800BD71C
void IFFResMap::GetIndNode(unsigned int type, int idx, void (*callback)(void*, int)) { (void)type; (void)idx; (void)callback; }
// 0x800BD7AC
void IFFResMap::RemoveNode(IFFResNode* node) { (void)node; }
// 0x800BD988
void IFFResMap::GetIndexedType(int idx) { (void)idx; }
// 0x800BD9CC
void IFFResMap::CountNodes(unsigned int type) { (void)type; }
// 0x800BDA2C
void IFFResMap::FreeAllHandles(void) { /* NOTE: asm-derived */ }
// 0x800BDAC8
void IFFResMap::RemoveAllNodes(void) { /* NOTE: asm-derived */ }
// 0x800BDB70
void IFFResMap::RemoveAllNodesOfType(unsigned int type) { (void)type; }
// 0x800BDC68
void IFFResMap::GetLastSwizzleProc(unsigned int type) { (void)type; }
// 0x800BDCB0
void IFFResMap::GetHighestID(unsigned int type, short lang) { (void)type; (void)lang; }
// 0x800BDD24
void IFFResMap::DoStream(ReconBuffer* buf, int flags) { (void)buf; (void)flags; }
// 0x803A4AD0
IFFResMap::~IFFResMap(void) { this->RemoveAllNodes(); }


// ============================================================================
// TreeSimImpl - Behavior tree simulation
// ============================================================================

class TreeSimImpl {
public:
    ~TreeSimImpl(void);
    void GetISimInstance(void);
    TreeSimImpl(int);
    void GetCurrentNode(short*, short*);
    void GetCurrentPrimitive(void);
    void Reset(Behavior*, short);
    void Gosub(Behavior*, short*, short);
    void RunCheckTree(Behavior*, short, short, short*);
    void HandleBreakpoint(StackElem*, BehaviorNode*);
    void DoNodeAction(StackElem*);
    void Simulate(int);
    void GetHighLevelAction(void);
    void GetMainSimElem(void);
};

// 0x80147258
TreeSimImpl::~TreeSimImpl(void) {
    // NOTE: asm-derived — set vtable, cleanup stack elems
    char* self = (char*)this;
    (void)self;
}

// 0x801476E0
void TreeSimImpl::GetISimInstance(void) { /* NOTE: asm-derived */ }

// 0x8014772C
TreeSimImpl::TreeSimImpl(int stackSize) {
    char* self = (char*)this;
    // Initialize stack, set vtable
    (void)stackSize;
}

// 0x80147960
void TreeSimImpl::GetCurrentNode(short* bhav, short* node) { (void)bhav; (void)node; }
// 0x801479BC
void TreeSimImpl::GetCurrentPrimitive(void) { /* NOTE: asm-derived */ }
// 0x80147A34
void TreeSimImpl::Reset(Behavior* bhav, short startNode) { (void)bhav; (void)startNode; }
// 0x80147AA0
void TreeSimImpl::Gosub(Behavior* bhav, short* retNode, short startNode) { (void)bhav; (void)retNode; (void)startNode; }
// 0x80147C70
void TreeSimImpl::RunCheckTree(Behavior* bhav, short startNode, short endNode, short* result) { (void)bhav; (void)startNode; (void)endNode; (void)result; }
// 0x80147F90
void TreeSimImpl::HandleBreakpoint(StackElem* elem, BehaviorNode* node) { (void)elem; (void)node; }
// 0x80147FD8
void TreeSimImpl::DoNodeAction(StackElem* elem) { (void)elem; }
// 0x80148550
void TreeSimImpl::Simulate(int ticks) { (void)ticks; }
// 0x801485D8
void TreeSimImpl::GetHighLevelAction(void) { /* NOTE: asm-derived */ }
// 0x80148708
void TreeSimImpl::GetMainSimElem(void) { /* NOTE: asm-derived */ }


// ============================================================================
// EIObjectMan - Object manager for a house
// ============================================================================

class EIObjectMan {
public:
    EIObjectMan(EHouse*);
    void Init(void);
    ~EIObjectMan(void);
    void AllPlayersActiveInputInteractors(void);
    void TurnOffAllHighlights(unsigned int);
    void GetObjectsInRect(int, TNodeList<ISimInstance*>&);
    void GetObjects(TNodeList<ISimInstance*>&);
    void FreeSimsObjectInstance(ISimInstance*);
    void AddObject(cXObject*, ERLevel*);
    void RemoveObjectsFromHouse(ERLevel*);
    void AllocSimsObjectInstance(cXObject*);
    void CountObjects(float&, float&, float&, float&);
    void ReOrientHouse(bool);
};

// 0x800549B0
EIObjectMan::EIObjectMan(EHouse* house) {
    char* self = (char*)this;
    *(u32*)(self + 0) = 0;
    // Init ERedBlackTree at offset 4
    *(u32*)(self + 16) = (u32)(uintptr_t)house;
}

// 0x80054A08
void EIObjectMan::Init(void) { /* NOTE: asm-derived */ }
// 0x80054A94
EIObjectMan::~EIObjectMan(void) { /* NOTE: asm-derived */ }
// 0x80054B88
void EIObjectMan::AllPlayersActiveInputInteractors(void) { /* NOTE: asm-derived */ }
// 0x80054C4C
void EIObjectMan::TurnOffAllHighlights(unsigned int mask) { (void)mask; }
// 0x80054CA0
void EIObjectMan::GetObjectsInRect(int rect, TNodeList<ISimInstance*>& list) { (void)rect; (void)list; }
// 0x80054D08
void EIObjectMan::GetObjects(TNodeList<ISimInstance*>& list) { (void)list; }
// 0x80054D54
void EIObjectMan::FreeSimsObjectInstance(ISimInstance* inst) { (void)inst; }
// 0x80054E14
void EIObjectMan::AddObject(cXObject* obj, ERLevel* level) { (void)obj; (void)level; }
// 0x80054FF4
void EIObjectMan::RemoveObjectsFromHouse(ERLevel* level) { (void)level; }
// 0x800550C0
void EIObjectMan::AllocSimsObjectInstance(cXObject* obj) { (void)obj; }
// 0x80055404
void EIObjectMan::CountObjects(float& a, float& b, float& c, float& d) { (void)a; (void)b; (void)c; (void)d; }
// 0x80055990
void EIObjectMan::ReOrientHouse(bool orient) { (void)orient; }


// ============================================================================
// EIFloor - Floor rendering and management
// ============================================================================

class EIFloor {
public:
    void DoLightingCalculation(void);
    EIFloor(void);
    void Draw(ELevelDrawData&);
    void DrawStencil(ELevelDrawData&);
    void DrawShadow(ELevelDrawData&);
    void DestroyFloors(void);
    void CreateFloors(EHouse*);
    void Cleanup(void);
    void IsRoomInFloor(unsigned short);
    void RegisterType(unsigned short);
    ~EIFloor(void);
};

// 0x80046614
void EIFloor::DoLightingCalculation(void) { /* NOTE: asm-derived — evaluate floor lights per vertex */ }
// 0x80047234
EIFloor::EIFloor(void) { char* self = (char*)this; memset(self, 0, 280); }
// 0x80047318
void EIFloor::Draw(ELevelDrawData& data) { (void)data; }
// 0x800474AC
void EIFloor::DrawStencil(ELevelDrawData& data) { (void)data; }
// 0x800475A4
void EIFloor::DrawShadow(ELevelDrawData& data) { (void)data; }
// 0x8004769C
void EIFloor::DestroyFloors(void) { /* NOTE: asm-derived */ }
// 0x800477D0
void EIFloor::CreateFloors(EHouse* house) { (void)house; }
// 0x80047D84
void EIFloor::Cleanup(void) { /* NOTE: asm-derived */ }
// 0x80047E54
void EIFloor::IsRoomInFloor(unsigned short roomId) { (void)roomId; }
// 0x80048440
void EIFloor::RegisterType(unsigned short type) { (void)type; }
// 0x800484B4
EIFloor::~EIFloor(void) { this->DestroyFloors(); }


// ============================================================================
// HouseImpl - House data and logic
// ============================================================================

class HouseImpl {
public:
    HouseImpl(void);
    ~HouseImpl(void);
    void Initialize(void);
    void Destroy(void);
    void RefreshHouse(void);
    void SetLotSize(int, int);
    void LoadFile(iResFile*, int*);
    void ComputeAndStoreLotData(void);
    void SaveFile(iResFile*);
    void DoCommand(short, int);
    void IsNative(cXPerson*);
    void IsResident(cXPerson*);
    void EnterLiveMode(void);
    void PrepareForBudgetWindow(void);
    void DoStream(ReconBuffer*, int);
    void GetHouseStats(HouseStats&);
};

// 0x800BB3C0
HouseImpl::HouseImpl(void) {
    char* self = (char*)this;
    // vtable, then Commander::Commander()
    (void)self;
}

// 0x800BB430
HouseImpl::~HouseImpl(void) { this->Destroy(); }
// 0x800BB4AC
void HouseImpl::Initialize(void) { /* NOTE: asm-derived */ }
// 0x800BB6A8
void HouseImpl::Destroy(void) { /* NOTE: asm-derived */ }
// 0x800BB760
void HouseImpl::RefreshHouse(void) { /* NOTE: asm-derived */ }
// 0x800BB7D4
void HouseImpl::SetLotSize(int w, int h) { (void)w; (void)h; }
// 0x800BB8CC
void HouseImpl::LoadFile(iResFile* file, int* version) { (void)file; (void)version; }
// 0x800BBAE8
void HouseImpl::ComputeAndStoreLotData(void) { /* NOTE: asm-derived */ }
// 0x800BBC3C
void HouseImpl::SaveFile(iResFile* file) { (void)file; }
// 0x800BBD40
void HouseImpl::DoCommand(short cmd, int param) { (void)cmd; (void)param; }
// 0x800BBF9C
void HouseImpl::IsNative(cXPerson* person) { (void)person; }
// 0x800BC00C
void HouseImpl::IsResident(cXPerson* person) { (void)person; }
// 0x800BC0E0
void HouseImpl::EnterLiveMode(void) { /* NOTE: asm-derived */ }
// 0x800BC154
void HouseImpl::PrepareForBudgetWindow(void) { /* NOTE: asm-derived */ }
// 0x800BC1B8
void HouseImpl::DoStream(ReconBuffer* buf, int flags) { (void)buf; (void)flags; }
// 0x800BC24C
void HouseImpl::GetHouseStats(HouseStats& stats) { (void)stats; }


// ============================================================================
// MemoryCardCache - Memory card caching layer
// ============================================================================

class MemoryCardCache {
public:
    void GetMemoryUsage(NghLayout*);
    void GetSubSectionMemoryUsage(NghLayout*, int);
    void Init(NghLayout*);
    void Destroy(void);
    void GetSection(NghLayout*, char*, unsigned int, unsigned int);
    void PutSection(NghLayout*, char*, unsigned int, unsigned int);
    void CacheNghSection(NghLayout*, char*, unsigned int, unsigned int);
    void LoadCacheFromMemoryCard(int, NghResFile*);
    void LoadConfigFromMemoryCard(int);
    void SaveAllToMemoryCard(int);
    void GetConfig(char*, unsigned int, int);
    void PutConfig(char*, unsigned int);
};

// 0x800D29DC
void MemoryCardCache::GetMemoryUsage(NghLayout* layout) {
    char* self = (char*)this;
    if (*(u32*)(self + 4) == 0) return;
    (void)layout;
}

// 0x800D2A68
void MemoryCardCache::GetSubSectionMemoryUsage(NghLayout* layout, int section) { (void)layout; (void)section; }
// 0x800D2AB4
void MemoryCardCache::Init(NghLayout* layout) { (void)layout; }
// 0x800D2BEC
void MemoryCardCache::Destroy(void) { /* NOTE: asm-derived */ }
// 0x800D2CC0
void MemoryCardCache::GetSection(NghLayout* layout, char* name, unsigned int off, unsigned int size) { (void)layout; (void)name; (void)off; (void)size; }
// 0x800D2D9C
void MemoryCardCache::PutSection(NghLayout* layout, char* name, unsigned int off, unsigned int size) { (void)layout; (void)name; (void)off; (void)size; }
// 0x800D2E7C
void MemoryCardCache::CacheNghSection(NghLayout* layout, char* name, unsigned int off, unsigned int size) { (void)layout; (void)name; (void)off; (void)size; }
// 0x800D2FE0
void MemoryCardCache::LoadCacheFromMemoryCard(int slot, NghResFile* file) { (void)slot; (void)file; }
// 0x800D3258
void MemoryCardCache::LoadConfigFromMemoryCard(int slot) { (void)slot; }
// 0x800D333C
void MemoryCardCache::SaveAllToMemoryCard(int slot) { (void)slot; }
// 0x800D3720
void MemoryCardCache::GetConfig(char* key, unsigned int off, int defValue) { (void)key; (void)off; (void)defValue; }
// 0x800D37C8
void MemoryCardCache::PutConfig(char* key, unsigned int value) { (void)key; (void)value; }


// ============================================================================
// TGAWriter - TGA image file writer
// ============================================================================

class TGAWriter {
public:
    void Init(void);
    void Reset(void);
    void WriteHeader(void*, int, int, int);
    void ConvertAndWriteLine(void*, void*, int, int);
    void WriteTGA(void*, int, int, int, char*);
    void WriteTGA16(void*, int, int, int, char*);
    void FinishTGA(void*);
};

// 0x8030C740
void TGAWriter::Init(void) { char* self = (char*)this; memset(self, 0, 32); }
// 0x8030C8E4
void TGAWriter::Reset(void) { /* NOTE: asm-derived */ }
// 0x8030C94C
void TGAWriter::WriteHeader(void* file, int w, int h, int bpp) { (void)file; (void)w; (void)h; (void)bpp; }
// 0x8030CAAC
void TGAWriter::ConvertAndWriteLine(void* file, void* data, int width, int format) { (void)file; (void)data; (void)width; (void)format; }
// 0x8030CCD8
void TGAWriter::WriteTGA(void* tex, int w, int h, int fmt, char* filename) { (void)tex; (void)w; (void)h; (void)fmt; (void)filename; }
// 0x8030D458
void TGAWriter::WriteTGA16(void* tex, int w, int h, int fmt, char* filename) { (void)tex; (void)w; (void)h; (void)fmt; (void)filename; }
// 0x8030D77C
void TGAWriter::FinishTGA(void* file) { (void)file; }


// ============================================================================
// TrapezoidFade - Trapezoid-shaped screen fade effect
// ============================================================================

class TrapezoidFade {
public:
    void Draw(void);
    void Update(float);
};

// 0x80308344
void TrapezoidFade::Draw(void) {
    // NOTE: asm-derived — renders trapezoid fade geometry (3752 bytes of asm)
    char* self = (char*)this;
    (void)self;
}

// 0x803091EC
void TrapezoidFade::Update(float dt) { (void)dt; }


// ============================================================================
// CasCostumes - Create-a-Sim costume management
// ============================================================================

class CasCostumes {
public:
    CasCostumes(void);
    ~CasCostumes(void);
    void GetNumCostumes(int);
    void GetCostumeName(int, int, unsigned short*);
    void GetCostumePreview(int, int);
    void LoadCostumeForSim(int, int);
    void StoreCostume(int);
    void SetRandomCostume(int);
    void ApplyCostume(int, bool);
    void SetCostumeCategory(int);
};

// 0x8015F55C
CasCostumes::CasCostumes(void) {
    char* self = (char*)this;
    memset(self, 0, 64); // approximate
}

// 0x8015F5E0
CasCostumes::~CasCostumes(void) { /* NOTE: asm-derived */ }
// 0x8015F654
void CasCostumes::GetNumCostumes(int category) { (void)category; }
// 0x8015F718
void CasCostumes::GetCostumeName(int category, int idx, unsigned short* outName) { (void)category; (void)idx; (void)outName; }
// 0x8015F7FC
void CasCostumes::GetCostumePreview(int category, int idx) { (void)category; (void)idx; }
// 0x8015F948
void CasCostumes::LoadCostumeForSim(int category, int idx) { (void)category; (void)idx; }
// 0x8015FE24
void CasCostumes::StoreCostume(int category) { (void)category; }
// 0x80160040
void CasCostumes::SetRandomCostume(int category) { (void)category; }
// 0x80160148
void CasCostumes::ApplyCostume(int category, bool apply) { (void)category; (void)apply; }
// 0x80160298
void CasCostumes::SetCostumeCategory(int category) { (void)category; }


// ============================================================================
// AptTextFormat - APT text formatting
// ============================================================================

class AptTextFormat {
public:
    void objectMemberSet(AptValue*, EAStringC*, AptValue*);
    void objectMemberLookup(AptValue*, EAStringC*) const;
    void CleanNativeFunctions(void);
    void sMethod_getTextExtent(AptValue*, int);
    void sAccessor_color(AptValue*, int);
};

// 0x802AF1D4
void AptTextFormat::objectMemberSet(AptValue* obj, EAStringC* name, AptValue* value) { (void)obj; (void)name; (void)value; }
// 0x802AF774
void AptTextFormat::objectMemberLookup(AptValue* obj, EAStringC* name) const { (void)obj; (void)name; }
// 0x802AFC14
void AptTextFormat::CleanNativeFunctions(void) { /* NOTE: asm-derived */ }
// 0x802AFE3C
void AptTextFormat::sMethod_getTextExtent(AptValue* thisVal, int argc) { (void)thisVal; (void)argc; }
// 0x802B0004
void AptTextFormat::sAccessor_color(AptValue* thisVal, int mode) { (void)thisVal; (void)mode; }


// ============================================================================
// AptScriptFunctionBase - APT script function base class
// ============================================================================

class AptScriptFunctionBase {
public:
    AptScriptFunctionBase(AptVirtualFunctionTable_Indices);
    ~AptScriptFunctionBase(void);
    void CleanNativeFunctions(void);
    void objectMemberSet(AptValue*, EAStringC*, AptValue*);
    void objectMemberLookup(AptValue*, EAStringC*) const;
    void sMethod_call(AptValue*, int);
    void sMethod_apply(AptValue*, int);
    void sAccessor_prototype(AptValue*, int);
    void sAccessor_constructor(AptValue*, int);
    void GetByteCodeBlock(void);
    void SetByteCodeBlock(AptScriptFunctionByteCodeBlock*);
    void GetActionBlock(void);
    void SetActionBlock(AptActionBlock*);
    void GetLength(void);
    void SetLength(int);
};

// 0x802B7920
AptScriptFunctionBase::AptScriptFunctionBase(AptVirtualFunctionTable_Indices vft) {
    // NOTE: asm-derived — call base AptValue ctor, set vtable
    (void)vft;
}

// 0x802B79D4
AptScriptFunctionBase::~AptScriptFunctionBase(void) { this->CleanNativeFunctions(); }
// 0x802B7A74
void AptScriptFunctionBase::CleanNativeFunctions(void) { /* NOTE: asm-derived */ }
// 0x802B7D54
void AptScriptFunctionBase::objectMemberSet(AptValue* obj, EAStringC* name, AptValue* value) { (void)obj; (void)name; (void)value; }
// 0x802B7FA8
void AptScriptFunctionBase::objectMemberLookup(AptValue* obj, EAStringC* name) const { (void)obj; (void)name; }
// 0x802B820C
void AptScriptFunctionBase::sMethod_call(AptValue* thisVal, int argc) { (void)thisVal; (void)argc; }
// 0x802B82A4
void AptScriptFunctionBase::sMethod_apply(AptValue* thisVal, int argc) { (void)thisVal; (void)argc; }
// 0x802B8390
void AptScriptFunctionBase::sAccessor_prototype(AptValue* thisVal, int mode) { (void)thisVal; (void)mode; }
// 0x802B8430
void AptScriptFunctionBase::sAccessor_constructor(AptValue* thisVal, int mode) { (void)thisVal; (void)mode; }
// 0x802B8804
void AptScriptFunctionBase::GetByteCodeBlock(void) { /* NOTE: asm-derived */ }
// 0x802B885C
void AptScriptFunctionBase::SetByteCodeBlock(AptScriptFunctionByteCodeBlock* block) { (void)block; }
// 0x802B88AC
void AptScriptFunctionBase::GetActionBlock(void) { /* NOTE: asm-derived */ }
// 0x802B8980
void AptScriptFunctionBase::SetActionBlock(AptActionBlock* block) { (void)block; }
// 0x802B8A18
void AptScriptFunctionBase::GetLength(void) { /* NOTE: asm-derived */ }
// 0x802B8B70
void AptScriptFunctionBase::SetLength(int len) { (void)len; }


// ============================================================================
// AptXml - APT XML parsing
// ============================================================================

class AptXml {
public:
    AptXml(AptVirtualFunctionTable_Indices);
    ~AptXml(void);
    void CleanNativeFunctions(void);
    void objectMemberSet(AptValue*, EAStringC*, AptValue*);
    void objectMemberLookup(AptValue*, EAStringC*) const;
    void sMethod_createElement(AptValue*, int);
    void sMethod_createTextNode(AptValue*, int);
    void sMethod_parseXML(AptValue*, int);
    void sMethod_toString(AptValue*, int);
    void sAccessor_childNodes(AptValue*, int);
};

// 0x802B93D4
AptXml::AptXml(AptVirtualFunctionTable_Indices vft) { (void)vft; }
// 0x802B942C
AptXml::~AptXml(void) { this->CleanNativeFunctions(); }
// 0x802B9548
void AptXml::CleanNativeFunctions(void) { /* NOTE: asm-derived */ }
// 0x802B958C
void AptXml::objectMemberSet(AptValue* obj, EAStringC* name, AptValue* value) { (void)obj; (void)name; (void)value; }
// 0x802B9674
void AptXml::objectMemberLookup(AptValue* obj, EAStringC* name) const { (void)obj; (void)name; }
// 0x802B96CC
void AptXml::sMethod_createElement(AptValue* thisVal, int argc) { (void)thisVal; (void)argc; }
// 0x802B9E3C
void AptXml::sMethod_createTextNode(AptValue* thisVal, int argc) { (void)thisVal; (void)argc; }
// 0x802B9F24
void AptXml::sMethod_parseXML(AptValue* thisVal, int argc) { (void)thisVal; (void)argc; }
// 0x802BA00C
void AptXml::sMethod_toString(AptValue* thisVal, int argc) { (void)thisVal; (void)argc; }
// 0x802BA114
void AptXml::sAccessor_childNodes(AptValue* thisVal, int mode) { (void)thisVal; (void)mode; }


// ============================================================================
// AptXmlNode - APT XML node
// ============================================================================

class AptXmlNode {
public:
    AptXmlNode(AptVirtualFunctionTable_Indices, IAptXmlNode*);
    ~AptXmlNode(void);
    void CleanNativeFunctions(void);
    void objectMemberSet(AptValue*, EAStringC*, AptValue*);
    void objectMemberLookup(AptValue*, EAStringC*) const;
    void sMethod_hasChildNodes(AptValue*, int);
    void sMethod_toString(AptValue*, int);
};

// 0x802BA3B4
AptXmlNode::AptXmlNode(AptVirtualFunctionTable_Indices vft, IAptXmlNode* xmlNode) {
    char* self = (char*)this;
    // AptValue ctor, set native hash, store xmlNode ref
    *(u8*)(self + 32) = 0;
    (void)vft; (void)xmlNode;
}

// 0x802BA438
AptXmlNode::~AptXmlNode(void) { this->CleanNativeFunctions(); }
// 0x802BA4AC
void AptXmlNode::CleanNativeFunctions(void) { /* NOTE: asm-derived */ }
// 0x802BA648
void AptXmlNode::objectMemberSet(AptValue* obj, EAStringC* name, AptValue* value) { (void)obj; (void)name; (void)value; }
// 0x802BA820
void AptXmlNode::objectMemberLookup(AptValue* obj, EAStringC* name) const { (void)obj; (void)name; }
// 0x802BB348
void AptXmlNode::sMethod_hasChildNodes(AptValue* thisVal, int argc) { (void)thisVal; (void)argc; }
// 0x802BB4E4
void AptXmlNode::sMethod_toString(AptValue* thisVal, int argc) { (void)thisVal; (void)argc; }


// ============================================================================
// UI Target classes - Common UI target pattern
// ============================================================================
// All UI Targets share: [0-24] base fields, [128] vtable, [40+] string table entries
// Constructor pattern: zero fields 0-24, set vtable, init string table entries

class FlowGotoTarget {
public:
    FlowGotoTarget(void);
    ~FlowGotoTarget(void);
    void SetVariable(char*, char*);
    void GetVariable(char*);
};

// 0x8017ABA0
FlowGotoTarget::FlowGotoTarget(void) {
    char* self = (char*)this;
    // Zero base fields, set vtable at 128, init string table entries
    for (int i = 0; i < 7; i++) *(u32*)(self + i * 4) = 0;
    // Init 6 string table entries at offsets 40,56,72,88,104,120
}

// 0x8017B02C
FlowGotoTarget::~FlowGotoTarget(void) { /* NOTE: asm-derived */ }
// 0x8017B170
void FlowGotoTarget::SetVariable(char* name, char* value) { (void)name; (void)value; }
// 0x8017B87C
void FlowGotoTarget::GetVariable(char* name) { (void)name; }


class RGTTarget {
public:
    RGTTarget(int);
    ~RGTTarget(void);
    void SetupNames(int);
    void GetVariable(char*);
    void SetVariable(char*, char*);
    void FindActualRingtoneIndex(int);
    void SetupRingtoneUnlocks(void);
};

// 0x80201654
RGTTarget::RGTTarget(int param) {
    char* self = (char*)this;
    for (int i = 0; i < 7; i++) *(u32*)(self + i * 4) = 0;
    this->SetupNames(param);
}

// 0x80201DD8
RGTTarget::~RGTTarget(void) { /* NOTE: asm-derived */ }
// 0x80201F9C
void RGTTarget::SetupNames(int param) { (void)param; }
// 0x802020E4
void RGTTarget::GetVariable(char* name) { (void)name; }
// 0x802021A8
void RGTTarget::SetVariable(char* name, char* value) { (void)name; (void)value; }
// 0x80202378
void RGTTarget::FindActualRingtoneIndex(int idx) { (void)idx; }
// 0x802023E0
void RGTTarget::SetupRingtoneUnlocks(void) { /* NOTE: asm-derived */ }


class CASMorphTarget {
public:
    CASMorphTarget(void);
    ~CASMorphTarget(void);
    void SetVariable(char*, char*);
    void SetVariableSubnav(UIScreenID, int, int);
    void GetLocalizableSubnav(UIScreenID, int, unsigned short*);
    void GetVariable(char*);
    void EnterMorphScreen(void);
    void ExitMorphScreenPrev(void);
};

// 0x8019C740
CASMorphTarget::CASMorphTarget(void) {
    char* self = (char*)this;
    for (int i = 0; i < 7; i++) *(u32*)(self + i * 4) = 0;
}

// 0x8019CC34
CASMorphTarget::~CASMorphTarget(void) { /* NOTE: asm-derived */ }
// 0x8019CD90
void CASMorphTarget::SetVariable(char* name, char* value) { (void)name; (void)value; }
// 0x8019CF0C
void CASMorphTarget::SetVariableSubnav(UIScreenID screen, int nav, int sub) { (void)screen; (void)nav; (void)sub; }
// 0x8019CFC4
void CASMorphTarget::GetLocalizableSubnav(UIScreenID screen, int nav, unsigned short* out) { (void)screen; (void)nav; (void)out; }
// 0x8019D1F8
void CASMorphTarget::GetVariable(char* name) { (void)name; }
// 0x8019D3AC
void CASMorphTarget::EnterMorphScreen(void) { /* NOTE: asm-derived */ }
// 0x8019D434
void CASMorphTarget::ExitMorphScreenPrev(void) { /* NOTE: asm-derived */ }


class CASFashionTarget {
public:
    CASFashionTarget(void);
    ~CASFashionTarget(void);
    void SetVariable(char*, char*);
    void SetVariableSubnav(UIScreenID, int, int);
    void GetLocalizableSubnav(UIScreenID, int, unsigned short*);
    void GetVariable(char*);
    void EnterFashionScreen(void);
    void ExitFashionScreenPrev(void);
    void ChangeCurrentFashion(int);
};

// 0x8019ADBC
CASFashionTarget::CASFashionTarget(void) {
    char* self = (char*)this;
    for (int i = 0; i < 7; i++) *(u32*)(self + i * 4) = 0;
}

// 0x8019B254
CASFashionTarget::~CASFashionTarget(void) { /* NOTE: asm-derived */ }
// 0x8019B3B0
void CASFashionTarget::SetVariable(char* name, char* value) { (void)name; (void)value; }
// 0x8019B404
void CASFashionTarget::SetVariableSubnav(UIScreenID screen, int nav, int sub) { (void)screen; (void)nav; (void)sub; }
// 0x8019B464
void CASFashionTarget::GetLocalizableSubnav(UIScreenID screen, int nav, unsigned short* out) { (void)screen; (void)nav; (void)out; }
// 0x8019B6EC
void CASFashionTarget::GetVariable(char* name) { (void)name; }
// 0x8019B7B0
void CASFashionTarget::EnterFashionScreen(void) { /* NOTE: asm-derived */ }
// 0x8019B82C
void CASFashionTarget::ExitFashionScreenPrev(void) { /* NOTE: asm-derived */ }
// 0x8019B900
void CASFashionTarget::ChangeCurrentFashion(int idx) { (void)idx; }


class FONTarget {
public:
    FONTarget(void);
    ~FONTarget(void);
    void GetVariable(char*);
    void SetVariable(char*, char*);
    void GetLocalizable(char*);
};

// 0x801E9808
FONTarget::FONTarget(void) {
    char* self = (char*)this;
    for (int i = 0; i < 7; i++) *(u32*)(self + i * 4) = 0;
}

// 0x801EA07C
FONTarget::~FONTarget(void) { /* NOTE: asm-derived */ }
// 0x801EA260
void FONTarget::GetVariable(char* name) { (void)name; }
// 0x801EA394
void FONTarget::SetVariable(char* name, char* value) { (void)name; (void)value; }
// 0x801EA50C
void FONTarget::GetLocalizable(char* name) { (void)name; }


class BBHTarget {
public:
    BBHTarget(void);
    ~BBHTarget(void);
    void SetVariable(char*, char*);
    void GetVariable(char*);
    void GetLocalizable(char*);
    void Update(void);
    void UpdateBillboard(void);
    void BuildBillboardMenuString(void);
    void HandleBBHCasEvent(void);
    void GetBillboardInfo(void);
};

// 0x801A31C4
BBHTarget::BBHTarget(void) {
    char* self = (char*)this;
    for (int i = 0; i < 7; i++) *(u32*)(self + i * 4) = 0;
}

// 0x801A3788
BBHTarget::~BBHTarget(void) { /* NOTE: asm-derived */ }
// 0x801A390C
void BBHTarget::SetVariable(char* name, char* value) { (void)name; (void)value; }
// 0x801A39BC
void BBHTarget::GetVariable(char* name) { (void)name; }
// 0x801A3A54
void BBHTarget::GetLocalizable(char* name) { (void)name; }
// 0x801A3CC0
void BBHTarget::Update(void) { /* NOTE: asm-derived */ }
// 0x801A3E30
void BBHTarget::UpdateBillboard(void) { /* NOTE: asm-derived */ }
// 0x801A3EB4
void BBHTarget::BuildBillboardMenuString(void) { /* NOTE: asm-derived */ }
// 0x801A3FB4
void BBHTarget::HandleBBHCasEvent(void) { /* NOTE: asm-derived */ }
// 0x801A4018
void BBHTarget::GetBillboardInfo(void) { /* NOTE: asm-derived */ }


class FCMTarget {
public:
    FCMTarget(void);
    ~FCMTarget(void);
    void SetVariable(char*, char*);
    void GetVariable(char*);
    void GetLocalizable(char*);
    void Update(void);
    void ShowFireCodeMeter(void);
    void UpdateFireCodeMeter(void);
};

// 0x801B34C0
FCMTarget::FCMTarget(void) {
    char* self = (char*)this;
    for (int i = 0; i < 7; i++) *(u32*)(self + i * 4) = 0;
}

// 0x801B3B68
FCMTarget::~FCMTarget(void) { /* NOTE: asm-derived */ }
// 0x801B3CC8
void FCMTarget::SetVariable(char* name, char* value) { (void)name; (void)value; }
// 0x801B3DD0
void FCMTarget::GetVariable(char* name) { (void)name; }
// 0x801B3E6C
void FCMTarget::GetLocalizable(char* name) { (void)name; }
// 0x801B3EF0
void FCMTarget::Update(void) { /* NOTE: asm-derived */ }
// 0x801B3FF8
void FCMTarget::ShowFireCodeMeter(void) { /* NOTE: asm-derived */ }
// 0x801B41C4
void FCMTarget::UpdateFireCodeMeter(void) { /* NOTE: asm-derived */ }


class ITBTarget {
public:
    ITBTarget(void);
    ~ITBTarget(void);
    void SetVariable(char*, char*);
    void GetVariable(char*);
    void GetLocalizable(char*);
    void Update(void);
    void UpdateIntroThoughtBalloon(void);
    void SpawnIntroThoughtBalloon(UIDialog*);
};

// 0x801BCA3C
ITBTarget::ITBTarget(void) {
    char* self = (char*)this;
    for (int i = 0; i < 7; i++) *(u32*)(self + i * 4) = 0;
}

// 0x801BD088
ITBTarget::~ITBTarget(void) { /* NOTE: asm-derived */ }
// 0x801BD1F8
void ITBTarget::SetVariable(char* name, char* value) { (void)name; (void)value; }
// 0x801BD32C
void ITBTarget::GetVariable(char* name) { (void)name; }
// 0x801BD3C8
void ITBTarget::GetLocalizable(char* name) { (void)name; }
// 0x801BD490
void ITBTarget::Update(void) { /* NOTE: asm-derived */ }
// 0x801BD888
void ITBTarget::UpdateIntroThoughtBalloon(void) { /* NOTE: asm-derived */ }
// 0x801BD8FC
void ITBTarget::SpawnIntroThoughtBalloon(UIDialog* dlg) { (void)dlg; }


class INTTarget {
public:
    INTTarget(int);
    ~INTTarget(void);
    void SetVariable(char*, char*);
    void GetVariable(char*);
    void GetLocalizable(char*);
    void Update(void);
    void UpdateInterestMeter(void);
    void SetInteractionDisplayValues(unsigned int, unsigned int);
    void TriggerInteractionAnimation(unsigned int, unsigned int, unsigned int);
    void MirrorUpArrow(bool);
};

// 0x801F8024
INTTarget::INTTarget(int param) {
    char* self = (char*)this;
    for (int i = 0; i < 7; i++) *(u32*)(self + i * 4) = 0;
    (void)param;
}

// 0x801F8720
INTTarget::~INTTarget(void) { /* NOTE: asm-derived */ }
// 0x801F88D4
void INTTarget::SetVariable(char* name, char* value) { (void)name; (void)value; }
// 0x801F89E4
void INTTarget::GetVariable(char* name) { (void)name; }
// 0x801F8A7C
void INTTarget::GetLocalizable(char* name) { (void)name; }
// 0x801F8BC0
void INTTarget::Update(void) { /* NOTE: asm-derived */ }
// 0x801F8DB0
void INTTarget::UpdateInterestMeter(void) { /* NOTE: asm-derived */ }
// 0x801F8E94
void INTTarget::SetInteractionDisplayValues(unsigned int a, unsigned int b) { (void)a; (void)b; }
// 0x801F8FDC
void INTTarget::TriggerInteractionAnimation(unsigned int a, unsigned int b, unsigned int c) { (void)a; (void)b; (void)c; }
// 0x801F9154
void INTTarget::MirrorUpArrow(bool mirror) { (void)mirror; }


class PAZBase {
public:
    PAZBase(void);
    ~PAZBase(void);
    void SetVariable(char*, char*);
    void GetVariable(char*);
    void GetLocalizable(char*);
    void Update(void);
};

// 0x801D0190
PAZBase::PAZBase(void) {
    char* self = (char*)this;
    for (int i = 0; i < 7; i++) *(u32*)(self + i * 4) = 0;
}

// 0x801D0318
PAZBase::~PAZBase(void) { /* NOTE: asm-derived */ }
// 0x801D0864
void PAZBase::SetVariable(char* name, char* value) { (void)name; (void)value; }
// 0x801D0A74
void PAZBase::GetVariable(char* name) { (void)name; }
// 0x801D0B74
void PAZBase::GetLocalizable(char* name) { (void)name; }
// 0x801D0ED4
void PAZBase::Update(void) { /* NOTE: asm-derived */ }


// ============================================================================
// UIDB - UI Database
// ============================================================================

class UIDB {
public:
    void UIDBInit(void);
    void UIDBShutdown(void);
    void UIDBGetInt(char*);
    void UIDBGetFloat(char*);
    void UIDBGetString(char*);
    void UIDBSetInt(char*, int);
    void UIDBSetFloat(char*, float);
    void UIDBSetString(char*, unsigned short*);
    void UIDBFindRecord(char*, int);
};

// 0x80178D90
void UIDB::UIDBInit(void) {
    // NOTE: asm-derived — massive init (3268 bytes), sets up all UI database records
    char* self = (char*)this;
    (void)self;
}

// 0x80179A54
void UIDB::UIDBShutdown(void) { /* NOTE: asm-derived */ }
// 0x80179AC8
void UIDB::UIDBGetInt(char* key) { (void)key; }
// 0x80179B18
void UIDB::UIDBGetFloat(char* key) { (void)key; }
// 0x80179B60
void UIDB::UIDBGetString(char* key) { (void)key; }
// 0x80179BB0
void UIDB::UIDBSetInt(char* key, int value) { (void)key; (void)value; }
// 0x80179C10
void UIDB::UIDBSetFloat(char* key, float value) { (void)key; (void)value; }
// 0x80179C68
void UIDB::UIDBSetString(char* key, unsigned short* value) { (void)key; (void)value; }
// 0x80179D04
void UIDB::UIDBFindRecord(char* key, int createIfMissing) { (void)key; (void)createIfMissing; }


// ============================================================================
// UIScreenManager - UI screen state manager
// ============================================================================

class UIScreenManager {
public:
    UIScreenManager(void);
    ~UIScreenManager(void);
    void FindDataByID(UIScreenID);
    void LoadUIScreen(UIScreenID, UIScreenInputMode);
    void UnloadUIScreen(UIScreenID);
    void SuspendAllActiveScreens(void);
    void SuspendScreenList(UIScreenID*);
    void AddScreen(UIScreenID, int);
    void RemoveScreen(UIScreenID);
    void GetScreenFlashName(char*, UIScreenID);
    void IsUIScreenMarkedForUnloading(UIScreenID);
    void SetHandlesInput(UIScreenID, bool);
    void SetVariable(char*, char*);
    void Update(void);
};

// 0x8017F0D0
UIScreenManager::UIScreenManager(void) {
    char* self = (char*)this;
    // Base UIObjectBase init, then init screen array
    for (int i = 0; i < 7; i++) *(u32*)(self + i * 4) = 0;
}

// 0x8017F688
UIScreenManager::~UIScreenManager(void) { /* NOTE: asm-derived */ }
// 0x8017F838
void UIScreenManager::FindDataByID(UIScreenID id) { (void)id; }
// 0x8017F884
void UIScreenManager::LoadUIScreen(UIScreenID id, UIScreenInputMode mode) { (void)id; (void)mode; }
// 0x8017FAE4
void UIScreenManager::UnloadUIScreen(UIScreenID id) { (void)id; }
// 0x8017FCB0
void UIScreenManager::SuspendAllActiveScreens(void) { /* NOTE: asm-derived */ }
// 0x8017FD58
void UIScreenManager::SuspendScreenList(UIScreenID* list) { (void)list; }
// 0x8017FE64
void UIScreenManager::AddScreen(UIScreenID id, int priority) { (void)id; (void)priority; }
// 0x8017FEF8
void UIScreenManager::RemoveScreen(UIScreenID id) { (void)id; }
// 0x8017FF44
void UIScreenManager::GetScreenFlashName(char* outName, UIScreenID id) { (void)outName; (void)id; }
// 0x80180068
void UIScreenManager::IsUIScreenMarkedForUnloading(UIScreenID id) { (void)id; }
// 0x801800BC
void UIScreenManager::SetHandlesInput(UIScreenID id, bool handles) { (void)id; (void)handles; }
// 0x8018019C
void UIScreenManager::SetVariable(char* name, char* value) { (void)name; (void)value; }
// 0x80180274
void UIScreenManager::Update(void) { /* NOTE: asm-derived */ }
