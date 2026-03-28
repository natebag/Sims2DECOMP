/* IngredientManager::~IngredientManager(void) at 0x8004B308 (40B) */

void __builtin_delete(void *ptr);

void IngredientManager_dtor(void *self, int delFlag) {
    if (delFlag & 1) {
        __builtin_delete(self);
    }
}
