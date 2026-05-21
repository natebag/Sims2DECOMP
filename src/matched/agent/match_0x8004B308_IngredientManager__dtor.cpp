// 0x8004B308 (40B) IngredientManager::~IngredientManager(void)
// Deleting dtor — empty body, conditional __builtin_delete on flag&1.

void __builtin_delete(void* p);

struct IngredientManager {
    void dtor(int flag);
};

void IngredientManager::dtor(int flag) {
    if (flag & 1) {
        __builtin_delete(this);
    }
}
