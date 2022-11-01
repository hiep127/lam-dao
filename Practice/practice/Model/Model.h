#ifndef MODEL_H
#define MODEL_H
#include <QString>

class Model
{
public:
    Model(QString name, int assembly, int cpp, int javaScript, int QML, int openGL);

    QString getName() const;
    int getAssembly() const;
    int getCpp() const;
    int getJavaScript() const;
    int getQML() const;
    int getOpenGL() const;

    void setAssembly(int assembly);
    void setCpp(int cpp);
    void setJavaScript(int javaScript);
    void setQML(int qml);
    void setOpenGL(int openGL);

private:
    QString m_sName;
    int m_iAssembly;
    int m_iCpp;
    int m_iJavaScript;
    int m_iQML;
    int m_iOpenGL;
};

#endif // MODEL_H
