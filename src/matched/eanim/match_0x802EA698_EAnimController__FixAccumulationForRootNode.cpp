// 0x802EA698 (68B) EAnimController::FixAccumulationForRootNode(EACTrack*, EACNodeState&)

class EACTrack {
public:
    int m_0;
    int m_4;
    unsigned int m_8_mask;
    char m_pad[128 - 12];
    float m_80_inputs[3];
};

class EACNodeState {
public:
    char m_pad[20];
    float m_14_outputs[3];
};

class EAnimController {
public:
    static void FixAccumulationForRootNode(EACTrack* track, EACNodeState& state);
};

void EAnimController::FixAccumulationForRootNode(EACTrack* track, EACNodeState& state) {
    int i = 0;
    unsigned int one = 1;
    for (; i < 3; i++) {
        unsigned int bit = one << i;
        if (track->m_8_mask & bit) {
            state.m_14_outputs[i] = track->m_80_inputs[i];
        }
    }
}
