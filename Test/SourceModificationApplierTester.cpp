#include "SourceModificationApplierTester.hpp"
#include <KTextEditor/Document>
#include "./gmock-1.6.0/fused-src/gmock/gmock.h"
#include "SourceReplacement.hpp"

#define QTEST_MAIN_WITH_GMOCK(TestObject) \
int main(int argc, char *argv[]) \
{ \
    ::testing::InitGoogleMock(&argc, argv); \
    QCoreApplication app(argc, argv); \
    TestObject tc; \
    return QTest::qExec(&tc, argc, argv); \
}

QTEST_MAIN_WITH_GMOCK(SourceModificationApplierTester)

using namespace testing;

void SourceModificationApplierTester::testApply()
{
    SourceReplacements replacements;
    replacements.push_back({{0,0}, {0,1}, std::string()});
    SourceLocation dupa(1,0);
    //doc.setText("");
    //applier.apply();
    QVERIFY(0== 0);
}

#include "SourceModificationApplierTester.moc"
