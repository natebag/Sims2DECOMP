/* InteractorModule::DirectInteractor::GetSelectionRadius(void) at 0x802057BC (12B) */

#pragma section SDA=".sdata"
extern float g_selectionRadius;
#pragma section

struct DirectInteractor {
    static float GetSelectionRadius(void);
};

float DirectInteractor::GetSelectionRadius(void) {
    return g_selectionRadius;
}
