// MUStateMachine::Draw(ERC *)
// Address: 0x800937B8 | Size: 48 bytes
// FLAGS: -fno-elide-constructors

struct ERC;
struct MUStateMachine;

extern MUStateMachine* g_muStateMachine;  // SDA global

extern void MUStateMachine_Draw_impl(MUStateMachine* sm, ERC* erc);

void MUStateMachine_Draw(ERC* erc) {
    if (g_muStateMachine != 0) {
        MUStateMachine_Draw_impl(g_muStateMachine, erc);
    }
}
