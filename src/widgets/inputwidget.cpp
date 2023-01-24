#include "widgets/inputwidget.h"
#include "ui_inputwidget.h"

InputWidget::InputWidget(QWidget* parent) : QWidget(parent), ui(new Ui::InputWidget) {
    ui->setupUi(this);
}

InputWidget::~InputWidget() {
    delete ui;
}

void InputWidget::setLabel(const QString& str) const {
    ui->label->setText(str);
}

QString InputWidget::getResult() const {
    return ui->lineEdit->text();
}
