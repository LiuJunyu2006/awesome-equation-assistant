#include "widgets/inputareawidget.h"

InputAreaWidget::InputAreaWidget(QWidget* parent) : QScrollArea(parent) {
    gridLayout = new QGridLayout(this);
    setLayout(gridLayout);
}

InputAreaWidget::~InputAreaWidget() {
    for (auto& i : inputWidgets)
        for (auto& j : i)
            delete j;
    delete gridLayout;
}

void InputAreaWidget::init(int row, int column) {
    inputWidgets.resize(row);
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < column; ++j) {
            inputWidgets[i].push_back(new InputWidget(this));
            gridLayout->addWidget(inputWidgets[i][j], i, j);
        }
}
