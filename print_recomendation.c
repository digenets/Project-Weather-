#include "print_recomendation.h"
#include "wind_printing.h"
#include "precipitation_constants.h"

StringArray Introductory() {
    StringArray introductory = CreateStringArray(5);
    introductory.array[0] = "Вследствие этого, ";
    introductory.array[1] = "Поэтому, ";
    introductory.array[2] = "Вероятнее всего, ";
    introductory.array[3] = "Согласно прогнозу погоды, ";
    introductory.array[4] = "В общем, ";
    return introductory;
}

StringArray RecommendationPhrase() {
    StringArray recommendation_phrases = CreateStringArray(4);
    recommendation_phrases.array[0] = "хотим вам порекомендовать эти вещи:";
    recommendation_phrases.array[1] = "мы рекомендуем вам надеть это:";
    recommendation_phrases.array[2] = "можете надеть:";
    recommendation_phrases.array[3] = "предоставим вам эти вещи на выход:";
    return recommendation_phrases;
}

StringArray VeryCold() {
    StringArray phrases_very_cold = CreateStringArray(4);
    phrases_very_cold.array[0] = "подумайте, а стоит ли завтра выходить на улицу?";
    phrases_very_cold.array[1] = "советуем вам остаться дома";
    phrases_very_cold.array[2] = "мы крайне не рекомендуем выходить на улицу в такую погоду";
    phrases_very_cold.array[3] = "в такую погоду свои дома сидят";
    return phrases_very_cold;
}

StringArray VeryColdWinterHat() {
    StringArray winter_hat = CreateStringArray(3);
    winter_hat.array[0] = "на голову возьмите шапку с мехом";
    winter_hat.array[1] = "на голову наденьте шапку-ушанку";
    winter_hat.array[2] = "без теплой шапки вам делать нечего";
    return winter_hat;
}

StringArray VeryColdGloves() {
    StringArray winter_gloves = CreateStringArray(3);
    winter_gloves.array[0] = "вязанные перчатки";
    winter_gloves.array[1] = "варежки";
    winter_gloves.array[2] = "утепленные перчатки";
    return winter_gloves;
}

StringArray VeryColdBoots() {
    StringArray very_cold_boots = CreateStringArray(2);
    very_cold_boots.array[0] = "валенки";
    very_cold_boots.array[1] = "теплые ботинки";
    return very_cold_boots;
}

StringArray VeryColdClothes() {
    StringArray very_cold_clothes = CreateStringArray(2);
    very_cold_clothes.array[0] = "и пуховик";
    very_cold_clothes.array[1] = "зимнюю куртку";
    return very_cold_clothes;
}

StringArray CoolWinterHat() {
    StringArray cool_winter_hat = CreateStringArray(3);
    cool_winter_hat.array[0] = "накиньте капюшон и кепку";
    cool_winter_hat.array[1] = "используйте капюшон куртки и легкий шарф";
    cool_winter_hat.array[2] = "беретку";
    return cool_winter_hat;
}

StringArray CoolClothes() {
    StringArray cool_clothes = CreateStringArray(3);
    cool_clothes.array[0] = "куртку с джинсами";
    cool_clothes.array[1] = "жилетку";
    cool_clothes.array[2] = "кожаную куртку";
    return cool_clothes;
}

StringArray CoolBoots() {
    StringArray cool_boots = CreateStringArray(2);
    cool_boots.array[0] = "ботинки";
    cool_boots.array[1] = "кроссовки";
    return cool_boots;
}

StringArray CoolSpecial() {
    StringArray cool_special = CreateStringArray(3);
    cool_special.array[0] = "Вместо капюшона возьмите зонт или дождевик.";
    cool_special.array[1] = "И возьмите дождевик.";
    cool_special.array[2] = "Также возьмите зонт.";
    return cool_special;
}

