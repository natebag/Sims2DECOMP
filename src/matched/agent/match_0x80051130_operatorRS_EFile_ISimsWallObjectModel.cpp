struct EStorable;
struct EFile;
struct ISimsWallObjectModel;

EFile& operator>>(EFile&, EStorable*&);

EFile& operator>>(EFile& file, ISimsWallObjectModel*& obj) {
    EStorable* storable;
    operator>>(file, storable);
    obj = (ISimsWallObjectModel*)storable;
    return file;
}
