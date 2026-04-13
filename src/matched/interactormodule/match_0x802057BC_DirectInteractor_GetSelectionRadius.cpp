// 0x802057BC DirectInteractor::GetSelectionRadius (12b)

extern char g_selectionRadius[];

struct DirectInteractor {
    static float GetSelectionRadius(void);
};

float DirectInteractor::GetSelectionRadius(void) {
    return *(float*)g_selectionRadius;
}
