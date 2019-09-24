#ifndef PLOTLINES_H
#define PLOTLINES_H

#include <QWidget>
#include"widget.h"
#include <qwt_plot_layout.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_renderer.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_histogram.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_zoomer.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_magnifier.h>

#include <qwt_legend.h>
#include <qwt_legend_label.h>
#include <qwt_column_symbol.h>
#include <qwt_series_data.h>
#include <qpen.h>
#include <qwt_symbol.h>
#include <qwt_picker_machine.h>

class PlotLines : public QwtPlot
{
    Q_OBJECT
public:
    explicit PlotLines(QWidget *parent = 0);

signals:

public slots:
    void showItem(const QVariant &itemToInfo,bool on);
};

#endif // PLOTLINES_H
