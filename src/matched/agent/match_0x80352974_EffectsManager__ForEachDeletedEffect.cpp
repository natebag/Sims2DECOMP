extern "C" void forEach(void* self, void* visitor, void* list);
void EffectsManager_ForEachDeletedEffect(void* self, void* visitor) {
    forEach(self, visitor, (char*)self + 16);
}
