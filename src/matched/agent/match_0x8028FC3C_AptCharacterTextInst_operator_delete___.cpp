// 0x8028FC3C (32B) AptCharacterTextInst::operator delete [](void *)
// Thunk to AptNonGCFreeSavedSize(void *)

extern void AptNonGCFreeSavedSize(void * a0);

void operator delete [](void * a0) {
    AptNonGCFreeSavedSize(a0);
}
