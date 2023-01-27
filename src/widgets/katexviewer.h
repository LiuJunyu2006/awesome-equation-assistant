#ifndef WIDGETS_KATEXVIEWER_H
#define WIDGETS_KATEXVIEWER_H

#include <QtCore/QString>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QWidget>

class KatexViewer : public QWidget {
    Q_OBJECT

  public:
    KatexViewer(QWidget* parent = nullptr);

    ~KatexViewer() override;

  public slots:
    void clearContent();

    void addContent(const QString& str);

  private slots:
    void flush() const;

  private:
    QWebEngineView* view;
    QFormLayout* layout;
    QString content;
};

#endif  // WIDGETS_KATEXVIEWER_H