#pragma once

#include "base.h"

#define NO_PRECIPITATION "-"
#define SNOW "снег"
#define RAIN "дождь"
#define SNOW_WITH_RAIN "снег с дождём"
#define HAIL "град"

StringArray CommentsNoPrecipitation();
StringArray CommentsNoPrecipitationAgain();

StringArray CommentsRain();
StringArray CommentsRainAgain();

StringArray CommentsSnow();
StringArray CommentsSnowAgain();

StringArray CommentsSnowWithRain();
StringArray CommentsSnowWithRainAgain();

StringArray CommentsHail();
StringArray CommentsHailAgain();

