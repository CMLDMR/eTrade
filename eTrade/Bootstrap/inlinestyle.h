#ifndef INLINESTYLE_H
#define INLINESTYLE_H


#include <iostream>
#include <string>





namespace Style {
    static const std::string style{"style"};
    static const std::string dataoid{"data-oid"};
    static const std::string userdata1{"userData1"};
    static const std::string userdata2{"userData2"};
    static const std::string customData{"customDatas"};
    namespace color {
        static const std::string rgb(const std::string &rgb){return std::string{"color:rgb("+rgb+");"};};
        static const std::string rgba(const std::string &rgba){return std::string{"color:rgba("+rgba+");"};};
        static const std::string color(const std::string &color){return std::string{"color:"+color+";"};};
        namespace Pink {
            static const std::string Pink {"Pink ;"};
            static const std::string LightPink {"LightPink ;"};
            static const std::string HotPink {"HotPink ;"};
            static const std::string DeepPink {"DeepPink ;"};
            static const std::string PaleVioletRed {"PaleVioletRed ;"};
            static const std::string MediumVioletRed {"MediumVioletRed ;"};
        }
        namespace Purple {
            static const std::string LightSkyBlue {"lightskyblue ;"};
            static const std::string Lavender {"Lavender ;"};
            static const std::string Thistle  {"Thistle ;"};
            static const std::string Plum  {"Plum ;"};
            static const std::string Orchid  {"Orchid ;"};
            static const std::string Violet  {"Violet ;"};
            static const std::string Fuchsia  {"Fuchsia ;"};
            static const std::string Magenta  {"Magenta ;"};
            static const std::string MediumOrchid  {"MediumOrchid ;"};
            static const std::string DarkOrchid  {"DarkOrchid ;"};
            static const std::string DarkViolet  {"DarkViolet ;"};
            static const std::string DodgerBlue  {"DodgerBlue ;"};
            static const std::string BlueViolet  {"BlueViolet ;"};
            static const std::string DarkMagenta   {"DarkMagenta ;"};
            static const std::string Purple   {"Purple ;"};
            static const std::string MediumPurple   {"MediumPurple ;"};
            static const std::string MediumSlateBlue   {"MediumSlateBlue ;"};
            static const std::string SlateBlue   {"SlateBlue ;"};
            static const std::string DarkSlateBlue   {"DarkSlateBlue ;"};
            static const std::string RebeccaPurple   {"RebeccaPurple ;"};
            static const std::string Indigo {"Indigo ;"};
            static const std::string MidnightBlue{"MidnightBlue;"};
            static const std::string RoyalBlue{"RoyalBlue;"};
        }
        namespace Red {
            static const std::string LightSalmon  {"LightSalmon ;"};
            static const std::string Salmon   {"Salmon ;"};
            static const std::string DarkSalmon   {"DarkSalmon ;"};
            static const std::string LightCoral   {"LightCoral ;"};
            static const std::string IndianRed    {"IndianRed ;"};
            static const std::string Crimson   {"Crimson ;"};
            static const std::string Red   {"Red ;"};
            static const std::string FireBrick   {"FireBrick ;"};
            static const std::string DarkRed   {"DarkRed ;"};
        }
        namespace Orange {
            static const std::string Orange  {"Orange ;"};
            static const std::string DarkOrange    {"DarkOrange ;"};
            static const std::string Coral    {"Coral ;"};
            static const std::string Tomato    {"Tomato ;"};
            static const std::string OrangeRed     {"OrangeRed ;"};
            static const std::string GoldenRod     {"GoldenRod ;"};
        }
        namespace Yellow {
            static const std::string Gold{"Gold;"};
            static const std::string Yellow{"Yellow;"};
            static const std::string LightYellow{"LightYellow;"};
            static const std::string LemonChiffon{"LemonChiffon;"};
            static const std::string LightGoldenRodYellow{"LightGoldenRodYellow;"};
            static const std::string PapayaWhip{"PapayaWhip;"};
            static const std::string Moccasin{"Moccasin;"};
            static const std::string PeachPuff{"PeachPuff;"};
            static const std::string PaleGoldenRod{"PaleGoldenRod;"};
            static const std::string Khaki{"Khaki;"};
            static const std::string DarkKhaki{"DarkKhaki;"};
        }
        namespace Green {
            static const std::string GreenYellow{"GreenYellow;"};
            static const std::string Chartreuse{"Chartreuse;"};
            static const std::string LawnGreen{"LawnGreen;"};
            static const std::string Lime{"Lime;"};
            static const std::string LimeGreen{"LimeGreen;"};
            static const std::string PaleGreen{"PaleGreen;"};
            static const std::string LightGreen{"LightGreen;"};
            static const std::string MediumSpringGreen{"MediumSpringGreen;"};
            static const std::string SpringGreen{"SpringGreen;"};
            static const std::string MediumSeaGreen{"MediumSeaGreen;"};
            static const std::string SeaGreen{"SeaGreen;"};
            static const std::string ForestGreen{"ForestGreen;"};
            static const std::string Green{"Green;"};
            static const std::string DarkGreen{"DarkGreen;"};
            static const std::string YellowGreen{"YellowGreen;"};
            static const std::string OliveDrab{"OliveDrab;"};
            static const std::string DarkOliveGreen{"DarkOliveGreen;"};
            static const std::string MediumAquaMarine{"MediumAquaMarine;"};
            static const std::string DarkSeaGreen{"DarkSeaGreen;"};
            static const std::string LightSeaGreen{"LightSeaGreen;"};
            static const std::string DarkCyan{"DarkCyan;"};
            static const std::string Teal{"Teal;"};
        }
        namespace White {
            static const std::string White{"White;"};
            static const std::string Snow{"Snow;"};
            static const std::string HoneyDew{"HoneyDew;"};
            static const std::string MintCream {"MintCream;"};
            static const std::string Azure{"Azure;"};
            static const std::string AliceBlue{"AliceBlue;"};
            static const std::string GhostWhite{"GhostWhite;"};
            static const std::string WhiteSmoke{"WhiteSmoke;"};
            static const std::string SeaShell{"SeaShell;"};
            static const std::string OldLace{"OldLace;"};
            static const std::string FloralWhite{"FloralWhite;"};
            static const std::string Ivory{"Ivory;"};
            static const std::string AntiqueWhite{"AntiqueWhite;"};
            static const std::string Linen{"Linen;"};
            static const std::string LavenderBlush{"LavenderBlush;"};
            static const std::string MistyRose{"MistyRose;"};
        }
        namespace Grey {
            static const std::string Gainsboro{"Gainsboro;"};
            static const std::string LightGray{"LightGray;"};
            static const std::string Silver{"Silver;"};
            static const std::string DarkGray {"DarkGray;"};
            static const std::string DimGray{"DimGray;"};
            static const std::string Gray{"Gray;"};
            static const std::string LightSlateGray{"LightSlateGray;"};
            static const std::string SlateGray{"SlateGray;"};
            static const std::string DarkSlateGray{"DarkSlateGray;"};
            static const std::string Black{"Black;"};
        }
    }


