// 0x802857E0 (32B) AptCharacterAnimationInst::operator delete [](void *)
// Thunk to AptNonGCFreeSavedSize(void *)

extern void AptNonGCFreeSavedSize(void * a0);

void operator delete [](void * a0) {
    AptNonGCFreeSavedSize(a0);
}
