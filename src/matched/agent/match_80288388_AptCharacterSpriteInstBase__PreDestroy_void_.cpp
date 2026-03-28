void AptDisplayList_RemoveAll(void* list);

struct AptCharacterSpriteInstBase {
    char pad[0x24];

    void PreDestroy();
};

void AptCharacterSpriteInstBase::PreDestroy() {
    AptDisplayList_RemoveAll((char*)this + 0x24);
}
