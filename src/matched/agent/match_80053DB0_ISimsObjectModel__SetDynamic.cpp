struct ISimsObjectModel { char pad[812]; int m_flags; void SetDynamic(int val); };
void ISimsObjectModel::SetDynamic(int val) {
    if (val) { m_flags |= 64; }
    else { m_flags &= ~64; }
}
