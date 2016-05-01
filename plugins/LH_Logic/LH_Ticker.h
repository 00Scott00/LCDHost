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

#ifndef LH_TICKER_H
#define LH_TICKER_H

#include <LH_QtCFInstance.h>
#include <QTimer>

class LH_Ticker : public LH_QtCFInstance
{
    Q_OBJECT

protected:
    LH_Qt_int *setup_ticks_;
    LH_Qt_int *setup_rate_;
    LH_Qt_int *setup_increment_;

public:
    LH_Ticker();

    const char *userInit();

    static lh_class *classInfo();
    QImage *render_qimage( int w, int h );

    virtual int polling();

public slots:
    void changePolling();
};

#endif // LH_TICKER_H
