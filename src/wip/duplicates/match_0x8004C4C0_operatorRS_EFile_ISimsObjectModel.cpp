struct EStorable;
struct EFile;
struct ISimsObjectModel;

EFile& operator>>(EFile&, EStorable*&);

EFile& operator>>(EFile& file, ISimsObjectModel*& obj) {
    EStorable* storable;
    operator>>(file, storable);
    obj = (ISimsObjectModel*)storable;
    return file;
}
