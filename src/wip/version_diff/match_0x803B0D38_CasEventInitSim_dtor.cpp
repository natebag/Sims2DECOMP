// CasEventInitSim::~CasEventInitSim(void)
// Address: 0x803B0D38 | Size: 48 bytes
// Pattern: Destructor setting vtable and calling base dtor

struct CasEventInitSim {
    void* vtable;  // at offset 0
};

// vtable at 0x80466028
extern char gCasEventInitSimVtable[4];

// Forward declaration of base destructor
extern "C" void CasEvent_Base_dtor(void* obj);

extern "C" void CasEventInitSim_dtor(CasEventInitSim* this_) {
    this_->vtable = &gCasEventInitSimVtable;
    CasEvent_Base_dtor(this_);
}
