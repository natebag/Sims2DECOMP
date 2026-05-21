// 0x8001AE0C ESimsCam::ReadControllerRotation(void) (84B)

class EController {
public:
    int GetStick(int a, int b, unsigned int c);
};

class EControllerManager {
public:
    int GetPlayerControllerIndex(int playerIdx);
    EController* GetController(int idx);
};

extern EControllerManager* gv_controllerMgr;

class ESimsCam {
public:
    char _pad0[4];
    int m_playerIdx;
    char _pad8[1376 - 8];
    unsigned int m_field1376;

    int ReadControllerRotation();
};

int ESimsCam::ReadControllerRotation() {
    EControllerManager* mgr = gv_controllerMgr;
    int pIdx = mgr->GetPlayerControllerIndex(m_playerIdx);
    return mgr->GetController(pIdx)->GetStick(1, 0, m_field1376);
}
