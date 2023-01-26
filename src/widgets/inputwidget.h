#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H

#include <QtCore/QString>
#include <QtGui/QValidator>
#include <QtWidgets/QWidget>

namespace Ui {
class InputWidget;
}

class InputWidget : public QWidget {
    Q_OBJECT

  public:
    explicit InputWidget(QWidget* parent = nullptr);
    ~InputWidget();

    void setLabel(const QString& str) const;

    void setValidator(QValidator* vali);

    QString getResult() const;

  private:
    Ui::InputWidget* ui;
};

#endif  // INPUTWIDGET_H
