// __tcf_2 - static cleanup function
// Uses small data area (r13 relative)

struct BStringThing {
    void SetFlags(int);
};

// Place in sdata/sbss section for r13 relative access
extern BStringThing _ZN11ObjSelector16sUserObjectNameE;

void __tcf_2() {
    _ZN11ObjSelector16sUserObjectNameE.SetFlags(2);
}
