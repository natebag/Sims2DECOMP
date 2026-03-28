struct TypeInfoData { int name; int key; unsigned short version; unsigned short readVer; };
TypeInfoData s_EREdithTreeSet_tid = { 1, 2, 3, 4 };
class EREdithTreeSet { public: int GetTypeName() const; };
int EREdithTreeSet::GetTypeName() const { return s_EREdithTreeSet_tid.name; }
