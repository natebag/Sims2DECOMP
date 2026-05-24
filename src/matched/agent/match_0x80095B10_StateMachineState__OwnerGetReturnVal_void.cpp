// FLAGS: -fno-schedule-insns
// 0x80095B10 StateMachineState::OwnerGetReturnVal(void) (12B)
// lwz r9,0x8(r3); lwz r3,0x90(r9); blr
struct Owner { char pad[0x90]; int m_returnVal; };
struct StateMachineState { char pad[8]; Owner* m_owner; int OwnerGetReturnVal() const; };
int StateMachineState::OwnerGetReturnVal() const { return m_owner->m_returnVal; }
