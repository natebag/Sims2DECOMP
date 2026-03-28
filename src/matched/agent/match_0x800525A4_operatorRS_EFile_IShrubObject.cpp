struct EStorable;
struct EFile;
struct IShrubObject;

EFile& operator>>(EFile&, EStorable*&);

EFile& operator>>(EFile& file, IShrubObject*& obj) {
    EStorable* storable;
    operator>>(file, storable);
    obj = (IShrubObject*)storable;
    return file;
}
