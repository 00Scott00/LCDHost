/*
  Copyright (c) 2009-2016 Johan Lindh <johan@linkdata.se>

  This file is part of LCDHost.

  LCDHost is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  LCDHost is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with LCDHost.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef APPSETUPPROGRESSBAR_H
#define APPSETUPPROGRESSBAR_H

#include <QProgressBar>

class AppSetupProgressBar : public QProgressBar
{
    Q_OBJECT
public:
    explicit AppSetupProgressBar(QWidget *parent = 0) : QProgressBar(parent) {}

signals:

public slots:
    void setMinMaxVal( int min, int max, int val )
    {
        blockSignals(true);
        setMinimum(min);
        setMaximum(max);
        blockSignals(false);
        if( val < min ) val = min;
        if( val > max ) val = max;
        setValue(val);
    }

};

#endif // APPSETUPPROGRESSBAR_H
