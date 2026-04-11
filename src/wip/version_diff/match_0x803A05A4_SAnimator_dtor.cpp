// SAnimator::~SAnimator(void)
// Address: 0x803A05A4 | Size: 52 bytes
// Pattern: Destructor with vtable reset at offset 0 and conditional base dtor call

struct SAnimator {
    void* vtable;  // at offset 0
};

// vtable at 0x8046CBB0
extern char gSAnimatorVtable[4];

// Forward declaration of base destructor
extern "C" void SAnimator_Base_dtor(void* obj);

extern "C" void SAnimator_dtor(SAnimator* this_, int flags) {
    this_->vtable = &gSAnimatorVtable;
    if (flags & 1) {
        SAnimator_Base_dtor(this_);
    }
}
