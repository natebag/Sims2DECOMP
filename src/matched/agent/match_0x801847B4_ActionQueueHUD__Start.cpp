// 0x801847B4 ActionQueueHUD::Start (16b)
// FLAGS: -fno-schedule-insns
typedef unsigned int uint;
typedef unsigned char uchar;

struct HUDTarget;
struct ActionQueueHUD {
    char _pad[0x318];
    uchar m_active;
};

void ActionQueueHUD__Start(ActionQueueHUD *self, HUDTarget *target) {
    *(HUDTarget **)self = target;
    self->m_active = 1;
}
