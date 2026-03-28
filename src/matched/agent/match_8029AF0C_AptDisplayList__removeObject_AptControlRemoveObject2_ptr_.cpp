struct AptControlRemoveObject2 {
    int m_depth;
};

struct AptDisplayList {
    void removeAtDepth(int depth);
    void removeObject(AptControlRemoveObject2* ctrl);
};

void AptDisplayList::removeObject(AptControlRemoveObject2* ctrl) {
    removeAtDepth(ctrl->m_depth);
}
