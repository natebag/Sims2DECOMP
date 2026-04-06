// 0x803B5E20 CBMemberTranslator0<ACTTarget, void (ACTTarget::*)(ACTTarget *)>::thunk (120b)

struct CBFunctorBase {
    short field_0;
    short field_2;
    int field_4;
    int field_8;
};

struct ACTTarget {
    virtual void Execute(ACTTarget*);
};

void CBMemberTranslator0_Thunk(CBFunctorBase* functor, ACTTarget* target) {
    // Load vtable adjustment
    short vtbl_idx = functor->field_2;
    int* vtbl = (int*)functor->field_8;
    
    // Calculate this pointer adjustment
    ACTTarget* adjusted_target = target;
    if (vtbl_idx >= 0) {
        // Vtable dispatch
        int vtbl_entry = vtbl[vtbl_idx * 2];
        adjusted_target = (ACTTarget*)((char*)target + (vtbl_entry >> 16));
    }
    
    // Call the function
    adjusted_target->Execute(target);
}
