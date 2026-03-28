struct TypeInfoData { int name; int key; unsigned short version; unsigned short readVer; };
TypeInfoData s_EREdithTreeSet_tid = { 1, 2, 3, 4 };
class EREdithTreeSet { public: int GetTypeKey() const; };
int EREdithTreeSet::GetTypeKey() const { return s_EREdithTreeSet_tid.key; }
