#include "widgets/quarticequationcalculatorwidget.h"

QuarticEquationCalculatorWidget::QuarticEquationCalculatorWidget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::QuarticEquationCalculatorWidgetClass())
{
	ui->setupUi(this);
}

QuarticEquationCalculatorWidget::~QuarticEquationCalculatorWidget()
{
	delete ui;
}