    namespace Affix {
        static const std::string data_spy{"data-spy"};
        static const std::string affix{"affix"};
        static const std::string affix_top{"affix-top"};
        static const std::string affix_bottom{"affix-bottom"};
        static const std::string offsetTop( int offsetTop = 0 ){ return "data-offset-top=\""+std::to_string(offsetTop)+"\"";}
        static const std::string offsetBottom( int offsetBottom = 0 ){ return "data-offset-bottom=\""+std::to_string(offsetBottom)+"\"";}
    }


    namespace font {
        namespace size {
            static const std::string s72px{"font-size:72px;"};
            static const std::string s64px{"font-size:64px;"};
            static const std::string s48px{"font-size:48px;"};
            static const std::string s36px{"font-size:36px;"};
            static const std::string s28px{"font-size:28px;"};
            static const std::string s24px{"font-size:24px;"};
            static const std::string s20px{"font-size:20px;"};
            static const std::string s18px{"font-size:18px;"};
            static const std::string s16px{"font-size:16px;"};
            static const std::string s14px{"font-size:14px;"};
            static const std::string s12px{"font-size:12px;"};
            static const std::string s11px{"font-size:11px;"};
            static const std::string s10px{"font-size:10px;"};
            static const std::string s9px{"font-size:9px;"};
            static const std::string s8px{"font-size:8px;"};
        }
        namespace family {
            static const std::string tahoma{"font-family:tahoma;"};
            static const std::string dosis{"font-family: 'Dosis', sans-serif;"};
        }
        namespace weight {
            static const std::string bold{"font-weight:bold;"};
            static const std::string normal{"font-weight:normal;"};
            static const std::string lighter{"font-weight:lighter;"};
        }
    }

