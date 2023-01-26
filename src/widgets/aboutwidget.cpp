#include "widgets/aboutwidget.h"

AboutWidget::AboutWidget(QWidget* parent) : QDialog(parent), ui(new Ui::AboutWidgetClass()) {
    ui->setupUi(this);
}

AboutWidget::~AboutWidget() {
    delete ui;
}
