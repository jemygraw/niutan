#include "QNPutPolicyTest.h"
#include "QNPutPolicy.h"
#include "QNPutRet.h"
#include "QNUtils.h"
#include <QString>
#include <iostream>

void QNPutPolicyTest::putPolicyTest1()
{
    QString scope=QString("jemydemob");
    QString saveKey=QString("hello.jpeg");
    QNPutPolicy policy=QNPutPolicy(scope);
    policy.setDeadline(QNUtils::expireInSeconds(3600));
    policy.setSaveKey(&saveKey);
    QString json= policy.toJSON();
    std::cout<<json.toStdString()<<std::endl;
}

void QNPutPolicyTest::putRetTest1()
{
    QByteArray jsonData=QByteArray("{\"hash\":\"Hash data\",\"key\":\"Key data\"}");
    std::cout<<QString(jsonData).toStdString()<<std::endl;
    QNPutRet putRet;
    QNPutRet::fromJSON(jsonData, &putRet);
    std::cout<<putRet.getHash()->toStdString()<<std::endl;
    std::cout<<putRet.getKey()->toStdString()<<std::endl;
}