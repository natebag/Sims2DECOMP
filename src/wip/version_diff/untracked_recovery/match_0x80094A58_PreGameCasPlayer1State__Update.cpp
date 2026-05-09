// FLAGS: -fno-elide-constructors
class CreateASimBaseState {
public:
    void Update(float dt);
};

class StateMachineState {
public:
    void OwnerReturnFromState(int val);
};

class PreGameCasPlayer1State {
public:
    char pad[32];
    int m_20;
    int m_24;
    int m_28;
    int m_2C;
    
    void Update(float dt);
};

void PreGameCasPlayer1State::Update(float dt) {
    ((CreateASimBaseState*)this)->Update(dt);
    int flag = 0;
    if (m_20 == 0) {
        if (m_28 != 0) {
            flag = 1;
        }
    }
    if (flag) {
        ((StateMachineState*)this)->OwnerReturnFromState(2);
        return;
    }
    flag = 0;
    if (m_20 == 0) {
        if (m_2C != 0) {
            flag = 1;
        }
    }
    if (flag) {
        ((StateMachineState*)this)->OwnerReturnFromState(1);
    }
}
