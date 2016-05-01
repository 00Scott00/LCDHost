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

#ifndef APPSETUPOPENFILE_H
#define APPSETUPOPENFILE_H

#include <QWidget>
#include <QLineEdit>
#include <QToolButton>

class AppSetupOpenFile : public QWidget
{
    Q_OBJECT

public:
    AppSetupOpenFile( QWidget *parent = 0 );

public slots:
    void setEnabled(bool);
    void setText(QString);
    void openFile();

signals:
    void textEdited(QString);

private:
    QLineEdit *le_;
    QToolButton *tb_;
};

#endif // APPSETUPOPENFILE_H
