/* test vtable layout */

struct TestA {
    virtual ~TestA();
    static void SafeDelete(TestA *p);
};

void TestA::SafeDelete(TestA *p)
{
    if (p) {
        delete p;
    }
}

struct TestB {
    virtual void f0();
    virtual ~TestB();
    static void SafeDelete(TestB *p);
};

void TestB::SafeDelete(TestB *p)
{
    if (p) {
        delete p;
    }
}

struct TestC {
    virtual void f0();
    virtual void f1();
    virtual ~TestC();
    static void SafeDelete(TestC *p);
};

void TestC::SafeDelete(TestC *p)
{
    if (p) {
        delete p;
    }
}