StringArray CloudyWinterHat() {
    StringArray cloudy_winter_hat = CreateStringArray(3);
    cloudy_winter_hat.array[0] = "шапку";
    cloudy_winter_hat.array[1] = "теплый головной убор";
    cloudy_winter_hat.array[2] = "на голову возьмите беретку с шарфом";
    return cloudy_winter_hat;
}

StringArray CloudyClothes() {
    StringArray cloudy_clothes = CreateStringArray(2);
    cloudy_clothes.array[0] = "пальто";
    cloudy_clothes.array[1] = "теплую куртку";
    return cloudy_clothes;
}

StringArray CloudyBoots() {
    StringArray cloudy_boots = CreateStringArray(2);
    cloudy_boots.array[0] = "ботинки";
    cloudy_boots.array[1] = "осенне-весенние ботинки";
    return cloudy_boots;
}

StringArray CloudyGloves() {
    StringArray cloudy_gloves = CreateStringArray(2);
    cloudy_gloves.array[0] = "кожаные перчатки";
    cloudy_gloves.array[1] = "теплые перчатки";
    return cloudy_gloves;
}

StringArray WarmCap() {
    StringArray warm_cap = CreateStringArray(3);
    warm_cap.array[0] = "можете взять шарфик";
    warm_cap.array[1] = "кепку";
    warm_cap.array[2] = "повязку";
    return warm_cap;
}

StringArray WarmClothes() {
    StringArray warm_clothes = CreateStringArray(3);
    warm_clothes.array[0] = "футболку с джинсами";
    warm_clothes.array[1] = "и ветровку";
    warm_clothes.array[2] = "и шорты";
    return warm_clothes;
}

StringArray WarmBoots() {
    StringArray warm_boots = CreateStringArray(3);
    warm_boots.array[0] = "кеды";
    warm_boots.array[1] = "кроссовки";
    warm_boots.array[2] = "сандалии";
    return warm_boots;
}