    namespace background {
        static std::string url(const std::string& imgPath){return std::string{"background:url("+imgPath+");"};};

        namespace color {
            static const std::string rgb(const std::string& rgb){return std::string{"background-color:rgb("+rgb+");"};};
            static const std::string rgb(int r , int g , int b ){return std::string{ "background-color:rgb(" +std::to_string(r)+","+std::to_string(g)+","+std::to_string(b)+");" };};
            static const std::string rgba(int r , int g , int b , double a = 0.5 ){return std::string{ "background-color:rgba(" +std::to_string(r)+","+std::to_string(g)+","+std::to_string(b)+","+std::to_string(a)+");" };};
            static const std::string rgba(const std::string& rgba){return std::string{"background-color:rgba("+rgba+");"};};
            static const std::string color(const std::string& color){return std::string{"background-color:"+color};};
        }

        namespace size {
            static const std::string contain{"background-size:contain;"};
            static const std::string initial{"background-size:initial;"};
            static const std::string cover{"background-size:cover;"};
            static const std::string auto_{"background-size:auto;"};
            static const std::string length(const std::string &inpixel){return std::string{"background-size:"+inpixel+"px;"};};
            static const std::string length(const std::string &inpixel1,const std::string &inpixel2){return std::string{"background-size:"+inpixel1+"px "+inpixel2+"px;"};};
            static const std::string percentage(const std::string &inper){return std::string{"background-size:"+inper+";"};};
            static const std::string percentage(const std::string &inper1,const std::string &inper2){return std::string{"background-size:"+inper1+" "+inper2+";"};};
        }
        namespace repeat {
            static const std::string repeat{"background-repeat:repeat;"};
            static const std::string repeat_x{"background-repeat:repeat-x;"};
            static const std::string repeat_y{"background-repeat:repeat-y;"};
            static const std::string repeat_x_y{"background-repeat:repeat-x-y;"};
            static const std::string norepeat{"background-repeat:no-repeat;"};
            static const std::string round{"background-repeat:round;"};
            static const std::string space{"background-repeat:space;"};
        }
        namespace origin {
            static const std::string padding_box{"background-origin:padding-box;"};
            static const std::string border_box{"background-origin:border-box;"};
            static const std::string content_box{"background-origin:content-box;"};
        }
        namespace attachment {
            static const std::string scroll{"background-attachment:scroll;"};
            static const std::string fixed{"background-attachment:fixed;"};
            static const std::string local{"background-attachment:local;"};
        }
        namespace blend_mode {
            static const std::string normal{"background-blend-mode:normal;"};
            static const std::string multiply{"background-blend-mode:multiply;"};
            static const std::string screen{"background-blend-mode:screen;"};
            static const std::string overlay{"background-blend-mode:overlay;"};
            static const std::string darken{"background-blend-mode:darken;"};
            static const std::string lighten{"background-blend-mode:lighten;"};
            static const std::string color_dodge{"background-blend-mode:color-dodge;"};
            static const std::string saturation{"background-blend-mode:saturation;"};
            static const std::string color{"background-blend-mode:color;"};
            static const std::string luminosity{"background-blend-mode:luminosity;"};
        }
        namespace clip {
            static const std::string border_box{"background-clip:border-box;"};
            static const std::string padding_box{"background-clip:padding-box;"};
            static const std::string content_box{"background-clip:content-box;"};
        }
        namespace position {
            static const std::string left_top{"background-position:left top;"};
            static const std::string left_center{"background-position:left center;"};
            static const std::string left_bottom{"background-position:left bottom;"};
            static const std::string right_top{"background-position:right top;"};
            static const std::string right_center{"background-position:right center;"};
            static const std::string right_bottom{"background-position:right bottom;"};
            static const std::string center_top{"background-position:center top;"};
            static const std::string center_center{"background-position:center center;"};
            static const std::string center_bottom{"background-position:center bottom;"};
            static const std::string pos(const std::string &xpos , const std::string &ypos){return std::string{"background-position:"+xpos+" "+ypos+";"};};
            static const std::string percentage(const std::string &per1 , const std::string &per2){return std::string{"background-position:"+per1+"% "+per2+"%;"};};
        }
    }

