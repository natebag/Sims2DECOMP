/* AwarenessManager::SetIsRaining(bool) at 0x80012250 (8B) */

extern int g_isRaining;

struct AwarenessManager {
    static void SetIsRaining(int val);
};

void AwarenessManager::SetIsRaining(int val) {
    g_isRaining = val;
}
