#include "widgets/inputareawidget.h"

InputAreaWidget::InputAreaWidget(QWidget* parent) : QScrollArea(parent) {
    contents = new QWidget(this);
    gridLayout = new QGridLayout(contents);
}

InputAreaWidget::~InputAreaWidget() {
    for (auto& i : inputWidgets)
        for (const auto& j : i)
            delete j;
    delete gridLayout;
}

void InputAreaWidget::init(int row, int column) {
    inputWidgets.resize(row);
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < column; ++j) {
            inputWidgets[i].push_back(new InputWidget(contents));
            gridLayout->addWidget(inputWidgets[i][j], i, j);
        }
    contents->setLayout(gridLayout);
    setWidget(contents);
}

void InputAreaWidget::setLabel(int x, int y, const QString& str) {
    inputWidgets[x][y]->setLabel(str);
}

void InputAreaWidget::setLabelValidator(int x, int y, const QRegularExpression& re) {
    inputWidgets[x][y]->setValidator(new QRegularExpressionValidator(re, inputWidgets[x][y]));
}

QString InputAreaWidget::getResult(int x, int y) {
    return inputWidgets[x][y]->getResult();
}
