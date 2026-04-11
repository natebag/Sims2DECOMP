// PlumbBobParms::~PlumbBobParms(void)
// Address: 0x803A0570 | Size: 52 bytes
// Pattern: Destructor with vtable reset and conditional base dtor call

struct PlumbBobParms {
    void* vtable;  // at offset 0x60 (vtable pointer)
};

// vtable at 0x8046CA38
extern char gPlumbBobParmsVtable[4];

// Forward declaration of base destructor
extern "C" void PlumbBobParms_Base_dtor(void* obj);

extern "C" void PlumbBobParms_dtor(PlumbBobParms* this_, int flags) {
    this_->vtable = &gPlumbBobParmsVtable;
    if (flags & 1) {
        PlumbBobParms_Base_dtor(this_);
    }
}
