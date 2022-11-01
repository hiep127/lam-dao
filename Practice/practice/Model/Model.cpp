#include "Model.h"

Model::Model(QString name, int assembly, int cpp, int javaScript, int QML, int openGL)
{
    m_sName = name;
    m_iAssembly = assembly;
    m_iCpp = cpp;
    m_iJavaScript = javaScript;
    m_iQML = QML;
    m_iOpenGL = openGL;
}

QString Model::getName() const
{
    return m_sName;
}

int Model::getAssembly() const
{
    return m_iAssembly;
}

int Model::getCpp() const
{
    return m_iCpp;
}

int Model::getJavaScript() const
{
    return m_iJavaScript;
}

int Model::getQML() const
{
    return m_iQML;
}

int Model::getOpenGL() const
{
    return m_iOpenGL;
}

void Model::setAssembly(int assembly)
{
    if(m_iAssembly == assembly)
        return;
    m_iAssembly = assembly;
}

void Model::setCpp(int cpp)
{
    if(m_iCpp == cpp)
        return;
    m_iCpp = cpp;
}

void Model::setJavaScript(int javaScript)
{
    if(m_iJavaScript == javaScript)
        return;
    m_iJavaScript = javaScript;
}

void Model::setQML(int qml)
{
    if(m_iQML == qml)
        return;
    m_iQML = qml;
}

void Model::setOpenGL(int openGL)
{
    if(m_iOpenGL == openGL)
        return;
    m_iOpenGL = openGL;
}

