// 0x800AD128 Behavior::GetResFileIDByClass(short) (84B)
// Explicit vtable slot access before GetBaseID forces the compiler to evaluate
// the lha/addi/add dispatch setup before the bl, matching the DOL's scheduler hoist.

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
    short adj = vt[6].thisAdj;
    vt += 6;
    Behavior* adjusted = (Behavior*)((char*)this + adj);

    int base = GetBaseID(id);

    typedef int (*Fn)(Behavior*, int);
    return ((Fn)vt->fn)(adjusted, base);
}
