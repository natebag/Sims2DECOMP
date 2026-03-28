extern void* ELevelManager_inner(void* arg);

void* ELevelManager_thunk(void* self, void* arg) {
    return ELevelManager_inner(arg);
}
