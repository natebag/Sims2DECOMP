/* AptViewer::RemoveCmdFromAptButtonFilter(int, unsigned int, ECTRL_CMD) - 0x80011CA8 (100B) */

struct Controller {
    int RemoveCmd(unsigned int mask, int cmd);
};

class AptViewer {
public:
    char pad[936];
    int m_field_936;

    Controller* GetPlayersController(int player);
    void RemoveCmdFromAptButtonFilter(int player, unsigned int mask, int cmd);
};

void AptViewer::RemoveCmdFromAptButtonFilter(int player, unsigned int mask, int cmd) {
    if (m_field_936 == 0) return;
    if ((unsigned)player > 1) player = 0;
    if (cmd > 49) return;
    Controller* ctrl = GetPlayersController(player);
    if (ctrl == 0) return;
    ctrl->RemoveCmd(mask, cmd);
}
