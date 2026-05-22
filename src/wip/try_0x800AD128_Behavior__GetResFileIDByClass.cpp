// 0x800AD128 Behavior::GetResFileIDByClass(short) (84B)
// DOL: entire vtable dispatch hoisted before bl GetBaseID.
// Approach: explicit vtable slot access before GetBaseID call forces
// the compiler to evaluate lha/addi/add before the bl.
// VEntry is 8 bytes {short thisAdj, short pad, void* fn} matching SN ProDG 8-byte vtable.

class Language;
class ObjSelector;

struct BehaviorVEntry {
    short thisAdj;
    short pad;
    void* fn;
};

class Behavior {
public:
    virtual int QueryInterface(unsigned int iid, void** ppv) = 0;
    virtual void AddRef() = 0;
    virtual void Release() = 0;
    virtual ~Behavior() {}
    virtual void Init(Language* lang, ObjSelector* sel) {}
    virtual int GetResFileID(int id);
    virtual int CountTrees(short classId) = 0;
    virtual int GetTreeByIndex(int index, short classId, void** ppTree) = 0;
    virtual int GetTreeIDByName(char* name) = 0;

    static int GetBaseID(short id);
    int GetResFileIDByClass(short id);
};

int Behavior::GetResFileIDByClass(short id) {
    BehaviorVEntry* vt = (BehaviorVEntry*)*(void**)this;
    short adj = vt[6].thisAdj;           // lha r0, 48(r30)
    vt += 6;                              // addi r30, r30, 48
    Behavior* adjusted = (Behavior*)((char*)this + adj);  // add r29, r29, r0

    int base = GetBaseID(id);

    typedef int (*Fn)(Behavior*, int);
    return ((Fn)vt->fn)(adjusted, base); // lwz r0, 4(r30); mr r4,r3; mr r3,r29; blrl
}
