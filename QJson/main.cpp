#include <QCoreApplication>

#include <QJsonParseError>
#include <QJsonDocument>
#include <QVariantMap>
#include <QFile>
#include <QDebug>


//(细看)参考：https://www.devbean.net/2013/09/qt-study-road-2-qjsondocument/

/*
QJsonArray      封装 JSON 数组
QJsonDocument 	读写 JSON 文档
QJsonObject 	封装 JSON 对象
QJsonObject::iterator 	用于遍历QJsonObject的 STL 风格的非 const 遍历器
QJsonParseError         报告 JSON 处理过程中出现的错误
QJsonValue      封装 JSON 值
*/


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /** 生成Json文档 **/

    // 分对象
    QVariantMap alice;
    alice.insert("Name", "Alice");
    alice.insert("Phonenumber", 321);

    // 分数组
    QVariantList age_Array;
    age_Array.append(19);
    age_Array.append(20);
    age_Array.append(21);

    // 总对象
    QVariantMap bob;
    bob.insert("Name", "Bob");
    bob.insert("Phonenumber", 123);
    bob.insert("OtherPeople",alice);
    bob.insert("age", age_Array);

    // 注意：QJsonDocument::fromVariant(param)  param：可以是QVariantMap（最外面是{}），可以是QVariantList（最外面是[]）
    QJsonDocument jsonDocument_generate = QJsonDocument::fromVariant(bob);
    if (!jsonDocument_generate.isNull()) {
        qDebug() << jsonDocument_generate.toJson();
    }

    /** 将Json写入配置文件 **/
    QString ConfigFileName = "/root/Configuration.txt";
    QFile   file(ConfigFileName);
    file.resize(0);

    if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        qDebug() << "can't open the file!";
    }
    else
    {
        QTextStream in(&file);

        // 将QJsonDocument（Json文档）使用toJson()转为Json格式
        in << jsonDocument_generate.toJson() << endl;
    }
    file.close();


    /**********************************************************************************************/


//    QString json("{"
//            "\"encoding\" : \"UTF-8\","
//            "\"plug-ins\" : ["
//            "\"python\","
//            "\"c++\","
//            "\"ruby\""
//            "],"
//            "\"indent\" : { \"length\" : 3, \"use_space\" : true }"
//            "}");
//    /**  解析Json文档  **/
//    QJsonParseError error;

//    // QJsonDocument 	读写 JSON 文档
//    QJsonDocument jsonDocument = QJsonDocument::fromJson(json.toUtf8(), &error);
//    if (error.error == QJsonParseError::NoError)
//    {
//        if (!(jsonDocument.isNull() || jsonDocument.isEmpty()))
//        {
//            if (jsonDocument.isObject())
//            {
//                /** 程序中定义 Json格式 的字符串**/
//                // json对象 (tomap) 转换为 QVariantMap
//                QVariantMap result = jsonDocument.toVariant().toMap();
//                qDebug() << "encoding:" << result["encoding"].toString();
//                qDebug() << "plugins:";

//                // json数组         转换为 QVariant
//                foreach (QVariant plugin, result["plug-ins"].toList()) {
//                    qDebug() << "\t-" << plugin.toString();
//                }

//                // json对象 (tomap) 转换为 QVariantMap
//                QVariantMap nestedMap = result["indent"].toMap();
//                qDebug() << "length:" << nestedMap["length"].toInt();
//                qDebug() << "use_space:" << nestedMap["use_space"].toBool();
//            }
//        }
//        else if (jsonDocument.isArray())
//        {
//                    // ...
//        }
//    }
//    else
//    {
//        qFatal(error.errorString().toUtf8().constData());
//        exit(1);
//    }


    QString json_str = "";

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "can't open the file!";
    }
    else
    {
        QTextStream stream(&file);
        json_str = stream.readAll();
    }


    //QString -> QByteArray
    QByteArray byte_JsonDocument = json_str.toLatin1();

    /**  解析Json文档  **/

    QJsonParseError json_error;         // 获取解析的结果
    QJsonParseError error;

    // QJsonDocument 	读写 JSON 文档
    QJsonDocument jsonDocument = QJsonDocument::fromJson(byte_JsonDocument, &error);
    if (error.error == QJsonParseError::NoError)
    {
        if (!(jsonDocument_generate.isNull() || jsonDocument_generate.isEmpty()))
        {
            if (jsonDocument_generate.isObject())
            {
                /** 程序中定义 Json格式 的字符串**/
                // value(字符串或者数字)
                QVariantMap result = jsonDocument_generate.toVariant().toMap();
                qDebug() << "Name:" << result["Name"].toString();
                qDebug() << "Phonenumber:" << result["Phonenumber"].toString();

                // value(数组)
                foreach (QVariant plugin, result["age"].toList()) {
                    qDebug() << "age:" << plugin.toInt();
                }

                // value(对象)
                QVariantMap nestedMap = result["OtherPeople"].toMap();
                qDebug() << "Name:" << nestedMap["Name"].toString();
                qDebug() << "Phonenumber:" << nestedMap["Phonenumber"].toString();
            }
        }
        else if (jsonDocument.isArray())
        {
                    // ...
        }
    }
    else
    {
        qFatal(error.errorString().toUtf8().constData());
        exit(1);
    }

    file.close();

    return a.exec();
}
