/**
  \file     LH_QtNetwork.h
  @author   Johan Lindh <johan@linkdata.se>
  Copyright (c) 2009-2011, Johan Lindh

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

#ifndef LH_QTNETWORK_H
#define LH_QTNETWORK_H

#include <QQueue>
#include "lh_plugin.h"
#include "LH_QtInstance.h"
#include "LH_Qt_QSlider.h"

class LH_API5PLUGIN_EXPORT LH_QtNetwork
{
    LH_QtObject *parent_;
    QQueue<lh_netdata*> data_;

protected:
    LH_Qt_QSlider *setup_smoothing_;

public:
    explicit LH_QtNetwork( LH_QtObject *parent );
    ~LH_QtNetwork();

    int notify(int n, void *p);

    const lh_systemstate *state() const { return parent_->state(); }

    int samples() const { return setup_smoothing_->value() + 1; }
    qint64 inTotal() const;
    qint64 outTotal() const;
    qint64 inRate() const;
    qint64 outRate() const;
    int inPermille() const;
    int outPermille() const;
    int tpPermille() const;

    void smoothingOrder(int n) { setup_smoothing_->setOrder(n); }
    void smoothingHidden(bool hide) { setup_smoothing_->setFlag(LH_FLAG_HIDDEN, hide); }
};

#endif // LH_QTNETWORK_H
