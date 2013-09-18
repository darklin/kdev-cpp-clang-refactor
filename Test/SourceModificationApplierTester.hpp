#ifndef SOURCEMODIFICATIONAPPLIERTESTER_HPP
#define SOURCEMODIFICATIONAPPLIERTESTER_HPP

#include <QtTest/QTest>
#include "../sourcemodificationsapplier.hpp"

class SourceModificationApplierTester: public QObject
{
    Q_OBJECT
public:
    SourceModificationApplierTester() :
        applier()
        {}
    virtual ~SourceModificationApplierTester() {}

private slots:
    void testApply();
private:
    SourceModificationsApplier applier;
};

#endif // SOURCEMODIFICATIONAPPLIERTESTER_HPP