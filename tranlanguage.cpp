#include "tranlanguage.h"
#include <QMap>
#include <iostream>
#include <QDebug>
const QMap<int,QString> index_language={
    { 1 , "ab" },{ 2 , "sq" },{ 3 , "ak" },{ 4 , "ar" },{ 5 , "an" },
    { 6 , "am" },{ 7 , "as" },{ 8 , "az" },{ 9 , "ast"},{ 10, "nch"},
    { 11, "ee" },{ 12, "ay" },{ 13, "ga" },{ 14, "et" },{ 15, "oj" },
    { 16, "oc" },{ 17, "or" },{ 18, "om" },{ 19, "os" },{ 20, "tpi"},
    { 21, "ba" },{ 22, "eu" },{ 23, "be" },{ 24, "ber"},{ 25, "bm" },
    { 26, "pag"},{ 27, "bg" },{ 28, "se" },{ 29, "bem"},{ 30, "byn"},
    { 31, "bi" },{ 32, "bal"},{ 33, "is" },{ 34, "pl" },{ 35, "bs" },
    { 36, "fa" },{ 37, "bho"},{ 38, "br" },{ 39, "ch" },{ 40, "cbk"},
    { 41, "cv" },{ 42, "ts" },{ 43, "tt" },{ 44, "da" },{ 45, "shn"},
    { 46, "tet"},{ 47, "de" },{ 48, "nds"},{ 49, "sco"},{ 50, "dv" },
    { 51, "kdx"},{ 52, "dtp"},{ 53, "ru" },{ 54, "fo" },{ 55, "fr" },
    { 56, "sa" },{ 57, "fil"},{ 58, "fj" },{ 59, "fi" },{ 60, "fur"},
    { 61, "fvr"},{ 62, "kg" },{ 63, "km" },{ 64, "ngu"},{ 65, "kl" },
    { 66, "ka" },{ 67, "gos"},{ 68, "gu" },{ 69, "gn" },{ 70, "kk" },
    { 71, "ht" },{ 72, "ko" },{ 73, "ha" },{ 74, "nl" },{ 75, "cnr"},
    { 76, "hup"},{ 77, "gil"},{ 78, "rn" },{ 79, "quc"},{ 80, "ky" },
    { 81, "gl" },{ 82, "ca" },{ 83, "cs" },{ 84, "kab"},{ 85, "kn" },
    { 86, "kr" },{ 87, "csb"},{ 88, "kha"},{ 89, "kw" },{ 90, "xh" },
    { 91, "co" },{ 92, "mus"},{ 93, "crh"},{ 94, "tlh"},{ 95, "hbs"},
    { 96, "qu" },{ 97, "ks" },{ 98, "ku" },{ 99, "la" },{100, "ltg"},
    {101, "lv" },{102, "lo" },{103, "lt" },{104, "li" },{105, "ln" },
    {106, "lg" },{107, "lb" },{108, "rue"},{109, "rw" },{110, "ro" },
    {111, "rm" },{112, "rom"},{113, "jbo"},{114, "mg" },{115, "gv" },
    {116, "mt" },{117, "mr" },{118, "ml" },{119, "ms" },{120, "chm"},
    {121, "mk" },{122, "mh" },{123, "kek"},{124, "mai"},{125, "mfe"},
    {126, "mi" },{127, "mn" },{128, "bn" },{129, "my" },{130, "hmn"},
    {131, "umb"},{132, "nv" },{133, "af" },{134, "ne" },{135, "niu"},
    {136, "no" },{137, "pmn"},{138, "pap"},{139, "pa" },{140, "pt" },
    {141, "ps" },{142, "ny" },{143, "tw" },{144, "chr"},{145, "ja" },
    {146, "sv" },{147, "sm" },{148, "sg" },{149, "si" },{150, "hsb"},
    {151, "eo" },{152, "sl" },{153, "sw" },{154, "so" },{155, "sk" },
    {156, "tl" },{157, "tg" },{158, "ty" },{159, "te" },{160, "ta" },
    {161, "th" },{162, "to" },{163, "toi"},{164, "ti" },{165, "tvl"},
    {166, "tyv"},{167, "tr" },{168, "tk" },{169, "wa" },{170, "war"},
    {171, "cy" },{172,  ""  },{173, "ve" },{174, "vo" },{175, "wo" },
    {176, "udm"},{177, "ur" },{178, "uz" },{179, "es" },{180, "ie" },
    {181, "fy" },{182, "szl"},{183, "he" },{184, "hil"},{185, "haw"},
    {186, "el" },{187, "lfn"},{188, "sd" },{189, "hu" },{190, "sn" },
    {191, "ceb"},{192, "syr"},{193, "su" },{194, "hy" },{195, "ace"},
    {196, "iba"},{197, "ig" },{198, "io" },{199, "ilo"},{200, "iu" },
    {201, "it" },{202, "yi" },{203, "ia" },{204, "hi" },{205, "id" },
    {206, "inh"},{207, "en" },{208, "yo" },{209, "vi" },{210, "zza"},
    {211, "jv" },{212, "zh" },{213,"zh-tw"},{214,"yue"},{215, "zu" }
};
tranlanguage::tranlanguage()
{

}

//通过索引查找语言代码
QString tranlanguage::catchlanguage(int index){
    return index_language.value(index+1);
}

//通过语言代码查找索引
int tranlanguage::catchindex(QString language){
    return index_language.key(language)-1;
}

