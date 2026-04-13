// 0x80152F5C XRoute::HasCurrentGoal (24B)
struct XRoute { char pad[0x54]; int m_goalId; };
int XRoute_HasCurrentGoal(XRoute* self) {
    int r = 1;
    if (self->m_goalId == -1) r = 0;
    return r;
}
