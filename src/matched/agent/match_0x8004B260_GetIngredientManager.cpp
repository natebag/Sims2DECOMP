// GetIngredientManager(void) at 0x8004B260 (60 bytes)
// Function-local static singleton with lazy init via new + ctor.
// Static is mangled as `spIngredientManager.2190` (GCC 2.95 .NUMBER suffix).

class IngredientManager {
public:
    IngredientManager();
};

IngredientManager* GetIngredientManager() {
    static IngredientManager* spIngredientManager;
    if (spIngredientManager == 0) {
        spIngredientManager = new IngredientManager;
    }
    return spIngredientManager;
}
