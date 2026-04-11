// Function at 0x801104B4 from ObjSelector.cpp

class BString {
public:
    void SetFlags(int flags);
};

// Global BString at r13 offset
extern BString* g_ObjSelector_global;

void ObjSelector_sub() {
    BString* obj = *(BString**)((char*)0 + (-24172));
    obj->SetFlags(2);
}
