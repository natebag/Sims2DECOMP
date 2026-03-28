struct TypeInfoData { int name; int key; unsigned short version; unsigned short readVer; };
TypeInfoData s_EREdithTreeSet_tid = { 1, 2, 3, 4 };
class EREdithTreeSet { public: unsigned short GetReadVersion(); };
unsigned short EREdithTreeSet::GetReadVersion() { return s_EREdithTreeSet_tid.readVer; }
