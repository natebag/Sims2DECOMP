// 0x80098D58 (92B) Physics::PhysicsGravitate(EVec3&)
// EVec3& param is unused; Physics inherits StateMachineState with m_owner at offset 8.
struct EVec3 { float x, y, z; };

struct TheSimsStateMachine {
    int IsFlowStateRequestPending();
    int GetFlowStateRequest();
    void SetFlowStateCurrent();
};

struct StateMachineState {
    char pad[0x08];
    TheSimsStateMachine* m_owner;
    void OwnerReturnFromState(int code);
};

struct Physics : StateMachineState {
    void PhysicsGravitate(EVec3& v);
};

void Physics::PhysicsGravitate(EVec3& v) {
    if (!m_owner->IsFlowStateRequestPending())
        return;
    if (m_owner->GetFlowStateRequest() != 1)
        return;
    m_owner->SetFlowStateCurrent();
    OwnerReturnFromState(1);
}
