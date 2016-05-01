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

#include <LH_Image/LH_QImage.h>
#include <LH_Qt_QStringList.h>

class LH_TS3SpeakingImage : public LH_QImage
{
protected:
    LH_Qt_QString *setup_talking_;

    bool loadPlaceholderImage(QImage *img)
    {
        return img->load(QString(":/images/%1.png")
                    .arg(setup_talking_->value()==""?"empty":"talking")
                    );
    }

public:
    const char *userInit()
    {
        if( const char *err = LH_QImage::userInit() ) return err;

        //setup_show_placeholder_->setTitle("Use default images");

        setup_talking_ = new LH_Qt_QString(this, "Talking", "", LH_FLAG_HIDDEN | LH_FLAG_READONLY | LH_FLAG_NOSAVE_DATA | LH_FLAG_NOSAVE_LINK | LH_FLAG_NOSOURCE | LH_FLAG_AUTORENDER);
        setup_talking_->setSubscribePath("/3rdParty/TeamSpeak 3/Speaking");
        //setup_talking_->refreshData();

        add_cf_target(setup_image_file_);
        add_cf_source(setup_talking_);

        return 0;
    }

    static lh_class *classInfo()
    {
        static lh_class classInfo =
        {
            sizeof(lh_class),
            "3rdParty/TeamSpeak 3",
            "TS3SpeakingStatusImage",
            "TS3 Speaking Status (Image)",
            16,16,
            lh_object_calltable_NULL,
            lh_instance_calltable_NULL
        };
        return &classInfo;
    }

};

LH_PLUGIN_CLASS(LH_TS3SpeakingImage)
