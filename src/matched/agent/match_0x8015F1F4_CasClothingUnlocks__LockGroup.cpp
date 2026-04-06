extern "C" void CasClothingUnlocks_SetGroupLock(void* self, unsigned int id, int lock, int notify);

void CasClothingUnlocks_LockGroup(void* self, unsigned int id) {
    CasClothingUnlocks_SetGroupLock(self, id, 1, 0);
}
