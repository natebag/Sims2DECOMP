void* WallPartCreateCopyImpl(void* self);

void* EIWallPart_CreateCopy(void* self) {
    return WallPartCreateCopyImpl(self);
}
