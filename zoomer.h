#ifndef ZOOMER_H
#define ZOOMER_H
#include<qwt_plot_zoomer.h>

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
#include <qwt_magnifier.h>

class Zoomer :public QwtPlotZoomer
{
    Q_OBJECT
public:
    QString m_vCurveType;
    Zoomer();
    Zoomer(QString curveType,QWidget *canvas, bool doReplot = true) :QwtPlotZoomer(canvas, doReplot)
    {
        m_vCurveType = curveType;
    }
protected:
    virtual bool accept(QPolygon & 	pa)	const
    {
        const QwtPlot *plot = QwtPlotPicker::plot();
        if ((m_vCurveType == "0" || m_vCurveType=="1")&&(plot->axisScaleDiv(QwtPlot::xBottom).interval().maxValue() - plot->axisScaleDiv(QwtPlot::xBottom).interval().minValue() < 5))
            return false;
        else if (m_vCurveType == "2" && (plot->axisScaleDiv(QwtPlot::yLeft).interval().maxValue() - plot->axisScaleDiv(QwtPlot::yLeft).interval().minValue() < 15))
            return false;
        return QwtPlotZoomer::accept(pa);
    }
};
#endif // ZOOMER_H
