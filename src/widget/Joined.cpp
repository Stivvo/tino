#include "Joined.hpp"

widget::Joined::Joined(core::Group *value, QWidget *parent) : QWidget(parent)
{
    this->val = value;
    l         = new QBoxLayout(QBoxLayout::LeftToRight, this);
    int dim   = static_cast<int>(val->getDim());

    box = new QSpinBox(this);
    box->setMinimum(0);
    box->setMaximum(dim * 255);

    connect(box, &QSpinBox::editingFinished, this,
            [this]() { (*val)[0].setInt(box->value()); });

    l->addWidget(box, 0, Qt::AlignVCenter);

    long v = 0;
    for (int i = 0; i < dim; ++i) {
        lbl.emplace_back(new QLabel(QString::fromStdString((*val)[i].getName()),
                                    this, Qt::Widget));
        l->addWidget(lbl[i], 0, Qt::AlignVCenter);
        v += (*val)[i].getInt();
    }
    box->setValue(static_cast<int>(v));
}
