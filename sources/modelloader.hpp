#pragma once

#include <QtCore/QObject>
#include <QFileDialog>
#include <QShortcut>

class SceneModifier;

class ModelLoader : public QWidget {
    Q_OBJECT

public:
    explicit ModelLoader(QWidget* parent = nullptr);
    ~ModelLoader() = default;

    QString getPathToModel() const;

    void setSceneModifier(SceneModifier* sceneModifier);

public slots:
    void hotkeyClicked();

signals:
    void modelPathChanged();

private:
    void connectSignals();

    Q_DISABLE_COPY(ModelLoader)

    QString m_pathToModel;
    QShortcut* m_keyCtlD;
    SceneModifier* m_pSceneModifier;
};
