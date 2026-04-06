extern "C" void forEach(void* self, void* visitor, void* list);
void EffectsManager_ForEachActiveEffect(void* self, void* visitor) {
    forEach(self, visitor, (char*)self + 4);
}
