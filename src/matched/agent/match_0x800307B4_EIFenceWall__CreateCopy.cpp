void* FenceWallCreateCopyImpl(void* self);

void* EIFenceWall_CreateCopy(void* self) {
    return FenceWallCreateCopyImpl(self);
}
