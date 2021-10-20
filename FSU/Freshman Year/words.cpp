#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

int main()
{
	bool match = false;
	
	char option;
	int count2;
	
	char Bank[1000];
	
	char able[] = "able";
	char acid[] = "acid";
	char aged[] = "aged";
	char also[] = "also";
	char area[] = "area";
	char army[] = "army";
	char away[] = "away";
	char baby[] = "baby";
	char back[] = "back";
	char ball[] = "ball";
	char band[] = "band";
	char bank[] = "bank";
	char base[] = "base";
	char bath[] = "bath";
	char bear[] = "bear";
	char beat[] = "beat";
	char been[] = "been";
	char beer[] = "beer";
	char bell[] = "bell";
	char belt[] = "belt";
	char best[] = "best";
	char bill[] = "bill";
	char bird[] = "bird";
	char blow[] = "blow";
	char blue[] = "blue";
	char boat[] = "boat";
	char body[] = "body";
	char bomb[] = "bomb";
	char bond[] = "bond";
	char bone[] = "bone";
	char book[] = "book";
	char boom[] = "boom";
	char born[] = "born";
	char boss[] = "boss";
	char both[] = "both";
	char bowl[] = "bowl";
	char bulk[] = "bulk";
	char burn[] = "burn";
	char bush[] = "bush";
	char busy[] = "busy";
	char call[] = "call";
	char calm[] = "calm";
	char came[] = "came";
	char camp[] = "camp";
	char card[] = "card";
	char care[] = "care";
	char cash[] = "cash";
	char cast[] = "cast";
	char cell[] = "cell";
	char chat[] = "chat";
	char chip[] = "chip";
	char city[] = "city";
	char club[] = "club";
	char coal[] = "coal";
	char coat[] = "coat";
	char code[] = "code";
	char cold[] = "cold";
	char come[] = "come";
	char cook[] = "cook";
	char cool[] = "cool";
	char cope[] = "cope";
	char copy[] = "copy";
	char core[] = "core";
	char cost[] = "cost";
	char crew[] = "crew";
	char crop[] = "crop";
	char dark[] = "dark";
	char data[] = "data";
	char date[] = "date";
	char dawn[] = "dawn";
	char days[] = "days";
	char dead[] = "dead";
	char deal[] = "deal";
	char dean[] = "dean";
	char dear[] = "dear";
	char debt[] = "debt";
	char deep[] = "deep";
	char deny[] = "deny";
	char desk[] = "desk";
	char dial[] = "dial";
	char dick[] = "dick";
	char diet[] = "diet";
	char disc[] = "disc";
	char disk[] = "disk";
	char does[] = "does";
	char done[] = "done";
	char door[] = "door";
	char dose[] = "dose";
	char down[] = "down";
	char draw[] = "draw";
	char drew[] = "drew";
	char drop[] = "drop";
	char drug[] = "drug";
	char dual[] = "dual";
	char duke[] = "duke";
	char dust[] = "dust";
	char duty[] = "duty";
	char each[] = "each";
	char earn[] = "earn";
	char ease[] = "ease";
	char east[] = "east";
	char easy[] = "easy";
	char edge[] = "edge";
	char even[] = "even";
	char ever[] = "ever";
	char evil[] = "evil";
	char exit[] = "exit";
	char face[] = "face";
	char fact[] = "fact";
	char fail[] = "fail";
	char fair[] = "fair";
	char fall[] = "fall";
	char farm[] = "farm";
	char fast[] = "fast";
	char fate[] = "fate";
	char fear[] = "fear";
	char feed[] = "feed";
	char feel[] = "feel";
	char feet[] = "feet";
	char fell[] = "fell";
	char felt[] = "felt";
	char file[] = "file";
	char fill[] = "fill";
	char film[] = "film";
	char find[] = "find";
	char fine[] = "fine";
	char fire[] = "fire";
	char firm[] = "firm";
	char fish[] = "fish";
	char five[] = "five";
	char flat[] = "flat";
	char flow[] = "flow";
	char food[] = "food";
	char foot[] = "foot";
	char ford[] = "ford";
	char form[] = "form";
	char fort[] = "fort";
	char four[] = "four";
	char free[] = "free";
	char from[] = "from";
	char fuel[] = "fuel";
	char full[] = "full";
	char fund[] = "fund";
	char gain[] = "gain";
	char game[] = "game";
	char gate[] = "gate";
	char gave[] = "gave";
	char gear[] = "gear";
	char gene[] = "gene";
	char gift[] = "gift";
	char girl[] = "girl";
	char give[] = "give";
	char glad[] = "glad";
	char goal[] = "goal";
	char goes[] = "goes";
	char gold[] = "gold";
	char golf[] = "golf";
	char gone[] = "gone";
	char good[] = "good";
	char gray[] = "gray";
	char grew[] = "grew";
	char grey[] = "grey";
	char grow[] = "grow";
	char gulf[] = "gulf";
	char hair[] = "hair";
	char half[] = "half";
	char hall[] = "hall";
	char hand[] = "hand";
	char hang[] = "hang";
	char hard[] = "hard";
	char harm[] = "harm";
	char hate[] = "hate";
	char have[] = "have";
	char head[] = "head";
	char hear[] = "hear";
	char heat[] = "heat";
	char held[] = "held";
	char hell[] = "hell";
	char help[] = "help";
	char here[] = "here";
	char hero[] = "hero";
	char high[] = "high";
	char hill[] = "hill";
	char hire[] = "hire";
	char hold[] = "hold";
	char hole[] = "hole";
	char holy[] = "holy";
	char home[] = "home";
	char hope[] = "hope";
	char host[] = "host";
	char hour[] = "hour";
	char huge[] = "huge";
	char hung[] = "hung";
	char hunt[] = "hunt";
	char hurt[] = "hurt";
	char idea[] = "idea";
	char inch[] = "inch";
	char into[] = "into";
	char iron[] = "iron";
	char item[] = "item";
	char jack[] = "jack";
	char jane[] = "jane";
	char jean[] = "jean";
	char john[] = "john";
	char join[] = "join";
	char jump[] = "jump";
	char jury[] = "jury";
	char just[] = "just";
	char keen[] = "keen";
	char keep[] = "keep";
	char kent[] = "kent";
	char kept[] = "kept";
	char kick[] = "kick";
	char kill[] = "kill";
	char kind[] = "kind";
	char king[] = "king";
	char knee[] = "knee";
	char knew[] = "knew";
	char know[] = "know";
	char lack[] = "lack";
	char lady[] = "lady";
	char laid[] = "laid";
	char lake[] = "lake";
	char land[] = "land";
	char lane[] = "lane";
	char last[] = "last";
	char late[] = "late";
	char lead[] = "lead";
	char left[] = "left";
	char less[] = "less";
	char life[] = "life";
	char lift[] = "lift";
	char like[] = "like";
	char line[] = "line";
	char link[] = "link";
	char list[] = "list";
	char live[] = "live";
	char load[] = "load";
	char loan[] = "loan";
	char lock[] = "lock";
	char logo[] = "logo";
	char look[] = "look";
	char lord[] = "lord";
	char lose[] = "lose";
	char loss[] = "loss";
	char lost[] = "lost";
	char love[] = "love";
	char luck[] = "luck";
	char made[] = "made";
	char mail[] = "mail";
	char main[] = "main";
	char make[] = "make";
	char male[] = "male";
	char many[] = "many";
	char mark[] = "mark";
	char mass[] = "mass";
	char matt[] = "matt";
	char meal[] = "meal";
	char mean[] = "mean";
	char meat[] = "meat";
	char meet[] = "meet";
	char menu[] = "menu";
	char mere[] = "mere";
	char mike[] = "mike";
	char mile[] = "mile";
	char milk[] = "milk";
	char mill[] = "mill";
	char mind[] = "mind";
	char mine[] = "mine";
	char miss[] = "miss";
	char mode[] = "mode";
	char mood[] = "mood";
	char moon[] = "moon";
	char more[] = "more";
	char most[] = "most";
	char move[] = "move";
	char much[] = "much";
	char must[] = "must";
	char navy[] = "navy";
	char near[] = "near";
	char neck[] = "neck";
	char need[] = "need";
	char news[] = "news";
	char next[] = "next";
	char nice[] = "nice";
	char nick[] = "nick";
	char nine[] = "nine";
	char none[] = "none";
	char nose[] = "nose";
	char note[] = "note";
	char okay[] = "okay";
	char once[] = "once";
	char only[] = "only";
	char onto[] = "onto";
	char open[] = "open";
	char oral[] = "oral";
	char over[] = "over";
	char pace[] = "pace";
	char pack[] = "pack";
	char page[] = "page";
	char paid[] = "paid";
	char pain[] = "pain";
	char pair[] = "pair";
	char palm[] = "palm";
	char park[] = "park";
	char part[] = "part";
	char pass[] = "pass";
	char past[] = "past";
	char path[] = "path";
	char peak[] = "peak";
	char pick[] = "pick";
	char pink[] = "pink";
	char pipe[] = "pipe";
	char plan[] = "plan";
	char play[] = "play";
	char plot[] = "plot";
	char plug[] = "plug";
	char plus[] = "plus";
	char poll[] = "poll";
	char pool[] = "pool";
	char poor[] = "poor";
	char port[] = "port";
	char post[] = "post";
	char pull[] = "pull";
	char pure[] = "pure";
	char push[] = "push";
	char race[] = "race";
	char rail[] = "rail";
	char rain[] = "rain";
	char rank[] = "rank";
	char rare[] = "rare";
	char rate[] = "rate";
	char read[] = "read";
	char real[] = "real";
	char rear[] = "rear";
	char rely[] = "rely";
	char rent[] = "rent";
	char rest[] = "rest";
	char rice[] = "rice";
	char rich[] = "rich";
	char ride[] = "ride";
	char ring[] = "ring";
	char rise[] = "rise";
	char risk[] = "risk";
	char road[] = "road";
	char rock[] = "rock";
	char role[] = "role";
	char roll[] = "roll";
	char roof[] = "roof";
	char room[] = "room";
	char root[] = "root";
	char rose[] = "rose";
	char rule[] = "rule";
	char rush[] = "rush";
	char ruth[] = "ruth";
	char safe[] = "safe";
	char said[] = "said";
	char sake[] = "sake";
	char sale[] = "sale";
	char salt[] = "salt";
	char same[] = "same";
	char sand[] = "sand";
	char save[] = "save";
	char seat[] = "seat";
	char seed[] = "seed";
	char seek[] = "seek";
	char seem[] = "seem";
	char seen[] = "seen";
	char self[] = "self";
	char sell[] = "sell";
	char send[] = "send";
	char sent[] = "sent";
	char sept[] = "sept";
	char ship[] = "ship";
	char shop[] = "shop";
	char shot[] = "shot";
	char show[] = "show";
	char shut[] = "shut";
	char sick[] = "sick";
	char side[] = "side";
	char sign[] = "sign";
	char site[] = "site";
	char size[] = "size";
	char skin[] = "skin";
	char slip[] = "slip";
	char slow[] = "slow";
	char snow[] = "snow";
	char soft[] = "soft";
	char soil[] = "soil";
	char sold[] = "sold";
	char sole[] = "sole";
	char some[] = "some";
	char song[] = "song";
	char soon[] = "soon";
	char sort[] = "sort";
	char soul[] = "soul";
	char spot[] = "spot";
	char star[] = "star";
	char stay[] = "stay";
	char step[] = "step";
	char stop[] = "stop";
	char such[] = "such";
	char suit[] = "suit";
	char sure[] = "sure";
	char take[] = "take";
	char tale[] = "tale";
	char talk[] = "talk";
	char tall[] = "tall";
	char tank[] = "tank";
	char tape[] = "tape";
	char task[] = "task";
	char team[] = "team";
	char tech[] = "tech";
	char tell[] = "tell";
	char tend[] = "tend";
	char term[] = "term";
	char test[] = "test";
	char text[] = "text";
	char than[] = "than";
	char that[] = "that";
	char them[] = "them";
	char then[] = "then";
	char they[] = "they";
	char thin[] = "thin";
	char thus[] = "thus";
	char till[] = "till";
	char tiny[] = "tiny";
	char told[] = "told";
	char toll[] = "toll";
	char tone[] = "tone";
	char tony[] = "tony";
	char took[] = "took";
	char tool[] = "tool";
	char tour[] = "tour";
	char town[] = "town";
	char tree[] = "tree";
	char trip[] = "trip";
	char tune[] = "tune";
	char turn[] = "turn";
	char twin[] = "twin";
	char type[] = "type";
	char unit[] = "unit";
	char upon[] = "upon";
	char used[] = "used";
	char user[] = "user";
	char vary[] = "vary";
	char vast[] = "vast";
	char very[] = "very";
	char vice[] = "vice";
	char view[] = "view";
	char vote[] = "vote";
	char wage[] = "wage";
	char wait[] = "wait";
	char wake[] = "wake";
	char walk[] = "walk";
	char wall[] = "wall";
	char want[] = "want";
	char ward[] = "ward";
	char warm[] = "warm";
	char wash[] = "wash";
	char wave[] = "wave";
	char ways[] = "ways";
	char weak[] = "weak";
	char wear[] = "wear";
	char week[] = "week";
	char well[] = "well";
	char went[] = "went";
	char were[] = "were";
	char west[] = "west";
	char what[] = "what";
	char when[] = "when";
	char whom[] = "whom";
	char wide[] = "wide";
	char wife[] = "wife";
	char wild[] = "wild";
	char will[] = "will";
	char wind[] = "wind";
	char wine[] = "wine";
	char wing[] = "wing";
	char wire[] = "wire";
	char wise[] = "wise";
	char wish[] = "wish";
	char with[] = "with";
	char wood[] = "wood";
	char word[] = "word";
	char wore[] = "wore";
	char work[] = "work";
	char yard[] = "yard";
	char yeah[] = "yeah";
	char year[] = "year";
	char your[] = "your";
	char zero[] = "zero";
	char zone[] = "zone";



	char name[4];
	int count = 0;
	
	srand(time(0));
	
	while(match != true)
	{
		name[0] = rand() % 26 + 97;
		name[1] = rand() % 26 + 97;
		name[2] = rand() % 26 + 97;
		name[3] = rand() % 26 + 97;
		
		cout << "TEST #" << count << ": " << name << endl;
		cout << "Checking against Word Bank" << endl;
		cout << "\n" << endl;
		
		if(strcmp(able, name) == 0
 || strcmp(acid, name) == 0
 || strcmp(aged, name) == 0
 || strcmp(also, name) == 0
 || strcmp(area, name) == 0
 || strcmp(army, name) == 0
 || strcmp(away, name) == 0
 || strcmp(baby, name) == 0
 || strcmp(back, name) == 0
 || strcmp(ball, name) == 0
 || strcmp(band, name) == 0
 || strcmp(bank, name) == 0
 || strcmp(base, name) == 0
 || strcmp(bath, name) == 0
 || strcmp(bear, name) == 0
 || strcmp(beat, name) == 0
 || strcmp(been, name) == 0
 || strcmp(beer, name) == 0
 || strcmp(bell, name) == 0
 || strcmp(belt, name) == 0
 || strcmp(best, name) == 0
 || strcmp(bill, name) == 0
 || strcmp(bird, name) == 0
 || strcmp(blow, name) == 0
 || strcmp(blue, name) == 0
 || strcmp(boat, name) == 0
 || strcmp(body, name) == 0
 || strcmp(bomb, name) == 0
 || strcmp(bond, name) == 0
 || strcmp(bone, name) == 0
 || strcmp(book, name) == 0
 || strcmp(boom, name) == 0
 || strcmp(born, name) == 0
 || strcmp(boss, name) == 0
 || strcmp(both, name) == 0
 || strcmp(bowl, name) == 0
 || strcmp(bulk, name) == 0
 || strcmp(burn, name) == 0
 || strcmp(bush, name) == 0
 || strcmp(busy, name) == 0
 || strcmp(call, name) == 0
 || strcmp(calm, name) == 0
 || strcmp(came, name) == 0
 || strcmp(camp, name) == 0
 || strcmp(card, name) == 0
 || strcmp(care, name) == 0
 || strcmp(cash, name) == 0
 || strcmp(cast, name) == 0
 || strcmp(cell, name) == 0
 || strcmp(chat, name) == 0
 || strcmp(chip, name) == 0
 || strcmp(city, name) == 0
 || strcmp(club, name) == 0
 || strcmp(coal, name) == 0
 || strcmp(coat, name) == 0
 || strcmp(code, name) == 0
 || strcmp(cold, name) == 0
 || strcmp(come, name) == 0
 || strcmp(cook, name) == 0
 || strcmp(cool, name) == 0
 || strcmp(cope, name) == 0
 || strcmp(copy, name) == 0
 || strcmp(core, name) == 0
 || strcmp(cost, name) == 0
 || strcmp(crew, name) == 0
 || strcmp(crop, name) == 0
 || strcmp(dark, name) == 0
 || strcmp(data, name) == 0
 || strcmp(date, name) == 0
 || strcmp(dawn, name) == 0
 || strcmp(days, name) == 0
 || strcmp(dead, name) == 0
 || strcmp(deal, name) == 0
 || strcmp(dean, name) == 0
 || strcmp(dear, name) == 0
 || strcmp(debt, name) == 0
 || strcmp(deep, name) == 0
 || strcmp(deny, name) == 0
 || strcmp(desk, name) == 0
 || strcmp(dial, name) == 0
 || strcmp(dick, name) == 0
 || strcmp(diet, name) == 0
 || strcmp(disc, name) == 0
 || strcmp(disk, name) == 0
 || strcmp(does, name) == 0
 || strcmp(done, name) == 0
 || strcmp(door, name) == 0
 || strcmp(dose, name) == 0
 || strcmp(down, name) == 0
 || strcmp(draw, name) == 0
 || strcmp(drew, name) == 0
 || strcmp(drop, name) == 0
 || strcmp(drug, name) == 0
 || strcmp(dual, name) == 0
 || strcmp(duke, name) == 0
 || strcmp(dust, name) == 0
 || strcmp(duty, name) == 0
 || strcmp(each, name) == 0
 || strcmp(earn, name) == 0
 || strcmp(ease, name) == 0
 || strcmp(east, name) == 0
 || strcmp(easy, name) == 0
 || strcmp(edge, name) == 0
 || strcmp(even, name) == 0
 || strcmp(ever, name) == 0
 || strcmp(evil, name) == 0
 || strcmp(exit, name) == 0
 || strcmp(face, name) == 0
 || strcmp(fact, name) == 0
 || strcmp(fail, name) == 0
 || strcmp(fair, name) == 0
 || strcmp(fall, name) == 0
 || strcmp(farm, name) == 0
 || strcmp(fast, name) == 0
 || strcmp(fate, name) == 0
 || strcmp(fear, name) == 0
 || strcmp(feed, name) == 0
 || strcmp(feel, name) == 0
 || strcmp(feet, name) == 0
 || strcmp(fell, name) == 0
 || strcmp(felt, name) == 0
 || strcmp(file, name) == 0
 || strcmp(fill, name) == 0
 || strcmp(film, name) == 0
 || strcmp(find, name) == 0
 || strcmp(fine, name) == 0
 || strcmp(fire, name) == 0
 || strcmp(firm, name) == 0
 || strcmp(fish, name) == 0
 || strcmp(five, name) == 0
 || strcmp(flat, name) == 0
 || strcmp(flow, name) == 0
 || strcmp(food, name) == 0
 || strcmp(foot, name) == 0
 || strcmp(ford, name) == 0
 || strcmp(form, name) == 0
 || strcmp(fort, name) == 0
 || strcmp(four, name) == 0
 || strcmp(free, name) == 0
 || strcmp(from, name) == 0
 || strcmp(fuel, name) == 0
 || strcmp(full, name) == 0
 || strcmp(fund, name) == 0
 || strcmp(gain, name) == 0
 || strcmp(game, name) == 0
 || strcmp(gate, name) == 0
 || strcmp(gave, name) == 0
 || strcmp(gear, name) == 0
 || strcmp(gene, name) == 0
 || strcmp(gift, name) == 0
 || strcmp(girl, name) == 0
 || strcmp(give, name) == 0
 || strcmp(glad, name) == 0
 || strcmp(goal, name) == 0
 || strcmp(goes, name) == 0
 || strcmp(gold, name) == 0
 || strcmp(golf, name) == 0
 || strcmp(gone, name) == 0
 || strcmp(good, name) == 0
 || strcmp(gray, name) == 0
 || strcmp(grew, name) == 0
 || strcmp(grey, name) == 0
 || strcmp(grow, name) == 0
 || strcmp(gulf, name) == 0
 || strcmp(hair, name) == 0
 || strcmp(half, name) == 0
 || strcmp(hall, name) == 0
 || strcmp(hand, name) == 0
 || strcmp(hang, name) == 0
 || strcmp(hard, name) == 0
 || strcmp(harm, name) == 0
 || strcmp(hate, name) == 0
 || strcmp(have, name) == 0
 || strcmp(head, name) == 0
 || strcmp(hear, name) == 0
 || strcmp(heat, name) == 0
 || strcmp(held, name) == 0
 || strcmp(hell, name) == 0
 || strcmp(help, name) == 0
 || strcmp(here, name) == 0
 || strcmp(hero, name) == 0
 || strcmp(high, name) == 0
 || strcmp(hill, name) == 0
 || strcmp(hire, name) == 0
 || strcmp(hold, name) == 0
 || strcmp(hole, name) == 0
 || strcmp(holy, name) == 0
 || strcmp(home, name) == 0
 || strcmp(hope, name) == 0
 || strcmp(host, name) == 0
 || strcmp(hour, name) == 0
 || strcmp(huge, name) == 0
 || strcmp(hung, name) == 0
 || strcmp(hunt, name) == 0
 || strcmp(hurt, name) == 0
 || strcmp(idea, name) == 0
 || strcmp(inch, name) == 0
 || strcmp(into, name) == 0
 || strcmp(iron, name) == 0
 || strcmp(item, name) == 0
 || strcmp(jack, name) == 0
 || strcmp(jane, name) == 0
 || strcmp(jean, name) == 0
 || strcmp(john, name) == 0
 || strcmp(join, name) == 0
 || strcmp(jump, name) == 0
 || strcmp(jury, name) == 0
 || strcmp(just, name) == 0
 || strcmp(keen, name) == 0
 || strcmp(keep, name) == 0
 || strcmp(kent, name) == 0
 || strcmp(kept, name) == 0
 || strcmp(kick, name) == 0
 || strcmp(kill, name) == 0
 || strcmp(kind, name) == 0
 || strcmp(king, name) == 0
 || strcmp(knee, name) == 0
 || strcmp(knew, name) == 0
 || strcmp(know, name) == 0
 || strcmp(lack, name) == 0
 || strcmp(lady, name) == 0
 || strcmp(laid, name) == 0
 || strcmp(lake, name) == 0
 || strcmp(land, name) == 0
 || strcmp(lane, name) == 0
 || strcmp(last, name) == 0
 || strcmp(late, name) == 0
 || strcmp(lead, name) == 0
 || strcmp(left, name) == 0
 || strcmp(less, name) == 0
 || strcmp(life, name) == 0
 || strcmp(lift, name) == 0
 || strcmp(like, name) == 0
 || strcmp(line, name) == 0
 || strcmp(link, name) == 0
 || strcmp(list, name) == 0
 || strcmp(live, name) == 0
 || strcmp(load, name) == 0
 || strcmp(loan, name) == 0
 || strcmp(lock, name) == 0
 || strcmp(logo, name) == 0
 || strcmp(look, name) == 0
 || strcmp(lord, name) == 0
 || strcmp(lose, name) == 0
 || strcmp(loss, name) == 0
 || strcmp(lost, name) == 0
 || strcmp(love, name) == 0
 || strcmp(luck, name) == 0
 || strcmp(made, name) == 0
 || strcmp(mail, name) == 0
 || strcmp(main, name) == 0
 || strcmp(make, name) == 0
 || strcmp(male, name) == 0
 || strcmp(many, name) == 0
 || strcmp(mark, name) == 0
 || strcmp(mass, name) == 0
 || strcmp(matt, name) == 0
 || strcmp(meal, name) == 0
 || strcmp(mean, name) == 0
 || strcmp(meat, name) == 0
 || strcmp(meet, name) == 0
 || strcmp(menu, name) == 0
 || strcmp(mere, name) == 0
 || strcmp(mike, name) == 0
 || strcmp(mile, name) == 0
 || strcmp(milk, name) == 0
 || strcmp(mill, name) == 0
 || strcmp(mind, name) == 0
 || strcmp(mine, name) == 0
 || strcmp(miss, name) == 0
 || strcmp(mode, name) == 0
 || strcmp(mood, name) == 0
 || strcmp(moon, name) == 0
 || strcmp(more, name) == 0
 || strcmp(most, name) == 0
 || strcmp(move, name) == 0
 || strcmp(much, name) == 0
 || strcmp(must, name) == 0
 || strcmp(navy, name) == 0
 || strcmp(near, name) == 0
 || strcmp(neck, name) == 0
 || strcmp(need, name) == 0
 || strcmp(news, name) == 0
 || strcmp(next, name) == 0
 || strcmp(nice, name) == 0
 || strcmp(nick, name) == 0
 || strcmp(nine, name) == 0
 || strcmp(none, name) == 0
 || strcmp(nose, name) == 0
 || strcmp(note, name) == 0
 || strcmp(okay, name) == 0
 || strcmp(once, name) == 0
 || strcmp(only, name) == 0
 || strcmp(onto, name) == 0
 || strcmp(open, name) == 0
 || strcmp(oral, name) == 0
 || strcmp(over, name) == 0
 || strcmp(pace, name) == 0
 || strcmp(pack, name) == 0
 || strcmp(page, name) == 0
 || strcmp(paid, name) == 0
 || strcmp(pain, name) == 0
 || strcmp(pair, name) == 0
 || strcmp(palm, name) == 0
 || strcmp(park, name) == 0
 || strcmp(part, name) == 0
 || strcmp(pass, name) == 0
 || strcmp(past, name) == 0
 || strcmp(path, name) == 0
 || strcmp(peak, name) == 0
 || strcmp(pick, name) == 0
 || strcmp(pink, name) == 0
 || strcmp(pipe, name) == 0
 || strcmp(plan, name) == 0
 || strcmp(play, name) == 0
 || strcmp(plot, name) == 0
 || strcmp(plug, name) == 0
 || strcmp(plus, name) == 0
 || strcmp(poll, name) == 0
 || strcmp(pool, name) == 0
 || strcmp(poor, name) == 0
 || strcmp(port, name) == 0
 || strcmp(post, name) == 0
 || strcmp(pull, name) == 0
 || strcmp(pure, name) == 0
 || strcmp(push, name) == 0
 || strcmp(race, name) == 0
 || strcmp(rail, name) == 0
 || strcmp(rain, name) == 0
 || strcmp(rank, name) == 0
 || strcmp(rare, name) == 0
 || strcmp(rate, name) == 0
 || strcmp(read, name) == 0
 || strcmp(real, name) == 0
 || strcmp(rear, name) == 0
 || strcmp(rely, name) == 0
 || strcmp(rent, name) == 0
 || strcmp(rest, name) == 0
 || strcmp(rice, name) == 0
 || strcmp(rich, name) == 0
 || strcmp(ride, name) == 0
 || strcmp(ring, name) == 0
 || strcmp(rise, name) == 0
 || strcmp(risk, name) == 0
 || strcmp(road, name) == 0
 || strcmp(rock, name) == 0
 || strcmp(role, name) == 0
 || strcmp(roll, name) == 0
 || strcmp(roof, name) == 0
 || strcmp(room, name) == 0
 || strcmp(root, name) == 0
 || strcmp(rose, name) == 0
 || strcmp(rule, name) == 0
 || strcmp(rush, name) == 0
 || strcmp(ruth, name) == 0
 || strcmp(safe, name) == 0
 || strcmp(said, name) == 0
 || strcmp(sake, name) == 0
 || strcmp(sale, name) == 0
 || strcmp(salt, name) == 0
 || strcmp(same, name) == 0
 || strcmp(sand, name) == 0
 || strcmp(save, name) == 0
 || strcmp(seat, name) == 0
 || strcmp(seed, name) == 0
 || strcmp(seek, name) == 0
 || strcmp(seem, name) == 0
 || strcmp(seen, name) == 0
 || strcmp(self, name) == 0
 || strcmp(sell, name) == 0
 || strcmp(send, name) == 0
 || strcmp(sent, name) == 0
 || strcmp(sept, name) == 0
 || strcmp(ship, name) == 0
 || strcmp(shop, name) == 0
 || strcmp(shot, name) == 0
 || strcmp(show, name) == 0
 || strcmp(shut, name) == 0
 || strcmp(sick, name) == 0
 || strcmp(side, name) == 0
 || strcmp(sign, name) == 0
 || strcmp(site, name) == 0
 || strcmp(size, name) == 0
 || strcmp(skin, name) == 0
 || strcmp(slip, name) == 0
 || strcmp(slow, name) == 0
 || strcmp(snow, name) == 0
 || strcmp(soft, name) == 0
 || strcmp(soil, name) == 0
 || strcmp(sold, name) == 0
 || strcmp(sole, name) == 0
 || strcmp(some, name) == 0
 || strcmp(song, name) == 0
 || strcmp(soon, name) == 0
 || strcmp(sort, name) == 0
 || strcmp(soul, name) == 0
 || strcmp(spot, name) == 0
 || strcmp(star, name) == 0
 || strcmp(stay, name) == 0
 || strcmp(step, name) == 0
 || strcmp(stop, name) == 0
 || strcmp(such, name) == 0
 || strcmp(suit, name) == 0
 || strcmp(sure, name) == 0
 || strcmp(take, name) == 0
 || strcmp(tale, name) == 0
 || strcmp(talk, name) == 0
 || strcmp(tall, name) == 0
 || strcmp(tank, name) == 0
 || strcmp(tape, name) == 0
 || strcmp(task, name) == 0
 || strcmp(team, name) == 0
 || strcmp(tech, name) == 0
 || strcmp(tell, name) == 0
 || strcmp(tend, name) == 0
 || strcmp(term, name) == 0
 || strcmp(test, name) == 0
 || strcmp(text, name) == 0
 || strcmp(than, name) == 0
 || strcmp(that, name) == 0
 || strcmp(them, name) == 0
 || strcmp(then, name) == 0
 || strcmp(they, name) == 0
 || strcmp(thin, name) == 0
 || strcmp(thus, name) == 0
 || strcmp(till, name) == 0
 || strcmp(tiny, name) == 0
 || strcmp(told, name) == 0
 || strcmp(toll, name) == 0
 || strcmp(tone, name) == 0
 || strcmp(tony, name) == 0
 || strcmp(took, name) == 0
 || strcmp(tool, name) == 0
 || strcmp(tour, name) == 0
 || strcmp(town, name) == 0
 || strcmp(tree, name) == 0
 || strcmp(trip, name) == 0
 || strcmp(tune, name) == 0
 || strcmp(turn, name) == 0
 || strcmp(twin, name) == 0
 || strcmp(type, name) == 0
 || strcmp(unit, name) == 0
 || strcmp(upon, name) == 0
 || strcmp(used, name) == 0
 || strcmp(user, name) == 0
 || strcmp(vary, name) == 0
 || strcmp(vast, name) == 0
 || strcmp(very, name) == 0
 || strcmp(vice, name) == 0
 || strcmp(view, name) == 0
 || strcmp(vote, name) == 0
 || strcmp(wage, name) == 0
 || strcmp(wait, name) == 0
 || strcmp(wake, name) == 0
 || strcmp(walk, name) == 0
 || strcmp(wall, name) == 0
 || strcmp(want, name) == 0
 || strcmp(ward, name) == 0
 || strcmp(warm, name) == 0
 || strcmp(wash, name) == 0
 || strcmp(wave, name) == 0
 || strcmp(ways, name) == 0
 || strcmp(weak, name) == 0
 || strcmp(wear, name) == 0
 || strcmp(week, name) == 0
 || strcmp(well, name) == 0
 || strcmp(went, name) == 0
 || strcmp(were, name) == 0
 || strcmp(west, name) == 0
 || strcmp(what, name) == 0
 || strcmp(when, name) == 0
 || strcmp(whom, name) == 0
 || strcmp(wide, name) == 0
 || strcmp(wife, name) == 0
 || strcmp(wild, name) == 0
 || strcmp(will, name) == 0
 || strcmp(wind, name) == 0
 || strcmp(wine, name) == 0
 || strcmp(wing, name) == 0
 || strcmp(wire, name) == 0
 || strcmp(wise, name) == 0
 || strcmp(wish, name) == 0
 || strcmp(with, name) == 0
 || strcmp(wood, name) == 0
 || strcmp(word, name) == 0
 || strcmp(wore, name) == 0
 || strcmp(work, name) == 0
 || strcmp(yard, name) == 0
 || strcmp(yeah, name) == 0
 || strcmp(year, name) == 0
 || strcmp(your, name) == 0
 || strcmp(zero, name) == 0
 || strcmp(zone, name) == 0)

		{
			for(int x = 0; x < 4; x++)
			{
				name[x] = (char)toupper(name[x]);
				
			}
			
			match = true;
			cout << "-----TESTING COMPLETE-----" << endl;
			cout << "\nAfter " << count << " attempts..." << endl;
			cout << "\n"<< "\"" << name << "\"" << " is a word in the Word Bank!" << endl;
			
			cout << "\nWould you like to continue? Type 'Y' for YES and 'N' for NO!" << endl;
			cout << "CONTINUE?: ";
			cin >> option;
			
			if(option == 'Y' || option == 'y')
			{
				match = false;
			}
			
				else match = true;
		}
		
		count++;
	}
	
	
	
	
	return 0;
}
