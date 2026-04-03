void AptDisplayList_StopAll(void* list, int flag);

struct AptCharacterAnimationInst {
    char pad[0x24];

    void PreDestroy();
};

void AptCharacterAnimationInst::PreDestroy() {
    AptDisplayList_StopAll((char*)this + 0x24, 0);
}
