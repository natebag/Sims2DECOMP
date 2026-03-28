struct EREdithTreeSet {
    static void Construct(EREdithTreeSet*);
};

void EREdithTreeSet_ConstructImpl(EREdithTreeSet*);

void EREdithTreeSet::Construct(EREdithTreeSet* p) {
    EREdithTreeSet_ConstructImpl(p);
}
