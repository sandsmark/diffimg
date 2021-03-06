
/******************************************************************************
   DiffImg: image difference viewer
   Copyright(C) 2011-2014  xbee@xbee.net

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2
   of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *******************************************************************************/

#include <QtCore/QDebug>

#include "MetricsManager.h"
#include "BaseMetric.h"

QList<BaseMetric *> MetricsManager::m_metrics;

MetricsManager::MetricsManager(QObject *parent) : QObject(parent)
{
}

MetricsManager::~MetricsManager()
{
    clear();
}

void MetricsManager::clear()
{
    qDeleteAll(m_metrics);
    m_metrics.clear();
}

void MetricsManager::registerMetrics(BaseMetric *metric)
{
    m_metrics << metric;
}

const QList<BaseMetric *> &MetricsManager::getMetrics()
{
    return m_metrics;
}

BaseMetric *MetricsManager::getMetricByType(const QString &type)
{
    foreach (BaseMetric *met, m_metrics) {
        if (met->getType() == type) {
            return met;
        }
    }

    return nullptr;
}
