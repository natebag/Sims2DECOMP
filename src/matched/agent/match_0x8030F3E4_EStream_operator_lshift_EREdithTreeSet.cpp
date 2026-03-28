struct EStream;
struct EREdithTreeSet;

EStream& EStream_Write_EREdithTreeSet(EStream&, EREdithTreeSet*);

EStream& operator<<(EStream& s, EREdithTreeSet* p) {
    return EStream_Write_EREdithTreeSet(s, p);
}