void PrintRecommendation(WEATHER* weather, FILE* out) {
    StringArray introductory = Introductory();
    StringArray recommendation_phrase = RecommendationPhrase();
    StringArray very_cold = VeryCold();
    StringArray very_cold_winter_hat = VeryColdWinterHat();
    StringArray very_cold_gloves = VeryColdGloves();
    StringArray very_cold_boots = VeryColdBoots();
    StringArray very_cold_clothes = VeryColdClothes();
    StringArray cool_winter_hat = CoolWinterHat();
    StringArray cool_clothes = CoolClothes();
    StringArray cool_boots = CoolBoots();
    StringArray cool_special = CoolSpecial();
    StringArray cloudy_winter_hat = CloudyWinterHat();
    StringArray cloudy_clothes = CloudyClothes();
    StringArray cloudy_boots = CloudyBoots();
    StringArray cloudy_gloves = CloudyGloves();
    StringArray warm_cap = WarmCap();
    StringArray warm_clothes = WarmClothes();
    StringArray warm_boots = WarmBoots();

    int koef_t = 0;
    int koef_s = 0;
    int koef_g = 0;

    int average_temperature = (weather->day_temp.min_val + weather->day_temp.max_val) / 2;
    int average_speed = GetAverageSpeed(weather->wind.speed_min_val, weather->wind.speed_max_val);

    int index = rand() % introductory.size;
    fprintf(out, "%s", introductory.array[index]);

    if (average_temperature < -30)
        koef_t = 0;
    else if ((average_temperature >= -30) && (average_temperature < -15))
        koef_t = 2;
    else if ((average_temperature >= -15) && (average_temperature < 0))
        koef_t = 4;
    else if ((average_temperature >= 0) && (average_temperature < 15))
        koef_t = 6;
    else if ((average_temperature >= 15) && (average_temperature < 25))
        koef_t = 8;
    else if (average_temperature >= 25)
        koef_t = 10;

    if (average_speed >= 25)
        koef_s = 0;
    else if ((average_speed < 25) && (average_speed >= 20))
        koef_s = 1;
    else if ((average_speed < 20) && (average_speed >= 15))
        koef_s = 2;
    else if ((average_speed < 15) && (average_speed >= 10))
        koef_s = 3;
    else if ((average_speed < 10) && (average_speed >= 5))
        koef_s = 4;
    else if (average_speed < 5)
        koef_s = 5;

    koef_g = koef_s + koef_t;

    // если совсем плохая погода - советуем остаться дома
    if ((koef_t == 0) || (koef_s == 0) || (koef_g <= 4)) {
        int very_cold_index = rand() % very_cold.size;
        fprintf(out, "%s", very_cold.array[very_cold_index]);
    }// верхняя одежда и ботинки clothes - boots
    else {
        int recommend_index = rand() % recommendation_phrase.size;
        fprintf(out, "%s", recommendation_phrase.array[recommend_index]);
        fprintf(out, " ");

        //  оч холодно но жить можно
        if (koef_g == 5) {
            int very_cold_hat_index = rand() % very_cold_winter_hat.size;
            fprintf(out, "%s", very_cold_winter_hat.array[very_cold_hat_index]);
            fprintf(out, ", ");

            int very_cold_gloves_index = rand() % very_cold_gloves.size;
            fprintf(out, "%s", very_cold_gloves.array[very_cold_gloves_index]);
            fprintf(out, ", ");

            int very_cold_boots_index = rand() % very_cold_boots.size;
            fprintf(out, "%s", very_cold_boots.array[very_cold_boots_index]);
            fprintf(out, ", ");

            int very_cold_clothes_index = rand() % very_cold_clothes.size;
            fprintf(out, "%s", very_cold_clothes.array[very_cold_clothes_index]);
            fprintf(out, ". ");


        // просто холодно
        } else if (koef_g == 6 || koef_g == 7 || koef_g == 8) {
            int cloudy_winter_hat_index = rand() % cloudy_winter_hat.size;
            fprintf(out, "%s", cloudy_winter_hat.array[cloudy_winter_hat_index]);
            fprintf(out, ", ");

            int cloudy_gloves_index = rand() % cloudy_gloves.size;
            fprintf(out, "%s", cloudy_gloves.array[cloudy_gloves_index]);

            fprintf(out, ", ");

            int cloudy_boots_index = rand() % cloudy_boots.size;
            fprintf(out, "%s", cloudy_boots.array[cloudy_boots_index]);
            fprintf(out, ", ");

            int cloudy_clothes_index = rand() % cloudy_clothes.size;
            fprintf(out, "%s", cloudy_clothes.array[cloudy_clothes_index]);
            fprintf(out, ". ");

        } else if ((koef_g == 9) || (koef_g == 10) || (koef_g == 11)) {
            int cool_winter_hat_index = rand() % cool_winter_hat.size;
            fprintf(out, "%s", cool_winter_hat.array[cool_winter_hat_index]);
            fprintf(out, ", ");

            int cool_boots_index = rand() % cool_boots.size;
            fprintf(out, "%s", cool_boots.array[cool_boots_index]);
            fprintf(out, ", ");

            int cool_clothes_index = rand() % cool_clothes.size;
            fprintf(out, "%s", cool_clothes.array[cool_clothes_index]);
            fprintf(out, ". ");

        // тепло
        } else if (koef_g >= 12) {
            int warm_cap_index = rand() % warm_cap.size;
            fprintf(out, "%s", warm_cap.array[warm_cap_index]);
            fprintf(out, ", ");

            int warm_clothes_index = rand() % warm_clothes.size;
            fprintf(out, "%s", warm_clothes.array[warm_clothes_index]);
            fprintf(out, ", ");

            int warm_boots_index = rand() % warm_boots.size;
            fprintf(out, "%s", warm_boots.array[warm_boots_index]);
            fprintf(out, ". ");
        }

        // если будет дождь
        if (strcmp(weather->precipitation, RAIN) == 0) {
            int cool_special_index = rand() % cool_special.size;
            fprintf(out, "%s", cool_special.array[cool_special_index]);
        }
    }
}