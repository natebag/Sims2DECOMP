struct EREdithTreeSet {
    static void Destruct(EREdithTreeSet*);
    void DestructImpl(int);
};

void EREdithTreeSet_DestructImpl(EREdithTreeSet*, int);

void EREdithTreeSet::Destruct(EREdithTreeSet* p) {
    EREdithTreeSet_DestructImpl(p, 2);
}
