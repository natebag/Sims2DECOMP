/* AptViewer::AddCmdToAptButtonFilter(int, unsigned int, ECTRL_CMD) - 0x80011C44 (100B) */

struct Controller {
    int AddCmd(unsigned int mask, int cmd);
};

class AptViewer {
public:
    char pad[936];
    int m_field_936;

    Controller* GetPlayersController(int player);
    void AddCmdToAptButtonFilter(int player, unsigned int mask, int cmd);
};

void AptViewer::AddCmdToAptButtonFilter(int player, unsigned int mask, int cmd) {
    if (m_field_936 == 0) return;
    if ((unsigned)player > 1) player = 0;
    if (cmd > 49) return;
    Controller* ctrl = GetPlayersController(player);
    if (ctrl == 0) return;
    ctrl->AddCmd(mask, cmd);
}
