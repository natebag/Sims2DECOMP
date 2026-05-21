// 0x8018FEF0 SaveGameTarget::BGCall_SaveGame(void) (76B)
// TRIAGE

class SaveGameTarget;
extern void BGExec_SaveGame(void*);  // 0x8018FF3C

class IManager {
public:
    virtual void M0();
    virtual void M1();
    virtual void M2();
    virtual void M3();
    virtual void M4();
    virtual void M5();
    virtual void M6();
    virtual void M7();
    virtual void PostCallback(void* fn, void* data);  // slot 9 (offset 72)
};

extern IManager* g_saveManager;   // SDA -22756
extern int g_saveFlag;             // SDA -21480

class SaveGameTarget {
public:
    void BGCall_SaveGame();
};

void SaveGameTarget::BGCall_SaveGame() {
    g_saveFlag = 0;
    g_saveManager->PostCallback((void*)&BGExec_SaveGame, this);
}
