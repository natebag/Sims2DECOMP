/* XRoute::GetNthGoal(int) - 0x80152F88 - 16 bytes */
/* lwz r3, 0(r3); rlwinm r4, r4, 4, 0, 27; add r3, r3, r4; blr */
/* Returns this->m_data + index*16 */

struct GoalData {
    int data[4];
};

class XRoute {
public:
    GoalData* m_goals;

    GoalData* GetNthGoal(int index);
};

GoalData* XRoute::GetNthGoal(int index) {
    return &m_goals[index];
}
