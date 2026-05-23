struct EREdithTreeSet {
    void* CreateCopy() const;
};

void* EStorable_CreateCopyImpl(const void*);

void* EREdithTreeSet::CreateCopy() const {
    return EStorable_CreateCopyImpl(this);
}