    namespace Border {
        static std::string border(const std::string &borderText){return std::string{"border:"+borderText+";"};};
        static std::string borderRardius(const std::string &radius1, const std::string &radius2 = "0" , const std::string &radius3 = "0" , const std::string &radius4 = "0")
        {return std::string{"border-radius:"+radius1+"px "+radius2+"px "+radius3+"px "+radius4+"px;"};};
        namespace width {
            static std::string medium{"-width:medium;"};
            static std::string thin{"-width:thin;"};
            static std::string thick{"-width:thick;"};
            static std::string length(const std::string &inpixel){return std::string{"-width:"+inpixel+"px;"};};
        }
        namespace style {
            static std::string none{"-style:none;"};
            static std::string hidden{"-style:hidden;"};
            static std::string dotted{"-style:dotted;"};
            static std::string dashed{"-style:dashed;"};
            static std::string solid{"-style:solid;"};
            static std::string double_{"-style:double;"};
            static std::string groove{"-style:groove;"};
            static std::string ridge{"-style:ridge;"};
            static std::string inset{"-style:inset;"};
            static std::string outset{"-style:outset;"};
        }
        namespace bottom {
            static std::string border(std::string borderText){return std::string{"border-bottom:"+borderText+";"};};
            static std::string border_width(std::string Borderwidth){ return "border-bottom:"+Borderwidth;};
            static std::string border_style(std::string Borderstyle){ return "border-bottom:"+Borderstyle;};
            static std::string border_color(std::string rgb,std::string a = "1"){ return "border-bottom-color:rgb("+rgb+","+a+");";};
        }
        namespace right {
            static std::string border(std::string borderText){return std::string{"border-right:"+borderText+";"};};
            static std::string border_width(std::string Borderwidth){ return "border-right:"+Borderwidth;};
            static std::string border_style(std::string Borderstyle){ return "border-right:"+Borderstyle;};
            static std::string border_color(std::string rgb,std::string a = "1"){ return "border-right-color:rgb("+rgb+","+a+");";};
        }
        namespace left {
            static std::string border(std::string borderText){return std::string{"border-left:"+borderText+";"};};
            static std::string border_width(std::string Borderwidth){ return "border-left:"+Borderwidth;};
            static std::string border_style(std::string Borderstyle){ return "border-left:"+Borderstyle;};
            static std::string border_color(std::string rgb,std::string a = "1"){ return "border-left-color:rgb("+rgb+","+a+");";};
        }
        namespace top {
            static std::string border(std::string borderText){return std::string{"border-top:"+borderText+";"};};
            static std::string border_width(std::string Borderwidth){ return "border-top:"+Borderwidth;};
            static std::string border_style(std::string Borderstyle){ return "border-top:"+Borderstyle;};
            static std::string border_color(std::string rgb,std::string a = "1"){return "border-top-color:rgb("+rgb+","+a+");";};
        }
    }


    namespace Height {
        static std::string height(std::string value,std::string type = "px"){return std::string{"height:"+value+type+";"};};
    }



}



#endif // INLINESTYLE_H
